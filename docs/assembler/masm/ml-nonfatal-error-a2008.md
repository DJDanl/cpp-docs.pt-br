---
title: Erro não fatal A2008 (ML)
ms.date: 08/30/2018
ms.topic: error-reference
f1_keywords:
- A2008
helpviewer_keywords:
- A2008
ms.assetid: ca24157f-c88a-4678-ae06-3bc3cd956001
ms.openlocfilehash: 7f85a3aabb7b1955cede912168dfc04618b8f2b2
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50630367"
---
# <a name="ml-nonfatal-error-a2008"></a>Erro não fatal A2008 (ML)

**Erro de sintaxe:**

Um token no local atual causou um erro de sintaxe.

Pode ter ocorrido um dos seguintes:

- Um prefixo de ponto foi adicionado a ou omitido de uma diretiva.

- Uma palavra reservada (como **C** ou **tamanho**) foi usado como um identificador.

- Foi usada uma instrução que não estava disponível com a seleção atual do processador ou coprocessador.

- Um operador de tempo de execução de comparação (como `==`) foi usado em uma instrução condicional de assembly em vez de um operador relacional (como [EQ](../../assembler/masm/operator-eq.md)).

- Uma instrução ou uma diretiva foi atribuída a operandos insuficientes.

- Uma diretiva obsoleta foi usada.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>