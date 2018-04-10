---
title: Especificadores de | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- declaration specifiers
- declarations, specifiers
- specifiers, in declarations
ms.assetid: 8b14e844-9880-4571-8779-28c8efe44633
caps.latest.revision: 9
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 352ef898c9380c55e90205129ba6fe48bf352856
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="specifiers"></a>Especificadores
Este tópico descreve o *especificadores de decl* componente (especificadores de declaração) de um [declaração](declarations-and-definitions-cpp.md).  
  
 Os seguintes espaços reservados e palavras-chave são especificadores de declaração:  
  
 *especificador de classe de armazenamento*  
  
 *especificador de tipo*  
  
 *especificador de função*  
  
 [Friend](../cpp/friend-cpp.md)  
  
 [typedef](http://msdn.microsoft.com/en-us/cc96cf26-ba93-4179-951e-695d1f5fdcf1)  
  
 [declspec](../cpp/declspec.md) `(` *estendidos-decl-modificador-seq*`)`  
  
## <a name="remarks"></a>Comentários  
 O *especificadores de decl* parte de uma declaração é a sequência mais longa do *especificadores de decl* que podem ser tomadas para significar um nome de tipo, não incluindo o ponteiro ou referência modificadores. O resto da declaração de *declarador*, que inclui o nome introduzido.  
  
 A tabela a seguir lista as quatro declarações e, em seguida, lista cada declaração *decl especificadores* e *declarador* componente separadamente.  
  
|Declaração|*especificadores de Decl*|`declarator`|  
|-----------------|------------------------|------------------|  
|`char *lpszAppName;`|`char`|`*lpszAppName`|  
|`typedef char * LPSTR;`|`char`|`*LPSTR`|  
|`const int func1();`|`const int`|`func1`|  
|`volatile void *pvvObj;`|`volatile void`|`*pvvObj`|  
  
 Porque `signed`, `unsigned`, `long`, e `short` todos implicam `int`, um `typedef` nome a seguir uma destas palavras-chave é necessário para ser um membro do *lista de declaradores,* não de *especificadores de decl*.  
  
> [!NOTE]
>  Como um nome pode ser declarado novamente, sua interpretação está sujeita à declaração mais recente no escopo atual. A nova declaração pode afetar a forma como os nomes são interpretados pelo compilador, principalmente os nomes de `typedef`.  
  
## <a name="see-also"></a>Consulte também  
 [Declarações e definições](declarations-and-definitions-cpp.md)