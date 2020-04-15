---
title: _execvpe, _wexecvpe
ms.date: 4/2/2020
api_name:
- _execvpe
- _wexecvpe
- _o__execvpe
- _o__wexecvpe
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
- wexecvpe
- _wexecvpe
- _execvpe
helpviewer_keywords:
- wexecvpe function
- execvpe function
- _wexecvpe function
- _execvpe function
ms.assetid: c0c3c986-d9c0-4814-a96c-10f0b3092766
ms.openlocfilehash: dd2e4c91affe211cc58a2f1c147646172f3f34c4
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81347650"
---
# <a name="_execvpe-_wexecvpe"></a>_execvpe, _wexecvpe

Carrega e executa novos processos filho.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
intptr_t _execvpe(
   const char *cmdname,
   const char *const *argv,
   const char *const *envp
);
intptr_t _wexecvpe(
   const wchar_t *cmdname,
   const wchar_t *const *argv,
   const wchar_t *const *envp
);
```

### <a name="parameters"></a>Parâmetros

*Cmdname*<br/>
Caminho do arquivo a ser executado.

*Argv*<br/>
Matriz de ponteiros para os parâmetros.

*Envp*<br/>
Matriz de ponteiros para as configurações de ambiente.

## <a name="return-value"></a>Valor retornado

Se bem-sucedidas, essas funções não retornam ao processo de chamada. Um valor de retorno de -1 indica um erro, nesse caso a variável **global errno** é definida.

|**valor errno**|Descrição|
|-------------------|-----------------|
|**E2BIG**|O espaço necessário para os argumentos e as configurações de ambiente excede 32 KB.|
|**Eacces**|O arquivo especificado tem uma violação de compartilhamento ou de bloqueio.|
|**EMFILE**|Há muitos arquivos abertos. (O arquivo especificado deve ser aberto para determinar se ele é executável.)|
|**Enoent**|Arquivo ou caminho não encontrado.|
|**ENOEXEC**|O arquivo especificado não é executável ou tem um formato inválido do arquivo executável.|
|**Enomem**|Não há memória suficiente disponível para executar o novo processo. A memória disponível foi corrompida ou há um bloco inválido, indicando que o processo de chamada não foi alocado corretamente.|

Para obter mais informações sobre esses e outros códigos de devolução, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

Cada uma dessas funções carrega e executa um novo processo, passando uma matriz de ponteiros para argumentos de linha de comando e uma matriz de ponteiros para as configurações de ambiente. Essas funções usam a variável de ambiente **PATH** para encontrar o arquivo para executar.

As funções **_execvpe** validam seus parâmetros. Se o *cmdname* for um ponteiro nulo ou se *argv* for um ponteiro nulo, um ponteiro para uma matriz vazia ou um ponteiro para uma matriz que contenha uma seqüência de string vazia como primeiro argumento, essas funções invocam o manipulador de parâmetros inválidos, conforme descrito em [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, essas funções definem **errno** para **EINVAL** e retornam -1. Nenhum processo é inicializado.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|Cabeçalho opcional|
|--------------|---------------------|---------------------|
|**_execvpe**|\<process.h>|\<errno.h>|
|**_wexecvpe**|\<process.h> ou \<wchar.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Consulte o exemplo nas [ funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md).

## <a name="see-also"></a>Confira também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)<br/>
[Abortar](abort.md)<br/>
[atexit](atexit.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[_onexit, _onexit_m](onexit-onexit-m.md)<br/>
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
[system, _wsystem](system-wsystem.md)<br/>
