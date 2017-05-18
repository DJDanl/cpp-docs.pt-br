---
title: "Compilador aviso (nível 4) C4634 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- C4634
dev_langs:
- C++
helpviewer_keywords:
- C4634
ms.assetid: 3e3496ce-2ac7-43d0-a48a-f514c950e81d
caps.latest.revision: 13
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: af8555307346dce78f59b55ec3429305206ff2da
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-4-c4634"></a>Compilador C4634 de aviso (nível 4)
Comentário de documento XML: não pode ser aplicada: motivo  
  
 Marcas de documentação XML não podem ser aplicadas ao C++ todas as construções.  Por exemplo, você não pode adicionar um comentário de documentação para um namespace ou um modelo.  
  
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
