---
title: float_control | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- vc-pragma.float_control
- float_control_CPP
dev_langs:
- C++
helpviewer_keywords:
- float_control pragma
- pragmas, float_control
ms.assetid: 4f4ba5cf-3707-413e-927d-5ecdbc0a9a43
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1525b92b43a688cdec970c646613aa4474d44cc3
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="floatcontrol"></a>float_control
Especifica o comportamento de ponto flutuante para uma função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
float_control( value,setting [push] | push | pop )  
```  
  
## <a name="flags"></a>Sinalizadores  
 `value`, `setting` **[push]**  
 Especifica o comportamento de ponto flutuante. `value` pode ser **preciso** ou **exceto**. Para obter mais informações, consulte [/fp (especificar comportamento de ponto flutuante)](../build/reference/fp-specify-floating-point-behavior.md). `setting` pode ser **na** ou **off**.  
  
 Se `value` é **preciso**, as configurações de **preciso** e **exceto** estão sendo especificados. **exceto** só pode ser definida como **na** quando **preciso** também é definido como **em**.  
  
 Se opcional **push** token é adicionado, atual configuração `value` é enviada em para a pilha do compilador interno.  
  
 **push**  
 Enviar por push a configuração atual de `float_control` para a pilha interna do compilador  
  
 **pop**  
 Remove o `float_control` configuração da parte superior da pilha do compilador interno e faz com que o novo `float_control` configuração.  
  
## <a name="remarks"></a>Comentários  
 Você não pode ativar `float_control precise` off quando **exceto** está em. Da mesma forma, **preciso** não podem ser desativadas quando `fenv_access` está em. Para ir do modelo estrito para um modelo rápido com o pragma `float_control`, use o seguinte código:  
  
```  
#pragma float_control(except, off)  
#pragma fenv_access(off)  
#pragma float_control(precise, off)  
// The following line is needed on Itanium processors  
#pragma fp_contract(on)  
```  
  
 Para ir do modelo rápido para um modelo estrito com o pragma `float_control`, use o seguinte código:  
  
```  
#pragma float_control(precise, on)  
#pragma fenv_access(on)  
#pragma float_control(except, on)  
// The following line is needed on Itanium processors.  
#pragma fp_contract(off)  
```  
  
 Outros pragmas de ponto flutuante incluem:  
  
-   [fenv_access](../preprocessor/fenv-access.md)  
  
-   [fp_contract](../preprocessor/fp-contract.md)  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como capturar uma exceção de ponto flutuante de estouro usando o pragma `float_control`.  
  
```  
// pragma_directive_float_control.cpp  
// compile with: /EHa  
#include <stdio.h>  
#include <float.h>  
  
double func( ) {  
   return 1.1e75;  
}  
  
#pragma float_control (except,on)  
  
int main( ) {  
   float u[1];  
   unsigned int currentControl;  
   errno_t err;  
  
   err = _controlfp_s(&currentControl, ~_EM_OVERFLOW, _MCW_EM);  
   if (err != 0)  
      printf_s("_controlfp_s failed!\n");  
  
   try  {  
      u[0] = func();  
      printf_s ("Fail");     
      return(1);  
   }   
  
   catch (...)  {  
      printf_s ("Pass");  
      return(0);  
   }  
}  
```  
  
```Output  
Pass  
```  
  
## <a name="see-also"></a>Consulte também  
 [Diretivas Pragma e a palavra-chave __Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)