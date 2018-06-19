---
title: C3708 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3708
dev_langs:
- C++
helpviewer_keywords:
- C3708
ms.assetid: 45e71564-9c7f-437f-98d8-a735ce162ed0
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3d54f61af55cb768251dd60e261d26ba8e990ee8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33275217"
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