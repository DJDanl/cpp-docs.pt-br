---
title: '&lt;queue&gt; | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- <queue>
dev_langs:
- C++
helpviewer_keywords:
- queue header
ms.assetid: 24fcf350-eb0e-48cf-9fef-978be1aeda1f
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7ba139e2b50f1dd7c9887701a522a002173c21ee
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33853671"
---
# <a name="ltqueuegt"></a>&lt;queue&gt;

Define o priority_queue e queue das classes de modelo e de vários modelos de suporte.

## <a name="syntax"></a>Sintaxe

```cpp
#include <queue>

```

### <a name="operators"></a>Operadores

|Operador|Descrição|
|-|-|
|[operator!=](../standard-library/queue-operators.md#op_neq)|Testa se o objeto da fila do lado esquerdo do operador não é igual ao do lado direito.|
|[operator<](../standard-library/queue-operators.md#op_lt)|Testa se o objeto da fila do lado esquerdo do operador é menor que o do lado direito.|
|[operator\<=](../standard-library/queue-operators.md#op_gt_eq)|Testa se o objeto da fila do lado esquerdo do operador é menor ou igual ao do lado direito.|
|[operator==](../standard-library/queue-operators.md#op_eq_eq)|Testa se o objeto da fila do lado esquerdo do operador é igual ao do lado direito.|
|[operator>](../standard-library/queue-operators.md#op_gt)|Testa se o objeto da fila do lado esquerdo do operador é maior que o do lado direito.|
|[operator>=](../standard-library/queue-operators.md#op_gt_eq)|Testa se o objeto de fila do lado esquerdo do operador é maior ou igual ao do lado direito.|

### <a name="classes"></a>Classes

|Classe|Descrição|
|-|-|
|[Classe queue](../standard-library/queue-class.md)|Uma classe do adaptador de contêiner de modelo que fornece uma restrição de funcionalidade que limita o acesso aos elementos inicial e final de alguns tipos de contêiner subjacentes.|
|[Classe priority_queue](../standard-library/priority-queue-class.md)|Uma classe do adaptador de contêiner de modelo que fornece uma restrição de funcionalidade para limitar o acesso ao elemento superior de alguns tipos de contêiner subjacentes, que sempre é o maior.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)<br/>
