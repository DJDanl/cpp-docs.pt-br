---
title: _execl, _wexecl
ms.date: 11/04/2016
apiname:
- _execl
- _wexecl
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
- _execl
- _wexecl
- wexecl
helpviewer_keywords:
- _execl function
- wexecl function
- _wexecl function
- execl function
ms.assetid: 81fefb8a-0a06-4221-b2bc-be18e38e89f4
ms.openlocfilehash: 3d736849f90782425e6e1c1cff04536972318c91
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50530294"
---
# <a name="execl-wexecl"></a>_execl, _wexecl

Carrega e executa novos processos filho.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
intptr_t _execl(
   const char *cmdname,
   const char *arg0,
   ... const char *argn,
   NULL
);
intptr_t _wexecl(
   const wchar_t *cmdname,
   const wchar_t *arg0,
   ... const wchar_t *argn,
   NULL
);
```

### <a name="parameters"></a>Parâmetros

*cmdname*<br/>
Caminho do arquivo a ser executado.

*arg0*,... *argn*<br/>
Lista de ponteiros para os parâmetros.

## <a name="return-value"></a>Valor de retorno

Se bem-sucedidas, essas funções não retornam ao processo de chamada. Um valor de retorno de -1 indica um erro, caso em que o **errno** variável global é definida.

|Valor errno|Descrição|
|-----------------|-----------------|
|**E2BIG**|O espaço necessário para os argumentos e as configurações de ambiente excede 32 KB.|
|**EACCES**|O arquivo especificado tem uma violação de compartilhamento ou de bloqueio.|
|**EINVAL**|Parâmetro inválido (um ou mais dos parâmetros era um ponteiro nulo ou uma cadeia de caracteres vazia).|
|**EMFILE**|Muitos arquivos abertos (o arquivo especificado deve ser aberto para determinar se ele é executável).|
|**ENOENT**|Arquivo ou caminho não encontrado.|
|**ENOEXEC**|O arquivo especificado não é executável ou tem um formato inválido do arquivo executável.|
|**ENOMEM**|Não há memória suficiente disponível para executar o novo processo. A memória disponível foi corrompida ou há um bloco inválido, indicando que o processo de chamada não foi alocado corretamente.|

## <a name="remarks"></a>Comentários

Cada uma dessas funções carrega e executa um novo processo, passando cada argumento de linha de comando como um parâmetro separado. O primeiro argumento é o nome do arquivo executável ou comando e o segundo argumento deve ser o mesmo que o primeiro. Ele se torna `argv[0]` no processo executado. O terceiro argumento é o primeiro argumento, `argv[1]`, do processo que está sendo executado.

O **execl** funções validam seus parâmetros. Se qualquer um dos *cmdname* ou *arg0* é um ponteiro nulo ou cadeia de caracteres vazia, essas funções invocarão o manipulador de parâmetro inválido, conforme descrito na [validação de parâmetro](../../c-runtime-library/parameter-validation.md) se execução tem permissão para continuar, essas funções definirão **errno** à **EINVAL** e retornarão -1. Nenhum processo novo é executado.

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|Cabeçalho opcional|
|--------------|---------------------|---------------------|
|**_execl**|\<process.h>|\<errno.h>|
|**_wexecl**|\<process.h> ou \<wchar.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Consulte o exemplo nas [ funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md).

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)<br/>
[abort](abort.md)<br/>
[atexit](atexit.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[_onexit, _onexit_m](onexit-onexit-m.md)<br/>
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
[system, _wsystem](system-wsystem.md)<br/>
