---
title: _scalb | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- _scalb
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
- api-ms-win-crt-math-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- scalb
- _scalb
dev_langs:
- C++
helpviewer_keywords:
- exponential calculations
- _scalb function
- scalb function
ms.assetid: 148cf5a8-b405-44bf-a1f0-7487adba2421
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 3f68d1e14a4f92c2ed7ee481966dc46c4384341f
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="scalb"></a>_scalb
Dimensiona o argumento por uma potência de 2.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
double _scalb(  
   double x,  
   long exp   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `x`  
 Valor de ponto flutuante de precisão dupla.  
  
 `exp`  
 Expoente inteiro longo.  
  
## <a name="return-value"></a>Valor de retorno  
 Retornará um valor exponencial se for bem-sucedido. No estouro (dependendo do sinal de `x`), `_scalb` retorna + /- `HUGE_VAL`; o `errno` variável é definida como `ERANGE`.  
  
 Para obter mais informações sobre este e outros códigos retornados, consulte [_doserrno, errno, _sys_errlist e _sys_nerr](../../c-runtime-library/errno-doserrno-sys-errlist-and-sys-nerr.md).  
  
## <a name="remarks"></a>Comentários  
 A função `_scalb` calcula o valor de `x *` 2exp.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário|  
|-------------|---------------------|  
|`_scalb`|\<float.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [ldexp](../../c-runtime-library/reference/ldexp.md)