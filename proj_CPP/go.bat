@echo off
docker build -t moja_aplikacja:1.0 .
REM lub bez wersji - docker build -t moja_aplikacja .  

REM to polecenie kasuje kontener - bardzie właściwa do testów i rozwijania kodu
REM nie może być 2 identycznych kontenerów
REM -it jeśli do aplikacji wprowadzamy dane i-interactive t-terminal
docker run --name MUP  --rm -it moja_aplikacja:1.0

REM ta wersja pozostawia kontener
REM docker run --name MUP -it moja_aplikacja:1.0

REM Jeśli aplikacja to proces i działa ciągle użyj:
REM docker run -d --name MUP moja_aplikacja