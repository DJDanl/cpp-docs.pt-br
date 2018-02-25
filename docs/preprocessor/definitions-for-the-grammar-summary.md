---
title: "Definições para o resumo de gramática | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- preprocessor, definitions
- preprocessor
ms.assetid: cc752dc8-6f4e-4347-a556-e0d9ef4c46bd
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 755533d59b9b893da4a657db6da2ea80f13138b5
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="definitions-for-the-grammar-summary"></a>Definições para o resumo de gramática
Os terminais são pontos de extremidade em uma definição de sintaxe. Nenhuma outra resolução é possível. Os terminais incluem o conjunto de palavras reservadas e identificadores definidos pelo usuário.  
  
Os não terminais são espaços reservados na sintaxe. A maioria é definida em outra parte deste resumo da sintaxe. As definições podem ser recursivas. Sem os terminais seguintes são definidos no [convenções lexicais](../cpp/lexical-conventions.md) seção o *referência de linguagem C++*:  
  
`constant`, *constant-expression*, *identifier*, *keyword*, `operator`, `punctuator`  
  
Um componente opcional é indicado pelo aceitação subscrita. Por exemplo, o exemplo a seguir indica uma expressão opcional incluída em chaves:  
  
**{** *expression*opt **}**  
  
## <a name="see-also"></a>Consulte também  
[Resumo de gramática (C/C++)](../preprocessor/grammar-summary-c-cpp.md)