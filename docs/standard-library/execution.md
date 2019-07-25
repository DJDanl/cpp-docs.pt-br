---
title: '&lt;chão&gt;'
ms.date: 04/18/2019
f1_keywords:
- <execution>
- std::<execution>
helpviewer_keywords:
- execution header
ms.openlocfilehash: 3b0ccd540c56500c2f265aa6192a12fc2d5078b0
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68457976"
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

|||
|-|-|
|[Estrutura is_execution_policy](is-execution-policy-struct.md)|Detecta políticas de execução para a finalidade de excluir assinaturas de função da participação de resolução de sobrecarga ambígua de outra forma.|
|[Classe parallel_policy](parallel-policy-class.md)|Usado como um tipo exclusivo para desambiguar a sobrecarga de algoritmo paralelo e indicar que a execução de um algoritmo paralelo pode ser paralelizada.|
|[Classe parallel_unsequenced_policy](parallel-unsequenced-policy-class.md)|Usado como um tipo exclusivo para desambiguar a sobrecarga de algoritmo paralelo e indicar que a execução de um algoritmo paralelo pode ser paralelizada e vetorizada.|
|[Classe sequenced_policy](sequenced-policy-class.md)|Usado como um tipo exclusivo para desambiguar a sobrecarga de algoritmo paralelo e exigir que a execução de um algoritmo paralelo não seja paralelizada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<> de execução

**Namespace:** stdext

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](cpp-standard-library-header-files.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](cpp-standard-library-reference.md)
