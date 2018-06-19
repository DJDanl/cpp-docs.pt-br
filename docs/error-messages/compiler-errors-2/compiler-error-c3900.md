---
title: C3900 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3900
dev_langs:
- C++
helpviewer_keywords:
- C3900
ms.assetid: a94cc561-8fa8-4344-9e01-e81ff462fae5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fc940d174edc337422818bc233c1ef9952b66276
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33269074"
---
# <a name="compiler-error-c3900"></a>C3900 de erro do compilador
'member': não é permitida no escopo atual  
  
 Blocos de propriedade podem conter declarações de função e definições de função embutida somente. Não há membros que não sejam são permitidos em blocos de propriedade. Nenhuma função friend, operadores ou definições de tipo é permitidas. Para obter mais informações, consulte [propriedade](../../windows/property-cpp-component-extensions.md).  
  
 Definições de evento só podem conter funções e métodos de acesso.  
  
 O exemplo a seguir gera C3900:  
  
```  
// C3900.cpp  
// compile with: /clr  
ref class X {  
   property int P {  
      void set(int);   // OK  
      int i;   // C3900 variable declaration  
   };  
};  
```  
  
 O exemplo a seguir gera C3900:  
  
```  
// C3900b.cpp  
// compile with: /clr  
using namespace System;  
delegate void H();  
ref class X {  
   event H^ E {  
      int m;   // C3900  
  
      // OK  
      void Test() {}  
  
      void add( H^ h ) {}  
      void remove( H^ h ) {}  
      void raise( ) {}  
   }  
};  
```