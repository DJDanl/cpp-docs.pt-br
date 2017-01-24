---
title: "_putchar_nolock, _putwchar_nolock | Microsoft Docs"
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
  - "_putchar_nolock"
  - "_putwchar_nolock"
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
  - "putwchar_nolock"
  - "_puttchar_nolock"
  - "_putchar_nolock"
  - "_putwchar_nolock"
  - "putchar_nolock"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _puttchar_nolock"
  - "Função putchar_nolock"
  - "caracteres, gravar"
  - "saída padrão, gravar"
  - "Função putwchar_nolock"
  - "Função _putchar_nolock"
  - "Função _putwchar_nolock"
  - "Função puttchar_nolock"
ms.assetid: 9ac68092-bfc3-4352-b486-c3e780220575
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _putchar_nolock, _putwchar_nolock
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Grava um caractere para **stdout** sem bloqueio do thread.  
  
## Sintaxe  
  
```  
  
int _putchar_nolock(   intc);wint_t _putwchar_nolock(   wchar_tc);  
```  
  
#### Parâmetros  
 `c`  
 Caracteres a serem gravados.  
  
## Valor de retorno  
 Consulte **putchar, putwchar**.  
  
## Comentários  
 **putchar\_nolock** e `_putwchar_nolock` são idênticas às versões sem o **NOLOCK** sufixo exceto que eles não são protegidos contra interferência por outros threads. Eles podem ser mais rápidos porque eles não incorrem na sobrecarga de bloqueio de outros threads. Use essas funções somente em contextos de thread\-safe, como aplicativos de thread único ou onde o escopo de chamada já manipula o isolamento de thread.  
  
### Mapeamentos de rotina de texto genérico  
  
|Rotina TCHAR. h|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_puttchar_nolock`|`_putchar_nolock`|`_putchar_nolock`|`_putwchar_nolock`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_putchar_nolock`|\< stdio \>|  
|`_putwchar_nolock`|\< stdio \> ou \< WCHAR \>|  
  
 Não há suporte para o console no [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos. Os identificadores de fluxo padrão que estão associados com o console —`stdin`, `stdout`, e `stderr`— devem ser redirecionados para funções de tempo de execução C podem usá\-los em [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos. Para obter informações de compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Libraries  
 Todas as versões do [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
  
```  
// crt_putchar_nolock.c  
/* This program uses putchar to write buffer  
 * to stdout. If an error occurs, the program  
 * stops before writing the entire buffer.  
 */  
  
#include <stdio.h>  
  
int main( void )  
{  
   FILE *stream;  
   char *p, buffer[] = "This is the line of output\n";  
   int  ch;  
  
   ch = 0;  
  
   for( p = buffer; (ch != EOF) && (*p != '\0'); p++ )  
      ch = _putchar_nolock( *p );  
}  
```  
  
## Saída  
  
```  
This is the line of output  
```  
  
## Equivalência do .NET Framework  
  
-   [System::IO::StreamWriter::Write](https://msdn.microsoft.com/en-us/library/system.io.streamwriter.write.aspx)  
  
-   [System::console::Write](https://msdn.microsoft.com/en-us/library/system.console.write.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fputc, fputwc](../../c-runtime-library/reference/fputc-fputwc.md)   
 [fgetc, fgetwc](../Topic/fgetc,%20fgetwc.md)