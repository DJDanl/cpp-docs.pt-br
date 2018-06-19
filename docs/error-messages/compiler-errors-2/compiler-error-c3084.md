---
title: C3084 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3084
dev_langs:
- C++
helpviewer_keywords:
- C3084
ms.assetid: 0362cb70-e24e-476f-a24d-8f5bb97c3afd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 959d2eb46d7a2c85cc25adf681c760fa1f8dc4fa
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33246419"
---
# <a name="compiler-error-c3084"></a>C3084 de erro do compilador
'function': um finalizador/destruidor não pode ser 'palavra-chave'  
  
 Um finalizador ou destrutor foi declarado incorretamente.  
  
 Por exemplo, um destruidor não deve ser marcado como sealed.  O destruidor ficará inacessível para tipos derivados.  Para obter mais informações, consulte [substituições explícitas](../../windows/explicit-overrides-cpp-component-extensions.md) e [destruidores e finalizadores em como: definir e consumir classes e estruturas (C + + CLI)](../../dotnet/how-to-define-and-consume-classes-and-structs-cpp-cli.md#BKMK_Destructors_and_finalizers).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3084.  
  
```  
// C3084.cpp  
// compile with: /clr /c  
ref struct R {  
protected:  
   !R() sealed;   // C3084  
   !R() abstract;   // C3084  
   !R();  
};  
```