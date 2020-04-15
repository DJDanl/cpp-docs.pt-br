---
title: _unlink, _wunlink
ms.date: 4/2/2020
api_name:
- _unlink
- _wunlink
- _o__unlink
- _o__wunlink
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
- api-ms-win-crt-filesystem-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _tunlink
- _unlink
- wunlink
- _wunlink
helpviewer_keywords:
- files [C++], deleting
- _wunlink function
- wunlink function
- unlink function
- _unlink function
- tunlink function
- files [C++], removing
- _tunlink function
ms.assetid: 5e4f5f1b-1e99-4391-9b18-9ac63c32fae8
ms.openlocfilehash: ffc1a64c60d41246773d5e262523000355b0de3b
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81361270"
---
# <a name="_unlink-_wunlink"></a>_unlink, _wunlink

Exclui um arquivo.

## <a name="syntax"></a>Sintaxe

```C
int _unlink(
   const char *filename
);
int _wunlink(
   const wchar_t *filename
);
```

### <a name="parameters"></a>Parâmetros

*Filename*<br/>
Nome do arquivo a ser removido.

## <a name="return-value"></a>Valor retornado

Cada uma dessas funções retornará 0 em caso de êxito. Caso contrário, a função retorna -1 e define **errno** para **EACCES**, o que significa que o caminho especifica um arquivo somente leitura ou um diretório, ou para **ENOENT,** o que significa que o arquivo ou caminho não é encontrado.

Veja [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses, e outros, códigos de devolução.

## <a name="remarks"></a>Comentários

A função **_unlink** exclui o arquivo especificado pelo *nome do arquivo*. **_wunlink** é uma versão ampla de **_unlink;** o argumento *de nome de arquivo* para **_wunlink** é uma seqüência de caracteres amplo. Caso contrário, essas funções se comportam de forma idêntica.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico

|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|
|---------------------|------------------------------------|--------------------|-----------------------|
|**_tunlink**|**_unlink**|**_unlink**|**_wunlink**|

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_unlink**|\<io.h> e \<stdio.h>|
|**_wunlink**|\<io.h> ou \<wchar.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="code-example"></a>Exemplo de código

Esse programa usa _unlink para excluir CRT_UNLINK.TXT.

```C
// crt_unlink.c

#include <stdio.h>

int main( void )
{
   if( _unlink( "crt_unlink.txt" ) == -1 )
      perror( "Could not delete 'CRT_UNLINK.TXT'" );
   else
      printf( "Deleted 'CRT_UNLINK.TXT'\n" );
}
```

### <a name="input-crt_unlinktxt"></a>Entrada: crt_unlink.txt

```Input
This file will be deleted.
```

### <a name="sample-output"></a>Saída de exemplo

```Output
Deleted 'CRT_UNLINK.TXT'
```

## <a name="see-also"></a>Confira também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_close](close.md)<br/>
[remove, _wremove](remove-wremove.md)<br/>
