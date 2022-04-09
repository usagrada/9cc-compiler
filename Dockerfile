FROM ubuntu:20.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update \
    && apt-get install -y \
        build-essential \
        cmake \
        git \
        locales \
        vim \
        wget \
        gcc \
    && echo "ja_JP.UTF-8" >> /etc/locale.gen \
    && locale-gen \
    && apt-get autoremove -y --purge \
    && apt-get clean \
    && rm -rf /var/lib/apt/lists/*

