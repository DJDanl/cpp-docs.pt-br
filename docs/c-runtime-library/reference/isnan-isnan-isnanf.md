---
title: isnan, _isnan, _isnanf | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _isnan
- _isnanf
- isnan
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
- _isnan
- isnan
- math/isnan
- math/_isnan
- math/_isnanf
- _isnanf
dev_langs:
- C++
helpviewer_keywords:
- NAN (not a number)
- _isnan function
- IEEE floating-point representation
- Not a Number (NANs)
- isnan function
ms.assetid: 391fbc5b-89a4-4fba-997e-68f1131caf82
caps.latest.revision: 11
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
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: fefdb830145cb2141f004045ec5426ead2a79a8b
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="isnan-isnan-isnanf"></a>isnan, _isnan, _isnanf
Testa se um valor de ponto flutuante não é um número (NAN).  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int isnan(  
   /* floating-point */ x   
); /* C-only macro */  
  
int _isnan(  
   double x   
);  
  
int _isnanf(  
   float x  
); /* x64 only */  
  
template <class T>  
bool isnan(  
   T x  
) throw(); /* C++ only */  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *x*  
 O valor de ponto flutuante a ser testado.  
  
## <a name="return-value"></a>Valor de retorno  
 No C, a macro `isnan` e as funções `_isnan` e `_isnanf` retornam um valor diferente de zero se o argumento `x` for NAN; caso contrário, retornam 0.  
  
 No C ++, as funções de modelo `isnan` retornam `true` se o argumento `x` for NAN; caso contrário, retornam `false`.  
  
## <a name="remarks"></a>Comentários  
 A macro `isnan` do C e as funções `_isnan` e `_isnanf` testam o valor de ponto flutuante *x*, retornando um valor diferente de zero se *x* for um valor que não é um número (NAN). Um NAN é gerado quando o resultado de uma operação de ponto flutuante não puder ser representado no formato de ponto flutuante IEEE-754 para o tipo especificado. Para obter informações sobre como um NaN é representado para saída, consulte [printf](../../c-runtime-library/reference/printf-printf-l-wprintf-wprintf-l.md).  
  
 Quando compilada como C++, a macro `isnan` não é definida e uma função de modelo `isnan` é definida em vez disso. Retorna um valor do tipo `bool` em vez de um inteiro.  
  
 As funções `_isnan` e `_isnanf` são específicas da Microsoft. A função `_isnanf` só está disponível quando compilada para x64.  
  
## <a name="requirements"></a>Requisitos  
  
|Rotina|Cabeçalho necessário (C)|Cabeçalho necessário (C++)|  
|-------------|---------------------------|-------------------------------|  
|`isnan`, `_isnanf`|\<math.h>|\<math.h> ou \<cmath>|  
|`_isnan`|\<float.h>|\<float.h> ou \<cfloat>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md).  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [_finite, _finitef](../../c-runtime-library/reference/finite-finitef.md)   
 [_fpclass, _fpclassf](../../c-runtime-library/reference/fpclass-fpclassf.md)
