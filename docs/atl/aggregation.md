---
title: Agregação
ms.date: 11/04/2016
helpviewer_keywords:
- aggregation [C++]
- aggregate objects [C++]
ms.assetid: 7125bb8e-b269-4b50-9bba-295b467a54cc
ms.openlocfilehash: 2eec7a801f9fe16bc48fc888d10ce413ec7e79db
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62223500"
---
# <a name="aggregation"></a>Agregação

Há vezes quando o implementador de um objeto gostaria de aproveitar os serviços oferecidos pelo predefinidas, de outro objeto. Além disso, ele gostaria que este segundo objeto a ser exibido como uma parte natural do primeiro. COM atinge ambas essas metas por meio de agregação e confinamento.

Agregação significa que o objeto de recipiente (externo) cria o objeto de (interno) independente como parte do processo de criação e as interfaces do objeto interno são expostas pelo externo. Um objeto permite que seja agregável, ou não. Se for, ele deve seguir algumas regras de agregação para funcionar corretamente.

Basicamente, tudo `IUnknown` chamadas de método no objeto independente devem delegar para o objeto recipiente.

## <a name="see-also"></a>Consulte também

[Introdução a COM](../atl/introduction-to-com.md)<br/>
[Reutilizando objetos](/windows/desktop/com/reusing-objects)
