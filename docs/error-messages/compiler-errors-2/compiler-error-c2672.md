---
title: Erro do compilador C2672
ms.date: 10/24/2017
f1_keywords:
- C2672
helpviewer_keywords:
- C2672
ms.assetid: 7e86338a-2d4b-40fe-9dd2-ac6886f3f31a
ms.openlocfilehash: df0f656c9db23739ec62629088b9cc5f7950a92d
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50570437"
---
# <a name="compiler-error-c2672"></a>Erro do compilador C2672

> '*função*': função sobrecarregada não correspondente encontrada

O compilador não foi possível encontrar uma função sobrecarregada que corresponde à função especificada. Foi encontrada nenhuma função que usa a correspondência de parâmetros ou nenhuma função correspondente tem a acessibilidade necessária no contexto.

Quando usado por determinados algoritmos ou contêineres da biblioteca padrão, seus tipos devem fornecer membros acessíveis ou funções de amigo que satisfazem os requisitos do contêiner ou algoritmo. Por exemplo, seus tipos de iterador devem derivar de `std::iterator<>`. Operações de comparação ou o uso de outros operadores em tipos de elemento de contêiner pode exigir que o tipo de ser considerado como um lado esquerdo e um operando à direita. Usar o tipo como um operando à direita pode exigir a implementação do operador como uma função não membro do tipo.

## <a name="example"></a>Exemplo

Versões do compilador antes do Visual Studio 2017 não executou a verificação de acesso em nomes qualificados em alguns contextos de modelo. Isso pode interferir no comportamento SFINAE esperado quando a substituição deve falhar devido à inacessibilidade de um nome. Eventualmente, isso poderia ter causado uma falha ou comportamento inesperado no tempo de execução devido ao compilador ter chamado incorretamente a sobrecarga errada do operador. No Visual Studio 2017, é gerado um erro do compilador.

Este exemplo é compilado no Visual Studio 2015, mas gera um erro no Visual Studio 2017. Para corrigir esse problema, torne o membro de parâmetro de modelo acessível no qual ela é avaliada.

```cpp
#include <type_traits>

template <class T> class S {
// public:    // Uncomment this line to fix
    typedef typename T type;
};

template <class T, std::enable_if<std::is_integral<typename S<T>::type>::value, T> * = 0>
bool f(T x)
{
    return (x == 0);
}

int main()
{
    f(10); // C2672: No matching overloaded function found.
}
```