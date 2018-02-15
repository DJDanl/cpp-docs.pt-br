---
title: ispunct, iswpunct, _ispunct_l, _iswpunct_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- ispunct
- _iswpunct_l
- iswpunct
- _ispunct_l
apilocation:
- msvcrt.dll
- msvcr80.dll
- msvcr90.dll
- msvcr100.dll
- msvcr100_clr0400.dll
- msvcr110.dll
- msvcr110_clr0400.dll
- msvcr120.dll
- msvcr120_clr0400.dll
- ucrtbase.dll
- api-ms-win-crt-string-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- iswpunct
- _istpunct
- ispunct
dev_langs:
- C++
helpviewer_keywords:
- _istpunct function
- _ispunct_l function
- iswpunct function
- ispunct function
- istpunct function
- ispunct_l function
- _iswpunct_l function
- iswpunct_l function
ms.assetid: 94403240-85c8-40a4-9c2b-e3e95c729c76
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: fc86de73132dcefc57602586b679b95333c99c2e
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="ispunct-iswpunct-ispunctl-iswpunctl"></a>ispunct, iswpunct, _ispunct_l, _iswpunct_l
Determina se um inteiro representa um caractere de pontuação.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int ispunct(  
   int c   
);  
int iswpunct(  
   wint_t c   
);  
int _ispunct_l(  
   int c,  
   _locale_t locale  
);  
int _iswpunct_l(  
   wint_t c,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `c`  
 Inteiro a ser testado.  
  
 `locale`  
 A localidade a ser usada.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada uma dessas rotinas retornará um valor diferente de zero se `c` for uma representação específica de um caractere de pontuação. `ispunct` retorna um valor diferente de zero para qualquer caractere imprimível que não for um caractere de espaço ou um caractere para o qual `isalnum` é diferente de zero. `iswpunct` retorna um valor diferente de zero para qualquer caractere largo imprimível que não for um caractere largo de espaço ou um caractere largo para o qual `iswalnum` é diferente de zero. Cada uma dessas rotinas retornará 0 se `c` não satisfizer a condição de teste.  
  
 O resultado da condição de teste para a função `ispunct` depende da configuração da categoria `LC_CTYPE` da localidade; consulte [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções que não têm o sufixo `_l` usam a localidade atual para qualquer comportamento dependente da localidade; as versões que têm o sufixo `_l` são idênticas, exceto por usarem a localidade que é passada. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 O comportamento de `ispunct` e `_ispunct_l` será indefinido se `c` não for EOF ou não estiver no intervalo de 0 a 0xFF, inclusive. Quando uma biblioteca de depuração CRT é usada e `c` não é um desses valores, as funções geram uma asserção.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|**_** `istpunct`|`ispunct`|[_ismbcpunct](../../c-runtime-library/reference/ismbcgraph-functions.md)|`iswpunct`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`ispunct`|\<ctype.h>|  
|`iswpunct`|\<ctype.h> ou \<wchar.h>|  
|`_ispunct_l`|\<ctype.h>|  
|`_iswpunct_l`|\<ctype.h> ou \<wchar.h>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classificação de caracteres](../../c-runtime-library/character-classification.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)