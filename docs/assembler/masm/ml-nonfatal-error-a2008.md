---
title: Erro não fatal A2008 (ML)
ms.date: 12/17/2019
ms.custom: error-reference
f1_keywords:
- A2008
helpviewer_keywords:
- A2008
ms.assetid: ca24157f-c88a-4678-ae06-3bc3cd956001
ms.openlocfilehash: 79448f9358ffd422b8b25a69ac2b83693e58560e
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75318040"
---
# <a name="ml-nonfatal-error-a2008"></a>Erro não fatal A2008 (ML)

**erro de sintaxe:**

Um token no local atual causou um erro de sintaxe.

Uma das seguintes opções pode ter ocorrido:

- Um prefixo de ponto foi adicionado ou omitido de uma diretiva.

- Uma palavra reservada (como **C** ou **size**) foi usada como um identificador.

- Foi usada uma instrução que não estava disponível com a seleção de processador ou coprocessador atual.

- Um operador de tempo de execução de comparação (como `==`) foi usado em uma instrução de assembly condicional em vez de um operador relacional (como [EQ](operator-eq.md)).

- Uma instrução ou diretiva recebeu poucos operandos.

- Uma diretiva obsoleta foi usada.

## <a name="see-also"></a>Veja também

[Mensagens de erro de ML](ml-error-messages.md)
