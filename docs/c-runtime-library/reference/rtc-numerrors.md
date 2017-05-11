---
title: _RTC_NumErrors | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _RTC_NumErrors
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
apitype: DLLExport
f1_keywords:
- _RTC_NumErrors
- RTC_NumErrors
dev_langs:
- C++
helpviewer_keywords:
- run-time errors
- _RTC_NumErrors function
- RTC_NumErrors function
ms.assetid: 7e82adae-38e2-4f8b-bc0b-37bda8109fd1
caps.latest.revision: 12
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.mt:
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: e233485881a5783155945589dbb7cf7c59c42a71
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="rtcnumerrors"></a>_RTC_NumErrors
Retorna o número total de erros que podem ser detectados por RTC (verificação de erro em tempo de execução). Você pode usar esse número como o controle em um loop **for**, em que cada valor no loop é passado para [_RTC_GetErrDesc](../../c-runtime-library/reference/rtc-geterrdesc.md).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
int _RTC_NumErrors( void );  
  
```  
  
## <a name="return-value"></a>Valor de retorno  
 Um inteiro cujo valor representa o número total de erros que podem ser detectados pelas verificações de erro em tempo de execução do Visual C++.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_RTC_NumErrors`|\<rtcapi.h>|  
  
 Para obter mais informações, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [_RTC_GetErrDesc](../../c-runtime-library/reference/rtc-geterrdesc.md)   
 [Verificação de erros em tempo de execução](../../c-runtime-library/run-time-error-checking.md)
