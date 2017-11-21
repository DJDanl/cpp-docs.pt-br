---
title: toupper, _toupper, towupper, _toupper_l, _towupper_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _toupper_l
- towupper
- toupper
- _towupper_l
- _toupper
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
- towupper
- _toupper
- _totupper
- toupper
dev_langs: C++
helpviewer_keywords:
- _toupper function
- towupper function
- uppercase, converting strings to
- totupper function
- string conversion, to different characters
- towupper_l function
- toupper_l function
- string conversion, case
- _toupper_l function
- _towupper_l function
- _totupper function
- case, converting
- characters, converting
- toupper function
ms.assetid: cdef1b0f-b19c-4d11-b7d2-cf6334c9b6cc
caps.latest.revision: "16"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: a40472922e61cbcc6c5788d575305613ae300e1e
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="toupper-toupper-towupper-toupperl-towupperl"></a>toupper, _toupper, towupper, _toupper_l, _towupper_l
Converta caractere em maiúscula.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int toupper(  
   int c   
);  
int _toupper(  
   int c   
);  
int towupper(  
   wint_t c   
);  
int _toupper_l(  
   int c ,  
   _locale_t locale  
);  
int _towupper_l(  
   wint_t c ,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `c`  
 Caractere a ser convertido.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 Todas essas rotinas convertem uma cópia do `c`, se possível e retornam o resultado.  
  
 Se `c` for um caractere largo para o qual `iswlower` é diferente de zero e houver um caractere largo correspondente para o qual `iswupper` é diferente de zero, `towupper` retornará o caractere largo correspondente; caso contrário, `towupper` retornará `c` sem alterações.  
  
 Não há valor retornado reservado para indicar um erro.  
  
 Para que `toupper` forneça os resultados esperados, [__isascii](../../c-runtime-library/reference/isascii-isascii-iswascii.md) e [islower](../../c-runtime-library/reference/islower-iswlower-islower-l-iswlower-l.md) devem retornar um valor diferente de zero.  
  
## <a name="remarks"></a>Comentários  
 Cada uma dessas rotinas converte determinada letra minúscula em maiúscula, se for possível e relevante. A conversão de maiúsculas e minúsculas de `towupper` é específica da localidade. Somente caracteres relevantes à localidade atual são alterados quanto a maiúsculas e minúsculas. As funções sem o sufixo `_l` usam a localidade definida atualmente. As versões dessas funções com o sufixo `_l` usam a localidade como parâmetro e a usam em vez da localidade definida atualmente. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
 Para que `toupper` forneça os resultados esperados, [__isascii](../../c-runtime-library/reference/isascii-isascii-iswascii.md) e [isupper](../../c-runtime-library/reference/isupper-isupper-l-iswupper-iswupper-l.md) devem retornar um valor diferente de zero.  
  
 [Rotinas de conversão de dados](../../c-runtime-library/data-conversion.md)  
  
### <a name="generic-text-routine-mappings"></a>Mapeamentos da rotina de texto genérico  
  
|Rotina TCHAR.H|_UNICODE e _MBCS não definidos|_MBCS definido|_UNICODE definido|  
|---------------------|------------------------------------|--------------------|-----------------------|  
|`_totupper`|`toupper`|`_mbctoupper`|`towupper`|  
|`_totupper_l`|`_toupper_l`|`_mbctoupper_l`|`_towupper_l`|  
  
> [!NOTE]
>  `_toupper_l` e `_towupper_l` não têm dependência de localidade e não se destinam a serem chamados diretamente. Eles são fornecidos para uso interno por `_totupper_l`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`toupper`|\<ctype.h>|  
|`_toupper`|\<ctype.h>|  
|`towupper`|\<ctype.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo em [Funções to](../../c-runtime-library/to-functions.md).  
  
## <a name="see-also"></a>Consulte também  
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)   
 [Funções to](../../c-runtime-library/to-functions.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)