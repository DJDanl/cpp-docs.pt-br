---
title: "optimize | Microsoft Docs"
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
  - "vc-pragma.optimize"
  - "optimize_CPP"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "otimizar pragma"
  - "pragmas, optimize"
ms.assetid: cb13c1cc-186a-45bc-bee7-95a8de7381cc
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# optimize
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Especifica as otimizações a serem executadas em uma base de função por função.  
  
## Sintaxe  
  
```  
  
#pragma optimize( "[optimization-list]", {on | off} )  
```  
  
## Comentários  
 O pragma **optimize** deve aparecer fora de uma função e entra em vigor na primeira função definida depois que o pragma é considerado.  Os argumentos **on** e **off** ativam e desativam as opções especificadas em *lista de otimização*.  
  
 A *lista de otimização* pode ser zero ou mais dos parâmetros mostrados na tabela a seguir.  
  
### Parâmetros do pragma de otimização  
  
|Parâmetro\(s\)|Tipo de otimização|  
|--------------------|------------------------|  
|**g**|Habilita as otimizações globais.|  
|**s** ou **t**|Especifica sequências curtas ou rápidas de código de máquina.|  
|**y**|Gera ponteiros de quadro na pilha de programa.|  
  
 Essas são as mesmas letras usadas com as opções de compilador [\/O](../build/reference/o-options-optimize-code.md).  Por exemplo, o pragma a seguir é equivalente à opção de compilador **\/Os**:  
  
```  
#pragma optimize( "ts", on )  
```  
  
 O uso do pragma **optimize** com a cadeia de caracteres vazia \(**""**\) é um formato especial de política:  
  
 Quando você usa o parâmetro **off**, ele desativa as otimizações listadas anteriormente na tabela neste tópico.  
  
 Quando você usa o parâmetro **on**, ele redefine as otimizações a que você especificou com a opção de compilador [\/O](../build/reference/o-options-optimize-code.md).  
  
```  
#pragma optimize( "", off )  
.  
.  
.  
#pragma optimize( "", on )   
```  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)