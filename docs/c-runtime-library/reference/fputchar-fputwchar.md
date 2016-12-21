---
title: "_fputchar, _fputwchar | Microsoft Docs"
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
  - "_fputchar"
  - "_fputwchar"
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
  - "fputtchar"
  - "_fputwchar"
  - "fputwchar"
  - "_fputtchar"
  - "fputchar"
  - "_fputchar"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _fputchar"
  - "Função _fputtchar"
  - "Função _fputwchar"
  - "Função fputchar"
  - "Função fputtchar"
  - "Função fputwchar"
  - "saída padrão, gravando em"
ms.assetid: b92ff600-a924-4f2b-b0e7-3097ee31bdff
caps.latest.revision: 15
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _fputchar, _fputwchar
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Grava um caractere em `stdout`.  
  
## Sintaxe  
  
```  
int _fputchar(  
   int c   
);  
wint_t _fputwchar(  
   wchar_t c   
);  
```  
  
#### Parâmetros  
 `c`  
 Caractere a ser gravado.  
  
## Valor de retorno  
 Cada uma dessas funções retorna o caractere escrito.  No caso de `_fputchar`, um valor de retorno de `EOF` indica um erro.  No caso de `_fputwchar`, um valor de retorno de `WEOF` indica um erro.  Se c for `NULL`, essas funções gerarão uma exceção de parâmetro inválido, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, elas retornarão `EOF`\(ou`WEOF`\) e definirão `errno` como `EINVAL`.  
  
 Para obter mais informações sobre esses e outros códigos de erro, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 Ambas as funções gravam o caractere único `c` em `stdout` e avançam o indicador quando apropriado.  `_fputchar` equivale a `fputc(``stdout )`.  Também é equivalente a `putchar`, mas somente implementado como função, em vez de uma função e uma macro.  Ao contrário de `fputc` e `putchar`, essas funções não são compatíveis com o padrão ANSI.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_fputtchar`|`_fputchar`|`_fputchar`|`_fputwchar`|  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`_fputchar`|\<stdio.h\>|  
|`_fputwchar`|\<stdio.h\> ou \<wchar.h\>|  
  
 O console não tem suporte em aplicativos do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  Os manipuladores de fluxo padrão associados ao console — `stdin`, `stdout` e `stderr` — devem ser redirecionados antes que as funções de tempo de execução do C possam utilizá\-los em aplicativos do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_fputchar.c  
// This program uses _fputchar  
// to send a character array to stdout.  
  
#include <stdio.h>  
  
int main( void )  
{  
    char strptr[] = "This is a test of _fputchar!!\n";  
    char *p = NULL;  
  
    // Print line to stream using _fputchar.   
    p = strptr;  
    while( (*p != '\0') && _fputchar( *(p++) ) != EOF )  
      ;  
}  
```  
  
  **Esse é um teste de \_fputchar\!\!**   
## Equivalência do .NET Framework  
  
-   [System::IO::StreamWriter::Write](https://msdn.microsoft.com/en-us/library/system.io.streamwriter.write.aspx)  
  
-   [System::Console::Write](https://msdn.microsoft.com/en-us/library/system.console.write.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fgetc, fgetwc](../Topic/fgetc,%20fgetwc.md)   
 [putc, putwc](../../c-runtime-library/reference/putc-putwc.md)