---
title: Definições para o resumo de gramática
ms.date: 08/29/2019
helpviewer_keywords:
- preprocessor, definitions
- preprocessor
ms.assetid: cc752dc8-6f4e-4347-a556-e0d9ef4c46bd
ms.openlocfilehash: 93cf6ffc5daf53a106c9f15a2289e2b52739d72f
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222416"
---
# <a name="definitions-for-the-grammar-summary"></a>Definições para o resumo de gramática

Os terminais são pontos de extremidade em uma definição de sintaxe. Nenhuma outra resolução é possível. Os terminais incluem o conjunto de palavras reservadas e identificadores definidos pelo usuário.

Os não terminais são espaços reservados na sintaxe. A maioria é definida em outra parte deste resumo da sintaxe. As definições podem ser recursivas. Os seguintes não terminais são definidos na seção [convenções lexicais](../cpp/lexical-conventions.md) da  *C++ referência de linguagem*:

*constante*, *expressão constante*, *identificador*, *palavra-chave*, *operador*, *pontuador*

Um componente opcional é indicado pelo <sub>opt</sub> subscrito. Por exemplo, o exemplo a seguir indica uma expressão opcional incluída em chaves:

**{** *expression*<sub>opt</sub> **}**

## <a name="see-also"></a>Consulte também

[Resumo da gramática (CC++/)](../preprocessor/grammar-summary-c-cpp.md)
