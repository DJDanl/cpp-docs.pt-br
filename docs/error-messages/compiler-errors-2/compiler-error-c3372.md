---
title: C3372 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3372
dev_langs:
- C++
helpviewer_keywords:
- C3372
ms.assetid: 38ee39ed-03ff-4e6d-9104-f1977b96645d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 29cad4056a06a3070808bfcd92bc6d17bde9333d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3372"></a>C3372 de erro do compilador
Especifique pelo menos 1 interface para atributo 'fonte' em uma coclass  
  
 Para determinados atributos, você deve passar um nome de interface como um parâmetro.  
  
 O exemplo a seguir gera C3372:  
  
```  
// C3372.cpp  
#include <windows.h>  
[module(name="MyModule")];  
  
[ object, uuid(373a1a4c-469b-11d3-a6b0-00c04f79ae8f) ]  
__interface IMyIface {  
   HRESULT f1();  
};  
// to resolve, pass an interface name to the source attribute  
// for example, source(IMyIface)  
[ coclass, uuid(373a1a4d-469b-11d3-a6b0-00c04f79ae8f), source,   
  default(IMyIface) ] // C3372  
class CMyClass {  
};  
  
int main() {  
}  
```