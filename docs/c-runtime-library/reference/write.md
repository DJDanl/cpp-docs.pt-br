---
title: _write
ms.date: 11/04/2016
apiname:
- _write
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
- _write
helpviewer_keywords:
- _write function
- write function
- files [C++], writing to
ms.assetid: 7b868c33-766f-4e1a-95a7-e8d25f0604c4
ms.openlocfilehash: b3fa53b21d4ea23c5f8e59de673f4074deedb505
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50519243"
---
# <a name="write"></a>_write

Grava dados em um arquivo.

## <a name="syntax"></a>Sintaxe

```C
int _write(
   int fd,
   const void *buffer,
   unsigned int count
);
```

### <a name="parameters"></a>Parâmetros

*fd*<br/>
O descritor de arquivo do arquivo em que os dados são gravados.

*buffer*<br/>
Dados a serem gravados.

*count*<br/>
Quantidade de bytes.

## <a name="return-value"></a>Valor de retorno

Se for bem-sucedido, **Write** retorna o número de bytes gravados. Se o espaço restante no disco for menor que o tamanho do buffer em que a função está tentando gravar no disco **Write** falhar e libera o conteúdo do buffer no disco. Um valor de retorno de -1 indica um erro. Se parâmetros inválidos forem passados, essa função invocará o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, a função retornará -1 e **errno** é definido como um dos três valores: **EBADF**, o que significa que o descritor de arquivo é inválido ou o arquivo não está aberto para gravação; **ENOSPC**, que significa que não há suficiente espaço disponível no dispositivo para a operação; ou **EINVAL**, o que significa que *buffer* era um ponteiro nulo ou que indefinido *contagem* de bytes foi passada para ser gravado em um arquivo no modo Unicode.

Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Se o arquivo é aberto no modo de texto, cada caractere de avanço de linha será substituído com um retorno de carro - alimentação de linha par na saída. Essa substituição não afeta o valor retornado.

Quando o arquivo é aberto no modo de conversão de Unicode – por exemplo, se *fd* é aberto usando **Open** ou **sopen** e um parâmetro de modo que inclua **_O_ WTEXT**, **_O_U16TEXT**, ou **_O_U8TEXT**, ou se ele for aberto usando **fopen** e um parâmetro de modo que inclua **ccs = UNICODE**, **ccs = UTF-16LE**, ou **ccs = UTF-8**, ou se o modo for alterado para um modo de translação Unicode usando **setmode**—*buffer* é interpretado como um ponteiro para uma matriz de **wchar_t** que contém **UTF-16** dados. Tentar gravar uma quantidade ímpar de bytes nesse modo gera um erro de validação de parâmetro.

## <a name="remarks"></a>Comentários

O **Write** função gravações *contagem* bytes do *buffer* para o arquivo associado *fd*. A operação de gravação começa na posição atual do ponteiro de arquivo (se houver) associado ao arquivo em questão. Se o arquivo estiver aberto para anexação, a operação começa no final do arquivo. Após a operação de gravação, o ponteiro do arquivo aumenta de acordo com a quantidade de bytes gravados.

Ao gravar em arquivos abertos no modo de texto **Write** trata um caractere CTRL + Z como o final do arquivo lógico. Ao gravar em um dispositivo **Write** considera um caractere CTRL + Z no buffer como terminador de saída.

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_write**|\<io.h>|

Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

## <a name="example"></a>Exemplo

```C
// crt__write.c
//
// This program opens a file for output and uses _write to write
// some bytes to the file.

#include <io.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <share.h>

char buffer[] = "This is a test of '_write' function";

int main( void )
{
   int         fileHandle = 0;
   unsigned    bytesWritten = 0;

   if ( _sopen_s(&fileHandle, "write.o", _O_RDWR | _O_CREAT,
                  _SH_DENYNO, _S_IREAD | _S_IWRITE) )
      return -1;

   if (( bytesWritten = _write( fileHandle, buffer, sizeof( buffer ))) == -1 )
   {
      switch(errno)
      {
         case EBADF:
            perror("Bad file descriptor!");
            break;
         case ENOSPC:
            perror("No space left on device!");
            break;
         case EINVAL:
            perror("Invalid parameter: buffer was NULL!");
            break;
         default:
            // An unrelated error occured
            perror("Unexpected error!");
      }
   }
   else
   {
      printf_s( "Wrote %u bytes to file.\n", bytesWritten );
   }
   _close( fileHandle );
}
```

```Output
Wrote 36 bytes to file.
```

## <a name="see-also"></a>Consulte também

[E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)<br/>
[fwrite](fwrite.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_read](read.md)<br/>
[_setmode](setmode.md)<br/>
