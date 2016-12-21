---
title: "isblank, iswblank, _isblank_l, _iswblank_l | Microsoft Docs"
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
  - "isblank"
  - "_isblank_l"
  - "iswblank"
  - "_iswblank_l"
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
  - "api-ms-win-crt-string-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "_iswblank_l"
  - "isblank"
  - "_istblank_l"
  - "_istblank"
  - "_isblank_l"
  - "iswblank"
dev_langs: 
  - "C++"
ms.assetid: 33ce96c0-f387-411a-8283-c3d2a69e56bd
caps.latest.revision: 4
caps.handback.revision: 4
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# isblank, iswblank, _isblank_l, _iswblank_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina se um inteiro representa um caractere em branco.  
  
## Sintaxe  
  
```  
int isblank(  
   int c   
);  
int iswblank(  
   wint_t c   
);  
int _isblank_l(  
   int c,  
   _locale_t locale  
);  
int _iswblank_l(  
   wint_t c,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `c`  
 Inteiro a ser testado.  
  
 `locale`  
 Localidade a ser usada.  
  
## Valor de retorno  
 Cada uma dessas rotinas retorna diferente de zero se `c` é uma representação específico de um espaço ou um caractere de tabulação horizontal, ou é de um conjunto específico de local de caracteres que são usados para separar palavra em uma linha de texto.  `isblank` retornará um valor diferente de zero caso `c` for um caractere de espaço \(0x20\) ou um caractere de tabulação horizontal \(0x09\).  O resultado da condição de teste para as funções de `isblank` depende da configuração da categoria de `LC_CTYPE` da localidade; para obter mais informações, consulte [setlocale, \_wsetlocale](../Topic/setlocale,%20_wsetlocale.md).  As versões dessas funções que não têm o sufixo de `_l` usam a localidade atual para qualquer comportamento dependente de local; as versões que têm o sufixo de `_l` são idênticas, exceto as que usam a localidade que é passada.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 `iswblank` retornará um valor diferente de zero caso `c` seja um caractere amplo que corresponda a um espaço padrão ou a um caractere de tabulação horizontal.  
  
 O comportamento de `isblank` e de `_isblank_l` é indefinido se `c` não é EOF ou no intervalo 0 0xFF direto, inclusive.  Quando uma biblioteca de CRT de depuração é usada e o `c` e não é um desses valores, as funções geram uma declaração.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_istblank`|`isblank`|[\_ismbcblank](../../c-runtime-library/reference/ismbcgraph-functions.md)|`iswblank`|  
|`_istblank_l`|`_isblank_l`|[\_ismbcblank\_l](../../c-runtime-library/reference/ismbcgraph-functions.md)|`_iswblank_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`isblank`|\<ctype.h\>|  
|`iswblank`|\<ctype.h\> ou \<wchar.h\>|  
|`_isblank_l`|\<ctype.h\>|  
|`_iswblank_l`|\<ctype.h\> ou \<wchar.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 [System::Char::IsWhiteSpace](https://msdn.microsoft.com/en-us/library/system.char.iswhitespace.aspx)  
  
## Consulte também  
 [Classificação de caractere](../../c-runtime-library/character-classification.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)