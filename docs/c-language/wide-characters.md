---
title: "Caracteres largos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "caracteres largos"
ms.assetid: 165c4a12-8ab9-45fb-9964-c55e9956194c
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Caracteres largos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**ANSI 3.1.3.4** O valor de uma constante de caractere de inteiro que contém mais de um caractere ou uma constante de caractere largo que contém mais de um caractere multibyte  
  
 A constante de caractere comum, 'ab' tem o valor inteiro \(int\)0x6162.  Quando houver mais de um byte, os bytes lidos anteriormente são deslocados para a esquerda pelo valor de **CHAR\_BIT** e o próximo byte é comparado ao uso do operador OR bit a bit com baixos bits **CHAR\_BIT**.  O número de bytes na constante de caracteres multibyte não pode exceder sizeof\(int\), que é 4 para o código de 32 bits de destino.  
  
 A constante de caracteres multibyte é lida como acima e é convertida em uma constante de caractere largo usando a função de tempo de execução `mbtowc`.  Se o resultado não for uma constante de caractere largo válida, um erro será emitido.  Em todo caso, o número de bytes examinados pela função `mbtowc` é limitado ao valor de `MB_CUR_MAX`.  
  
## Consulte também  
 [Caracteres](../c-language/characters.md)