---
title: _tell, _telli64
ms.date: 11/04/2016
api_name:
- _telli64
- _tell
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
- api-ms-win-crt-stdio-l1-1-0.dll
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- telli64
- _telli64
- _tell
helpviewer_keywords:
- tell function
- file pointers [C++], getting
- _tell function
- file pointers [C++]
- telli64 function
- _telli64 function
ms.assetid: 1500e8f9-8fec-4253-9eec-ec66125dfc9b
ms.openlocfilehash: f092bdfdb27dd73baf159da60ba66bd5809aaf61
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79443679"
---
# <a name="_tell-_telli64"></a>_tell, _telli64

Obtenha a posição do ponteiro de arquivo.

## <a name="syntax"></a>Sintaxe

```C
long _tell(
   int handle
);
__int64 _telli64(
   int handle
);
```

### <a name="parameters"></a>Parâmetros

*processamento*<br/>
Descritor de arquivo que faz referência a um arquivo aberto.

## <a name="return-value"></a>Valor retornado

A posição atual do ponteiro de arquivo. Em dispositivos sem capacidade de busca, o valor retornado será indefinido.

Um valor de retorno de-1L indica um erro. Se o *identificador* for um descritor de arquivo inválido, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções definirão **errno** como **EBADF** e retornará-1L.

Consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md) para obter mais informações sobre esses e outros códigos de retorno.

## <a name="remarks"></a>Comentários

A função **_tell** Obtém a posição atual do ponteiro do arquivo (se houver) associado ao argumento *Handle* . A posição é expressa como o número de bytes do início do arquivo. Para a função **_telli64** , esse valor é expresso como um inteiro de 64 bits.

## <a name="requirements"></a>{1&gt;{2&gt;Requisitos&lt;2}&lt;1}

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_tell**, **_telli64**|\<io.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>{1&gt;Exemplo&lt;1}

```C
// crt_tell.c
// This program uses _tell to tell the
// file pointer position after a file read.
//

#include <io.h>
#include <stdio.h>
#include <fcntl.h>
#include <share.h>
#include <string.h>

int main( void )
{
   int  fh;
   char buffer[500];

   if ( _sopen_s( &fh, "crt_tell.txt", _O_RDONLY, _SH_DENYNO, 0) )
   {
      char buff[50];
      _strerror_s( buff, sizeof(buff), NULL );
      printf( buff );
      exit( -1 );
   }

   if( _read( fh, buffer, 500 ) > 0 )
      printf( "Current file position is: %d\n", _tell( fh ) );
   _close( fh );
}
```

### <a name="input-crt_telltxt"></a>Entrada: crt_tell.txt

```Input
Line one.
Line two.
```

### <a name="output"></a>Saída

```Output
Current file position is: 20
```

## <a name="see-also"></a>Consulte também

[E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)<br/>
[ftell, _ftelli64](ftell-ftelli64.md)<br/>
[_lseek, _lseeki64](lseek-lseeki64.md)<br/>
