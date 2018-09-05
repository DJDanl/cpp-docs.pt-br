---
title: Erro Fatal de ML A1008 | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A1008
dev_langs:
- C++
helpviewer_keywords:
- A1008
ms.assetid: fe592f9d-c37b-4cd8-a51d-e3c15ddcab83
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5ec709823856e17c90d4af2a06262b30c966f39c
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43691932"
---
# <a name="ml-fatal-error-a1008"></a>Erro fatal A1008 (ML)

**aninhamento de macro não correspondentes**

A macro não foi encerrada antes do final do arquivo ou a diretiva de terminação [ENDM](../../assembler/masm/endm.md) foi encontrado fora de um bloco de macro.

Uma causa desse erro é a omissão do ponto antes de [. REPITA](../../assembler/masm/dot-repeat.md) ou [. ENQUANTO](../../assembler/masm/dot-while.md).

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>