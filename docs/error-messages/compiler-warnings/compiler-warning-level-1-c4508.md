---
title: "Compilador (nível 1) de aviso C4508 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4508
dev_langs: C++
helpviewer_keywords: C4508
ms.assetid: c05f113b-b789-4df0-a4ef-78bce4767021
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 52139327831be17d6800f30b00f667da7d3b0376
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="compiler-warning-level-1-c4508"></a>Compilador C4508 de aviso (nível 1)
'function': função deve retornar um valor. presume-se que tipo de retorno 'void'  
  
 A função não tem nenhum tipo de retorno especificado. Nesse caso, C4430 também deve ser disparada, e o compilador implementa a correção relatada pelo C4430 (o valor padrão é int).  
  
 Para resolver este aviso, declare explicitamente o tipo de retorno de funções.  
  
 O exemplo a seguir gera C4508:  
  
```  
// C4508.cpp  
// compile with: /W1 /c  
#pragma warning (disable : 4430)  
func() {}   // C4508  
void func2() {}   // OK  
```