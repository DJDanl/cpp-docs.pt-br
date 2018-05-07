---
title: C3219 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3219
dev_langs:
- C++
helpviewer_keywords:
- C3219
ms.assetid: 9c9757b0-1256-4cdf-9d8c-a3a72f300ce5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 16341412ae5028753b2a542b45da4ea2b549c29e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3219"></a>C3219 de erro do compilador
'param': parâmetro genérico não pode ser restrito por várias não interfaces: 'class'  
  
 Não é válido para restringir um parâmetro genérico por dois ou mais classes gerenciadas.  
  
 O exemplo a seguir gera C3219:  
  
```  
// C3219.cpp  
// compile with: /clr  
ref class A {};  
ref class B {};  
  
generic <class T>  
where T : A, B  
ref class E {};   // C3219  
```  
  
 O exemplo a seguir demonstra uma possível resolução:  
  
```  
// C3219b.cpp  
// compile with: /clr /c  
ref class A {};  
  
interface struct C {};  
  
generic <class T>  
where T : A  
ref class E {};  
```