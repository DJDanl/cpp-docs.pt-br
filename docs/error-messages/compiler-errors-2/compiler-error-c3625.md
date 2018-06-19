---
title: C3625 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3625
dev_langs:
- C++
helpviewer_keywords:
- C3625
ms.assetid: fdf49f21-d6b1-42f4-9eec-23b04ae8b4aa
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3a3462c3600a59c453fbde818c11b602c2254343
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33255170"
---
# <a name="compiler-error-c3625"></a>C3625 de erro do compilador
'native_type': um tipo nativo não pode derivar de gerenciada ou WinRT ' tipo '  
  
Uma classe nativo não pode herdar de gerenciada ou WinRT classe. Para obter mais informações, consulte [Classes e estruturas](../../windows/classes-and-structs-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
O exemplo a seguir gera C3625:  
  
```  
// C3625.cpp  
// compile with: /clr /c  
ref class B {};  
class D : public B {};   // C3625 cannot inherit from a managed class  
```  
