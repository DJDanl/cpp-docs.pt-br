---
title: "Formatos de data/hora do Windows de 32 bits | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.time"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Windows de 32 bits"
ms.assetid: ef1589db-84d7-4b24-8799-7c7a22cfe2bf
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Formatos de data/hora do Windows de 32 bits
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A hora do arquivo e a data são armazenadas individualmente, usando números inteiros sem sinal como campos de bit.  A hora e a data de Arquivo são empacotadas como segue:  
  
### Time  
  
|Posição de bit:|0   1   2   3   4|5 6 7 8 A 9|B C\- 2.0 D F\- 2.0 AND|  
|---------------------|-----------------------|-----------------|-----------------------------|  
|Comprimento:|5|6|5|  
|Conteúdo:|horas|minutos|incrementos 2 second|  
|Intervalo de valor:|0–23|0–59|0\-29 em intervalos de 2 segundos|  
  
### Date  
  
|Posição de bit:|0   1   2   3   4   5   6|7 A 8 9|B C\- 2.0 D F\- 2.0 AND|  
|---------------------|-------------------------------|-------------|-----------------------------|  
|Comprimento:|7|4|5|  
|Conteúdo:|ano|mês|dia|  
|Intervalo de valor:|0–119|1–12|1–31|  
||\(relativo a 1980\)|||  
  
## Consulte também  
 [Constantes globais](../c-runtime-library/global-constants.md)