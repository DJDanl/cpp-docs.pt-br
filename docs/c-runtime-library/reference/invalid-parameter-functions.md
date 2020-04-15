---
title: _invalid_parameter, _invalid_parameter_noinfo, _invalid_parameter_noinfo_noreturn, _invoke_watson
ms.date: 4/2/2020
api_name:
- _invalid_parameter
- _invalid_parameter_noinfo
- _invalid_parameter_noinfo_noreturn
- _invoke_watson
- _o__invalid_parameter_noinfo
- _o__invalid_parameter_noinfo_noreturn
api_location:
- api-ms-win-crt-runtime-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- CORECRT/_invalid_parameter
- _invalid_parameter
- CORECRT/_invalid_parameter_noinfo
- _invalid_parameter_noinfo
- CORECRT/_invalid_parameter_noinfo_noreturn
- _invalid_parameter_noinfo_noreturn
- CORECRT/_invoke_watson
- _invoke_watson
ms.assetid: a4d6f1fd-ce56-4783-8719-927151a7a814
ms.openlocfilehash: 0f0a3ea3e1f2e43d53650b4017905c696269ce20
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81343936"
---
# <a name="_invalid_parameter-_invalid_parameter_noinfo-_invalid_parameter_noinfo_noreturn-_invoke_watson"></a>_invalid_parameter, _invalid_parameter_noinfo, _invalid_parameter_noinfo_noreturn, _invoke_watson

Essas funções são usadas pela Biblioteca em Runtime do C para lidar com parâmetros inválidos passados para funções da biblioteca do CRT. Seu código também pode usar essas funções para dar suporte à manipulação padrão ou personalizável de parâmetros inválidos.

## <a name="syntax"></a>Sintaxe

```C
extern "C" void __cdecl
_invalid_parameter(
    wchar_t const* const expression,
    wchar_t const* const function_name,
    wchar_t const* const file_name,
    unsigned int   const line_number,
    uintptr_t      const reserved);

extern "C" void __cdecl
_invalid_parameter_noinfo(void);

extern "C" __declspec(noreturn) void __cdecl
_invalid_parameter_noinfo_noreturn(void);

extern "C" __declspec(noreturn) void __cdecl
_invoke_watson(
    wchar_t const* const expression,
    wchar_t const* const function_name,
    wchar_t const* const file_name,
    unsigned int   const line_number,
    uintptr_t      const reserved);
```

## <a name="parameters"></a>Parâmetros

*expressão*<br/>
Uma cadeia de caracteres que representa a expressão do parâmetro de código-fonte que não é válida.

*Function_name*<br/>
O nome da função que chamou o manipulador.

*Nome_do_arquivo*<br/>
O arquivo de código-fonte em que o manipulador foi chamado.

*line_number*<br/>
O número de linha no código-fonte em que o manipulador foi chamado.

*Reservados*<br/>
Não utilizado.

## <a name="return-value"></a>Valor retornado

Essas funções não retornam um valor. As funções **_invalid_parameter_noinfo_noreturn** e **_invoke_watson** não retornam ao chamador e, em alguns casos, **_invalid_parameter** e **_invalid_parameter_noinfo** não podem retornar ao chamador.

## <a name="remarks"></a>Comentários

Quando funções da biblioteca de runtime do C recebem parâmetros inválidos, as funções da biblioteca chamam um *manipulador de parâmetro inválido*, que é uma função que pode ser especificada pelo programador para realizar várias ações. Por exemplo, ela pode informar o problema para o usuário, gravar em um log, interrompê-lo em um depurador, encerrar o programa ou não fazer nada. Se nenhuma função for especificada pelo programador, um manipulador padrão, **_invoke_watson**, será chamado.

Por padrão, quando um parâmetro não válido é identificado no código de depuração, as funções da biblioteca CRT chamam a função **_invalid_parameter** usando parâmetros verbos. No código não depurado, a função **_invalid_parameter_noinfo** é chamada, que chama a função **_invalid_parameter** usando parâmetros vazios. Se a função de biblioteca CRT não depurar exigir o término do programa, a função **_invalid_parameter_noinfo_noreturn** é chamada, que chama a função **_invalid_parameter** usando parâmetros vazios, seguida de uma chamada para a função **_invoke_watson** para forçar o término do programa.

A função **_invalid_parameter** verifica se um manipulador de parâmetros inválidos definido pelo usuário foi definido e, se for o caso, o chama. Por exemplo, se um manipulador local do thread definido pelo usuário tiver sido definido por uma chamada para [set_thread_local_invalid_parameter_handler](set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md) no thread atual, ele será chamado e a função será retornada. Caso contrário, se um manipulador de parâmetro inválido global definido pelo usuário tiver sido definido por uma chamada para [set_invalid_parameter_handler](set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md), ele será chamado e a função será retornada. Caso contrário, o manipulador padrão **_invoke_watson** é chamado. O comportamento padrão do **_invoke_watson** é encerrar o programa. Manipuladores definidos pelo usuário podem ser encerrados ou retornados. Recomendamos que manipuladores definidos pelo usuário finalizem o programa, a menos que a recuperação seja certa.

Quando o **manipulador** padrão _invoke_watson é chamado, se o processador suportar uma operação [__fastfail,](../../intrinsics/fastfail.md) ele é invocado usando um parâmetro de **FAST_FAIL_INVALID_ARG** e o processo termina. Caso contrário, uma exceção de falha rápida será gerada, o que pode ser capturado por um depurador anexado. Se o processo for permitido continuar, ele será encerrado por uma chamada para a função Windows **TerminateProcess** usando um status de código de exceção de **STATUS_INVALID_CRUNTIME_PARAMETER**.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|------------------|
|**_invalid_parameter** **_invalid_parameter_noinfo**, **_invalid_parameter_noinfo_noreturn** **_invoke_watson**|\<corecrt.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[_get_invalid_parameter_handler, _get_thread_local_invalid_parameter_handler](get-invalid-parameter-handler-get-thread-local-invalid-parameter-handler.md)<br/>
[_set_invalid_parameter_handler, _set_thread_local_invalid_parameter_handler](set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md)<br/>
[Validação de Parâmetro](../../c-runtime-library/parameter-validation.md)<br/>
