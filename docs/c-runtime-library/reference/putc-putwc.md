---
title: "putc, putwc | Microsoft Docs"
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
  - "putwc"
  - "putc"
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
  - "_puttc"
  - "putwc"
  - "putc"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "fluxos, gravando caracteres em"
  - "caracteres, gravar"
  - "Função putwc"
  - "Função putc"
  - "Função _puttc"
  - "Função puttc"
ms.assetid: a37b2e82-9d88-4565-8190-ff8d04c0ddb9
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# putc, putwc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Grava um caractere em um fluxo.  
  
## Sintaxe  
  
```  
  
int  
putc(  
   int  
c  
,  
   FILE  
*  
stream  
);  
wint_t  
putwc(  
   wchar_t  
c  
,  
   FILE  
*  
stream  
);  
  
```  
  
#### Parâmetros  
 `c`  
 Caracteres a serem gravados.  
  
 `stream`  
 Ponteiro para **arquivo** estrutura.  
  
## Valor de retorno  
 Retorna o caractere escrito. Para indicar um erro ou condição de fim de arquivo, `putc` e `putchar` retornar `EOF`; `putwc` e `putwchar` retornar **WEOF**. Para todas as rotinas de quatro, use [ferror](../../c-runtime-library/reference/ferror.md) ou [feof](../../c-runtime-library/reference/feof.md) para verificar se há um erro ou o final do arquivo. Se passado um ponteiro nulo para `stream`, o manipulador de parâmetro inválido é invocado, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornam `EOF` ou **WEOF** e defina `errno` para `EINVAL`.  
  
 Consulte [doserrno, errno, sys\_errlist e sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) para obter mais informações sobre esses e outros, códigos de erro.  
  
## Comentários  
 O `putc` rotina grava o único caractere `c` à saída `stream` na posição atual. Qualquer inteiro pode ser passado para `putc`, mas somente os 8 bits inferiores são gravados. O `putchar` rotina é idêntica ao **putc \(** `c`**, stdout\)**.   Para cada rotina, se ocorrer um erro de leitura, o indicador de erro para o fluxo é definido.`putc` e `putchar` são semelhantes às `fputc` e `_fputchar`, respectivamente, mas são implementadas como funções e macros \(consulte [escolher entre funções e Macros](../../c-runtime-library/recommendations-for-choosing-between-functions-and-macros.md)\).`putwc` e `putwchar` são versões de caractere largo de `putc` e `putchar`, respectivamente.`putwc` e `putc` tenham comportamento idêntico quando o fluxo é aberto no modo ANSI.`putc` atualmente não suporta a saída em um fluxo UNICODE.  
  
 As versões com o **NOLOCK** sufixo são idênticas, exceto que eles não são protegidos contra interferência por outros threads. Para obter mais informações, consulte **putc\_nolock, putwc\_nolock**.  
  
### Mapeamentos de rotina de texto genérico  
  
|TCHAR. Rotina H|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_puttc`|`putc`|`putc`|**putwc**|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`putc`|\< stdio \>|  
|`putwc`|\< stdio \> ou \< WCHAR \>|  
  
 Não há suporte para o console no [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos. Os identificadores de fluxo padrão que estão associados com o console —`stdin`, `stdout`, e `stderr`— devem ser redirecionados para funções de tempo de execução C podem usá\-los em [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)] aplicativos. Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Libraries  
 Todas as versões do [bibliotecas de tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
  
```  
// crt_putc.c  
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
      ch = putc( *p, stream );  
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