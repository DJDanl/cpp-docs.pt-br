---
title: Funções embutidas
ms.date: 10/16/2017
helpviewer_keywords:
- fast code
- inline functions, __inline keyword
- functions [C++], inline functions
ms.assetid: 00f4b2ff-8ad0-4165-9f4c-2ef157d03f31
ms.openlocfilehash: 5ee07dbb6cd6ea26991da588747ccbe720358326
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87211808"
---
# <a name="inline-functions"></a>Funções embutidas

**Específico da Microsoft**

A **`__inline`** palavra-chave informa ao compilador para substituir o código na definição de função para cada instância de uma chamada de função. No entanto, a substituição ocorre apenas ao critério do compilador. Por exemplo, o compilador não uma embute uma função se seu endereço já estiver em uso ou se for muito grande para embutir.

Para que uma função seja considerada candidata para embutir, ela deve usar a definição de função de novo estilo.

Use esse formato para especificar uma função embutida:

> **`__inline`***type*função<sub>opcional</sub> *de tipo-definição*

O uso de funções embutidas gera código mais rápido e às vezes pode gerar código menor do que a chamada de função equivalente gera pelos seguintes motivos:

- Ela poupa o tempo necessário para executar chamadas de função.

- As funções embutidas pequenas, talvez três linhas ou menos, criam menos código do que a chamada de função equivalente porque o compilador não gera código para tratar de argumentos e um valor de retorno.

- As funções geradas embutidas estão sujeitas às otimizações de código não disponíveis para funções normais porque o compilador não executa otimizações entre procedimentos.

As funções que usam **`__inline`** não devem ser confundidas com o código do assembler embutido. Consulte [Assembler embutido](../c-language/inline-assembler-c.md) para obter mais informações.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[inline, __inline, \_ _forceinline](../cpp/inline-functions-cpp.md)
