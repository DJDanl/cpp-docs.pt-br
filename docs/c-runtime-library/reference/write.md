---
title: _write
ms.date: 4/2/2020
api_name:
- _write
- _o__write
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
- _write
helpviewer_keywords:
- _write function
- write function
- files [C++], writing to
ms.assetid: 7b868c33-766f-4e1a-95a7-e8d25f0604c4
ms.openlocfilehash: a616df570d266c335337d897da59a2a0ec69b40e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81367392"
---
# <a name="_write"></a>_write

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

*Fd*<br/>
O descritor de arquivo do arquivo em que os dados são gravados.

*Buffer*<br/>
Dados a serem gravados.

*contagem*<br/>
Quantidade de bytes.

## <a name="return-value"></a>Valor retornado

Se for bem sucedido, **_write** retorna o número de bytes escritos. Se o espaço real restante no disco for menor do que o tamanho do buffer, a função está tentando gravar no disco, **_write** falhar e não liberar nenhum dos conteúdos do buffer para o disco. Um valor de retorno de -1 indica um erro. Se parâmetros inválidos forem passados, essa função invocará o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução for permitida, a função retorna -1 e **errno** é definida como um dos três valores: **EBADF**, o que significa que o descritor de arquivo é inválido ou o arquivo não é aberto para gravação; **ENOSPC**, o que significa que não há espaço suficiente no dispositivo para a operação; ou **EINVAL,** o que significa que *buffer* era um ponteiro nulo ou que uma *contagem* ímpar de bytes foi passada para ser escrita para um arquivo no modo Unicode.

Para obter mais informações sobre esses e outros códigos de devolução, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).

Se o arquivo for aberto no modo texto, cada caractere de alimentação de linha será substituído por um par de feed de linha de retorno de transporte na saída. A substituição não afeta o valor de retorno.

Quando o arquivo é aberto no modo de tradução Unicode — por exemplo, se *fd* for aberto usando **_open** ou **_sopen** e um parâmetro de modo que inclua **_O_WTEXT**, **_O_U16TEXT**ou **_O_U8TEXT**, ou se for aberto usando **fopen** e um parâmetro de modo que inclui **ccs=UNICODE**, **ccs=UTF-16LE**, ou **ccs=UTF-8**, ou se o modo for alterado para um modo de tradução Unicode usando **_setmode**-*buffer* é interpretado como um ponteiro para um conjunto de **wchar_t** que contém **UTF-16** Tentar gravar uma quantidade ímpar de bytes nesse modo gera um erro de validação de parâmetro.

## <a name="remarks"></a>Comentários

A **função _write** grava bytes de *contagem* de *buffer* no arquivo associado ao *fd*. A operação de gravação começa na posição atual do ponteiro de arquivo (se houver) associado ao arquivo em questão. Se o arquivo estiver aberto para anexação, a operação começa no final do arquivo. Após a operação de gravação, o ponteiro do arquivo é aumentado pelo número de bytes escritos.

Ao escrever para arquivos abertos no modo texto, **_write** trata um caractere CTRL+Z como o final lógico do arquivo. Ao escrever para um dispositivo, **_write** trata um caractere CTRL+Z no buffer como um exterminador de saída.

Por padrão, o estado global desta função é escopo para o aplicativo. Para mudar isso, consulte [Estado Global no CRT](../global-state.md).

## <a name="requirements"></a>Requisitos

|Rotina|Cabeçalho necessário|
|-------------|---------------------|
|**_write**|\<io.h>|

Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).

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
            // An unrelated error occurred
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

## <a name="see-also"></a>Confira também

[E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)<br/>
[fwrite](fwrite.md)<br/>
[_open, _wopen](open-wopen.md)<br/>
[_read](read.md)<br/>
[_setmode](setmode.md)<br/>
