---
title: "Operador de caracteriza&#231;&#227;o (#@) | Microsoft Docs"
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
  - "#@"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Operador de pré-processador  #@"
  - "Operador charizing"
  - "pré-processador, operadores"
ms.assetid: dee03314-d27c-4063-965c-64756efbef22
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Operador de caracteriza&#231;&#227;o (#@)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 O operador de charizing pode usado apenas com os argumentos das macros.  Se **\#@** preceder um parâmetro formal na definição da macro, o argumento real é encapsulado em aspas simples e tratado como um caractere quando uma macro for expandida.  Por exemplo:  
  
```  
#define makechar(x)  #@x  
```  
  
 faz com que a instrução  
  
```  
a = makechar(b);  
```  
  
 seja expandida para  
  
```  
a = 'b';  
```  
  
 O caractere de aspas simples não pode ser usado com o operador de charizing.  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [Operadores de pré\-processador](../preprocessor/preprocessor-operators.md)