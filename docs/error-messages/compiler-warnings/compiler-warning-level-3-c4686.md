---
title: "Compilador aviso (nível 3) C4686 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4686
dev_langs: C++
helpviewer_keywords: C4686
ms.assetid: 767c83c2-9e4b-4f9e-88c8-02128ba563f4
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 576e714937f0066a7b60ebf38d821715d4157b11
ms.sourcegitcommit: ca2f94dfd015e0098a6eaf5c793ec532f1c97de1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2017
---
# <a name="compiler-warning-level-3-c4686"></a>Compilador C4686 de aviso (nível 3)
**'**   
 ***tipo definido pelo usuário* ': possível alteração em comportamento, alteração no UDT retornar a convenção de chamada**  
  
 Uma especialização de modelo de classe não foi está definido antes que ele foi usado em um tipo de retorno. Tudo o que cria uma instância da classe será resolvido C4686; declarando uma instância ou acessar um membro (C\<int >:: nada) também são opções.  
  
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