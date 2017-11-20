---
title: C3136 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3136
dev_langs: C++
helpviewer_keywords: C3136
ms.assetid: c77103cd-00f7-408e-b74b-4f8562039d31
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 9e6a8e3c958c6c1293b20451f632910001ef24f2
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3136"></a>C3136 de erro do compilador
'interface': uma interface COM só pode herdar de outra interface COM, 'interface' não é uma interface COM  
  
 Uma interface para o qual você aplicou um [atributo interface](../../windows/interface-attributes.md) herda de uma interface que não é uma interface COM. Uma interface COM, por fim, herda de `IUnknown`. Nenhuma interface precedido por um atributo de interface é uma interface COM.  
  
 O exemplo a seguir gera C3136:  
  
```  
// C3136.cpp  
#include "unknwn.h"  
  
__interface A   // C3136  
// try the following line instead  
// _interface A : IUnknown  
{  
   int a();  
};  
  
[object]  
__interface B : A  
{  
   int aa();  
};  
```