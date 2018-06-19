---
title: Cadeia de caracteres e formatação de e-S (C++ moderno) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 3954e8de-a59b-4175-89c9-4ee842ab89ed
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 391648d71fa3d38a0f704a014c163b7f8b102e40
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32422378"
---
# <a name="string-and-io-formatting-modern-c"></a>Cadeia de caracteres e formatação de E/S (C++ moderno)
C++ [iostreams](../standard-library/iostream.md) são capazes de e/s de cadeia de caracteres formatada. Por exemplo, o código a seguir mostra como definir cout para formatar um número inteiro para a saída em hexadecimal, primeiro salvando desativar o estado atual e novamente configuração posteriormente, porque depois que a formatação de estado é passado para cout, ela permanece assim até que seja alterado, não apenas para uma linha de código.  
  
```cpp  
#include <iostream>  
#include <iomanip>  
  
using namespace std;  
  
int main()   
{  
    ios state(nullptr);  
  
    cout << "The answer in decimal is: " << 42 << endl;  
  
    state.copyfmt(cout); // save current formatting  
    cout << "In hex: 0x" // now load up a bunch of formatting modifiers  
        << hex   
        << uppercase   
        << setw(8)   
        << setfill('0')   
        << 42            // the actual value we wanted to print out  
        << endl;  
    cout.copyfmt(state); // restore previous formatting  
}  
  
```  
  
 Isso pode ser totalmente muito complicado em muitos casos. Como alternativa, você pode usar Boost.Format de bibliotecas C++ aumento, mesmo que seja diferente do padrão. Você pode baixar qualquer biblioteca de aumento do [aumento](http://www.boost.org/) site.  
  
 Algumas vantagens do Boost.Format são:  
  
-   Safe: Fortemente tipado e gera uma exceção para erros — por exemplo, a especificação de muitos ou poucos itens.  
  
-   Extensível: Funciona para qualquer tipo que pode ser transmitido.  
  
-   Conveniente: Posix padrão e cadeias de caracteres de formato semelhantes.  
  
 Embora Boost.Format baseia-se no C++ [iostreams](../standard-library/iostream-programming.md), que são seguros e extensível, não são otimizadas para desempenho. Quando você precisar de otimização de desempenho, considere a possibilidade de C [printf](../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md) e [sprintf](../c-runtime-library/reference/sprintf-sprintf-l-swprintf-swprintf-l-swprintf-l.md), que são rápidos e fáceis de usar. No entanto, eles não são protegidos contra vulnerabilidades ou extensível. (Existem versões seguras, mas eles incorrem em uma pequena penalidade de desempenho. Para obter mais informações, consulte [printf_s, printf_s_l, wprintf_s, wprintf_s_l](../c-runtime-library/reference/printf-s-printf-s-l-wprintf-s-wprintf-s-l.md) e [sprintf_s, sprintf_s_l, swprintf_s, swprintf_s_l](../c-runtime-library/reference/sprintf-s-sprintf-s-l-swprintf-s-swprintf-s-l.md)).  
  
 O código a seguir demonstra alguns o aumento de recursos de formatação.  
  
```cpp  
    string s = str( format("%2% %2% %1%\n") % "world" % "hello" );  
    // s contains "hello hello world"    
  
    for( auto i = 0; i < names.size(); ++i )  
        cout << format("%1% %2% %|40t|%3%\n") % first[i] % last[i] % tel[i];  
    // Georges Benjamin Clemenceau             +33 (0) 123 456 789  
    // Jean de Lattre de Tassigny              +33 (0) 987 654 321  
  
```  
  
## <a name="see-also"></a>Consulte também  
 [Bem-vindo novamente para C++](../cpp/welcome-back-to-cpp-modern-cpp.md)   
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)   
 [\<iostream >](../standard-library/iostream.md)   
 [\<limites >](../standard-library/limits.md)   
 [\<iomanip>](../standard-library/iomanip.md)
