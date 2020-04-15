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
- api-ms-win-crt-private-l1-1-0
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
ms.openlocfilehash: ee6d6155c06bb174a6ffd1e29cda0d73cbd2da32
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81355751"
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

*Modo*<br/>
Modo de execução para chamar o processo.

*Cmdname*<br/>
Caminho do arquivo a ser executado.

*Argv*<br/>
Matriz de ponteiros para os argumentos. O argumento *argv*[0] é geralmente um ponteiro para um caminho no modo real ou para o nome do programa no modo protegido, e *argv*[1] através *de argv*[**n**] são ponteiros para as strings de caractereque formam a nova lista de argumentos. O argumento *argv*[**n** +1] deve ser um ponteiro **NULL** para marcar o fim da lista de argumentos.

## <a name="return-value"></a>Valor retornado

O valor de retorno de um **_spawnvp** síncrono ou **_wspawnvp** (**_P_WAIT** especificado para o *modo*) é o status de saída do novo processo. O valor de retorno de um **_spawnvp** assíncrono ou **_wspawnvp** **(_P_NOWAIT** ou **_P_NOWAITO** especificado para o *modo*) é a alça do processo. O status de saída é 0 se o processo foi encerrado normalmente. Você pode definir o status de saída como um valor não zero se o processo desovado usar especificamente um argumento não zero para chamar a rotina **de saída.** Se o novo processo não definir explicitamente um status de saída positivo, um status de saída positivo indicará uma saída anormal com uma anulação ou uma interrupção. Um valor de retorno de -1 indica um erro (o novo processo não é iniciado). Neste caso, **errno** é definido como um dos seguintes valores:

|||
|-|-|
| **E2BIG** | A lista de argumentos ultrapassa 1.024 bytes. |
| **Einval** | *o* argumento do modo é inválido. |
| **Enoent** | Arquivo ou caminho não encontrado. |
| **ENOEXEC** | O arquivo especificado não é executável ou tem um formato de arquivo executável inválido. |
| **Enomem** | Não há memória suficiente disponível para executar o novo processo. |

Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Cada uma dessas funções cria um novo processo e executa-o, e passa uma matriz de ponteiros para argumentos de linha de comando e usa a variável de ambiente **PATH** para encontrar o arquivo para executar.

Essas funções validam seus parâmetros. Se *cmdname* ou *argv* for um ponteiro nulo, ou se *argv* apontar para ponteiro nulo, ou *argv*[0] for uma seqüência vazia, o manipulador de parâmetros inválido é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, essas funções definem **errno** para **EINVAL**e retornam -1. Nenhum processo novo é gerado.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_spawnvp**|\<stdio.h> ou \<process.h>|
|**_wspawnvp**|\<stdio.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo em [Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md).

## <a name="see-also"></a>Confira também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
[Abortar](abort.md)<br/>
[atexit](atexit.md)<br/>
[Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[_flushall](flushall.md)<br/>
[_getmbcp](getmbcp.md)<br/>
[_onexit, _onexit_m](onexit-onexit-m.md)<br/>
[_setmbcp](setmbcp.md)<br/>
[system, _wsystem](system-wsystem.md)<br/>
