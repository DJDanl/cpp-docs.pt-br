---
title: Pré-processador
ms.date: 08/29/2019
helpviewer_keywords:
- preprocessor
ms.assetid: e120eda3-b413-49f1-a07c-e9fb128cf500
ms.openlocfilehash: 7188d7a6803c9eec109a59906cf0c016a460819d
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81337499"
---
# <a name="preprocessor"></a>Pré-processador

O pré-processador é um processador de texto que manipula o texto de um arquivo de origem como parte da primeira fase da tradução. O pré-processador não analisa o texto de origem, mas o divide em tokens para localizar chamadas de macro. Embora o compilador invoque normalmente o pré-processador na primeira passagem, o pré-processador também pode ser invocado separadamente para processar o texto sem compilar.

O material de referência no pré-processador inclui as seguintes seções:

- [Diretivas do pré-processador](../preprocessor/preprocessor-directives.md)

- [Operadores de pré-processador](../preprocessor/preprocessor-operators.md)

- [Macros predefinidas](../preprocessor/predefined-macros.md)

- [Pragmas](../preprocessor/pragma-directives-and-the-pragma-keyword.md)

**Específico da Microsoft**

Você pode obter uma listagem do seu código fonte após o pré-processamento usando a opção [/E](../build/reference/e-preprocess-to-stdout.md) ou [/EP](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) compilador. Ambas as opções invocam o pré-processador e enviam o texto resultante para o dispositivo de saída padrão, que, na maioria dos casos, é o console. A diferença entre as `/E` duas `#line` opções é `/EP` que inclui diretivas, e retira essas diretivas.

**Fim específico da Microsoft**

## <a name="special-terminology"></a><a name="_predir_special_terminology"></a>Terminologia especial

Na documentação de pré-processador, o termo "argumento" refere-se à entidade passada para uma função. Em alguns casos, é modificado por "real" ou "formal", que descreve a expressão de argumento especificada na chamada de função, e a declaração de argumento especificada na definição da função, respectivamente.

O termo "variável" se refere a um objeto de dados simples do tipo C. O termo "objeto" refere-se tanto aos objetos C++ quanto às variáveis; é um termo inclusivo.

## <a name="see-also"></a>Confira também

[Referência do pré-processador C/C++](../preprocessor/c-cpp-preprocessor-reference.md)\
[Fases da tradução](../preprocessor/phases-of-translation.md)
