---
title: Operadores de pré-processador
ms.date: 11/04/2016
helpviewer_keywords:
- preprocessor operators
- operators [C++], preprocessor
ms.assetid: 884126d1-0ce2-48b6-9e06-8a2d7c4a9656
ms.openlocfilehash: 3573ce2d86f38193a4f8f7c1c0f310283f304648
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50584386"
---
# <a name="preprocessor-operators"></a>Operadores de pré-processador
Quatro operadores específicos de pré-processadores são usados no contexto da política de `#define` (consulte a lista a seguir para obter um resumo de cada um.) Os operadores stringizing, charizing e token-pasting são discutidos nas três seções seguintes. Para obter informações sobre o `defined` operador, consulte [o #if, #elif, #else e # #endif](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md).

|Operador|Ação|
|--------------|------------|
|[Operador stringizing (#)](../preprocessor/stringizing-operator-hash.md)|Faz com que o argumento correspondente real seja incluído entre aspas duplas|
|[Operador de charizing (#@)](../preprocessor/charizing-operator-hash-at.md)|Faz com que o argumento correspondente seja incluído entre aspas simples e tratado como um caractere (específico da Microsoft)|
|[Operador token-pasting (#)](../preprocessor/token-pasting-operator-hash-hash.md)|Permite que os tokens utilizados como argumentos reais sejam concatenados para formar outros tokens|
|[operador definido](../preprocessor/hash-if-hash-elif-hash-else-and-hash-endif-directives-c-cpp.md)|Simplifica a gravação de expressões compostas em determinadas políticas de macro|

## <a name="see-also"></a>Consulte também

[Diretivas do pré-processador](../preprocessor/preprocessor-directives.md)<br/>
[Macros predefinidas](../preprocessor/predefined-macros.md)<br/>
[Referência de pré-processador do C/C++](../preprocessor/c-cpp-preprocessor-reference.md)