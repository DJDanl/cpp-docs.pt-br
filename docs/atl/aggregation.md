---
title: Agregação
ms.date: 11/04/2016
helpviewer_keywords:
- aggregation [C++]
- aggregate objects [C++]
ms.assetid: 7125bb8e-b269-4b50-9bba-295b467a54cc
ms.openlocfilehash: d5a09dcd8c289447491ebc7111a77549166a7d00
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50633368"
---
# <a name="aggregation"></a>Agregação

Há vezes quando o implementador de um objeto gostaria de aproveitar os serviços oferecidos pelo predefinidas, de outro objeto. Além disso, ele gostaria que este segundo objeto a ser exibido como uma parte natural do primeiro. COM atinge ambas essas metas por meio de agregação e confinamento.

Agregação significa que o objeto de recipiente (externo) cria o objeto de (interno) independente como parte do processo de criação e as interfaces do objeto interno são expostas pelo externo. Um objeto permite que seja agregável, ou não. Se for, ele deve seguir algumas regras de agregação para funcionar corretamente.

Basicamente, tudo `IUnknown` chamadas de método no objeto independente devem delegar para o objeto recipiente.

## <a name="see-also"></a>Consulte também

[Introdução a COM](../atl/introduction-to-com.md)<br/>
[Reutilizando objetos](/windows/desktop/com/reusing-objects)

