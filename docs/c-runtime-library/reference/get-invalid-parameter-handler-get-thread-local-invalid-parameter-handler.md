---
title: _get_invalid_parameter_handler, _get_thread_local_invalid_parameter_handler | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _get_invalid_parameter_handler
- _get_thread_local_invalid_parameter_handler
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
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _get_invalid_parameter_handler
- stdlib/_get_invalid_parameter_handler
- _get_thread_local_invalid_parameter_handler
- stdlib/_get_thread_local_invalid_parameter_handler
dev_langs:
- C++
helpviewer_keywords:
- _get_thread_local_invalid_parameter_handler function
- _get_invalid_parameter_handler function
ms.assetid: a176da0e-38ca-4d99-92bb-b0e2b8072f53
caps.latest.revision: 3
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 9a3e4df593e027c77909f6d3d1ea7c7a106799a9
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="getinvalidparameterhandler-getthreadlocalinvalidparameterhandler"></a>_get_invalid_parameter_handler, _get_thread_local_invalid_parameter_handler

Obtém a função que é chamada quando o CRT detecta um argumento inválido.

## <a name="syntax"></a>Sintaxe

```C
_invalid_parameter_handler _get_invalid_parameter_handler(void);
_invalid_parameter_handler _get_thread_local_invalid_parameter_handler(void);
```

## <a name="return-value"></a>Valor de retorno

Um ponteiro para a função do manipulador de parâmetro inválido definida atualmente ou um ponteiro nulo, se nenhum tiver sido definido.

## <a name="remarks"></a>Comentários

O **_get_invalid_parameter_handler** função obtém atualmente definida manipulador global de parâmetro inválido. Ela retornará um ponteiro nulo, se nenhum manipulador de parâmetro inválido global tiver sido definido. Da mesma forma, o **_get_thread_local_invalid_parameter_handler** obtém o manipulador de parâmetro inválido de local de thread atual do thread for chamado, ou um ponteiro nulo se nenhum manipulador foi definido. Para obter informações sobre como definir manipuladores de parâmetro inválido de thread local e global, consulte [_set_invalid_parameter_handler, _set_thread_local_invalid_parameter_handler](set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md).

O ponteiro de função do manipulador de parâmetro inválido retornado tem o seguinte tipo:

```C
typedef void (__cdecl* _invalid_parameter_handler)(
    wchar_t const*,
    wchar_t const*,
    wchar_t const*,
    unsigned int,
    uintptr_t
    );
```

Para obter detalhes sobre o manipulador de parâmetro inválido, consulte o protótipo em [_set_invalid_parameter_handler, _set_thread_local_invalid_parameter_handler](set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_invalid_parameter_handler**, **_get_thread_local_invalid_parameter_handler**|C: \<stdlib.h><br /><br /> C++: \<cstdlib> ou \<stdlib.h>|

O **_get_invalid_parameter_handler** e **_get_thread_local_invalid_parameter_handler** funções são específicas da Microsoft. Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[_set_invalid_parameter_handler, _set_thread_local_invalid_parameter_handler](set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md)<br/>
[Versões de funções CRT com segurança aprimorada](../../c-runtime-library/security-enhanced-versions-of-crt-functions.md)<br/>
