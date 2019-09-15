---
title: _read
ms.date: 02/13/2019
api_name:
- _read
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
- _read
helpviewer_keywords:
- data [CRT]
- _read function
- read function
- data [C++], reading
- reading data [C++]
- files [C++], reading
ms.assetid: 2ce9c433-57ad-47fe-9ac1-4a7d4c883d30
ms.openlocfilehash: 32238923aeef14230f68def15e27c676753faf61
ms.sourcegitcommit: f19474151276d47da77cdfd20df53128fdcc3ea7
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2019
ms.locfileid: "70949541"
---
# <a name="_read"></a>_read

Lê dados de um arquivo.

## <a name="syntax"></a>Sintaxe

```C
int _read(
   int const fd,
   void * const buffer,
   unsigned const buffer_size
);
```

### <a name="parameters"></a>Parâmetros

*fd*<br/>
Descritor de arquivo que se refere ao arquivo aberto.

*buffer*<br/>
Local de armazenamento de dados.

*buffer_size*<br/>
Número máximo de bytes a serem lidos.

## <a name="return-value"></a>Valor de retorno

**_read** retorna o número de bytes lidos, que pode ser menor que *buffer_size* se houver menos de *buffer_size* bytes restantes no arquivo ou se o arquivo tiver sido aberto no modo de texto. No modo de texto, cada par `\r\n` retorno de carro-alimentação de linha é substituído por um caractere `\n`de alimentação de linha única. Somente o caractere de alimentação de linha única é contado no valor de retorno. A substituição não afeta o ponteiro do arquivo.

Se a função tentar ler o final do arquivo, ela retornará 0. Se *FD* não for válido, o arquivo não está aberto para leitura ou o arquivo está bloqueado, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, a função retornará-1 e definirá **errno** como **EBADF**.

Se o *buffer* for **nulo**ou se *buffer_size* > **INT_MAX**, o manipulador de parâmetro inválido será invocado. Se a execução puder continuar, a função retornará-1 e **errno** será definida como **EINVAL**.

Para obter mais informações sobre este e outros códigos retornados, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

A função **_read** lê um máximo de *buffer_size* bytes no *buffer* do arquivo associado ao *FD*. A operação de leitura começa na posição atual do ponteiro de arquivo associado ao arquivo em questão. Após a operação de leitura, o ponteiro do arquivo aponta para o próximo caractere não lido.

Se o arquivo tiver sido aberto no modo de texto, a leitura será encerrada quando **_read** encontrar um caractere CTRL + Z, que é tratado como um indicador de fim de arquivo. Use [_lseek](lseek-lseeki64.md) para limpar o indicador de fim do arquivo.

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
   int fh, bytesread;
   unsigned int nbytes = 60000;

   /* Open file for input: */
   if ( _sopen_s( &fh, "crt_read.txt", _O_RDONLY, _SH_DENYNO, 0 ))
   {
      perror( "open failed on input file" );
      exit( 1 );
   }

   /* Read in input: */
   if (( bytesread = _read( fh, buffer, nbytes )) <= 0 )
      perror( "Problem reading file" );
   else
      printf( "Read %u bytes from file\n", bytesread );

   _close( fh );
}
```

### <a name="input-crt_readtxt"></a>Entrada: crt_read.txt

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
