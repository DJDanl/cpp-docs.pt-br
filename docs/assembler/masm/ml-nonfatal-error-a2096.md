---
title: Erro não fatal A2096 (ML)
ms.date: 08/30/2018
ms.custom: error-reference
f1_keywords:
- A2096
helpviewer_keywords:
- A2096
ms.assetid: bab0b5ee-b39f-4e44-a41a-3f949fab4297
ms.openlocfilehash: 14fb30214cf7badf51368672dc52635d50a067f1
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74855468"
---
# <a name="ml-nonfatal-error-a2096"></a>Erro não fatal A2096 (ML)

**segmento, grupo ou registro de segmento esperado**

Um segmento ou grupo era esperado, mas não foi encontrado.

Ocorreu um dos seguintes:

- O operando esquerdo especificado com o operador de substituição de segmento ( **:** ) não era um registro de segmento (CS, DS, SS, es, FS ou GS), nome do grupo, nome do segmento ou expressão de segmento.

- A diretiva [supor](../../assembler/masm/assume.md) recebeu um registro de segmento sem um endereço de segmento válido, registro de segmento, grupo ou o grupo **plano** especial.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>