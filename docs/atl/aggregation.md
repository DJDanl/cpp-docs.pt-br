---
title: Agregação
ms.date: 11/04/2016
helpviewer_keywords:
- aggregation [C++]
- aggregate objects [C++]
ms.assetid: 7125bb8e-b269-4b50-9bba-295b467a54cc
ms.openlocfilehash: 288af427bd6a8d9baf572dfad8e4a25452694ad9
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69491977"
---
# <a name="aggregation"></a>Agregação

Há ocasiões em que o implementador de um objeto gostaria de aproveitar os serviços oferecidos por outro objeto predefinido. Além disso, gostaria que esse segundo objeto fosse exibido como uma parte natural do primeiro. O COM alcança essas duas metas por meio de contenção e agregação.

Agregação significa que o objeto recipiente (externo) cria o objeto contido (interno) como parte de seu processo de criação e as interfaces do objeto interno são expostas pela externa. Um objeto permite que ele próprio seja agregável ou não. Se for, ele deverá seguir algumas regras para que a agregação funcione corretamente.

Principalmente, todas `IUnknown` as chamadas de método no objeto contido devem delegar ao objeto recipiente.

## <a name="see-also"></a>Consulte também

[Introdução a COM](../atl/introduction-to-com.md)<br/>
[Reutilizando objetos](/windows/win32/com/reusing-objects)
