---
title: _ismbclower, _ismbclower_l, _ismbcupper, _ismbcupper_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _ismbclower
- _ismbclower_l
- _ismbcupper_l
- _ismbcupper
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
- _ismbcupper
- _ismbclower
dev_langs:
- C++
helpviewer_keywords:
- _ismbcupper function
- ismbclower function
- _ismbclower_l function
- ismbcupper_l function
- _ismbclower function
- ismbcupper function
- ismbclower_l function
- _ismbcupper_l function
ms.assetid: 17d89587-65bc-477c-ba8f-a84e63cf59e7
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 865c2280ab395b5c8172ee978da16a2bcc26f7b9
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="ismbclower-ismbclowerl-ismbcupper-ismbcupperl"></a>_ismbclower, _ismbclower_l, _ismbcupper, _ismbcupper_l
Verifica se um caractere multibyte está em letras minúsculas ou maiúsculas.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [funções de CRT sem suporte em aplicativos de plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _ismbclower(  
   unsigned int c   
);  
int _ismbclower_l(  
   unsigned int c,  
   _locale_t locale   
);  
int _ismbcupper(  
   unsigned int c   
);  
int _ismbcupper_l(  
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
 Cada uma dessas rotinas retornará um valor diferente de zero se o caractere satisfizer a condição de teste ou 0 se não satisfizer. Se `c`<= 255 e houver uma rotina `_ismbb` correspondente (por exemplo, `_ismbcalnum` corresponder a `_ismbbalnum`), o resultado será o valor retornado da rotina `_ismbb` correspondente.  
  
## <a name="remarks"></a>Comentários  
 Cada uma dessas funções testa um determinado caractere multibyte quanto a uma determinada condição.  
  
 As versões dessas funções com o sufixo `_l` são idênticas, exceto por usarem a localidade passada em vez da localidade atual para seu comportamento que depende da localidade. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
|Rotina|Condição de teste|Exemplo da página de código 932|  
|-------------|--------------------|---------------------------|  
|`_ismbclower`|Alfabético minúsculo|Retorna um valor diferente de zero se e somente se `c` for uma representação de um byte de uma letra minúscula ASCII em inglês: 0x61<=`c`<=0x7A.|  
|`_ismbclower_l`|Alfabético minúsculo|Retorna um valor diferente de zero se e somente se `c` for uma representação de um byte de uma letra minúscula ASCII em inglês: 0x61<=`c`<=0x7A.|  
|`_ismbcupper`|Alfabético maiúsculo|Retorna um valor diferente de zero se e somente se `c` for uma representação de um byte de uma letra maiúscula ASCII em inglês: 0x41<=`c`<=0x5A.|  
|`_ismbcupper_l`|Alfabético maiúsculo|Retorna um valor diferente de zero se e somente se `c` for uma representação de um byte de uma letra maiúscula ASCII em inglês: 0x41<=`c`<=0x5A.|  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_ismbclower`|\<mbstring.h>|  
|`_ismbclower_l`|\<mbstring.h>|  
|`_ismbcupper`|\<mbstring.h>|  
|`_ismbcupper_l`|\<mbstring.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classificação de caracteres](../../c-runtime-library/character-classification.md)   
 [Rotinas _ismbc](../../c-runtime-library/ismbc-routines.md)   
 [Localidade](../../c-runtime-library/locale.md)   
 [Interpretação de sequências de caracteres multibyte](../../c-runtime-library/interpretation-of-multibyte-character-sequences.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)   
 [Rotinas _ismbb](../../c-runtime-library/ismbb-routines.md)