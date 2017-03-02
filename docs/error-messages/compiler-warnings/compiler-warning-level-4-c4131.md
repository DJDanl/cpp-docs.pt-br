---
title: "Compilador aviso (nível 4) C4131 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-csharp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4131
dev_langs:
- C++
helpviewer_keywords:
- C4131
ms.assetid: 7903b3e1-454f-4be2-aa9b-230992f96a2d
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 4bc0d1262026998e79e365e9d47fba0186636f00
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4131"></a>Compilador C4131 de aviso (nível 4)
'function': usa o declarador de estilo antigo  
  
 A declaração de função especificado não está no formato de protótipo.  
  
 Declarações de função de estilo antigo devem ser convertidas em forma de protótipo.  
  
 O exemplo a seguir mostra uma declaração de função de estilo antigo:  
  
```  
// C4131.c  
// compile with: /W4 /c  
void addrec( name, id ) // C4131 expected  
char *name;  
int id;  
{ }  
```  
  
 O exemplo a seguir mostra um formulário de protótipo:  
  
```  
void addrec( char *name, int id )  
{ }  
```
