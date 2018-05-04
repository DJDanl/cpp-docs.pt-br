---
title: Campos de bits | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- bitfields
ms.assetid: e9a1010d-1e1b-487f-9943-3c574e08f544
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 85db49f138cc733326e47a3008e79bae5ab4b7cb
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="bitfields"></a>Campos de bits
Campos de bits de estrutura são limitados a 64 bits e podem ser de tipo assinado int, int não assinado, int64 ou int64 não assinados. Campos de bits que cruzam o limite de tipo ignorará o bits para alinhar o campo de bits para o próximo alinhamento de tipo. Por exemplo, campos de bits de inteiro não podem ultrapassar um limite de 32 bits.  
  
## <a name="see-also"></a>Consulte também  
 [Tipos e armazenamento](../build/types-and-storage.md)