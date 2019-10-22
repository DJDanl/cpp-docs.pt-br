---
title: '&lt;queue&gt;'
ms.date: 11/04/2016
f1_keywords:
- <queue>
helpviewer_keywords:
- queue header
ms.assetid: 24fcf350-eb0e-48cf-9fef-978be1aeda1f
ms.openlocfilehash: ee35f880ddf40561cacb5c4d519f2e6291ad77a8
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72689110"
---
# <a name="ltqueuegt"></a>&lt;queue&gt;

Define os modelos de classe priority_queue e Queue e vários modelos de suporte.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<queue>

**Namespace:** std

> [!NOTE]
> A biblioteca \<queue > também usa a instrução `#include <initializer_list>`.

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
