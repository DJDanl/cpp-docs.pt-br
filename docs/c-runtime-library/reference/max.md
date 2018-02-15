---
title: __max | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1868106e4224e05d661aba5bfb0ed4dca31f508a
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
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
  
## <a name="see-also"></a>Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [__min](../../c-runtime-library/reference/min.md)