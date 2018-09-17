---
title: alloca | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
dev_langs:
- C++
ms.assetid: 2b209335-e3a0-4934-93f0-3b5925d22918
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: e0c73abcb52b991ee6bd4de839861aa4ef684181
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45702740"
---
# <a name="alloca"></a>alloca

[alloca](../c-runtime-library/reference/alloca.md) deve ser de 16 bytes alinhado e adicionalmente necessários para usar um ponteiro de quadro.

A pilha é alocada precisa incluir o espaço abaixo dela para parâmetros de funções, subsequentemente, chamadas, conforme discutido em [alocação da pilha](../build/stack-allocation.md).

## <a name="see-also"></a>Consulte também

[Uso da pilha](../build/stack-usage.md)