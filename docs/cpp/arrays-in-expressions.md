---
title: "Matrizes em expressões | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- expressions [C++], arrays in
- arrays [C++], in expressions
ms.assetid: 6e5a795b-d6bd-4e39-b313-6a20d47c4d4b
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: ec97fba837ffae0a03ff8d4fc3d85c4011aa59c6
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="arrays-in-expressions"></a>Matrizes em expressões
Quando um identificador de um tipo de matriz é exibido em uma expressão diferente de `sizeof`, endereço de rede (**&**), ou inicialização de uma referência, ele será convertido em um ponteiro para o primeiro elemento da matriz. Por exemplo:  
  
```  
char szError1[] = "Error: Disk drive not ready.";  
char *psz = szError1;  
```  
  
 O ponteiro `psz` aponta para o primeiro elemento da matriz `szError1`. Observe que as matrizes, ao contrário dos ponteiros, não são l-values modificáveis. Dessa forma, a atribuição a seguir é inválida:  
  
```  
szError1 = psz;  
```  
  
## <a name="see-also"></a>Consulte também  
 [Matrizes](../cpp/arrays-cpp.md)
