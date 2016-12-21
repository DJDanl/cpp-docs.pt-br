---
title: "_fgetchar, _fgetwchar | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_fgetchar"
  - "_fgetwchar"
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
  - "fgetwchar"
  - "_fgettchar"
  - "_fgetchar"
  - "_fgetwchar"
  - "fgettchar"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _fgetchar"
  - "Função _fgettchar"
  - "Função _fgetwchar"
  - "Função fgetchar"
  - "Função fgettchar"
  - "Função fgetwchar"
  - "entrada padrão, lendo de"
ms.assetid: 8bce874c-701a-41a3-b1b2-feff266fb5b9
caps.latest.revision: 16
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _fgetchar, _fgetwchar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Lê um caractere de `stdin`.  
  
## Sintaxe  
  
```  
int _fgetchar( void );  
wint_t _fgetwchar( void );  
```  
  
## Valor de retorno  
 `_fgetchar` retorna a leitura de caractere como um `int` ou retorna `EOF` para indicar um erro ou fim de arquivo.  **\_**`fgetwchar` retorna, como [wint\_t](../../c-runtime-library/standard-types.md), o caractere largo que corresponde à leitura de caractere ou retorna `WEOF` para indicar um erro ou fim de arquivo.  Para ambas as funções, use `feof` ou `ferror` para distinguir entre um erro e uma condição de fim de arquivo.  
  
## Comentários  
 Essas funções leem um único caractere de `stdin`.  A função incrementa o ponteiro do arquivo associado \(se definido\) para indicar o próximo caractere.  Se o fluxo estiver no final do arquivo, o indicador de fim de arquivo para o fluxo é definido.  
  
 `_fgetchar` equivale a `fgetc( stdin )`.  Também é equivalente a `getchar`, mas somente implementado como função, em vez de uma função e uma macro.  `_fgetwchar` é a versão de caracteres largos de `_fgetchar`.  
  
 Essas funções não são compatíveis com o padrão ANSI.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_fgettchar`|`_fgetchar`|`_fgetchar`|`_fgetwchar`|  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`_fgetchar`|\<stdio.h\>|  
|`_fgetwchar`|\<stdio.h\> ou \<wchar.h\>|  
  
 O console não tem suporte em aplicativos do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  Os manipuladores de fluxo padrão associados ao console — `stdin`, `stdout` e `stderr` — devem ser redirecionados antes que as funções de tempo de execução do C possam utilizá\-los em aplicativos do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_fgetchar.c  
// This program uses _fgetchar to read the first  
// 80 input characters (or until the end of input)  
// and place them into a string named buffer.  
//  
  
#include <stdio.h>  
#include <stdlib.h>  
  
int main( void )  
{  
   char buffer[81];  
   int  i, ch;  
  
   // Read in first 80 characters and place them in "buffer":  
   ch = _fgetchar();  
   for( i=0; (i < 80 ) && ( feof( stdin ) == 0 ); i++ )  
   {  
      buffer[i] = (char)ch;  
      ch = _fgetchar();  
   }  
  
   // Add null to end string   
   buffer[i] = '\0';  
   printf( "%s\n", buffer );  
}  
```  
  
  **`Linha um. Linha dois.`Linha um.**  
**Linha dois.**   
## Equivalência do .NET Framework  
  
-   [System::IO::StreamReader::Read](https://msdn.microsoft.com/en-us/library/system.io.streamreader.read.aspx)  
  
-   [System::Console::Read](https://msdn.microsoft.com/en-us/library/system.console.read.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fputc, fputwc](../../c-runtime-library/reference/fputc-fputwc.md)   
 [getc, getwc](../../c-runtime-library/reference/getc-getwc.md)