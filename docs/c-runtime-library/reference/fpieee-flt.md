---
title: "_fpieee_flt | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apiname: 
  - "_fpieee_flt"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
  - "api-ms-win-crt-runtime-l1-1-0.dll"
apitype: "DLLExport"
f1_keywords: 
  - "fpieee_flt"
  - "_fpieee_flt"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "Função _fpieee_flt"
  - "tratamento de exceções, ponto flutuante"
  - "tratamento de exceções de ponto flutuante"
  - "Função fpieee_flt"
ms.assetid: 2bc4801e-0eed-4e73-b518-215da8cc9740
caps.latest.revision: 15
caps.handback.revision: 15
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# _fpieee_flt
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Invoca um manipulador de armadilha definido pelo usuário para exceções de ponto flutuante IEEE.  
  
## Sintaxe  
  
```  
int _fpieee_flt(   
   unsigned long excCode,  
   struct _EXCEPTION_POINTERS *excInfo,  
   int handler(_FPIEEE_RECORD *)   
);  
```  
  
#### Parâmetros  
 `excCode`  
 Código da exceção.  
  
 `excInfo`  
 Ponteiro para a estrutura de informações da exceção do Windows NT.  
  
 `handler`  
 Ponteiro para a rotina de armadilha\- manipulador do IEEE do usuário.  
  
## Valor de retorno  
 O valor de retorno de `_fpieee_flt` é o valor retornado por `handler`.  Como tal, a rotina de filtro IEEE pode ser usada na cláusula FROM de um mecanismo estruturado de \(SEH\) manipulação de exceções gerais.  
  
## Comentários  
 A função de `_fpieee_flt` invoca um manipulador de armadilha definido pelo usuário para exceções de ponto flutuante IEEE e fornecê\-lo com todas as informações relevantes.  Esta rotina serve como um filtro de exceção no mecanismo, que invoca seu próprio manipulador de exceção IEEE quando necessário.  
  
 A estrutura de `_FPIEEE_RECORD` , definida em Fpieee.h, contém informações que pertencem a uma exceção de ponto flutuante IEEE.  Essa estrutura é passada para o manipulador de armadilha definida pelo usuário por `_fpieee_flt`.  
  
|campo de \_FPIEEE\_RECORD|Descrição|  
|-------------------------------|---------------|  
|`unsigned int RoundingMode`, `unsigned int Precision`|Esses campos contiverem informações sobre o ambiente de ponto flutuante na exceção.|  
|`unsigned int Operation`|Indica o tipo de operação que causou a armadilha.  Se o tipo for uma comparação \(`_FpCodeCompare`\), você pode fornecer um dos valores especiais de `_FPIEEE_COMPARE_RESULT` \(conforme definido em Fpieee.h\) no campo de `Result.Value` .  O tipo de conversão \(`_FpCodeConvert`\) indica que a armadilha durante uma operação de ponto flutuante de conversão.  Você pode assistir `Operand1` e `Result` tipos para determinar o tipo de conversão que está sendo tentada.|  
|`_FPIEEE_VALUE Operand1`, `_FPIEEE_VALUE Operand2`, `_FPIEEE_VALUE Result`|Essas estruturas indica os tipos e os valores de resultado dos operandos e propõe:<br /><br /> `OperandValid` Sinalizador que indica se o valor de resposta é válido.<br /><br /> `Format` Tipo de dados do valor correspondente.  O tipo de formato pode ser retornado se o valor correspondente não é válido.<br /><br /> `Value` Valor de dados do resultado ou do operando.|  
|`_FPIEEE_EXCEPTION_FLAGS Cause`, `_FPIEEE_EXCEPTION_FLAGS Enable`, `_FPIEEE_EXCEPTION_FLAGS Status`|o \_FPIEEE\_EXCEPTION\_FLAGS contém um campo de bit pelo tipo de exceção de ponto flutuante.<br /><br /> Há uma correspondência entre esses campos e os argumentos usados para mascarar as exceções fornecidas a [\_controlfp](../Topic/_control87,%20_controlfp,%20__control87_2.md).<br /><br /> O significado de cada bit exato depende do contexto:<br /><br /> `Cause` Cada bit do conjunto específico que indica a exceção foi gerada.<br /><br /> `Enable` Cada bit do conjunto indica que a exceção específica estiver desmascarada atualmente.<br /><br /> `Status` Cada bit do conjunto indica que a exceção específica está pendente no momento.  Isso inclui as exceções que não foram gerados como foram mascaradas por `_controlfp`.|  
  
 Durante as exceções que são desabilitadas são gerados quando você habilita as.  Isso pode resultar em um comportamento indefinido ao usar `_fpieee_flt` como um filtro de exceção.  Sempre chamada [\_clearfp](../../c-runtime-library/reference/clear87-clearfp.md) antes de habilitar as exceções de ponto flutuante.  
  
## Requisitos  
  
|Função|Cabeçalho necessário|  
|------------|--------------------------|  
|`_fpieee_flt`|\<fpieee.h\>|  
  
 Para obter mais informações sobre compatibilidade, consulte [Compatibilidade](../../c-runtime-library/compatibility.md) na Introdução.  
  
## Exemplo  
  
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
  
## Equivalência do .NET Framework  
 Não aplicável. Para chamar a função padrão de C, use `PInvoke`. Para obter mais informações, consulte [Exemplos de chamadas de plataformas](../Topic/Platform%20Invoke%20Examples.md).  
  
## Consulte também  
 [Suporte de ponto flutuante](../../c-runtime-library/floating-point-support.md)   
 [\_control87, \_controlfp, \_\_control87\_2](../Topic/_control87,%20_controlfp,%20__control87_2.md)   
 [\_controlfp\_s](../../c-runtime-library/reference/controlfp-s.md)