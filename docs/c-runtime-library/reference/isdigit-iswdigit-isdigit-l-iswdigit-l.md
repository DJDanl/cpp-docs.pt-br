---
title: "isdigit, iswdigit, _isdigit_l, _iswdigit_l | Microsoft Docs"
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
  - "_isdigit_l"
  - "iswdigit"
  - "_iswdigit_l"
  - "isdigit"
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
  - "_iswdigit_l"
  - "_isdigit_l"
  - "iswdigit"
  - "isdigit"
  - "_istdigit"
  - "_istdigit_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função iswdigit"
  - "Função iswdigit_l"
  - "Função _iswdigit_l"
  - "Função _istdigit_l"
  - "Função _istdigit"
  - "Função istdigit"
  - "Função isdigit"
  - "Função isdigit_l"
  - "Função _ismbcdigit_l"
  - "Função _isdigit_l"
ms.assetid: 350b0093-843a-47b0-954e-c1776e8a3853
caps.latest.revision: 19
caps.handback.revision: 19
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# isdigit, iswdigit, _isdigit_l, _iswdigit_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina se um número inteiro representa um caractere de dígito decimal.  
  
## Sintaxe  
  
```  
int isdigit(   
   int c   
);  
int iswdigit(   
   wint_t c   
);  
int _isdigit_l(   
   int c,  
   _locale_t locale  
);  
int _iswdigit_l(   
   wint_t c,  
   _locale_t locale  
);  
```  
  
#### Parâmetros  
 `c`  
 Inteiro a ser testado.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 Cada uma dessas rotinas retorna diferente de zero se `c` for uma representação específica de um caractere de dígito decimal.  `isdigit` retorna um valor diferente de zero se `c` for um dígito decimal \(0 – 9\).  `iswdigit` retorna um valor diferente de zero caso `c` seja um caractere largo que corresponda a um caractere de dígito decimal.  Cada uma dessas rotinas retornará 0 se `c` não atender à condição de teste.  
  
 As versões dessas funções que têm o sufixo `_l` usam a localidade informada em vez da localidade atual de seu comportamento dependente da localidade.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 O comportamento de `isdigit` e de `_isdigit_l` é indefinido se `c` não é EOF ou no intervalo 0 0xFF direto, inclusive.  Quando uma biblioteca de CRT de depuração é usada e o `c` e não é um desses valores, as funções geram uma declaração.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_istdigit`|`isdigit`|[\_ismbcdigit](../Topic/_ismbcalnum,%20_ismbcalnum_l,%20_ismbcalpha,%20_ismbcalpha_l,%20_ismbcdigit,%20_ismbcdigit_l.md)|`iswdigit`|  
|`_istdigit_l`|`_isdigit_l`|[\_ismbcdigit\_l](../Topic/_ismbcalnum,%20_ismbcalnum_l,%20_ismbcalpha,%20_ismbcalpha_l,%20_ismbcdigit,%20_ismbcdigit_l.md)|`_iswdigit_l`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`isdigit`|\<ctype.h\>|  
|`iswdigit`|\<ctype.h\> ou \<wchar.h\>|  
|`_isdigit_l`|\<ctype.h\>|  
|`_iswdigit_l`|\<ctype.h\> ou \<wchar.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 [System::Char::IsDigit](https://msdn.microsoft.com/en-us/library/system.char.isdigit.aspx)  
  
## Consulte também  
 [Classificação de caractere](../../c-runtime-library/character-classification.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)