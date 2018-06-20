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
ms.openlocfilehash: b571cd2836e66ebef21898af27cf2a6d7082e0e5
ms.sourcegitcommit: d06966efce25c0e66286c8047726ffe743ea6be0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/19/2018
ms.locfileid: "36261037"
---
# <a name="header-files-c"></a>Arquivos de cabeçalho (C++)

Os nomes dos elementos do programa, como variáveis, funções, classes e assim por diante devem ser declarados antes que possam ser usados. Por exemplo, você não pode gravar apenas `x = 42` sem primeiro declarar 'x'. 

```cpp
int x; // declaration
x = 42; // use x
```

 A declaração informa ao compilador se é um **int**, um **duplo**, um **função**, um **classe** ou alguma outra coisa.  Além disso, cada nome deve ser declarado (direta ou indiretamente) em todos os arquivos. cpp no qual ele é usado. Quando você compila um programa, cada arquivo. cpp é compilado independentemente em uma unidade de compilação. O compilador não tem conhecimento de que os nomes são declarados em outras unidades de compilação. Isso significa que, se você definir uma classe ou função ou variável global, você deve fornecer uma declaração que algo em cada arquivo. cpp adicionais que o utiliza. Cada declaração daquilo que deve ser exatamente idêntica em todos os arquivos. Uma inconsistência pequena fará com que erros ou comportamento indesejado, quando o vinculador tenta mesclar todas as unidades de compilação em um único programa.

Para minimizar a possibilidade de erros, C++ adotou a convenção de usar *arquivos de cabeçalho* para conter declarações. Verifique as declarações em um arquivo de cabeçalho, e use o #include diretiva em todos os arquivos. cpp ou outro arquivo de cabeçalho requer essa declaração. O #include inserções diretivas uma cópia do arquivo de cabeçalho diretamente no arquivo. cpp antes da compilação. 

## <a name="example"></a>Exemplo

O exemplo a seguir mostra uma maneira comum para declarar uma classe e, em seguida, usá-lo em um arquivo de origem diferente. Vamos começar com o arquivo de cabeçalho **my_class.h**. Ele contém uma definição de classe, mas observe que a definição está incompleta. a função de membro `do_something` não está definido:

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

Em seguida, crie um arquivo de implementação (normalmente com uma extensão semelhante ou. cpp). Vamos chamar a my_class.cpp de arquivo e forneça uma definição para a declaração de membro. Adicionamos um `#include` diretiva para o arquivo "my_class.h" para ter a declaração my_class inserida neste momento na. cpp arquivo e incluem  **\<iostream >** para efetuar pull na declaração para `std::cout`. Observe que as aspas são usadas para arquivos de cabeçalho no mesmo diretório que o arquivo de origem e parênteses são usados para cabeçalhos de biblioteca padrão. Além disso, muitos cabeçalhos de biblioteca padrão não têm. h ou qualquer outra extensão de arquivo.

O arquivo de implementação, pode, opcionalmente, usamos um **usando** instrução para evitar ter que qualificar cada menção "my_class" ou "cout" com "n::" ou "std::".  Não coloque **usando** instruções nos arquivos de cabeçalho!

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

Agora podemos usar `my_class` em outro arquivo. cpp. Podemos #include o arquivo de cabeçalho para que o compilador extrai na declaração. Todas as necessidades de compilador saber é que my_class é uma classe que tem uma função de membro público chamada `do_something()`.

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

Depois que o compilador conclusão da compilação de cada arquivo. cpp em arquivos. obj, ele passa os arquivos. obj para o vinculador. Quando o vinculador mescla os arquivos de objeto encontrar exatamente uma definição para my_class; ele está no arquivo. obj produzido para my_class.cpp e a compilação for bem-sucedida.

## <a name="include-guards"></a>Incluir protege

Normalmente, os arquivos de cabeçalho têm um *incluem proteção* ou um **#pragma uma vez** diretiva para garantir que eles não estejam inseridos várias vezes em um arquivo. cpp único. 

my_class.h
#<a name="ifndef-myclassh--include-guard"></a>ifndef MY_CLASS_H / / incluem proteção
#<a name="define-myclassh"></a>Definir MY_CLASS_H


namespace N {classe my_class {público: void do_something();};

}

#<a name="endif--myclassh-"></a>endif / * MY_CLASS_H * /

## <a name="what-to-put-in-a-header-file"></a>O que deve ser colocado em um arquivo de cabeçalho

Como um arquivo de cabeçalho potencialmente pode ser incluído por vários arquivos, ele não pode conter definições que podem produzir várias definições de mesmo nome. O exemplo a seguir não é permitidas ou é considerados prática muito ruim:

- definições de tipo interno no namespace ou escopo global
- definições de função não embutida 
- definições de variáveis não constante
- definições de agregação
- namespaces sem nome
- usando diretivas

Usar o **usando** diretiva não necessariamente causará um erro, mas poderá causar um problema porque ele traz o namespace no escopo em cada arquivo. cpp direta ou indiretamente inclui esse cabeçalho. 

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
