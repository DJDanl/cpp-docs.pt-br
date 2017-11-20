---
title: C2553 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2553
dev_langs: C++
helpviewer_keywords: C2553
ms.assetid: 64bc1e9a-627f-4ce9-b7bc-dc911bdb9180
caps.latest.revision: "9"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 623a09c54333ef62de7a7924cc4be02ff1b2c726
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c2553"></a>C2553 de erro do compilador
'base_function': função virtual de substituição retornar tipo difere de 'override_function'  
  
 Uma função em uma classe derivada tentou substituir uma função virtual em uma classe base, mas a função de classe derivada não tem o mesmo tipo de retorno da função da classe base.  Uma assinatura de função de substituição deve corresponder à assinatura da função que está sendo substituída.  
  
 O exemplo a seguir gera C2553:  
  
```  
// C2553.cpp  
// compile with: /clr /c  
ref struct C {  
   virtual void f();  
};  
  
ref struct D : C {  
   virtual int f() override ;   // C2553   
  
   // try the following line instead  
   // virtual void f() override;  
};  
```