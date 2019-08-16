---
title: Introdução ao COM
ms.custom: index-page
ms.date: 11/04/2016
helpviewer_keywords:
- COM
ms.assetid: 120735d9-db71-4ad3-a730-ce576ea2354e
ms.openlocfilehash: e29f761e0380357bc999af82cc4bde8bfbaf4d6e
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492354"
---
# <a name="introduction-to-com"></a>Introdução ao COM

COM é o "modelo de objeto" fundamental no qual os controles ActiveX e OLE são criados. COM permite que um objeto exponha sua funcionalidade a outros componentes e hospede aplicativos. Ele define como o objeto se expõe e como essa exposição funciona em processos e em redes. COM também define o ciclo de vida do objeto.

Conceitos fundamentais para COM são estes conceitos:

- [Interfaces](../atl/interfaces-atl.md) — o mecanismo pelo qual um objeto expõe sua funcionalidade.

- [IUnknown](../atl/iunknown.md) — a interface básica na qual todos os outros são baseados. Ele implementa a contagem de referência e os mecanismos de consulta de interface executados por meio de COM.

- [Contagem de referência](../atl/reference-counting.md) — a técnica pela qual um objeto (ou, estritamente, uma interface) decide quando não está mais sendo usado e, portanto, está livre para ser removido.

- [QueryInterface](../atl/queryinterface.md) — o método usado para consultar um objeto para uma determinada interface.

- [Marshaling](../atl/marshaling.md) — o mecanismo que permite que os objetos sejam usados em limites de thread, processo e rede, permitindo a independência de localização.

- [Agregação](../atl/aggregation.md) — uma maneira na qual um objeto pode usar outro.

## <a name="see-also"></a>Consulte também

[Introdução ao COM e à ATL](../atl/introduction-to-com-and-atl.md)<br/>
[O Component Object Model](/windows/win32/com/the-component-object-model)
