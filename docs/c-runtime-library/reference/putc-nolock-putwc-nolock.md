---
title: "_putc_nolock, _putwc_nolock | Microsoft Docs"
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
  - "_putc_nolock"
  - "_putwc_nolock"
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
  - "_puttc_nolock"
  - "puttc_nolock"
  - "putwc_nolock"
  - "_putwc_nolock"
  - "_putc_nolock"
  - "putc_nolock"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função puttc_nolock"
  - "Função putc_nolock"
  - "Função _putc_nolock"
  - "fluxos, gravando caracteres em"
  - "caracteres, gravar"
  - "Função putwc_nolock"
  - "Função _puttc_nolock"
  - "Função _putwc_nolock"
ms.assetid: 3cfc7f21-c9e8-4b7f-b0fb-af0d4d85e7e1
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _putc_nolock, _putwc_nolock
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Grava um caractere em um fluxo sem bloqueio do thread.  
  
## Sintaxe  
  
```  
  
int _putc_nolock(   intc,   FILE*stream);wint_t _putwc_nolock(   wchar_tc,   FILE*stream);  
```  
  
#### Parâmetros  
 `c`  
 Caracteres a serem gravados.  
  
 `stream`  
 Ponteiro para o **arquivo** estrutura.  
  
## Valor de retorno  
 Consulte **putc, putwc**.  
  
## Comentários  
 `_putc_nolock` e `_putwc_nolock` são idênticas às versões sem o **NOLOCK** sufixo exceto que eles não são protegidos contra interferência por outros threads. Eles podem ser mais rápidos porque eles não incorrem na sobrecarga de bloqueio de outros threads. Use essas funções somente em contextos de thread\-safe, como aplicativos de thread único ou onde o escopo de chamada já manipula o isolamento de thread.  
  
 `_putwc_nolock` é a versão de caractere largo do `_putc_nolock`; as duas funções tenham comportamento idêntico quando o fluxo é aberto no modo ANSI.`_putc_nolock` atualmente não suporta a saída em um fluxo UNICODE.  
  
### Mapeamentos de rotina de texto genérico  
  
|Rotina TCHAR. h|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_puttc_nolock`|`_putc_nolock`|`_putc_nolock`|**putwc\_nolock**|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_putc_nolock`|\< stdio \>|  
|`_putwc_nolock`|\< stdio \> ou \< WCHAR \>|  
  
 Não há suporte para o console no [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos. Os identificadores de fluxo padrão que estão associados com o console —`stdin`, `stdout`, e `stderr`— devem ser redirecionados para funções de tempo de execução C podem usá\-los em [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos. Para obter informações de compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Libraries  
 Todas as versões do [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
  
```  
// crt_putc_nolock.c  
/* This program uses putc to write buffer  
 * to a stream. If an error occurs, the program  
 * stops before writing the entire buffer.  
 */  
  
#include <stdio.h>  
  
int main( void )  
{  
   FILE *stream;  
   char *p, buffer[] = "This is the line of output\n";  
   int  ch;  
  
   ch = 0;  
   /* Make standard out the stream and write to it. */  
   stream = stdout;  
   for( p = buffer; (ch != EOF) && (*p != '\0'); p++ )  
      ch = _putc_nolock( *p, stream );  
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
 [getc, getwc](../../c-runtime-library/reference/getc-getwc.md)