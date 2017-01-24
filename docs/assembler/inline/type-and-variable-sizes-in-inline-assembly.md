---
title: "Tamanhos de tipo e vari&#225;vel em assembly embutido | Microsoft Docs"
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
  - "length"
  - "Type"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "assembly embutido, operadores"
  - "Operador LENGTH"
  - " (tamanho)"
  - "Operador SIZE"
  - " (tamanho), obtendo em assembly embutido"
  - "Operador TYPE"
  - "variáveis, comprimento"
  - "variáveis,  (tamanho)"
  - "variáveis, Tipo "
ms.assetid: b62c2f2b-a7ad-4145-bae4-d890db86d348
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Tamanhos de tipo e vari&#225;vel em assembly embutido
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 **LENGTH**, **TAMANHO**, e os operadores de **TIPO** tem um significado limitado no assembly embutido.  Não podem ser usados em todas com o operador de `DUP` \(porque você não pode definir dados com políticas ou operadores de MASM\).  Mas você pode usá\-lo para localizar o tamanho de C ou variáveis ou tipos de C\+\+:  
  
-   O operador de **LENGTH** pode retornar o número de elementos em uma matriz.  Retorna o valor 1 para variáveis de não matriz.  
  
-   O operador de **TAMANHO** pode retornar o tamanho atual do da variável c ou C\+\+.  O tamanho de uma variável é o produto de seus **LENGTH** e **TIPO**.  
  
-   O operador de **TIPO** pode retornar o tamanho do tipo c ou C\+\+ ou a variável.  Se a variável for uma matriz, **TIPO** retorna o tamanho de um único elemento da matriz.  
  
 Por exemplo, se seu programa tem uma matriz de `int` de elementos, 8  
  
```  
int arr[8];  
```  
  
 as seguintes expressões e C do assembly retorna o tamanho de `arr` e de seus elementos.  
  
|\_\_asm|C|Size \(Tamanho\)|  
|-------------|-------|----------------------|  
|Arr de**LENGTH**|`sizeof`\(\) de arr\/`sizeof`\(arr \[0\]\)|8|  
|arr de**TAMANHO**|`sizeof`\(arr\)|32|  
|arr de**TIPO**|`sizeof`\(arr \[0\]\)|4|  
  
 **FINALIZAR Específico da Microsoft**  
  
## Consulte também  
 [Usando linguagem de assembly em blocos de \_\_asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)