---
title: C2632 de erro do compilador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2632
dev_langs:
- C++
helpviewer_keywords:
- C2632
ms.assetid: b15a6b1b-42d2-4e1b-8660-e6bfde61052d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: c3bc07c404a1f4d667045fdfea24009e7d20ad69
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33232627"
---
# <a name="compiler-error-c2632"></a>C2632 de erro do compilador
'type1' seguido de 'type2' é inválido  
  
 Esse erro pode ser causado se faltarem código entre dois especificadores de tipo.  
  
 O exemplo a seguir gera C2632:  
  
```  
// C2632.cpp  
int float i;   // C2632  
```  
  
 Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003. `bool` Agora é um tipo adequado. Nas versões anteriores, `bool` foi um typedef, e você pode criar identificadores com esse nome.  
  
 O exemplo a seguir gera C2632:  
  
```  
// C2632_2.cpp  
// compile with: /LD  
void f(int bool);   // C2632  
```  
  
 Para resolver esse erro para que o código é válido em versões do Visual Studio .NET 2003 e o Visual Studio .NET do Visual C++, renomeie o identificador.