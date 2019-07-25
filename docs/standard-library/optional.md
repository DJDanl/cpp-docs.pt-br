---
title: '&lt;optional&gt;'
ms.date: 11/04/2016
f1_keywords:
- <optional>
helpviewer_keywords:
- <optional>
ms.assetid: 8b4ab09e-1475-434a-b4e0-fdbc07a08b5b
ms.openlocfilehash: 83a0ad52735f92d731dafb32ad1be5a8278776b4
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68447176"
---
# <a name="ltoptionalgt"></a>&lt;optional&gt;

Define a classe de modelo de contêiner opcional e vários modelos de suporte.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<> opcional

**Namespace:** std

## <a name="members"></a>Membros

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator==](../standard-library/optional-operators.md#op_eq_eq)|Testa se o `optional` objeto no lado esquerdo do operador é igual `optional` ao objeto no lado direito.|
|[operator!=](../standard-library/optional-operators.md#op_neq)|Testa se o `optional` objeto no lado esquerdo do operador não é igual `optional` ao objeto no lado direito.|
|[operator<](../standard-library/optional-operators.md#op_lt)|Testa se o `optional` objeto no lado esquerdo do operador é menor que o `optional` objeto no lado direito.|
|[operator<=](../standard-library/optional-operators.md#op_lt_eq)|Testa se o `optional` objeto no lado esquerdo do operador é menor ou igual `optional` ao objeto no lado direito.|
|[operator>](../standard-library/optional-operators.md#op_gt)|Testa se o `optional` objeto no lado esquerdo do operador é maior que o `optional` objeto no lado direito.|
|[operator>=](../standard-library/optional-operators.md#op_lt_eq)|Testa se o `optional` objeto no lado esquerdo do operador é maior ou igual `optional` ao objeto no lado direito.|

> [!NOTE]
> Além das comparações relacionais \<, os operadores de > opcionais também dão `T`suporte à comparação com **nullopt** e.

### <a name="functions"></a>Funções

|||
|-|-|
|[make_optional](../standard-library/optional-functions.md#make_optional)|Torna um objeto opcional.|
|[swap](../standard-library/optional-functions.md#swap)||

### <a name="classes-and-structs"></a>Classes e structs

|||
|-|-|
|[hash]()||
|[Classe opcional](../standard-library/optional-class.md)|Descreve um objeto que pode ou não conter um valor.|
|[Estrutura nullopt_t](../standard-library/nullopt-t-structure.md)|Descreve um objeto que não contém um valor.|
|[Classe bad_optional_access](../standard-library/bad-optional-access-class.md)|Descreve um objeto gerado como uma exceção para relatar uma tentativa de acessar um valor que não está lá.|

### <a name="objects"></a>Objetos

|||
|-|-|
|[nullopt](../standard-library/optional-functions.md#nullopt)||

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
