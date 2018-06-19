---
title: C3612 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3612
dev_langs:
- C++
helpviewer_keywords:
- C3612
ms.assetid: aa6e3a2b-4afa-481c-98c1-1b6d1f82f869
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e07c899dbacdc58e9048ffa21d6be1b6abc02632
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33252839"
---
# <a name="compiler-error-c3612"></a>C3612 de erro do compilador
'type': uma classe sealed não pode ser abstrata  
  
Tipos definidos usando `value` são lacradas por padrão, e uma classe é abstrata, a menos que ele implementa todos os métodos de sua base. Uma classe sealed abstract não pode ser uma classe base nem pode ser instanciado.  
  
Para obter mais informações, consulte [Classes e estruturas](../../windows/classes-and-structs-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C3612:  
  
```  
// C3612.cpp  
// compile with: /clr /c  
value struct V: public System::ICloneable {};   // C3612  
  
// OK  
value struct V2: public System::ICloneable {  
   Object^ Clone();  
};  
```