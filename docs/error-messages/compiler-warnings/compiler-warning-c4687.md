---
title: C4687 de aviso do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4687
dev_langs:
- C++
helpviewer_keywords:
- C4687
ms.assetid: 2f28e0b1-7358-4c88-bd70-aad8f0aa004c
caps.latest.revision: 5
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: f2dc847b6d75a563379b46e1375f93ceab9c7531
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-c4687"></a>C4687 de aviso do compilador
'class': uma classe abstrata lacrada não pode implementar uma interface de ''  
  
 Um tipo abstrato lacrado normalmente só é útil para manter funções de membro estático.  
  
 Para obter mais informações, consulte [abstrato](../../windows/abstract-cpp-component-extensions.md)e [lacrado](../../windows/sealed-cpp-component-extensions.md).  
  
 Por padrão, C4687 é emitida como um erro. Você pode suprimir C4687 com o [aviso](../../preprocessor/warning.md) pragma. Se você tiver certeza de que deseja implementar uma interface em um tipo abstrato lacrado, você pode suprimir C4687.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4687.  
  
```  
// C4687.cpp  
// compile with: /clr /c  
interface class A {};  
  
ref struct B sealed abstract : A {};   // C4687  
ref struct C sealed : A {};   // OK  
ref struct D abstract : A {};   // OK  
```
