#!/usr/bin/env bash
# Install gcc6 (6.4.0-2 on Mac OS) for Travis builds

if [[ "$TRAVIS_OS_NAME" == "linux" ]]; then
  sudo apt-get install -qq gcc-6 g++-6
fi

if [[ "$TRAVIS_OS_NAME" == "osx" ]]; then
  echo 'Updating packages database'
  brew update
  echo 'Available versions (gcc)'
  brew list --versions gcc
  echo 'Creating gcc@64 formula'
  cd "$(brew --repository)/Library/Taps/homebrew/homebrew-core"
  git show 42d31bba7772fb01f9ba442d9ee98b33a6e7a055:Formula/gcc\@6.rb | grep -v 'fails_with' > Formula/gcc\@6.rb
  echo 'Installing gcc@6 (6.4.0-2)'
  brew install gcc\@6 || brew link --overwrite gcc\@6
fi

cd $TRAVIS_BUILD_DIR

