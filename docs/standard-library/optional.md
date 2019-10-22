---
title: '&lt;optional&gt;'
ms.date: 08/06/2019
f1_keywords:
- <optional>
helpviewer_keywords:
- <optional>
ms.openlocfilehash: bce31811c98d351f3c561b3136d41f7ed23d13e0
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72687254"
---
# <a name="ltoptionalgt"></a>&lt;optional&gt;

Define o modelo de classe de contêiner `optional` e vários modelos de suporte.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<optional >

**Namespace:** std

## <a name="members"></a>Membros

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator==](../standard-library/optional-operators.md#op_eq_eq)|Testa se um objeto é igual a outro objeto.|
|[operator!=](../standard-library/optional-operators.md#op_neq)|Testa se um objeto não é igual a outro objeto.|
|[operator<](../standard-library/optional-operators.md#op_lt)|Testa se o objeto à esquerda é menor que o objeto à direita.|
|[operator<=](../standard-library/optional-operators.md#op_lt_eq)|Testa se o objeto à esquerda é menor ou igual ao objeto à direita.|
|[operator>](../standard-library/optional-operators.md#op_gt)|Testa se o objeto à esquerda é maior que o objeto à direita.|
|[operator>=](../standard-library/optional-operators.md#op_lt_eq)|Testa se o objeto à esquerda é maior ou igual ao objeto à direita.|

> [!NOTE]
> Além das comparações relacionais, \<optional operadores de > também dão suporte à comparação com **nullopt** e `T`.

### <a name="functions"></a>Funções

|||
|-|-|
|[make_optional](../standard-library/optional-functions.md#make_optional)|Torna um objeto opcional.|
|[swap](../standard-library/optional-functions.md#swap)|Permuta os valores contidos de dois objetos `optional`.|

### <a name="classes-and-structs"></a>Classes e structs

|||
|-|-|
|hash|Retorna um hash do objeto contido.|
|[classe opcional](../standard-library/optional-class.md)|Descreve um objeto que pode ou não conter um valor.|
|[estrutura nullopt_t](../standard-library/nullopt-t-structure.md)|Descreve um objeto que não contém um valor.|
|[classe bad_optional_access](../standard-library/bad-optional-access-class.md)|Descreve um objeto gerado como uma exceção para relatar uma tentativa de acessar um valor que não está lá.|

### <a name="objects"></a>Objetos

|||
|-|-|
|[nullopt](../standard-library/optional-functions.md#nullopt)|Uma instância de `nullopt_t` para comparações.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
