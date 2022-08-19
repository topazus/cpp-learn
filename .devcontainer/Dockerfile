FROM fedora:rawhide

WORKDIR /home

RUN dnf -y update && \
  dnf groupinstall -y "Development Tools" "Development Libraries" && \
  dnf install -y passwd wget gcc-c++ which dnf-plugins-core && \
  echo "su - ruby" >> /root/.bashrc

RUN useradd -m -G wheel ruby
