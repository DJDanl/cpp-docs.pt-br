---
title: Erro fatal C1071 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1071
dev_langs:
- C++
helpviewer_keywords:
- C1071
ms.assetid: 489f1786-370e-4ecd-af67-538fe6e5bd4e
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.translationtype: MT
ms.sourcegitcommit: 35b46e23aeb5f4dbfd2a0dd44b906389dd5bfc88
ms.openlocfilehash: acd48401d3abc17d994e861bf6fb046450d88ca6
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="fatal-error-c1071"></a>Erro fatal C1071
fim de arquivo inesperado encontrado no comentário  
  
 O compilador chegou ao fim do arquivo durante a verificação de um comentário.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Falta o terminador de comentário (* /).  
  
2.  Caractere de nova linha ausente após um comentário na última linha de um arquivo de origem.  
  
 O exemplo a seguir gera C1071:  
  
```  
// C1071.cpp  
int main() {  
}  
  
/* this comment is fine */  
/* forgot the closing tag        // C1071  
```
