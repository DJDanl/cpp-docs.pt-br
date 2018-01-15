---
title: raise | Microsoft Docs
ms.custom: 
ms.date: 1/02/2018
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: raise
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
f1_keywords: Raise
dev_langs: C++
helpviewer_keywords:
- signals, sending to executing programs
- raise function
- signals
- programs [C++], sending signals to executing programs
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 1b7ec6c886c96bae93f511e54119500d58d6fea5
ms.sourcegitcommit: a5d8f5b92cb5e984d5d6c9d67fe8a1241f3fe184
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/05/2018
---
# <a name="raise"></a>raise

Envia um sinal para o programa em execução.

> [!NOTE]
> Não use esse método para desligar um aplicativo da Microsoft Store, exceto em teste ou cenários de depuração. Modos de interface do usuário ou por programação para fechar um aplicativo de repositório não são permitidos de acordo com o [políticas do Microsoft Store](http://go.microsoft.com/fwlink/?LinkId=865936). Para obter mais informações, consulte [ciclo de vida do aplicativo UWP](http://go.microsoft.com/fwlink/p/?LinkId=865934).

## <a name="syntax"></a>Sintaxe

```C
int raise(
   int sig
);
```

### <a name="parameters"></a>Parâmetros

*sig*  
Sinal a ser gerado.

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, **raise** retornará 0. Caso contrário, retornará um valor diferente de zero.

## <a name="remarks"></a>Comentários

A função **raise** envia *sig* para o programa em execução. Se uma chamada anterior a **signal** tiver instalado uma função de manipulação de sinal para *sig*, **raise** executará essa função. Se nenhuma função de manipulador tiver sido instalada, a ação padrão associada com o valor de sinal *sig* será obtida da seguinte maneira.

|Sinal|Significado|Padrão|
|------------|-------------|-------------|
|`SIGABRT`|Encerramento anormal|Termina o programa de chamada com código de saída 3|
|`SIGFPE`|Erro de ponto flutuante|Encerra o programa de chamada|
|`SIGILL`|Instrução ilegal|Encerra o programa de chamada|
|`SIGINT`|Interrupção CTRL+C|Encerra o programa de chamada|
|`SIGSEGV`|Acesso ao armazenamento inválido|Encerra o programa de chamada|
|`SIGTERM`|Solicitação de término enviado para o programa|Ignora o sinal|

Se o argumento não for um sinal válido conforme especificado acima, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se o erro não for tratado, a função define `errno` como `EINVAL` e retorna um valor diferente de zero.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**raise**|\<signal.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)  
[abort](../../c-runtime-library/reference/abort.md)  
[signal](../../c-runtime-library/reference/signal.md)  
