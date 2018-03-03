---
title: C3279 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3279
dev_langs:
- C++
helpviewer_keywords:
- C3279
ms.assetid: 639afc20-984c-4a95-be35-8bf9409f02d5
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 4535edc3ccca0c5abd972e31ee7284fad7384c31
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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