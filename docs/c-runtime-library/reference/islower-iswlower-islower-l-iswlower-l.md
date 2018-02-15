---
title: islower, iswlower, _islower_l, _iswlower_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- iswlower
- _islower_l
- islower
- _iswlower_l
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
- _istlower
- islower
- _ismbclower_l
- _liswlower_l
- _istlower_l
- _iswlower_l
- _islower _l
- _islower_l
- iswlower
dev_langs:
- C++
helpviewer_keywords:
- _islower _l function
- _ismbclower_l function
- islower function
- _iswlower_l function
- _liswlower_l function
- _istlower_l function
- istlower function
- _istlower function
- iswlower function
- _islower_l function
ms.assetid: fcc3b70a-2b47-45fd-944d-e5c1942e6457
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 649e723fc56fd27e816b05963aef88eec3c37a02
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="islower-iswlower-islowerl-iswlowerl"></a>islower, iswlower, _islower_l, _iswlower_l
Determina se um inteiro representa um caractere minúsculo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int islower(  
   int c   
);  
int iswlower(  
   wint_t c   
);  
int islower_l(  
   int c,  
   _locale_t locale  
);  
int _iswlower_l(  
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
 Cada uma dessas rotinas retornará um valor diferente de zero se `c` for uma representação específica de um caractere minúsculo. `islower` Retorna um valor diferente de zero se `c` é um caractere minúsculo (a - z). `iswlower` retornará um valor diferente de zero se `c` for um caractere largo que corresponde a uma letra minúscula ou se `c` for um conjunto de caracteres largos definido pela implementação para o qual nenhum `iswcntrl`, `iswdigit`, `iswpunct` ou `iswspace` são diferentes de zero. Cada uma dessas rotinas retornará 0 se `c` não satisfizer a condição de teste.  
  
 As versões dessas funções que têm o sufixo `_l` usam a localidade passada em vez da localidade atual para seu comportamento que depende da localidade. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 O comportamento de `islower` e `_islower_l` será indefinido se `c` não for EOF ou não estiver no intervalo de 0 a 0xFF, inclusive. Quando uma biblioteca de depuração CRT é usada e `c` não é um desses valores, as funções geram uma asserção.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_istlower`|`islower`|[_ismbclower](../../c-runtime-library/reference/ismbclower-ismbclower-l-ismbcupper-ismbcupper-l.md)|`iswlower`|  
|`_istlower_l`|`_islower _l`|[_ismbclower_l](../../c-runtime-library/reference/ismbclower-ismbclower-l-ismbcupper-ismbcupper-l.md)|`_liswlower_l`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`islower`|\<ctype.h>|  
|`iswlower`|\<ctype.h> ou \<wchar.h>|  
|`_islower_l`|\<ctype.h>|  
|`_swlower_l`|\<ctype.h> ou \<wchar.h>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classificação de caracteres](../../c-runtime-library/character-classification.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)