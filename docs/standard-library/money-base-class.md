---
title: Classe money_base
ms.date: 11/04/2016
f1_keywords:
- xlocmon/std::money_base
helpviewer_keywords:
- money_base class
ms.assetid: 1a303c15-9272-4f26-ae16-dcf43a0fd38a
ms.openlocfilehash: c614832b0cbb1cc23e42ecb3a939ccf1334a5cea
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689320"
---
# <a name="money_base-class"></a>Classe money_base

A classe descreve uma enumeração e uma estrutura comum a todas as especializações do modelo de classe [moneypunct](../standard-library/moneypunct-class.md).

## <a name="syntax"></a>Sintaxe

```cpp
struct pattern
{
   char field[_PATTERN_FIELD_SIZE];
};
```

## <a name="remarks"></a>Comentários

A `part` de enumeração descreve os valores possíveis em elementos do campo de matriz no padrão de estrutura. Os valores de `part` são:

- `none` para corresponder a zero ou mais espaços ou não gerar nada.

- `sign` para corresponder ou gerar um sinal positivo ou negativo.

- `space` para corresponder a zero ou mais espaços ou gerar um espaço.

- `symbol` para corresponder ou gerar um símbolo de moeda.

- `value` para corresponder ou gerar um valor monetário.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<locale>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
