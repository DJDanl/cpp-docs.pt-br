---
title: C2357 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2357
dev_langs:
- C++
helpviewer_keywords:
- C2357
ms.assetid: d1083945-0ea2-4385-9e66-8c665978806c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 4c8739576eced6b831f5c3b72d85417e2daabb06
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33196575"
---
# <a name="compiler-error-c2357"></a>C2357 de erro do compilador
'Identificador': deve ser uma função de tipo 'type'  
  
 O código declara uma versão do `atexit` função que não coincide com a versão declarada internamente pelo compilador. Declarar `atexit` da seguinte maneira:  
  
```  
int __cdecl atexit(void (__cdecl *)());  
```  
  
 Para obter mais informações, consulte [init_seg](../../preprocessor/init-seg.md).  
  
 O exemplo a seguir gera C2357:  
  
```  
// C2357.cpp  
// compile with: /c  
// C2357 expected  
#pragma warning(disable : 4075)  
// Uncomment the following line to resolve.  
// int __cdecl myexit(void (__cdecl *)());  
#pragma init_seg(".mine$m",myexit)  
```