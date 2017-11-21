---
title: "Comportamento não padrão | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs: C++
helpviewer_keywords:
- compatibility and compliance, nonstandard behavior
- Microsoft-specific, compiler behavior
- nonstandard behavior, compliance and compatibility
ms.assetid: a57dea27-dc79-4f64-8a83-017e84841773
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 73b60bbdbd38738f8cb5d127b464b14465de413b
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="nonstandard-behavior"></a>Comportamento não padrão
As seções a seguir listam alguns dos locais em que a implementação de C++ do Visual C++ não cumpre o padrão C++. Os números de seção fornecidos abaixo se referem aos números da seção no padrão C++ 11 (ISO/IEC 14882:2011(E)).  
  
 A lista de limites do compilador diferentes daqueles definidos no C++ padrão é determinada em [limites do compilador](../cpp/compiler-limits.md).  
  
## <a name="covariant-return-types"></a>Tipos de retorno covariantes  
 As classes base virtuais não têm suporte como tipo de retorno covariante quando a função virtual tem um número variável de argumentos. Isso não está em conformidade com a seção 10.3, parágrafo 7 da especificação ISO do C++. O exemplo a seguir não é compilado, dando o erro do compilador [C2688](../error-messages/compiler-errors-2/compiler-error-c2688.md)  
  
```cpp  
// CovariantReturn.cpp  
class A   
{  
   virtual A* f(int c, ...);   // remove ...  
};  
  
class B : virtual A  
{  
   B* f(int c, ...);   // C2688 remove ...  
};  
```  
  
## <a name="binding-nondependent-names-in-templates"></a>Associação de nomes não dependentes nos modelos  
 O compilador do Visual C++, atualmente, não oferece suporte à associação de nomes não dependentes ao analisar inicialmente um modelo. Isso não está em conformidade com a seção 14.6.3 da especificação ISO do C++. Isso pode fazer com que sobrecargas declaradas após o modelo (mas antes do modelo ser instanciado) sejam vistas.  
  
```cpp  
#include <iostream>  
using namespace std;  
  
namespace N {  
   void f(int) { cout << "f(int)" << endl;}  
}  
  
template <class T> void g(T) {  
    N::f('a');   // calls f(char), should call f(int)  
}  
  
namespace N {  
    void f(char) { cout << "f(char)" << endl;}  
}  
  
int main() {  
    g('c');  
}  
// Output: f(char)  
  
```  
  
## <a name="function-exception-specifiers"></a>Especificadores de exceção de função  
 Os especificadores da exceção de função diferentes de `throw()` são analisados, mas não usados. Isso não está em conformidade com a seção 15.4 da especificação ISO do C++. Por exemplo:  
  
```cpp  
void f() throw(int); // parsed but not used  
void g() throw();    // parsed and used  
```  
  
 Para obter mais informações sobre as especificações de exceção, consulte [especificações de exceção](../cpp/exception-specifications-throw-cpp.md).  
  
## <a name="chartraitseof"></a>char_traits::eof()  
 O padrão C++ estados que [char_traits:: EOF](../standard-library/char-traits-struct.md#eof) não deve corresponder a uma opção válida `char_type` valor. O compilador do Visual C++ impõe essa restrição para o tipo `char`, mas não para o tipo `wchar_t`. Isso não está em conformidade com o requisito da Tabela 62, na seção 12.1.1 da especificação ISO do C++. O exemplo abaixo demonstra isso.  
  
```cpp  
#include <iostream>  
  
int main()  
{  
    using namespace std;  
  
    char_traits<char>::int_type int2 = char_traits<char>::eof();  
    cout << "The eof marker for char_traits<char> is: " << int2 << endl;  
  
    char_traits<wchar_t>::int_type int3 = char_traits<wchar_t>::eof();  
    cout << "The eof marker for char_traits<wchar_t> is: " << int3 << endl;  
}  
```  
  
## <a name="storage-location-of-objects"></a>Local de armazenamento de objetos  
 O padrão C++ (seção 1.8, parágrafo 6) exige que objetos completos do C++ tenham locais exclusivos de armazenamento. No entanto, com o Visual C++, há casos em que tipos sem membros de dados compartilharão um local de armazenamento com outros tipos pelo tempo de vida do objeto.