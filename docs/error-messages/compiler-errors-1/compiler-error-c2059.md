---
title: C2059 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2059
dev_langs:
- C++
helpviewer_keywords:
- C2059
ms.assetid: 2be4eb39-3f37-4b32-8e8d-75835e07c78a
caps.latest.revision: 22
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: dbf80ab803eaaacc29ac82657af130194417f1c7
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="compiler-error-c2059"></a>C2059 de erro do compilador
Erro de sintaxe: 'token'  
  
 O token causou um erro de sintaxe.  
  
 O exemplo a seguir gera uma mensagem de erro para a linha que declara `j`.  
  
```  
// C2059e.cpp  
// compile with: /c  
// C2143 expected  
// Error caused by the incorrect use of '*'.  
   int j*; // C2059   
```  
  
 Para determinar a causa do erro, examine não apenas a linha que está listada na mensagem de erro, mas também as linhas acima dele. Se examinar as linhas não produz nenhuma pista sobre o problema, tente comentar a linha que está listada na mensagem de erro e talvez várias linhas acima dele.  
  
 Se a mensagem de erro ocorre em um símbolo que segue imediatamente um `typedef` variável, certifique-se de que a variável é definida no código-fonte.  
  
 Você pode obter C2059 se um símbolo for avaliada como nothing, pois pode ocorrer quando **/D** `symbol`  **=**  é usada para compilar.  
  
```  
// C2059a.cpp  
// compile with: /DTEST=  
#include <stdio.h>  
  
int main() {  
   #ifdef TEST  
      printf_s("\nTEST defined %d", TEST);   // C2059  
   #else  
      printf_s("\nTEST not defined");  
   #endif  
}  
```  
  
 Outro caso em que C2059 pode ocorrer é quando você compila um aplicativo que especifica uma estrutura nos argumentos padrão para uma função. O valor padrão para um argumento deve ser uma expressão. Uma lista de inicializadores — por exemplo, um que é usado para inicializar uma estrutura — não é uma expressão.  Para resolver esse problema, defina um construtor para executar a inicialização exigida.  
  
 O exemplo a seguir gera C2059:  
  
```  
// C2059b.cpp  
// compile with: /c  
struct ag_type {  
   int a;  
   float b;  
   // Uncomment the following line to resolve.  
   // ag_type(int aa, float bb) : a(aa), b(bb) {}   
};  
  
void func(ag_type arg = {5, 7.0});   // C2059  
void func(ag_type arg = ag_type(5, 7.0));   // OK  
```  
  
 Você também pode obter C2059 se você definir uma classe de modelo de membro ou função fora da classe. Para obter informações, consulte [artigo da Base de dados de Conhecimento 241949](http://support.microsoft.com/kb/241949).  
  
 C2059 pode ocorrer devido a uma conversão mal formados.  
  
 O exemplo a seguir gera C2059:  
  
```  
// C2059c.cpp  
// compile with: /clr  
using namespace System;  
ref class From {};  
ref class To : public From {};  
  
int main() {  
   From^ refbase = gcnew To();  
   To^ refTo = safe_cast<To^>(From^);   // C2059  
   To^ refTo2 = safe_cast<To^>(refbase);   // OK  
}  
```  
  
 C2059 também pode ocorrer se você tentar criar um nome de namespace que contém um ponto.  
  
 O exemplo a seguir gera C2059:  
  
```  
// C2059d.cpp  
// compile with: /c  
namespace A.B {}   // C2059  
  
// OK  
namespace A  {  
   namespace B {}  
}  
```  
  
 C2059 pode ocorrer quando um operador que pode ser um nome qualificado (`::`, `->`, e `.`) deve ser seguido da palavra-chave `template`, conforme mostrado neste exemplo:  
  
```cpp  
template <typename T> struct Allocator {  
    template <typename U> struct Rebind {  
        typedef Allocator<U> Other;  
    };  
};  
  
template <typename X, typename AY> struct Container {  
    typedef typename AY::Rebind<X>::Other AX; // error C2059  
};  
  
```  
  
 Por padrão, o C++ supõe que `AY::Rebind` não é um modelo; portanto, o seguinte `<` é interpretado como um valor menor-sinal.  Você deve informar o compilador explicitamente que `Rebind` é um modelo para que ele pode analisar corretamente o colchete angular. Para corrigir esse erro, use o `template` palavra-chave no nome do tipo dependentes, como mostrado aqui:  
  
```cpp  
template <typename T> struct Allocator {  
    template <typename U> struct Rebind {  
        typedef Allocator<U> Other;  
    };  
};  
  
template <typename X, typename AY> struct Container {  
    typedef typename AY::template Rebind<X>::Other AX; // correct  
};  
  
```
