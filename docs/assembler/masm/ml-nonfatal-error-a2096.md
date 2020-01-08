---
title: Erro não fatal A2096 (ML)
ms.date: 12/17/2019
ms.custom: error-reference
f1_keywords:
- A2096
helpviewer_keywords:
- A2096
ms.assetid: bab0b5ee-b39f-4e44-a41a-3f949fab4297
ms.openlocfilehash: 425e99c1dc6675e8b970433948e0cc09b8d54485
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75312658"
---
# <a name="ml-nonfatal-error-a2096"></a>Erro não fatal A2096 (ML)

**segmento, grupo ou registro de segmento esperado**

Um segmento ou grupo era esperado, mas não foi encontrado.

Ocorreu um dos seguintes:

- O operando esquerdo especificado com o operador de substituição de segmento ( **:** ) não era um registro de segmento (CS, DS, SS, es, FS ou GS), nome do grupo, nome do segmento ou expressão de segmento.

- A diretiva [supor](assume.md) recebeu um registro de segmento sem um endereço de segmento válido, registro de segmento, grupo ou o grupo **plano** especial.

## <a name="see-also"></a>Veja também

[Mensagens de erro de ML](ml-error-messages.md)
