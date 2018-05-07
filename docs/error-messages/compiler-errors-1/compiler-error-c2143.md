---
title: C2143 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2143
dev_langs:
- C++
helpviewer_keywords:
- C2143
ms.assetid: 1d8d1456-e031-4965-9240-09a6e33ba81c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 076f2ccb594edd5d9e627d8a4dcea2d9bb928890
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c2143"></a>C2143 de erro do compilador
Erro de sintaxe: faltando 'token1' antes de 'token2'  
  
 O compilador esperado um token específico (ou seja, um elemento de linguagem que não seja espaço em branco) e outro token encontrado.  
  
 Para obter informações sobre esse erro quando ele ocorre quando você estiver usando um bloco try de função, consulte [artigo da Base de dados de Conhecimento 241706](http://support.microsoft.com/kb/241706).  
  
 Verifique o [referência de linguagem C++](../../cpp/cpp-language-reference.md) para determinar onde o código está sintaticamente incorreto. Porque o compilador pode relatar esse erro depois de encontrar a linha que faz com que o problema, verifique várias linhas de código que precedem o erro.  
  
 C2143 pode ocorrer em situações diferentes.  
  
 Isso pode ocorrer quando um operador que pode ser um nome qualificado (`::`, `->`, e `.`) deve ser seguido da palavra-chave `template`, como no exemplo:  
  
```cpp  
class MyClass  
{  
    template<class Ty, typename PropTy>  
    struct PutFuncType : public Ty::PutFuncType<Ty, PropTy> // error C2143  
    {  
    };  
};  
  
```  
  
 Por padrão, o C++ supõe que `Ty::PutFuncType` não é um modelo; portanto, o seguinte `<` é interpretado como um valor menor-sinal.  Você deve informar o compilador explicitamente que `PutFuncType` é um modelo para que ele pode analisar corretamente o colchete angular. Para corrigir esse erro, use o `template` palavra-chave no nome do tipo dependentes, como mostrado aqui:  
  
```cpp  
class MyClass  
{  
    template<class Ty, typename PropTy>  
    struct PutFuncType : public Ty::template PutFuncType<Ty, PropTy> // correct  
    {  
    };  
};  
  
```  
  
 C2143 pode ocorrer quando **/clr** é usado e uma `using` diretiva tem um erro de sintaxe:  
  
```cpp  
// C2143a.cpp  
// compile with: /clr /c  
using namespace System.Reflection;   // C2143  
using namespace System::Reflection;  
```  
  
 Ele também pode ocorrer quando você está tentando compilar um arquivo de código de origem usando a sintaxe do CLR sem também **/clr**:  
  
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
  
 O primeiro caractere diferente de espaço que segue um `if` instrução deve ser um parêntese esquerdo. O compilador não pode converter qualquer outra coisa:  
  
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
  
 C2143 pode ocorrer quando uma chave de fechamento, parênteses ou ponto e vírgula está ausente na linha em que o erro for detectado ou em uma das linhas apenas acima:  
  
```cpp  
// C2143d.cpp  
// compile with: /c  
class X {  
   int member1;  
   int member2   // C2143  
} x;  
```  
  
 Ou, quando há uma marca inválida em uma declaração de classe:  
  
```cpp  
// C2143e.cpp  
class X {  
   int member;  
} x;  
  
class + {};   // C2143 + is an invalid tag name  
class ValidName {};   // OK  
```  
  
 Ou, quando um rótulo não é anexado a uma instrução. Se você deve colocar um rótulo por si só, por exemplo, no final de uma instrução composta, anexá-lo a uma instrução nulo:  
  
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
  
 O erro pode ocorrer quando é feita uma chamada não qualificada para um tipo na biblioteca padrão C++:  
  
```cpp  
// C2143g.cpp  
// compile with: /EHsc /c  
#include <vector>  
static vector<char> bad;   // C2143  
static std::vector<char> good;   // OK  
```  
  
 Ou a ausência de um `typename` palavra-chave:  
  
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
  
 Ou, se você tentar definir uma instanciação explícita:  
  
```cpp  
// C2143i.cpp  
// compile with: /EHsc /c  
// template definition  
template <class T>  
void PrintType(T i, T j) {}  
  
template void PrintType(float i, float j){}   // C2143  
template void PrintType(float i, float j);   // OK  
```  
  
 Em um programa C, variáveis devem ser declaradas no início da função e não pode ser declarados depois que a função executa instruções de declaração não.  
  
```C  
// C2143j.c  
int main()   
{  
    int i = 0;  
    i++;  
    int j = 0; // C2143  
}  
```  
