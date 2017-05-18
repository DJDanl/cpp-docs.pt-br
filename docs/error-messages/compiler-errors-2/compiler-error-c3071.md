---
title: C3071 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3071
dev_langs:
- C++
helpviewer_keywords:
- C3071
ms.assetid: 69879e66-a60e-4058-9bbd-d5c5e2d8ee37
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 11abc98378bd77dafe4a741fb7f7d5ea83ba3d4c
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3071"></a>C3071 de erro do compilador
operador 'operator' só pode ser aplicado a uma instância de uma classe ref ou um tipo de valor  
  
 Um operador CLR não pode ser usado em um tipo nativo. O operador pode ser usado em uma classe ref ou um struct ref (um tipo de valor), mas não um tipo nativo como int ou um alias para um tipo nativo como System:: Int32. Esses tipos não podem ser convertidos no código C++ de forma que se refere à variável nativa para que o operador não pode ser usado.  
  
 Para obter mais informações, consulte [operador de referência de controle](../../windows/tracking-reference-operator-cpp-component-extensions.md).  
  
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
