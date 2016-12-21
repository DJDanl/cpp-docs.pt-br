---
title: "iscsym, iscsymf, iscsym, iswcsym, iscsymf, iswcsymf, iscsym_l, iswcsym_l, iscsymf_l, iswcsymf_l | Microsoft Docs"
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
  - "_iswcsym_l"
  - "__iswcsym"
  - "__iscsym"
  - "_iswcsymf_l"
  - "_iscsym_l"
  - "__iswcsymf"
  - "__iscsymf"
  - "_iscsymf_l"
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
  - "_iswcsym_l"
  - "_iswcsymf_l"
  - "iscsymf"
  - "iswcsymf"
  - "__iswcsym"
  - "__iswcsymf"
  - "iscsym"
  - "iswcsym"
  - "__iscsym"
  - "_iscsym_l"
  - "_iscsymf_l"
  - "__iscsymf"
  - "ctype/iscsym"
  - "ctype/iscsymf"
  - "ctype/__iscsym"
  - "ctype/__iscsymf"
  - "ctype/__iscsym_l"
  - "ctype/__iscsymf_l"
  - "ctype/__iswcsym"
  - "ctype/__iswcsymf"
  - "ctype/__iswcsym_l"
  - "ctype/__iswcsymf_l"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função iscsymf_l"
  - "Função iswsym_l"
  - "Função _iswcsym_l"
  - "Função iscsym_l"
  - "Função _iscsymf_l"
  - "Função _iswcsymf_l"
  - "Função _iscsym_l"
  - "Função __iscsym"
  - "Função __iswcsymf"
  - "Função iswsymf_l"
  - "Função __iscsymf"
  - "Função __iswcsym"
  - "Função iscsym"
  - "Função iscsymf"
ms.assetid: 944dfb99-f2b8-498c-9f55-dbcf370d0a2c
caps.latest.revision: 21
caps.handback.revision: 21
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# iscsym, iscsymf, iscsym, iswcsym, iscsymf, iswcsymf, iscsym_l, iswcsym_l, iscsymf_l, iswcsymf_l
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determine se um número inteiro representa um caractere que pode ser usado em um identificador.  
  
## Sintaxe  
  
```  
int __iscsym(   
   int c   
);  
int __iswcsym(   
   wint_t c   
);  
int __iscsymf(   
   int c   
);  
int __iswcsymf(   
   wint_t c   
);  
int _iscsym_l(   
   int c,  
   _locale_t locale  
);  
int _iswcsym_l(   
   wint_t c,  
   _locale_t locale  
);  
int _iscsymf_l(   
   int c,  
   _locale_t locale  
);  
int _iswcsymf_l(   
   wint_t c,  
   _locale_t locale  
);  
#define iscsym __iscsym  
#define iscsymf __iscsymf  
```  
  
#### Parâmetros  
 `c`  
 Inteiro para testar.`c` deve estar no intervalo de 0 a 255 para a versão de caractere estreito da função.  
  
 `locale`  
 A localidade a ser usada.  
  
## Valor de retorno  
 Ambos `__iscsym` e `__iswcsym` retornar um valor diferente de zero se `c` é uma letra, um sublinhado ou um dígito. Ambos `__iscsymf` e `__iswcsymf` retornar um valor diferente de zero se `c` é uma letra ou um sublinhado. Todas essas rotinas retornará 0 se `c` não satisfaz a condição de teste. As versões dessas funções com o `_l` sufixo são idênticas, exceto que eles usam a localidade passada em vez da localidade atual para o seu comportamento depende da localidade. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
## Comentários  
 Essas rotinas são definidas como macros, a menos que a macro do pré\-processador \_CTYPE\_DISABLE\_MACROS está definido. Quando você usa as versões de macro essas rotinas, os argumentos podem ser avaliados mais de uma vez. Tenha cuidado ao usar expressões com efeitos colaterais na lista de argumentos.  
  
 Para compatibilidade com versões anteriores, `iscsym` e `iscsymf` são definidos como macros somente quando [\_\_STDC\_\_](../../preprocessor/predefined-macros.md) não está definido ou está definido como 0; caso contrário, eles são indefinidos.  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`iscsym`, `iscsymf`, `__iscsym`, `__iswcsym`, `__iscsymf`, `__iswcsymf`, `_iscsym_l`, `_iswcsym_l`, `_iscsymf_l`, `_iswcsymf_l`|C: \< CType \><br /><br /> C\+\+: \< cctype \> ou \< CType \>|  
  
 O `iscsym`, `iscsymf`, `__iscsym`, `__iswcsym`, `__iscsymf`, `__iswcsymf`, `_iscsym_l`, `_iswcsym_l`, `_iscsymf_l`, e `_iswcsymf_l` rotinas são específicas da Microsoft. Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Consulte também  
 [Classificação de caractere](../../c-runtime-library/character-classification.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)