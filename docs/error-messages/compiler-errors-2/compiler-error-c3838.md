---
title: C3838 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3838
dev_langs:
- C++
helpviewer_keywords:
- C3838
ms.assetid: d6f470c2-131a-4a8c-843a-254acd43da83
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dea27fde00773ccdaf7acb2dff135cd3cf894da4
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3838"></a>C3838 de erro do compilador
explicitamente não pode herdar de 'type'  
  
 Especificado `type` não pode atuar como uma classe base em qualquer classe.  
  
## <a name="example"></a>Exemplo
 O exemplo a seguir gera C3838:  
  
```  
// C3838a.cpp  
// compile with: /clr /c  
public ref class B : public System::Enum {};   // C3838  
```  
