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
ms.openlocfilehash: a7451ea6afee81cc296fb091705bde48041ef5d1
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45722482"
---
# <a name="bitfields"></a>Campos de bits

Campos de bits da estrutura são limitados a 64 bits e pode ser do tipo assinado int, int sem sinal, int64 ou int64 sem sinal. Os campos de bits que cruzam o limite de tipo ignorará o bits para alinhar o campo de bits para o alinhamento do tipo Avançar. Por exemplo, os campos de bits de inteiro não podem cruzar um limite de 32 bits.

## <a name="see-also"></a>Consulte também

[Tipos e armazenamento](../build/types-and-storage.md)