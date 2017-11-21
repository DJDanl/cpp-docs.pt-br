---
title: "Compilador (nível 4) de aviso C4680 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4680
dev_langs: C++
helpviewer_keywords: C4680
ms.assetid: 6e043f4c-c601-4b77-8130-920cff1d912e
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: f69e3c3a00be2de8ef428480e30bb76981a32cfe
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-4-c4680"></a>Compilador C4680 de aviso (nível 4)
'class': coclass não especifica uma interface padrão  
  
 Um [padrão](../../windows/default-cpp.md) interface não foi especificada para uma classe marcada com o [coclass](../../windows/coclass.md) atributo. Para um objeto para ser útil, ele deve implementar uma interface.  
  
 O exemplo a seguir gera C4680:  
  
```  
// C4680.cpp  
// compile with: /W4  
#include <windows.h>  
[module(name="MyModule")];  
  
[ object, uuid(373a1a4c-469b-11d3-a6b0-00c04f79ae8f) ]  
__interface IMyIface1  
{  
   HRESULT f1();  
};  
  
[ object, uuid(37331a4c-469b-11d3-a6b0-00c04f79ae8f) ]  
__interface IMyIface2  
{  
   HRESULT f1();  
};  
  
// to resolve C4680, specify a source interface also  
// for example, default(IMyIface1, IMyface2)  
[ coclass, uuid(373a1a4d-469b-11d3-a6b0-00c04f79ae8f), default(IMyIface1), source(IMyIface1) ]  
class CMyClass : public IMyIface1  
{   // C4680  
};  
  
int main()  
{  
}  
```