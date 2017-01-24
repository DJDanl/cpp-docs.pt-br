---
title: "Rebaixamento de inteiros | Microsoft Docs"
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
  - "rebaixando inteiros"
ms.assetid: 51fb3654-60b0-4de7-80eb-bd910086c18a
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Rebaixamento de inteiros
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**ANSI 3.2.1.2** O resultado da conversão de um inteiro para um número inteiro com sinal mais curto, ou o resultado da conversão de um número inteiro sem sinal para um número inteiro com sinal de mesmo comprimento, se o valor não puder ser representado  
  
 Quando um inteiro **long** é convertido em **short**, ou **short** é convertido em `char`, os bytes menos significativos são retidos.  
  
 Por exemplo, esta linha  
  
```  
short x = (short)0x12345678L;  
```  
  
 atribui o valor 0x5678 a `x`, e esta linha  
  
```  
char y = (char)0x1234;  
```  
  
 atribui o valor 0x34 a `y`.  
  
 Quando variáveis com sinal são convertidas em sem sinal e vice\-versa, os padrões de bits permanecem os mesmos.  Por exemplo, converter –2 \(0xFE\) em um valor sem sinal gera 254 \(também 0xFE\).  
  
## Consulte também  
 [Inteiros](../Topic/Integers.md)