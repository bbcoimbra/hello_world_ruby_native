require 'rubygems'
require 'rake'

begin
  require 'jeweler'
  Jeweler::Tasks.new do |gem|
    gem.name = "hello_world"
    gem.summary = %Q{Simple Hello World Native Extension}
    gem.description = %{Simple Hello World Native Extension}
    gem.email = "bbcoimbra@gmail.com"
    gem.homepage = "http://github.com/bbcoimbra/hello_world"
    gem.authors = ["Bruno Coimbra"]
    gem.add_development_dependency "jeweler"
		gem.add_development_dependency "rake-compiler"
		gem.extensions << "ext/hello_world_api/extconf.rb"
  end
rescue LoadError
  puts "Jeweler (or a dependency) not available. Install it with: sudo gem install jeweler"
end

require 'rake/testtask'
Rake::TestTask.new(:test) do |test|
  test.libs << 'lib' << 'test'
  test.pattern = 'test/**/*_test.rb'
  test.verbose = true
end

begin
  require 'rcov/rcovtask'
  Rcov::RcovTask.new do |test|
    test.libs << 'test'
    test.pattern = 'test/**/*_test.rb'
    test.verbose = true
  end
rescue LoadError
  task :rcov do
    abort "RCov is not available. In order to run rcov, you must: sudo gem install spicycode-rcov"
  end
end

task :test => :check_dependencies

task :default => :test

require 'rake/rdoctask'
Rake::RDocTask.new do |rdoc|
  if File.exist?('VERSION')
    version = File.read('VERSION')
  else
    version = ""
  end

  rdoc.rdoc_dir = 'rdoc'
  rdoc.title = "hello_world #{version}"
  rdoc.rdoc_files.include('README*')
  rdoc.rdoc_files.include('lib/**/*.rb')
end

require 'rake/extensiontask'
Rake::ExtensionTask.new('hello_world_api')
