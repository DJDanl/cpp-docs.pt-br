---
title: Campos de bits
ms.date: 11/04/2016
helpviewer_keywords:
- bitfields
ms.assetid: e9a1010d-1e1b-487f-9943-3c574e08f544
ms.openlocfilehash: 3ff0092bbd31b8b1cd98fa56fb802c7ce28cb472
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50652823"
---
# <a name="bitfields"></a>Campos de bits

Campos de bits da estrutura são limitados a 64 bits e pode ser do tipo assinado int, int sem sinal, int64 ou int64 sem sinal. Os campos de bits que cruzam o limite de tipo ignorará o bits para alinhar o campo de bits para o alinhamento do tipo Avançar. Por exemplo, os campos de bits de inteiro não podem cruzar um limite de 32 bits.

## <a name="see-also"></a>Consulte também

[Tipos e armazenamento](../build/types-and-storage.md)