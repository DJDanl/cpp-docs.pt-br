---
title: _ismbslead, _ismbstrail, _ismbslead_l, _ismbstrail_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _ismbstrail
- _ismbslead_l
- _ismbslead
- _ismbstrail_l
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
- _ismbslead
- ismbs
- ismbslead_l
- _ismbs
- ismbstrail_l
- ismbslead
- _ismbstrail
- _ismbstrail_l
- ismbstrail
- _ismbslead_l
dev_langs:
- C++
helpviewer_keywords:
- ismbstrail function
- _ismbslead function
- ismbslead function
- ismbslead_l function
- _ismbstrail function
- _ismbslead_l function
- ismbstrail_l function
- _ismbstrail_l function
ms.assetid: 86d2cd7a-3cff-443a-b713-14cc17a231e9
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a3d44722daa76e7409a43887f91d127c732dd6df
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="ismbslead-ismbstrail-ismbsleadl-ismbstraill"></a>_ismbslead, _ismbstrail, _ismbslead_l, _ismbstrail_l
Executa testes sensíveis ao contexto de bytes de início e bytes finais da cadeia de caracteres multibyte e determina se um determinado ponteiro de subcadeia de caracteres aponta para um byte inicial ou para um byte final.  
  
> [!IMPORTANT]
>  Esta API não pode ser usada em aplicativos executados no Tempo de Execução do Windows. Para obter mais informações, consulte [funções de CRT sem suporte em aplicativos de plataforma Universal do Windows](../../cppcx/crt-functions-not-supported-in-universal-windows-platform-apps.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _ismbslead(  
   const unsigned char *str,  
   const unsigned char *current   
);  
int _ismbstrail(  
   const unsigned char *str,  
   const unsigned char *current   
);  
int _ismbslead_l(  
   const unsigned char *str,  
   const unsigned char *current,  
   _locale_t locale  
);  
int _ismbstrail_l(  
   const unsigned char *str,  
   const unsigned char *current,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `str`  
 Ponteiro para o início da cadeia de caracteres ou o byte inicial anterior conhecido.  
  
 `current`  
 Ponteiro para a posição na cadeia de caracteres a ser testada.  
  
 `locale`  
 A localidade a ser usada.  
  
## <a name="return-value"></a>Valor de retorno  
 `_ismbslead` retornará -1 se o caractere é um byte e `_ismbstrail` retornará -1 se o caractere é um byte final. Se as cadeias de caracteres de entrada forem válidas, mas não forem um byte inicial ou um byte final, essas funções retornarão zero. Se um dos argumentos for `NULL`, o manipulador de parâmetro inválido será invocado, conforme descrito em [Validação de parâmetro](../../c-runtime-library/parameter-validation.md). Se a execução puder continuar, essas funções retornarão `NULL` e definirão `errno` para `EINVAL`.  
  
## <a name="remarks"></a>Comentários  
 `_ismbslead` e `_ismbstrail` são mais lentos que as versões `_ismbblead` e `_ismbbtrail`, porque consideram o contexto da cadeia de caracteres.  
  
 As versões dessas funções que têm o sufixo `_l` são idênticas, exceto por usarem a localidade passada em vez da localidade atual para seu comportamento que depende da localidade. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|Cabeçalho opcional|  
|-------------|---------------------|---------------------|  
|`_ismbslead`|\<mbctype.h> ou \<mbstring.h>|\<ctype.h>,* \<limits.h>, \<stdlib.h>|  
|`_ismbstrail`|\<mbctype.h> ou \<mbstring.h>|\<ctype.h>,* \<limits.h>, \<stdlib.h>|  
|`_ismbslead_l`|\<mbctype.h> ou \<mbstring.h>|\<ctype.h>,* \<limits.h>, \<stdlib.h>|  
|`_ismbstrail_l`|\<mbctype.h> ou \<mbstring.h>|\<ctype.h>,* \<limits.h>, \<stdlib.h>|  
  
 \* Para constantes de manifesto para as condições de teste.  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classificação de caracteres](../../c-runtime-library/character-classification.md)   
 [Rotinas _ismbc](../../c-runtime-library/ismbc-routines.md)   
 [Rotinas is, isw](../../c-runtime-library/is-isw-routines.md)   
 [Rotinas _ismbb](../../c-runtime-library/ismbb-routines.md)