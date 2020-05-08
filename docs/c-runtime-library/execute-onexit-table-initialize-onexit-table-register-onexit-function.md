---
title: _execute_onexit_table, _initialize_onexit_table, _register_onexit_function
ms.date: 4/2/2020
api_name:
- _execute_onexit_table
- _initialize_onexit_table
- _register_onexit_function
- _o__execute_onexit_table
- _o__initialize_onexit_table
- _o__register_onexit_function
api_location:
- api-ms-win-crt-runtime-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _execute_onexit_table
- process/_execute_onexit_table
- _initialize_onexit_table
- process/_initialize_onexit_table
- _register_onexit_function
- process/_register_onexit_function
helpviewer_keywords:
- _execute_onexit_table function
- _initialize_onexit_table function
- _register_onexit_function function
ms.assetid: ad9e4149-d4ad-4fdf-aaaf-cf786fcb4473
ms.openlocfilehash: 051961f049109b4fa6a2881e442e621036cb279c
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82913832"
---
# <a name="_execute_onexit_table-_initialize_onexit_table-_register_onexit_function"></a>_execute_onexit_table, _initialize_onexit_table, _register_onexit_function

Gerencia as rotinas que serão chamadas no tempo de saída.

## <a name="syntax"></a>Sintaxe

```
int _initialize_onexit_table(
    _onexit_table_t* table
    );

int _register_onexit_function(
    _onexit_table_t* table,
    _onexit_t        function
    );

int _execute_onexit_table(
    _onexit_table_t* table
    );
```

#### <a name="parameters"></a>Parâmetros

*table*<br/>
[in, out] Ponteiro para a tabela de função onexit.

*funcionamento*<br/>
[in] Ponteiro para uma função a ser adicionada à tabela de função onexit.

## <a name="return-value"></a>Valor retornado

Se for bem-sucedido, retornará 0. Caso contrário, retornará um valor negativo.

## <a name="remarks"></a>Comentários

Essas funções são detalhes da implementação de infraestrutura usada para dar suporte ao runtime C e não devem ser chamadas diretamente no seu código. O tempo de execução C usa uma *tabela de funções onexit* para representar a sequência de funções registradas `at_quick_exit`por chamadas `_onexit`para `atexit`, e. A estrutura de dados de tabela de função onexit é um detalhe de implementação opaco do runtime C; a ordem e o significado de seus membros de dados podem ser alterados. Eles não devem ser examinados pelo código externo.

A função `_initialize_onexit_table` inicializa a tabela de função onexit para seu valor inicial.  Essa função deve ser chamada antes que a tabela de função onexit seja passada para `_register_onexit_function` ou `_execute_onexit_table`.

A função `_register_onexit_function` acrescenta uma função ao final da tabela de função onexit.

A função `_execute_onexit_table` executa todas as funções na tabela de função onexit, limpa a tabela e, em seguida, retorna. Após uma chamada para `_execute_onexit_table`, a tabela fica em um estado inválido. Ela deve ser reinicializada por uma chamada para `_initialize_onexit_table` antes de ser usada novamente.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|`_initialize_onexit_table function`, `_register_onexit_function`, `_execute_onexit_table`|C, C++: \<process.h>|

As `_initialize_onexit_table`funções `_register_onexit_function`, e `_execute_onexit_table` são específicas da Microsoft. Para obter informações sobre compatibilidade, consulte [Compatibilidade](../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[atexit](../c-runtime-library/reference/atexit.md)<br/>
[exit, _Exit, _exit](../c-runtime-library/reference/exit-exit-exit.md)<br/>
[_onexit, _onexit_m](../c-runtime-library/reference/onexit-onexit-m.md)
