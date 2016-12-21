---
title: "Byte e fluxos largos | Microsoft Docs"
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
  - "Byte and Wide Streams"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "fluxos de bytes"
  - "fluxos largos"
ms.assetid: 61ef0587-4cbc-4eb8-aae5-4c298dbbc6f9
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Byte e fluxos largos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um fluxo de bytes trata um arquivo com uma sequência de bytes.  No programa, o fluxo será idêntica a sequência de bytes.  
  
 Por outro lado, um fluxo amplo trata um arquivo com uma sequência de caracteres generalizados multibyte, o que pode ter um amplo intervalo de regras de codificação. \(O texto e os arquivos binários ainda são lidos e gravados como descrito anteriormente.\) No programa, o fluxo correspondente é semelhante à sequência de caracteres amplos.  As conversões entre as duas representações ocorrem dentro da biblioteca padrão C.  As regras de conversão podem, em princípio, ser alteradas por uma chamada a [setlocale](../Topic/setlocale,%20_wsetlocale.md) que altera a categoria `LC_CTYPE`.  Cada fluxo amplo determina as regras de conversão em ficar orientado para todo, e retém essas regras se a categoria `LC_CTYPE` for alterado posteriormente.  
  
 O posicionamento dentro de um fluxo de sofrê as mesmas restrições que para vapores de texto.  Além disso, o indicador de arquivo posição bem pode ter que lidar com uma codificação de estado dependente.  Normalmente, o inclui um deslocamento de bytes no fluxo e um objeto de tipo `mbstate_t`.  Portanto, o único modo seguro para obter uma posição do arquivo em um fluxo amplo é chamando [fgetpos](../c-runtime-library/reference/fgetpos.md), e o único modo confiável de restaurar uma posição adquiriu esse modo é chamando [fsetpos](../Topic/fsetpos.md).  
  
## Consulte também  
 [Arquivos e fluxos](../c-runtime-library/files-and-streams.md)   
 [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md)