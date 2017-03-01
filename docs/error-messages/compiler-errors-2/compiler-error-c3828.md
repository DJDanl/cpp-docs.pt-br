---
title: C3828 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3828
dev_langs:
- C++
helpviewer_keywords:
- C3828
ms.assetid: 8d9cee75-9504-4bc8-88b6-2413618a3f45
caps.latest.revision: 11
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b42765591d0e2311706049b3fac66fab147662ce
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3828"></a>C3828 de erro do compilador
tipo de objeto: argumentos de posicionamento não permitidos enquanto a criação de instâncias de gerenciado ou WinRTclasses  
  
 Ao criar um objeto de um tipo gerenciado ou tempo de execução do Windows, você não pode usar o formulário de posicionamento do operador [ref new, gcnew](../../windows/ref-new-gcnew-cpp-component-extensions.md) ou [novo](../../cpp/new-operator-cpp.md).  
  
 O exemplo a seguir gera C3828 e mostra como corrigi-lo:  
  
```  
// C3828a.cpp  
// compile with: /clr  
ref struct M {  
};  
  
ref struct N {  
   static array<char>^ bytes = gcnew array<char>(256);  
};  
  
int main() {  
   M ^m1 = new (&N::bytes) M();   // C3828  
   // The following line fixes the error.  
   // M ^m1 = gcnew M();  
}  
```
