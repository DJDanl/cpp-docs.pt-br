---
title: C3080 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3080
dev_langs:
- C++
helpviewer_keywords:
- C3080
ms.assetid: ff62a3f7-9b3b-44bd-b8d9-f3a8e5354560
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e563fb9ef2f78ee597ae49aca9152b8823deb7ea
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33246656"
---
# <a name="compiler-error-c3080"></a>C3080 de erro do compilador
'finalizer_function': um finalizador não pode ter um especificador de classe de armazenamento  
  
 Para obter mais informações, consulte [destruidores e finalizadores em como: definir e consumir classes e estruturas (C + + CLI)](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3080.  
  
```  
// C3080.cpp  
// compile with: /clr /c  
ref struct rs {  
protected:  
   static !rs(){}   // C3080  
   !rs(){}   // OK  
};  
```