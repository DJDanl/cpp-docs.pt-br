---
title: C3279 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3279
dev_langs:
- C++
helpviewer_keywords:
- C3279
ms.assetid: 639afc20-984c-4a95-be35-8bf9409f02d5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0a86f3dd637f84901559c4be8443a81425347237
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33256816"
---
# <a name="compiler-error-c3279"></a>C3279 de erro do compilador
especializações parciais e explícitas bem como instanciações explícitas de modelos de classe declaradas no namespace cli não são permitidas  
  
 O `cli` namespace é definida pela Microsoft e contém os modelos de pseudo. O compilador do Visual C++ não permite especializações definida pelo usuário, parciais e explícitas e instanciações explícitas de modelos de classe neste namespace.  
  
 O exemplo a seguir gera C3279:  
  
```  
// C3279.cpp  
// compile with: /clr  
namespace cli {  
   template <> ref class array<int> {};   // C3279  
   template <typename T> ref class array<T, 2> {};   // C3279  
}  
```