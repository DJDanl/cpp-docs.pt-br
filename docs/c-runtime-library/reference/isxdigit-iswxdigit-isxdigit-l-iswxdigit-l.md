---
title: "isxdigit, iswxdigit, _isxdigit_l, _iswxdigit_l | Microsoft Docs"
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
  - "_iswxdigit_l"
  - "iswxdigit"
  - "isxdigit"
  - "_isxdigit_l"
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
  - "iswxdigit"
  - "isxdigit"
  - "_istxdigit"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _istxdigit"
  - "Função _iswxdigit_l"
  - "Função _isxdigit_l"
  - "caracteres hexadecimais"
  - "Função istxdigit"
  - "Função iswxdigit"
  - "Função iswxdigit_l"
  - "Função isxdigit"
  - "Função isxdigit_l"
ms.assetid: c8bc5146-0b58-4e3f-bee3-f2318dd0f829
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# isxdigit, iswxdigit, _isxdigit_l, _iswxdigit_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina se um inteiro representa um caractere que é um dígito hexadecimal.  
  
## Sintaxe  
  
```  
int isxdigit(  
   int c   
);  
int iswxdigit(  
   wint_t c   
);  
int _isxdigit_l(  
   int c,  
   _locale_t locale  
);  
int _iswxdigit_l(  
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
 Cada uma dessas rotinas retorna diferente de zero se `c` for uma representação específica de um caractere de dígito hexadecimal.  `isxdigit` retorna um valor diferente de zero se `c` for um dígito hexadecimal \(A – F, a – f, ou 0 – 9\).  `iswxdigit` retorna um valor diferente de zero caso `c` seja um caractere largo que corresponda a um caractere de dígito hexadecimal.  Cada uma dessas rotinas retornará 0 se `c` não atender à condição de teste.  
  
 Para a localização de "C", a função de `iswxdigit` não oferece suporte a caracteres hexadecimais de Unicode largos.  
  
 As versões dessas funções que têm o sufixo `_l` usam a localidade informada em vez da localidade atual de seu comportamento dependente da localidade.  Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 O comportamento de `isxdigit` e de `_isxdigit_l` é indefinido se `c` não é EOF ou no intervalo 0 0xFF direto, inclusive.  Quando uma biblioteca de CRT de depuração é usada e o `c` e não é um desses valores, as funções geram uma declaração.  
  
### Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|\_UNICODE & \_MBCS não definido|\_MBCS definido|\_UNICODE definido|  
|--------------------|-------------------------------------|---------------------|------------------------|  
|`_istxdigit`|`isxdigit`|`isxdigit`|`iswxdigit`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`isxdigit`|\<ctype.h\>|  
|`iswxdigit`|\<ctype.h\> ou \<wchar.h\>|  
|`_isxdigit_l`|\<ctype.h\>|  
|`_iswxdigit_l`|\<ctype.h\> ou \<wchar.h\>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## Equivalência do .NET Framework  
 [System::Char::IsNumber](https://msdn.microsoft.com/en-us/library/system.char.isnumber.aspx)  
  
## Consulte também  
 [Classificação de caractere](../../c-runtime-library/character-classification.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)