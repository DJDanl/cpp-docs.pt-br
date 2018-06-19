---
title: _read | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
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
dev_langs:
- C++
helpviewer_keywords:
- data [CRT]
- _read function
- read function
- data [C++], reading
- reading data [C++]
- files [C++], reading
ms.assetid: 2ce9c433-57ad-47fe-9ac1-4a7d4c883d30
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 2c67ce8ac0e754bf3003b23c56cd1d3f428be903
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32405803"
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

**Leia** retorna o número de bytes lidos, que pode ser menor que *contagem* se houver menos de *contagem* bytes restantes no arquivo ou se o arquivo foi aberto no modo de texto, caso em que cada carro linha de retorno de alimentação par '\r\n' é substituída por um caractere de avanço de linha única '\n'. Apenas o caractere de avanço de linha único é contado no valor retornado. A substituição não afeta o ponteiro do arquivo.

Se a função tentar ler o final do arquivo, ela retornará 0. Se *fd* é não é válido, o arquivo não está aberto para leitura, ou o arquivo está bloqueado, o manipulador de parâmetro inválido é invocado, conforme descrito em [validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução é permitida para continuar, a função retornará -1 e conjuntos de **errno** para **EBADF**.

Se *buffer* for **NULL**, o manipulador do parâmetro inválido será invocado. Se a execução é permitida para continuar, a função retornará -1 e **errno** é definido como **EINVAL**.

Para obter mais informações sobre este e outros códigos retornados, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

## <a name="remarks"></a>Comentários

O **Read** função lê um máximo de *contagem* bytes em *buffer* do arquivo associado *fd*. A operação de leitura começa na posição atual do ponteiro de arquivo associado ao arquivo em questão. Após a operação de leitura, o ponteiro do arquivo aponta para o próximo caractere não lido.

Se o arquivo foi aberto no modo de texto, a leitura será encerrada quando **Read** encontra um caractere CTRL + Z, que é tratado como um indicador de fim de arquivo. Use [_lseek](lseek-lseeki64.md) para limpar o indicador de fim do arquivo.

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
