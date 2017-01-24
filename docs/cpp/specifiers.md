---
title: "Especificadores | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "especificadores de declaração"
  - "declarações, especificadores"
  - "especificadores, em declarações"
ms.assetid: 8b14e844-9880-4571-8779-28c8efe44633
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Especificadores
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico descreve o *especificadores* componente \(especificadores de declaração\) de um [declaração](../misc/declarations.md).  
  
 Os seguintes espaços reservados e palavras\-chave são especificadores de declaração:  
  
 *especificador de classe de armazenamento*  
  
 *especificador de tipo*  
  
 *especificador de função*  
  
 [friend](../cpp/friend-cpp.md)  
  
 [typedef](http://msdn.microsoft.com/pt-br/cc96cf26-ba93-4179-951e-695d1f5fdcf1)  
  
 [declspec](../cpp/declspec.md) `(` *extended\-decl\-modifier\-seq* `)`  
  
## Comentários  
 O *especificadores* parte de uma declaração é a seqüência mais longa de *especificadores* que pode ser utilizada para significar um nome de tipo, não incluindo o ponteiro ou modificadores de referência.  O restante da declaração é a *declarador*, que inclui o nome apresentado.  
  
 A tabela a seguir lista quatro declarações e, em seguida, lista cada declaração *decl especificadores* e *declarador* componentes separadamente.  
  
|Declaração|*especificadores*|`declarator`|  
|----------------|-----------------------|------------------|  
|`char *lpszAppName;`|`char`|`*lpszAppName`|  
|`typedef char * LPSTR;`|`char`|`*LPSTR`|  
|`const int func1();`|`const int`|`func1`|  
|`volatile void *pvvObj;`|`volatile void`|`*pvvObj`|  
  
 Como `signed`, `unsigned`, `long`, e `short` implicam `int`, um `typedef` nome seguir uma dessas palavras\-chave é considerada como um membro do *lista de declaradores,* não é do *especificadores*.  
  
> [!NOTE]
>  Como um nome pode ser declarado novamente, sua interpretação está sujeita à declaração mais recente no escopo atual.  A nova declaração pode afetar a forma como os nomes são interpretados pelo compilador, principalmente os nomes de `typedef`.  
  
## Consulte também  
 [Declarações](../misc/declarations.md)