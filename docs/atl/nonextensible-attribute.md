---
title: Atributo nonextensible
ms.date: 11/04/2016
f1_keywords:
- nonextensible
helpviewer_keywords:
- nonextensible attribute
- dual interfaces, nonextensible attribute
ms.assetid: 02a4a18b-ffd3-4d53-8fd1-feb1c05ad5ac
ms.openlocfilehash: 5aa5b8514435e9876500daa4d92504d75eb6dc23
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57257625"
---
# <a name="nonextensible-attribute"></a>Atributo nonextensible

Se uma interface dupla não será estendida em tempo de execução (ou seja, você não fornecer métodos ou propriedades por meio `IDispatch::Invoke` que não estão disponíveis por meio de vtable), você deve aplicar a **nonextensible** à sua interface de atributo definição. Esse atributo fornece informações para idiomas do cliente (por exemplo, o Visual Basic) que pode ser usado para habilitar a verificação de código completo no tempo de compilação. Se esse atributo não for fornecido, bugs permanecerão ocultos no código do cliente até o tempo de execução.

Para obter mais informações sobre o **nonextensible** atributo e um exemplo, consulte [nonextensible](../windows/nonextensible.md).

## <a name="see-also"></a>Consulte também

[Interfaces duplas e a ATL](../atl/dual-interfaces-and-atl.md)
