# Starting from a Ubuntu 20.04 installation
FROM ubuntu:20.04

ENV LAST_UPDATED=2022-03-01

ARG NB_USER="jovyan"
ARG NB_UID="1000"
ARG NB_GID="100"

# Fix DL4006
SHELL ["/bin/bash", "-o", "pipefail", "-c"]

# Install cmake and g++
RUN apt-get update --yes  && \
    apt-get install --yes --no-install-recommends g++ cmake make python3-pip libeigen3-dev && \
    apt-get --yes clean          && \
    apt-get --yes autoremove     && \
    rm -Rf /var/lib/apt/lists/*

# Install JupyterLab
USER root

RUN chmod 777 /tmp        && \
    apt-get update --yes  && \
    DEBIAN_FRONTEND="noninteractive" && \
    # Install required python packages
    #   - sympy, see https://savannah.gnu.org/bugs/?58491
    pip3 install --upgrade --no-cache-dir \
      jupyterlab                    \
      jupytext                      \
      jupyter-book                  \
      ghp-import                    \
      numpy                         \
      networkx                   && \
    apt-get --yes clean          && \
    apt-get --yes autoremove     && \
    rm -Rf /var/lib/apt/lists/*

# Configure environment
ENV SHELL=/bin/bash \
    NB_USER="${NB_USER}" \
    NB_UID=${NB_UID} \
    NB_GID=${NB_GID} \
    LC_ALL=en_US.UTF-8 \
    LANG=en_US.UTF-8 \
    LANGUAGE=en_US.UTF-8 \
    HOME="/home/${NB_USER}"

# Make sure the contents of our repo are in ${HOME}
COPY . ${HOME}
USER root
RUN chown -R ${NB_UID} ${HOME}
# Switch back to jovyan to avoid accidental container runs as root
USER ${NB_UID}

WORKDIR "${HOME}"
