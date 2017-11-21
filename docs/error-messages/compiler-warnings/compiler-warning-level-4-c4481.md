---
title: "Compilador (nível 4) de aviso C4481 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4481
dev_langs: C++
helpviewer_keywords: C4481
ms.assetid: 7bfd4e0c-b452-4e6c-b7c4-ac5cc93fe4ea
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: c61ee3729a859d1ed2d9dd0ba9fe4ce253634bc0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-4-c4481"></a>Compilador C4481 de aviso (nível 4)
extensão não padrão usada: substituir especificador 'palavra-chave'  
  
 Uma palavra-chave que não está em C++ padrão, por exemplo, um dos especificadores de substituição também funciona em /clr foi usada.  Para obter mais informações, consulte  
  
-   [/CLR (common Language Runtime Compilation)](../../build/reference/clr-common-language-runtime-compilation.md)  
  
-   [Especificadores de substituição](../../windows/override-specifiers-cpp-component-extensions.md)  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4481.  
  
```  
// C4481.cpp  
// compile with: /W4 /c  
class B {  
   virtual void f(unsigned);  
};  
  
class C : B {  
   void f(unsigned) override;   // C4481  
   void f2(unsigned);  
};  
```