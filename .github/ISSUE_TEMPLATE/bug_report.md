---
name: Bug report
about: Create a report to help us improve
title: ''
labels: 'bug'
assignees: ''

---

**Describe the bug**
A clear and concise description of the problem and bug effects.

**Environment information:**

- Platform: the equivalent of `uname -smr` or `uname -smrv` e.g. Darwin 17.4.0 x86_64
- Go environment:

```
# Output of goenv e.g.
$ go env
GOARCH="amd64"
GOBIN=""
GOCACHE="/Users/$USER/Library/Caches/go-build"
GOEXE=""
GOFLAGS=""
GOHOSTARCH="amd64"
GOHOSTOS="darwin"
GOOS="darwin"
GOPATH="/path/to/gopath"
GOPROXY=""
GORACE=""
GOROOT="/usr/local/Cellar/go/1.11/libexec"
GOTMPDIR=""
GOTOOLDIR="/usr/local/Cellar/go/1.11/libexec/pkg/tool/darwin_amd64"
GCCGO="gccgo"
CC="clang"
CXX="clang++"
CGO_ENABLED="1"
GOMOD=""
CGO_CFLAGS="-g -O2"
CGO_CPPFLAGS=""
CGO_CXXFLAGS="-g -O2"
CGO_FFLAGS="-g -O2"
CGO_LDFLAGS="-g -O2"
PKG_CONFIG="pkg-config"
GOGCCFLAGS="-fPIC -m64 -pthread -fno-caret-diagnostics -Qunused-arguments -fmessage-length=0 -fdebug-prefix-map=/var/folders/mn/3604lp_57sg1c707mvclltm80000gn/T/go-build917640487=/tmp/go-build -gno-record-gcc-switches -fno-common"
```

- Compiler info:

```
#  something like the output of `gcc --version` e.g.
$ gcc --version
Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/usr/include/c++/4.2.1
Apple LLVM version 9.1.0 (clang-902.0.39.2)
Target: x86_64-apple-darwin17.4.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

**Steps to Reproduce**
Steps to reproduce the behavior:

1. Go to '...'
2. Run '....'
3. Write data to '....'
4. See error

**Actual behavior**
Explain the failure modes and effects, everything indicating the existence of the bug.
If applicable, add screenshots to help explain your problem.

**Expected behavior**
A clear and concise description of what you expected to happen.

**Additional context**
Add any other context about the problem here.

**Possible implementation**
Hints to fix the bug.
