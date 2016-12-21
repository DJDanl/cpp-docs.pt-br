---
title: "Deslocamentos para a direita | Microsoft Docs"
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
ms.assetid: c878e97d-ea3c-4c6b-90a8-b1b24b2d5b19
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Deslocamentos para a direita
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O resultado de um deslocamento à direita de um valor negativo tipo integral com sinal  
  
 O deslocamento de um valor negativo para a direita gera metade do valor absoluto, arredondado para baixo.  Por exemplo, um sinal`short`valor – 253 \(0xFF03 hex, binário 11111111 00000011\) deslocados um direito de bit produz – 127 \(0xFF81 hex, binário 10000001 11111111\).  Um positivo 253 deslocados direita gera \+ 126.  
  
 Deslocamentos para a direito preservam o bit de sinal de tipos integrais com sinal.  Quando um inteiro assinado é deslocado para a direita, o bit mais significativo permanece definido.  Por exemplo, se 0xF0000000 for entrou`int`um deslocamento para a direita produz 0xF8000000.  Mudando um negativo`int`direita 32 vezes produz 0xFFFFFFFF.  
  
 Quando um inteiro não assinado é deslocado para a direita, o bit mais significativo é limpo.  Por exemplo, se 0xF000 não for assinado, o resultado será 0x7800.  Mudando um`unsigned`positivo ou`int`direita 32 vezes produz 0x00000000.  
  
## Consulte também  
 [Inteiros](../Topic/Integers.md)