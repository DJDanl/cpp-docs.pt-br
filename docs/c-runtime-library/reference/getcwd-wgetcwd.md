---
title: "_getcwd, _wgetcwd | Microsoft Docs"
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
  - "_wgetcwd"
  - "_getcwd"
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
  - "api-ms-win-crt-environment-l1-1-0.dll"
  - "api-ms-win-crt-stdio-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_getcwd"
  - "wgetcwd"
  - "_wgetcwd"
  - "tgetcwd"
  - "_tgetcwd"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função getcwd"
  - "diretório de trabalho"
  - "Função _wgetcwd"
  - "Função _getcwd"
  - "diretório de trabalho atual"
  - "Função wgetcwd"
  - "diretórios [C++] atuais trabalhando"
ms.assetid: 888dc8c6-5595-4071-be55-816b38e3e739
caps.latest.revision: 24
caps.handback.revision: 24
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _getcwd, _wgetcwd
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém o diretório de trabalho atual.  
  
## Sintaxe  
  
```  
char *_getcwd(   
   char *buffer,  
   int maxlen   
);  
wchar_t *_wgetcwd(   
   wchar_t *buffer,  
   int maxlen   
);  
```  
  
#### Parâmetros  
 `buffer`  
 Local de armazenamento para o caminho.  
  
 `maxlen`  
 Comprimento máximo de caminho em caracteres: `char` para `_getcwd` e `wchar_t` para `_wgetcwd`.  
  
## Valor de retorno  
 Retorna um ponteiro para `buffer`. Um `NULL` retornar valor indica um erro, e `errno` for definido `ENOMEM`, indicando que não há memória suficiente para alocar `maxlen` bytes \(quando um `NULL` argumento é fornecido como `buffer`\), ou `ERANGE`, indicando que o caminho tem mais de `maxlen` caracteres. Se `maxlen` for menor ou igual a zero, essa função invoca um manipulador de parâmetro inválido, como descrito em [Validação do parâmetro](../../c-runtime-library/parameter-validation.md).  
  
 Para obter mais informações sobre esses e outros códigos de retorno, consulte [doserrno, errno, sys\_errlist e sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md).  
  
## Comentários  
 O `_getcwd` função obtém o caminho completo do diretório de trabalho atual para a unidade padrão e o armazena em `buffer`. O argumento de inteiro `maxlen` Especifica o comprimento máximo para o caminho. Ocorrerá um erro se o comprimento do caminho \(incluindo o caractere de terminação nula\) excede `maxlen`*.* O `buffer` argumento pode ser `NULL`; um buffer de tamanho de pelo menos `maxlen` \(mais somente se for necessário\) será alocado automaticamente, usando `malloc`, para armazenar o caminho. Esse buffer posteriormente pode ser liberado chamando `free` e passando\-o `_getcwd` retornar valor \(um ponteiro para o buffer alocado\).  
  
 `_getcwd` Retorna uma cadeia de caracteres que representa o caminho do diretório de trabalho atual. Se o diretório de trabalho atual é a raiz, a cadeia de caracteres termina com uma barra invertida \( `\` \). Se o diretório de trabalho atual é um diretório que não seja a raiz, a cadeia de caracteres termina com o nome do diretório e não com uma barra invertida.  
  
 `_wgetcwd` é uma versão de caractere largo de `_getcwd`; o `buffer` argumento e retornar o valor de `_wgetcwd` são cadeias de caracteres largos.`_wgetcwd` e `_getcwd` tenham comportamento idêntico caso contrário.  
  
 Quando `_DEBUG` e `_CRTDBG_MAP_ALLOC` são definidas, as chamadas para `_getcwd` e `_wgetcwd` são substituídos por chamadas para `_getcwd_dbg` e `_wgetcwd_dbg` para permitir a depuração de alocações de memória. Para obter mais informações, consulte [getcwd\_dbg, wgetcwd\_dbg](../../c-runtime-library/reference/getcwd-dbg-wgetcwd-dbg.md).  
  
### Mapeamentos de rotina de texto genérico  
  
|Rotina TCHAR. h|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_tgetcwd`|`_getcwd`|`_getcwd`|`_wgetcwd`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_getcwd`|\< Direct. h \>|  
|`_wgetcwd`|\< Direct. h \> ou \< WCHAR \>|  
  
 Para obter informações de compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_getcwd.c  
// This program places the name of the current directory in the   
// buffer array, then displays the name of the current directory   
// on the screen. Passing NULL as the buffer forces getcwd to allocate  
// memory for the path, which allows the code to support file paths  
// longer than _MAX_PATH, which are supported by NTFS.  
  
#include <direct.h>  
#include <stdlib.h>  
#include <stdio.h>  
  
int main( void )  
{  
   char* buffer;  
  
   // Get the current working directory:   
   if( (buffer = _getcwd( NULL, 0 )) == NULL )  
      perror( "_getcwd error" );  
   else  
   {  
      printf( "%s \nLength: %d\n", buffer, strnlen(buffer) );  
      free(buffer);  
   }  
}  
```  
  
```Output  
C:\Code  
```  
  
## Equivalência do .NET Framework  
 [System::Environment::CurrentDirectory](https://msdn.microsoft.com/en-us/library/system.environment.currentdirectory.aspx)  
  
## Consulte também  
 [Controle de diretório](../../c-runtime-library/directory-control.md)   
 [\_chdir, \_wchdir](../Topic/_chdir,%20_wchdir.md)   
 [\_mkdir, \_wmkdir](../Topic/_mkdir,%20_wmkdir.md)   
 [\_rmdir, \_wrmdir](../../c-runtime-library/reference/rmdir-wrmdir.md)