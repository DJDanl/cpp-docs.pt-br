---
title: Introdução a COM
ms.custom: index-page
ms.date: 11/04/2016
helpviewer_keywords:
- COM
ms.assetid: 120735d9-db71-4ad3-a730-ce576ea2354e
ms.openlocfilehash: 7631ba98b0e2cb00310400206b0b442ab7a23dd7
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62262366"
---
# <a name="introduction-to-com"></a>Introdução a COM

O COM é fundamentais "modelo de objeto" em quais controles ActiveX e OLE são criados. COM permite que um objeto exponha sua funcionalidade a outros componentes e aplicativos host. Ele define como expõe o objeto em si e como essa exposição funciona entre processos e entre redes. COM também define o ciclo de vida do objeto.

Fundamentais para COM são esses conceitos:

- [Interfaces](../atl/interfaces-atl.md) — o mecanismo pelo qual um objeto expõe sua funcionalidade.

- [IUnknown](../atl/iunknown.md) — a interface básica na qual todos os outros são baseados. Ele implementa a contagem de referência e a interface consultando os mecanismos de execução usando COM.

- [Contagem de referência](../atl/reference-counting.md) — a técnica pela qual um objeto (ou, estritamente, uma interface) decide quando ele não está sendo usado e, portanto, está livre para remover a mesmo.

- [QueryInterface](../atl/queryinterface.md) — o método usado para consultar um objeto para uma determinada interface.

- [Marshaling](../atl/marshaling.md) — o mecanismo que permite que objetos sejam usados por thread, processo e limites de rede, permitindo a independência de local.

- [Agregação](../atl/aggregation.md) — uma maneira na qual um objeto pode fazer uso de outro.

## <a name="see-also"></a>Consulte também

[Introdução ao COM e à ATL](../atl/introduction-to-com-and-atl.md)<br/>
[O Component Object Model](/windows/desktop/com/the-component-object-model)
