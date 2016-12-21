---
title: "fputc, fputwc | Microsoft Docs"
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
  - "fputc"
  - "fputwc"
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
  - "fputc"
  - "fputwc"
  - "_fputtc"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _fputtc"
  - "Função fputc"
  - "Função fputtc"
  - "Função fputwc"
  - "fluxos, gravando caracteres em"
ms.assetid: 5a0a593d-43f4-4fa2-a401-ec4e23de4d2f
caps.latest.revision: 20
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# fputc, fputwc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Grava um caractere em um fluxo.  
  
## Sintaxe  
  
```  
int fputc(  
   int c,  
   FILE *stream   
);  
wint_t fputwc(  
   wchar_t c,  
   FILE *stream   
);  
```  
  
#### Parâmetros  
 `c`  
 Caractere a ser gravado.  
  
 `stream`  
 Ponteiro a estrutura de `FILE` .  
  
## Valor de retorno  
 Cada uma dessas funções retorna o caractere escrito.  Para `fputc`, um valor de retorno de `EOF` indica um erro.  No caso de `fputwc`, um valor de retorno de `WEOF` indica um erro.  Se `stream` for `NULL`, essas funções chamarão o manipulador de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, elas retornarão `EOF` e definirão `errno` como `EINVAL`.  
  
 Para obter mais informações sobre esses e outros códigos de erro, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 Cada uma dessas funções grava o caractere único `c` a um arquivo na posição indicada pelo indicador de posição associado do arquivo \(se definido\) e avança o indexador conforme apropriado.  No caso de `fputc` e de `fputwc`, o arquivo é associado com `stream`*.* Se o arquivo não puder suportar solicitações de posicionamento ou tiver sido aberto em modo de anexação, o caractere é acrescentado ao final de fluxo.  
  
 As duas funções se comportam de maneira idêntica, se o fluxo estiver aberto no modo de ANSI.  `fputc` não tem suporte para saída em um fluxo UNICODE.  
  
 As versões com o sufixo `_nolock` são idênticas, exceto pelo fato de que não são protegidas contra interferência de outros threads.  Para obter mais informações, consulte[\_fputc\_nolock, \_fputwc\_nolock](../../c-runtime-library/reference/fputc-nolock-fputwc-nolock.md).  
  
 As observações específicas da rotina são as seguintes:  
  
|Rotina|Comentários|  
|------------|-----------------|  
|`fputc`|Equivalente a `putc`, mas somente implementado como uma função, em vez de como uma função e uma macro.|  
|`fputwc`|Versão de caracteres largos de `fputc`.  Grava `c` como um caractere de multibyte ou um caractere largo, de acordo com o modo em que `stream` é aberto \- modo de texto ou modo binário.|  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_fputtc`|`fputc`|`fputc`|`fputwc`|  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`fputc`|\<stdio.h\>|  
|`fputwc`|\<stdio.h\> ou \<wchar.h\>|  
  
 O console não tem suporte em aplicativos do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  Os manipuladores de fluxo padrão associados ao console — `stdin`, `stdout` e `stderr` — devem ser redirecionados antes que as funções de tempo de execução do C possam utilizá\-los em aplicativos do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_fputc.c  
// This program uses fputc  
// to send a character array to stdout.  
  
#include <stdio.h>  
  
int main( void )  
{  
   char strptr1[] = "This is a test of fputc!!\n";  
   char *p;  
  
   // Print line to stream using fputc.   
   p = strptr1;  
   while( (*p != '\0') && fputc( *(p++), stdout ) != EOF ) ;  
  
}  
```  
  
  **Esse é um teste de fputc\!\!**   
## Equivalência do .NET Framework  
  
-   [System::IO::StreamWriter::Write](https://msdn.microsoft.com/en-us/library/system.io.streamwriter.write.aspx)  
  
-   [System::Console::Write](https://msdn.microsoft.com/en-us/library/system.console.write.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fgetc, fgetwc](../Topic/fgetc,%20fgetwc.md)   
 [putc, putwc](../../c-runtime-library/reference/putc-putwc.md)