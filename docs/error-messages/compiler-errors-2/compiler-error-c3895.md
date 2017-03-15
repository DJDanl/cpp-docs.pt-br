---
title: C3895 de erro do compilador | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C3895
dev_langs:
- C++
helpviewer_keywords:
- C3895
ms.assetid: 771b9fe5-d6d4-4297-bf57-e2f857722155
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: b7c5412579a6e9e0cb32282525cab1168fb6009d
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-error-c3895"></a>C3895 de erro do compilador
'var': membros de dados de tipo não podem ser 'volátil'  
  
 Determinados tipos de membros de dados, por exemplo [literal](../../windows/literal-cpp-component-extensions.md) ou [initonly](../../dotnet/initonly-cpp-cli.md), não pode ser [volátil](../../cpp/volatile-cpp.md).  
  
 O exemplo a seguir gera C3895:  
  
```  
// C3895.cpp  
// compile with: /clr  
ref struct Y1 {  
   initonly  
   volatile int data_var2;   // C3895  
};  
```
