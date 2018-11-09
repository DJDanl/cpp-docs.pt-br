---
title: Funções embutidas
ms.date: 10/16/2017
helpviewer_keywords:
- fast code
- inline functions, __inline keyword
- functions [C++], inline functions
ms.assetid: 00f4b2ff-8ad0-4165-9f4c-2ef157d03f31
ms.openlocfilehash: 2f2ed8ccff0ecbdeff7f3ebac94d5e19ec8042f6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50452631"
---
# <a name="inline-functions"></a>Funções embutidas

**Seção específica da Microsoft**

A palavra-chave `__inline` diz para o compilador substituir o código na definição de função para cada instância de uma chamada de função. No entanto, a substituição ocorre apenas ao critério do compilador. Por exemplo, o compilador não uma embute uma função se seu endereço já estiver em uso ou se for muito grande para embutir.

Para que uma função seja considerada candidata para embutir, ela deve usar a definição de função de novo estilo.

Use esse formato para especificar uma função embutida:

> **__inline** *type*<sub>opt</sub> *definição da função*

O uso de funções embutidas gera código mais rápido e às vezes pode gerar código menor do que a chamada de função equivalente gera pelos seguintes motivos:

- Ela poupa o tempo necessário para executar chamadas de função.

- As funções embutidas pequenas, talvez três linhas ou menos, criam menos código do que a chamada de função equivalente porque o compilador não gera código para tratar de argumentos e um valor de retorno.

- As funções geradas embutidas estão sujeitas às otimizações de código não disponíveis para funções normais porque o compilador não executa otimizações entre procedimentos.

As funções que usam `__inline` não devem ser confundidas com o código de assembler embutido. Consulte [Assembler embutido](../c-language/inline-assembler-c.md) para obter mais informações.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[inline, __inline, \__forceinline](../cpp/inline-functions-cpp.md)

