# BackgroundRemove-HMS-Core-Swift

# BackgroundRemove-HMS-Core-Swift


```swift

import UIKit
import MLImageSegmentationLibrary

class ViewController: UIViewController {

  var options:MLImageSegmentationSetting?
  var analyzer:MLImageSegmentationAnalyzer?
  
  @IBOutlet weak var resultImageView: UIImageView!
  	
  @IBOutlet weak var btnRemoveBackground: UIButton!
  
  override func viewDidLoad() {
    super.viewDidLoad()
    setRemoverSettings()
    initAnalyser()
    setActions()
  }
  
  func setActions(){
    btnRemoveBackground.addTarget(self, action: #selector(removeBackground), for: .touchUpInside)
  }

  func initAnalyser() {
    analyzer = MLImageSegmentationAnalyzer.sharedInstance()
    analyzer?.setImageSegmentationAnalyzer(options!)
  }

  func setRemoverSettings(){
    options = MLImageSegmentationSetting.init()
    options?.exact = true
    options?.analyzerType = MLImageSegmentationAnalyzerType.body
    options?.scene = MLImageSegmentationScene.all
  }
  
  @objc func removeBackground()  {
    let frame = MLFrame(image: UIImage(named: "deneme")!)
  
    analyzer?.asyncAnalyse(frame) { (res) in
      self.resultImageView.image = nil
      self.resultImageView.image  = res.getForeground()
      self.analyzer?.stop()
    } addOnFailureListener: { (errorCode, errorStr) in
      print("ErrorCode: ", errorCode, "error: ", errorStr)
      self.analyzer?.stop()
    }
    
  }
  
}

```
