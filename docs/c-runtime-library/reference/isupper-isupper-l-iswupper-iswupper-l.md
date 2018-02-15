---
title: isupper, _isupper_l, iswupper, _iswupper_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- isupper
- iswupper
- _iswupper_l
- _isupper_l
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
- isupper
- _istupper
- iswupper
dev_langs:
- C++
helpviewer_keywords:
- istupper function
- iswupper function
- isupper_l function
- _isupper_l function
- iswupper_l function
- _istupper function
- _iswupper_l function
- isupper function
ms.assetid: da2bcc9f-241c-48c0-9a0e-ad273827e16a
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 333e772c2716b87b43cb71ac1797e714af709b3e
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="isupper-isupperl-iswupper-iswupperl"></a>isupper, _isupper_l, iswupper, _iswupper_l
Determina se um inteiro representa um caractere com letra maiúscula.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int isupper(  
   int c   
);  
int _isupper_l (  
   int c,  
   _locale_t locale  
);  
int iswupper(  
   wint_t c   
);  
int _iwsupper_l(  
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
 Cada um dessas rotinas retornará um valor diferente de zero se `c` for uma representação específica de uma letra maiúscula. `isupper` Retorna um valor diferente de zero se `c` é um caractere maiusculo (A - Z). `iswupper` retornará um valor diferente de zero se `c` for um caractere largo que corresponde a uma letra maiúscula ou se `c` for um conjunto de caracteres largos definido pela implementação para o qual nenhum de `iswcntrl`, `iswdigit`, `iswpunct` ou `iswspace` são diferentes de zero. Cada uma dessas rotinas retornará 0 se `c` não satisfizer a condição de teste.  
  
 As versões dessas funções que têm o sufixo `_l` usam a localidade passada em vez da localidade atual para seu comportamento que depende da localidade. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 O comportamento de `isupper` e `_isupper_l` será indefinido se `c` não for EOF ou não estiver no intervalo de 0 a 0xFF, inclusive. Quando uma biblioteca de depuração CRT é usada e `c` não é um desses valores, as funções geram uma asserção.  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_istupper`|`isupper`|[_ismbcupper](../../c-runtime-library/reference/ismbclower-ismbclower-l-ismbcupper-ismbcupper-l.md)|`iswupper`|  
|`_istupper_l`|`_isupper_l`|[_ismbclower, _ismbclower_l, _ismbcupper, _ismbcupper_l](../../c-runtime-library/reference/ismbclower-ismbclower-l-ismbcupper-ismbcupper-l.md)|`_iswupper_l`|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`isupper`|\<ctype.h>|  
|`_isupper_l`|\<ctype.h>|  
|`iswupper`|\<ctype.h> ou \<wchar.h>|  
|`_iswupper_l`|\<ctype.h>|  
  
 Para obter informações adicionais sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classificação de caracteres](../../c-runtime-library/character-classification.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)