---
title: ML aviso A4012 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-masm
ms.topic: error-reference
f1_keywords:
- A4012
dev_langs:
- C++
helpviewer_keywords:
- A4012
ms.assetid: 842b1259-9679-4eeb-a02d-672a583a94e5
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 865b6afb6d5dd8fb8e5d7d6205a525bae2f7c934
ms.sourcegitcommit: dbca5fdd47249727df7dca77de5b20da57d0f544
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/28/2018
---
# <a name="ml-warning-a4012"></a>Aviso A4012 (ML)
**informações de número de linha de segmento sem que a classe 'CODE'**  
  
 Havia instruções em um segmento que não tem um nome de classe que termina com "Código". O assembler não gerou informações do CodeView para estas instruções.  
  
 CodeView não é possível processar a módulos com o código em segmentos com nomes de classe que não terminam com "Código".  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)