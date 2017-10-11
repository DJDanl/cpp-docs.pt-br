---
title: C3139 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3139
dev_langs:
- C++
helpviewer_keywords:
- C3139
ms.assetid: 95c92263-10ac-4ff3-b385-6312dd92adbc
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: 2982e615e2e99bfa64cb73a707af703f04d1ebf0
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3139"></a>C3139 de erro do compilador
'struct': não é possível exportar um UDT sem membros  
  
 Você tentou se aplicam a [exportar](../../windows/export.md) atributo a uma UDT vazio (tipo definido pelo usuário). Por exemplo:  
  
```  
// C3139.cpp  
#include "unknwn.h"  
[emitidl];  
[module(name=xx)];  
  
[export] struct MyStruct {   // C3139 empty type  
};  
int main(){}  
```
