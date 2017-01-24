---
title: "_write | Microsoft Docs"
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
  - "_write"
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
apitype: "DLLExport"
f1_keywords: 
  - "_write"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _write"
  - "Arquivos  [C++], gravando em"
  - "Função write"
ms.assetid: 7b868c33-766f-4e1a-95a7-e8d25f0604c4
caps.latest.revision: 21
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _write
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Grava dados em um arquivo.  
  
## Sintaxe  
  
```  
int _write(    int fd,    const void *buffer,    unsigned int count  );  
```  
  
#### Parâmetros  
 `fd`  
 O descritor de arquivo do arquivo em que os dados são gravados.  
  
 `buffer`  
 Dados a serem gravados.  
  
 `count`  
 Quantidade de bytes.  
  
## Valor de retorno  
 Em caso de êxito, `_write` retorna a quantidade de bytes gravados.  Se o espaço restantes em disco for menor que o tamanho do buffer que a função está tentando gravar no disco, `_write` falha e não libera o conteúdo do buffer para o disco.  Um valor retornado de \-1 indica que há um erro.  Se parâmetros inválidos forem enviados, essa função invoca o manipulador de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução tiver permissão para continuar, a função retorna \-1 e `errno` é definido como um de três valores: `EBADF`, que significa que o descritor de arquivo é inválido ou que o arquivo não está aberto para gravação; `ENOSPC`, que significa que não há espaço suficiente no dispositivo para a operação; ou `EINVAL`, que significa que `buffer` era um ponteiro nulo ou que uma quantidade `count` ímpar de bytes foi apresentada para edição de um arquivo no modo Unicode.  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [errno, \_doserrno, \_sys\_errlist e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
 Se o arquivo for aberto no modo de texto, cada caractere de avanço de linha será substituído por um par carro de retorno na saída.  Essa substituição não afeta o valor retornado.  
  
 Quando o arquivo é aberto no modo de conversão Unicode \(por exemplo, se `fd` for aberto com o uso de `_open` ou `_sopen` e um parâmetro de modo que inclua `_O_WTEXT`, `_O_U16TEXT` ou `_O_U8TEXT`, ou se ele for aberto com uso de `fopen` e um parâmetro de modo que inclua `ccs=UNICODE`, `ccs=UTF-16LE` ou `ccs=UTF-8` ou se o modo for alterado para um modo de conversão Unicode com o uso de `_setmode`\)`buffer` é interpretado como ponteiro para uma matriz de `wchar_t` que contém dados **UTF\-16**.  Tentar gravar uma quantidade ímpar de bytes nesse modo gera um erro de validação de parâmetro.  
  
## Comentários  
 A função `_write` grava `count` bytes de `buffer` no arquivo associado a `fd`.  A operação de gravação começa na posição atual do ponteiro de arquivo \(se houver\) associado ao arquivo em questão.  Se o arquivo estiver aberto para anexação, a operação começa no final do arquivo.  Após a operação de gravação, o ponteiro do arquivo aumenta de acordo com a quantidade de bytes gravados.  
  
 Ao gravar em arquivos abertos no modo de texto, `_write` considera um caractere CTRL\+Z como o fim lógico do arquivo.  Ao gravar em um dispositivo, `_write` considera um caractere CTRL\+Z no buffer como terminador de saída.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_write`|\<io.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
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
  
  **Gravou 36 bytes no arquivo.**   
## Consulte também  
 [E\/S de nível inferior](../../c-runtime-library/low-level-i-o.md)   
 [fwrite](../Topic/fwrite.md)   
 [\_open, \_wopen](../../c-runtime-library/reference/open-wopen.md)   
 [\_read](../Topic/_read.md)   
 [\_setmode](../../c-runtime-library/reference/setmode.md)