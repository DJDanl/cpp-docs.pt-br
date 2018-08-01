---
title: Arquivos de cabeçalho (C++) | Microsoft Docs
ms.custom: ''
ms.date: 04/20/2018
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- header files [C++]
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9f6950049d9bd9b9264383ab6e5e216023526880
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39404759"
---
# <a name="header-files-c"></a>Arquivos de cabeçalho (C++)

Os nomes dos elementos do programa, como variáveis, funções, classes e assim por diante devem ser declarados antes que possam ser usados. Por exemplo, você não pode gravar apenas `x = 42` sem primeiro declarar 'x'. 

```cpp
int x; // declaration
x = 42; // use x
```

 A declaração informa ao compilador se é um **int**, um **duplo**, um **função**, um **classe** ou alguma outra coisa.  Além disso, cada nome deve ser declarado (direta ou indiretamente) em todos os arquivos. cpp no qual ele é usado. Quando você compila um programa, cada arquivo. cpp é compilado de forma independente em uma unidade de compilação. O compilador não tem conhecimento de que nomes são declarados em outras unidades de compilação. Isso significa que, se você definir uma classe ou função ou variável global, você deve fornecer uma declaração dessa coisa em cada arquivo. cpp adicionais que o utiliza. Cada declaração de lá o que deve ser exatamente idêntica em todos os arquivos. Uma inconsistência de pequena causará erros ou um comportamento não intencional, quando o vinculador tenta mesclar todas as unidades de compilação em um único programa.

Para minimizar o potencial para erros, o C++ adotou a convenção de uso *arquivos de cabeçalho* para conter as declarações. Você fazer as declarações em um arquivo de cabeçalho e usar o #include diretiva em todos os arquivos. cpp ou outro arquivo de cabeçalho requer essa declaração. O #include diretiva insere uma cópia do arquivo de cabeçalho diretamente no arquivo. cpp antes da compilação. 

## <a name="example"></a>Exemplo

O exemplo a seguir mostra uma maneira comum de declarar uma classe e, em seguida, usá-lo em outro arquivo de origem. Vamos começar com o arquivo de cabeçalho `my_class.h`. Ela contém uma definição de classe, mas observe que a definição está incompleta. a função de membro `do_something` não está definido:

```cpp
// my_class.h
namespace N
{
    class my_class
    {
    public:
        void do_something();
    };

}
```

Em seguida, crie um arquivo de implementação (normalmente com uma extensão de semelhante ou. cpp). Vamos chamar o my_class.cpp de arquivo e forneça uma definição para a declaração de membro. Adicionamos uma `#include` diretiva para o arquivo de "my_class.h" para que a declaração my_class inserida neste momento na. cpp de arquivo e podemos incluir `<iostream>` efetuar pull na declaração para `std::cout`. Observe que as aspas são usadas para arquivos de cabeçalho no mesmo diretório que o arquivo de origem e colchetes angulares são usados para os cabeçalhos da biblioteca padrão. Além disso, muitos cabeçalhos da biblioteca padrão não tem. h ou qualquer outra extensão de arquivo.

No arquivo de implementação, pode, opcionalmente, usamos uma **usando** instrução para evitar ter que qualificar cada menção de "my_class" ou "cout" com "n::" ou "std::".  Não coloque **usando** instruções em seus arquivos de cabeçalho!

```cpp
// my_class.cpp
#include "my_class.h" // header in local directory
#include <iostream> // header in standard library

using namespace N;
using namespace std;

void my_class::do_something()
{
    cout << "Doing something!" << endl;
}
```

Agora podemos usar `my_class` em outro arquivo. cpp. Podemos #include no arquivo de cabeçalho, de modo que o compilador efetua pull na declaração. Todas as necessidades de compilador saber é que my_class é uma classe que tem uma função de membro público chamada `do_something()`.

```cpp
// my_program.cpp
#include "my_class.h"

using namespace N;

int main()
{
    my_class mc;
    mc.do_something();
    return 0;
}
```

Depois que o compilador conclusão da compilação de cada arquivo. cpp em arquivos. obj, ele passa os arquivos. obj para o vinculador. Quando o vinculador mescla os arquivos de objeto encontra exatamente uma definição para my_class; ele está no arquivo. obj produzido para my_class.cpp e a compilação for bem-sucedida.

## <a name="include-guards"></a>Incluir protege

Normalmente, os arquivos de cabeçalho têm um *incluem guard* ou um `#pragma once` diretiva para garantir que eles não são inseridos várias vezes em um arquivo. cpp único. 

```cpp
// my_class.h
#ifndef MY_CLASS_H // include guard
#define MY_CLASS_H

namespace N
{
    class my_class
    {
    public:
        void do_something();
    };
}

#endif /* MY_CLASS_H */
```

## <a name="what-to-put-in-a-header-file"></a>O que colocar em um arquivo de cabeçalho

Como um arquivo de cabeçalho potencialmente pode ser incluído por vários arquivos, ele não pode conter definições que podem produzir várias definições de mesmo nome. O exemplo a seguir não é permitidas ou é considerados muito boa prática:

- definições de tipo interno no namespace ou escopo global
- definições de função não embutida 
- definições de variável não const
- definições de agregação
- namespaces sem nome
- usando diretivas

Usar o **usando** diretiva não necessariamente causará um erro, mas potencialmente pode causar um problema porque ele traz o namespace no escopo em todos os arquivos. cpp que direta ou indiretamente, inclua esse cabeçalho. 

## <a name="sample-header-file"></a>Arquivo de cabeçalho de exemplo

O exemplo a seguir mostra os vários tipos de declarações e definições que são permitidas em um arquivo de cabeçalho:

```cpp
#pragma once 
#include <vector> // #include directive
#include <string>

namespace N  // namespace declaration
{
    inline namespace P
    {
        //...
    }

    enum class colors : short { red, blue, purple, azure };

    const double PI = 3.14;  // const and constexpr definitions
    constexpr int MeaningOfLife{ 42 };
    constexpr int get_meaning()
    {
        static_assert(MeaningOfLife == 42, "unexpected!"); // static_assert
        return MeaningOfLife;
    }
    using vstr = std::vector<int>;  // type alias
    extern double d; // extern variable

#define LOG   // macro definition

#ifdef LOG   // conditional compilation directive
    void print_to_log();
#endif

    class my_class   // regular class definition, 
    {                // but no non-inline function definitions

        friend class other_class;
    public:
        void do_something();   // definition in my_class.cpp
        inline void put_value(int i) { vals.push_back(i); } // inline OK

    private:
        vstr vals;
        int i;
    };

    struct RGB
    {
        short r{ 0 };  // member initialization
        short g{ 0 };
        short b{ 0 };
    };

    template <typename T>  // template definition
    class value_store
    {
    public:
        value_store<T>() = default;
        void write_value(T val)
        {
            //... function definition OK in template
        }
    private:
        std::vector<T> vals;
    };

    template <typename T>  // template declaration
    class value_widget;
}
```