# LoRaWAN
*Git Hub contenant les ressources pour le projet LoRaWAN*

## Liste de choses à faire

1. **Gateway: trouver une solution 12h**
 - Le fabriquer à partir d'un autre module

2. **Programmer les modules 8h**
 - Tester les connexions avec la Gateway

3. **Mettre la réception finale 8h**
 - Effectuer des tests
 - Un site web pour récupérer les données reçues

## Liens utiles
 - Modules utilisés : https://wiki.seeedstudio.com/Grove_LoRa_E5_New_Version/ 
 - Tuto LoRaWAN de Seeed studio : https://www.seeedstudio.com/blog/2020/08/03/lorapedia-an-introduction-of-lora-and-lorawan-technology/ 
 - Doc des modules utilisés : https://files.seeedstudio.com/products/317990687/res/LoRa-E5%20module%20datasheet_V1.0.pdf
 - Doc des microprocesseurs des modules utilisés : https://files.seeedstudio.com/products/317990687/res/STM32WLE5JC%20Datasheet.pdf
 - Video "LoRaWan end node": https://www.youtube.com/watch?v=duwUwXt-hs8&list=PL3XBzmAj53Rkkogh-lti58h_GkhzU1n7U&index=3&ab_channel=AndreasSpiess
 - Tuto AT : https://www.disk91.com/2021/technology/lora/lora-e5-the-seeed-studio-stm32-wl-module/
 - tuto At arduino : https://create.arduino.cc/projecthub/sufiankaki/lora-e5-communication-without-lorawan-9fbddc?ref=part&ref_id=10308&offset=18

## Avancement
- 16/05/2022 : 
  1. Mise en place de la connection UART carte-carte 1h
  2. Communication entre STM32 et module LoRa-E5 grâce à des commandes AT 1h
- 17/05/2022 :
  1. Mise en place de la communication LoRa entre deux modules 4h
- 23/05/2022 :
  1. On choisit de partir sur une connection LoRa PURE et non LoRaWAN
     (Gateway fonctionnelle pas en place et iréalisable en 8h) 2h
- 24/05/2022 : 
  1. Soutenance des projets 3h
  2. Développement d'un protocole de communication pour le réseau LoRa 1h

# Protocole LoRa du projet
## Infos utilse
- Temps de transmission de 4ko : 3 secondes
- Délais entre deux transmissions consécutives de 4ko (temps de transmission compris) : 5s

## Fonctionnemen
La transmission :
- Maitre->Esclave se fait en Hexa
- Esclave->Maitre se fait en char
Par défaut, la réception de messages n'est possible qu'en Hexa pour le module LoRa-E5 en mode LoRa.

1. - Maitre : en mode Tx, il envoie l'id de l'esclave pour la transmission. Ensuite le maitre passe en mode Rx.
2. - Esclave : si il reçoit son id il...

```mermaid
graph TD

A[Tx]
B[Rx]
C[Process]

A --> B
A --> C

class A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z internal-link;

stateDiagram-v2
    state if_state <<choice>>
    [*] --> IsPositive
    IsPositive --> if_state
    if_state --> False: if n < 0
    if_state --> True : if n >= 0
```
