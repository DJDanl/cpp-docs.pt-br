---
title: Erro do compilador C2672
ms.date: 10/24/2017
f1_keywords:
- C2672
helpviewer_keywords:
- C2672
ms.assetid: 7e86338a-2d4b-40fe-9dd2-ac6886f3f31a
ms.openlocfilehash: 9f844b54285a7df69bfb4387a7afcc82dfef9252
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80177125"
---
# <a name="compiler-error-c2672"></a>Erro do compilador C2672

> '*Function*': nenhuma função sobrecarregada correspondente encontrada

O compilador não pôde encontrar uma função sobrecarregada que corresponda à função especificada. Não foi encontrada nenhuma função que aceite parâmetros correspondentes ou nenhuma função correspondente tem a acessibilidade necessária no contexto.

Quando usado por determinados contêineres ou algoritmos de biblioteca padrão, seus tipos devem fornecer Membros acessíveis ou funções Friend que atendam aos requisitos do contêiner ou do algoritmo. Por exemplo, os tipos de iteradores devem derivar de `std::iterator<>`. As operações de comparação ou o uso de outros operadores em tipos de elementos de contêiner podem exigir que o tipo seja considerado como um operando à esquerda e à direita. O uso do tipo como um operando à direita pode exigir a implementação do operador como uma função não membro do tipo.

## <a name="example"></a>Exemplo

As versões do compilador antes do Visual Studio 2017 não realizaram a verificação de acesso em nomes qualificados em alguns contextos de modelo. Isso pode interferir no comportamento SFINAE esperado quando a substituição deve falhar devido à inacessibilidade de um nome. Eventualmente, isso poderia ter causado uma falha ou comportamento inesperado no runtime devido ao compilador ter chamado incorretamente a sobrecarga errada do operador. No Visual Studio 2017, é gerado um erro do compilador.

Este exemplo é compilado no Visual Studio 2015, mas gera um erro no Visual Studio 2017. Para corrigir esse problema, torne o membro de parâmetro de modelo acessível onde ele é avaliado.

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
