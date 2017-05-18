---
title: C2165 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C2165
dev_langs:
- C++
helpviewer_keywords:
- C2165
ms.assetid: b108313b-b8cb-4dce-b2ec-f2b31c9cdc87
caps.latest.revision: 8
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: c9511650ab0714ad3350244133f1110c5b40e16c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2165"></a>C2165 de erro do compilador
'palavra-chave': não é possível modificar os ponteiros para os dados  
  
 O `__stdcall`, `__cdecl`, ou `__fastcall` palavra-chave tenta modificar um ponteiro para dados.  
  
 O exemplo a seguir gera C2165:  
  
```  
// C2165.cpp  
// compile with: /c  
char __cdecl *p;   // C2165  
char *p;   // OK  
```
