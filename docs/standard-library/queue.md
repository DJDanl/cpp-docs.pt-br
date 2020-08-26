---
title: '&lt;queue&gt;'
ms.date: 11/04/2016
f1_keywords:
- <queue>
helpviewer_keywords:
- queue header
ms.assetid: 24fcf350-eb0e-48cf-9fef-978be1aeda1f
ms.openlocfilehash: a41d34b45264472a5c8c88ca0619e78444dd8aec
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88832588"
---
# <a name="ltqueuegt"></a>&lt;queue&gt;

Define os modelos de classe priority_queue e fila e vários modelos de suporte.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<queue>

**Namespace:** std

> [!NOTE]
> A \<queue> biblioteca também usa a `#include <initializer_list>` instrução.

## <a name="members"></a>Membros

### <a name="operators"></a>Operadores

|Nome|Descrição|
|-|-|
|[operador! =](../standard-library/queue-operators.md#op_neq)|Testa se o objeto da fila do lado esquerdo do operador não é igual ao do lado direito.|
|[<do operador ](../standard-library/queue-operators.md#op_lt)|Testa se o objeto da fila do lado esquerdo do operador é menor que o do lado direito.|
|[operador\<=](../standard-library/queue-operators.md#op_gt_eq)|Testa se o objeto da fila do lado esquerdo do operador é menor ou igual ao do lado direito.|
|[operador = =](../standard-library/queue-operators.md#op_eq_eq)|Testa se o objeto da fila do lado esquerdo do operador é igual ao do lado direito.|
|[>do operador ](../standard-library/queue-operators.md#op_gt)|Testa se o objeto da fila do lado esquerdo do operador é maior que o do lado direito.|
|[>do operador =](../standard-library/queue-operators.md#op_gt_eq)|Testa se o objeto de fila do lado esquerdo do operador é maior ou igual ao do lado direito.|

### <a name="classes"></a>Classes

|Nome|Descrição|
|-|-|
|[Classe de fila](../standard-library/queue-class.md)|Uma classe do adaptador de contêiner de modelo que fornece uma restrição de funcionalidade que limita o acesso aos elementos inicial e final de alguns tipos de contêiner subjacentes.|
|[Classe priority_queue](../standard-library/priority-queue-class.md)|Uma classe do adaptador de contêiner de modelo que fornece uma restrição de funcionalidade para limitar o acesso ao elemento superior de alguns tipos de contêiner subjacentes, que sempre é o maior.|

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)
