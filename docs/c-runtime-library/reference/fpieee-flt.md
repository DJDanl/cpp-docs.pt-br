---
title: _fpieee_flt | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
apiname:
- _fpieee_flt
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
- api-ms-win-crt-runtime-l1-1-0.dll
apitype: DLLExport
f1_keywords:
- fpieee_flt
- _fpieee_flt
dev_langs:
- C++
helpviewer_keywords:
- _fpieee_flt function
- exception handling, floating-point
- floating-point exception handling
- fpieee_flt function
ms.assetid: 2bc4801e-0eed-4e73-b518-215da8cc9740
caps.latest.revision: 15
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
ms.translationtype: Machine Translation
ms.sourcegitcommit: e257f037a05c45f5b98e64ea55bd125af443b0be
ms.openlocfilehash: c2e9f909f3e7e778845d8fefebe5d8b1604af489
ms.contentlocale: pt-br
ms.lasthandoff: 03/30/2017

---
# <a name="fpieeeflt"></a>_fpieee_flt
Invoca um manipulador de interceptação definido pelo usuário para exceções de ponto flutuante do IEEE.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
int _fpieee_flt(   
   unsigned long excCode,  
   struct _EXCEPTION_POINTERS *excInfo,  
   int handler(_FPIEEE_RECORD *)   
);  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `excCode`  
 Código da exceção.  
  
 `excInfo`  
 Ponteiro para a estrutura de informações de exceção do Windows NT.  
  
 `handler`  
 Ponteiro para a rotina do manipulador de interceptação do IEEE do usuário.  
  
## <a name="return-value"></a>Valor de retorno  
 O valor retornado de `_fpieee_flt` é o valor retornado por `handler`. Sendo assim, a rotina de filtro do IEEE pode ser usada na cláusula except de um mecanismo de SEH (manipulação de exceção estruturada).  
  
## <a name="remarks"></a>Comentários  
 A função `_fpieee_flt` invoca um manipulador de interceptação definido pelo usuário para exceções de ponto flutuante do IEEE e fornece a ele todas as informações relevantes. Essa rotina serve como um filtro de exceção no mecanismo de SEH, que invoca seu próprio manipulador de exceção do IEEE quando necessário.  
  
 A estrutura `_FPIEEE_RECORD`, definida em Fpieee.h, contém informações referentes a uma exceção de ponto flutuante do IEEE. Essa estrutura é passada para o manipulador de interceptação definido pelo usuário por `_fpieee_flt`.  
  
|Campo _FPIEEE_RECORD|Descrição|  
|----------------------------|-----------------|  
|`unsigned int RoundingMode`, `unsigned int Precision`|Esses campos contêm informações sobre o ambiente de ponto flutuante no momento em que a exceção ocorreu.|  
|`unsigned int Operation`|Indica o tipo de operação que causou a interceptação. Se o tipo for uma comparação (`_FpCodeCompare`), você poderá fornecer um dos valores especiais de `_FPIEEE_COMPARE_RESULT` (conforme definido em Fpieee.h) no campo `Result.Value`. O tipo de conversão (`_FpCodeConvert`) indica que a interceptação ocorreu durante uma operação de conversão de ponto flutuante. Examine os tipos `Operand1` e `Result` para determinar o tipo de conversão que está sendo tentada.|  
|`_FPIEEE_VALUE Operand1`, `_FPIEEE_VALUE Operand2`, `_FPIEEE_VALUE Result`|Essas estruturas indicam os tipos e valores do resultado e dos operandos propostos:<br /><br /> `OperandValid` Sinalizador que indica se o valor de resposta é válido.<br /><br /> `Format` Tipo de dados do valor correspondente. O tipo de formato pode ser retornado, mesmo que o valor correspondente não seja válido.<br /><br /> `Value` Valor de dados do resultado ou do operando.|  
|`_FPIEEE_EXCEPTION_FLAGS Cause`, `_FPIEEE_EXCEPTION_FLAGS Enable`, `_FPIEEE_EXCEPTION_FLAGS Status`|_FPIEEE_EXCEPTION_FLAGS contém um campo de bits por tipo de exceção de ponto flutuante.<br /><br /> Há uma correspondência entre esses campos e os argumentos usados para mascarar as exceções fornecidas a [_controlfp](../../c-runtime-library/reference/control87-controlfp-control87-2.md).<br /><br /> O significado exato de cada bit depende do contexto:<br /><br /> `Cause` Cada bit definido indica a exceção específica que foi gerada.<br /><br /> `Enable` Cada bit definido indica que a exceção específica está sendo desmascarada.<br /><br /> `Status` Cada bit definido indica que a exceção específica está pendente. Isso inclui exceções que não foram geradas porque estavam mascaradas por `_controlfp`.|  
  
 Exceções pendentes desabilitadas são geradas quando você as habilita. Isso pode resultar em um comportamento indefinido ao usar `_fpieee_flt` como um filtro de exceção. Sempre chame [_clearfp](../../c-runtime-library/reference/clear87-clearfp.md) antes de habilitar exceções de ponto flutuante.  
  
## <a name="requirements"></a>Requisitos  
  
|Função|Cabeçalho necessário|  
|--------------|---------------------|  
|`_fpieee_flt`|\<fpieee.h>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## <a name="example"></a>Exemplo  
  
```  
// crt_fpieee.c  
// This program demonstrates the implementation of  
// a user-defined floating-point exception handler using the  
// _fpieee_flt function.  
  
#include <fpieee.h>  
#include <excpt.h>  
#include <float.h>  
#include <stddef.h>  
  
int fpieee_handler( _FPIEEE_RECORD * );  
  
int fpieee_handler( _FPIEEE_RECORD *pieee )  
{  
   // user-defined ieee trap handler routine:  
   // there is one handler for all   
   // IEEE exceptions  
  
   // Assume the user wants all invalid   
   // operations to return 0.  
  
   if ((pieee->Cause.InvalidOperation) &&   
       (pieee->Result.Format == _FpFormatFp32))   
   {  
        pieee->Result.Value.Fp32Value = 0.0F;  
  
        return EXCEPTION_CONTINUE_EXECUTION;  
   }  
   else  
      return EXCEPTION_EXECUTE_HANDLER;  
}  
  
#define _EXC_MASK    \  
    _EM_UNDERFLOW  + \  
    _EM_OVERFLOW   + \  
    _EM_ZERODIVIDE + \  
    _EM_INEXACT  
  
int main( void )  
{  
   // ...  
  
   __try {  
      // unmask invalid operation exception  
      _controlfp_s(NULL, _EXC_MASK, _MCW_EM);   
  
      // code that may generate   
      // fp exceptions goes here  
   }  
   __except ( _fpieee_flt( GetExceptionCode(),  
                GetExceptionInformation(),  
                fpieee_handler ) ){  
  
      // code that gets control   
  
      // if fpieee_handler returns  
      // EXCEPTION_EXECUTE_HANDLER goes here  
  
   }  
  
   // ...  
}  
```  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [_control87, _controlfp, \__control87_2](../../c-runtime-library/reference/control87-controlfp-control87-2.md)   
 [_controlfp_s](../../c-runtime-library/reference/controlfp-s.md)
