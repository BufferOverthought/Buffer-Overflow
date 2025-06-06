FROM ubuntu:20.04

# Evita prompts do tzdata/etc
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    gcc \
    netcat \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /home/ctf

# Copia o código fonte e flag
COPY source.c .
COPY flag.txt /flag.txt

# Compila o binário vulnerável (sem proteções modernas)
RUN gcc -fno-stack-protector -z execstack -o safepass source.c

EXPOSE 8080

# Mensagem inicial ao usuário (ajuda pra quem rodar)
CMD echo "Welcome to SafePass Manager CTF!\nConnect with: nc <container_ip> 8080\n" && ./safepass
