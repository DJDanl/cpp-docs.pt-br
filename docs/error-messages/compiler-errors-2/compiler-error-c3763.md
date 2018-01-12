---
title: C3763 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3763
dev_langs: C++
helpviewer_keywords: C3763
ms.assetid: 58b1f079-cd1d-46e0-9431-ea18210106b7
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a299d6caafc0c6cc4349a602a4849d05cad7015d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3763"></a>C3763 de erro do compilador
'type': 'retval' e 'out' só pode aparecer em um tipo de ponteiro de dados  
  
 O [out](../../windows/out-cpp.md) ou [retval](../../windows/retval.md) atributos só podem aparecer em parâmetros de ponteiro de tipo. Remova o atributo ou torne o parâmetro de ponteiro de tipo.  
  
 O exemplo a seguir gera C3763:  
  
```  
// C3763.cpp  
#define _ATL_ATTRIBUTES 1  
#include <atlbase.h>  
#include <atlplus.h>  
#include <atlcom.h>  
  
[ module(name=test) ];  
  
[ dispinterface, uuid("00000000-0000-0000-0000-000000000001") ]  
__interface IF84 : IDispatch  
{  
   [id(0x00000002)]HRESULT m2([out]unsigned char);  
};  
  
[ coclass, uuid("00000000-0000-0000-0000-000000000002") ]  
class CF84 : public IF84  
{   // C3763  
public:  
   HRESULT __stdcall m2(unsigned char i)  
   {  
      return S_OK;  
   }  
};  
  
int main()  
{  
}  
```