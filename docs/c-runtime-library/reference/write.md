---
title: _write | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: _write
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
apitype: DLLExport
f1_keywords: _write
dev_langs: C++
helpviewer_keywords:
- _write function
- write function
- files [C++], writing to
ms.assetid: 7b868c33-766f-4e1a-95a7-e8d25f0604c4
caps.latest.revision: "21"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: cc9adfe9dc61062fa406791904ea15bb7aade242
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="write"></a>_write
Grava dados em um arquivo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _write(  
   int fd,  
   const void *buffer,  
   unsigned int count   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `fd`  
 O descritor de arquivo do arquivo em que os dados são gravados.  
  
 `buffer`  
 Dados a serem gravados.  
  
 `count`  
 Quantidade de bytes.  
  
## <a name="return-value"></a>Valor de retorno  
 Em caso de êxito, `_write` retorna a quantidade de bytes gravados. Se o espaço restantes em disco for menor que o tamanho do buffer que a função está tentando gravar no disco, `_write` falha e não libera o conteúdo do buffer para o disco. Um valor de retorno de -1 indica um erro. Se parâmetros inválidos forem passados, essa função invocará o manipulador de parâmetro inválido, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução tiver permissão para continuar, a função retorna -1 e `errno` é definido como um de três valores: `EBADF`, que significa que o descritor de arquivo é inválido ou que o arquivo não está aberto para gravação; `ENOSPC`, que significa que não há espaço suficiente no dispositivo para a operação; ou `EINVAL`, que significa que `buffer` era um ponteiro nulo ou que uma quantidade `count` ímpar de bytes foi apresentada para edição de um arquivo no modo Unicode.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, _doserrno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
 Se o arquivo é aberto no modo de texto, cada caractere de avanço de linha será substituída por um retorno de carro - par de avanço de linha na saída. Essa substituição não afeta o valor retornado.  
  
 Quando o arquivo é aberto no modo de translação Unicode (por exemplo, se `fd` for aberto usando `_open` ou `_sopen` e um parâmetro de modo que inclua `_O_WTEXT`, `_O_U16TEXT` ou `_O_U8TEXT` ou se for aberto usando `fopen` e um parâmetro de modo que inclua `ccs=UNICODE`, `ccs=UTF-16LE` ou `ccs=UTF-8` ou se o modo for alterado para um modo de translação Unicode usando `_setmode`), `buffer` é interpretado como um ponteiro para uma matriz de `wchar_t` que contém dados **UTF-16**. Tentar gravar uma quantidade ímpar de bytes nesse modo gera um erro de validação de parâmetro.  
  
## <a name="remarks"></a>Comentários  
 A função `_write` grava `count` bytes de `buffer` no arquivo associado a `fd`. A operação de gravação começa na posição atual do ponteiro de arquivo (se houver) associado ao arquivo em questão. Se o arquivo estiver aberto para anexação, a operação começa no final do arquivo. Após a operação de gravação, o ponteiro do arquivo aumenta de acordo com a quantidade de bytes gravados.  
  
 Ao gravar em arquivos abertos no modo de texto, `_write` considera um caractere CTRL+Z como o fim lógico do arquivo. Ao gravar em um dispositivo, `_write` considera um caractere CTRL+Z no buffer como terminador de saída.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_write`|\<io.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="example"></a>Exemplo  
  
```  
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
 [E/S de nível inferior](../../c-runtime-library/low-level-i-o.md)   
 [fwrite](../../c-runtime-library/reference/fwrite.md)   
 [_open, _wopen](../../c-runtime-library/reference/open-wopen.md)   
 [_read](../../c-runtime-library/reference/read.md)   
 [_setmode](../../c-runtime-library/reference/setmode.md)