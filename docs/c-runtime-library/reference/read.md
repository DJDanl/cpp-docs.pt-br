---
title: _read
ms.date: 11/04/2016
apiname:
- _read
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
- api-ms-win-crt-stdio-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- _read
helpviewer_keywords:
- data [CRT]
- _read function
- read function
- data [C++], reading
- reading data [C++]
- files [C++], reading
ms.assetid: 2ce9c433-57ad-47fe-9ac1-4a7d4c883d30
ms.openlocfilehash: 8c43cbbc2681433bda02038ae73a827fad904835
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50658432"
---
# <a name="read"></a>_read

Lê dados de um arquivo.

## <a name="syntax"></a>Sintaxe

```C
int _read(
   int fd,
   void *buffer,
   unsigned int count
);
```

### <a name="parameters"></a>Parâmetros

*fd*<br/>
Descritor de arquivo que se refere ao arquivo aberto.

*buffer*<br/>
Local de armazenamento de dados.

*count*<br/>
O número máximo de bytes.

## <a name="return-value"></a>Valor de retorno

**Read** retorna o número de bytes lidos, que pode ser menor que *contagem* se houver menos *contagem* bytes deixado no arquivo ou se o arquivo foi aberto no modo de texto, caso em que cada carro retorno par '\r\n' de avanço de linha é substituída por um caractere de avanço de linha única '\n'. Apenas o caractere de avanço de linha único é contado no valor retornado. A substituição não afeta o ponteiro do arquivo.

Se a função tentar ler o final do arquivo, ela retornará 0. Se *fd* é não é válido, o arquivo não está aberto para leitura, ou o arquivo está bloqueado, o manipulador de parâmetro inválido será invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará -1 e definirá **errno** à **EBADF**.

Se *buffer* for **NULL**, o manipulador do parâmetro inválido será invocado. Se a execução puder continuar, a função retornará -1 e **errno** é definido como **EINVAL**.

Para obter mais informações sobre este e outros códigos retornados, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **Read** função lê um máximo de *contagem* bytes no *buffer* do arquivo associado *fd*. A operação de leitura começa na posição atual do ponteiro de arquivo associado ao arquivo em questão. Após a operação de leitura, o ponteiro do arquivo aponta para o próximo caractere não lido.

Se o arquivo foi aberto no modo de texto, a leitura termina quando **Read** encontrar um caractere CTRL + Z, que é tratado como um indicador de final de arquivo. Use [_lseek](lseek-lseeki64.md) para limpar o indicador de fim do arquivo.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_read**|\<io.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="libraries"></a>Libraries

Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).

## <a name="example"></a>Exemplo

```C
// crt_read.c
/* This program opens a file named crt_read.txt
* and tries to read 60,000 bytes from
* that file using _read. It then displays the
* actual number of bytes read.
*/

#include <fcntl.h>      /* Needed only for _O_RDWR definition */
#include <io.h>
#include <stdlib.h>
#include <stdio.h>
#include <share.h>

char buffer[60000];

int main( void )
{
   int fh;
   unsigned int nbytes = 60000, bytesread;

   /* Open file for input: */
   if( _sopen_s( &fh, "crt_read.txt", _O_RDONLY, _SH_DENYNO, 0 ) )
   {
      perror( "open failed on input file" );
      exit( 1 );
   }

   /* Read in input: */
   if( ( bytesread = _read( fh, buffer, nbytes ) ) <= 0 )
      perror( "Problem reading file" );
   else
      printf( "Read %u bytes from file\n", bytesread );

   _close( fh );
}
```

### <a name="input-crtreadtxt"></a>Entrada: crt_read.txt

```Input
Line one.
Line two.
```

### <a name="output"></a>Saída

```Output
Read 19 bytes from file
```

## <a name="see-also"></a>Consulte também

[E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)<br/>
[_creat, _wcreat](creat-wcreat.md)<br/>
[fread](fread.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_write](write.md)<br/>
