---
title: _futime, _futime32, _futime64 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
apiname:
- _futime64
- _futime32
- _futime
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
- api-ms-win-crt-time-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- futime
- _futime
- futime64
- _futime64
dev_langs:
- C++
helpviewer_keywords:
- _futime function
- futime32 function
- futime64 function
- file modification time [C++]
- _futime64 function
- futime function
- _futime32 function
ms.assetid: b942ce8f-5cc7-4fa8-ab47-de5965eded53
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: cdd7b68ac9e3bf55f64b9a68f7b8075eab640faa
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46056814"
---
# <a name="futime-futime32-futime64"></a>_futime, _futime32, _futime64

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

*fd*<br/>
Descritor de arquivo do arquivo aberto.

*FILETIME*<br/>
Ponteiro para a estrutura que contém a nova data de modificação.

## <a name="return-value"></a>Valor de retorno

Retorna 0 se for bem-sucedido. Se ocorrer um erro, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará -1 e **errno** é definido como **EBADF**, que indica um descritor de arquivo inválido, ou **EINVAL**, indicando um inválido parâmetro.

## <a name="remarks"></a>Comentários

O **futime** rotina define a data de modificação e a hora de acesso no arquivo aberto associado *fd*. **futime** é idêntica à [utime](utime-utime32-utime64-wutime-wutime32-wutime64.md), exceto que o argumento é o descritor de arquivo de um arquivo aberto, em vez do nome de um arquivo ou um caminho para um arquivo. O **utimbuf** estrutura contém campos para a nova data de modificação e a hora de acesso. Os dois campos devem conter valores válidos. **_utimbuf32** e **_utimbuf64** são idênticas às **utimbuf** exceto para o uso dos tipos de tempo de 32 bits e 64 bits, respectivamente. **futime** e **utimbuf** usar um tipo de tempo de 64 bits e **futime** é idêntico ao comportamento **_futime64**. Se você precisar forçar o comportamento antigo, defina **_USE_32BIT_TIME_T**. Fazer isso faz com que **futime** seja idêntico ao comportamento **_futime32** e faz com que o **utimbuf** estrutura para usar o tipo de tempo de 32 bits, tornando-o equivalente ao **__utimbuf32**.

**_futime64**, que usa o **__utimbuf64** estrutura, que pode ler e modificar datas de arquivo por meio do 23:59:59, 31 de dezembro de 3000, a UTC; enquanto uma chamada para **_futime32** falhará se a data em que o arquivo é mais tarde do que 23:59:59 18 de janeiro de 2038, UTC. Meia-noite de 1º de janeiro de 1970 é o limite inferior do intervalo de datas para essas funções.

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

### <a name="input-crtfutimecinput"></a>Entrada: crt_futime.c_input

```Input
Arbitrary file contents.
```

### <a name="sample-output"></a>Saída de Exemplo

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

## <a name="see-also"></a>Consulte também

[Gerenciamento de Tempo](../../c-runtime-library/time-management.md)<br/>
