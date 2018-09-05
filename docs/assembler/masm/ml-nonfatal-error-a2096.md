---
title: Erro não fatal de ML A2096 | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A2096
dev_langs:
- C++
helpviewer_keywords:
- A2096
ms.assetid: bab0b5ee-b39f-4e44-a41a-3f949fab4297
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 82f4ef76dca10b1208a931bc3e1cc09d82a639d2
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43679592"
---
# <a name="ml-nonfatal-error-a2096"></a>Erro não fatal A2096 (ML)

**segmento, grupo ou registro de segmento esperado**

Um segmento ou o grupo era esperado, mas não foi encontrado.

Um dos seguintes ocorreu:

- O operando esquerdo especificado com o segmento de substituir o operador (**:**) não era um nome de grupo segmento register (CS, DS, SS, ES, FS ou GS), o nome do segmento ou a expressão de segmento.

- O [PRESSUPOR](../../assembler/masm/assume.md) diretiva foi fornecida um registrador de segmento sem um endereço válido de segmento, registre-se do segmento, grupo ou especiais **simples** grupo.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>