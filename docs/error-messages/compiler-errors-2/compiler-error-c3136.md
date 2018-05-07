---
title: C3136 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3136
dev_langs:
- C++
helpviewer_keywords:
- C3136
ms.assetid: c77103cd-00f7-408e-b74b-4f8562039d31
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f892c7f3d1ca7bf2aebf3ecfe7574182b544fd01
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3136"></a>C3136 de erro do compilador
'interface': uma interface COM só pode herdar de outra interface COM, 'interface' não é uma interface COM  
  
 Uma interface para o qual você aplicou um [atributo interface](../../windows/interface-attributes.md) herda de uma interface que não é uma interface COM. Uma interface COM, por fim, herda de `IUnknown`. Nenhuma interface precedido por um atributo de interface é uma interface COM.  
  
 O exemplo a seguir gera C3136:  
  
```  
// C3136.cpp  
#include "unknwn.h"  
  
__interface A   // C3136  
// try the following line instead  
// _interface A : IUnknown  
{  
   int a();  
};  
  
[object]  
__interface B : A  
{  
   int aa();  
};  
```