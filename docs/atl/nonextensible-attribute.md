---
title: Atributo não extensível
ms.date: 11/04/2016
helpviewer_keywords:
- nonextensible attribute
- dual interfaces, nonextensible attribute
ms.assetid: 02a4a18b-ffd3-4d53-8fd1-feb1c05ad5ac
ms.openlocfilehash: fda2a0d43144b6e9832e061e7198b3f3e65f8b86
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91500112"
---
# <a name="nonextensible-attribute"></a>Atributo não extensível

Se uma interface dupla não for estendida em tempo de execução (ou seja, você não fornecerá métodos ou propriedades por meio `IDispatch::Invoke` do que não estão disponíveis por meio de vtable), deverá aplicar o atributo **extensível** à sua definição de interface. Esse atributo fornece informações para os idiomas do cliente (como Visual Basic) que podem ser usados para habilitar a verificação completa de código no momento da compilação. Se esse atributo não for fornecido, os bugs poderão permanecer ocultos no código do cliente até o tempo de execução.

Para obter mais informações sobre o atributo não **extensível** e um exemplo, consulte [extensível](../windows/attributes/nonextensible.md).

## <a name="see-also"></a>Consulte também

[Interfaces duplas e ATL](../atl/dual-interfaces-and-atl.md)
