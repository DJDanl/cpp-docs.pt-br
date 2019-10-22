---
title: '&lt;list&gt;'
ms.date: 11/04/2016
f1_keywords:
- <list>
- std::<list>
helpviewer_keywords:
- list header
ms.assetid: 2345823b-5612-44d8-95d3-aa96ed076d17
ms.openlocfilehash: c81990f14c6f9dc2400362015b838df5aed86429
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689425"
---
# <a name="ltlistgt"></a>&lt;list&gt;

Define a lista de modelos de classe de contêiner e vários modelos de suporte.

## <a name="syntax"></a>Sintaxe

```cpp
#include <list>
```

> [!NOTE]
> A biblioteca \<list > também usa a instrução `#include <initializer_list>`.

## <a name="members"></a>Membros

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator!=](../standard-library/list-operators.md#op_neq)|Testa se o objeto da lista à esquerda do operador é diferente do objeto da lista à direita.|
|[operator<](../standard-library/list-operators.md#op_lt)|Testa se o objeto da lista à esquerda do operador é menor que o objeto da lista à direita.|
|[operator\<=](../standard-library/list-operators.md#op_gt_eq)|Testa se o objeto da lista à esquerda do operador é menor que ou igual ao objeto da lista à direita.|
|[operator==](../standard-library/list-operators.md#op_eq_eq)|Testa se o objeto da lista à esquerda do operador é igual ao objeto da lista à direita.|
|[operator>](../standard-library/list-operators.md#op_gt)|Testa se o objeto da lista à esquerda do operador é maior que o objeto da lista à direita.|
|[operator>=](../standard-library/list-operators.md#op_gt_eq)|Testa se o objeto da lista à esquerda do operador é maior que ou igual ao objeto da lista à direita.|

### <a name="functions"></a>Funções

|||
|-|-|
|[swap](../standard-library/list-functions.md#swap)|Troca os elementos das duas listas.|

### <a name="classes"></a>Classes

|||
|-|-|
|[Classe list](../standard-library/list-class.md)|Um modelo de classe de contêineres de sequência que mantém seus elementos em uma organização linear e permite inserções e exclusões eficientes em qualquer local dentro da sequência.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
