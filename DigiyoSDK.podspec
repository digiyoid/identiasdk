Pod::Spec.new do |s|
  s.name             = 'DigiyoSDK'
  s.version          = '1.2.6'
  s.summary          = 'Digiyo SDK es una solución para integrar funcionalidades de identificación digital en aplicaciones móviles.'
  s.homepage         = 'https://github.com/digiyoid/identiasdk'
  s.license          = { :type => 'Proprietary', :text => 'Copyright (c) 2025 Witec. All rights reserved.' }
  s.author           = { 'digiyoid' => 'info@digiyoid.com' }

  s.source		 = {
    :http => 'https://github.com/digiyoid/identiasdk/releases/download/v1.2.6/Digiyo.xcframework.zip',
    :sha256 => '8464a15e4ce934d50cb9fda7e640b88bc5bf5a58d0cd7b0a6d43b0f81b5b02ad'
  }

  s.ios.deployment_target = '13.0'
  s.platform         = :ios, '13.0'

  s.vendored_frameworks = 'Digiyo.xcframework'

end
