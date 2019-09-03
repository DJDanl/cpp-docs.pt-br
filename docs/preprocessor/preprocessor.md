---
title: Pré-processador
ms.date: 08/29/2019
helpviewer_keywords:
- preprocessor
ms.assetid: e120eda3-b413-49f1-a07c-e9fb128cf500
ms.openlocfilehash: 883504810f1b659e28764a75ebc7cfda325920a5
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70222238"
---
# <a name="preprocessor"></a>Pré-processador

O pré-processador é um processador de texto que manipula o texto de um arquivo de origem como parte da primeira fase da tradução. O pré-processador não analisa o texto de origem, mas o divide em tokens para localizar chamadas de macro. Embora o compilador invoque normalmente o pré-processador na primeira passagem, o pré-processador também pode ser invocado separadamente para processar o texto sem compilar.

O material de referência no pré-processador inclui as seguintes seções:

- [Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)

- [Operadores de pré-processador](../preprocessor/preprocessor-operators.md)

- [Macros predefinidas](../preprocessor/predefined-macros.md)

- [Pragmas](../preprocessor/pragma-directives-and-the-pragma-keyword.md)

**Seção específica da Microsoft**

Você pode obter uma lista de seu código-fonte após o pré-processamento usando a opção de compilador [/e](../build/reference/e-preprocess-to-stdout.md) ou [/EP](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) . Ambas as opções invocam o pré-processador e enviam o texto resultante para o dispositivo de saída padrão, que, na maioria dos casos, é o console do. A diferença entre as duas opções é que `/E` inclui `#line` diretivas e `/EP` retira essas diretivas.

**Fim da seção específica da Microsoft**

##  <a name="_predir_special_terminology"></a>Terminologia especial

Na documentação de pré-processador, o termo "argumento" refere-se à entidade passada para uma função. Em alguns casos, ele é modificado por "real" ou "formal", que descreve a expressão de argumento especificada na chamada de função e a declaração de argumento especificada na definição da função, respectivamente.

O termo "variável" se refere a um objeto de dados simples do tipo C. O termo "objeto" refere-se C++ a objetos e variáveis; é um termo inclusivo.

## <a name="see-also"></a>Consulte também

[Referência deC++ C/pré-processador](../preprocessor/c-cpp-preprocessor-reference.md)\
[Fases de tradução](../preprocessor/phases-of-translation.md)
