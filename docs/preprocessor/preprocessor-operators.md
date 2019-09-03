---
title: Operadores do pré-processador
ms.date: 08/29/2019
helpviewer_keywords:
- preprocessor operators
- operators [C++], preprocessor
ms.assetid: 884126d1-0ce2-48b6-9e06-8a2d7c4a9656
ms.openlocfilehash: 1c556e4af5913ba8d0dc7efc9648e0d0004d9d7e
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222244"
---
# <a name="preprocessor-operators"></a>Operadores do pré-processador

Quatro operadores específicos de pré-processador são usados no contexto da `#define` diretiva. Consulte a tabela a seguir para obter um resumo de cada um. Os operadores stringizing, charizing e token-pasting são discutidos nas três seções seguintes. Para obter informações sobre `defined` o operador, consulte [as diretivas #if, #elif, #else e #endif](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md).

|Operator|Ação|
|--------------|------------|
|[Operador de cadeia de caracteres (#)](../preprocessor/stringizing-operator-hash.md)|Faz com que o argumento correspondente real seja incluído entre aspas duplas|
|[Operador de caracteres (# @)](../preprocessor/charizing-operator-hash-at.md)|Faz com que o argumento correspondente seja incluído entre aspas simples e tratado como um caractere (específico da Microsoft)|
|[Operador de colagem de tokens (# #)](../preprocessor/token-pasting-operator-hash-hash.md)|Permite que os tokens utilizados como argumentos reais sejam concatenados para formar outros tokens|
|[operador definido](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)|Simplifica a gravação de expressões compostas em determinadas políticas de macro|

## <a name="see-also"></a>Consulte também

[Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)\
[Macros predefinidas](../preprocessor/predefined-macros.md)\
[referência de pré-processador do c/c++](../preprocessor/c-cpp-preprocessor-reference.md)
