---
title: Modelos e resolução de nome
ms.date: 11/04/2016
ms.assetid: 519ba7b5-cd25-4549-865a-9a7b9dffdc28
ms.openlocfilehash: e4a53df0a192c1d7b7f376e4401eb99fcbf7d481
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50611920"
---
# <a name="templates-and-name-resolution"></a>Modelos e resolução de nome

Em definições de modelo, há três tipos de nomes.

- Nomes declarados localmente, incluindo o nome do próprio modelo e alguns nomes declarados na definição de modelo.

- Nomes de escopo delimitador fora da definição de modelo.

- Nomes que dependem de alguma forma dos argumentos do modelo, conhecidos como nomes dependentes.

Embora os primeiros dois nomes também pertençam aos escopos de classe e função, regras especiais para a resolução de nomes são necessárias nas definições de modelo para lidar com a complexidade adicional de nomes dependentes. Isso é porque o compilador não sabe muito sobre esses nomes até que o modelo instanciado, porque podem ser tipos completamente diferentes dependendo dos argumentos de modelo usados. Os nomes não dependentes são pesquisados de acordo com as regras comuns e no momento da definição do modelo. Esses nomes, sendo independentes dos argumentos de modelo, são procurados uma vez para todas as especializações de modelo. Os nomes dependentes não são pesquisados até que o modelo seja instanciado e são pesquisados separadamente para cada especialização.

Um tipo é dependente quando depende dos argumentos do modelo. Especificamente, um tipo é dependente quando é:

- O próprio argumento do modelo:

    ```cpp
    T
    ```

- Um nome qualificado com uma qualificação que inclui um tipo dependente:

    ```cpp
    T::myType
    ```

- Um nome qualificado se a parte não qualificada identifica um tipo dependente:

    ```cpp
    N::T
    ```

- Um tipo const ou volatile cujo tipo de base é um tipo dependente:

    ```cpp
    const T
    ```

- Um ponteiro, uma referência, uma matriz, ou um tipo de ponteiro de função baseado em um tipo dependente:

    ```cpp
    T *, T &, T [10], T (*)()
    ```

- Uma matriz cujo tamanho é baseado em um parâmetro do modelo:

    ```cpp
    template <int arg> class X {
    int x[arg] ; // dependent type
    }
    ```

- um tipo de modelo construído de um parâmetro do modelo:

    ```cpp
    T<int>, MyTemplate<T>
    ```

## <a name="type-dependence-and-value-dependence"></a>Dependência de tipo e dependência de valor

Os nomes e as expressões dependentes de um parâmetro de modelo são categorizados como dependentes de tipo ou de valor, dependendo se o parâmetro de modelo for um parâmetro de tipo ou um parâmetro de valor. Além disso, os identificadores declarados em um modelo com um tipo dependente do argumento de modelo são considerados dependentes de valor, pois é um tipo de integral ou de enumeração inicializado com uma expressão dependente de valor.

As expressões dependentes de tipo e de valor são expressões que envolvem variáveis que são dependentes de tipo ou de valor. Essas expressões podem ter a semântica diferente, dependendo dos parâmetros usados para o modelo.

## <a name="see-also"></a>Consulte também

[Modelos](../cpp/templates-cpp.md)