---
title: "Iteradores Verificados | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "_SECURE_SCL"
  - "_SECURE_SCL_THROWS"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "iteradores verificados"
  - "iteradores, checked"
  - "Bibliotecas Seguras"
  - "Bibliotecas Seguras, Biblioteca Padrão C++"
  - "Biblioteca Padrão C++ Segura"
ms.assetid: cfc87df8-e3d9-403b-ab78-e9483247d940
caps.latest.revision: 30
caps.handback.revision: 29
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Iteradores Verificados
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os iteradores verificados garantem que os limites de seu contêiner não serão substituídos.  
  
 Os iteradores verificados se aplicam a compilações de versão e compilações de depuração.  Para obter mais informações sobre como usar iteradores ao compilar no modo de depuração, consulte [Suporte a Iterador de Depuração](../standard-library/debug-iterator-support.md).  
  
## Comentários  
 Para obter informações sobre como desabilitar avisos que são gerados pelos iteradores verificados, consulte [\_SCL\_SECURE\_NO\_WARNINGS](../standard-library/scl-secure-no-warnings.md).  
  
 Você pode usar o símbolo a seguir com o recurso de iteradores verificados.  
  
 `_SECURE_SCL`  
 Se `_SECURE_SCL` for definido como 1, o uso não seguro de iteradores vai gerar um erro de tempo de execução e o programa será finalizado.  Se definido como 0, os iteradores verificados serão desabilitados.  Por padrão, o valor de `_SECURE_SCL` é 0 para compilações de versão e 1 para compilações de depuração.  
  
> [!IMPORTANT]
>  Use `_ITERATOR_DEBUG_LEVEL` para controlar [\_SECURE\_SCL](../standard-library/secure-scl.md).  Para obter mais informações, consulte [\_ITERATOR\_DEBUG\_LEVEL](../standard-library/iterator-debug-level.md).  
  
 Quando `_SECURE_SCL` for definido como 1, as seguintes verificações SCL serão executadas:  
  
-   Todos os iteradores padrão \(por exemplo, [vector::iterator](../Topic/vector::iterator.md)\) serão verificados.  
  
-   Se um iterador de saída for um iterador verificado, você obterá comportamento verificado em chamadas para a função padrão \(por exemplo, [std::copy](../Topic/copy.md)\).  
  
-   Se o iterador de saída for um iterador não verificado, as chamadas para a função padrão vão gerar avisos de compilador.  
  
-   As seguintes funções gerarão um erro de tempo de execução se houver um acesso fora dos limites do contêiner:  
  
|||||  
|-|-|-|-|  
|[basic\_string::operator](../Topic/basic_string::operator.md)|[bitset::operator](../Topic/bitset::operator.md)|[deque::back](../Topic/deque::back.md)|[deque::front](../Topic/deque::front.md)|  
|[deque::operator](../Topic/deque::operator.md)|[list::back](../Topic/list::back.md)|[list::front](../Topic/list::front.md)|[queue::back](../Topic/queue::back.md)|  
|[queue::front](../Topic/queue::front.md)|[vector::operator](../Topic/vector::operator.md)|[vector::back](../Topic/vector::back.md)|[vector::front](../Topic/vector::front.md)|  
  
 Quando `_SECURE_SCL` é definido como 0:  
  
-   Todos os iteradores padrão são não verificados \(iteradores pode ir além dos limites de contêiner, o que leva ao comportamento indefinido\).  
  
-   Se um iterador de saída for um iterador verificado, você obterá comportamento verificado em chamadas para a função padrão \(por exemplo, `std::copy`\).  
  
-   Se um iterador de saída for um iterador não verificado, você obterá comportamento não verificado em chamadas para a função padrão \(por exemplo, `std::copy`\).  
  
 Um iterador verificado se refere a um iterador que chamará `invalid_parameter_handler` se você tentar passar dos limites do contêiner.  Para obter mais informações sobre `invalid_parameter_handler`, consulte [Validação do parâmetro](../c-runtime-library/parameter-validation.md).  
  
 [Classe checked\_array\_iterator](../standard-library/checked-array-iterator-class.md) e [Classe unchecked\_array\_iterator](../standard-library/unchecked-array-iterator-class.md) são os adaptadores de iterador que oferecem suporte aos iteradores verificados.  
  
## Exemplo  
 Quando você compila usando `_SECURE_SCL 1`, um erro de tempo de execução ocorrerá se você tentar acessar um elemento que esteja fora dos limites do contêiner usando o operador de indexação de determinadas classes.  
  
```cpp  
// checked_iterators_1.cpp  
// cl.exe /Zi /MDd /EHsc /W4  
  
#define _ITERATOR_DEBUG_LEVEL 1  
// implies #define _SECURE_SCL 1  
  
#include <vector>  
#include <iostream>  
  
using namespace std;  
  
int main()   
{  
    vector<int> v;  
    v.push_back(67);  
  
    int i = v[0];  
    cout << i << endl;  
  
    i = v[1]; // triggers invalid parameter handler  
};  
  
```  
  
 Esse programa imprimirá "67" e exibirá uma caixa de diálogo de falha de asserção com informações adicionais sobre a falha.  
  
## Exemplo  
 Da mesma forma, ao compilar usando `_SECURE_SCL 1`, um erro de tempo de execução ocorrerá se você tentar acessar um elemento usando anterior ou posterior de determinadas classes, quando o contêiner estiver vazio.  
  
```cpp  
// checked_iterators_2.cpp  
// cl.exe /Zi /MDd /EHsc /W4  
  
#define _ITERATOR_DEBUG_LEVEL 1  
// implies #define _SECURE_SCL 1  
  
#include <vector>  
#include <iostream>  
  
using namespace std;  
  
int main()   
{  
    vector<int> v;  
  
    int& i = v.front(); // triggers invalid parameter handler  
};  
  
```  
  
 Esse programa exibirá uma caixa de diálogo de falha de asserção com informações adicionais sobre a falha.  
  
 O código a seguir demonstra vários cenários de caso de uso de iterador com comentários sobre cada um.  
  
```cpp  
// cl.exe /MTd /EHsc /W4  
#include <algorithm>  
#include <array>  
#include <iostream>  
#include <iterator>  
#include <numeric>  
#include <string>  
#include <vector>  
  
using namespace std;  
  
template <typename C> void print(const string& s, const C& c) {  
    cout << s;  
  
    for (const auto& e : c) {  
        cout << e << " ";  
    }  
  
    cout << endl;  
}  
  
int main()  
{  
    vector<int> v(16);  
    iota(v.begin(), v.end(), 0);  
    print("v: ", v);  
  
    // OK: vector::iterator is checked in debug mode  
    // (i.e. an overrun will trigger a debug assertion)  
    vector<int> v2(16);  
    transform(v.begin(), v.end(), v2.begin(), [](int n) { return n * 2; });  
    print("v2: ", v2);  
  
    // OK: back_insert_iterator is marked as checked in debug mode  
    // (i.e. an overrun is impossible)  
    vector<int> v3;  
    transform(v.begin(), v.end(), back_inserter(v3), [](int n) { return n * 3; });  
    print("v3: ", v3);  
  
    // OK: array::iterator is checked in debug mode  
    // (i.e. an overrun will trigger a debug assertion)  
    array<int, 16> a4;  
    transform(v.begin(), v.end(), a4.begin(), [](int n) { return n * 4; });  
    print("a4: ", a4);  
  
    // OK: Raw arrays are checked in debug mode  
    // (an overrun will trigger a debug assertion)  
    // NOTE: This applies only when raw arrays are given to STL algorithms!  
    int a5[16];  
    transform(v.begin(), v.end(), a5, [](int n) { return n * 5; });  
    print("a5: ", a5);  
  
    // WARNING C4996: Pointers cannot be checked in debug mode  
    // (an overrun will trigger undefined behavior)  
    int a6[16];  
    int * p6 = a6;  
    transform(v.begin(), v.end(), p6, [](int n) { return n * 6; });  
    print("a6: ", a6);  
  
    // OK: stdext::checked_array_iterator is checked in debug mode  
    // (an overrun will trigger a debug assertion)  
    int a7[16];  
    int * p7 = a7;  
    transform(v.begin(), v.end(), stdext::make_checked_array_iterator(p7, 16), [](int n) { return n * 7; });  
    print("a7: ", a7);  
  
    // WARNING SILENCED: stdext::unchecked_array_iterator is marked as checked in debug mode  
    // (it performs no checking, so an overrun will trigger undefined behavior)  
    int a8[16];  
    int * p8 = a8;  
    transform(v.begin(), v.end(), stdext::make_unchecked_array_iterator(p8), [](int n) { return n * 8; });  
    print("a8: ", a8);  
}  
  
```  
  
## Saída  
 A compilação de código mostrada na seção anterior com `cl.exe /EHsc /W4 /MTd` resultará no seguinte aviso de compilador, mas que compila sem erro em um executável:  
  
```  
algorithm(1026) : warning C4996: 'std::_Transform1': Function call with parameters that may be unsafe - this call rel  
ies on the caller to check that the passed values are correct. To disable this warning, use -D_SCL_SECURE_NO_WARNINGS. See documentation on how to use Visual C++ 'Checked Iterators'  
```  
  
 A execução do executável do aplicativo de console resulta na seguinte saída:  
  
```  
v: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15  
v2: 0 2 4 6 8 10 12 14 16 18 20 22 24 26 28 30  
v3: 0 3 6 9 12 15 18 21 24 27 30 33 36 39 42 45  
a4: 0 4 8 12 16 20 24 28 32 36 40 44 48 52 56 60  
a5: 0 5 10 15 20 25 30 35 40 45 50 55 60 65 70 75  
a6: 0 6 12 18 24 30 36 42 48 54 60 66 72 78 84 90  
a7: 0 7 14 21 28 35 42 49 56 63 70 77 84 91 98 105  
a8: 0 8 16 24 32 40 48 56 64 72 80 88 96 104 112 120  
```  
  
## Consulte também  
 [Visão geral da STL](../standard-library/cpp-standard-library-overview.md)   
 [Suporte a Iterador de Depuração](../standard-library/debug-iterator-support.md)