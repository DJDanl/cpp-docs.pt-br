---
title: _spawnve, _wspawnve
ms.date: 4/2/2020
api_name:
- _spawnve
- _wspawnve
- _o__spawnve
- _o__wspawnve
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
- wspawnve
- _spawnve
- _wspawnve
helpviewer_keywords:
- _spawnve function
- spawnve function
- wspawnve function
- processes, creating
- _wspawnve function
- processes, executing new
- process creation
ms.assetid: 26d1713d-b551-4f21-a07b-e9891a2ae6cf
ms.openlocfilehash: 0f546185039bb1503af40d5f690fd8d8c172a679
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81355869"
---
# <a name="_spawnve-_wspawnve"></a>_spawnve, _wspawnve

Cria e executa um novo processo.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
intptr_t _spawnve(
   int mode,
   const char *cmdname,
   const char *const *argv,
   const char *const *envp
);
intptr_t _wspawnve(
   int mode,
   const wchar_t *cmdname,
   const wchar_t *const *argv,
   const wchar_t *const *envp
);
```

### <a name="parameters"></a>Parâmetros

*Modo*<br/>
Modo de execução de um processo de chamada.

*Cmdname*<br/>
Caminho do arquivo a ser executado.

*Argv*<br/>
Matriz de ponteiros para os argumentos. O argumento *argv*[0] é geralmente um ponteiro para um caminho no modo real ou para o nome do programa no modo protegido, e *argv*[1] através *de argv*[**n**] são ponteiros para as strings de caracteres formando a nova lista de argumentos. O argumento *argv*[**n** +1] deve ser um ponteiro **NULL** para marcar o fim da lista de argumentos.

*Envp*<br/>
Matriz de ponteiros para as configurações de ambiente.

## <a name="return-value"></a>Valor retornado

O valor de retorno de um **_spawnve** síncrono ou **_wspawnve** **(_P_WAIT** especificado para o *modo*) é o status de saída do novo processo. O valor de retorno de um **_spawnve** assíncrono ou **_wspawnve** **(_P_NOWAIT** ou **_P_NOWAITO** especificado para o *modo*) é a alça do processo. O status de saída é 0 se o processo foi encerrado normalmente. Você pode definir o status de saída como um valor não zero se o processo desovado chamar especificamente a rotina **de saída** com um argumento não zero. Se o novo processo não definir explicitamente um status de saída positivo, um status de saída positivo indicará uma saída anormal com uma anulação ou uma interrupção. Um valor de retorno de -1 indica um erro (o novo processo não é iniciado). Neste caso, **errno** é definido como um dos seguintes valores.

|||
|-|-|
| **E2BIG** | A lista de argumentos ultrapassa 1.024 bytes. |
| **Einval** | *o* argumento do modo é inválido. |
| **Enoent** | Arquivo ou caminho não encontrado. |
| **ENOEXEC** | O arquivo especificado não é executável ou tem um formato de arquivo executável inválido. |
| **Enomem** | Não há memória suficiente disponível para executar o novo processo. |

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Cada uma dessas funções cria e executa um novo processo, passando uma matriz de ponteiros para argumentos de linha de comando e uma matriz de ponteiros para as configurações de ambiente.

Essas funções validam seus parâmetros. Se *cmdname* ou *argv* for um ponteiro nulo, ou se *argv* apontar para ponteiro nulo, ou *argv*[0] for uma seqüência vazia, o manipulador de parâmetros inválido é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, essas funções definem **errno** para **EINVAL**e retornam -1. Nenhum processo novo é gerado.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_spawnve**|\<stdio.h> ou \<process.h>|
|**_wspawnve**|\<stdio.h> ou \<wchar.h>|

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
