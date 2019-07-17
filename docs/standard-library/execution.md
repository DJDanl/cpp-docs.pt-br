---
title: '&lt;Execução&gt;'
ms.date: 04/18/2019
f1_keywords:
- <execution>
- std::<execution>
helpviewer_keywords:
- execution header
ms.openlocfilehash: 3bce34019f9ed4880d72a9d16c3c8b78dde0e0e3
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68268418"
---
# <a name="ltexecutiongt"></a>&lt;Execução&gt;

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
|[is_execution_policy Struct](is-execution-policy-struct.md)|Detecta as políticas de execução com a finalidade de excluindo assinaturas de função de participação de resolução de sobrecarga ambígua caso contrário.|
|[Classe de parallel_policy](parallel-policy-class.md)|Usado como um tipo exclusivo para resolver a ambiguidade de sobrecarga de algoritmo paralelo e indicam que a execução de um algoritmo paralelo pode ser paralelizada.|
|[Classe de parallel_unsequenced_policy](parallel-unsequenced-policy-class.md)|Usado como um tipo exclusivo para resolver a ambiguidade de sobrecarga de algoritmo paralelo e indicam que a execução de um algoritmo paralelo pode ser colocados em paralelo e vetorizada.|
|[Classe de sequenced_policy](sequenced-policy-class.md)|Usado como um tipo exclusivo para resolver a ambiguidade de sobrecarga de algoritmo paralelo e exigem a execução de um algoritmo paralelo não pode ser paralelizada.|

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<execução >

**Namespace:** stdext

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](cpp-standard-library-header-files.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](cpp-standard-library-reference.md)
