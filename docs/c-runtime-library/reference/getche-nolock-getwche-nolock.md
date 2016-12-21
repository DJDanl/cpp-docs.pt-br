---
title: "_getche_nolock, _getwche_nolock | Microsoft Docs"
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
  - "_getche_nolock"
  - "_getwche_nolock"
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
apitype: "DLLExport"
f1_keywords: 
  - "_getche_nolock"
  - "_gettche_nolock"
  - "_getwche_nolock"
  - "getche_nolock"
  - "getwche_nolock"
  - "gettche_nolock"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _getche_nolock"
  - "Função _gettche_nolock"
  - "Função _getwche_nolock"
  - "caracteres, obtendo do console"
  - "console, lendo de"
  - "Função getche_nolock"
  - "Função gettche_nolock"
  - "Função getwche_nolock"
ms.assetid: 9e853ad4-4d8a-4442-9ae5-da4b434f0b8c
caps.latest.revision: 18
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _getche_nolock, _getwche_nolock
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém um caractere do console com eco e sem bloquear o segmento.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _getche_nolock( void );  
wint_t _getwche_nolock( void );  
```  
  
## Valor de retorno  
 Retorna a leitura de caracteres.  Não há nenhum retorno de erro.  
  
## Comentários  
 `_getche_nolock` e `_getwche_nolock` são idênticos a `_getche` e `_getwche` exceto que não são protegidos contra a interferência de outros threads.  Elas podem ser mais rápidas, pois não incorrem na sobrecarga de bloquear outros threads.  Use essas funções somente em contextos de thread\-safe, como aplicativos single\-threaded ou onde o escopo de chamada já manipula o isolamento do thread.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_gettche_nolock`|`_getche_nolock`|`_getch_nolock`|`_getwche_nolock`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_getche_nolock`|\<conio.h\>|  
|`_getwche_nolock`|\<conio.h\> ou \<wchar.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_getche_nolock.c  
// compile with: /c  
// This program reads characters from  
// the keyboard until it receives a 'Y' or 'y'.  
  
#include <conio.h>  
#include <ctype.h>  
  
int main( void )  
{  
   int ch;  
  
   _cputs( "Type 'Y' when finished typing keys: " );  
   do  
   {  
      ch = _getche_nolock();  
      ch = toupper( ch );  
   } while( ch != 'Y' );  
  
   _putch_nolock( ch );  
   _putch_nolock( '\r' );    // Carriage return  
   _putch_nolock( '\n' );    // Line feed   
}  
```  
  
  **`abcdey`Digite 'Y' quando concluir as teclas de digitação: Y**   
## Equivalente ao .NET Framework  
 Não aplicável.  Para chamar a função padrão de C, use `PInvoke`.  Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Console e E\/S de porta](../../c-runtime-library/console-and-port-i-o.md)   
 [\_cgets, \_cgetws](../../c-runtime-library/cgets-cgetws.md)   
 [getc, getwc](../../c-runtime-library/reference/getc-getwc.md)   
 [\_ungetch, \_ungetwch, \_ungetch\_nolock, \_ungetwch\_nolock](../../c-runtime-library/reference/ungetch-ungetwch-ungetch-nolock-ungetwch-nolock.md)