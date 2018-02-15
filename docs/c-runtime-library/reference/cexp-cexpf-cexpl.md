---
title: cexp, cexpf, cexpl | Microsoft Docs
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
- cexp
- cexpf
- cexpl
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
- cexp
- cexpf
- cexpl
- complex/cepx
- complex/cexpf
- complex/cexpl
dev_langs:
- C++
helpviewer_keywords:
- cexp function
- cexpl function
- cexpf function
ms.assetid: f27fd5a9-70c7-4957-a7ee-5256d19bd1da
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ce5f42c8a13db45e3f75345b873bc6ec76885052
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="cexp-cexpf-cexpl"></a>cexp, cexpf, cexpl
Calcule o exponencial de base e de um número complexo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
_Dcomplex cexp(   
   _Dcomplex z   
);  
_Fcomplex cexp(   
   _Fcomplex z   
);  // C++ only  
_Lcomplex cexp(   
   _Lcomplex z   
);  // C++ only  
_Fcomplex cexpf(   
  _Fcomplex z   
);  
_Lcomplex cexpl(   
   _Lcomplex z   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `z`  
 Um número complexo que representa o expoente.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor de `e` elevado à potência de `z`.  
  
## <a name="remarks"></a>Comentários  
 Como C++ permite sobrecargas, é possível chamar sobrecargas de `cexp` que tomam e retornam valores de `_Fcomplex` e `_Lcomplex`. Em um programa do C, `cexp` sempre usa e retorna um valor `_Dcomplex`.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho C|Cabeçalho C++|  
|-------------|--------------|------------------|  
|`cexp`,               `cexpf`, `cexpl`|\<complex.h>|\<complex.h>|  
  
 Para obter informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Alphabetical Function Reference](../../c-runtime-library/reference/crt-alphabetical-function-reference.md)  (Referência da função alfabética)  
 [cpow, cpowf, cpowl](../../c-runtime-library/reference/cpow-cpowf-cpowl.md)   
 [clog10, clog10f, clog10l](../../c-runtime-library/reference/clog10-clog10f-clog10l.md)   
 [clog, clogf, clogl](../../c-runtime-library/reference/clog-clogf-clogl.md)