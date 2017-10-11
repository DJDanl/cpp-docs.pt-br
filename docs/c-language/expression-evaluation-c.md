---
title: "Avaliação de expressão (C) | Microsoft Docs"
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
- expression evaluation
- expressions [C++], evaluating
ms.assetid: 9493f8cc-64a2-4284-9aaf-26eec11c4f40
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 16d1bf59dfd4b3ef5f037aed9c0f6febfdf1a2e8
ms.openlocfilehash: 21b78b659b4d4cd8f3bb5db849b3c64a5f66f971
ms.contentlocale: pt-br
ms.lasthandoff: 10/09/2017

---
# <a name="expression-evaluation-c"></a>Avaliação de expressão (C)
Expressões que envolvem atribuição, incremento unário, diminuição unária ou chamando de uma função podem ter consequências incidentais à sua avaliação (efeitos colaterais). Quando um "ponto de sequência" é alcançado, tudo que precede o ponto de sequência, inclusive todos os efeitos colaterais, obrigatoriamente foram avaliados antes que a avaliação seja iniciada em qualquer coisa posterior ao ponto de sequência.  
  
 Os "efeitos colaterais" são alterações causadas pela avaliação de uma expressão. Os efeitos colaterais ocorrem sempre que o valor de uma variável é alterado por uma avaliação da expressão. Todas as operações de atribuição têm efeitos colaterais. As chamadas de função também poderão ter efeitos colaterais se alterarem o valor de um item externamente visível, seja pela atribuição direta ou indireta por meio de um ponteiro.  
  
## <a name="see-also"></a>Consulte também  
 [Operandos e expressões](../c-language/operands-and-expressions.md)
