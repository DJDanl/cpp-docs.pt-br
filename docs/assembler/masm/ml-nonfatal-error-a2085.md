---
title: ML erro não fatal A2085 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 82f0a014810679f0b48f79198b1335240f5cd6a8
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
ms.locfileid: "32054270"
---
# <a name="ml-nonfatal-error-a2085"></a>Erro não fatal A2085 (ML)
**instrução ou o registro não é aceito no modo de CPU atual**  
  
 Foi feita uma tentativa para usar uma instrução, o registro ou a palavra-chave que não era válido para o modo atual do processador.  
  
 Por exemplo, registros de 32 bits exigem [. 386 de](../../assembler/masm/dot-386.md) ou superior. Registros de controle, como CR0 exigem modo privilegiado [. 386p](../../assembler/masm/dot-386p.md) ou superior. Esse erro também será gerado para o **NEAR32**, **FAR32**, e **simples** palavras-chave, que exigem. **386** ou superior.  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)