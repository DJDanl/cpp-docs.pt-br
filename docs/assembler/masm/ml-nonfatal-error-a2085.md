---
title: Erro não fatal de ML A2085 | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A2085
dev_langs:
- C++
helpviewer_keywords:
- A2085
ms.assetid: c2fef415-a32b-4249-896c-6d981fc6e327
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: dd5ec9f36a4f956b8eeb097b6a8f8eaed89ba2b2
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43681429"
---
# <a name="ml-nonfatal-error-a2085"></a>Erro não fatal A2085 (ML)

**instrução ou o registro não foi aceito no modo de CPU atual**

Foi feita uma tentativa para usar uma instrução, registre-se ou uma palavra-chave que não era válido para o modo atual do processador.

Por exemplo, registros de 32 bits exigem [. 386 de](../../assembler/masm/dot-386.md) ou superior. Registros de controle, como CR0 exigem modo privilegiado [. 386p](../../assembler/masm/dot-386p.md) ou superior. Esse erro também será gerado para o **NEAR32**, **FAR32**, e **simples** palavras-chave, que exigem. **386** ou superior.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>