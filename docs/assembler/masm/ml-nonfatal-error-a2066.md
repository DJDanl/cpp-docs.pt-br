---
title: Erro não fatal A2066 (ML)
ms.date: 08/30/2018
ms.custom: error-reference
f1_keywords:
- A2066
helpviewer_keywords:
- A2066
ms.assetid: 58220fdf-fb8f-47fc-a36d-737867361185
ms.openlocfilehash: 8dc3000b2edc2b1ecda7cc3952b554296de19aa3
ms.sourcegitcommit: a6d63c07ab9ec251c48bc003ab2933cf01263f19
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/05/2019
ms.locfileid: "74855873"
---
# <a name="ml-nonfatal-error-a2066"></a>Erro não fatal A2066 (ML)

**modo de CPU e tamanho de segmento incompatíveis**

Foi feita uma tentativa de abrir um segmento com um atributo **USE16**, **USE32**ou **Flat** que não era compatível com a CPU especificada ou para mudar para uma CPU de 16 bits em um segmento de 32 bits.

Os atributos **USE32** e **Flat** devem ser precedidos pela diretiva de processador. 386 ou superior.

## <a name="see-also"></a>Consulte também

[Mensagens de erro de ML](../../assembler/masm/ml-error-messages.md)<br/>