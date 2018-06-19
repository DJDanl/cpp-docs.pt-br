---
title: C3707 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3707
dev_langs:
- C++
helpviewer_keywords:
- C3707
ms.assetid: ac63a5dd-7a4b-48d2-9f2a-be9cb090134c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7268f584d9f269b4f2f15b837379ec12ab0185d8
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33273719"
---
# <a name="compiler-error-c3707"></a>C3707 de erro do compilador
'function': método dispinterface deve possuir um dispid  
  
 Se você usar um `dispinterface` método, é necessário atribuir um `dispid`. Para corrigir esse erro, atribua um `dispid` para o `dispinterface` método, por exemplo, removendo marca de comentário de `id` atributo no método no exemplo abaixo. Para obter mais informações, consulte os atributos [dispinterface](../../windows/dispinterface.md) e [id](../../windows/id.md).  
  
 O exemplo a seguir gera C3707:  
  
```  
// C3707.cpp  
#include <atlbase.h>  
#include <atlcom.h>  
#include <atlctl.h>  
  
[module(name="xx")];  
[dispinterface]  
__interface IEvents : IDispatch  
{  
   HRESULT event1([in] int i);   // C3707  
   // try the following line instead  
   // [id(1)] HRESULT event1([in] int i);  
};  
  
int main() {  
}  
```