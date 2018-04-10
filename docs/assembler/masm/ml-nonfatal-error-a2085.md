---
title: ML erro não fatal A2085 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-tools
ms.tgt_pltfrm: ''
ms.topic: error-reference
f1_keywords:
- A2085
dev_langs:
- C++
helpviewer_keywords:
- A2085
ms.assetid: c2fef415-a32b-4249-896c-6d981fc6e327
caps.latest.revision: 6
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 29d0d58e5cd65c16c848b3cc05e10b9f57488639
ms.sourcegitcommit: 6002df0ac79bde5d5cab7bbeb9d8e0ef9920da4a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/14/2018
---
# <a name="ml-nonfatal-error-a2085"></a>Erro não fatal A2085 (ML)
**instrução ou o registro não é aceito no modo de CPU atual**  
  
 Foi feita uma tentativa para usar uma instrução, o registro ou a palavra-chave que não era válido para o modo atual do processador.  
  
 Por exemplo, registros de 32 bits exigem [. 386 de](../../assembler/masm/dot-386.md) ou superior. Registros de controle, como CR0 exigem modo privilegiado [. 386p](../../assembler/masm/dot-386p.md) ou superior. Esse erro também será gerado para o **NEAR32**, **FAR32**, e **simples** palavras-chave, que exigem. **386** ou superior.  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)