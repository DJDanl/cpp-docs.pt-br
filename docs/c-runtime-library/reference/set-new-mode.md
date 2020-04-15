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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: 3a27717d65714de54f477e4e2b3f243c4631fd8c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81332316"
---
# <a name="_set_new_mode"></a>_set_new_mode

Define um novo modo de manipulador para **malloc**.

## <a name="syntax"></a>Sintaxe

```cpp
int _set_new_mode( int newhandlermode );
```

### <a name="parameters"></a>Parâmetros

*newhandlermode*<br/>
Novo modo de manipulador para **malloc;** valor válido é 0 ou 1.

## <a name="return-value"></a>Valor retornado

Retorna o modo de manipulador anterior definido para **malloc**. Um valor de retorno de 1 indica que, ao não alocar memória, **malloc** anteriormente chamado de nova rotina de manipulador; um valor de retorno de 0 indica que não. Se o argumento *newhandlermode* não for igual a 0 ou 1, retorna -1.

## <a name="remarks"></a>Comentários

A função de C++ **set_new_mode** define o novo modo do manipulador para [malloc](malloc.md). O novo modo de manipulador indica se, em falha, **malloc** deve chamar a nova rotina de manipulador conforme definido por [_set_new_handler](set-new-handler.md). Por padrão, **o malloc** não chama a nova rotina de manipulador na falha de alocar memória. Você pode substituir esse comportamento padrão para que, quando **o malloc** não aloque a memória, **o malloc** chame a nova rotina de manipulador da mesma forma que o **novo** operador faz quando falha pelo mesmo motivo. Para obter mais informações, consulte os operadores [new](../../cpp/new-operator-cpp.md) e [delete](../../cpp/delete-operator-cpp.md) na *Referência da Linguagem C++*. Para substituir o padrão, chame:

```cpp
_set_new_mode(1);
```

no início do seu programa ou link com Newmode.obj (ver [Opções de Link](../../c-runtime-library/link-options.md)).

Esta função valida seu parâmetro. Se *o novo modo de manipulador* for algo diferente de 0 ou 1, a função invoca o manipulador de parâmetros inválido, conforme descrito na Validação de [Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, <strong>_set_new_mode</strong> retorna -1 `EINVAL`e define **errno** para .

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_set_new_mode**|\<new.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Alocação de memória](../../c-runtime-library/memory-allocation.md)<br/>
[calloc](calloc.md)<br/>
[Livre](free.md)<br/>
[realloc](realloc.md)<br/>
[_query_new_handler](query-new-handler.md)<br/>
[_query_new_mode](query-new-mode.md)<br/>
