---
title: _invalid_parameter, _invalid_parameter_noinfo, _invalid_parameter_noinfo_noreturn, _invoke_watson
ms.date: 11/04/2016
apiname:
- _invalid_parameter
- _invalid_parameter_noinfo
- _invalid_parameter_noinfo_noreturn
- _invoke_watson
apilocation:
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
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
ms.openlocfilehash: e43d5caaeebb6303d209d870c804357117812985
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62157533"
---
# <a name="invalidparameter-invalidparameternoinfo-invalidparameternoinfonoreturn-invokewatson"></a>_invalid_parameter, _invalid_parameter_noinfo, _invalid_parameter_noinfo_noreturn, _invoke_watson

Essas funções são usadas pela Biblioteca em Tempo de Execução do C para lidar com parâmetros inválidos passados para funções da biblioteca do CRT. Seu código também pode usar essas funções para dar suporte à manipulação padrão ou personalizável de parâmetros inválidos.

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

*Expressão*<br/>
Uma cadeia de caracteres que representa a expressão do parâmetro de código-fonte que não é válida.

*function_name*<br/>
O nome da função que chamou o manipulador.

*file_name*<br/>
O arquivo de código-fonte em que o manipulador foi chamado.

*line_number*<br/>
O número de linha no código-fonte em que o manipulador foi chamado.

*reserved*<br/>
Não utilizado.

## <a name="return-value"></a>Valor de retorno

Essas funções não retornam um valor. O **invalid_parameter_noinfo_noreturn** e **_invoke_watson** funções não retornam o chamador e, em alguns casos **invalid_parameter** e **invalid_parameter_noinfo** não pode retornar ao chamador.

## <a name="remarks"></a>Comentários

Quando funções da biblioteca em tempo de execução do C recebem parâmetros inválidos, as funções da biblioteca chamam um *manipulador de parâmetro inválido*, que é uma função que pode ser especificada pelo programador para realizar várias ações. Por exemplo, ela pode informar o problema para o usuário, gravar em um log, interrompê-lo em um depurador, encerrar o programa ou não fazer nada. Se nenhuma função for especificada pelo programador, um manipulador padrão, **_invoke_watson**, é chamado.

Por padrão, quando um parâmetro inválido é identificado no código de depuração, funções da biblioteca CRT chamam a função **invalid_parameter** usando parâmetros detalhados. No código sem depuração, o **invalid_parameter_noinfo** função é chamada, que chama o **invalid_parameter** funcionam usando parâmetros vazios. Se a função de biblioteca de CRT sem depuração exigir o encerramento do programa, o **invalid_parameter_noinfo_noreturn** função é chamada, que chama o **invalid_parameter** funcionam usando vazio parâmetros, seguido por uma chamada para o **_invoke_watson** função para forçar o encerramento do programa.

O **invalid_parameter** função verifica se um manipulador de parâmetro inválido definido pelo usuário tiver sido definido e nesse caso, chama. Por exemplo, se um manipulador local do thread definido pelo usuário tiver sido definido por uma chamada para [set_thread_local_invalid_parameter_handler](set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md) no thread atual, ele será chamado e a função será retornada. Caso contrário, se um manipulador de parâmetro inválido global definido pelo usuário tiver sido definido por uma chamada para [set_invalid_parameter_handler](set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md), ele será chamado e a função será retornada. Caso contrário, o manipulador padrão **_invoke_watson** é chamado. O comportamento padrão do **_invoke_watson** é encerrar o programa. Manipuladores definidos pelo usuário podem ser encerrados ou retornados. Recomendamos que manipuladores definidos pelo usuário finalizem o programa, a menos que a recuperação seja certa.

Quando o manipulador padrão **_invoke_watson** é chamado, se o processador der suporte a um [fastfail](../../intrinsics/fastfail.md) operação, ele é invocado usando um parâmetro de **FAST_FAIL_INVALID_ARG** e o processo é encerrado. Caso contrário, uma exceção de falha rápida será gerada, o que pode ser capturado por um depurador anexado. Se o processo puder continuar, ele será encerrado por uma chamada para o Windows **TerminateProcess** funcionam usando um status de código de exceção de **STATUS_INVALID_CRUNTIME_PARAMETER**.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|------------------|
|**_invalid_parameter**, **_invalid_parameter_noinfo**, **_invalid_parameter_noinfo_noreturn**, **_invoke_watson**|\<corecrt.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Referência da Função Alfabética](crt-alphabetical-function-reference.md)<br/>
[_get_invalid_parameter_handler, _get_thread_local_invalid_parameter_handler](get-invalid-parameter-handler-get-thread-local-invalid-parameter-handler.md)<br/>
[_set_invalid_parameter_handler, _set_thread_local_invalid_parameter_handler](set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md)<br/>
[Validação de parâmetro](../../c-runtime-library/parameter-validation.md)<br/>
