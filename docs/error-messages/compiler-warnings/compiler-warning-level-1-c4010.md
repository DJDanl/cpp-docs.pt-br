---
title: "Compilador aviso (nível 1) C4010 | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
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
ms.openlocfilehash: d92f9dfcfef18e2fa9752c2787146ccfe74c7d9f
ms.lasthandoff: 02/25/2017

---
# <a name="compiler-warning-level-1-c4010"></a>Compilador C4010 de aviso (nível 1)
comentário de linha única contém caractere de continuação de linha  
  
 Um comentário de linha única, que é apresentado pelo / /, contém uma barra invertida (\\) que serve como um caractere de continuação de linha. O compilador considera a próxima linha seja uma continuação e tratá-la como um comentário.  
  
 Alguns sintaxe direcionadas editores não indicam a linha após o caractere de continuação como um comentário. Ignore cores em todas as linhas que causam esse aviso de sintaxe.  
  
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
