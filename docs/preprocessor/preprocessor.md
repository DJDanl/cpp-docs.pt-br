---
title: Pré-processador
ms.date: 11/04/2016
helpviewer_keywords:
- preprocessor
ms.assetid: e120eda3-b413-49f1-a07c-e9fb128cf500
ms.openlocfilehash: b1443d88fdba470cb8ed5058c9a9012bfbdc5bc7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62179848"
---
# <a name="preprocessor"></a>Pré-processador
O pré-processador é um processador de texto que manipula o texto de um arquivo de origem como parte da primeira fase da tradução. O pré-processador não analisa o texto de origem, mas o divide em tokens com a finalidade de localizar as chamadas macro. Embora o compilador invoque normalmente o pré-processador na primeira passagem, o pré-processador também pode ser invocado separadamente para processar o texto sem compilar.

O material de referência no pré-processador inclui as seguintes seções:

- [Diretivas de pré-processador](../preprocessor/preprocessor-directives.md)

- [Operadores de pré-processador](../preprocessor/preprocessor-operators.md)

- [Macros predefinidas](../preprocessor/predefined-macros.md)

- [Pragmas](../preprocessor/pragma-directives-and-the-pragma-keyword.md)

**Seção específica da Microsoft**

Você pode obter uma listagem de código-fonte após o pré-processamento usando o [/E](../build/reference/e-preprocess-to-stdout.md) ou [/EP](../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md) opção de compilador. As duas opções invocam o pré-processador e tem como saída o texto resultante no dispositivo de saída padrão que, na maioria dos casos, é o console. A diferença entre as duas opções é que /E inclui as políticas `#line` e /EP as retira.

**Fim da seção específica da Microsoft**

##  <a name="_predir_special_terminology"></a> Terminologia especial

Na documentação de pré-processador, o termo "argumento" refere-se à entidade passada para uma função. Em alguns casos, ele é modificado por "atual" ou "formal", que descreve a expressão do argumento especificada na chamada de função e na declaração do argumento especificada na definição de função, respectivamente.

O termo "variável" se refere a um objeto de dados simples do tipo C. O termo "objeto" se refere a objetos e variáveis C++; ele é um termo inclusivo.

## <a name="see-also"></a>Consulte também

[Referência de pré-processador do C/C++](../preprocessor/c-cpp-preprocessor-reference.md)<br/>
[Fases de translação](../preprocessor/phases-of-translation.md)