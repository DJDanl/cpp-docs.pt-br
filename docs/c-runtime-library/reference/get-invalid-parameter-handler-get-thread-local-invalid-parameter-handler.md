---
title: _get_invalid_parameter_handler, _get_thread_local_invalid_parameter_handler
ms.date: 11/04/2016
api_name:
- _get_invalid_parameter_handler
- _get_thread_local_invalid_parameter_handler
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
- api-ms-win-crt-runtime-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _get_invalid_parameter_handler
- stdlib/_get_invalid_parameter_handler
- _get_thread_local_invalid_parameter_handler
- stdlib/_get_thread_local_invalid_parameter_handler
helpviewer_keywords:
- _get_thread_local_invalid_parameter_handler function
- _get_invalid_parameter_handler function
ms.assetid: a176da0e-38ca-4d99-92bb-b0e2b8072f53
ms.openlocfilehash: 572d21696d38c47fe0f67d68af5eb249aeb94319
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857795"
---
# <a name="_get_invalid_parameter_handler-_get_thread_local_invalid_parameter_handler"></a>_get_invalid_parameter_handler, _get_thread_local_invalid_parameter_handler

Obtém a função que é chamada quando o CRT detecta um argumento inválido.

## <a name="syntax"></a>Sintaxe

```C
_invalid_parameter_handler _get_invalid_parameter_handler(void);
_invalid_parameter_handler _get_thread_local_invalid_parameter_handler(void);
```

## <a name="return-value"></a>Valor retornado

Um ponteiro para a função do manipulador de parâmetro inválido definida atualmente ou um ponteiro nulo, se nenhum tiver sido definido.

## <a name="remarks"></a>Comentários

A função **_get_invalid_parameter_handler** Obtém o manipulador de parâmetro global inválido definido atualmente. Ela retornará um ponteiro nulo, se nenhum manipulador de parâmetro inválido global tiver sido definido. Da mesma forma, o **_get_thread_local_invalid_parameter_handler** Obtém o manipulador de parâmetros inválido local do thread atual do thread em que ele é chamado, ou um ponteiro nulo se nenhum manipulador foi definido. Para obter informações sobre como definir manipuladores de parâmetro inválido de thread local e global, consulte [_set_invalid_parameter_handler, _set_thread_local_invalid_parameter_handler](set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md).

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

## <a name="requirements"></a>Requisitos do

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_get_invalid_parameter_handler**, **_get_thread_local_invalid_parameter_handler**|C: \<stdlib.h><br /><br /> C++: \<cstdlib> ou \<stdlib.h>|

As funções **_get_invalid_parameter_handler** e **_get_thread_local_invalid_parameter_handler** são específicas da Microsoft. Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[_set_invalid_parameter_handler, _set_thread_local_invalid_parameter_handler](set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md)<br/>
[Versões de funções CRT com segurança aprimorada](../../c-runtime-library/security-enhanced-versions-of-crt-functions.md)<br/>
