---
title: Interfaces (ATL)
ms.date: 11/04/2016
ms.topic: reference
helpviewer_keywords:
- COM interfaces
- interfaces, COM
ms.assetid: de6c8b12-6230-4fdc-af66-a28b91d5ee55
ms.openlocfilehash: 56d5a010bc28257dce181ee33e0ddf74655ccd3c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319381"
---
# <a name="interfaces-atl"></a>Interfaces (ATL)

Uma interface é a maneira pela qual um objeto expõe sua funcionalidade ao mundo exterior. Em COM, uma interface é uma tabela de ponteiros (como uma vtable C++) para funções implementadas pelo objeto. A tabela representa a interface e as funções para as quais ela aponta são os métodos dessa interface. Um objeto pode expor quantas interfaces quiser.

Cada interface é baseada na interface COM fundamental, [IUnknown](../atl/iunknown.md). Os métodos `IUnknown` permitem a navegação para outras interfaces expostas pelo objeto.

Além disso, cada interface recebe um ID de interface único (IID). Essa singularidade facilita o suporte à versão de interface. Uma nova versão de uma interface é simplesmente uma nova interface, com um novo IID.

> [!NOTE]
> Os IIDs para as interfaces COM e OLE padrão são predefinidos.

## <a name="see-also"></a>Confira também

[Introdução ao COM](../atl/introduction-to-com.md)<br/>
[Objetos e interfaces COM](/windows/win32/com/com-objects-and-interfaces)
