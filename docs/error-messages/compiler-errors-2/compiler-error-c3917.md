---
title: C3917 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C3917
dev_langs: C++
helpviewer_keywords: C3917
ms.assetid: a24cd0c9-262f-46e5-9488-1c01f945933d
caps.latest.revision: "11"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bff35b18457035ea03035bd98d467dd20e1d34be
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c3917"></a>C3917 de erro do compilador
'*propriedade*': estilo de declaração de construção obsoleta  
  
Uma definição de propriedade ou evento usado a sintaxe de uma versão anterior do Visual Studio 2005.  
  
Para obter mais informações, consulte [propriedade](../../windows/property-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
  
```cpp  
// C3917.cpp  
// compile with: /clr /c  
public ref class  C {  
private:  
   int m_length;  
public:  
   C() {  
      m_length = 0;  
   }  
  
   property int get_Length();   // C3917  
  
   // The correct property definition:  
   property int Length {  
      int get() {  
         return m_length;  
      }  
  
      void set( int i ) {  
         m_length = i;  
      }  
   }  
};  
```