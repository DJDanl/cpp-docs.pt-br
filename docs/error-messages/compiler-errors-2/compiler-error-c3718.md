---
title: C3718 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3718
dev_langs:
- C++
helpviewer_keywords:
- C3718
ms.assetid: 346b5205-c44d-49d3-b66a-96417d3d6986
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 87a41b0937935038cf4f6d30d2abc1f47afef7c2
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3718"></a>C3718 de erro do compilador
somente é possível chamar 'event' no contexto de uma função de membro da classe recebedora  
  
 O `event` só pode ser chamado da classe de recebimento.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3718:  
  
```  
// C3718.cpp  
#define _ATL_ATTRIBUTES 1  
#include "atlbase.h"  
#include "atlcom.h"  
  
[module(name="test")];  
  
[object, uuid("00000000-0000-0000-0000-000000000001")]  
__interface I  
{  
    HRESULT f();  
};  
  
[event_source(com), coclass, uuid("00000000-0000-0000-0000-000000000002")]  
struct E  
{  
    __event __interface I;  
};  
  
[event_receiver(com)]  
struct R  
{  
    void b()  
    {  
        printf_s("B::bar()\n");   
    }  
  
    void HookAndRun(E* pE)  
    {  
        __hook(&I::f, pE->GetUnknown(), &R::b);  
        __raise pE->f();  
    }  
};  
  
int main()  
{  
    CComObject<E>* pE;  
    CComObject<E>::CreateInstance(&pE);  
  
    __hook(&I::f, pE->GetUnknown(), &R::b, &r);   // C3718  
    __raise pE->f();  
    // try the following lines instead  
    // R r;  
    // r.HookAndRun(pE);  
}  
```
