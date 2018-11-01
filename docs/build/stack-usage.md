---
title: Uso da pilha
ms.date: 11/04/2016
ms.assetid: 383f0072-0438-489f-8829-cca89582408c
ms.openlocfilehash: 5ee9da50a03e1137ed6543cd349481148c9127d6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50452215"
---
# <a name="stack-usage"></a>Uso da pilha

Toda a memória além do endereço atual do RSP é considerada voláteis: O sistema operacional ou um depurador, poderá substituir essa memória durante uma sessão de depuração do usuário ou um manipulador de interrupção. Assim, RSP sempre deve ser definido antes de tentar ler ou gravar valores em um quadro de pilha.

Esta seção discute a alocação de espaço de pilha para variáveis locais e o **alloca** intrínseco.

- [Alocação da pilha](../build/stack-allocation.md)

- [Construção da área de pilha de parâmetros dinâmicos](../build/dynamic-parameter-stack-area-construction.md)

- [Tipos de função](../build/function-types.md)

- [Alinhamento de malloc](../build/malloc-alignment.md)

- [alloca](../build/alloca.md)

## <a name="see-also"></a>Consulte também

[Convenções de software x64](../build/x64-software-conventions.md)