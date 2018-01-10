---
title: ML aviso A4012 | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: A4012
dev_langs: C++
helpviewer_keywords: A4012
ms.assetid: 842b1259-9679-4eeb-a02d-672a583a94e5
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 0648d2bac0d300fc8e2c696b54741a3d7293a4f6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="ml-warning-a4012"></a>Aviso A4012 (ML)
**informações de número de linha de segmento sem que a classe 'CODE'**  
  
 Havia instruções em um segmento que não tem um nome de classe que termina com "Código". O assembler não gerou informações do CodeView para estas instruções.  
  
 CodeView não é possível processar a módulos com o código em segmentos com nomes de classe que não terminam com "Código".  
  
## <a name="see-also"></a>Consulte também  
 [Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)