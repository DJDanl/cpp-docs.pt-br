---
title: '&lt;chão&gt;'
ms.date: 04/18/2019
f1_keywords:
- <execution>
- std::<execution>
helpviewer_keywords:
- execution header
ms.openlocfilehash: f37458fdc0b58968e095a7c59de797eac295bde7
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88835930"
---
# <a name="ltexecutiongt"></a>&lt;chão&gt;

Descreve as políticas de execução para algoritmos paralelos.

## <a name="syntax"></a>Sintaxe

```
namespace std {
    template<class T> inline constexpr bool is_execution_policy_v = is_execution_policy<T>::value;
}
namespace std::execution {
    inline constexpr sequenced_policy seq { unspecified };
    inline constexpr parallel_policy par { unspecified };
    inline constexpr parallel_unsequenced_policy par_unseq { unspecified };
}
```

### <a name="classes-and-structs"></a>Classes e structs

|Nome|Descrição|
|-|-|
|[is_execution_policy struct](is-execution-policy-struct.md)|Detecta políticas de execução para a finalidade de excluir assinaturas de função da participação de resolução de sobrecarga ambígua de outra forma.|
|[Classe parallel_policy](parallel-policy-class.md)|Usado como um tipo exclusivo para desambiguar a sobrecarga de algoritmo paralelo e indicar que a execução de um algoritmo paralelo pode ser paralelizada.|
|[Classe parallel_unsequenced_policy](parallel-unsequenced-policy-class.md)|Usado como um tipo exclusivo para desambiguar a sobrecarga de algoritmo paralelo e indicar que a execução de um algoritmo paralelo pode ser paralelizada e vetorizada.|
|[Classe sequenced_policy](sequenced-policy-class.md)|Usado como um tipo exclusivo para desambiguar a sobrecarga de algoritmo paralelo e exigir que a execução de um algoritmo paralelo não seja paralelizada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<execution>

**Namespace:** stdext

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](cpp-standard-library-header-files.md)\
[Segurança de thread na biblioteca padrão C++](thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão do C++](cpp-standard-library-reference.md)
