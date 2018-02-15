---
title: isblank, iswblank, _isblank_l, _iswblank_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- isblank
- _isblank_l
- iswblank
- _iswblank_l
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
- _iswblank_l
- isblank
- _istblank_l
- _istblank
- _isblank_l
- iswblank
dev_langs:
- C++
ms.assetid: 33ce96c0-f387-411a-8283-c3d2a69e56bd
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5c3dff4f409fe57c67e00afe24f10cbb69c6f83b
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="isblank-iswblank-isblankl-iswblankl"></a>isblank, iswblank, _isblank_l, _iswblank_l
Determina se um inteiro representa um caractere em branco.  
  
## <a name="syntax"></a>Sintaxe  
  
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
  
#### <a name="parameters"></a>Parâmetros  
 `c`  
 Inteiro a ser testado.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada um desses rotinas retornará um valor diferente de zero se `c` for uma representação específica de caractere de tabulação horizontal ou de espaço, ou for um conjunto de caracteres específicos da localidade que são usados para separar palavras em uma linha de texto. `isblank` retornará um valor diferente de zero se `c` for um caractere de espaço (0x20) ou um caractere de tabulação horizontal (0x09). O resultado da condição de teste para as funções `isblank` depende da configuração da categoria `LC_CTYPE` da localidade; consulte [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções que não têm o sufixo `_l` usam a localidade atual para qualquer comportamento dependente da localidade; as versões que têm o sufixo `_l` são idênticas, exceto por usarem a localidade que é passada. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 `iswblank` retornará um valor diferente de zero se `c` for um caractere largo que corresponde a um espaço padrão ou um caractere de tabulação horizontal.  
  
 O comportamento de `isblank` e `_isblank_l` será indefinido se `c` não for EOF ou não estiver no intervalo de 0 a 0xFF, inclusive. Quando uma biblioteca de depuração CRT é usada e `c` não é um desses valores, as funções geram uma asserção.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_istblank`|`isblank`|[_ismbcblank](../../c-runtime-library/reference/ismbcgraph-functions.md)|`iswblank`|  
|`_istblank_l`|`_isblank_l`|[_ismbcblank_l](../../c-runtime-library/reference/ismbcgraph-functions.md)|`_iswblank_l`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`isblank`|\<ctype.h>|  
|`iswblank`|\<ctype.h> ou \<wchar.h>|  
|`_isblank_l`|\<ctype.h>|  
|`_iswblank_l`|\<ctype.h> ou \<wchar.h>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classificação de caracteres](../../c-runtime-library/character-classification.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)