---
title: C2668 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: efb9abfa44a9c90d44a87046a6320a5e4ace8f57
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c2668"></a>C2668 de erro do compilador
'function': chamada ambígua para função sobrecarregada  
  
 A chamada de função sobrecarregada especificado não pôde ser resolvida. Você talvez queira converter explicitamente um ou mais dos parâmetros reais.  
  
 Você também pode obter esse erro por meio do uso do modelo. Se, na mesma classe, você tem uma função de membro regular e uma função de membro modelado com a mesma assinatura, o um modelo deve vir primeiro. Essa é uma limitação da implementação atual do Visual C++.  
  
 Consulte o artigo da Base de dados de Conhecimento Q240869 para obter mais informações sobre ordenação parcial de modelos de função.  
  
 Se você estiver criando um projeto do ATL que contém um objeto COM suporte `ISupportErrorInfo`, consulte o artigo da Base de dados de Conhecimento Q243298.  
  
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
 Outra maneira de resolver esse erro é com um [usando a declaração](../../cpp/using-declaration.md):  
  
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
 Esse erro também pode ser gerado como resultado de trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003: conversão ambígua na conversão da constante 0.  
  
 Conversão em uma conversão usando constante 0 é ambíguo, pois int requer uma conversão dois longos e void *. Para resolver esse erro, converta 0 para o tipo exato do parâmetro de função que está sendo usado de forma que nenhuma conversão precisa ocorrer (esse código será válido nas versões Visual Studio .NET 2003 e Visual Studio .NET do Visual C++).  
  
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
 Esse erro pode ocorrer porque o CRT agora tem float e double formas de todas as funções matemáticas.  
  
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
 Esse erro pode ocorrer porque o pow (int, int) foi removido do Math no CRT.  
  
```  
// C2668e.cpp  
#include <math.h>  
int main() {  
   pow(9,9);   // C2668  
   pow((double)9,9);   // OK  
}  
```
