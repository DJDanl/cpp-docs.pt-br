---
title: C3469 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C3469
dev_langs: C++
helpviewer_keywords: C3469
ms.assetid: e23b0e5c-c704-4e67-a868-bf02c2055d85
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 64a82be68ec8722db40bb3f39e4898219e9e16c2
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3469"></a>C3469 de erro do compilador
'type': uma classe genérica não pode ser encaminhada  
  
 Você não pode usar o encaminhamento de tipo em uma classe genérica.  
  
 Para obter mais informações, consulte [encaminhamento de tipo (C + + CLI)](../../windows/type-forwarding-cpp-cli.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir cria um componente.  
  
```  
// C3469.cpp  
// compile with: /clr /LD  
generic<typename T>  
public ref class GR {};  
  
public ref class GR2 {};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3466.  
  
```  
// C3469_b.cpp  
// compile with: /clr /c  
#using "C3469.dll"  
[assembly:TypeForwardedTo(GR::typeid)];   // C3469  
[assembly:TypeForwardedTo(GR2::typeid)];   // OK  
```