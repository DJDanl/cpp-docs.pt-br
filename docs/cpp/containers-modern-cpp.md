---
title: Contêineres (C++ moderno)
ms.date: 01/18/2018
ms.topic: conceptual
ms.openlocfilehash: 37b540132fc9ddc03d5eaafd33c545b5db5e7935
ms.sourcegitcommit: effb516760c0f956c6308eeded48851accc96b92
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70926254"
---
# <a name="containers-modern-c"></a>Contêineres (C++ moderno)

Por padrão, use [vector](../standard-library/vector-class.md) como o contêiner sequencial preferencial C++no. Isso é equivalente a `List<T>` em linguagens .net.

```cpp
vector<string> apples;
apples.push_back("Granny Smith");
```

Use [MAP](../standard-library/map-class.md) (não `unordered_map`) como o contêiner associativo padrão. Use [set](../standard-library/set-class.md), [Multimap](../standard-library/multimap-class.md)e [multiconjunto](../standard-library/multiset-class.md) para degenerar & vários casos.

```cpp
map<string, string> apple_color;
// ...
apple_color["Granny Smith"] = "Green";
```

Quando a otimização de desempenho for necessária, considere o uso de:

- O tipo de [matriz](../standard-library/array-class-stl.md) ao inserir é importante, por exemplo, como um membro de classe.

- Contêineres associativos não ordenados, como [unordered_map](../standard-library/unordered-map-class.md). Elas têm uma sobrecarga por elemento menor e uma pesquisa em tempo constante, mas podem ser mais difíceis de usar de forma correta e eficiente.

- Classificado `vector`. Para obter mais informações, consulte [Algoritmos](../cpp/algorithms-modern-cpp.md).

Não use matrizes de estilo C. Para APIs mais antigas que precisam de acesso direto aos dados, use métodos de acessador, como `f(vec.data(), vec.size());` em vez disso.

Para obter mais informações sobre contêineres, consulte [ C++ standard library containers](../standard-library/stl-containers.md).

## <a name="see-also"></a>Consulte também

[Bem-vindo ao C++ (C++ moderno)](../cpp/welcome-back-to-cpp-modern-cpp.md)<br/>
[Referência da linguagem C++](../cpp/cpp-language-reference.md)<br/>
[Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)
