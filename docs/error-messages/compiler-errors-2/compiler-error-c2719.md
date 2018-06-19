---
title: C2719 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2719
dev_langs:
- C++
helpviewer_keywords:
- C2719
ms.assetid: ea6236d3-8286-45cc-9478-c84ad3dd3c8e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: ee8779db363c506d2f4ad884e15f78ba8231caa7
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33233328"
---
# <a name="compiler-error-c2719"></a>C2719 de erro do compilador
'parameter': parâmetro formal com __declspec(align('#')) não alinhado  
  
 O [alinhar](../../cpp/align-cpp.md) `__declspec` modificador não é permitido em parâmetros de função. Alinhamento de parâmetro de função é controlado pela convenção de chamada usada. Para obter mais informações, consulte [convenções de chamada](../../cpp/calling-conventions.md).  
  
 O exemplo a seguir gera C2719 e mostra como corrigi-lo:  
  
```  
// C2719.cpp  
void func(int __declspec(align(32)) i);   // C2719  
// try the following line instead  
// void func(int i);  
```