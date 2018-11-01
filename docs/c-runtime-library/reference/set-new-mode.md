---
title: _set_new_mode
ms.date: 11/04/2016
apiname:
- _set_new_mode
apilocation:
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
apitype: DLLExport
f1_keywords:
- set_new_mode
- _set_new_mode
helpviewer_keywords:
- handler modes
- _set_new_mode function
- set_new_mode function
ms.assetid: 4d14039a-e54e-4689-8c70-74a4b9834768
ms.openlocfilehash: 0228170e4ab5b55b4b061fa61a412766de77a063
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50602456"
---
# <a name="setnewmode"></a>_set_new_mode

Define um novo modo do manipulador **malloc**.

## <a name="syntax"></a>Sintaxe

```cpp
int _set_new_mode( int newhandlermode );
```

### <a name="parameters"></a>Parâmetros

*newhandlermode*<br/>
Novo modo do manipulador **malloc**; válido valor for 0 ou 1.

## <a name="return-value"></a>Valor de retorno

Retorna o manipulador anterior para o conjunto de modos **malloc**. Um valor retornado de 1 indica que, em caso de falha ao alocar memória, **malloc** chamado anteriormente a nova rotina do manipulador; um valor de retorno 0 indica que não funcionou. Se o *newhandlermode* argumento não é igual a 0 ou 1, retorna -1.

## <a name="remarks"></a>Comentários

A função de C++ **set_new_mode** define o novo modo do manipulador para [malloc](malloc.md). O novo modo do manipulador indica se, em caso de falha, **malloc** é chamar a nova rotina do manipulador conforme definido pela [set_new_handler](set-new-handler.md). Por padrão, **malloc** não chama a nova rotina do manipulador em caso de falha ao alocar memória. Você pode substituir esse comportamento padrão para que, quando **malloc** falhar ao alocar memória, **malloc** chame a nova rotina do manipulador da mesma forma que o **novo** operador faz Quando ele falha pelo mesmo motivo. Para obter mais informações, consulte os operadores [new](../../cpp/new-operator-cpp.md) e [delete](../../cpp/delete-operator-cpp.md) na *Referência da Linguagem C++*. Para substituir o padrão, chame:

```cpp
_set_new_mode(1);
```

no início do seu programa ou vincule com Newmode.obj (consulte [Opções de link](../../c-runtime-library/link-options.md)).

Esta função valida seu parâmetro. Se *newhandlermode* é qualquer coisa diferente de 0 ou 1, a função invocará o manipulador de parâmetro inválido, como descrita em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, <strong>set_new_mode</strong> retornará -1 e definirá **errno** para `EINVAL`.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_set_new_mode**|\<new.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Alocação de Memória](../../c-runtime-library/memory-allocation.md)<br/>
[calloc](calloc.md)<br/>
[free](free.md)<br/>
[realloc](realloc.md)<br/>
[_query_new_handler](query-new-handler.md)<br/>
[_query_new_mode](query-new-mode.md)<br/>
