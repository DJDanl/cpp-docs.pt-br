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
- api-ms-win-crt-private-l1-1-0.dll
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
ms.openlocfilehash: 7138e9cb7381e4d40911054e1473536b6e639e2d
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82919828"
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

*function_name*<br/>
O nome da função que chamou o manipulador.

*file_name*<br/>
O arquivo de código-fonte em que o manipulador foi chamado.

*line_number*<br/>
O número de linha no código-fonte em que o manipulador foi chamado.

*reservado*<br/>
Não utilizado.

## <a name="return-value"></a>Valor retornado

Essas funções não retornam um valor. As funções **_invalid_parameter_noinfo_noreturn** e **_invoke_watson** não retornam ao chamador e, em alguns casos, **_invalid_parameter** e **_invalid_parameter_noinfo** podem não retornar ao chamador.

## <a name="remarks"></a>Comentários

Quando funções da biblioteca de runtime do C recebem parâmetros inválidos, as funções da biblioteca chamam um *manipulador de parâmetro inválido*, que é uma função que pode ser especificada pelo programador para realizar várias ações. Por exemplo, ela pode informar o problema para o usuário, gravar em um log, interrompê-lo em um depurador, encerrar o programa ou não fazer nada. Se nenhuma função for especificada pelo programador, um manipulador padrão, **_invoke_watson**, será chamado.

Por padrão, quando um parâmetro não válido é identificado no código de depuração, as funções de biblioteca CRT chamam a função **_invalid_parameter** usando parâmetros detalhados. No código não-depurado, a função **_invalid_parameter_noinfo** é chamada, que chama a função **_invalid_parameter** usando parâmetros vazios. Se a função de biblioteca CRT sem depuração exigir terminação de programa, a função **_invalid_parameter_noinfo_noreturn** será chamada, que chama a função **_invalid_parameter** usando parâmetros vazios, seguida por uma chamada para a função **_invoke_watson** para forçar o encerramento do programa.

A função **_invalid_parameter** verifica se um manipulador de parâmetro inválido definido pelo usuário foi definido e, nesse caso, o chama. Por exemplo, se um manipulador local do thread definido pelo usuário tiver sido definido por uma chamada para [set_thread_local_invalid_parameter_handler](set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md) no thread atual, ele será chamado e a função será retornada. Caso contrário, se um manipulador de parâmetro inválido global definido pelo usuário tiver sido definido por uma chamada para [set_invalid_parameter_handler](set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md), ele será chamado e a função será retornada. Caso contrário, o manipulador padrão **_invoke_watson** será chamado. O comportamento padrão de **_invoke_watson** é encerrar o programa. Manipuladores definidos pelo usuário podem ser encerrados ou retornados. Recomendamos que manipuladores definidos pelo usuário finalizem o programa, a menos que a recuperação seja certa.

Quando o manipulador padrão **_invoke_watson** for chamado, se o processador der suporte a uma operação [__fastfail](../../intrinsics/fastfail.md) , ele será invocado usando um parâmetro de **FAST_FAIL_INVALID_ARG** e o processo é encerrado. Caso contrário, uma exceção de falha rápida será gerada, o que pode ser capturado por um depurador anexado. Se o processo tiver permissão para continuar, ele será encerrado por uma chamada para a função **TerminateProcess** do Windows usando um status de código de exceção de **STATUS_INVALID_CRUNTIME_PARAMETER**.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|------------------|
|**_invalid_parameter**, **_invalid_parameter_noinfo**, **_invalid_parameter_noinfo_noreturn** **_invoke_watson**|\<corecrt.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[_get_invalid_parameter_handler, _get_thread_local_invalid_parameter_handler](get-invalid-parameter-handler-get-thread-local-invalid-parameter-handler.md)<br/>
[_set_invalid_parameter_handler, _set_thread_local_invalid_parameter_handler](set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md)<br/>
[Validação de parâmetro](../../c-runtime-library/parameter-validation.md)<br/>
