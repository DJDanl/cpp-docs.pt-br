---
title: Literais da cadeia de caracteres em expressões primárias | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- string literals, in primary expressions
ms.assetid: 3ec31278-527b-40d2-8c83-6b09e2d81ca6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 818284a0eabce779d9f52e8fe7b3af4cc1d8df4b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46095516"
---
# <a name="string-literals-in-primary-expressions"></a>literais String em expressões primárias

Um “literal de cadeia de caracteres” é um caractere, um caractere largo ou uma sequência de caracteres adjacentes entre aspas duplas. Como não são variáveis, nem literais de cadeia de caracteres nem seus elementos podem ser o operando esquerdo em uma operação de atribuição. O tipo de uma literal de cadeia de caracteres é uma matriz de `char` (ou uma matriz de `wchar_t` para literais de cadeia de caracteres largos). As matrizes nas expressões são convertidas em ponteiros. Consulte [Literais de cadeia de caracteres](../c-language/c-string-literals.md) para obter mais informações sobre cadeias de caracteres.

## <a name="see-also"></a>Consulte também

[Expressões primárias C](../c-language/c-primary-expressions.md)