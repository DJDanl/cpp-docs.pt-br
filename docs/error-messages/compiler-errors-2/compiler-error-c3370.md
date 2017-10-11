---
title: C3370 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3370
dev_langs:
- C++
helpviewer_keywords:
- C3370
ms.assetid: ee6d4c85-78fc-42b2-836e-5cc491a3b2ba
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b1a6a450c0c3faca9088b01e1016df5f4e5a4045
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-error-c3370"></a>C3370 de erro do compilador
'idl_module name': idl_module ainda não foi definido  
  
 Antes de usar [idl_module](../../windows/idl-module.md) para especificar um ponto de entrada em uma DLL, você deve primeiro usar `idl_module` para especificar o nome da DLL.  
  
 O exemplo a seguir gera C3370:  
  
```  
// C3370.cpp  
[module(name=MyLibrary)];  
// uncomment the following line to resolve the error  
// [idl_module(name="name1", dllname=x.dll)];  
[idl_module(name="name1"), entry(100)] // C3370  
int f1();  
  
int main()  
{  
}  
```
