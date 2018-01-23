---
title: "Contêineres (C++ moderno) | Microsoft Docs"
ms.custom: 
ms.date: 1/18/2018
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: d43570f644e9627de5a40fc5b824a17e4fd33ffc
ms.sourcegitcommit: 6f40bba1772a09ff0e3843d5f70b553e1a15ab50
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/22/2018
---
# <a name="containers-modern-c"></a>Contêineres (C++ moderno)

Por padrão, usam [vetor](../standard-library/vector-class.md) como o contêiner sequencial preferencial em C++. Isso é equivalente a `List<T>` em linguagens .NET.

```cpp
vector<string> apples;
apples.push_back("Granny Smith");
```

Use [mapa](../standard-library/map-class.md) (não `unordered_map`) como o contêiner de associação padrão. Use [definir](../standard-library/set-class.md), [multimap](../standard-library/multimap-class.md), e [multiset](../standard-library/multiset-class.md) degenerado & vários casos.

```cpp
map<string, string> apple_color;
// ...
apple_color["Granny Smith"] = "Green";
```

Quando for necessário otimizar o desempenho, considere o uso de:

- O [matriz](../standard-library/array-class-stl.md) quando incorporação é importante, por exemplo, como um membro de classe de tipo.

- Não ordenados associativos contêineres como [unordered_map](../standard-library/unordered-map-class.md). Eles têm o elemento de menor sobrecarga e pesquisa de tempo constante, mas eles podem ser mais difícil de usar de forma correta e eficiente.

- Classificados **vetor**. Para obter mais informações, consulte [Algoritmos](../cpp/algorithms-modern-cpp.md).

Não use matrizes de estilo C. Para APIs mais antigos que precisam de acesso aos dados direto, usar os métodos de acessador como `f(vec.data(), vec.size());` em vez disso.

Para obter mais informações sobre contêineres, consulte [contêineres da biblioteca padrão C++](../standard-library/stl-containers.md).

## <a name="see-also"></a>Consulte também

[Bem-vindo outra vez ao C++](../cpp/welcome-back-to-cpp-modern-cpp.md)  
[Referência da linguagem C++](../cpp/cpp-language-reference.md)  
[Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)  
