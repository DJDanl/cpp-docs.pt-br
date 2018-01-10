---
title: btowc | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname: btowc
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
- api-ms-win-crt-convert-l1-1-0.dll
apitype: DLLExport
f1_keywords: btowc
dev_langs: C++
helpviewer_keywords: btowc function
ms.assetid: 99a46e02-6f86-4569-af79-5feca012add8
caps.latest.revision: "10"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 7d63fa7e13e5c52b80edc9755c66e2aab4533331
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="btowc"></a>btowc
Determine se um inteiro representa um caractere de byte único válido no estado inicial do deslocamento.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
wint_t btowc(  
   int c  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `c`  
 Inteiro a ser testado.  
  
## <a name="return-value"></a>Valor de retorno  
 Retornará a representação de caractere largo do caractere se o inteiro representar um caractere de byte único válido no estado inicial do deslocamento. Retornará WEOF se o inteiro for EOF ou não for um caractere de byte único válido no estado inicial do deslocamento. A saída dessa função é afetada pela localidade `LC_TYPE` atual.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`btowc`|\<stdio.h> ou \<wchar.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [mbtowc, _mbtowc_l](../../c-runtime-library/reference/mbtowc-mbtowc-l.md)