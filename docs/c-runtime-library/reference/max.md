---
title: __max | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- __max
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
- max
- __max
dev_langs:
- C++
helpviewer_keywords:
- max macro
- maximum macro
- __max macro
ms.assetid: 05c936f6-0e22-45d6-a58d-4bc102e9dae2
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
ms.openlocfilehash: f9476c2d75038338d245778823b15c0ba3f3388a
ms.lasthandoff: 02/25/2017

---
# <a name="max"></a>__max
Retorna o maior de dois valores.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
type __max(  
   type a,  
   type b   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `type`  
 Qualquer tipo de dados numérico.  
  
 `a, b`  
 Valores de qualquer tipo numérico a serem comparados.  
  
## <a name="return-value"></a>Valor de retorno  
 `__max` retorna o maior dos seus argumentos.  
  
## <a name="remarks"></a>Comentários  
 A macro `__max` compara dois valores e retorna o valor do maior. Os argumentos podem ser de qualquer tipo de dados numérico, com ou sem sinal. Os argumentos e o valor retornado devem ser do mesmo tipo de dados.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`__max`|\<stdlib.h>|  
  
## <a name="example"></a>Exemplo  
 Para obter mais informações, consulte o exemplo para [__min](../../c-runtime-library/reference/min.md).  
  
## <a name="net-framework-equivalent"></a>Equivalente ao .NET Framework  
 [System::Math::Max](https://msdn.microsoft.com/en-us/library/system.math.max.aspx)  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [__min](../../c-runtime-library/reference/min.md)
