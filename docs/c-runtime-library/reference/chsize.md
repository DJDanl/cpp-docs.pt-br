---
title: "_chsize | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_chsize"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-stdio-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_chsize"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _chsize"
  - "Função chsize"
  - "Arquivos  [C++], alterando tamanho"
  - " (tamanho)"
  - " (tamanho), alterando o arquivo"
ms.assetid: b3e881c5-7b27-4837-a3d4-c51591ab10ff
caps.latest.revision: 21
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _chsize
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Altera o tamanho de um arquivo.  Uma versão mais segura estiver disponível; consulte [\_chsize\_s](../../c-runtime-library/reference/chsize-s.md).  
  
## Sintaxe  
  
```  
int _chsize(   
   int fd,  
   long size   
);  
```  
  
#### Parâmetros  
 `fd`  
 O descritor de Arquivo que faz referência a um arquivo aberto.  
  
 `size`  
 Novo comprimento do arquivo em bytes.  
  
## Valor de retorno  
 `_chsize` retorna o valor 0 se o tamanho do arquivo é modificado com êxito.  Um valor de retorno – 1 indica um erro: `errno` é definido como `EACCES` se o arquivo especificado é bloqueada no acesso a `EBADF` , se o arquivo especificado é somente leitura ou o descritor for inválido, a `ENOSPC` se nenhum espaço é deixado no dispositivo, ou a `EINVAL` se `size` é menor que zero.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função de `_chsize` estende ou trunca o arquivo associado com `fd` ao comprimento especificado por `size`.  O arquivo deve estar aberto em um modo que permite gravar.  Os caracteres nulos \(\\ “0 "\) são acrescentados se o arquivo é estendido.  Se o arquivo é truncado, todos os dados do final do arquivo reduzido ao tamanho original do arquivo serão perdidos.  
  
 Essa função valida seus parâmetros.  Se `size` é menor que zero ou `fd` é um descritor de arquivo incorreto, o manipulador inválido do parâmetro é chamado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|------------|--------------------------|------------------------|  
|`_chsize`|\<io.h\>|\<errno.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_chsize.c  
// This program uses _filelength to report the size  
// of a file before and after modifying it with _chsize.  
  
#include <io.h>  
#include <fcntl.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <stdio.h>  
#include <share.h>  
  
int main( void )  
{  
   int fh, result;  
   unsigned int nbytes = BUFSIZ;  
  
   // Open a file   
   if( _sopen_s( &fh, "data", _O_RDWR | _O_CREAT, _SH_DENYNO,  
                 _S_IREAD | _S_IWRITE ) == 0 )  
   {  
      printf( "File length before: %ld\n", _filelength( fh ) );  
      if( ( result = _chsize( fh, 329678 ) ) == 0 )  
         printf( "Size successfully changed\n" );  
      else  
         printf( "Problem in changing the size\n" );  
      printf( "File length after:  %ld\n", _filelength( fh ) );  
      _close( fh );  
   }  
}  
```  
  
  **Comprimento de Arquivo antes: 0**  
**Tamanho modificado com êxito**  
**Comprimento de Arquivo após:  329678**   
## Equivalência do .NET Framework  
  
-   [System::IO::Stream::SetLength](https://msdn.microsoft.com/en-us/library/system.io.stream.setlength.aspx)  
  
-   [System::IO::FileStream::SetLength](https://msdn.microsoft.com/en-us/library/system.io.filestream.setlength.aspx)  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)   
 [\_close](../Topic/_close.md)   
 [\_sopen, \_wsopen](../../c-runtime-library/reference/sopen-wsopen.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)