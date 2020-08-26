---
title: '&lt;opcional&gt;'
ms.date: 08/06/2019
f1_keywords:
- <optional>
helpviewer_keywords:
- <optional>
ms.openlocfilehash: 31a3d9aad539e45bb835331a4ef63690d0e16f49
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88842670"
---
# <a name="ltoptionalgt"></a>&lt;opcional&gt;

Define o modelo de classe de contêiner `optional` e vários modelos de suporte.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<optional>

**Namespace:** std

## <a name="members"></a>Membros

### <a name="operators"></a>Operadores

|Nome|Descrição|
|-|-|
|[operador = =](../standard-library/optional-operators.md#op_eq_eq)|Testa se um objeto é igual a outro objeto.|
|[operador! =](../standard-library/optional-operators.md#op_neq)|Testa se um objeto não é igual a outro objeto.|
|[<do operador ](../standard-library/optional-operators.md#op_lt)|Testa se o objeto à esquerda é menor que o objeto à direita.|
|[<do operador =](../standard-library/optional-operators.md#op_lt_eq)|Testa se o objeto à esquerda é menor ou igual ao objeto à direita.|
|[>do operador ](../standard-library/optional-operators.md#op_gt)|Testa se o objeto à esquerda é maior que o objeto à direita.|
|[>do operador =](../standard-library/optional-operators.md#op_lt_eq)|Testa se o objeto à esquerda é maior ou igual ao objeto à direita.|

> [!NOTE]
> Além das comparações relacionais, os \<optional> operadores também dão suporte à comparação com **nullopt** e `T` .

### <a name="functions"></a>Funções

|Nome|Descrição|
|-|-|
|[make_optional](../standard-library/optional-functions.md#make_optional)|Torna um objeto opcional.|
|[permuta](../standard-library/optional-functions.md#swap)|Permuta os valores contidos de dois `optional` objetos.|

### <a name="classes-and-structs"></a>Classes e structs

|Nome|Descrição|
|-|-|
|hash|Retorna um hash do objeto contido.|
|[Classe optional](../standard-library/optional-class.md)|Descreve um objeto que pode ou não conter um valor.|
|[nullopt_t struct](../standard-library/nullopt-t-structure.md)|Descreve um objeto que não contém um valor.|
|[classe bad_optional_access](../standard-library/bad-optional-access-class.md)|Descreve um objeto gerado como uma exceção para relatar uma tentativa de acessar um valor que não está lá.|

### <a name="objects"></a>Objetos

|Nome|Descrição|
|-|-|
|[nullopt](../standard-library/optional-functions.md#nullopt)|Uma instância do para comparações `nullopt_t` .|

## <a name="see-also"></a>Confira também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
