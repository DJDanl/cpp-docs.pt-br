---
title: C3216 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3216
dev_langs:
- C++
helpviewer_keywords:
- C3216
ms.assetid: bbab1efe-8779-4489-8bb0-b11e45f5cbe5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 19091b0e200bb44ca6c1ec7c9a8ee359a95fad1e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33247642"
---
# <a name="compiler-error-c3216"></a>C3216 de erro do compilador
a restrição deve ser um parâmetro genérico, não 'type'  
  
 Uma restrição ill foi formada.  
  
 O exemplo a seguir gera C3216:  
  
```  
// C3216.cpp  
// compile with: /clr  
interface struct A {};  
  
generic <class T>  
where F : A   // C3216  
// Try the following line instead:  
// where T : A    // C3216  
ref class C {};  
```  
  
 O exemplo a seguir demonstra uma possível resolução:  
  
```  
// C3216b.cpp  
// compile with: /clr /c  
interface struct A {};  
  
generic <class T>  
where T : A  
ref class C {};  
```