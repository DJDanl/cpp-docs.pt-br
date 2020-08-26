---
title: '&lt;system_error&gt;'
ms.date: 03/15/2019
f1_keywords:
- <system_error>
- system_error
helpviewer_keywords:
- system_error header
ms.assetid: 5e046c6e-48d9-4740-8c8a-05f3727c1215
ms.openlocfilehash: 18df18379fbee8271ba5cf851b04210f1dfddf57
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88841877"
---
# <a name="ltsystem_errorgt"></a>&lt;system_error&gt;

Inclua o cabeçalho \<system_error> para definir a classe de exceção `system_error` e modelos relacionados para o processamento de erros de nível inferior do sistema.

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<system_error>

**Namespace:** std

## <a name="members"></a>Membros

### <a name="objects"></a>Objetos

|Nome|Descrição|
|-|-|
|[generic_category](../standard-library/system-error-functions.md#generic_category)|Representa a categoria de erros genéricos.|
|[is_error_code_enum_v](../standard-library/system-error-functions.md#is_error_code_enum_v)||
|[is_error_condition_enum_v](../standard-library/system-error-functions.md#is_error_condition_enum_v)||
|[system_category](../standard-library/system-error-functions.md#system_category)|Representa a categoria de erros causados por estouros de nível inferior do sistema.|

### <a name="functions"></a>Funções

|Nome|Descrição|
|-|-|
|[make_error_code](../standard-library/system-error-functions.md#make_error_code)|Cria um objeto de `error_code` .|
|[make_error_condition](../standard-library/system-error-functions.md#make_error_condition)|Cria um objeto de `error_condition` .|

### <a name="operators"></a>Operadores

|Nome|Descrição|
|-|-|
|[operador = =](../standard-library/system-error-operators.md#op_eq_eq)|Testa se o objeto à esquerda do operador é igual ao objeto à direita.|
|[operador! =](../standard-library/system-error-operators.md#op_neq)|Testa se o objeto à esquerda do operador é diferente do objeto à direita.|
|[<do operador ](../standard-library/system-error-operators.md#op_lt)|Testa se um objeto é menor que o objeto passado para comparação.|
|[<<do operador ](../standard-library/system-error-operators.md#op_ostream)||

### <a name="enums"></a>Enumerações

|Nome|Descrição|
|-|-|
|[errc](../standard-library/system-error-enums.md#errc)|Fornece nomes simbólicos para todas as macros de código de erro definidas pelo POSIX em `<errno.h>` .|

### <a name="classes-and-structs"></a>Classes e structs

|Nome|Descrição|
|-|-|
|[error_category](../standard-library/error-category-class.md)|Representa a base abstrata e comum para objetos e descreve uma categoria de códigos de erro.|
|[error_code](../standard-library/error-code-class.md)|Representa os erros de sistema de nível inferior específicos à implementação.|
|[error_condition](../standard-library/error-condition-class.md)|Representa códigos de erro definidos pelo usuário.|
|[hash](../standard-library/hash-structure.md#system_error)||
|[is_error_code_enum](../standard-library/is-error-code-enum-class.md)|Representa um predicado de tipo que testa a enumeração [Classe error_code](../standard-library/error-code-class.md).|
|[is_error_condition_enum](../standard-library/is-error-condition-enum-class.md)|Representa um predicado de tipo que testa a enumeração [Classe error_condition](../standard-library/error-condition-class.md).|
|[system_error](../standard-library/system-error-class.md)|Representa a classe base para todas as exceções geradas para relatar um estouro de nível inferior do sistema.|

## <a name="see-also"></a>Confira também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)
