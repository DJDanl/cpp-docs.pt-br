---
title: C3868 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C3868
dev_langs:
- C++
helpviewer_keywords:
- C3868
ms.assetid: f0e45c2a-2149-4885-a03b-0d230069f03a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: b0f038d8e9e3ec344fffee579792a8c3a67fd6f1
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33268631"
---
# <a name="compiler-error-c3868"></a>C3868 de erro do compilador
'type': restrições de parâmetro genérico 'parameter' diferem na declaração  
  
 Várias declarações devem ter as mesmas restrições genéricas.  Para obter mais informações, consulte [Genéricos](../../windows/generics-cpp-component-extensions.md).  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir gera C3868.  
  
```  
// C3868.cpp  
// compile with: /clr /c  
interface struct I1;  
  
generic <typename T> ref struct MyStruct;  
generic <typename U> where U : I1 ref struct MyStruct;   // C3868  
  
// OK  
generic <typename T> ref struct MyStruct2;  
generic <typename U> ref struct MyStruct2;  
  
generic <typename T> where T : I1 ref struct MyStruct3;  
generic <typename U> where U : I1 ref struct MyStruct3;  
```