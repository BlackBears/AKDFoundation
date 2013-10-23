Pod::Spec.new do |s|

  

  s.name         = "AKDFoundation"
  s.version      = "0.0.1"
  s.summary      = "Foundation and CoreFoudation extensions"

  s.description  = <<-DESC
                  Foundation and CoreFoundation extensions we use for multiple projects
                   DESC

  s.homepage     = "https://github.com/cocoa-factory/AKDFoundation"
  s.license = { :type => 'MIT', :file => 'LICENSE' }

  s.author       = { "Alan Duncan" => "alan@cocoa-factory.com" }

  s.ios.deployment_target = '6.0'
  s.osx.deployment_target = '10.8'

  s.source       = { :git => "https://github.com/cocoa-factory/AKDFoundation.git", :commit => "a13bad0f3cbe91659407d0dff2819952d9233e68" }

  s.source_files = 'source'

  s.frameworks = 'Foundation', 'Security', 'CoreFoundation'

  s.requires_arc = true

end
