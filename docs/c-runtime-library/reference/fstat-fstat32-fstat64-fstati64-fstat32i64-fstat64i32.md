---
title: _fstat, _fstat32, _fstat64, _fstati64, _fstat32i64, _fstat64i32 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _fstat32
- _fstat64
- _fstati64
- _fstat
- _fstat64i32
- _fstat32i64
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
- api-ms-win-crt-filesystem-l1-1-0.dll
apitype: DLLExport
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
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 65d77bfdd7922387568ca8257e66f6e19dde1a35
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="fstat-fstat32-fstat64-fstati64-fstat32i64-fstat64i32"></a>_fstat, _fstat32, _fstat64, _fstati64, _fstat32i64, _fstat64i32

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

*fd*<br/>
Descritor de arquivo do arquivo aberto.

*buffer*<br/>
Ponteiro para a estrutura para armazenar resultados.

## <a name="return-value"></a>Valor de retorno

Retornará 0 se as informações de status do arquivo forem obtidas. Um valor de retorno de -1 indica um erro. Se o descritor de arquivo é inválido ou *buffer* é **nulo**, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, **errno** é definido como **EBADF**, no caso de um descritor de arquivo inválido ou a **EINVAL**, se *buffer* é **nulo**.

## <a name="remarks"></a>Comentários

O **fstat** função obtém informações sobre o arquivo aberto associado *fd* e o armazena na estrutura apontada pelo *buffer*. O **STAT** estrutura, definida em SYS\Stat.h, contém os campos a seguir.

|Campo|Significado|
|-|-|
**st_atime**|Hora do último acesso ao arquivo.
**st_ctime**|Hora da criação do arquivo.
**st_dev**|Se um dispositivo, *fd*; caso contrário, 0.
**st_mode**|Máscara de bits para informações sobre o modo de arquivo. O **s_ifchr** bit é definido se *fd* refere-se a um dispositivo. O **s_ifreg** bit é definido se *fd* refere-se a um arquivo comum. Os bits de leitura/gravação são definidos de acordo com o modo de permissão do arquivo. **S_ifchr** e outras constantes estão definidas no SYS\Stat.h.
**st_mtime**|Hora da última modificação do arquivo.
**st_nlink**|Sempre 1 em sistemas de arquivos diferentes de NTFS.
**st_rdev**|Se um dispositivo, *fd*; caso contrário, 0.
**st_size**|Tamanho do arquivo em bytes.

Se *fd* refere-se a um dispositivo, o **st_atime**, **st_ctime**, **st_mtime**, e **st_size** campos são não é significativo.

Como Stat.h usa o tipo [_dev_t](../../c-runtime-library/standard-types.md), que é definido em Types.h, você deve incluir Types.h antes de Stat.h em seu código.

**fstat64**, que usa o **stat64** estrutura, permite que as datas de criação do arquivo a ser expressa backup por meio de 23:59:59, 31 de dezembro de 3000 a UTC; enquanto as outras funções representam apenas datas até 23:59:59 18 de janeiro, 2038, UTC. Meia-noite de 1º de janeiro de 1970 é o limite inferior do intervalo de datas para todas essas funções.

Variações dessas funções dão suporte a tipos de hora de 32 ou de 64 bits e a comprimentos de arquivo de 32 ou de 64 bits. O primeiro sufixo numérico (**32** ou **64**) indica o tamanho do tempo tipo usado; é o sufixo do segundo **i32** ou **i64**, que indica se o tamanho do arquivo é representado como um inteiro de 32 bits ou 64 bits.

**fstat** é equivalente a **_fstat64i32**, e **struct** **STAT** contém um tempo de 64 bits. Isso é verdadeiro, a menos que **_USE_32BIT_TIME_T** for definido, caso em que o comportamento antigo está em vigor; **fstat** usa um tempo de 32 bits, e **struct** **STAT** contém um tempo de 32 bits. O mesmo é verdadeiro para **fstati64**.

### <a name="time-type-and-file-length-type-variations-of-stat"></a>Variações de tipo de hora e de tipo de tamanho de arquivo de _stat

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

## <a name="see-also"></a>Consulte também

[Manipulação de Arquivos](../../c-runtime-library/file-handling.md)<br/>
[_access, _waccess](access-waccess.md)<br/>
[_chmod, _wchmod](chmod-wchmod.md)<br/>
[_filelength, _filelengthi64](filelength-filelengthi64.md)<br/>
[Funções _stat, _wstat](stat-functions.md)<br/>
