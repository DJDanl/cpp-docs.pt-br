---
title: _spawnve, _wspawnve
ms.date: 11/04/2016
api_name:
- _spawnve
- _wspawnve
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
ms.openlocfilehash: 37f8b6737fbd2b36c1482790a34dc386936b704b
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79442705"
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

*modo*<br/>
Modo de execução de um processo de chamada.

*cmdname*<br/>
Caminho do arquivo a ser executado.

*argv*<br/>
Matriz de ponteiros para os argumentos. O argumento *argv*[0] geralmente é um ponteiro para um caminho em modo real ou para o nome do programa no modo protegido, e *argv*[1] a *argv*[**n**] são ponteiros para as cadeias de caracteres que formam a nova lista de argumentos. O argumento *argv*[**n** + 1] deve ser um ponteiro **nulo** para marcar o final da lista de argumentos.

*envp*<br/>
Matriz de ponteiros para as configurações de ambiente.

## <a name="return-value"></a>Valor retornado

O valor de retorno de um **_spawnve** síncrono ou **_wspawnve** ( **_P_WAIT** especificado para o *modo*) é o status de saída do novo processo. O valor de retorno de um **_spawnve** assíncrono ou **_wspawnve** ( **_P_NOWAIT** ou **_P_NOWAITO** especificado para o *modo*) é o identificador de processo. O status de saída é 0 se o processo foi encerrado normalmente. Você pode definir o status de saída como um valor diferente de zero se o processo gerado chamar especificamente a rotina de **saída** com um argumento diferente de zero. Se o novo processo não definir explicitamente um status de saída positivo, um status de saída positivo indicará uma saída anormal com uma anulação ou uma interrupção. Um valor de retorno de-1 indica um erro (o novo processo não é iniciado). Nesse caso, **errno** é definido como um dos valores a seguir.

|||
|-|-|
| **E2BIG** | A lista de argumentos ultrapassa 1.024 bytes. |
| **EINVAL** | argumento de *modo* inválido. |
| **ENOENT** | Arquivo ou caminho não encontrado. |
| **ENOEXEC** | O arquivo especificado não é executável ou tem um formato de arquivo executável inválido. |
| **ENOMEM** | Não há memória suficiente disponível para executar o novo processo. |

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Cada uma dessas funções cria e executa um novo processo, passando uma matriz de ponteiros para argumentos de linha de comando e uma matriz de ponteiros para as configurações de ambiente.

Essas funções validam seus parâmetros. Se *cmdname* ou *argv* for um ponteiro NULL ou se *argv* apontar para um ponteiro NULL ou *argv*[0] for uma cadeia de caracteres vazia, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções definem **errno** como **EINVAL**e retornam-1. Nenhum processo novo é gerado.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_spawnve**|\<stdio.h> ou \<process.h>|
|**_wspawnve**|\<stdio.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

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
