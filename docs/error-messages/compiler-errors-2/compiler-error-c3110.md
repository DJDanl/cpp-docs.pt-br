---
title: C3110 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3110
dev_langs:
- C++
helpviewer_keywords:
- C3110
ms.assetid: 821dc71f-896e-4b2d-af0e-aa9932934b7b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5a0e21b964b8a9b38961de24c94aee3b69ade651
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33246764"
---
# <a name="compiler-error-c3110"></a>C3110 de erro do compilador
'function_name': não é possível sobrecarregar um método de interface COM  
  
 Uma interface que é precedida por um atributo de interface, tais como:  
  
-   [custom](../../windows/custom-cpp.md)  
  
-   [dispinterface](../../windows/dispinterface.md)  
  
-   [dual](../../windows/dual.md)  
  
-   [object](../../windows/object-cpp.md)  
  
 não podem ser sobrecarregados. Por exemplo:  
  
```  
// C3110.cpp  
#include <unknwn.h>  
[ object, uuid= "4F98A180-EF37-11D1-978D-0000F805D73B" ]  
__interface ITestInterface  
{  
   HRESULT mf1(void);  
   HRESULT mf1(BSTR); // C3110  
};  
  
int main()  
{  
}  
```