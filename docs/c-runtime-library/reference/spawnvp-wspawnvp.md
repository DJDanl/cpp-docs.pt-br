---
title: _spawnvp, _wspawnvp
ms.date: 11/04/2016
apiname:
- _wspawnvp
- _spawnvp
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
- api-ms-win-crt-process-l1-1-0.dll
apitype: DLLExport
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
ms.openlocfilehash: b697eabd7a45eedbf9c892acee570a9e8b818d1b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62355127"
---
# <a name="spawnvp-wspawnvp"></a>_spawnvp, _wspawnvp

Cria e executa um processo.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

*modo*<br/>
Modo de execução para chamar o processo.

*cmdname*<br/>
Caminho do arquivo a ser executado.

*argv*<br/>
Matriz de ponteiros para os argumentos. O argumento *argv*[0] é geralmente um ponteiro para um caminho em modo real ou o nome do programa no modo protegido, e *argv*[1] por meio do *argv*[**n**] são ponteiros para as cadeias de caracteres que formam a nova lista de argumentos. O argumento *argv*[**n** + 1] deve ser um **nulo** ponteiro para marcar o final da lista de argumentos.

## <a name="return-value"></a>Valor de retorno

O valor de retorno de um síncrono **spawnvp** ou **wspawnvp** (**p_wait** especificado para *modo*) é o status de saída do novo processo . O valor de retorno de um assíncrono **spawnvp** ou **wspawnvp** (**p_nowait** ou **p_nowaito** especificado para  *modo*) é o identificador de processo. O status de saída é 0 se o processo foi encerrado normalmente. Você pode definir o status de saída para um valor diferente de zero se o processo gerado usar especificamente um argumento diferente de zero para chamar o **sair** rotina. Se o novo processo não definir explicitamente um status de saída positivo, um status de saída positivo indicará uma saída anormal com uma anulação ou uma interrupção. Um valor de retorno de -1 indica um erro (o novo processo não é iniciado). Nesse caso, **errno** é definido como um dos seguintes valores:

|||
|-|-|
| **E2BIG** | A lista de argumentos ultrapassa 1.024 bytes. |
| **EINVAL** | *modo* argumento é inválido. |
| **ENOENT** | Arquivo ou caminho não encontrado. |
| **ENOEXEC** | O arquivo especificado não é executável ou tem um formato de arquivo executável inválido. |
| **ENOMEM** | Não há memória suficiente disponível para executar o novo processo. |

Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Cada uma dessas funções cria um novo processo e executa-o e passa uma matriz de ponteiros para argumentos de linha de comando e usa o **caminho** variável de ambiente para localizar o arquivo a ser executado.

Essas funções validam seus parâmetros. Se qualquer um dos *cmdname* ou *argv* é um ponteiro nulo, ou se *argv* aponta para um ponteiro nulo, ou *argv*[0] é uma cadeia de caracteres vazia, o inválido manipulador de parâmetro é invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão **errno** à **EINVAL**e retornarão -1. Nenhum processo novo é gerado.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_spawnvp**|\<stdio.h> ou \<process.h>|
|**_wspawnvp**|\<stdio.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo em [Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md).

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
[abort](abort.md)<br/>
[atexit](atexit.md)<br/>
[Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[_flushall](flushall.md)<br/>
[_getmbcp](getmbcp.md)<br/>
[_onexit, _onexit_m](onexit-onexit-m.md)<br/>
[_setmbcp](setmbcp.md)<br/>
[system, _wsystem](system-wsystem.md)<br/>
