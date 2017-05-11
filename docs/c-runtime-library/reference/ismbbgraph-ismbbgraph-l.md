---
title: _ismbbgraph, _ismbbgraph_l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _ismbbgraph_l
- _ismbbgraph
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
- _ismbbgraph
- _ismbbgraph_l
- ismbbgraph
- ismbbgraph_l
dev_langs:
- C++
helpviewer_keywords:
- _ismbbgraph_l function
- ismbbgraph_l function
- _ismbbgraph function
- ismbbgraph function
ms.assetid: b60db718-134f-4796-acc1-592d0b9efbb7
caps.latest.revision: 20
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
ms.openlocfilehash: 99ab02233eed70ab92e1aabcf567d9cfc244c101
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="ismbbgraph-ismbbgraphl"></a>_ismbbgraph, _ismbbgraph_l
Determina se um dado caractere multibyte é um caractere gráfico.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _ismbbgraph (  
   unsigned int c   
);  
int _ismbbgraph_l (  
   unsigned int c,  
   _locale_t locale  
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `c`  
 Inteiro a ser testado.  
  
 `locale`  
 Localidade a usar.  
  
## <a name="return-value"></a>Valor de retorno  
 Retorna um valor diferente de zero se a expressão:  
  
```  
( _PUNCT | _UPPER | _LOWER | _DIGIT ) || _ismbbkprint  
```  
  
 for diferente de zero para `c` ou 0 se não for. `_ismbbgraph` usa a localidade atual para qualquer comportamento que dependa da localidade. `_ismbbgraph_l` é idêntico, exceto pelo fato de usar a localidade passada. Para obter mais informações, consulte [Localidade](../../c-runtime-library/locale.md).  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_ismbbgraph`|\<mbctype.h>|  
|`_ismbbgraph_l`|\<mbctype.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="libraries"></a>Libraries  
 Todas as versões das [bibliotecas em tempo de execução C](../../c-runtime-library/crt-library-features.md).  
  
## <a name="see-also"></a>Consulte também  
 [Classificação de byte](../../c-runtime-library/byte-classification.md)   
 [Rotinas _ismbb](../../c-runtime-library/ismbb-routines.md)
