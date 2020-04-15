---
title: system, _wsystem
ms.date: 4/2/2020
api_name:
- system
- _wsystem
- _o__wsystem
- _o_system
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
- api-ms-win-crt-runtime-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
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
ms.openlocfilehash: 21ce04d30da80a40a1162dce06ff378150008766
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81362786"
---
# <a name="system-_wsystem"></a>system, _wsystem

Executa um comando.

> [!IMPORTANT]
> Esta API não pode ser usada em aplicativos executados no Windows Runtime. Para obter mais informações, confira [Funções do CRT sem suporte em aplicativos da Plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).

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

*Comando*<br/>
O comando a ser executado.

## <a name="return-value"></a>Valor retornado

Se o *comando* **for NULL** e o intérprete de comando for encontrado, retorna um valor não zero. Se o intérprete de comando não for encontrado, retorna 0 e define **errno** para **ENOENT**. Se o *comando* não for **NULL,** o **sistema** retorna o valor que é devolvido pelo intérprete de comando. Retornará o valor 0 somente se o interpretador de comandos retornar o valor 0. Um valor de retorno de - 1 indica um erro, e **errno** é definido como um dos seguintes valores:

|||
|-|-|
| **E2BIG** | A lista de argumentos (que é dependente do sistema) é muito grande. |
| **Enoent** | Não foi possível encontrar o interpretador de comandos. |
| **ENOEXEC** | O arquivo do interpretador de comandos não pode ser executado porque o formato não é válido. |
| **Enomem** | Não há memória suficiente disponível para executar o comando, a memória disponível foi corrompida ou há um bloco inválido, indicando que o processo que está fazendo a chamada não foi alocado corretamente. |

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses códigos de retorno.

## <a name="remarks"></a>Comentários

A função **do sistema** passa *o comando* para o intérprete de comando, que executa a seqüência como um comando do sistema operacional. **o sistema** usa as variáveis de ambiente **COMSPEC** e **PATH** para localizar o arquivo de intérprete de comando CMD.exe. Se o *comando* for **NULL**, a função apenas verifica se o intérprete de comando existe.

Você deve explicitamente dar descarga, usando [fflush](fflush.md) ou [_flushall,](flushall.md)ou fechar qualquer fluxo antes de chamar **o sistema**.

**_wsystem** é uma versão de amplo caractere do **sistema;** o argumento *de comando* para **_wsystem** é uma seqüência de caracteres amplo. Caso contrário, essas funções se comportam de forma idêntica.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tsystem**|**sistema**|**sistema**|**_wsystem**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**sistema**|\<process.h> ou \<stdlib.h>|
|**_wsystem**|\<process.h>, \<stdlib.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

Este exemplo usa **o sistema** para digitar um arquivo de texto.

```C
// crt_system.c

#include <process.h>

int main( void )
{
   system( "type crt_system.txt" );
}
```

### <a name="input-crt_systemtxt"></a>Entrada: crt_system.txt

```Input
Line one.
Line two.
```

### <a name="output"></a>Saída

```Output
Line one.
Line two.
```

## <a name="see-also"></a>Confira também

[Controle de processo e de ambiente](../../c-runtime-library/process-and-environment-control.md)<br/>
[Funções _exec, _wexec](../../c-runtime-library/exec-wexec-functions.md)<br/>
[exit, _Exit, _exit](exit-exit-exit.md)<br/>
[_flushall](flushall.md)<br/>
[Funções _spawn, _wspawn](../../c-runtime-library/spawn-wspawn-functions.md)<br/>
