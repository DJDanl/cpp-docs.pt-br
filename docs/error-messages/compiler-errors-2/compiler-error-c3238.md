---
title: C3238 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3238
dev_langs:
- C++
helpviewer_keywords:
- C3238
ms.assetid: 19942497-b3c5-4df0-9144-142ced92468b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 33252d094847869fda07ad55563b085853681793
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33249882"
---
# <a name="compiler-error-c3238"></a>C3238 de erro do compilador
'type': um tipo com este nome já foi encaminhado para o assembly 'assembly'  
  
 Um tipo foi definido em um aplicativo cliente que também esteja definido, por meio da sintaxe, em um assembly referenciado de encaminhamento de tipo. Ambos os tipos não podem ser definidos no escopo do aplicativo.  
  
 Consulte [encaminhamento de tipo (C + + CLI)](../../windows/type-forwarding-cpp-cli.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir cria um assembly que contém um tipo que foi encaminhado de outro assembly.  
  
```  
// C3238.cpp  
// compile with: /clr /LD  
public ref class R {};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir cria um assembly usado para conter a definição de tipo, mas não só contém sintaxe de encaminhamento de tipo.  
  
```  
// C3238_b.cpp  
// compile with: /clr /LD  
#using "C3238.dll"  
[ assembly:TypeForwardedTo(R::typeid) ];  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3238.  
  
```  
// C3238_c.cpp  
// compile with: /clr /c  
// C3238 expected  
// Delete the following line to resolve.  
#using "C3238_b.dll"  
public ref class R {};  
```