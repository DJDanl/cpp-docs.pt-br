---
title: "_isatty | Microsoft Docs"
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
  - "_isatty"
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
  - "_isatty"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _isatty"
  - "verificando o dispositivo de caracteres"
  - "verificando dispositivos de caracteres"
  - "Função isatty"
ms.assetid: 9f1b2e87-0cd7-4079-b187-f2b7ca15fcbe
caps.latest.revision: 18
caps.handback.revision: 18
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _isatty
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina se um arquivo descritor está associado a um dispositivo de caracteres.  
  
## Sintaxe  
  
```  
  
      int _isatty(  
int fd   
);  
```  
  
#### Parâmetros  
 `fd`  
 Arquivo descritor que refere\-se ao dispositivo a ser testado.  
  
## Valor de retorno  
 `_isatty` retornará um valor diferente de zero se o descritor for associado a um dispositivo de caracteres.  Caso contrário, `_isatty` retorna 0.  
  
## Comentários  
 A função `_isatty` determina se `fd` está associado a um dispositivo de caracteres \(um terminal, um console, uma impressora ou uma porta serial\).  
  
 Essa função valida o parâmetro `fd`.  Se `fd` for um ponteiro de arquivo incorreto, o manipulador de parâmetro inválido será chamado, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  Se a execução puder continuar, a função retornará 0 e definirá `errno` como `EBADF`.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_isatty`|\<io.h\>|  
  
 Para obter mais informações de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
  
```  
// crt_isatty.c  
/* This program checks to see whether  
 * stdout has been redirected to a file.  
 */  
  
#include <stdio.h>  
#include <io.h>  
  
int main( void )  
{  
   if( _isatty( _fileno( stdout ) ) )  
      printf( "stdout has not been redirected to a file\n" );  
   else  
      printf( "stdout has been redirected to a file\n");  
}  
```  
  
## Saída de Exemplo  
  
```  
stdout has not been redirected to a file  
```  
  
## Consulte também  
 [Manipulação de arquivos](../../c-runtime-library/file-handling.md)