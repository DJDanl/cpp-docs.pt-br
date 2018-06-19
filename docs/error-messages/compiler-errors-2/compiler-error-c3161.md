---
title: C3161 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3161
dev_langs:
- C++
helpviewer_keywords:
- C3161
ms.assetid: 1fe2be85-a343-487b-8476-bf9e257eb29d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: f2d7aff3eb41c03f5be774704922340ac54126fc
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33250697"
---
# <a name="compiler-error-c3161"></a>C3161 de erro do compilador
'interface': aninhar classe, struct, união ou interface em uma interface é inválido; aninhar interface em uma classe, struct ou união é inválido  
  
 Um [interface](../../cpp/interface.md) só pode aparecer no escopo global ou dentro de um namespace. Uma classe, struct ou union não pode aparecer em uma interface.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3161.  
  
```  
// C3161.cpp  
// compile with: /c  
__interface X {  
   __interface Y {};   // C3161 A nested interface  
};  
```