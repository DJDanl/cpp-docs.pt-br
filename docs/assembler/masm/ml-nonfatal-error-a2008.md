---
title: Erro não fatal de ML A2008 | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A2008
dev_langs:
- C++
helpviewer_keywords:
- A2008
ms.assetid: ca24157f-c88a-4678-ae06-3bc3cd956001
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 774cf4c2a51bf084fb63e572cc99b0c8e3cba26f
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43679369"
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