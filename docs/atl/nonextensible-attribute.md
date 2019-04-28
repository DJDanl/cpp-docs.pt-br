---
title: Atributo nonextensible
ms.date: 11/04/2016
helpviewer_keywords:
- nonextensible attribute
- dual interfaces, nonextensible attribute
ms.assetid: 02a4a18b-ffd3-4d53-8fd1-feb1c05ad5ac
ms.openlocfilehash: cc57acb8bd7bc3e32c764606da651f57316ceabf
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62250096"
---
# <a name="nonextensible-attribute"></a>Atributo nonextensible

Se uma interface dupla não será estendida em tempo de execução (ou seja, você não fornecer métodos ou propriedades por meio `IDispatch::Invoke` que não estão disponíveis por meio de vtable), você deve aplicar a **nonextensible** à sua interface de atributo definição. Esse atributo fornece informações para idiomas do cliente (por exemplo, o Visual Basic) que pode ser usado para habilitar a verificação de código completo no tempo de compilação. Se esse atributo não for fornecido, bugs permanecerão ocultos no código do cliente até o tempo de execução.

Para obter mais informações sobre o **nonextensible** atributo e um exemplo, consulte [nonextensible](../windows/nonextensible.md).

## <a name="see-also"></a>Consulte também

[Interfaces duplas e a ATL](../atl/dual-interfaces-and-atl.md)
