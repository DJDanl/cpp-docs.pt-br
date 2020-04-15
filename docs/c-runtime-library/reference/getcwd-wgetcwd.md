---
title: _getcwd, _wgetcwd
description: C Funções da Biblioteca de Tempo de Execução _getcwd, _wgetcwd obter o diretório de trabalho atual.
ms.date: 4/2/2020
api_name:
- _wgetcwd
- _getcwd
- _o__getcwd
- _o__wgetcwd
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
- api-ms-win-crt-environment-l1-1-0.dll
- api-ms-win-crt-stdio-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _getcwd
- wgetcwd
- _wgetcwd
- tgetcwd
- _tgetcwd
helpviewer_keywords:
- getcwd function
- working directory
- _wgetcwd function
- _getcwd function
- current working directory
- wgetcwd function
- directories [C++], current working
ms.assetid: 888dc8c6-5595-4071-be55-816b38e3e739
ms.openlocfilehash: bc19a416ebebeb901e8dbb435971e6d5f33e4067
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81344444"
---
# <a name="_getcwd-_wgetcwd"></a>_getcwd, _wgetcwd

Obtém o diretório de trabalho atual.

## <a name="syntax"></a>Sintaxe

```C
char *_getcwd(
   char *buffer,
   int maxlen
);
wchar_t *_wgetcwd(
   wchar_t *buffer,
   int maxlen
);
```

### <a name="parameters"></a>Parâmetros

*Buffer*\
Local de armazenamento para o caminho.

*Maxlen*\
Comprimento máximo do caminho em caracteres: **char** para **_getcwd** e **wchar_t** para **_wgetcwd**.

## <a name="return-value"></a>Valor retornado

Retorna um ponteiro para *buffer*. Um valor **de** retorno NULL indica um erro, e **errno** é definido tanto no **ENOMEM**, indicando que não há memória suficiente para alocar bytes *maxlen* (quando um argumento **NULL** é dado como *buffer),* ou para **ERANGE,** indicando que o caminho é mais longo do que caracteres *maxlen.* Se *maxlen* for menor ou igual a zero, esta função invoca um manipulador de parâmetros inválido, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md).

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_getcwd** obtém o caminho completo do diretório de trabalho atual para a unidade padrão e armazena-a no *buffer*. O argumento inteiro *maxlen* especifica o comprimento máximo para o caminho. Um erro ocorre se o comprimento do caminho (incluindo o caractere nulo terminante) exceder *maxlen*. O argumento *buffer* pode ser **NULO;** um buffer de *maxlen* de pelo menos tamanho (mais apenas se necessário) é automaticamente alocado, usando **malloc**, para armazenar o caminho. Este buffer pode ser liberado posteriormente ligando **para free** e passando-o o valor de retorno **_getcwd** (um ponteiro para o buffer alocado).

**_getcwd** retorna uma seqüência que representa o caminho do diretório de trabalho atual. Se o diretório de trabalho atual for a raiz,`\`a corda termina com uma barra invertida ( ). Se o diretório de trabalho atual for um diretório que não seja o raiz, a cadeia de caracteres terminará com o nome do diretório e não com uma barra invertida.

**_wgetcwd** é uma versão ampla de **_getcwd;** o argumento *de buffer* e o valor de retorno de **_wgetcwd** são strings de caracteres amplos. **_wgetcwd** e **_getcwd** se comportam de forma idêntica.

Quando **_DEBUG** e **_CRTDBG_MAP_ALLOC** são definidas, as chamadas para **_getcwd** e **_wgetcwd** são substituídas por chamadas para **_getcwd_dbg** e **_wgetcwd_dbg** para permitir a depuração de alocações de memória. Para obter mais informações, consulte [_getcwd_dbg, _wgetcwd_dbg](getcwd-dbg-wgetcwd-dbg.md).

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina Tchar.h|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|--------------------------------------|--------------------|-----------------------|
|**_tgetcwd**|**_getcwd**|**_getcwd**|**_wgetcwd**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_getcwd**|\<direct.h>|
|**_wgetcwd**|\<direct.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_getcwd.c
// Compile with: cl /W4 crt_getcwd.c
// This program places the name of the current directory in the
// buffer array, then displays the name of the current directory
// on the screen. Passing NULL as the buffer forces getcwd to allocate
// memory for the path, which allows the code to support file paths
// longer than _MAX_PATH, which are supported by NTFS.

#include <direct.h> // _getcwd
#include <stdlib.h> // free, perror
#include <stdio.h>  // printf
#include <string.h> // strlen

int main( void )
{
   char* buffer;

   // Get the current working directory:
   if ( (buffer = _getcwd( NULL, 0 )) == NULL )
      perror( "_getcwd error" );
   else
   {
      printf( "%s \nLength: %zu\n", buffer, strlen(buffer) );
      free(buffer);
   }
}
```

```Output
C:\Code
```

## <a name="see-also"></a>Confira também

[Controle de Diretórios](../../c-runtime-library/directory-control.md)\
[_chdir _wchdir](chdir-wchdir.md)\
[_mkdir _wmkdir](mkdir-wmkdir.md)\
[_rmdir, _wrmdir](rmdir-wrmdir.md)
