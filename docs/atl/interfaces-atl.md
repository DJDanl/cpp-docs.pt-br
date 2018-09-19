---
title: Interfaces (ATL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- COM interfaces
- interfaces, COM
ms.assetid: de6c8b12-6230-4fdc-af66-a28b91d5ee55
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ef93476e669b923d642f79f480c602229d6a4322
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46071153"
---
# <a name="interfaces-atl"></a>Interfaces (ATL)

Uma interface é a maneira na qual um objeto exponha sua funcionalidade para o mundo exterior. No COM, uma interface é uma tabela de ponteiros (como uma vtable C++) para funções implementadas pelo objeto. A tabela representa a interface e as funções para o qual ele aponta são os métodos dessa interface. Um objeto pode expor quantas interfaces conforme ele escolhe.

Cada interface é baseada na interface COM fundamental, [IUnknown](../atl/iunknown.md). Os métodos de `IUnknown` permitem a navegação para outras interfaces expostas pelo objeto.

Além disso, cada interface é fornecida uma interface exclusiva IID (ID). Este exclusividade torna fácil para dar suporte a controle de versão da interface. Uma nova versão de uma interface é simplesmente uma nova interface, com uma IID de novo.

> [!NOTE]
>  IIDs para interfaces COM e OLE padrão são predefinidos.

## <a name="see-also"></a>Consulte também

[Introdução a COM](../atl/introduction-to-com.md)<br/>
[Interfaces e objetos COM](/windows/desktop/com/com-objects-and-interfaces)

