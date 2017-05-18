---
title: C2061 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2061
dev_langs:
- C++
helpviewer_keywords:
- C2061
ms.assetid: b0e61c0c-a205-4820-b9aa-301d6c6fe6eb
caps.latest.revision: 12
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
ms.openlocfilehash: 06a14e3c7c05af5cac03c7b0a49cef6a6b9fdfeb
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2061"></a>C2061 de erro do compilador
Erro de sintaxe: identificador 'Identificador'  
  
 O compilador encontrar um identificador onde ele não era esperado. Verifique se `identifier` é declarado antes de você usá-lo.  
  
 Um inicializador pode ser delimitado por parênteses. Para evitar esse problema, coloque o declarador entre parênteses ou torná-lo um `typedef`.  
  
 Esse erro também pode ser causado quando o compilador detecta uma expressão como um argumento de modelo de classe; Use [typename](../../cpp/typename.md) para dizer ao compilador é um tipo.  
  
 O exemplo a seguir gera C2061:  
  
```  
// C2061.cpp  
// compile with: /c  
template < A a >   // C2061  
// try the following line instead  
// template < typename b >  
class c{};  
```  
  
 C2061 pode ocorrer se você passar um nome de instância para [typeid](../../windows/typeid-cpp-component-extensions.md):  
  
```  
// C2061b.cpp  
// compile with: /clr  
ref struct G {  
   int i;  
};  
  
int main() {  
   G ^ pG = gcnew G;  
   System::Type ^ pType = typeid<pG>;   // C2061  
   System::Type ^ pType2 = typeid<G>;   // OK  
}  
```
