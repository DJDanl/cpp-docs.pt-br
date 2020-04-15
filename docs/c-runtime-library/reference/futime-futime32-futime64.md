---
title: _futime, _futime32, _futime64
ms.date: 4/2/2020
api_name:
- _futime64
- _futime32
- _futime
- _o__futime32
- _o__futime64
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
- api-ms-win-crt-time-l1-1-0.dll
- api-ms-win-crt-private-l1-1-0
api_type:
- DLLExport
topic_type:
- apiref
f1_keywords:
- futime
- _futime
- futime64
- _futime64
helpviewer_keywords:
- _futime function
- futime32 function
- futime64 function
- file modification time [C++]
- _futime64 function
- futime function
- _futime32 function
ms.assetid: b942ce8f-5cc7-4fa8-ab47-de5965eded53
ms.openlocfilehash: 1f60bb3b366c48e3d53368f81ebc2528694794f3
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81345500"
---
# <a name="_futime-_futime32-_futime64"></a>_futime, _futime32, _futime64

Define o tempo de modificação em um arquivo aberto.

## <a name="syntax"></a>Sintaxe

```C
int _futime(
   int fd,
   struct _utimbuf *filetime
);
int _futime32(
   int fd,
   struct __utimbuf32 *filetime
);
int _futime64(
   int fd,
   struct __utimbuf64 *filetime
);
```

### <a name="parameters"></a>Parâmetros

*Fd*<br/>
Descritor de arquivo do arquivo aberto.

*Filetime*<br/>
Ponteiro para a estrutura que contém a nova data de modificação.

## <a name="return-value"></a>Valor retornado

Retorna 0 se for bem-sucedido. Se ocorrer um erro, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, a função retorna -1 e **errno** é definida como **EBADF**, indicando um descritor de arquivo inválido, ou **EINVAL,** indicando um parâmetro inválido.

## <a name="remarks"></a>Comentários

A rotina **_futime** define a data de modificação e o tempo de acesso no arquivo aberto associado ao *fd*. **_futime** é idêntico ao [_utime,](utime-utime32-utime64-wutime-wutime32-wutime64.md)exceto que seu argumento é o descritor de arquivo de um arquivo aberto, em vez do nome de um arquivo ou um caminho para um arquivo. A estrutura **_utimbuf** contém campos para a nova data de modificação e tempo de acesso. Os dois campos devem conter valores válidos. **_utimbuf32** e **_utimbuf64** são idênticos aos **_utimbuf** exceto pelo uso dos tipos de tempo de 32 e 64 bits, respectivamente. **_futime** e **_utimbuf** usam um tipo de tempo de 64 bits e **_futime** é idêntico no comportamento **_futime64**. Se você precisa forçar o comportamento antigo, defina **_USE_32BIT_TIME_T**. Fazer isso **faz com que _futime** seja idêntico no comportamento _futime32 e faz com que a estrutura **_utimbuf** use o tipo de tempo de 32 bits, tornando-o equivalente a **__utimbuf32**. **_futime32**

**_futime64**, que usa a estrutura **__utimbuf64,** pode ler e modificar datas de arquivo até 23:59:59, 31 de dezembro de 3000, UTC; que uma chamada para **_futime32** falhar se a data do arquivo for mais tarde do que 23:59:59 janeiro 18, 2038, UTC. Meia-noite de 1º de janeiro de 1970 é o limite inferior do intervalo de datas para essas funções.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Função|Cabeçalho necessário|Cabeçalho opcional|
|--------------|---------------------|---------------------|
|**_futime**|\<sys/utime.h>|\<errno.h>|
|**_futime32**|\<sys/utime.h>|\<errno.h>|
|**_futime64**|\<sys/utime.h>|\<errno.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt_futime.c
// This program uses _futime to set the
// file-modification time to the current time.

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/utime.h>
#include <share.h>

int main( void )
{
   int hFile;

   // Show file time before and after.
   system( "dir crt_futime.c_input" );

   _sopen_s( &hFile, "crt_futime.c_input", _O_RDWR, _SH_DENYNO, 0 );

   if( _futime( hFile, NULL ) == -1 )
      perror( "_futime failed\n" );
   else
      printf( "File time modified\n" );

   _close (hFile);

   system( "dir crt_futime.c_input" );
}
```

### <a name="input-crt_futimec_input"></a>Entrada: crt_futime.c_input

```Input
Arbitrary file contents.
```

### <a name="sample-output"></a>Saída de exemplo

```Output
Volume in drive Z has no label.
Volume Serial Number is 5C68-57C1

Directory of Z:\crt

03/25/2004  10:40 AM                24 crt_futime.c_input
               1 File(s)             24 bytes
               0 Dir(s)  24,268,476,416 bytes free
Volume in drive Z has no label.
Volume Serial Number is 5C68-57C1

Directory of Z:\crt

03/25/2004  10:41 AM                24 crt_futime.c_input
               1 File(s)             24 bytes
               0 Dir(s)  24,268,476,416 bytes free
File time modified
```

## <a name="see-also"></a>Confira também

[Gerenciamento de tempo](../../c-runtime-library/time-management.md)<br/>
