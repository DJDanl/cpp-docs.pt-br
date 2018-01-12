---
title: C4687 de aviso do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4687
dev_langs: C++
helpviewer_keywords: C4687
ms.assetid: 2f28e0b1-7358-4c88-bd70-aad8f0aa004c
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 41992e91b40fc17ef73ccb75828796b31ee3249e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-c4687"></a>C4687 de aviso do compilador
'class': uma classe sealed abstract não pode implementar uma interface 'interface'  
  
 Um tipo lacrado, abstract normalmente só é útil para manter as funções de membro estático.  
  
 Para obter mais informações, consulte [abstrata](../../windows/abstract-cpp-component-extensions.md)e [lacrado](../../windows/sealed-cpp-component-extensions.md).  
  
 Por padrão, C4687 é emitido como um erro. Você pode suprimir C4687 com o [aviso](../../preprocessor/warning.md) pragma. Se você tiver certeza de que deseja implementar uma interface em um tipo lacrado, abstract, você pode suprimir C4687.  
  
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