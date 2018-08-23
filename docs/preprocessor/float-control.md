---
title: float_control | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b9b94e5b8eccdc63735c7cb25faa7eacb1e23670
ms.sourcegitcommit: d4c803bd3a684d7951bf88dcecf1f14af43ae411
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/10/2018
ms.locfileid: "42541523"
---
# <a name="floatcontrol"></a>float_control
Especifica o comportamento de ponto flutuante para uma função.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
float_control( value,setting [push] | push | pop )  
```  
  
## <a name="flags"></a>Sinalizadores  
 
*valor*, *configuração* *[envio]*  
Especifica o comportamento de ponto flutuante. *valor* pode ser `precise` ou `except`. Para obter mais informações, consulte [/fp (especificar comportamento de ponto flutuante)](../build/reference/fp-specify-floating-point-behavior.md). *definindo* pode ser `on` ou `off`.  
  
Se *valor* é `precise`, as configurações para `precise` e `except` estão sendo especificados. `except` só pode ser definida como `on` quando `precise` também é definido como `on`.  
  
Se o opcional *por push* token é adicionado, atual definindo para *valor* é empurrado na pilha interna do compilador.  
  
*push*  
Enviar por push o atual **float_control** definindo na pilha interna do compilador  
  
*pop*  
Remove o **float_control** configuração da parte superior da pilha interna do compilador e faz com que a nova **float_control** configuração.  
  
## <a name="remarks"></a>Comentários  
 
Você não pode desativar `float_control precise` quando `except` está ativado. Da mesma forma, `precise` não pode ser desativado quando `fenv_access` está ativado. Para ir do modelo estrito para um modelo rápido com o **float_control** pragma, use o seguinte código:  
  
```  
#pragma float_control(except, off)  
#pragma fenv_access(off)  
#pragma float_control(precise, off)  
```  
  
Para ir do modelo rápido para um modelo estrito com o **float_control** pragma, use o seguinte código:  
  
```  
#pragma float_control(precise, on)  
#pragma fenv_access(on)  
#pragma float_control(except, on)  
```  
  
Outros pragmas de ponto flutuante incluem:  
  
- [fenv_access](../preprocessor/fenv-access.md)  
  
- [fp_contract](../preprocessor/fp-contract.md)  
  
## <a name="example"></a>Exemplo  
 
O exemplo a seguir mostra como capturar uma exceção de ponto flutuante de estouro usando o pragma **float_control**.  
  
```cpp  
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
