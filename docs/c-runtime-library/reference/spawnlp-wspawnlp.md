---
title: _spawnlp, _wspawnlp
ms.date: 11/04/2016
api_name:
- _wspawnlp
- _spawnlp
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
- _wspawnlp
- wspawnlp
- _spawnlp
helpviewer_keywords:
- wspawnlp function
- _spawnlp function
- processes, creating
- processes, executing new
- _wspawnlp function
- process creation
- spawnlp function
ms.assetid: 74fc6e7a-4f24-4103-9387-7177875875e6
ms.openlocfilehash: 68ad011af1a53452c0f3cfda02bdf80582a8431b
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88845946"
---
# <a name="_spawnlp-_wspawnlp"></a>_spawnlp, _wspawnlp

Cria e executa um novo processo.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
intptr_t _spawnlp(
   int mode,
   const char *cmdname,
   const char *arg0,
   const char *arg1,
   ... const char *argn,
   NULL
);
intptr_t _wspawnlp(
   int mode,
   const wchar_t *cmdname,
   const wchar_t *arg0,
   const wchar_t *arg1,
   ... const wchar_t *argn,
   NULL
);
```

### <a name="parameters"></a>parâmetros

*mode*<br/>
Modo de execução do processo de chamada.

*cmdname*<br/>
Caminho do arquivo a ser executado.

*arg0*, *arg1*,... *argN*<br/>
Lista de ponteiros para os argumentos. O argumento *arg0* geralmente é um ponteiro para *cmdname*. Os argumentos *arg1* a *argN* são ponteiros para as cadeias de caracteres que formam a nova lista de argumentos. Após *argN*, deve haver um ponteiro **nulo** para marcar o final da lista de argumentos.

## <a name="return-value"></a>Valor Retornado

O valor de retorno de um **_spawnlp** síncrono ou **_wspawnlp** (**_P_WAIT** especificado para o *modo*) é o status de saída do novo processo. O valor de retorno de um **_spawnlp** assíncrono ou **_wspawnlp** (**_P_NOWAIT** ou **_P_NOWAITO** especificado para o *modo*) é o identificador de processo. O status de saída é 0 se o processo foi encerrado normalmente. Você pode definir o status de saída como um valor diferente de zero se o processo gerado chamar especificamente a rotina de **saída** com um argumento diferente de zero. Se o novo processo não definir explicitamente um status de saída positivo, um status de saída positivo indicará uma saída anormal com uma anulação ou uma interrupção. Um valor de retorno de-1 indica um erro (o novo processo não é iniciado). Nesse caso, **errno** é definido como um dos valores a seguir.

| Valor | Descrição |
|-|-|
| **E2BIG** | A lista de argumentos ultrapassa 1.024 bytes. |
| **EINVAL** | argumento de *modo* inválido. |
| **ENOENT** | Arquivo ou caminho não encontrado. |
| **ENOEXEC** | O arquivo especificado não é executável ou tem um formato de arquivo executável inválido. |
| **ENOMEM** | Não há memória suficiente disponível para executar o novo processo. |

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Cada uma dessas funções cria e executa um novo processo, passando cada argumento de linha de comando como um parâmetro separado e usando a variável de ambiente **path** para localizar o arquivo a ser executado.

Essas funções validam seus parâmetros. Se *cmdname* ou *arg0* for uma cadeia de caracteres vazia ou um ponteiro NULL, essas funções gerarão uma exceção de parâmetro inválida, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, essas funções definem **errno** como **EINVAL**e retornam-1. Nenhum processo novo é gerado.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_spawnlp**|\<process.h>|
|**_wspawnlp**|\<stdio.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Veja o exemplo em [Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md).

## <a name="see-also"></a>Confira também

[Controle de processo e ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[_spawn, _wspawn funções](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
[anular](abort.md)<br/>
[atexit](atexit.md)<br/>
[_exec, _wexec funções](../../c-runtime-library/exec-wexec-functions.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[_flushall](flushall.md)<br/>
[_getmbcp](getmbcp.md)<br/>
[_onexit, _onexit_m](onexit-onexit-m.md)<br/>
[_setmbcp](setmbcp.md)<br/>
[system, _wsystem](system-wsystem.md)<br/>
