---
title: _ismbcl0, _ismbcl0_l, _ismbcl1, _ismbcl1_l, _ismbcl2, _ismbcl2_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _ismbcl2
- _ismbcl1
- _ismbcl0
- _ismbcl2_l
- _ismbcl1_l
- _ismbcl0_l
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
- api-ms-win-crt-multibyte-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- ismbcl0
- _ismbcl1_l
- _ismbcl0
- ismbcl1
- ismbcl0_l
- _ismbcl2_l
- ismbcl2
- ismbcl1_l
- _ismbcl1
- _ismbcl0_l
- _ismbcl2
- ismbcl2_l
dev_langs:
- C++
helpviewer_keywords:
- _ismbcl0_l function
- _ismbcl2 function
- _ismbcl1_l function
- ismbcl2 function
- _ismbcl1 function
- ismbcl0_l function
- ismbcl2_l function
- ismbcl1_l function
- ismbcl0 function
- ismbcl1 function
- _ismbcl2_l function
- _ismbcl0 function
ms.assetid: ee15ebd1-462c-4a43-95f3-6735836d626a
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 007b94015b0d898ccedf9d9a7a07d60b26f5faa7
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="ismbcl0-ismbcl0l-ismbcl1-ismbcl1l-ismbcl2-ismbcl2l"></a>_ismbcl0, _ismbcl0_l, _ismbcl1, _ismbcl1_l, _ismbcl2, _ismbcl2_l
**Funções específicas da página de código 932**, usando a localidade atual ou uma categoria de estado de conversão LC_CTYPE especificada.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [funções de CRT sem suporte em aplicativos de plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _ismbcl0(  
   unsigned int c   
);  
int _ismbcl0_l(  
   unsigned int c,  
   _locale_t locale  
);  
int _ismbcl1(  
   unsigned int c   
);  
int _ismbcl1_l(  
   unsigned int c ,  
   _locale_t locale  
);  
int _ismbcl2(  
   unsigned int c   
);  
int _ismbcl2_l(  
   unsigned int c,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `c`  
 Caractere a ser testado.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 Cada uma dessas rotinas retornará um valor diferente de zero se o caractere satisfizer a condição de teste ou 0 se não satisfizer. Se `c` <= 255 e houver uma rotina `_ismbb` correspondente (por exemplo, `_ismbcalnum` corresponder a `_ismbbalnum`), o resultado será o valor retornado da rotina `_ismbb` correspondente.  
  
## <a name="remarks"></a>Comentários  
 Cada uma dessas funções testa um determinado caractere multibyte quanto a uma determinada condição.  
  
 O valor de saída é afetado pela configuração da categoria `LC_CTYPE` da localidade; consulte [setlocale](../../c-runtime-library/reference/setlocale-wsetlocale.md) para obter mais informações. As versões dessas funções sem o sufixo `_l` usam a localidade atual desse comportamento dependente da localidade. As versões com o sufixo `_l` são idênticas, exceto por usarem o parâmetro de localidade passado em seu lugar. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
|Rotina|Condição de teste (página de código 932 somente)|  
|-------------|-------------------------------------------|  
|`_ismbcl0`|JIS não Kanji: 0x8140<=`c`<=0x889E.|  
|`_ismbcl0_l`|JIS não Kanji: 0x8140<=`c`<=0x889E.|  
|`_ismbcl1`|JIS nível 1: 0x889F<=`c`<=0x9872.|  
|`_ismbcl1_l`|JIS nível 1: 0x889F<=`c`<=0x9872.|  
|`_ismbcl2`|JIS nível 2: 0x989F<=`c`<=0xEAA4.|  
|`_ismbcl2_l`|JIS nível 2: 0x989F<=`c`<=0xEAA4.|  
  
 As funções verificam se o valor especificado `c` corresponde às condições de teste descritas acima, mas não verificam se `c` é um caractere multibyte válido. Se o byte inferior estiver nos intervalos 0x00 – 0x3F, 0x7F ou 0xFD – 0xFF, essas funções retornarão um valor diferente de zero, indicando que o caractere satisfaz a condição de teste. Use [_ismbbtrail](../../c-runtime-library/reference/ismbbtrail-ismbbtrail-l.md) para testar se o caractere multibyte foi definido.  
  
 **Final específico da página de código 932**  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_ismbcl0`|\<mbstring.h>|  
|`_ismbcl0_l`|\<mbstring.h>|  
|`_ismbcl1`|\<mbstring.h>|  
|`_ismbcl1_l`|\<mbstring.h>|  
|`_ismbcl2`|\<mbstring.h>|  
|`_ismbcl2_l`|\<mbstring.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classificação de caracteres](../../c-runtime-library/character-classification.md)   
 [Rotinas _ismbc](../../c-runtime-library/ismbc-routines.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)