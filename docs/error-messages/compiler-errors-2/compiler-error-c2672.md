---
title: C2672 de erro do compilador | Microsoft Docs
ms.date: 10/24/2017
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2672
dev_langs:
- C++
helpviewer_keywords:
- C2672
ms.assetid: 7e86338a-2d4b-40fe-9dd2-ac6886f3f31a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 98c569c8b9b1466f184b44d345e76341d1476935
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33236112"
---
# <a name="compiler-error-c2672"></a>C2672 de erro do compilador

> '*função*': função sobrecarregada não correspondente encontrada

O compilador não foi possível localizar uma função sobrecarregada que coincide com a função especificada. Nenhuma função foi encontrada que usa parâmetros ou nenhuma função correspondente correspondentes tem a acessibilidade necessária no contexto.

Quando usado por certos algoritmos ou contêineres da biblioteca padrão, seus tipos devem fornecer acessíveis membros ou funções de amigo que satisfazem os requisitos do contêiner ou algoritmo. Por exemplo, seus tipos de iterador devem derivar de `std::iterator<>`. Operações de comparação ou o uso de outros operadores em tipos de elemento de contêiner pode exigir o tipo ser considerado como um esquerdo e um operando direito. Use o tipo como um operando direito pode exigir a implementação do operador como uma função de membro não do tipo.

## <a name="example"></a>Exemplo

Versões do compilador antes de 2017 do Visual Studio não executam a verificação em nomes qualificados em alguns contextos de modelo de acesso. Isso pode interferir no comportamento SFINAE esperado quando a substituição deve falhar devido à inacessibilidade de um nome. Eventualmente, isso poderia ter causado uma falha ou comportamento inesperado no tempo de execução devido ao compilador ter chamado incorretamente a sobrecarga errada do operador. No Visual Studio 2017, é gerado um erro do compilador.

Este exemplo é compilado no Visual Studio 2015, mas gera um erro no Visual Studio de 2017. Para corrigir esse problema, verifique o membro de parâmetro de modelo acessível onde ela é avaliada.

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