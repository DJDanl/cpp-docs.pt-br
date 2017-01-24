---
title: "gets_s, _getws_s | Microsoft Docs"
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
  - "_getws_s"
  - "gets_s"
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
  - "_getws_s"
  - "gets_s"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _getws_s"
  - "saturações de buffer"
  - "buffers, evitando saturações"
  - "buffers, saturações de buffer"
  - "Função gets_s"
  - "Função getws_s"
  - "linhas, obtendo"
  - "entrada padrão, lendo de"
  - "fluxos, obtendo linhas"
ms.assetid: 5880c36f-122c-4061-a1a5-aeeced6fe58c
caps.latest.revision: 29
caps.handback.revision: 27
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# gets_s, _getws_s
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém uma linha do fluxo de `stdin`.  Essas versões de [obtém o, \_getws](../../c-runtime-library/gets-getws.md) têm os aprimoramentos de segurança, conforme descrito em [Recursos de segurança no CRT](../Topic/Security%20Features%20in%20the%20CRT.md).  
  
## Sintaxe  
  
```  
char *gets_s(   
   char *buffer,  
   size_t sizeInCharacters  
);  
wchar_t *_getws_s(   
   wchar_t *buffer,  
   size_t sizeInCharacters  
);  
template <size_t size>  
char *gets_s(   
   char (&buffer)[size]  
); // C++ only  
template <size_t size>  
wchar_t *_getws_s(   
   wchar_t (&buffer)[size]  
); // C++ only  
```  
  
#### Parâmetros  
 \[saída\] `buffer`  
 Local de armazenamento de uma cadeia de caracteres de entrada.  
  
 \[entrada\] `sizeInCharacters`  
 O tamanho do buffer.  
  
## Valor de retorno  
 Retorna `buffer` se tiver êxito.  Um ponteiro de `NULL` indica um erro ou uma condição de fim de arquivo.  Use [ferror](../../c-runtime-library/reference/ferror.md) ou [feof](../../c-runtime-library/reference/feof.md) para determinar qual ocorreu.  
  
## Comentários  
 A função `gets_s` lê uma linha do fluxo de entrada padrão `stdin` e a armazena em `buffer`.  A linha consiste em todos os caracteres até, e incluindo, o primeiro caractere de nova linha \('\\n'\).  `gets_s` substitui o caractere de nova linha por um caractere nulo \(“\\0"\) antes de retornar a linha.  Por outro lado, a função de `fgets_s` retém o caractere de nova linha.  
  
 Se a primeira leitura de caractere é o caractere de participante de Arquivo, um caractere nulo é armazenado no início de `buffer` e `NULL` é retornado.  
  
 `_getws` é uma versão caracteres largos de `gets_s`; seu argumento e valor de retorno são cadeias de caracteres de largos.  
  
 Se `buffer` é `NULL` ou `sizeInCharacters` é menor ou igual a zero, ou se o buffer é muito pequeno conter a linha de entrada e o terminador nulo, essas funções invoca um manipulador inválido do parâmetro, conforme descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, essas funções retornarão `NULL` e definirão errno como `ERANGE`.  
  
 No C\+\+, o uso dessas funções é simplificado por sobrecargas de modelo; as sobrecargas podem interpretar o tamanho do buffer automaticamente \(eliminando a necessidade de especificar um argumento de tamanho\) e podem substituir automaticamente as funções menos seguras mais antigas por correspondentes mais seguras e mais recentes.  Para obter mais informações, consulte [Sobrecargas de modelo seguras](../Topic/Secure%20Template%20Overloads.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_getts`|`gets_s`|`gets_s`|`_getws`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`gets_s`|\<stdio.h\>|  
|`_getws`|\<stdio.h\> ou \<wchar.h\>|  
  
 O console não tem suporte em aplicativos do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  Os manipuladores de fluxo padrão associados ao console — `stdin`, `stdout` e `stderr` — devem ser redirecionados antes que as funções de tempo de execução do C possam utilizá\-los em aplicativos do [!INCLUDE[win8_appname_long](../../build/includes/win8_appname_long_md.md)].  Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_gets_s.c  
// This program retrieves a string from the stdin and   
// prints the same string to the console.  
  
#include <stdio.h>  
  
int main( void )  
{  
   char line[21]; // room for 20 chars + '\0'  
   gets_s( line, 20 );  
   printf( "The line entered was: %s\n", line );  
}  
```  
  
  **`Olá!`A linha foi inserida foi: Olá\!**   
## Equivalência do .NET Framework  
 [System::Console::Read](https://msdn.microsoft.com/en-us/library/system.console.read.aspx)  
  
## Consulte também  
 [E\/S de fluxo](../../c-runtime-library/stream-i-o.md)   
 [gets, \_getws](../../c-runtime-library/gets-getws.md)   
 [fgets, fgetws](../../c-runtime-library/reference/fgets-fgetws.md)   
 [fputs, fputws](../Topic/fputs,%20fputws.md)   
 [puts, \_putws](../Topic/puts,%20_putws.md)