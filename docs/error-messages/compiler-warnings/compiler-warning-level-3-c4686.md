---
title: "Compilador aviso (nível 3) C4686 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4686
dev_langs:
- C++
helpviewer_keywords:
- C4686
ms.assetid: 767c83c2-9e4b-4f9e-88c8-02128ba563f4
caps.latest.revision: 8
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
ms.openlocfilehash: 9d6ef8c948e93a9916ff79f06f9aad5cd200c0e9
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-3-c4686"></a>Compilador C4686 de aviso (nível 3)
**'**   
 ***tipo definido pelo usuário* ': possível alteração no comportamento, alteração no UDT retornar a convenção de chamada**  
  
 Uma especialização de modelo de classe não foi é definida para que foi usado em um tipo de retorno. Qualquer coisa que instancia a classe resolverá C4686; declarar uma instância ou acessar um membro (C\<int >:: nada) também são opções.  
  
 Esse aviso é o resultado do trabalho para tornar o compilador do Visual C++ .NET 2003 estão em conformidade com ISO C++ padrão.  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../../preprocessor/compiler-warnings-that-are-off-by-default.md) para obter mais informações.  
  
 Tente o seguinte em vez disso,  
  
```  
// C4686.cpp  
// compile with: /W3  
#pragma warning (default : 4686)  
template <class T>  
class C;  
  
template <class T>  
C<T> f(T);  
  
template <class T>  
class C {};  
  
int main() {  
   f(1);   // C4686  
}  
  
template <class T>  
C<T> f(T) {  
   return C<int>();  
}  
```
