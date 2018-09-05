---
title: Erro não fatal de ML A2219 | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A2219
dev_langs:
- C++
helpviewer_keywords:
- A2219
ms.assetid: 5ebc2f40-e47e-4f8e-b7b9-960b9cfc9f6d
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 365997181b0d4f4471162d7cf8f65a4429e69e74
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43681639"
---
# <a name="ml-nonfatal-error-a2219"></a>Erro não fatal A2219 (ML)

**Alinhamento incorreto para o deslocamento no código de desenrolamento**

O operando para [. ALLOCSTACK](../../assembler/masm/dot-allocstack.md) e [. SAVEREG](../../assembler/masm/dot-savereg.md) deve ser um múltiplo de 8.  O operando para [. SAVEXMM128](../../assembler/masm/dot-savexmm128.md) e [. SETFRAME](../../assembler/masm/dot-setframe.md) deve ser um múltiplo de 16.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>