---
title: C3880 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3880
dev_langs:
- C++
helpviewer_keywords:
- C3880
ms.assetid: b0e05d1e-32d0-4034-9246-f37d23573ea9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 34cc36f3b5fb9571a707e4ffe4e75182e984e407
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33269751"
---
# <a name="compiler-error-c3880"></a>C3880 de erro do compilador
'var': não pode ser um membro de dados literal  
  
 O tipo de um [literal](../../windows/literal-cpp-component-extensions.md) atributo deve ser, ou em tempo de compilação conversível para um dos seguintes tipos:  
  
-   tipo integral  
  
-   cadeia de caracteres  
  
-   enumeração com um tipo integral ou subjacente  
  
 O exemplo a seguir gera C3880:  
  
```  
// C3880.cpp  
// compile with: /clr /c  
ref struct Y1 {  
   literal System::Decimal staticConst1 = 10;   // C3880  
   literal int staticConst2 = 10;   // OK  
};  
```