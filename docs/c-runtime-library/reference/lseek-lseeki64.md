---
title: _lseek, _lseeki64
ms.date: 4/2/2020
api_name:
- _lseeki64
- _lseek
- _o__lseek
- _o__lseeki64
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
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- _lseeki64
- _lseek
- lseeki64
helpviewer_keywords:
- lseek function
- _lseek function
- _lseeki64 function
- lseeki64 function
- file pointers [C++], moving
- seek file pointers
ms.assetid: aba8a768-d40e-48c3-b38e-473dbd782f93
ms.openlocfilehash: d35b3db157d4f33e3a8490c6620a08000ff090f5
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81341613"
---
# <a name="_lseek-_lseeki64"></a>_lseek, _lseeki64

Move o ponteiro do arquivo para um local especificado.

## <a name="syntax"></a>Sintaxe

```C
long _lseek(
   int fd,
   long offset,
   int origin
);
__int64 _lseeki64(
   int fd,
   __int64 offset,
   int origin
);
```

### <a name="parameters"></a>Parâmetros

*Fd*<br/>
Descritor de arquivo que faz referência a um arquivo aberto.

*deslocamento*<br/>
Número de bytes de *origem*.

*Origem*<br/>
Posição inicial.

## <a name="return-value"></a>Valor retornado

**_lseek** retorna o deslocamento, em bytes, da nova posição desde o início do arquivo. **_lseeki64** devolve o deslocamento em um inteiro de 64 bits. A função retorna -1L para indicar um erro. Se um parâmetro inválido for passado, como um descritor de arquivo incorreto, o valor de *origem* será inválido ou a posição especificada por *deslocamento* será anterior ao início do arquivo e o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de Parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, essas funções definem **errno** para **EBADF** e retornam -1L. Em dispositivos incapazes de fazer buscas (como terminais e impressoras), o valor retornado será indefinido.

Para obter mais informações sobre esses e outros códigos de erro, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A **função _lseek** move o ponteiro de arquivo associado ao *fd* para um novo local que é *offset* bytes de *origem*. A operação seguinte no arquivo ocorre no novo local. O argumento de *origem* deve ser uma das constantes a seguir, definidas em Stdio.h.

|valor *de origem*||
|-|-|
| **SEEK_SET** | Início do arquivo. |
| **SEEK_CUR** | Posição atual do ponteiro de arquivo. |
| **SEEK_END** | Final do arquivo. |

Você pode usar **_lseek** para reposicionar o ponteiro em qualquer lugar de um arquivo ou além do final do arquivo.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_lseek**|\<io.h>|
|**_lseeki64**|\<io.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Bibliotecas

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_lseek.c
/* This program first opens a file named lseek.txt.
* It then uses _lseek to find the beginning of the file,
* to find the current position in the file, and to find
* the end of the file.
*/

#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <share.h>

int main( void )
{
   int fh;
   long pos;               /* Position of file pointer */
   char buffer[10];

   _sopen_s( &fh, "crt_lseek.c_input", _O_RDONLY, _SH_DENYNO, 0 );

   /* Seek the beginning of the file: */
   pos = _lseek( fh, 0L, SEEK_SET );
   if( pos == -1L )
      perror( "_lseek to beginning failed" );
   else
      printf( "Position for beginning of file seek = %ld\n", pos );

   /* Move file pointer a little */
    _read( fh, buffer, 10 );

   /* Find current position: */
   pos = _lseek( fh, 0L, SEEK_CUR );
   if( pos == -1L )
      perror( "_lseek to current position failed" );
   else
      printf( "Position for current position seek = %ld\n", pos );

   /* Set the end of the file: */
   pos = _lseek( fh, 0L, SEEK_END );
   if( pos == -1L )
      perror( "_lseek to end failed" );
   else
      printf( "Position for end of file seek = %ld\n", pos );

   _close( fh );
}
```

### <a name="input-crt_lseekc_input"></a>Entrada: crt_lseek.c_input

```Input
Line one.
Line two.
Line three.
Line four.
Line five.
```

### <a name="output"></a>Saída

```Output
Position for beginning of file seek = 0
Position for current position seek = 10
Position for end of file seek = 57
```

## <a name="see-also"></a>Confira também

[E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)<br/>
[fseek, _fseeki64](fseek-fseeki64.md)<br/>
[_tell, _telli64](tell-telli64.md)<br/>
