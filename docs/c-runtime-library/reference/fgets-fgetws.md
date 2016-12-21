---
title: "fgets, fgetws | Microsoft Docs"
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
  - "fgets"
  - "fgetws"
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
  - "_fgetts"
  - "fgetws"
  - "fgets"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _fgetts"
  - "Função fgets"
  - "Função fgetts"
  - "Função fgetws"
  - "fluxos, obtendo cadeias de caracteres de"
  - "fluxos, lendo de"
ms.assetid: ad549bb5-df98-4ccd-a53f-95114e60c4fc
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# fgets, fgetws
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obter uma cadeia de caracteres de um fluxo.  
  
## Sintaxe  
  
```  
char *fgets(   
   char *str,  
   int n,  
   FILE *stream   
);  
wchar_t *fgetws(   
   wchar_t *str,  
   int n,  
   FILE *stream   
);  
```  
  
#### Parâmetros  
 `str`  
 Local para armazenamento de dados.  
  
 `n`  
 Número máximo de caracteres a serem lidos.  
  
 `stream`  
 Ponteiro a estrutura de `FILE` .  
  
## Valor de retorno  
 Cada uma dessas funções retorna `str`.  `NULL` é retornado para indicar um erro ou uma condição de participante de Arquivo.  Use `feof` ou `ferror` para determinar se um erro ocorreu.  Se `str` ou `stream` for um ponteiro nulo, ou `n` é menor ou igual a zero, essa função invoca o manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, `errno` será definido como `EINVAL` e a função retornará `NULL`.  
  
 Para obter mais informações sobre esses e outros códigos de erro, consulte [\_doserrno, errno, \_sys\_errlist, and \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 A função de `fgets` leu uma cadeia de caracteres do argumento de `stream` de entrada e armazená\-las em `str`.  os caracteres de leituras de`fgets` da posição atual do fluxo e de incluir o primeiro caractere de nova linha, ao final do fluxo, ou até que o número de caracteres são iguais a `n` – 1, o que vem primeiro.  O resultado armazenado em `str` é acrescentado com um caractere nulo.  O caractere de nova linha, se ler, é incluído na cadeia de caracteres.  
  
 `fgetws` é uma versão de caracteres largos de `fgets`.  
  
 `fgetws` ler o argumento `str` ampla de caracteres como uma cadeia de caracteres de multibyte\- caractere ou uma cadeia de caracteres de ampla caractere de acordo com o que `stream` está aberto no modo de texto ou no modo de binário, respectivamente.  Para obter mais informações sobre como usar os modos de texto e binários em Unicode e em vários stream\-I\/O, consulte [O modo de texto e binários de E\/S](../../c-runtime-library/text-and-binary-mode-file-i-o.md) e [Fluxo de E\/S Unicode nos modos de texto e binários](../../c-runtime-library/unicode-stream-i-o-in-text-and-binary-modes.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_fgetts`|`fgets`|`fgets`|`fgetws`|  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`fgets`|\<stdio.h\>|  
|`fgetws`|\<stdio.h\> ou \<wchar.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
```  
// crt_fgets.c  
// This program uses fgets to display  
// a line from a file on the screen.  
//  
  
#include <stdio.h>  
  
int main( void )  
{  
   FILE *stream;  
   char line[100];  
  
   if( fopen_s( &stream, "crt_fgets.txt", "r" ) == 0 )  
   {  
      if( fgets( line, 100, stream ) == NULL)  
         printf( "fgets error\n" );  
      else  
         printf( "%s", line);  
      fclose( stream );  
   }  
}  
```  
  
## Entrada: crt\_fgets.txt  
  
```  
Line one.  
Line two.  
```  
  
### Saída  
  
```  
Line one.  
```  
  
## Equivalência do .NET Framework  
  
-   [System::IO::StreamReader::ReadLine](https://msdn.microsoft.com/en-us/library/system.io.streamreader.readline.aspx)  
  
-   [System::IO::TextReader::ReadBlock](https://msdn.microsoft.com/en-us/library/system.io.textreader.readblock.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [fputs, fputws](../Topic/fputs,%20fputws.md)   
 [gets, \_getws](../../c-runtime-library/gets-getws.md)   
 [puts, \_putws](../Topic/puts,%20_putws.md)