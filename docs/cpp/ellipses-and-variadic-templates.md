---
title: Reticências e modelos variadic
ms.date: 11/04/2016
ms.assetid: f20967d9-c967-4fd2-b902-2bb1d5ed87e3
ms.openlocfilehash: 358cdeeaf6f3e8c7f7841bbc796eca6557ccd145
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366334"
---
# <a name="ellipses-and-variadic-templates"></a>Reticências e modelos variadic

Este artigo mostra como usar reticências (`...`) com modelos variadic de C++. As reticências tiveram muitos usos em C e C++. Eles incluem listas de argumentos variáveis para funções. A função `printf()` da Biblioteca em Runtime C é um dos exemplos mais conhecidos.

Um *modelo variado* é um modelo de classe ou função que suporta um número arbitrário de argumentos. Esse mecanismo é útil principalmente para os desenvolvedores de biblioteca C++, pois você pode aplicá-lo a modelos de classe e modelos de função e, dessa forma, fornecer uma ampla variedade de funcionalidades e flexibilidade fortemente tipadas e não triviais.

## <a name="syntax"></a>Sintaxe

As reticências são usadas em duas maneiras por modelos variadic. À esquerda do nome do parâmetro, significa um pacote de *parâmetros*, e à direita do nome do parâmetro, ele expande os pacotes de parâmetros em nomes separados.

Aqui está um exemplo básico da sintaxe de definição de *classe de modelo variadica:*

```cpp
template<typename... Arguments> class classname;
```

Para pacotes e expansões do parâmetro, você pode acrescentar espaço em branco em torno de reticências, com base em sua preferência, conforme mostrado nestes exemplos:

```cpp
template<typename ...Arguments> class classname;
```

Ou assim:

```cpp
template<typename ... Arguments> class classname;
```

Observe que este artigo usa a convenção que é mostrada no primeiro exemplo (as reticências estão anexadas a `typename`).

Nos exemplos anteriores, Arguments é um pacote de *parâmetros.* A classe `classname` pode aceitar um número variável de argumentos, como nestes exemplos:

```cpp
template<typename... Arguments> class vtclass;

vtclass< > vtinstance1;
vtclass<int> vtinstance2;
vtclass<float, bool> vtinstance3;
vtclass<long, std::vector<int>, std::string> vtinstance4;
```

Ao usar uma definição de classe de modelo variadic, você também pode requisitar pelo menos um parâmetro:

```cpp
template <typename First, typename... Rest> class classname;
```

Aqui está um exemplo básico de sintaxe da *função do modelo variac:*

```cpp
template <typename... Arguments> returntype functionname(Arguments... args);
```

O pacote de *parâmetros Argumentos* é então expandido para uso, como mostrado na próxima seção, **Entendendo modelos variados**.

Outras formas de sintaxe de função de modelo variadic são possíveis, incluindo, mas não limitado a, esses exemplos:

```cpp
template <typename... Arguments> returntype functionname(Arguments&... args);
template <typename... Arguments> returntype functionname(Arguments&&... args);
template <typename... Arguments> returntype functionname(Arguments*... args);
```

Especificadores como **const** também são permitidos:

```cpp
template <typename... Arguments> returntype functionname(const Arguments&... args);
```

Tal como as definições de classe de modelo variadic, você pode criar funções que exigem ao menos um parâmetro:

```cpp
template <typename First, typename... Rest> returntype functionname(const First& first, const Rest&... args);
```

Os modelos Variadic usam o operador `sizeof...()` (não relacionado ao operador mais antigo `sizeof()`):

```cpp
template<typename... Arguments>
void tfunc(const Arguments&... args)
{
    constexpr auto numargs{ sizeof...(Arguments) };

    X xobj[numargs]; // array of some previously defined type X

    helper_func(xobj, args...);
}
```

## <a name="more-about-ellipsis-placement"></a>Mais sobre o posicionamento das reticências

Anteriormente, esse artigo descreveu a colocação de reticências que define pacotes e expansões de parâmetros como “à esquerda do nome do parâmetro, significa um pacote de parâmetros, e à direita do nome do parâmetro, expande os pacotes de parâmetros em nomes separados”. Isso é tecnicamente verdade, mas pode ser uma tradução confusa do código. Considerar:

- Em uma lista de parâmetros `typename...` de modelo (),`template <parameter-list>`introduz um parâmetro de modelo.

- Em uma cláusula de declaração de parâmetro (),`func(parameter-list)`uma elipse de "nível superior" introduz um pacote de parâmetros de função, e o posicionamento da elipse é importante:

    ```cpp
    // v1 is NOT a function parameter pack:
    template <typename... Types> void func1(std::vector<Types...> v1);

    // v2 IS a function parameter pack:
    template <typename... Types> void func2(std::vector<Types>... v2);
    ```

- Onde as reticências aparecem imediatamente após o nome de parâmetro, você tem uma expansão do pacote de parâmetros.

## <a name="example"></a>Exemplo

Uma boa maneira de ilustrar o mecanismo de função do modelo variadic é usá-lo em uma reescritura de algumas das funcionalidades de `printf`:

```cpp
#include <iostream>

using namespace std;

void print() {
    cout << endl;
}

template <typename T> void print(const T& t) {
    cout << t << endl;
}

template <typename First, typename... Rest> void print(const First& first, const Rest&... rest) {
    cout << first << ", ";
    print(rest...); // recursive call using pack expansion syntax
}

int main()
{
    print(); // calls first overload, outputting only a newline
    print(1); // calls second overload

    // these call the third overload, the variadic template,
    // which uses recursion as needed.
    print(10, 20);
    print(100, 200, 300);
    print("first", 2, "third", 3.14159);
}
```

## <a name="output"></a>Saída

```Output
1
10, 20
100, 200, 300
first, 2, third, 3.14159
```

> [!NOTE]
> A maioria das implementações que incorporam funções de modelo variatórias usam recursão de alguma forma, mas é ligeiramente diferente da recursão tradicional.  A recursão tradicional envolve uma função que se autodenomina usando a mesma assinatura. (Pode estar sobrecarregado ou modelado, mas a mesma assinatura é escolhida todas as vezes.) A recursão variada envolve chamar um modelo de função variada usando diferentes (quase sempre diminuindo) números de argumentos, e assim carimbar uma assinatura diferente a cada vez. Um “caso base” ainda é necessário, mas a natureza de recursão é diferente.
