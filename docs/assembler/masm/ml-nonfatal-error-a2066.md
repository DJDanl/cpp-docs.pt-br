---
title: Erro não fatal A2066 (ML)
ms.date: 12/17/2019
ms.custom: error-reference
f1_keywords:
- A2066
helpviewer_keywords:
- A2066
ms.assetid: 58220fdf-fb8f-47fc-a36d-737867361185
ms.openlocfilehash: 4c7c32264fe5daa6cd4e14f47cff111899e8f8d6
ms.sourcegitcommit: 0781c69b22797c41630601a176b9ea541be4f2a3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/20/2019
ms.locfileid: "75316883"
---
# <a name="ml-nonfatal-error-a2066"></a>Erro não fatal A2066 (ML)

**modo de CPU e tamanho de segmento incompatíveis**

Foi feita uma tentativa de abrir um segmento com um atributo **USE16**, **USE32**ou **Flat** que não era compatível com a CPU especificada ou para mudar para uma CPU de 16 bits em um segmento de 32 bits.

Os atributos **USE32** e **Flat** devem ser precedidos pela diretiva de processador. 386 ou superior.

## <a name="see-also"></a>Veja também

[Mensagens de erro de ML](ml-error-messages.md)
