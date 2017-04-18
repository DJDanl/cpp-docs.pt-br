---
title: C3238 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C3238
dev_langs:
- C++
helpviewer_keywords:
- C3238
ms.assetid: 19942497-b3c5-4df0-9144-142ced92468b
caps.latest.revision: 9
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- ru-ru
- zh-cn
- zh-tw
translation.priority.mt:
- cs-cz
- pl-pl
- pt-br
- tr-tr
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 556b8b218db52147c2c2631de8e23dc90ad5e12a
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3238"></a>C3238 de erro do compilador
'type': um tipo com esse nome já foi encaminhado para o assembly 'assembly'  
  
 Um tipo foi definido em um aplicativo cliente que também é definido, por meio do tipo de encaminhamento de sintaxe, em um assembly referenciado. Ambos os tipos não podem ser definidos no escopo do aplicativo.  
  
 Consulte [encaminhamento de tipo (C + + / CLI)](../../windows/type-forwarding-cpp-cli.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir cria um assembly que contém um tipo que foi encaminhado de outro assembly.  
  
```  
// C3238.cpp  
// compile with: /clr /LD  
public ref class R {};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir cria um assembly usado para conter a definição de tipo, mas não apenas contém o tipo de sintaxe de encaminhamento.  
  
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
