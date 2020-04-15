---
title: _fstat, _fstat32, _fstat64, _fstati64, _fstat32i64, _fstat64i32
ms.date: 4/2/2020
api_name:
- _fstat32
- _fstat64
- _fstati64
- _fstat
- _fstat64i32
- _fstat32i64
- _o__fstat32
- _o__fstat32i64
- _o__fstat64
- _o__fstat64i32
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
- _fstat32i64
- fstat
- fstat64i32
- _fstat64
- _fstati64
- fstat64
- _fstat32
- fstat32i64
- fstati64
- _fstat
- fstat32
- _fstat64i32
helpviewer_keywords:
- _fstat64 function
- fstati64 function
- _fstat64i32 function
- _fstat32i64 function
- _fstat32 function
- file information
- fstat64i32 function
- fstat32 function
- fstat function
- fstat64 function
- _fstat function
- _fstati64 function
- fstat32i64 function
ms.assetid: 088f5e7a-9636-4cf7-ab8e-e28d2aa4280a
ms.openlocfilehash: 02d297fec2ada545a8b693abacfecc7981149dae
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81345664"
---
# <a name="_fstat-_fstat32-_fstat64-_fstati64-_fstat32i64-_fstat64i32"></a>_fstat, _fstat32, _fstat64, _fstati64, _fstat32i64, _fstat64i32

Obtém informações sobre um arquivo aberto.

## <a name="syntax"></a>Sintaxe

```C
int _fstat(
   int fd,
   struct _stat *buffer
);
int _fstat32(
   int fd,
   struct __stat32 *buffer
);
int _fstat64(
   int fd,
   struct __stat64 *buffer
);
int _fstati64(
   int fd,
   struct _stati64 *buffer
);
int _fstat32i64(
   int fd,
   struct _stat32i64 *buffer
);
int _fstat64i32(
   int fd,
   struct _stat64i32 *buffer
);
```

### <a name="parameters"></a>Parâmetros

*Fd*<br/>
Descritor de arquivo do arquivo aberto.

*Buffer*<br/>
Ponteiro para a estrutura para armazenar resultados.

## <a name="return-value"></a>Valor retornado

Retornará 0 se as informações de status do arquivo forem obtidas. Um valor de retorno de -1 indica um erro. Se o descritor do arquivo for inválido ou *o buffer* for **NULL,** o manipulador de parâmetros inválidos será invocado, conforme descrito na [Validação de Parâmetros](../../c-runtime-library/parameter-validation.md). Se a execução continuar, **errno** será definido como **EBADF,** no caso de um descritor de arquivo inválido, ou para **EINVAL,** se *o buffer* for **NULL**.

## <a name="remarks"></a>Comentários

A função **_fstat** obtém informações sobre o arquivo aberto associado ao *FD* e armazena-o na estrutura apontada pelo *buffer*. A estrutura **_stat,** definida em SYS\Stat.h, contém os seguintes campos.

|Campo|Significado|
|-|-|
| **st_atime** | Hora do último acesso ao arquivo. |
| **st_ctime** | Hora da criação do arquivo. |
| **st_dev** | Se um dispositivo, *fd;* caso contrário, 0. |
| **st_mode** | Máscara de bits para informações sobre o modo de arquivo. A **_S_IFCHR** bit é definida se *fd* se refere a um dispositivo. A **_S_IFREG** bit é definida se *fd* se refere a um arquivo comum. Os bits de leitura/gravação são definidos de acordo com o modo de permissão do arquivo. **_S_IFCHR** e outras constantes são definidas no SYS\Stat.h. |
| **st_mtime** | Hora da última modificação do arquivo. |
| **st_nlink** | Sempre 1 em sistemas de arquivos diferentes de NTFS. |
| **st_rdev** | Se um dispositivo, *fd;* caso contrário, 0. |
| **st_size** | Tamanho do arquivo em bytes. |

Se *fd* se refere a um dispositivo, os **campos st_atime**, **st_ctime**, **st_mtime**e **st_size** não são significativos.

Como Stat.h usa o tipo [_dev_t](../../c-runtime-library/standard-types.md), que é definido em Types.h, você deve incluir Types.h antes de Stat.h em seu código.

**_fstat64**, que usa a estrutura **__stat64,** permite que as datas de criação de arquivos sejam expressas até 23:59:59, 31 de dezembro de 3000, UTC; enquanto as outras funções representam apenas datas até 23:59:59 janeiro 18, 2038, UTC. Meia-noite de 1º de janeiro de 1970 é o limite inferior do intervalo de datas para todas essas funções.

Variações dessas funções dão suporte a tipos de hora de 32 ou de 64 bits e a comprimentos de arquivo de 32 ou de 64 bits. O primeiro sufixo numérico **(32** ou **64**) indica o tamanho do tipo de tempo utilizado; o segundo sufixo é **i32** ou **i64,** indicando se o tamanho do arquivo é representado como um inteiro de 32 bits ou 64 bits.

**_fstat** equivale a **_fstat64i32**e **a estrutura** **_stat** contém um tempo de 64 bits. Isso é verdade, a menos que **_USE_32BIT_TIME_T** seja definido, nesse caso o comportamento antigo está em vigor; **_fstat** usa um tempo de 32 **bits,** e **a estruturação _stat** contém um tempo de 32 bits. O mesmo vale para **_fstati64.**

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

### <a name="time-type-and-file-length-type-variations-of-_stat"></a>Variações de tipo de hora e de tipo de tamanho de arquivo de _stat

|Funções|_USE_32BIT_TIME_T definido?|Tipo de hora|Tipo de tamanho de arquivo|
|---------------|------------------------------------|---------------|----------------------|
|**_fstat**|Não definido|64 bits|32 bits|
|**_fstat**|Definido|32 bits|32 bits|
|**_fstat32**|Não afetado pela definição de macro|32 bits|32 bits|
|**_fstat64**|Não afetado pela definição de macro|64 bits|64 bits|
|**_fstati64**|Não definido|64 bits|64 bits|
|**_fstati64**|Definido|32 bits|64 bits|
|**_fstat32i64**|Não afetado pela definição de macro|32 bits|64 bits|
|**_fstat64i32**|Não afetado pela definição de macro|64 bits|32 bits|

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|
|--------------|---------------------|
|**_fstat**|\<sys/stat.h> e \<sys/types.h>|
|**_fstat32**|\<sys/stat.h> e \<sys/types.h>|
|**_fstat64**|\<sys/stat.h> e \<sys/types.h>|
|**_fstati64**|\<sys/stat.h> e \<sys/types.h>|
|**_fstat32i64**|\<sys/stat.h> e \<sys/types.h>|
|**_fstat64i32**|\<sys/stat.h> e \<sys/types.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_fstat.c
// This program uses _fstat to report
// the size of a file named F_STAT.OUT.

#include <io.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <share.h>

int main( void )
{
   struct _stat buf;
   int fd, result;
   char buffer[] = "A line to output";
   char timebuf[26];
   errno_t err;

   _sopen_s( &fd,
             "f_stat.out",
             _O_CREAT | _O_WRONLY | _O_TRUNC,
             _SH_DENYNO,
             _S_IREAD | _S_IWRITE );
   if( fd != -1 )
      _write( fd, buffer, strlen( buffer ) );

   // Get data associated with "fd":
   result = _fstat( fd, &buf );

   // Check if statistics are valid:
   if( result != 0 )
   {
      if (errno == EBADF)
        printf( "Bad file descriptor.\n" );
      else if (errno == EINVAL)
        printf( "Invalid argument to _fstat.\n" );
   }
   else
   {
      printf( "File size     : %ld\n", buf.st_size );
      err = ctime_s(timebuf, 26, &buf.st_mtime);
      if (err)
      {
         printf("Invalid argument to ctime_s.");
         exit(1);
      }
      printf( "Time modified : %s", timebuf );
   }
   _close( fd );
}
```

```Output
File size     : 16
Time modified : Wed May 07 15:25:11 2003
```

## <a name="see-also"></a>Confira também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_access, _waccess](access-waccess.md)<br/>
[_chmod, _wchmod](chmod-wchmod.md)<br/>
[_filelength, _filelengthi64](filelength-filelengthi64.md)<br/>
[Funções _stat, _wstat](stat-functions.md)<br/>
