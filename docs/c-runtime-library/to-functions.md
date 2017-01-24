---
title: "Fun&#231;&#245;es to | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apilocation: 
  - "msvcr120.dll"
  - "msvcr90.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr80.dll"
  - "msvcr100.dll"
apitype: "DLLExport"
f1_keywords: 
  - "To"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "case, convertendo"
  - "caracteres, convertendo"
  - "minúsculas, convertendo cadeias de caracteres"
  - "conversão de cadeia de caracteres, case"
  - "conversão de cadeia de caracteres, para caracteres diferentes"
  - "para funções"
  - "maiúsculas, convertendo cadeias de caracteres"
ms.assetid: f636a4c6-8c9f-4be2-baac-064f9dbae300
caps.latest.revision: 13
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Fun&#231;&#245;es to
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Cada uma das funções de **to** e seu macro associada, se houver, converte um único caractere para outro caractere.  
  
|||  
|-|-|  
|[\_\_toascii](../c-runtime-library/reference/toascii-toascii.md)|[toupper, \_toupper, towupper](../Topic/toupper,%20_toupper,%20towupper,%20_toupper_l,%20_towupper_l.md)|  
|[tolower, \_tolower, towlower](../Topic/tolower,%20_tolower,%20towlower,%20_tolower_l,%20_towlower_l.md)||  
  
## Comentários  
 As funções de **to** e as conversões macro são como se segue.  
  
|Rotina|Macro|Descrição|  
|------------|-----------|---------------|  
|`__toascii`|`__toascii`|Converte `c` ao caractere ASCII|  
|`tolower`|`tolower`|Converte `c` minúsculas se apropriado|  
|`_tolower`|`_tolower`|Converte `c` minúsculas|  
|`towlower`|Nenhum|Converte `c` a letra minúscula correspondente ampla de caracteres|  
|`toupper`|`toupper`|Converte `c` se apropriado para letras maiúsculas|  
|`_toupper`|`_toupper`|Converte `c` para letras maiúsculas|  
|`towupper`|Nenhum|Converte c a letra maiúscula correspondente ampla de caracteres|  
  
 Para usar as versões da função de rotinas de **to** que também são definidas como macros, remova as definições macro com políticas de `#undef` ou não inclua CTYPE.H.  Se você usar a opção do compilador do \/Za, o compilador usa a versão da função de `toupper` ou de `tolower`.  As declarações das funções de `toupper` e de `tolower` estão em. STDLIB.H.  
  
 A rotina de `__toascii` define todos menos os bits de ordem mais inferior de `c` 7 a 0, de forma que o valor convertido representa um caractere no conjunto de caracteres ASCII.  Se já `c` representa um caractere ASCII, `c` permanecerá inalterado.  
  
 As rotinas de `tolower` e de `toupper` :  
  
-   É dependente da categoria de `LC_CTYPE` de localidade atual \(`tolower` chama `isupper` e `toupper` chama `islower`\).  
  
-   Converter `c` se `c` representa uma letra conversível dos casos apropriadas na localidade atual e os casos opostos existem para essa localidade.  Caso contrário, `c` permanecerá inalterado.  
  
 As rotinas de `_tolower` e de `_toupper` :  
  
-   As versões de localidade independentes, muito mais rápido de `tolower` e **toupper.**  
  
-   Pode ser usado quando **isascii\(**`c`**\)** e **isupper\(**`c`**\)** ou **islower\(**`c`**\)**, respectivamente, for diferente de zero.  
  
-   Tem resultados indefinidos se `c` não é uma letra ASCII dos argumentos apropriados para converter.  
  
 As funções de `towlower` e de `towupper` retornam uma cópia convertida de `c` se e somente se ambas as condições forem diferentes de zero.  Caso contrário, `c` permanecerá inalterado.  
  
-   `c` é um caractere largo dos casos adequados \(ou seja, para que `iswupper` ou **iswlower,** respectivamente, é diferente de zero\).  
  
-   Há um caractere largo correspondente dos exemplos de destino \(ou seja, para que `iswlower` ou **iswupper,** respectivamente, é diferente de zero\).  
  
## Exemplo  
  
```  
// crt_toupper.c  
/* This program uses toupper and tolower to  
 * analyze all characters between 0x0 and 0x7F. It also  
 * applies _toupper and _tolower to any code in this  
 * range for which these functions make sense.  
 */  
  
#include <ctype.h>  
#include <string.h>  
  
char msg[] = "Some of THESE letters are Capitals.";  
char *p;  
  
int main( void )  
{  
   printf( "%s\n", msg );  
  
   /* Reverse case of message. */  
   for( p = msg; p < msg + strlen( msg ); p++ )  
   {  
      if( islower( *p ) )  
         putchar( _toupper( *p ) );  
      else if( isupper( *p ) )  
         putchar( _tolower( *p ) );  
      else  
         putchar( *p );  
   }  
}  
```  
  
  **Algumas de ESTAS letras são capitais.**  
**algumas dessas LETRAS IS capitais.**   
## Consulte também  
 [Conversão de dados](../c-runtime-library/data-conversion.md)   
 [Localidade](../c-runtime-library/locale.md)   
 [Rotinas is, isw](../c-runtime-library/is-isw-routines.md)