---
title: "isascii isascii, iswascii | Microsoft Docs"
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
  - "iswascii"
  - "__isascii"
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
  - "iswascii"
  - "istascii"
  - "__isascii"
  - "_istascii"
  - "isascii"
  - "ctype/isascii"
  - "ctype/__isascii"
  - "corecrt_wctype/iswascii"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função __isascii"
  - "Função _isascii"
  - "Função isascii"
  - "Função _istascii"
  - "Função istascii"
  - "Função iswascii"
ms.assetid: ba4325ad-7cb3-4fb9-b096-58906d67971a
caps.latest.revision: 22
caps.handback.revision: 22
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# isascii isascii, iswascii
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Determina se um determinado caractere é um caractere ASCII.  
  
## Sintaxe  
  
```  
int __isascii(   
   int c   
);  
int iswascii(   
   wint_t c   
);  
#define isascii __isascii  
```  
  
#### Parâmetros  
 `c`  
 Inteiro para testar.  
  
## Valor de retorno  
 Cada um desses rotinas retorna zero se `c` é uma representação específica de um caractere ASCII.`__isascii` Retorna um valor diferente de zero se `c` é um caractere ASCII \(no intervalo 0x00 – 0x7F\).`iswascii` Retorna um valor diferente de zero se `c` é uma representação de caractere largo de um caractere ASCII. Todas essas rotinas retornará 0 se `c` não satisfaz a condição de teste.  
  
## Comentários  
 Ambos `__isascii` e `iswascii` são implementados como macros, a menos que a macro do pré\-processador \_CTYPE\_DISABLE\_MACROS está definido.  
  
 Para compatibilidade com versões anteriores, `isascii` é implementado como uma só se macro [\_\_STDC\_\_](../../preprocessor/predefined-macros.md) não está definido ou está definido como 0; caso contrário, é indefinido.  
  
### Mapeamentos de rotina de texto genérico  
  
|Rotina TCHAR. h|Unicode e MBCS não definidos|MBCS definido|Unicode definido|  
|---------------------|----------------------------------|-------------------|----------------------|  
|`_istascii`|`__isascii`|`__isascii`|`iswascii`|  
  
## Requisitos  
  
|Rotina|Cabeçalho necessário|  
|------------|--------------------------|  
|`isascii`, `__isascii`|C: \< CType \><br /><br /> C\+\+: \< cctype \> ou \< CType \>|  
|`iswascii`|C: \< wctype \>, \< CType \> ou \< WCHAR \><br /><br /> C\+\+: \< cwctype \>, \< cctype \>, \< wctype \>, \< CType \> ou \< WCHAR \>|  
  
 O `isascii`, `__isascii` e `iswascii` funções são específicas da Microsoft. Para obter informações adicionais sobre compatibilidade, consulte [compatibilidade](../../c-runtime-library/compatibility.md) na introdução.  
  
## Consulte também  
 [Classificação de caractere](../../c-runtime-library/character-classification.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)