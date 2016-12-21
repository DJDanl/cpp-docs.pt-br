---
title: "_getche, _getwche | Microsoft Docs"
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
  - "_getwche"
  - "_getche"
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
  - "getwche"
  - "_getche"
  - "_getwche"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _getche"
  - "Função _getwche"
  - "caracteres, obtendo do console"
  - "console, lendo de"
  - "Função getche"
  - "Função getwche"
ms.assetid: eac978a8-c43a-4130-938f-54f12e2a0fda
caps.latest.revision: 23
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _getche, _getwche
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Obtém um caractere do console com eco.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos que executam no Tempo de Execução do Windows.  Para obter mais informações, consulte [Funções CRT sem suporte pelo \/ZW](http://msdn.microsoft.com/library/windows/apps/jj606124.aspx).  
  
## Sintaxe  
  
```  
int _getche( void );  
wint_t _getwche( void );  
```  
  
## Valor de retorno  
 Retorna a leitura de caracteres.  Não há nenhum retorno de erro.  
  
## Comentários  
 As funções `_getche` e `_getwche` leem um único caractere do console com eco, o que significa que o caractere é exibido no console.  Qualquer uma dessas funções podem ser usadas para ler CTRL\+C.  Ao ler uma tecla de função ou uma tecla de seta, cada função deve ser chamada duas vezes. A primeira chamada retorna 0 ou 0xE0, e a segunda retorna o código real da chave.  
  
 Essas funções bloqueiam o thread de chamada e, portanto, são thread\-safe.  Para versões sem bloqueio, consulte [\_getche\_nolock, \_getwche\_nolock](../../c-runtime-library/reference/getche-nolock-getwche-nolock.md).  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina Tchar.h|\_UNICODE e \_MBCS não definidos|\_MBCS definido|\_UNICODE definido|  
|--------------------|--------------------------------------|---------------------|------------------------|  
|`_getche`|`_getche`|`_getch`|`_getwche`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`_getche`|\<conio.h\>|  
|`_getwche`|\<conio.h\> ou \<wchar.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Exemplo  
  
```  
// crt_getche.c  
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
      ch = _getche();  
      ch = toupper( ch );  
   } while( ch != 'Y' );  
  
   _putch( ch );  
   _putch( '\r' );    // Carriage return  
   _putch( '\n' );    // Line feed       
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