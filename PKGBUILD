# Maintainer: Joshua Stiefer <facedelajunk@gmail.com>

pkgname=dwm
pkgver=6.0
pkgrel=1
pkgdesc="A dynamic window manager for X"
url="http://dwm.suckless.org"
arch=('i686' 'x86_64')
license=('MIT')
options=(zipman)
depends=('libx11' 'libxinerama')
install=dwm.install
source=(http://dl.suckless.org/dwm/dwm-$pkgver.tar.gz
	      config.h
	      dwm.desktop
        01-dwm-6.0-pertag2.diff
        02-dwm-6.0-clicktofocus.diff
        03-dwm-6.0-bstack.diff
        04-dwm-6.0-xkeycodetokeysym.diff
        05-dwm-6.0-push.diff
        06-dwm-6.0-cycle.diff
        07-dwm-6.0-gaplessgrid.diff
        08-dwm-6.0-viewontag.diff
        09-dwm-6.0-uselessgaps.diff
        10-dwm-6.0-systray.diff
        11-dwm-6.0-autostart.diff
        12-dwm-6.0-selfrestart.diff)
md5sums=('8bb00d4142259beb11e13473b81c0857'
         '185a009cbf323d984db4902735a4db4e'
         '93a8fb4f8f20eccb7ce0447a86cf796b'
         '2bb0abd4c4cdf14f088744f17eb635ac'
         '72dd910edd6d4407e8327d6d42c7f666'
         'b60183f343d3912e841d5cbda3de768f'
         'e10bb76eb96046e2803035334d829ec5'
         'f90eb7c257c685ed7566e3b8fbe127b2'
         '7f306001162ed175d3b41196b66dc69f'
         '926f0afbcf40c9b349c056ce7866ff6c'
         'a25dcffde0d7bb946611f2e60b3458b7'
         '55795a29967784e0f7980bfc79fb8f27'
         '81ece11dfd07210c1e578607ad83ef30'
         'b8d90491ac423a9bae567845c0a43af0'
         '8929ac2d94f7d8528f531d16de6a372c')

build() {
  cd $srcdir/$pkgname-$pkgver
  patch -p1 < $srcdir/01-dwm-6.0-pertag2.diff
  patch -p1 < $srcdir/02-dwm-6.0-clicktofocus.diff
  patch -p1 < $srcdir/03-dwm-6.0-bstack.diff
  patch -p1 < $srcdir/04-dwm-6.0-xkeycodetokeysym.diff
  patch -p1 < $srcdir/05-dwm-6.0-push.diff
  patch -p1 < $srcdir/06-dwm-6.0-cycle.diff
  patch -p1 < $srcdir/07-dwm-6.0-gaplessgrid.diff
  patch -p1 < $srcdir/08-dwm-6.0-viewontag.diff
  patch -p1 < $srcdir/09-dwm-6.0-uselessgaps.diff
  patch -p1 < $srcdir/10-dwm-6.0-systray.diff
  patch -p1 < $srcdir/11-dwm-6.0-autostart.diff
  patch -p1 < $srcdir/12-dwm-6.0-selfrestart.diff
  cp $srcdir/config.h config.h
  sed -i 's/CPPFLAGS =/CPPFLAGS +=/g' config.mk
  sed -i 's/^CFLAGS = -g/#CFLAGS += -g/g' config.mk
  sed -i 's/^#CFLAGS = -std/CFLAGS += -std/g' config.mk
  sed -i 's/^LDFLAGS = -g/#LDFLAGS += -g/g' config.mk
  sed -i 's/^#LDFLAGS = -s/LDFLAGS += -s/g' config.mk
  make X11INC=/usr/include/X11 X11LIB=/usr/lib/X11
}

package() {
  cd $srcdir/$pkgname-$pkgver
  make PREFIX=/usr DESTDIR=$pkgdir install
  install -m644 -D LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE
  install -m644 -D README $pkgdir/usr/share/doc/$pkgname/README
  install -m644 -D $srcdir/dwm.desktop $pkgdir/usr/share/xsessions/dwm.desktop
}
