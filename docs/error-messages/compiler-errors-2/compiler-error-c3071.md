---
title: C3071 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3071
dev_langs:
- C++
helpviewer_keywords:
- C3071
ms.assetid: 69879e66-a60e-4058-9bbd-d5c5e2d8ee37
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 163cb170953c444789e39b906ff4d408739f7514
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3071"></a>C3071 de erro do compilador
operador 'operator' só pode ser aplicado a uma instância de uma classe ou um tipo de valor  
  
 Um operador CLR não pode ser usado em um tipo nativo. O operador pode ser usado em uma classe ref ou uma estrutura (um tipo de valor), mas não é um tipo nativo como int ou um alias para um tipo nativo como System::Int32. Esses tipos não podem ser convertidos de código C++ de forma que se refere à variável nativo para que o operador não pode ser usado.  
  
 Para obter mais informações, consulte [operador de referência de rastreamento](../../windows/tracking-reference-operator-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3071.  
  
```  
// C3071.cpp  
// compile with: /clr  
class N {};  
ref struct R {};  
  
int main() {  
   N n;  
   %n;   // C3071  
  
   R r;  
   R ^ r2 = %r;   // OK  
}  
```