---
title: C3168 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3168
dev_langs:
- C++
helpviewer_keywords:
- C3168
ms.assetid: 4c36fcfb-c351-48ff-b4eb-78d2aa1b4d55
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 83f0d6c6b35d863ee200798bd4c6a8bcd08d88ab
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33245232"
---
# <a name="compiler-error-c3168"></a>C3168 de erro do compilador
'type': tipo subjacente inválido para enum  
  
O tipo subjacente especificado para o `enum` tipo não era válido. O tipo subjacente deve ser um tipo integral de C++ ou um tipo CLR correspondente.  
  
O exemplo a seguir gera C3168:  
  
```  
// C3168.cpp  
// compile with: /clr /c  
ref class G{};  
  
enum class E : G { e };   // C3168  
enum class F { f };   // OK  
```  
