---
title: Erro não fatal A2008 (ML)
ms.date: 08/30/2018
ms.custom: error-reference
f1_keywords:
- A2008
helpviewer_keywords:
- A2008
ms.assetid: ca24157f-c88a-4678-ae06-3bc3cd956001
ms.openlocfilehash: 192d82186a58d4e6b534ab5ec65b696d4d7ce3ee
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74856747"
---
# <a name="ml-nonfatal-error-a2008"></a>Erro não fatal A2008 (ML)

**erro de sintaxe:**

Um token no local atual causou um erro de sintaxe.

Uma das seguintes opções pode ter ocorrido:

- Um prefixo de ponto foi adicionado ou omitido de uma diretiva.

- Uma palavra reservada (como **C** ou **size**) foi usada como um identificador.

- Foi usada uma instrução que não estava disponível com a seleção de processador ou coprocessador atual.

- Um operador de tempo de execução de comparação (como `==`) foi usado em uma instrução de assembly condicional em vez de um operador relacional (como [EQ](../../assembler/masm/operator-eq.md)).

- Uma instrução ou diretiva recebeu poucos operandos.

- Uma diretiva obsoleta foi usada.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>