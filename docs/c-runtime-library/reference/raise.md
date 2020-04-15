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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: b38a3430274b2324e345be30ce9e38f0c2749fa3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81338257"
---
# <a name="raise"></a>raise

Envia um sinal para o programa em execução.

> [!NOTE]
> Não use esse método para desligar um aplicativo da Microsoft Store, exceto em cenários de teste ou depuração. Formas programáticas ou de uI para fechar um aplicativo da Loja não são permitidas de acordo com as políticas da [Microsoft Store](/legal/windows/agreements/store-policies). Para obter mais informações, consulte [o ciclo de vida do aplicativo UWP](/windows/uwp/launch-resume/app-lifecycle).

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

Se o argumento não for um sinal válido conforme especificado acima, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se não for tratada, a função define **errno** para **EINVAL** e retorna um valor não zero.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**raise**|\<signal.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Confira também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[Abortar](abort.md)<br/>
[Sinal](signal.md)<br/>
