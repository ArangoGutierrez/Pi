FROM gcc
MAINTAINER Eduardo Arango <carangog@redhat.com>

USER root
COPY pi.c /projects/Pi/
RUN pwd && ls -l && ls -l /projects/Pi
WORKDIR /projects/Pi
RUN g++ -fopenmp pi.c -o pi
RUN cp pi /bin

USER jboss
ENTRYPOINT ["pi","100"]
CMD ["pi"]
