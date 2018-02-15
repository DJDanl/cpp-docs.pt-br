---
title: clog10, clog10f, clog10l | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: reference
apiname:
- clog10
- clog10f
- clog10l
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
- clog10
- clog10f
- clog10l
- complex/clog10
- complex/clog10f
- complex/clog10l
dev_langs:
- C++
helpviewer_keywords:
- clog10 function
- clog10f function
- clog10l function
ms.assetid: 2ddae00d-ef93-4441-add3-f4d58358401b
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 59fa3d069d68fdb55a9377ca4a4bf89adb1de9f2
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="clog10-clog10f-clog10l"></a>clog10, clog10f, clog10l
Recupera o logaritmo de base 10 de um número complexo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
_Dcomplex clog10(   
   _Dcomplex z   
);  
_Fcomplex clog10(   
  _Fcomplex z   
);  // C++ only  
_Lcomplex clog10(   
   _Lcomplex z   
);  // C++ only  
_Fcomplex clog10f(   
   _Fcomplex z   
);  
_Lcomplex clog10l(   
   _Lcomplex z   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `z`  
 A base do logaritmo.  
  
## <a name="return-value"></a>Valor de retorno  
 Os valores de retorno possíveis são:  
  
|Parâmetro z|Valor retornado|  
|-----------------|------------------|  
|Positivo|O logaritmo de base 10 de z|  
|Zero|- ∞|  
|Negativo|NaN|  
|NaN|NaN|  
|+ ∞|+ ∞|  
  
## <a name="remarks"></a>Comentários  
 Como C++ permite sobrecargas, é possível chamar sobrecargas de `clog10` que tomam e retornam valores de `_Fcomplex` e `_Lcomplex`. Em um programa do C, `clog10` sempre usa e retorna um valor `_Dcomplex`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho C|Cabeçalho C++|  
|-------------|--------------|------------------|  
|`clog10`,               `clog10f`, `clogl`|\<complex.h>|\<ccomplex>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="see-also"></a>Consulte também  
 [Alphabetical Function Reference](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)  (Referência da função alfabética)  
 [cexp, cexpf, cexpl](../../c-runtime-library/reference/cexp-cexpf-cexpl.md)   
 [cpow, cpowf, cpowl](../../c-runtime-library/reference/cpow-cpowf-cpowl.md)   
 [clog, clogf, clogl](../../c-runtime-library/reference/clog-clogf-clogl.md)