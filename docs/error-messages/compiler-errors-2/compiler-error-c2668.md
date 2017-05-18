---
title: C2668 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 03/28/2017
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2668
dev_langs:
- C++
helpviewer_keywords:
- C2668
ms.assetid: 041e9627-1c76-420e-a653-cfc83f933bd3
caps.latest.revision: 13
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
ms.sourcegitcommit: b790beb88de009e1c7161f3c9af6b3e21c22fd8e
ms.openlocfilehash: 6bb1dc7c1dbf26a4ff8ec25a46fe7128e0fb6aa8
ms.contentlocale: pt-br
ms.lasthandoff: 03/29/2017

---
# <a name="compiler-error-c2668"></a>C2668 de erro do compilador
'function': chamada ambígua para função sobrecarregada  
  
 A chamada de função sobrecarregada especificado não pôde ser resolvida. Talvez você queira converter explicitamente um ou mais dos parâmetros reais.  
  
 Você também pode obter esse erro por meio do uso do modelo. Se, na mesma classe, você tem uma função de membro regular e uma função de membro de modelo com a mesma assinatura, um modelo deve vir primeiro. Essa é uma limitação da implementação atual do Visual C++.  
  
 Consulte o artigo da Base de dados de Conhecimento Q240869 para obter mais informações sobre a ordenação parcial de modelos de função.  
  
 Se você estiver criando um projeto de ATL que contém um objeto COM suporte `ISupportErrorInfo`, consulte o artigo da Base de dados de Conhecimento Q243298.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C2668:  
  
```  
// C2668.cpp  
struct A {};  
struct B : A {};  
struct X {};  
struct D : B, X {};  
  
void func( X, X ){}  
void func( A, B ){}  
D d;  
int main() {  
   func( d, d );   // C2668 D has an A, B, and X   
   func( (X)d, (X)d );   // OK, uses func( X, X )  
}  
```  
  
## <a name="example"></a>Exemplo  
 Outra maneira de resolver esse erro é com um [utilizando declaração](../../cpp/using-declaration.md):  
  
```  
// C2668b.cpp  
// compile with: /EHsc /c  
// C2668 expected  
#include <iostream>  
class TypeA {  
public:  
   TypeA(int value) {}  
};  
  
class TypeB {  
   TypeB(int intValue);  
   TypeB(double dbValue);  
};  
  
class TestCase {  
public:  
   void AssertEqual(long expected, long actual, std::string  
                    conditionExpression = "");  
};  
  
class AppTestCase : public TestCase {  
public:  
   // Uncomment the following line to resolve.  
   // using TestCase::AssertEqual;  
   void AssertEqual(const TypeA expected, const TypeA actual,  
                    std::string conditionExpression = "");  
   void AssertEqual(const TypeB expected, const TypeB actual,  
                    std::string conditionExpression = "");  
};  
  
class MyTestCase : public AppTestCase {  
   void TestSomething() {  
      int actual = 0;  
      AssertEqual(0, actual, "Value");  
   }  
};  
```  
  
## <a name="example"></a>Exemplo  
 Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: ambíguo conversão na conversão de constante 0.  
  
 Conversão de uma conversão usando a constante 0 é ambíguo como int requer uma conversão de ambos os longa e void *. Para resolver esse erro, converta 0 para o tipo exato do parâmetro de função que está sendo usado de forma que nenhuma conversão precisa ocorrer (esse código será válido das versões do Visual Studio .NET 2003 e o Visual Studio .NET do Visual C++).  
  
```  
// C2668c.cpp  
#include "stdio.h"  
void f(long) {  
   printf_s("in f(long)\n");  
}  
void f(void*) {  
   printf_s("in f(void*)\n");  
}  
int main() {  
   f((int)0);   // C2668  
  
   // OK  
   f((long)0);  
   f((void*)0);  
}  
```  
  
## <a name="example"></a>Exemplo  
 Esse erro pode ocorrer porque o CRT agora tem flutuante e duplas formas de todas as funções de matemática.  
  
```  
// C2668d.cpp  
#include <math.h>  
int main() {  
   int i = 0;  
   float f;  
   f = cos(i);   // C2668  
   f = cos((float)i);   // OK  
}  
```  
  
## <a name="example"></a>Exemplo  
 Esse erro pode ocorrer porque o pow (int, int) foi removido do math.h no CRT.  
  
```  
// C2668e.cpp  
#include <math.h>  
int main() {  
   pow(9,9);   // C2668  
   pow((double)9,9);   // OK  
}  
```

## <a name="example"></a>Exemplo  
Esse código é bem-sucedida no Visual Studio 2015, mas não em 2017 do Visual Studio e posterior com C2668. No Visual Studio 2015, o compilador tratou a inicialização de lista de cópia de maneira incorreta da mesma maneira que a inicialização de cópia regular; ele considerou somente a conversão de construtores para a resolução de sobrecarga. 

```
C++
struct A {
    explicit A(int) {}
};

struct B {
    B(int) {}
};

void f(const A&) {}
void f(const B&) {}

int main()
{
    f({ 1 }); // error C2668: 'f': ambiguous call to overloaded function
}
```
