import torch

import torch.nn as nn

class ConvBNReLU(nn.Module):
    def __init__(self, in_channels, out_channels, kernel_size, stride=1):
        super().__init__()
        padding = kernel_size // 2
        self.conv = nn.Conv2d(in_channels, out_channels, kernel_size, stride, padding, bias=False)
        self.bn = nn.BatchNorm2d(out_channels)
        self.relu = nn.LeakyReLU(0.1, inplace=True)

    def forward(self, x):
        return self.relu(self.bn(self.conv(x)))

class YOLOv3NanoBlock(nn.Module):
    def __init__(self, in_channels, out_channels):
        super().__init__()
        self.block = nn.Sequential(
            ConvBNReLU(in_channels, out_channels, 3),
            ConvBNReLU(out_channels, out_channels, 3)
        )

    def forward(self, x):
        return self.block(x)

class YOLOv3Nano(nn.Module):
    def __init__(self, num_classes=80, anchors=[(10,13),(16,30),(33,23)]):
        super().__init__()
        self.num_classes = num_classes
        self.anchors = anchors

        # Backbone (very lightweight)
        self.layer1 = ConvBNReLU(3, 16, 3)
        self.layer2 = ConvBNReLU(16, 32, 3, stride=2)
        self.layer3 = YOLOv3NanoBlock(32, 32)
        self.layer4 = ConvBNReLU(32, 64, 3, stride=2)
        self.layer5 = YOLOv3NanoBlock(64, 64)
        self.layer6 = ConvBNReLU(64, 128, 3, stride=2)
        self.layer7 = YOLOv3NanoBlock(128, 128)

        # Detection head
        self.detect = nn.Conv2d(128, len(anchors) * (num_classes + 5), 1)

    def forward(self, x):
        x = self.layer1(x)
        x = self.layer2(x)
        x = self.layer3(x)
        x = self.layer4(x)
        x = self.layer5(x)
        x = self.layer6(x)
        x = self.layer7(x)
        out = self.detect(x)
        # Output shape: (batch, anchors*(num_classes+5), H, W)
        return out

if __name__ == "__main__":
    # Example usage
    model = YOLOv3Nano(num_classes=80)
    dummy_input = torch.randn(1, 3, 224, 224)
    output = model(dummy_input)
    print("Output shape:", output.shape)