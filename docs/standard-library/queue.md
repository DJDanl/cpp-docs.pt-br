---
title: '&lt;queue&gt;'
ms.date: 11/04/2016
f1_keywords:
- <queue>
helpviewer_keywords:
- queue header
ms.assetid: 24fcf350-eb0e-48cf-9fef-978be1aeda1f
ms.openlocfilehash: 506ab5fccd44ad37a08a9f741f44f24d3a85b87d
ms.sourcegitcommit: 16c0392fc8d96e814c3a40b0c5346d7389aeb525
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/12/2019
ms.locfileid: "68956991"
---
# <a name="ltqueuegt"></a>&lt;queue&gt;

Define o priority_queue e queue das classes de modelo e de vários modelos de suporte.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<queue>

**Namespace:** std

> [!NOTE]
> A \<biblioteca de > de fila também `#include <initializer_list>` usa a instrução.

## <a name="members"></a>Membros

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator!=](../standard-library/queue-operators.md#op_neq)|Testa se o objeto da fila do lado esquerdo do operador não é igual ao do lado direito.|
|[operator<](../standard-library/queue-operators.md#op_lt)|Testa se o objeto da fila do lado esquerdo do operador é menor que o do lado direito.|
|[operator\<=](../standard-library/queue-operators.md#op_gt_eq)|Testa se o objeto da fila do lado esquerdo do operador é menor ou igual ao do lado direito.|
|[operator==](../standard-library/queue-operators.md#op_eq_eq)|Testa se o objeto da fila do lado esquerdo do operador é igual ao do lado direito.|
|[operator>](../standard-library/queue-operators.md#op_gt)|Testa se o objeto da fila do lado esquerdo do operador é maior que o do lado direito.|
|[operator>=](../standard-library/queue-operators.md#op_gt_eq)|Testa se o objeto de fila do lado esquerdo do operador é maior ou igual ao do lado direito.|

### <a name="classes"></a>Classes

|||
|-|-|
|[Classe queue](../standard-library/queue-class.md)|Uma classe do adaptador de contêiner de modelo que fornece uma restrição de funcionalidade que limita o acesso aos elementos inicial e final de alguns tipos de contêiner subjacentes.|
|[Classe priority_queue](../standard-library/priority-queue-class.md)|Uma classe do adaptador de contêiner de modelo que fornece uma restrição de funcionalidade para limitar o acesso ao elemento superior de alguns tipos de contêiner subjacentes, que sempre é o maior.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
