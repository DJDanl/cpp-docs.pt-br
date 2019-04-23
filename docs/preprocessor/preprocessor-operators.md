---
title: Operadores de pré-processador
ms.date: 11/04/2016
helpviewer_keywords:
- preprocessor operators
- operators [C++], preprocessor
ms.assetid: 884126d1-0ce2-48b6-9e06-8a2d7c4a9656
ms.openlocfilehash: 0b105cc2039e2aa50c11b796e5474a97d8c5c702
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59035683"
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