---
title: Arquivos de cabeçalho (C++)
ms.date: 12/11/2019
helpviewer_keywords:
- header files [C++]
ms.openlocfilehash: 0b76773b8b7d55645c807588fe41b242df9eea2f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227446"
---
# <a name="header-files-c"></a>Arquivos de cabeçalho (C++)

Os nomes dos elementos do programa, como variáveis, funções, classes e assim por diante, devem ser declarados antes que possam ser usados. Por exemplo, você não pode apenas escrever `x = 42` sem primeiro declarar ' x '.

```cpp
int x; // declaration
x = 42; // use x
```

A declaração informa ao compilador se o elemento é um, **`int`** uma **`double`** **função**, uma **`class`** ou alguma outra coisa.  Além disso, cada nome deve ser declarado (direta ou indiretamente) em cada arquivo. cpp no qual é usado. Quando você compila um programa, cada arquivo. cpp é compilado de forma independente em uma unidade de compilação. O compilador não tem conhecimento de quais nomes são declarados em outras unidades de compilação. Isso significa que, se você definir uma classe ou função ou variável global, deverá fornecer uma declaração dessa coisa em cada arquivo. cpp adicional que a usa. Cada declaração dessa coisa deve ser exatamente idêntica em todos os arquivos. Uma ligeira inconsistência causará erros ou comportamento indesejado quando o vinculador tentar mesclar todas as unidades de compilação em um único programa.

Para minimizar o potencial de erros, o C++ adotou a Convenção de uso de *arquivos de cabeçalho* para conter declarações. Você faz as declarações em um arquivo de cabeçalho e, em seguida, usa a diretiva #include em cada arquivo. cpp ou outro arquivo de cabeçalho que requer essa declaração. A diretiva #include insere uma cópia do arquivo de cabeçalho diretamente no arquivo. cpp antes da compilação.

> [!NOTE]
> No Visual Studio 2019, o recurso de *módulos* do c++ 20 é apresentado como uma melhoria e substituição eventual para arquivos de cabeçalho. Para obter mais informações, consulte [visão geral dos módulos em C++](modules-cpp.md).

## <a name="example"></a>Exemplo

O exemplo a seguir mostra uma maneira comum de declarar uma classe e, em seguida, usá-la em um arquivo de origem diferente. Vamos começar com o arquivo de cabeçalho, `my_class.h` . Ele contém uma definição de classe, mas observe que a definição está incompleta; a função de membro `do_something` não está definida:

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

Em seguida, crie um arquivo de implementação (normalmente com uma extensão. cpp ou semelhante). Vamos chamar o arquivo my_class. cpp e fornecer uma definição para a declaração de membro. Adicionamos uma `#include` diretiva para o arquivo "my_class. h" para que a declaração de my_class inserida neste ponto no arquivo. cpp e incluímos `<iostream>` para efetuar pull da declaração para `std::cout` . Observe que as aspas são usadas para arquivos de cabeçalho no mesmo diretório que o arquivo de origem, e os colchetes angulares são usados para cabeçalhos de biblioteca padrão. Além disso, muitos cabeçalhos de biblioteca padrão não têm. h ou qualquer outra extensão de arquivo.

No arquivo de implementação, opcionalmente, podemos usar uma **`using`** instrução para evitar ter que qualificar cada menção de "my_class" ou "cout" com "N::" ou "std::".  Não coloque **`using`** instruções em seus arquivos de cabeçalho!

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

Agora, podemos usar `my_class` em outro arquivo. cpp. Podemos #include o arquivo de cabeçalho para que o compilador receba a declaração. Tudo o que o compilador precisa saber é que my_class é uma classe que tem uma função de membro público chamada `do_something()` .

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

Depois que o compilador conclui a compilação de cada arquivo. cpp em arquivos. obj, ele passa os arquivos. obj para o vinculador. Quando o vinculador mescla os arquivos de objeto, ele encontra exatamente uma definição para my_class; Ele está no arquivo. obj produzido por my_class. cpp e a compilação é realizada com sucesso.

## <a name="include-guards"></a>Incluir proteções

Normalmente, os arquivos de cabeçalho têm uma *proteção include* ou uma `#pragma once` diretiva para garantir que eles não sejam inseridos várias vezes em um único arquivo. cpp.

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

Como um arquivo de cabeçalho pode potencialmente ser incluído por vários arquivos, ele não pode conter definições que possam produzir várias definições de mesmo nome. Os itens a seguir não são permitidos ou são considerados uma prática muito boa:

- definições de tipo interno no namespace ou escopo global
- definições de função não embutidas
- definições de variáveis não const
- definições de agregação
- namespaces sem nome
- usando diretivas

O uso da **`using`** diretiva não causará necessariamente um erro, mas pode potencialmente causar um problema, pois ele coloca o namespace no escopo em cada arquivo. cpp que inclui direta ou indiretamente esse cabeçalho.

## <a name="sample-header-file"></a>Arquivo de cabeçalho de exemplo

O exemplo a seguir mostra os vários tipos de declarações e definições que são permitidas em um arquivo de cabeçalho:

```cpp
// sample.h
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
