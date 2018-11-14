---
title: system, _wsystem
ms.date: 11/04/2016
apiname:
- system
- _wsystem
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
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _tsystem
- _wsystem
helpviewer_keywords:
- _wsystem function
- wsystem function
- tsystem function
- _tsystem function
- system function
- commands, executing
- command interpreter
ms.assetid: 7d3df2b6-f742-49ce-bf52-012b0aee3df5
ms.openlocfilehash: 46c4949fcc8cfbe4a3477e66b57d8fc6fc97ed73
ms.sourcegitcommit: 1819bd2ff79fba7ec172504b9a34455c70c73f10
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/09/2018
ms.locfileid: "51328650"
---
# <a name="system-wsystem"></a>system, _wsystem

Executa um comando.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

## <a name="syntax"></a>Sintaxe

```C
int system(
   const char *command
);
int _wsystem(
   const wchar_t *command
);
```

### <a name="parameters"></a>Parâmetros

*command*<br/>
O comando a ser executado.

## <a name="return-value"></a>Valor de retorno

Se *comando* é **nulo** e o interpretador de comandos for encontrado, retorna um valor diferente de zero. Se o interpretador de comandos não for encontrado, retornará 0 e definirá **errno** à **ENOENT**. Se *comando* não está **nulo**, **sistema** retorna o valor retornado pelo interpretador de comandos. Retornará o valor 0 somente se o interpretador de comandos retornar o valor 0. Um valor retornado de - 1 indica um erro, e **errno** é definido como um dos seguintes valores:

|||
|-|-|
| **E2BIG** | A lista de argumentos (que é dependente do sistema) é muito grande. |
| **ENOENT** | Não foi possível encontrar o interpretador de comandos. |
| **ENOEXEC** | O arquivo do interpretador de comandos não pode ser executado porque o formato não é válido. |
| **ENOMEM** | Não há memória suficiente disponível para executar o comando, a memória disponível foi corrompida ou há um bloco inválido, indicando que o processo que está fazendo a chamada não foi alocado corretamente. |

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses códigos de retorno.

## <a name="remarks"></a>Comentários

O **system** função passa *comando* ao interpretador de comandos, que executa a cadeia de caracteres como um comando de sistema operacional. **sistema** usa o **COMSPEC** e **caminho** CMD.exe de arquivo de variáveis de ambiente para localizar o interpretador de comandos. Se *comando* é **nulo**, a função apenas verificará se o interpretador de comandos existe.

Você deve liberar explicitamente, usando [fflush](fflush.md) ou [flushall](flushall.md), ou fechar qualquer fluxo antes de chamar **sistema**.

**wsystem** é uma versão de caractere largo de **system**; o *comando* argumento **wsystem** é uma cadeia de caracteres largos. Caso contrário, essas funções se comportam de forma idêntica.

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**tsystem**|**system**|**system**|**_wsystem**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**system**|\<process.h> ou \<stdlib.h>|
|**_wsystem**|\<process.h>, \<stdlib.h> ou \<wchar.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Este exemplo usa **sistema** para o tipo de um arquivo de texto.

```C
// crt_system.c

#include <process.h>

int main( void )
{
   system( "type crt_system.txt" );
}
```

### <a name="input-crtsystemtxt"></a>Entrada: crt_system.txt

```Input
Line one.
Line two.
```

### <a name="output"></a>Saída

```Output
Line one.
Line two.
```

## <a name="see-also"></a>Consulte também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[_flushall](flushall.md)<br/>
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
