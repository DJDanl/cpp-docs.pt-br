---
title: "Literais da cadeia de caracteres em expressões primárias | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: string literals, in primary expressions
ms.assetid: 3ec31278-527b-40d2-8c83-6b09e2d81ca6
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0920280f672b1c45d317ade4c592a6b93356fb8f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="string-literals-in-primary-expressions"></a>literais String em expressões primárias
Um “literal de cadeia de caracteres” é um caractere, um caractere largo ou uma sequência de caracteres adjacentes entre aspas duplas. Como não são variáveis, nem literais de cadeia de caracteres nem seus elementos podem ser o operando esquerdo em uma operação de atribuição. O tipo de uma literal de cadeia de caracteres é uma matriz de `char` (ou uma matriz de `wchar_t` para literais de cadeia de caracteres largos). As matrizes nas expressões são convertidas em ponteiros. Consulte [Literais de cadeia de caracteres](../c-language/c-string-literals.md) para obter mais informações sobre cadeias de caracteres.  
  
## <a name="see-also"></a>Consulte também  
 [Expressões primárias C](../c-language/c-primary-expressions.md)