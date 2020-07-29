---
title: _set_new_mode
ms.date: 4/2/2020
api_name:
- _set_new_mode
- _o__set_new_mode
api_location:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-heap-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- set_new_mode
- _set_new_mode
helpviewer_keywords:
- handler modes
- _set_new_mode function
- set_new_mode function
ms.assetid: 4d14039a-e54e-4689-8c70-74a4b9834768
ms.openlocfilehash: aa21854f6a8c4b58a510b16e824449a53b91f329
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218527"
---
# <a name="_set_new_mode"></a>_set_new_mode

Define um novo modo de manipulador para **malloc**.

## <a name="syntax"></a>Sintaxe

```cpp
int _set_new_mode( int newhandlermode );
```

### <a name="parameters"></a>parâmetros

*newhandlermode*<br/>
Novo modo de manipulador para **malloc**; o valor válido é 0 ou 1.

## <a name="return-value"></a>Valor retornado

Retorna o modo de manipulador anterior definido para **malloc**. Um valor de retorno 1 indica que, em caso de falha ao alocar memória, **malloc** anteriormente chamou a nova rotina do manipulador; um valor de retorno 0 indica que ele não foi. Se o argumento *newhandlermode* não for igual a 0 ou 1, retornará-1.

## <a name="remarks"></a>Comentários

A função de C++ **set_new_mode** define o novo modo do manipulador para [malloc](malloc.md). O novo modo de manipulador indica se, em caso de falha, **malloc** é chamar a nova rotina do manipulador, conforme definido por [_set_new_handler](set-new-handler.md). Por padrão, o **malloc** não chama a nova rotina do manipulador em caso de falha para alocar memória. Você pode substituir esse comportamento padrão para que, quando **malloc** não aloca memória, **malloc** chame a nova rotina do manipulador da mesma maneira que o **`new`** operador faz quando ele falha pelo mesmo motivo. Para obter mais informações, consulte os operadores [new](../../cpp/new-operator-cpp.md) e [delete](../../cpp/delete-operator-cpp.md) na *Referência da Linguagem C++*. Para substituir o padrão, chame:

```cpp
_set_new_mode(1);
```

no início do programa ou link com NEWMODE. obj (consulte [Opções de link](../../c-runtime-library/link-options.md)).

Esta função valida seu parâmetro. Se *newhandlermode* for algo diferente de 0 ou 1, a função invocará o manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, <strong>_set_new_mode</strong> retornará-1 e definirá **errno** como `EINVAL` .

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_set_new_mode**|\<new.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Alocação de memória](../../c-runtime-library/memory-allocation.md)<br/>
[calloc](calloc.md)<br/>
[informações](free.md)<br/>
[realloc](realloc.md)<br/>
[_query_new_handler](query-new-handler.md)<br/>
[_query_new_mode](query-new-mode.md)<br/>
