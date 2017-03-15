---
title: _invalid_parameter, _invalid_parameter_noinfo, _invalid_parameter_noinfo_noreturn, _invoke_watson | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
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
caps.latest.revision: 4
author: corob-msft
ms.author: corob
manager: ghogen
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 49ae87567cd311e271a0ab50d7112a4a8f0c1b4a
ms.lasthandoff: 02/25/2017

---
# <a name="invalidparameter-invalidparameternoinfo-invalidparameternoinfonoreturn-invokewatson"></a>_invalid_parameter, _invalid_parameter_noinfo, _invalid_parameter_noinfo_noreturn, _invoke_watson
Essas funções são usadas pela Biblioteca em Tempo de Execução do C para lidar com parâmetros inválidos passados para funções da biblioteca do CRT. Seu código também pode usar essas funções para dar suporte à manipulação padrão ou personalizável de parâmetros inválidos.

## <a name="syntax"></a>Sintaxe
```
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

## <a name="return-value"></a>Valor de retorno
Essas funções não retornam um valor. As funções `_invalid_parameter_noinfo_noreturn` e `_invoke_watson` não são retornadas ao chamador e, em alguns casos, `_invalid_parameter` e `_invalid_parameter_noinfo` podem não ser retornadas ao chamador.

## <a name="parameters"></a>Parâmetros
`expression`  
Uma cadeia de caracteres que representa a expressão do parâmetro de código-fonte que não é válida.

`function_name`  
O nome da função que chamou o manipulador.

`file_name`  
O arquivo de código-fonte em que o manipulador foi chamado.

`line_number`  
O número de linha no código-fonte em que o manipulador foi chamado.

`reserved`  
Não utilizado.

## <a name="remarks"></a>Comentários
Quando funções da biblioteca em tempo de execução do C recebem parâmetros inválidos, as funções da biblioteca chamam um *manipulador de parâmetro inválido*, que é uma função que pode ser especificada pelo programador para realizar várias ações. Por exemplo, ela pode informar o problema para o usuário, gravar em um log, interrompê-lo em um depurador, encerrar o programa ou não fazer nada. Se nenhuma função for especificada pelo programador, um manipulador padrão, `_invoke_watson`, será chamado.

Por padrão, quando um parâmetro inválido é identificado no código de depuração, funções da biblioteca do CRT chamam a função `_invalid_parameter` usando parâmetros detalhados. No código sem depuração, a função `_invalid_parameter_noinfo` é chamada, o que chama a função `_invalid_parameter` usando parâmetros vazios. Se a função da biblioteca do CRT sem depuração exigir o encerramento do programa, a função `_invalid_parameter_noinfo_noreturn` será chamada, o que chama a função `_invalid_parameter` usando parâmetros vazios, seguidos por uma chamada para a função `_invoke_watson` para forçar o encerramento do programa.

A função `_invalid_parameter` verifica se um manipulador de parâmetro inválido definido pelo usuário foi definido e, nesse caso, o chama. Por exemplo, se um manipulador local do thread definido pelo usuário tiver sido definido por uma chamada para [set_thread_local_invalid_parameter_handler](../../c-runtime-library/reference/set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md) no thread atual, ele será chamado e a função será retornada. Caso contrário, se um manipulador de parâmetro inválido global definido pelo usuário tiver sido definido por uma chamada para [set_invalid_parameter_handler](../../c-runtime-library/reference/set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md), ele será chamado e a função será retornada. Caso contrário, o manipulador padrão `_invoke_watson` será chamado. O comportamento padrão de `_invoke_watson` é encerrar o programa. Manipuladores definidos pelo usuário podem ser encerrados ou retornados. Recomendamos que manipuladores definidos pelo usuário finalizem o programa, a menos que a recuperação seja certa. 

Quando o manipulador padrão `_invoke_watson` for chamado, se o processador der suporte a uma operação [__fastfail](../../intrinsics/fastfail.md), ele será invocado usando um parâmetro de `FAST_FAIL_INVALID_ARG` e o processo será encerrado. Caso contrário, uma exceção de falha rápida será gerada, o que pode ser capturado por um depurador anexado. Se o processo puder continuar, ele será encerrado por uma chamada para a função `TerminateProcess` do Windows usando um status de código de exceção de `STATUS_INVALID_CRUNTIME_PARAMETER`. 

## <a name="requirements"></a>Requisitos  
|Função|Cabeçalho necessário|  
|--------------|------------------|  
|`_invalid_parameter`, `_invalid_parameter_noinfo`, `_invalid_parameter_noinfo_noreturn`, `_invoke_watson`|\<corecrt.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência da Função Alfabética](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)   
 [_get_invalid_parameter_handler, _get_thread_local_invalid_parameter_handler](../../c-runtime-library/reference/get-invalid-parameter-handler-get-thread-local-invalid-parameter-handler.md)  
 [_set_invalid_parameter_handler, _set_thread_local_invalid_parameter_handler](../../c-runtime-library/reference/set-invalid-parameter-handler-set-thread-local-invalid-parameter-handler.md)  
 [Validação de parâmetro](../../c-runtime-library/parameter-validation.md)

