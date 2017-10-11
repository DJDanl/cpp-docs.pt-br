---
title: "Compilador (nível 1) de aviso C4010 | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C4010
dev_langs:
- C++
helpviewer_keywords:
- C4010
ms.assetid: d607a9ff-8f8f-45c0-b07b-3b2f439e5485
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: b6a0c84d5138cf2ae8a7a6279d9dc0fde9fe9512
ms.contentlocale: pt-br
ms.lasthandoff: 10/10/2017

---
# <a name="compiler-warning-level-1-c4010"></a>Compilador C4010 de aviso (nível 1)
comentário de linha única contém caractere de continuação de linha  
  
 Um comentário de linha única, que é apresentado pelo / /, contém uma barra invertida (\\) que serve como um caractere de continuação de linha. O compilador considera a próxima linha a ser uma continuação e tratá-la como um comentário.  
  
 Alguns sintaxe orientada para editores não indicam a linha após o caractere de continuação como um comentário. Ignore cores em todas as linhas que causam esse aviso de sintaxe.  
  
 O exemplo a seguir gera C4010:  
  
```  
// C4010.cpp  
// compile with: /WX  
int main() {  
   // the next line is also a comment because of the backslash \  
   int a = 3; // C4010  
   a++;  
}  
```
