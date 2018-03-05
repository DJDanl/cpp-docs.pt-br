---
title: "Identificadores em expressões primárias | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- identifiers, designating objects
ms.assetid: d4602fe6-e7e6-40cc-9823-3b1ebf5d3d38
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e507c2b7c05f9ea818f55b10d222592fe0172cc0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="identifiers-in-primary-expressions"></a>Identificadores em expressões primárias
Os identificadores podem ser do tipo integral, **float**, `enum`, `struct`, **union**, matriz, ponteiro ou função. Um identificador é uma expressão primária contanto que tenha sido declarada como a designação de um objeto (nesse caso, um l-value) ou como uma função (nesse caso, um designador de função). Para obter uma definição de l-value, consulte [Expressões de L-Value e R-Value](../c-language/l-value-and-r-value-expressions.md).  
  
 O valor do ponteiro representado por um identificador de matriz não é uma variável, portanto, um identificador de matriz não pode formar o operando esquerdo de uma operação de atribuição e, em virtude disso, não é um l-value modificável.  
  
 Um identificador declarado como uma função representa um ponteiro cujo valor é o endereço da função. O ponteiro aborda uma função que retorna um valor de um tipo especificado. Portanto, os identificadores da função também não podem ser l-values em operações de atribuição. Para obter mais informações, consulte [Identificadores](../c-language/c-identifiers.md).  
  
## <a name="see-also"></a>Consulte também  
 [Expressões primárias C](../c-language/c-primary-expressions.md)