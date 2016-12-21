---
title: "Armazenamento de literais da cadeia de caracteres | Microsoft Docs"
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
  - "literais String, armazenamento"
ms.assetid: ba5e4d2c-d456-44b3-a8ca-354af547ac50
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Armazenamento de literais da cadeia de caracteres
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os caracteres de uma cadeia de caracteres literal são armazenados em locais de memória contíguos.  Uma sequência de escape \(como **\\\\** ou **\\"**\) dentro de uma literal de cadeia de caracteres conta como um único caractere.  Um caractere nulo \(representado pela sequência de escape **\\0**\) é acrescentado automaticamente às literais de cadeia de caracteres, e marca o fim de cada uma delas. \(Isso ocorre durante a [fase de tradução](../preprocessor/phases-of-translation.md) 7.\) observe que o compilador pode não armazenar duas cadeias de caracteres idênticas em dois endereços diferentes.  [\/GF](../Topic/-GF%20\(Eliminate%20Duplicate%20Strings\).md) força o compilador a colocar uma única cópia de cadeias de caracteres idênticas no arquivo executável.  
  
## Comentários  
 **Específico da Microsoft**  
  
 As cadeias de caracteres têm duração de armazenamento estático.  Consulte [Classes de armazenamento](../c-language/c-storage-classes.md) para obter informações sobre a duração de armazenamento.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [literais String C](../c-language/c-string-literals.md)