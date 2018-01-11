---
title: "Compilador (nível 4) de aviso C4634 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: C4634
dev_langs: C++
helpviewer_keywords: C4634
ms.assetid: 3e3496ce-2ac7-43d0-a48a-f514c950e81d
caps.latest.revision: "13"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 4f2812675fd47c72bc0825f9afb870af2451731d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-4-c4634"></a>Compilador C4634 de aviso (nível 4)
Comentário de documento XML: não pode ser aplicado: motivo  
  
 Marcações de documentação XML não podem ser aplicadas a todos os C++ constrói.  Por exemplo, você não pode adicionar um comentário de documentação para um namespace ou o modelo.  
  
 Para obter mais informações, consulte [documentação XML](../../ide/xml-documentation-visual-cpp.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4634.  
  
```  
// C4634.cpp  
// compile with: /W4 /doc /c  
/// This is a namespace.   // C4634  
namespace hello {  
   class MyClass  {};  
};  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C4634.  
  
```  
// C4634_b.cpp  
// compile with: /W4 /doc /c  
/// This is a template.   // C4634  
template <class T>  
class MyClass  {};  
```