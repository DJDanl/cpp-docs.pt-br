---
title: C3071 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3071
dev_langs: C++
helpviewer_keywords: C3071
ms.assetid: 69879e66-a60e-4058-9bbd-d5c5e2d8ee37
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: dfe7bf24ac7b81387420a52cfb9f39989fe43b68
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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