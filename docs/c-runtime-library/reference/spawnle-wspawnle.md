---
title: _spawnle, _wspawnle | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
apiname:
- _spawnle
- _wspawnle
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
- spawnle
- _spawnle
- wspawnle
- _wspawnle
dev_langs:
- C++
helpviewer_keywords:
- spawnle function
- processes, creating
- _wspawnle function
- processes, executing new
- process creation
- wspawnle function
- _spawnle function
ms.assetid: 80308892-2815-49b1-8cca-53894c366f5a
caps.latest.revision: 17
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 465fe8533698681f131cd5783b8f20d9f39d2203
ms.sourcegitcommit: ef859ddf5afea903711e36bfd89a72389a12a8d6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/20/2018
---
# <a name="spawnle-wspawnle"></a>_spawnle, _wspawnle

Cria e executa um novo processo.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
intptr_t _spawnle(
   int mode,
   const char *cmdname,
   const char *arg0,
   const char *arg1,
   ... const char *argn,
   NULL,
   const char *const *envp
);
intptr_t _wspawnle(
   int mode,
   const wchar_t *cmdname,
   const wchar_t *arg0,
   const wchar_t *arg1,
   ... const wchar_t *argn,
   NULL,
   const wchar_t *const *envp
);
```

### <a name="parameters"></a>Parâmetros

*modo*<br/>
Modo de execução do processo de chamada.

*cmdname*<br/>
Caminho do arquivo a ser executado.

*arg0*, *arg1*,... *argn*<br/>
Lista de ponteiros para os argumentos. O *arg0* argumento geralmente é um ponteiro para *cmdname*. Os argumentos *arg1* por meio de *argn* são ponteiros para as cadeias de caracteres que formam a nova lista de argumentos. A seguir *argn*, deve haver uma **nulo** ponteiro para marcar o fim da lista de argumentos.

*envp*<br/>
Matriz de ponteiros para as configurações de ambiente.

## <a name="return-value"></a>Valor de retorno

O valor de retorno de um síncrono **spawnle** ou **wspawnle** (**p_wait** especificado para *modo*) é o status de saída do processo de novo . O valor de retorno de assíncrona **spawnle** ou **wspawnle** (**p_nowait** ou **p_nowaito** especificado para  *modo*) é o identificador de processo. O status de saída é 0 se o processo foi encerrado normalmente. Você pode definir o status de saída para um valor diferente de zero se o processo gerado especificamente chama o **sair** rotina com um argumento diferente de zero. Se o novo processo não definir explicitamente um status de saída positivo, um status de saída positivo indicará uma saída anormal com uma anulação ou uma interrupção. Um valor de retorno de -1 indica um erro (o novo processo não é iniciado). Nesse caso, **errno** é definido como um dos valores a seguir.

|||
|-|-|
**E2BIG**|A lista de argumentos ultrapassa 1.024 bytes.
**EINVAL**|*modo* argumento é inválido.
**ENOENT**|Arquivo ou caminho não encontrado.
**ENOEXEC**|O arquivo especificado não é executável ou tem um formato de arquivo executável inválido.
**ENOMEM**|Não há memória suficiente disponível para executar o novo processo.

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Cada uma dessas funções cria e executa um novo processo, passando cada argumento de linha de comando como um parâmetro separado e também passando uma matriz de ponteiros para as configurações de ambiente.

Essas funções validam seus parâmetros. Se qualquer um dos *cmdname* ou *arg0* é uma cadeia de caracteres vazia ou um ponteiro nulo, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, essas funções definido **errno** para **EINVAL**e retorna -1. Nenhum processo novo é gerado.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_spawnle**|\<process.h>|
|**_wspawnle**|\<stdio.h> ou \<wchar.h>|

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
