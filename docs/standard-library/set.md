---
title: '&lt;set&gt;'
ms.date: 11/04/2016
f1_keywords:
- <set>
helpviewer_keywords:
- set header
ms.assetid: 43cb1ab2-6383-48cf-8bdc-2b96d7203596
ms.openlocfilehash: 4ac5c0bbf94c4d17389efb424d2e12b84717c4a9
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88846219"
---
# <a name="ltsetgt"></a>&lt;set&gt;

Define o conjunto de modelos de classe de contêiner e multiconjunto e seus modelos de suporte.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<set>

**Namespace:** std

> [!NOTE]
> A \<set> biblioteca também usa a `#include <initializer_list>` instrução.

## <a name="members"></a>Membros

### <a name="operators"></a>Operadores

|Versão do set|Versão do multiset|Descrição|
|-|-|-|
|[operador! = (conjunto)](../standard-library/set-operators.md#op_neq)|[operador! = (multiconjunto)](../standard-library/set-operators.md#op_neq)|Testa se o objeto set ou multiset à esquerda do operador é diferente do objeto set ou multiset à direita.|
|[< do operador (Set)](../standard-library/set-operators.md#op_lt)|[< do operador (multiconjunto)](../standard-library/set-operators.md#op_lt_multiset)|Testa se o objeto set ou multiset à esquerda do operador é menor que o objeto set ou multiset à direita.|
|[operador<= (Set)](../standard-library/set-operators.md#op_lt_eq)|[operator\<= (multiset)](../standard-library/set-operators.md#op_lt_eq_multiset)|Testa se o objeto set ou multiset à esquerda do operador é menor ou igual ao objeto set ou multiset à direita.|
|[Operator = = (Set)](../standard-library/set-operators.md#op_eq_eq)|[Operator = = (MultiSet)](../standard-library/set-operators.md#op_eq_eq_multiset)|Testa se o objeto set ou multiset à esquerda do operador é igual ao objeto set ou multiset à direita.|
|[> do operador (Set)](../standard-library/set-operators.md#op_gt)|[> do operador (multiconjunto)](../standard-library/set-operators.md#op_gt_multiset)|Testa se o objeto set ou multiset à esquerda do operador é maior que o objeto set ou multiset à direita.|
|[operador>= (Set)](../standard-library/set-operators.md#op_gt_eq)|[operador>= (multiconjunto)](../standard-library/set-operators.md#op_gt_eq_multiset)|Testa se o objeto set ou multiset à esquerda do operador é maior ou igual ao objeto set ou multiset à direita.|

### <a name="specialized-template-functions"></a>Funções de Modelo Especializadas

|Versão do set|Versão do multiset|Descrição|
|-|-|-|
|[permuta](../standard-library/set-functions.md#swap)|[swap (multiset)](../standard-library/set-functions.md#swap_multiset)|Troca os elementos de dois sets ou multisets.|

### <a name="classes"></a>Classes

|Nome|Descrição|
|-|-|
|[definir classe](../standard-library/set-class.md)|Usada para o armazenamento e a recuperação de dados de uma coleção na qual os valores dos elementos contidos são exclusivos e funcionam como os valores de chave, de acordo com os quais os dados são automaticamente ordenados.|
|[Classe multiconjunto](../standard-library/multiset-class.md)|Usada para o armazenamento e a recuperação de dados de uma coleção na qual os valores dos elementos contidos não precisam ser exclusivos e na qual funcionam como os valores de chave, de acordo com os quais os dados são automaticamente ordenados.|

## <a name="see-also"></a>Confira também

[Referência de arquivos de cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão do C++](../standard-library/cpp-standard-library-reference.md)
