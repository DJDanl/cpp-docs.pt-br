---
title: Operadores do pré-processador
ms.date: 08/29/2019
helpviewer_keywords:
- preprocessor operators
- operators [C++], preprocessor
ms.assetid: 884126d1-0ce2-48b6-9e06-8a2d7c4a9656
ms.openlocfilehash: 5dd252fb495a05efe6eef45674f9ecd601a298a7
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74857938"
---
# <a name="preprocessor-operators"></a>Operadores do pré-processador

Quatro operadores específicos de pré-processador são usados no contexto da diretiva `#define`. Consulte a tabela a seguir para obter um resumo de cada um. Os operadores stringizing, charizing e token-pasting são discutidos nas três seções seguintes. Para obter informações sobre o operador de `defined`, consulte [as diretivas #if, #elif, #else e #endif](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md).

|Operador|Action|
|--------------|------------|
|[Operador de cadeia de caracteres (#)](../preprocessor/stringizing-operator-hash.md)|Faz com que o argumento correspondente real seja incluído entre aspas duplas|
|[Operador de caracteres (# @)](../preprocessor/charizing-operator-hash-at.md)|Faz com que o argumento correspondente seja colocado entre aspas simples e seja tratado como um caractere (específico da Microsoft)|
|[Operador de colagem de tokens (# #)](../preprocessor/token-pasting-operator-hash-hash.md)|Permite que os tokens utilizados como argumentos reais sejam concatenados para formar outros tokens|
|[operador definido](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)|Simplifica a gravação de expressões compostas em determinadas políticas de macro|

## <a name="see-also"></a>Consulte também

\ de [diretivas de pré-processador](../preprocessor/preprocessor-directives.md)
[Macros Predefinidas](../preprocessor/predefined-macros.md)\
[referência de pré-processador do c/c++](../preprocessor/c-cpp-preprocessor-reference.md)
