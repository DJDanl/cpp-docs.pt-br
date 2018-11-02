---
title: _getcwd, _wgetcwd
ms.date: 11/04/2016
apiname:
- _wgetcwd
- _getcwd
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
- api-ms-win-crt-environment-l1-1-0.dll
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
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
ms.openlocfilehash: 4c533f0e716cb9a13c152b9be3c46f60291118d9
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50520231"
---
# <a name="getcwd-wgetcwd"></a>_getcwd, _wgetcwd

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

*MaxLen*<br/>
Comprimento máximo do caminho em caracteres: **char** para **getcwd** e **wchar_t** para **wgetcwd**.

## <a name="return-value"></a>Valor de retorno

Retorna um ponteiro para *buffer*. Um **nulo** valor retornado indica um erro, e **errno** será definido como **ENOMEM**, indicando que há memória suficiente para alocar *maxlen* bytes (quando um **nulo** argumento é fornecido como *buffer*), ou **ERANGE**, que indica que o caminho é maior que *maxlen*  caracteres. Se *maxlen* é menor que ou igual a zero, essa função invocará um manipulador de parâmetro inválido, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md).

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **getcwd** função obtém o caminho completo do diretório de trabalho atual para a unidade padrão e o armazena em *buffer*. O argumento de inteiro *maxlen* Especifica o comprimento máximo para o caminho. Ocorre um erro se o tamanho do caminho (incluindo o caractere nulo de terminação) ultrapassar *maxlen*. O *buffer* argumento pode ser **nulo**; um buffer de tamanho de pelo menos *maxlen* (mais somente se for necessário) é alocado automaticamente, usando **malloc**, para armazenar o caminho. Esse buffer pode, posteriormente, ser liberado chamando **livre** e passá-lo a **getcwd** retornar valor (um ponteiro para o buffer alocado).

**getcwd** retorna uma cadeia de caracteres que representa o caminho do diretório de trabalho atual. Se o diretório de trabalho atual é a raiz, a cadeia de caracteres termina com uma barra invertida ( **\\** ). Se o diretório de trabalho atual for um diretório que não seja o raiz, a cadeia de caracteres terminará com o nome do diretório e não com uma barra invertida.

**wgetcwd** é uma versão de caractere largo de **getcwd**; o *buffer* argumento e o valor retornado de **wgetcwd** são cadeias de caracteres largos. **wgetcwd** e **getcwd** se comportam de forma idêntica caso contrário.

Quando **Debug** e **crtdbg_map_alloc** são definidos, chamadas para **getcwd** e **wgetcwd** são substituídos por chamadas para **_ getcwd_dbg** e **wgetcwd_dbg** para permitir a depuração de alocações de memória. Para obter mais informações, consulte [_getcwd_dbg, _wgetcwd_dbg](getcwd-dbg-wgetcwd-dbg.md).

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
