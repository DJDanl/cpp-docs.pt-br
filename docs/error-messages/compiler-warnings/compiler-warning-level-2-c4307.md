---
title: "Compilador (nível 2) do aviso C4307 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: C4307
dev_langs: C++
helpviewer_keywords: C4307
ms.assetid: 7cca11e9-be61-49e4-8b15-88b84f0cbf07
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 31a17a5130bf8068928ba5840f792fca54e45cf2
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="compiler-warning-level-2-c4307"></a>Compilador C4307 de aviso (nível 2)
'operator': estouro de constante integral  
  
 O operador é usado em uma expressão que resulta em uma constante inteira ultrapassar os limites de espaço alocado para ele. Talvez seja necessário usar um tipo maior para a constante. Um **assinado int** contém um valor menor que um `unsigned int` porque o **assinado int** usa um bit para representar o logon.  
  
 O exemplo a seguir gera C4307:  
  
```  
// C4307.cpp  
// compile with: /W2  
int i = 2000000000 + 2000000000;   // C4307  
int j = (unsigned)2000000000 + 2000000000;   // OK  
  
int main()  
{  
}  
```