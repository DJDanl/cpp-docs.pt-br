---
title: _spawnvp, _wspawnvp
ms.date: 4/2/2020
api_name:
- _wspawnvp
- _spawnvp
- _o__spawnvp
- _o__wspawnvp
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
- api-ms-win-crt-process-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _wspawnvp
- _spawnvp
- wspawnvp
helpviewer_keywords:
- wspawnvp function
- processes, creating
- _wspawnvp function
- processes, executing new
- spawnvp function
- process creation
- _spawnvp function
ms.assetid: 8d8774ec-6ad4-4680-a5aa-440cde1e0249
ms.openlocfilehash: 3ed6b780fb06db9e5951a943f52a556ad0f0748e
ms.sourcegitcommit: 5a069c7360f75b7c1cf9d4550446ec2fa2eb2293
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2020
ms.locfileid: "82916117"
---
# <a name="_spawnvp-_wspawnvp"></a>_spawnvp, _wspawnvp

Cria e executa um processo.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
intptr_t _spawnvp(
   int mode,
   const char *cmdname,
   const char *const *argv
);
intptr_t _wspawnvp(
   int mode,
   const wchar_t *cmdname,
   const wchar_t *const *argv
);
```

### <a name="parameters"></a>Parâmetros

*mode*<br/>
Modo de execução para chamar o processo.

*cmdname*<br/>
Caminho do arquivo a ser executado.

*argv*<br/>
Matriz de ponteiros para os argumentos. O argumento *argv*[0] geralmente é um ponteiro para um caminho em modo real ou para o nome do programa no modo protegido e *argv*[1] a *argv*[**n**] são ponteiros para as cadeias de caracteres que formam a nova lista de argumentos. O argumento *argv*[**n** + 1] deve ser um ponteiro **nulo** para marcar o final da lista de argumentos.

## <a name="return-value"></a>Valor retornado

O valor de retorno de um **_spawnvp** síncrono ou **_wspawnvp** (**_P_WAIT** especificado para o *modo*) é o status de saída do novo processo. O valor de retorno de um **_spawnvp** assíncrono ou **_wspawnvp** (**_P_NOWAIT** ou **_P_NOWAITO** especificado para o *modo*) é o identificador de processo. O status de saída é 0 se o processo foi encerrado normalmente. Você pode definir o status de saída como um valor diferente de zero se o processo gerado usa especificamente um argumento diferente de zero para chamar a rotina de **saída** . Se o novo processo não definir explicitamente um status de saída positivo, um status de saída positivo indicará uma saída anormal com uma anulação ou uma interrupção. Um valor de retorno de-1 indica um erro (o novo processo não é iniciado). Nesse caso, **errno** é definido como um dos seguintes valores:

|||
|-|-|
| **E2BIG** | A lista de argumentos ultrapassa 1.024 bytes. |
| **EINVAL** | argumento de *modo* inválido. |
| **ENOENT** | Arquivo ou caminho não encontrado. |
| **ENOEXEC** | O arquivo especificado não é executável ou tem um formato de arquivo executável inválido. |
| **ENOMEM** | Não há memória suficiente disponível para executar o novo processo. |

Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Cada uma dessas funções cria um novo processo e a executa, e passa uma matriz de ponteiros para argumentos de linha de comando e usa a variável de ambiente **path** para localizar o arquivo a ser executado.

Essas funções validam seus parâmetros. Se *cmdname* ou *argv* for um ponteiro NULL ou se *argv* apontar para um ponteiro NULL ou *argv*[0] for uma cadeia de caracteres vazia, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções definem **errno** como **EINVAL**e retornam-1. Nenhum processo novo é gerado.

Por padrão, o estado global dessa função tem como escopo o aplicativo. Para alterar isso, consulte [estado global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_spawnvp**|\<stdio.h> ou \<process.h>|
|**_wspawnvp**|\<stdio.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo em [Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md).

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
[anular](abort.md)<br/>
[atexit](atexit.md)<br/>
[Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[_flushall](flushall.md)<br/>
[_getmbcp](getmbcp.md)<br/>
[_onexit, _onexit_m](onexit-onexit-m.md)<br/>
[_setmbcp](setmbcp.md)<br/>
[system, _wsystem](system-wsystem.md)<br/>
