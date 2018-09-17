---
title: Uso de pilha | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 383f0072-0438-489f-8829-cca89582408c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 827a129c0b7a444cc5b48ba68a3e360712e1c08e
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45721533"
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