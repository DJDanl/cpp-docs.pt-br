---
title: "getc, getwc | Microsoft Docs"
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
  - "getwc"
  - "getc"
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
  - "_gettc"
  - "getwc"
  - "_gettchar"
  - "getc"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _gettc"
  - "caracteres, lendo"
  - "Função getc"
  - "Função gettc"
  - "Função getwc"
  - "Função getwchar"
  - "lendo caracteres de fluxos"
  - "fluxos, lendo caracteres de"
ms.assetid: 354ef514-d0c7-404b-92f5-995f6a834bb3
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# getc, getwc
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Lê um caractere de um fluxo.  
  
## Sintaxe  
  
```  
int getc(   
   FILE *stream   
);  
wint_t getwc(   
   FILE *stream   
);  
```  
  
#### Parâmetros  
 `stream`  
 Fluxo de entrada.  
  
## Valor de retorno  
 Retorna a leitura de caracteres.  Para indicar um erro de leitura ou uma condição de participante de Arquivo, retorna `EOF`de `getc` , e retorna `WEOF`de `getwc` .  Para `getc`, use `ferror` ou `feof` para verificar para um erro ou a fim de arquivo.  Se `stream` é `NULL`, `getc` e `getwc` invoca o manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução for permitida continuar, essas funções `EOF` de retorno \(ou `WEOF` para`getwc`\) e `errno` definido como `EINVAL`.  
  
 Para obter mais informações sobre esses e outros códigos de erro, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 Cada rotina ler um único caractere de um arquivo na posição atual e incrementa o ponteiro de arquivo associado \(se definido\) para apontar para o próximo caractere.  O arquivo é associado a `stream`.  
  
 Essas funções bloqueiam o thread de chamada e, portanto, são thread\-safe.  Para uma versão sem bloqueio, consulte [\_getc\_nolock, \_getwc\_nolock](../../c-runtime-library/reference/getc-nolock-getwc-nolock.md).  
  
 As observações específicas da rotina são as seguintes:  
  
|Rotina|Comentários|  
|------------|-----------------|  
|`getc`|Mesmo que `fgetc`, mas implementado como uma função e como uma macro.|  
|`getwc`|Versão de caracteres largos de `getc`.  Lê um caracteres multibyte ou um caractere largo de acordo com o que `stream` está aberto no modo de texto ou no modo binário.|  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_gettc`|`getc`|`getc`|`getwc`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`getc`|\<stdio.h\>|  
|`getwc`|\<stdio.h\> ou \<wchar.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_getc.c  
// Use getc to read a line from a file.  
  
#include <stdio.h>  
  
int main()  
{  
    char buffer[81];  
    int i, ch;  
    FILE* fp;  
  
    // Read a single line from the file "crt_getc.txt".   
  
    fopen_s(&fp, "crt_getc.txt", "r");  
    if (!fp)  
    {  
       printf("Failed to open file crt_getc.txt.\n");  
       exit(1);  
    }  
  
    for (i = 0; (i < 80) && ((ch = getc(fp)) != EOF)  
                         && (ch != '\n'); i++)  
    {  
        buffer[i] = (char) ch;  
    }  
  
    // Terminate string with a null character   
    buffer[i] = '\0';  
    printf( "Input was: %s\n", buffer);  
  
    fclose(fp);  
}  
```  
  
## Entrada: crt\_getc.txt  
  
```  
Line one.  
Line two.  
```  
  
### Saída  
  
```  
Input was: Line one.  
```  
  
## Equivalência do .NET Framework  
  
-   [System::IO::StreamReader::Read](https://msdn.microsoft.com/en-us/library/system.io.streamreader.read.aspx)  
  
-   [System::Console::Read](https://msdn.microsoft.com/en-us/library/system.console.read.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fgetc, fgetwc](../Topic/fgetc,%20fgetwc.md)   
 [\_getch, \_getwch](../Topic/_getch,%20_getwch.md)   
 [putc, putwc](../../c-runtime-library/reference/putc-putwc.md)   
 [ungetc, ungetwc](../../c-runtime-library/reference/ungetc-ungetwc.md)