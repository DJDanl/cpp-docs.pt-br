---
title: Avaliação de expressão (C) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- expression evaluation
- expressions [C++], evaluating
ms.assetid: 9493f8cc-64a2-4284-9aaf-26eec11c4f40
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9c250cba9e26d82ba129a842b61006783d13f6e3
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32382722"
---
# <a name="expression-evaluation-c"></a>Avaliação de expressão (C)
Expressões que envolvem atribuição, incremento unário, diminuição unária ou chamando de uma função podem ter consequências incidentais à sua avaliação (efeitos colaterais). Quando um "ponto de sequência" é alcançado, tudo que precede o ponto de sequência, inclusive todos os efeitos colaterais, obrigatoriamente foram avaliados antes que a avaliação seja iniciada em qualquer coisa posterior ao ponto de sequência.  
  
 Os "efeitos colaterais" são alterações causadas pela avaliação de uma expressão. Os efeitos colaterais ocorrem sempre que o valor de uma variável é alterado por uma avaliação da expressão. Todas as operações de atribuição têm efeitos colaterais. As chamadas de função também poderão ter efeitos colaterais se alterarem o valor de um item externamente visível, seja pela atribuição direta ou indireta por meio de um ponteiro.  
  
## <a name="see-also"></a>Consulte também  
 [Operandos e expressões](../c-language/operands-and-expressions.md)