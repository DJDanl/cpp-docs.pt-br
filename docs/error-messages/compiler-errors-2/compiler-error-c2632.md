---
title: C2632 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C2632
dev_langs:
- C++
helpviewer_keywords:
- C2632
ms.assetid: b15a6b1b-42d2-4e1b-8660-e6bfde61052d
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 03a6d75ab9af6cd45ef982ff9d2e12640266c1b7
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2632"></a>C2632 de erro do compilador
'type1' seguido de 'type2' é inválido  
  
 Esse erro pode ser causado se faltarem código entre dois especificadores de tipo.  
  
 O exemplo a seguir gera C2632:  
  
```  
// C2632.cpp  
int float i;   // C2632  
```  
  
 Esse erro também pode ser gerado como resultado do trabalho de conformidade do compilador que foi feito para o Visual Studio .NET 2003. `bool`Agora é um tipo adequado. Nas versões anteriores, `bool` foi um typedef, e você pode criar identificadores com esse nome.  
  
 O exemplo a seguir gera C2632:  
  
```  
// C2632_2.cpp  
// compile with: /LD  
void f(int bool);   // C2632  
```  
  
 Para resolver esse erro para que o código é válido em versões do Visual Studio .NET 2003 e o Visual Studio .NET do Visual C++, renomeie o identificador.