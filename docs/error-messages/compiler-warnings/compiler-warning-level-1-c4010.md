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
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1a56adb54c4a4b7123bde706a2b6b8bdcb184775
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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