---
title: C3358 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3358
dev_langs:
- C++
helpviewer_keywords:
- C3358
ms.assetid: 180b93df-e78f-441a-91fb-1594c681f7f0
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: bcb1ebe23b9772efb885fe547cd03c9af9c39cf7
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3358"></a>C3358 de erro do compilador
'symbol': símbolo não encontrado  
  
 O símbolo necessário não foi encontrado.  
  
 O exemplo a seguir gera C3358:  
  
```  
// C3358.cpp  
#define __ATLEVENT_H__ 1   // remove this line to resolve the error  
#define _ATL_ATTRIBUTES 1  
#include "atlbase.h"  
#include "atlcom.h"  
  
[event_receiver(com)]  
struct A   // C3358  
{  
   void func();  
};  
  
int main()  
{  
}  
```
