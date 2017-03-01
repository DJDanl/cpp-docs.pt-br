---
title: _free_locale | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _free_locale
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
- api-ms-win-crt-locale-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- __free_locale
- free_locale
- _free_locale
dev_langs:
- C++
helpviewer_keywords:
- __free_locale function
- free_locale function
- locales, freeing
- _free_locale function
ms.assetid: 1f08d348-ab32-4028-a145-6cbd51b49af9
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: eb4516bc75ee88225f51f87d863439892d6fdb30
ms.lasthandoff: 02/25/2017

---
# <a name="freelocale"></a>_free_locale
Libera um objeto de localidade.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
void _free_locale(  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `locale`  
 Objeto de localidade a ser liberado.  
  
## <a name="remarks"></a>Comentários  
 A função `_free_locale` é usada para liberar o objeto de localidade obtido com uma chamada para `_get_current_locale` ou `_create_locale`.  
  
 O nome anterior dessa função, `__free_locale` (com dois sublinhados à esquerda), foi preterido.  
  
## <a name="requirements"></a>Requisitos  
  
|`Routine`|Cabeçalho necessário|  
|---------------|---------------------|  
|`_free_locale`|\<locale.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 Não há equivalência.  
  
## <a name="see-also"></a>Consulte também  
 [_get_current_locale](../../c-runtime-library/reference/get-current-locale.md)   
 [_create_locale, _wcreate_locale](../../c-runtime-library/reference/create-locale-wcreate-locale.md)
