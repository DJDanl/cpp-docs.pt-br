---
title: isspace, iswspace, _isspace_l, _iswspace_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- iswspace
- _isspace_l
- _iswspace_l
- isspace
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
- iswspace
- _istspace
- isspace
dev_langs:
- C++
helpviewer_keywords:
- iswspace function
- isspace function
- _iswspace_l function
- _isspace_l function
- iswspace_l function
- isspace_l function
- _istspace function
- istspace function
ms.assetid: b851e0c0-36bb-4dac-a1a3-533540939035
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 5eef3b216ed70bb7fa6a22d02827dec34b44c3b3
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="isspace-iswspace-isspacel-iswspacel"></a>isspace, iswspace, _isspace_l, _iswspace_l
Determina se um inteiro representa um caractere de espaço.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int isspace(  
   int c   
);  
int iswspace(  
   wint_t c   
);  
int _isspace_l(  
   int c,  
   _locale_t locale  
);  
int _iswspace_l(  
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
 Cada um dessas rotinas retornará um valor diferente de zero se `c` for uma representação específica de um caractere de espaço. `isspace` Retorna um valor diferente de zero se `c` é um caractere de espaço em branco (0x09-0x0D ou 0x20). O resultado da condição de teste para a função `isspace` depende da configuração da categoria `LC_CTYPE` da localidade; consulte [setlocale, _wsetlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções que não têm o sufixo `_l` usam a localidade atual para qualquer comportamento dependente da localidade; as versões que têm o sufixo `_l` são idênticas, exceto por usarem a localidade que é passada. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 `iswspace` retornará um valor diferente de zero se `c` for um caractere largo que corresponde a um caractere de espaço em branco padrão.  
  
 O comportamento de `isspace` e `_isspace_l` será indefinido se `c` não for EOF ou não estiver no intervalo de 0 a 0xFF, inclusive. Quando uma biblioteca de depuração CRT é usada e `c` não é um desses valores, as funções geram uma asserção.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|**_** `istspace`|`isspace`|[_ismbcspace](../../c-runtime-library/reference/ismbcgraph-functions.md)|`iswspace`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`isspace`|\<ctype.h>|  
|`iswspace`|\<ctype.h> ou \<wchar.h>|  
|`_isspace_l`|\<ctype.h>|  
|`_iswspace_l`|\<ctype.h> ou \<wchar.h>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classificação de caracteres](../../c-runtime-library/character-classification.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)