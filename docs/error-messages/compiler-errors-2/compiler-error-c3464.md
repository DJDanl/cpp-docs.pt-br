---
title: C3464 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C3464
dev_langs: C++
helpviewer_keywords: C3464
ms.assetid: 0ede05dc-4486-4921-8e8c-78ab5a2e09c5
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 69ddfd70c92c306a9e68d5eacc568b24b07c9745
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3464"></a>C3464 de erro do compilador
'type' não pode ser enviado a um tipo aninhado  
  
 Encaminhamento de tipo não funciona em tipos aninhados.  
  
 Para obter mais informações, consulte [encaminhamento de tipo (C + + CLI)](../../windows/type-forwarding-cpp-cli.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir cria um componente.  
  
```  
// C3464.cpp  
// compile with: /LD /clr  
public ref class R {  
public:  
   ref class N {};  
};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3464.  
  
```  
// C3464_b.cpp  
// compile with: /clr /c  
#using "C3464.dll"  
[assembly:TypeForwardedTo(R::N::typeid)];   // C3464  
[assembly:TypeForwardedTo(R::typeid)];   // OK  
```