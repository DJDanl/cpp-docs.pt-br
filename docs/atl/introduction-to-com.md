---
title: Introdução a COM | Microsoft Docs
ms.custom: index-page
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- COM
ms.assetid: 120735d9-db71-4ad3-a730-ce576ea2354e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a98c7bb473e36e53e8cbe0f90f9dd94f655392d6
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46073220"
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
[O modelo de objeto de componente](/windows/desktop/com/the-component-object-model)

