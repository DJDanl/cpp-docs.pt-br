---
title: _getcwd, _wgetcwd | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- getcwd function
- working directory
- _wgetcwd function
- _getcwd function
- current working directory
- wgetcwd function
- directories [C++], current working
ms.assetid: 888dc8c6-5595-4071-be55-816b38e3e739
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 10f242569579680c8e388b84bdcaca235a142a34
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32405283"
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

Retorna um ponteiro para *buffer*. Um **nulo** retornar valor indica um erro, e **errno** é definido como **ENOMEM**, indicando que há memória suficiente para alocar *maxlen* bytes (quando um **nulo** argumento é determinado como *buffer*), ou **ERANGE**, indicando que o caminho é maior que *maxlen*  caracteres. Se *maxlen* é menor ou igual a zero, esta função chama um manipulador de parâmetro inválido, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md).

Para obter mais informações sobre esses e outros códigos de retorno, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **getcwd** função obtém o caminho completo do diretório de trabalho atual para a unidade padrão e o armazena em *buffer*. O argumento de inteiro *maxlen* Especifica o tamanho máximo para o caminho. Ocorrerá um erro se excede o comprimento do caminho (incluindo o caractere null de terminação) *maxlen*. O *buffer* argumento pode ser **nulo**; um buffer de tamanho de pelo menos *maxlen* (mais se necessário) é alocado automaticamente, usando **malloc**, para o caminho do repositório. Esse buffer posteriormente pode ser liberado chamando **livre** e passá-lo a **getcwd** (um ponteiro para o buffer alocado) do valor de retorno.

**getcwd** retorna uma cadeia de caracteres que representa o caminho do diretório de trabalho atual. Se o diretório de trabalho atual é a raiz, a cadeia de caracteres termina com uma barra invertida ( **\\** ). Se o diretório de trabalho atual for um diretório que não seja o raiz, a cadeia de caracteres terminará com o nome do diretório e não com uma barra invertida.

**wgetcwd** é uma versão de caractere largo de **getcwd**; o *buffer* argumento e retornar o valor de **wgetcwd** são cadeias de caracteres do caractere largo. **wgetcwd** e **getcwd** se comportam de forma idêntica caso contrário.

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
