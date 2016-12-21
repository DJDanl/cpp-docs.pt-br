---
title: "C2143 de erro do compilador | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C2143"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2143"
ms.assetid: 1d8d1456-e031-4965-9240-09a6e33ba81c
caps.latest.revision: 23
caps.handback.revision: 23
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C2143 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

erro de sintaxe: “token1 ausentes” antes de “token2”  
  
 O compilador esperou um token específico \(isto é, um elemento de linguagem diferente do espaço em branco\) e encontrou um outro token em vez disso.  
  
 Para obter informações sobre este erro quando ocorre quando você está usando um bloco de com tentativa, consulte [Artigo da Base de Dados de Conhecimento 241706](http://support.microsoft.com/kb/241706).  
  
 Verifique [Referência de linguagem C\+\+](../../cpp/cpp-language-reference.md) para determinar onde o código está sintaticamente incorretas.  Como o compilador pode relatar este erro depois de encontrar a linha que faz com que o problema, verifique várias linhas de código que precedem o erro.  
  
 C2143 pode ocorrer em situações diferentes.  
  
 Pode ocorrer quando um operador que pode qualificar um nome \(`::`, `->`, e `.`\) deve ser seguido pela palavra\-chave `template`, como neste exemplo:  
  
```cpp  
class MyClass  
{  
    template<class Ty, typename PropTy>  
    struct PutFuncType : public Ty::PutFuncType<Ty, PropTy> // error C2143  
    {  
    };  
};  
  
```  
  
 Por padrão, C\+\+ supõe que `Ty::PutFuncType` não é um modelo; consequentemente, seguinte `<` é interpretado como menor que o sinal.  Você deve informar ao compilador explicitamente que `PutFuncType` é um modelo de forma que possa corretamente analisar o colchetes angulares.  Para corrigir esse erro, use a palavra\-chave no nome de `template` dependente do tipo, conforme mostrado aqui:  
  
```cpp  
class MyClass  
{  
    template<class Ty, typename PropTy>  
    struct PutFuncType : public Ty::template PutFuncType<Ty, PropTy> // correct  
    {  
    };  
};  
  
```  
  
 C2143 pode ocorrer quando **\/clr** é usado e uma política de `using` tem um erro de sintaxe:  
  
```cpp  
// C2143a.cpp  
// compile with: /clr /c  
using namespace System.Reflection;   // C2143  
using namespace System::Reflection;  
```  
  
 Também pode ocorrer quando você está tentando criar um arquivo de origem usando a sintaxe de CLR sem usar **\/clr**:  
  
```cpp  
// C2143b.cpp  
ref struct A {   // C2143 error compile with /clr  
   void Test() {}  
};  
  
int main() {  
   A a;  
   a.Test();  
}  
```  
  
 O primeiro caractere do não espaço em branco que segue uma instrução de `if` deve ser um parêntese esquerdo.  O compilador não pode traduzir algo:  
  
```cpp  
// C2143c.cpp  
int main() {  
   int j = 0;  
  
   // OK  
   if (j < 25)  
      ;  
  
   if (j < 25)   // C2143  
}  
```  
  
 C2143 pode ocorrer quando uma chave, um parêntese, ou um ponto\-e\-vírgula de fechamento estão faltando na linha em que o erro for detectado ou em uma das linhas exatamente acima:  
  
```caml  
// C2143d.cpp  
// compile with: /c  
class X {  
   int member1;  
   int member2   // C2143  
} x;  
```  
  
 Ou quando há uma marca válida em uma declaração de classe:  
  
```cpp  
// C2143e.cpp  
class X {  
   int member;  
} x;  
  
class + {};   // C2143 + is an invalid tag name  
class ValidName {};   // OK  
```  
  
 Um rótulo ou quando não é anexado a uma instrução.  Se você deverá colocar um rótulo por si só, por exemplo, ao final de uma instrução composta, anexa\-o a uma instrução nula:  
  
```cpp  
// C2143f.cpp  
// compile with: /c  
void func1() {  
   // OK  
   end1:  
      ;  
  
   end2:   // C2143  
}  
```  
  
 O erro pode ocorrer quando uma chamada não qualificado é feita para um tipo na biblioteca padrão do C\+\+:  
  
```cpp  
// C2143g.cpp  
// compile with: /EHsc /c  
#include <vector>  
static vector<char> bad;   // C2143  
static std::vector<char> good;   // OK  
```  
  
 Há uma palavra\-chave ou ausente de `typename` :  
  
```cpp  
// C2143h.cpp  
template <typename T>  
struct X {  
   struct Y {  
      int i;  
   };  
   Y memFunc();  
};  
template <typename T>  
X<T>::Y X<T>::memFunc() {   // C2143  
// try the following line instead  
// typename X<T>::Y X<T>::memFunc() {  
   return Y();  
}  
```  
  
 Ou se você tentar definir uma instanciação explícita:  
  
```cpp  
// C2143i.cpp  
// compile with: /EHsc /c  
// template definition  
template <class T>  
void PrintType(T i, T j) {}  
  
template void PrintType(float i, float j){}   // C2143  
template void PrintType(float i, float j);   // OK  
```  
  
 No programa c, as variáveis devem ser declaradas no início da função, e não podem ser declaradas depois que a função executa instruções de não declaração.  
  
```c  
// C2143j.c  
int main()   
{  
    int i = 0;  
    i++;  
    int j = 0; // C2143  
}  
  
```