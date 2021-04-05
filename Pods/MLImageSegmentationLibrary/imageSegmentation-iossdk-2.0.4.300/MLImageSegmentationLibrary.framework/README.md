# MLImageSegmentationLibrary iOS SDK

Image segmentation service（MLImageSegmentationLibrary）can be widely used in video entertainment apps. The image editing app integrates this service and can quickly change the image background. The camera app integrates this service and can identify different elements for different optimizations.

## SDK Access

### Add SDK

1. Open a command line window and 'cd' to the location of the Xcode project.
2. Create a 'Podfile' file. If it already exists, skip this step.
```
cd project-directory 
pod init
```
3. Add the pod of SDK to podfile. The currently supported services are shown in the following table.
```
pod 'MLImageSegmentationLibrary', '~> 2.0.4.300'
```
|service|collocation method|
|----|-----|
|Certification services|pod ‘MLImageSegmentationLibrary’|

4. install pod，Then open it .xcworkspace file add view the project。
```
pod install
```

## LICENSE

see[Huawei License file](./LICENSE)

