---
title: _set_new_mode | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- handler modes
- _set_new_mode function
- set_new_mode function
ms.assetid: 4d14039a-e54e-4689-8c70-74a4b9834768
caps.latest.revision: 14
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 0fa7022c5195882145452fa14e0cbf7347573a0a
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="setnewmode"></a>_set_new_mode

Define um novo modo de manipulador para **malloc**.

## <a name="syntax"></a>Sintaxe

```cpp
int _set_new_mode( int newhandlermode );
```

### <a name="parameters"></a>Parâmetros

*newhandlermode*<br/>
Novo modo de manipulador para **malloc**; válido valor for 0 ou 1.

## <a name="return-value"></a>Valor de retorno

Retorna o manipulador anterior modo conjunto para **malloc**. A retornar o valor de 1 indica que, em caso de falha ao alocar memória, **malloc** anteriormente chamado de rotina do manipulador de novo; um valor de retorno 0 indica que não compraram. Se o *newhandlermode* argumento não é igual a 0 ou 1, retornará -1.

## <a name="remarks"></a>Comentários

A função de C++ **set_new_mode** define o novo modo do manipulador para [malloc](malloc.md). O novo modo de manipulador indica se, em caso de falha **malloc** é chamar a rotina do manipulador de novo conforme definido pela [set_new_handler](set-new-handler.md). Por padrão, **malloc** não chamar a rotina do manipulador de novo em caso de falha ao alocar memória. Você pode substituir esse comportamento padrão para que, quando **malloc** Falha ao alocar memória, **malloc** chama a rotina do manipulador de novo na mesma forma que o **novo** does de operador Quando falhar pela mesma razão. Para obter mais informações, consulte os operadores [new](../../cpp/new-operator-cpp.md) e [delete](../../cpp/delete-operator-cpp.md) na *Referência da Linguagem C++*. Para substituir o padrão, chame:

```cpp
_set_new_mode(1);
```

no início do seu programa ou vincule com Newmode.obj (consulte [Opções de link](../../c-runtime-library/link-options.md)).

Esta função valida seu parâmetro. Se *newhandlermode* qualquer coisa diferente de 0 ou 1, a função invoca o manipulador de parâmetro inválido, como descrita no [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, **_ * set_new_mode** retorna -1 e define **errno** para **EINVAL**.

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
