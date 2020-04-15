---
title: _spawnvpe, _wspawnvpe
ms.date: 4/2/2020
api_name:
- _spawnvpe
- _wspawnvpe
- _o__spawnvpe
- _o__wspawnvpe
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
- _spawnvpe
- wspawnvpe
- _wspawnvpe
helpviewer_keywords:
- _wspawnvpe function
- processes, creating
- _spawnvpe function
- processes, executing new
- wspawnvpe function
- process creation
- spawnvpe function
ms.assetid: 3db6394e-a955-4837-97a1-fab1db1e6092
ms.openlocfilehash: c8a97e99711a2053a26ae850c09c82a4342cda3a
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81355706"
---
# <a name="_spawnvpe-_wspawnvpe"></a>_spawnvpe, _wspawnvpe

Cria e executa um novo processo.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
intptr_t _spawnvpe(
   int mode,
   const char *cmdname,
   const char *const *argv,
   const char *const *envp
);
intptr_t _wspawnvpe(
   int mode,
   const wchar_t *cmdname,
   const wchar_t *const *argv,
   const wchar_t *const *envp
);
```

### <a name="parameters"></a>Parâmetros

*Modo*<br/>
Modo de execução do processo de chamada

*Cmdname*<br/>
Caminho do arquivo a ser executado

*Argv*<br/>
Matriz de ponteiros para os argumentos. O argumento *argv*[0] é geralmente um ponteiro para um caminho no modo real ou para o nome do programa no modo protegido, e *argv*[1] através *de argv*[**n**] são ponteiros para as strings de caracteres formando a nova lista de argumentos. O argumento *argv*[**n** +1] deve ser um ponteiro **NULL** para marcar o fim da lista de argumentos.

*Envp*<br/>
Matriz de ponteiros para as configurações de ambiente

## <a name="return-value"></a>Valor retornado

O valor de retorno de um **_spawnvpe** síncrono ou **_wspawnvpe** **(_P_WAIT** especificado para o *modo*) é o status de saída do novo processo. O valor de retorno de uma **_spawnvpe** assíncrona ou **_wspawnvpe** **(_P_NOWAIT** ou **_P_NOWAITO** especificado para o *modo*) é a alça do processo. O status de saída é 0 se o processo foi encerrado normalmente. Você pode definir o status de saída como um valor não zero se o processo desovado chamar especificamente a rotina **de saída** com um argumento não zero. Se o novo processo não definir explicitamente um status de saída positivo, um status de saída positivo indicará uma saída anormal com uma anulação ou uma interrupção. Um valor de retorno de -1 indica um erro (o novo processo não é iniciado). Neste caso, **errno** é definido como um dos seguintes valores:

|||
|-|-|
| **E2BIG** | A lista de argumentos ultrapassa 1.024 bytes. |
| **Einval** | *o* argumento do modo é inválido. |
| **Enoent** | Arquivo ou caminho não encontrado. |
| **ENOEXEC** | O arquivo especificado não é executável ou tem um formato de arquivo executável inválido. |
| **Enomem** | Não há memória suficiente disponível para executar o novo processo. |

Veja [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses, e outros, códigos de devolução.

## <a name="remarks"></a>Comentários

Cada uma dessas funções cria e executa um novo processo, passando uma matriz de ponteiros para argumentos de linha de comando e uma matriz de ponteiros para as configurações de ambiente. Essas funções usam a variável de ambiente **PATH** para encontrar o arquivo para executar.

Essas funções validam seus parâmetros. Se *cmdname* ou *argv* for um ponteiro nulo, ou se *argv* apontar para ponteiro nulo, ou *argv*[0] for uma seqüência vazia, o manipulador de parâmetros inválido é invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md) . Se a execução for permitida, essas funções definem **errno** para **EINVAL**e retornam -1. Nenhum processo novo é gerado.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_spawnvpe**|\<stdio.h> ou \<process.h>|
|**_wspawnvpe**|\<stdio.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo em [Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md).

## <a name="see-also"></a>Confira também

[Abortar](abort.md)<br/>
[atexit](atexit.md)<br/>
[Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[_flushall](flushall.md)<br/>
[_getmbcp](getmbcp.md)<br/>
[_onexit, _onexit_m](onexit-onexit-m.md)<br/>
[_setmbcp](setmbcp.md)<br/>
[system, _wsystem](system-wsystem.md)<br/>
