---
title: C3708 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3708
dev_langs:
- C++
helpviewer_keywords:
- C3708
ms.assetid: 45e71564-9c7f-437f-98d8-a735ce162ed0
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 8cc63e34c42f2c8d91c787530680d76e81192569
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3708"></a>C3708 de erro do compilador
'interface': uso inadequado de 'palavra-chave'; deve ser um membro de uma fonte de eventos compatível  
  
 Para declarar uma interface como um evento, a declaração de evento deve estar em uma fonte de evento.  
  
 O exemplo a seguir gera C3708:  
  
```  
// C3708.cpp  
// compile with: /c  
#define _ATL_ATTRIBUTES 1  
#include "atlbase.h"  
#include "atlcom.h"  
  
[ module(name="MyLibrary")];  
  
[ object, uuid("00000000-0000-0000-0000-000000000001") ]  
__interface I {  
   HRESULT func();  
};  
  
[ object, uuid("00000000-0000-0000-0000-000000000002") ]  
__interface II {  
   HRESULT func();  
};  
  
__event __interface I;   // C3708  
  
// put the event in an event source  
[ coclass, event_source(com), uuid("00000000-0000-0000-0000-000000000003") ]  
struct E : II {  
   __event __interface II;  
};  
```
