---
title: C3384 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3384
dev_langs:
- C++
helpviewer_keywords:
- C3384
ms.assetid: c9f92c6a-62a9-4333-b2b1-bc55c7f288b6
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ab09df08edb9f1d5808f2214535c76b20fda62b3
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="compiler-error-c3384"></a>C3384 de erro do compilador
'type_parameter': a restrição de valor e a restrição ref são mutuamente exclusivos  
  
 Não é possível restringir um tipo genérico para ambos `value class` e `ref class`.  
  
 Consulte [restrições em parâmetros de tipo genérico (C + + CLI)](../../windows/constraints-on-generic-type-parameters-cpp-cli.md) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3384.  
  
```  
// C3384.cpp  
// compile with: /c /clr  
generic <typename T>  
where T : ref class  
where T : value class   // C3384  
ref class List {};  
```