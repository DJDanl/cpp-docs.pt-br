---
title: raise
ms.date: 4/2/2020
api_name:
- raise
- _o_raise
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
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- Raise
helpviewer_keywords:
- signals, sending to executing programs
- raise function
- signals
- programs [C++], sending signals to executing programs
ms.openlocfilehash: 81b92404603820948a384b6ad33421251a27c13c
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82919556"
---
# <a name="raise"></a>raise

Envia um sinal para o programa em execução.

> [!NOTE]
> Não use esse método para desligar um aplicativo Microsoft Store, exceto em cenários de teste ou depuração. As maneiras programática ou de interface do usuário de fechar um aplicativo da loja não são permitidas de acordo com as [políticas de Microsoft Store](/legal/windows/agreements/store-policies). Para obter mais informações, consulte [ciclo de vida do aplicativo UWP](/windows/uwp/launch-resume/app-lifecycle).

## <a name="syntax"></a>Sintaxe

```C
int raise(
   int sig
);
```

### <a name="parameters"></a>Parâmetros

*sig*<br/>
Sinal a ser gerado.

## <a name="return-value"></a>Valor retornado

Se for bem-sucedido, **raise** retornará 0. Caso contrário, retornará um valor diferente de zero.

## <a name="remarks"></a>Comentários

A função **raise** envia *sig* para o programa em execução. Se uma chamada anterior a **signal** tiver instalado uma função de manipulação de sinal para *sig*, **raise** executará essa função. Se nenhuma função de manipulador tiver sido instalada, a ação padrão associada com o valor de sinal *sig* será obtida da seguinte maneira.

|Sinal|Significado|Padrão|
|------------|-------------|-------------|
|**SIGABRT**|Encerramento anormal|Termina o programa de chamada com código de saída 3|
|**SIGFPE**|Erro de ponto flutuante|Encerra o programa de chamada|
|**SIGILL**|Instrução ilegal|Encerra o programa de chamada|
|**SIGINT**|Interrupção CTRL+C|Encerra o programa de chamada|
|**SIGSEGV**|Acesso ao armazenamento inválido|Encerra o programa de chamada|
|**SIGTERM**|Solicitação de término enviado para o programa|Ignora o sinal|

Se o argumento não for um sinal válido conforme especificado acima, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se não for tratado, a função definirá **errno** como **EINVAL** e retornará um valor diferente de zero.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**raise**|\<signal.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[anular](abort.md)<br/>
[signal](signal.md)<br/>
