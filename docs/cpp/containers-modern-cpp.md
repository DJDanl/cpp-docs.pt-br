---
title: Contêineres (C++ moderno)
ms.date: 1/18/2018
ms.topic: conceptual
ms.openlocfilehash: b25afe6d75147c37b92bf0805858a24f276195fd
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50564652"
---
# <a name="containers-modern-c"></a>Contêineres (C++ moderno)

Por padrão, use [vetor](../standard-library/vector-class.md) como o contêiner sequencial preferencial no C++. Isso é equivalente a `List<T>` em linguagens .NET.

```cpp
vector<string> apples;
apples.push_back("Granny Smith");
```

Use [mapa](../standard-library/map-class.md) (não `unordered_map`) como o contêiner associativo padrão. Use [definir](../standard-library/set-class.md), [multimap](../standard-library/multimap-class.md), e [multiset](../standard-library/multiset-class.md) para casos de degeneração & múltipla.

```cpp
map<string, string> apple_color;
// ...
apple_color["Granny Smith"] = "Green";
```

Quando for necessário otimizar o desempenho, considere usar:

- O [matriz](../standard-library/array-class-stl.md) quando a inserção é importante, por exemplo, como um membro de classe de tipo.

- Não ordenada de contêineres associativos, como [unordered_map](../standard-library/unordered-map-class.md). Elas têm o elemento de menor sobrecarga e pesquisa de tempo constante, mas eles podem ser mais difícil de usar de forma correta e eficiente.

- Classificado `vector`. Para obter mais informações, consulte [Algoritmos](../cpp/algorithms-modern-cpp.md).

Não use matrizes C-style. Para APIs mais antigas que precisa de acesso direto a dados, use os métodos de acessador como `f(vec.data(), vec.size());` em vez disso.

Para obter mais informações sobre contêineres, consulte [contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).

## <a name="see-also"></a>Consulte também

[Bem-vindo outra vez ao C++](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)