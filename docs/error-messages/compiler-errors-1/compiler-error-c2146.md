---
title: C2146 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2146
dev_langs: C++
helpviewer_keywords: C2146
ms.assetid: 6bfb7de6-6723-4486-9350-c66ef88d7a64
caps.latest.revision: "14"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a7da8021cabb5eab31ae12912374268ee4d7d24b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2146"></a>C2146 de erro do compilador
Erro de sintaxe: token antes do identificador 'Identificador' não tem  
  
 O compilador esperado `token` e encontrado `identifier` em vez disso.  Possíveis causas:  
  
1.  Erro de ortografia ou de capitalização.  
  
2.  Especificador de tipo ausente na declaração do identificador.  
  
 Esse erro pode ser causado por um erro de digitação. Erro [C2065](../../error-messages/compiler-errors-1/compiler-error-c2065.md) precede geralmente esse erro.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2146.  
  
```  
// C2146.cpp  
class CDeclaredClass {};  
  
class CMyClass {  
   CUndeclared m_myClass;   // C2146  
   CDeclaredClass m_myClass2;   // OK  
};  
  
int main() {  
   int x;  
   int t x;   // C2146 : missing semicolon before 'x'  
}  
```  
  
## <a name="example"></a>Exemplo  
 Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: ausente `typename` palavra-chave.  
  
 O exemplo a seguir é compilado no Visual Studio .NET 2002, mas não no Visual Studio .NET 2003:  
  
```  
// C2146b.cpp  
// compile with: /c  
template <typename T>  
struct X {  
   struct Y {  
      int i;  
   };  
   Y memFunc();  
};  
  
template <typename T>  
X<T>::Y func() { }   // C2146  
  
// OK  
template <typename T>  
typename X<T>::Y func() { }  
```  
  
## <a name="example"></a>Exemplo  
 Você também verá esse erro como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: especializações explícitas não localizar os parâmetros de modelo do modelo principal.  
  
 O uso de `T` do modelo principal não é permitida na especialização explícita. Para o código seja válido nas versões do Visual Studio .NET 2003 e o Visual Studio .NET do Visual C++, substitua todas as instâncias do parâmetro de modelo na especialização com o tipo explicitamente especializado.  
  
 O exemplo a seguir é compilado no Visual Studio .NET, mas não no Visual Studio .NET 2003:  
  
```  
// C2146_c.cpp  
// compile with: /c  
template <class T>   
struct S;  
  
template <>   
struct S<int> {  
   T m_t;   // C2146  
   int m_t2;   // OK  
};  
```