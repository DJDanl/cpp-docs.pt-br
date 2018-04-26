---
title: _spawnv, _wspawnv | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _wspawnv
- _spawnv
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
- wspawnv
- _spawnv
- _wspawnv
dev_langs:
- C++
helpviewer_keywords:
- wspawnv function
- processes, creating
- _spawnv function
- processes, executing new
- process creation
- _wspawnv function
- spawnv function
ms.assetid: 72360ef4-dfa9-44c1-88c1-b3ecb660aa7d
caps.latest.revision: 17
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 30e55677395f528b15de90ba2045bb7e0785ca9a
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="spawnv-wspawnv"></a>_spawnv, _wspawnv

Cria e executa um novo processo.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
intptr_t _spawnv(
   int mode,
   const char *cmdname,
   const char *const *argv
);
intptr_t _wspawnv(
   int mode,
   const wchar_t *cmdname,
   const wchar_t *const *argv
);
```

### <a name="parameters"></a>Parâmetros

*modo*<br/>
Modo de execução do processo de chamada.

*cmdname*<br/>
Caminho do arquivo a ser executado.

*argv*<br/>
Matriz de ponteiros para os argumentos. O argumento *argv*[0] é geralmente um ponteiro para um caminho em modo real ou o nome do programa no modo protegido, e *argv*[1] por meio de *argv*[**n**] são ponteiros para as cadeias de caracteres que formam a nova lista de argumentos. O argumento *argv*[**n** + 1] deve ser um **nulo** ponteiro para marcar o fim da lista de argumentos.

## <a name="return-value"></a>Valor de retorno

O valor de retorno de um síncrono **spawnv** ou **wspawnv** (**p_wait** especificado para *modo*) é o status de saída do processo de novo. O valor de retorno de assíncrona **spawnv** ou **wspawnv** (**p_nowait** ou **p_nowaito** especificado para *modo* ) é o identificador de processo. O status de saída é 0 se o processo foi encerrado normalmente. Você pode definir o status de saída para um valor diferente de zero se o processo gerado especificamente chama o **sair** rotina com um argumento diferente de zero. Se o novo processo não definir explicitamente um status de saída positivo, um status de saída positivo indicará uma saída anormal com uma anulação ou uma interrupção. Um valor de retorno de -1 indica um erro (o novo processo não é iniciado). Nesse caso, **errno** é definido como um dos valores a seguir.

|||
|-|-|
**E2BIG**|A lista de argumentos ultrapassa 1.024 bytes.
**EINVAL**|*modo* argumento é inválido.
**ENOENT**|Arquivo ou caminho não encontrado.
**ENOEXEC**|O arquivo especificado não é executável ou tem um formato de arquivo executável inválido.
**ENOMEM**|Não há memória suficiente disponível para executar o novo processo.

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Cada uma dessas funções cria e executa um novo processo, passando uma matriz de ponteiros para argumentos de linha de comando.

Essas funções validam seus parâmetros. Se qualquer um dos *cmdname* ou *argv* é um ponteiro nulo, ou se *argv* aponta para um ponteiro nulo, ou *argv*[0] é uma cadeia de caracteres vazia, inválido manipulador de parâmetro é chamado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções definido **errno** para **EINVAL**e retorna -1. Nenhum processo novo é gerado.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_spawnv**|\<stdio.h> ou \<process.h>|
|**_wspawnv**|\<stdio.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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
