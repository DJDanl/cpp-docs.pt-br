---
title: Definições para o resumo de gramática
ms.date: 11/04/2016
helpviewer_keywords:
- preprocessor, definitions
- preprocessor
ms.assetid: cc752dc8-6f4e-4347-a556-e0d9ef4c46bd
ms.openlocfilehash: 6e8671ba0d68b13f68db0f2b08dab4fe98f917e7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62389275"
---
# <a name="definitions-for-the-grammar-summary"></a>Definições para o resumo de gramática

Os terminais são pontos de extremidade em uma definição de sintaxe. Nenhuma outra resolução é possível. Os terminais incluem o conjunto de palavras reservadas e identificadores definidos pelo usuário.

Os não terminais são espaços reservados na sintaxe. A maioria é definida em outra parte deste resumo da sintaxe. As definições podem ser recursivas. Os seguintes não terminais são definidos na [convenções lexicais](../cpp/lexical-conventions.md) seção o *referência da linguagem C++*:

`constant`, *constant-expression*, *identifier*, *keyword*, `operator`, `punctuator`

Um componente opcional é indicado pelo <sub>opt</sub> subscrito. Por exemplo, o exemplo a seguir indica uma expressão opcional incluída em chaves:

**{** *expression*<sub>opt</sub> **}**

## <a name="see-also"></a>Consulte também

[Resumo de gramática (C/C++)](../preprocessor/grammar-summary-c-cpp.md)