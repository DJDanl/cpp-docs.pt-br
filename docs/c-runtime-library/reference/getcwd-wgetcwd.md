---
title: _getcwd, _wgetcwd
ms.date: 11/04/2016
api_name:
- _wgetcwd
- _getcwd
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
ms.openlocfilehash: 78b02871aafca85db50df2eea74a2210c578c204
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70955243"
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

*buffer*<br/>
Local de armazenamento para o caminho.

*maxlen*<br/>
Comprimento máximo do caminho em caracteres: **Char** para **_getcwd** e **wchar_t** para **_wgetcwd**.

## <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para o *buffer*. Um valor de retorno **nulo** indica um erro e **errno** é definido como **ENOMEM**, indicando que não há memória suficiente para alocar *maxlen* bytes (quando um argumento **nulo** é fornecido como *buffer*) ou para **ERANGE** , indicando que o caminho tem mais de *maxlen* caracteres. Se *maxlen* for menor ou igual a zero, essa função invocará um manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md).

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_getcwd** Obtém o caminho completo do diretório de trabalho atual para a unidade padrão e o armazena no *buffer*. O argumento Integer *maxlen* especifica o comprimento máximo para o caminho. Ocorrerá um erro se o comprimento do caminho (incluindo o caractere nulo de terminação) exceder *maxlen*. O argumento de *buffer* pode ser **nulo**; um buffer de pelo menos o tamanho *maxlen* (somente se necessário) é alocado automaticamente, usando **malloc**, para armazenar o caminho. Esse buffer pode ser liberado posteriormente chamando **Free** e passando o valor de retorno de **_getcwd** (um ponteiro para o buffer alocado).

**_getcwd** retorna uma cadeia de caracteres que representa o caminho do diretório de trabalho atual. Se o diretório de trabalho atual for a raiz, a cadeia de caracteres terminará com **\\** uma barra invertida (). Se o diretório de trabalho atual for um diretório que não seja o raiz, a cadeia de caracteres terminará com o nome do diretório e não com uma barra invertida.

**_wgetcwd** é uma versão de caractere largo do **_getcwd**; o argumento de *buffer* e o valor de retorno de **_wgetcwd** são cadeias de caracteres largos. **_wgetcwd** e **_getcwd** se comportam de outra forma.

Quando **_DEBUG** e **_CRTDBG_MAP_ALLOC** são definidos, chamadas para **_getcwd** e **_wgetcwd** são substituídas por chamadas para **_getcwd_dbg** e **_wgetcwd_dbg** para permitir a depuração de alocações de memória. Para obter mais informações, consulte [_getcwd_dbg, _wgetcwd_dbg](getcwd-dbg-wgetcwd-dbg.md).

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
// This program places the name of the current directory in the
// buffer array, then displays the name of the current directory
// on the screen. Passing NULL as the buffer forces getcwd to allocate
// memory for the path, which allows the code to support file paths
// longer than _MAX_PATH, which are supported by NTFS.

#include <direct.h>
#include <stdlib.h>
#include <stdio.h>

int main( void )
{
   char* buffer;

   // Get the current working directory:
   if( (buffer = _getcwd( NULL, 0 )) == NULL )
      perror( "_getcwd error" );
   else
   {
      printf( "%s \nLength: %d\n", buffer, strnlen(buffer) );
      free(buffer);
   }
}
```

```Output
C:\Code
```

## <a name="see-also"></a>Consulte também

[Controle de diretório](../../c-runtime-library/directory-control.md)<br/>
[_chdir, _wchdir](chdir-wchdir.md)<br/>
[_mkdir, _wmkdir](mkdir-wmkdir.md)<br/>
[_rmdir, _wrmdir](rmdir-wrmdir.md)<br/>
