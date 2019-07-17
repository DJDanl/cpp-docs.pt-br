---
title: '&lt;optional&gt;'
ms.date: 11/04/2016
f1_keywords:
- <optional>
helpviewer_keywords:
- <optional>
ms.assetid: 8b4ab09e-1475-434a-b4e0-fdbc07a08b5b
ms.openlocfilehash: c73ad2ad94a5de29bc2c457fdf6ca8b9c783615c
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68268478"
---
# <a name="ltoptionalgt"></a>&lt;optional&gt;

Define a classe de modelo do contêiner opcional e vários modelos de suporte.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<opcional >

**Namespace:** std

## <a name="members"></a>Membros

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator==](../standard-library/optional-operators.md#op_eq_eq)|Testa se o `optional` objeto no lado esquerdo do operador é igual ao `optional` objeto no lado direito.|
|[operator!=](../standard-library/optional-operators.md#op_neq)|Testa se o `optional` objeto no lado esquerdo do operador não é igual ao `optional` objeto no lado direito.|
|[operator<](../standard-library/optional-operators.md#op_lt)|Testa se o `optional` objeto no lado esquerdo do operador é menor do que o `optional` objeto no lado direito.|
|[operator<=](../standard-library/optional-operators.md#op_lt_eq)|Testa se o `optional` objeto no lado esquerdo do operador é menor ou igual ao `optional` objeto no lado direito.|
|[operator>](../standard-library/optional-operators.md#op_gt)|Testa se o `optional` objeto no lado esquerdo do operador é maior que o `optional` objeto no lado direito.|
|[operator>=](../standard-library/optional-operators.md#op_lt_eq)|Testa se o `optional` objeto no lado esquerdo do operador é maior que ou igual ao `optional` objeto no lado direito.|

> [!NOTE]
> Além do relacional compara, \<opcional > operadores também dão suporte a comparação com **nullopt** e `T`.

### <a name="functions"></a>Funções

|||
|-|-|
|[make_optional](../standard-library/optional-functions.md#make_optional)|Faz com que um objeto opcional.|
|[swap](../standard-library/optional-functions.md#swap)||

### <a name="classes-and-structs"></a>Classes e structs

|||
|-|-|
|[hash]()||
|[Classe opcional](../standard-library/optional-class.md)|Descreve um objeto que pode ou não pode conter um valor.|
|[nullopt_t Struct](../standard-library/nullopt-t-structure.md)|Descreve um objeto que não contém um valor.|
|[Classe de bad_optional_access](../standard-library/bad-optional-access-class.md)|Descreve um objeto lançado como uma exceção para relatar uma tentativa de acessar um valor não existe.|

### <a name="objects"></a>Objetos

|||
|-|-|
|[nullopt](../standard-library/optional-functions.md#nullopt)||

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
