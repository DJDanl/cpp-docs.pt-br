---
title: Interfaces (ATL)
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- COM interfaces
- interfaces, COM
ms.assetid: de6c8b12-6230-4fdc-af66-a28b91d5ee55
ms.openlocfilehash: 2373351330982623ffa602fd81bec61d0bc257b2
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492134"
---
# <a name="interfaces-atl"></a>Interfaces (ATL)

Uma interface é a maneira na qual um objeto expõe sua funcionalidade ao mundo exterior. Em COM, uma interface é uma tabela de ponteiros (como C++ uma vtable) para funções implementadas pelo objeto. A tabela representa a interface e as funções às quais ela aponta são os métodos dessa interface. Um objeto pode expor quantas interfaces forem escolhidas.

Cada interface é baseada na interface COM básica, [IUnknown](../atl/iunknown.md). Os métodos de `IUnknown` permitir a navegação para outras interfaces expostas pelo objeto.

Além disso, cada interface recebe uma ID de interface exclusiva (IID). Essa exclusividade facilita o suporte ao controle de versão de interface. Uma nova versão de uma interface é simplesmente uma nova interface, com uma nova IID.

> [!NOTE]
>  IIDs para as interfaces COM e OLE padrão são predefinidas.

## <a name="see-also"></a>Consulte também

[Introdução a COM](../atl/introduction-to-com.md)<br/>
[Objetos e interfaces COM](/windows/win32/com/com-objects-and-interfaces)
