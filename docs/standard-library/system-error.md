---
title: '&lt;system_error&gt;'
ms.date: 03/15/2019
f1_keywords:
- <system_error>
- system_error
helpviewer_keywords:
- system_error header
ms.assetid: 5e046c6e-48d9-4740-8c8a-05f3727c1215
ms.openlocfilehash: 4365f0aaf8fdd4d43159b78acf6dcffa4fcbe428
ms.sourcegitcommit: 3590dc146525807500c0477d6c9c17a4a8a2d658
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/16/2019
ms.locfileid: "68246558"
---
# <a name="ltsystemerrorgt"></a>&lt;system_error&gt;

Inclua o cabeçalho \<system_error > para definir a classe de exceção `system_error` e modelos relacionados para erros de nível inferior do sistema de processamento.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<system_error>

**Namespace:** std

## <a name="members"></a>Membros

### <a name="objects"></a>Objetos

|||
|-|-|
|[generic_category](../standard-library/system-error-functions.md#generic_category)|Representa a categoria de erros genéricos.|
|[is_error_code_enum_v](../standard-library/system-error-functions.md#is_error_code_enum_v)||
|[is_error_condition_enum_v](../standard-library/system-error-functions.md#is_error_condition_enum_v)||
|[system_category](../standard-library/system-error-functions.md#system_category)|Representa a categoria de erros causados por estouros de nível inferior do sistema.|

### <a name="functions"></a>Funções

|||
|-|-|
|[make_error_code](../standard-library/system-error-functions.md#make_error_code)|Cria um objeto de `error_code` .|
|[make_error_condition](../standard-library/system-error-functions.md#make_error_condition)|Cria um objeto de `error_condition` .|

### <a name="operators"></a>Operadores

|||
|-|-|
|[operator==](../standard-library/system-error-operators.md#op_eq_eq)|Testa se o objeto à esquerda do operador é igual ao objeto à direita.|
|[operator!=](../standard-library/system-error-operators.md#op_neq)|Testa se o objeto à esquerda do operador é diferente do objeto à direita.|
|[operator<](../standard-library/system-error-operators.md#op_lt)|Testa se um objeto é menor que o objeto passado para comparação.|
|[operator<<](../standard-library/system-error-operators.md#op_ostream)||

### <a name="enums"></a>Enums

|||
|-|-|
|[errc](../standard-library/system-error-enums.md#errc)|Fornece nomes simbólicos para todas as macros de código de erro definidas pelo Posix em `<errno.h>`.|

### <a name="classes-and-structs"></a>Classes e structs

|||
|-|-|
|[error_category](../standard-library/error-category-class.md)|Representa a base abstrata e comum para objetos e descreve uma categoria de códigos de erro.|
|[error_code](../standard-library/error-code-class.md)|Representa os erros de sistema de nível inferior específicos à implementação.|
|[error_condition](../standard-library/error-condition-class.md)|Representa códigos de erro definidos pelo usuário.|
|[hash](../standard-library/hash-structure.md#system_error)||
|[is_error_code_enum](../standard-library/is-error-code-enum-class.md)|Representa um predicado de tipo que testa a enumeração [Classe error_code](../standard-library/error-code-class.md).|
|[is_error_condition_enum](../standard-library/is-error-condition-enum-class.md)|Representa um predicado de tipo que testa a enumeração [Classe error_condition](../standard-library/error-condition-class.md).|
|[system_error](../standard-library/system-error-class.md)|Representa a classe base para todas as exceções geradas para relatar um estouro de nível inferior do sistema.|

## <a name="see-also"></a>Consulte também

[Referência de Arquivos de Cabeçalho](../standard-library/cpp-standard-library-header-files.md)<br/>
