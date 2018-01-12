---
title: C2190 de erro do compilador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C2190
dev_langs: C++
helpviewer_keywords: C2190
ms.assetid: 34e15f85-d979-4948-80fc-46c414508a70
caps.latest.revision: "8"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 647c17808c1a91fb06923fd8601ee77c17732a2f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-error-c2190"></a>C2190 de erro do compilador
primeira lista de parâmetros mais de segundo  
  
 Uma função de C foi declarada uma segunda vez com uma lista de parâmetros mais curto. C não oferece suporte a funções sobrecarregadas.  
  
 O exemplo a seguir gera C2190:  
  
```  
// C2190.c  
// compile with: /Za /c  
void func( int, float );  
void func( int  );   // C2190, different parameter list  
void func2( int  );   // OK  
```