---
title: C3753 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3753
dev_langs: C++
helpviewer_keywords: C3753
ms.assetid: a5b99e28-796c-4107-a673-97c2ae3bb2b9
caps.latest.revision: "3"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 93150c018159a649e772406a5a9a96836b87da8a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-error-c3753"></a>C3753 de erro do compilador
uma propriedade de generic não é permitida  
  
 Listas de parâmetro genérico só podem aparecer em classes gerenciadas, estruturas ou funções.  
  
 Para obter mais informações, consulte [genéricos](../../windows/generics-cpp-component-extensions.md) e [propriedade](../../windows/property-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3753.  
  
```  
// C3753.cpp  
// compile with: /clr /c  
ref struct A {  
   generic <typename T>  
   property int i;   // C3753 error  
};  
```