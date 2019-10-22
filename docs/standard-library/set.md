---
title: '&lt;set&gt;'
ms.date: 11/04/2016
f1_keywords:
- <set>
helpviewer_keywords:
- set header
ms.assetid: 43cb1ab2-6383-48cf-8bdc-2b96d7203596
ms.openlocfilehash: fed6219c483bdade0132d5faae8b6597bcc5d732
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72686465"
---
# <a name="ltsetgt"></a>&lt;set&gt;

Define o conjunto de modelos de classe de contêiner e multiconjunto e seus modelos de suporte.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<set>

**Namespace:** std

> [!NOTE]
> A biblioteca \<set > também usa a instrução `#include <initializer_list>`.

## <a name="members"></a>Membros

### <a name="operators"></a>Operadores

|Versão do set|Versão do multiset|Descrição|
|-|-|-|
|[operator!= (set)](../standard-library/set-operators.md#op_neq)|[operator!= (multiset)](../standard-library/set-operators.md#op_neq)|Testa se o objeto set ou multiset à esquerda do operador é diferente do objeto set ou multiset à direita.|
|[operator< (set)](../standard-library/set-operators.md#op_lt)|[operator< (multiset)](../standard-library/set-operators.md#op_lt_multiset)|Testa se o objeto set ou multiset à esquerda do operador é menor que o objeto set ou multiset à direita.|
|[operator<= (set)](../standard-library/set-operators.md#op_lt_eq)|[operator\<= (multiset)](../standard-library/set-operators.md#op_lt_eq_multiset)|Testa se o objeto set ou multiset à esquerda do operador é menor ou igual ao objeto set ou multiset à direita.|
|[operator== (set)](../standard-library/set-operators.md#op_eq_eq)|[operator== (multiset)](../standard-library/set-operators.md#op_eq_eq_multiset)|Testa se o objeto set ou multiset à esquerda do operador é igual ao objeto set ou multiset à direita.|
|[operator> (set)](../standard-library/set-operators.md#op_gt)|[operator> (multiset)](../standard-library/set-operators.md#op_gt_multiset)|Testa se o objeto set ou multiset à esquerda do operador é maior que o objeto set ou multiset à direita.|
|[operator>= (set)](../standard-library/set-operators.md#op_gt_eq)|[operator>= (multiset)](../standard-library/set-operators.md#op_gt_eq_multiset)|Testa se o objeto set ou multiset à esquerda do operador é maior ou igual ao objeto set ou multiset à direita.|

### <a name="specialized-template-functions"></a>Funções de Modelo Especializadas

|Versão do set|Versão do multiset|Descrição|
|-|-|-|
|[swap](../standard-library/set-functions.md#swap)|[swap (multiset)](../standard-library/set-functions.md#swap_multiset)|Troca os elementos de dois sets ou multisets.|

### <a name="classes"></a>Classes

|||
|-|-|
|[Classe set](../standard-library/set-class.md)|Usada para o armazenamento e a recuperação de dados de uma coleção na qual os valores dos elementos contidos são exclusivos e funcionam como os valores de chave, de acordo com os quais os dados são automaticamente ordenados.|
|[Classe multiset](../standard-library/multiset-class.md)|Usada para o armazenamento e a recuperação de dados de uma coleção na qual os valores dos elementos contidos não precisam ser exclusivos e na qual funcionam como os valores de chave, de acordo com os quais os dados são automaticamente ordenados.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)\
[Referência da biblioteca padrão C++](../standard-library/cpp-standard-library-reference.md)
