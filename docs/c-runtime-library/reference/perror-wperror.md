---
title: "perror, _wperror | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_wperror"
  - "perror"
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
  - "api-ms-win-crt-runtime-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_wperror"
  - "_tperror"
  - "perror"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _tperror"
  - "Função _wperror"
  - "mensagens de erro, imprimindo"
  - "Função perror"
  - "imprimindo mensagens de erro"
  - "Função tperror"
  - "Função wperror"
ms.assetid: 34fce792-16fd-4673-9849-cd88b54b6cd5
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# perror, _wperror
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Imprime uma mensagem de erro.  
  
## Sintaxe  
  
```  
  
      void perror(  
   const char *string   
);  
void _wperror(  
   const wchar_t *string   
);  
```  
  
#### Parâmetros  
 `string`  
 Mensagem de cadeia de caracteres para imprimir.  
  
## Comentários  
 A função de `perror` imprime uma mensagem de erro a `stderr`.  `_wperror` é uma versão de ampla caractere de **\_perror**; o argumento de `string` a `_wperror` é uma cadeia de caracteres de ampla caractere.  `_wperror` e **\_perror** se comportam idêntica de outra forma.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_tperror`|`perror`|`perror`|`_wperror`|  
  
 `string` é impresso primeiro, seguido por dois\-pontos, então pela mensagem de erro do sistema para a última chamada de biblioteca que gerou o erro e, finalmente por um caractere de nova linha.  Se `string` for um ponteiro nulo ou um ponteiro para uma cadeia de caracteres nula, `perror` imprime apenas a mensagem de erro do sistema.  
  
 O número do erro é armazenado na variável [errno](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) \(definido em ERRNO.H\).  As mensagens de erro do sistema são acessadas por meio da variável [\_sys\_errlist](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md), que é uma matriz de mensagens ordenadas pelo número do erro.  `perror` imprime a mensagem de erro apropriado usando o valor de `errno` como um índice a `_sys_errlist`.  O valor da variável [\_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) é definido como o número máximo de elementos na matriz `_sys_errlist`.  
  
 Para resultados precisos, a chamada `perror` imediatamente após uma rotina de biblioteca retorna o com um erro.  Caso contrário, as chamadas subsequentes podem substituir o valor de `errno` .  
  
 No sistema operacional Windows, alguns valores de `errno` listados em ERRNO.H não são usados.  Esses valores são reservados para uso do sistema operacional do UNIX.  Consulte [\_doserrno, errno, \_sys\_errlist, e \_sys\_nerr](../Topic/errno,%20_doserrno,%20_sys_errlist,%20and%20_sys_nerr.md) para uma lista de valores de `errno` usados pelo sistema operacional Windows.  `perror` imprime uma cadeia de caracteres vazia para qualquer valor de `errno` não usados por essas plataformas.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`perror`|\<stdio.h ou\> stdlib.h \<\>|  
|`_wperror`|\<stdio.h\> ou \<wchar.h\>|  
  
 Para informações adicionais de compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Bibliotecas  
 Todas as versões das [Bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## Exemplo  
  
```  
// crt_perror.c  
// compile with: /W3  
/* This program attempts to open a file named  
 * NOSUCHF.ILE. Because this file probably doesn't exist,  
 * an error message is displayed. The same message is  
 * created using perror, strerror, and _strerror.  
 */  
  
#include <fcntl.h>  
#include <sys/types.h>  
#include <sys/stat.h>  
#include <io.h>  
#include <stdlib.h>  
#include <stdio.h>  
#include <string.h>  
#include <share.h>  
  
int main( void )  
{  
   int  fh;  
  
   if( _sopen_s( &fh, "NOSUCHF.ILE", _O_RDONLY, _SH_DENYNO, 0 ) != 0 )  
   {  
      /* Three ways to create error message: */  
      perror( "perror says open failed" );  
      printf( "strerror says open failed: %s\n",  
         strerror( errno ) ); // C4996  
      printf( _strerror( "_strerror says open failed" ) ); // C4996  
      // Note: strerror and _strerror are deprecated; consider  
      // using strerror_s and _strerror_s instead.  
   }  
   else  
   {  
      printf( "open succeeded on input file\n" );  
      _close( fh );  
   }  
}  
```  
  
## Saída  
  
```  
perror says open failed: No such file or directory  
strerror says open failed: No such file or directory  
_strerror says open failed: No such file or directory  
```  
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Processo e controle de ambiente](../../c-runtime-library/process-and-environment-control.md)   
 [clearerr](../../c-runtime-library/reference/clearerr.md)   
 [ferror](../../c-runtime-library/reference/ferror.md)   
 [strerror, \_strerror, \_wcserror, \_\_wcserror](../../c-runtime-library/reference/strerror-strerror-wcserror-wcserror.md)