---
title: Implementando uma Interface dupla (ATL) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- IDispatchImpl class, implementing dual interfaces
- dual interfaces, implementing
ms.assetid: d1da3633-b445-4dcd-8a0a-3efdafada3ea
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7a362ba60b1601e2b291201e10ac49cf9c0ec1ef
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43765977"
---
# <a name="implementing-a-dual-interface"></a>Implementando uma Interface dupla

Você pode implementar uma interface dupla usando o [IDispatchImpl](../atl/reference/idispatchimpl-class.md) classe, que fornece uma implementação padrão da `IDispatch` métodos em uma interface dupla. Para obter mais informações, consulte [Implementando a IDispatch Interface](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface).

Para usar essa classe:

- Defina sua interface dupla em uma biblioteca de tipos.

- Derive sua classe de uma especialização de `IDispatchImpl` (passar informações sobre a biblioteca de interface e o tipo como argumentos de modelo).

- Adicionar uma entrada (ou entradas) para o mapa de COM para expor a interface dupla através de `QueryInterface`.

- Implemente a parte vtable da interface em sua classe.

- Certifique-se de que a biblioteca de tipos que contém a definição da interface está disponível para seus objetos em tempo de execução.

## <a name="atl-simple-object-wizard"></a>ATL Simple Object Wizard

Se você quiser criar uma nova interface e uma nova classe implementá-lo, você pode usar o [caixa de diálogo Adicionar classe de ATL](../ide/add-class-dialog-box.md)e, em seguida, o [ATL Simple Object Wizard](../atl/reference/atl-simple-object-wizard.md).

## <a name="implement-interface-wizard"></a>Assistente de Implementação de Interface

Se você tiver uma interface existente, você pode usar o [Assistente de implementação de Interface](../atl/reference/adding-a-new-interface-in-an-atl-project.md) para adicionar a classe base necessária, entradas de mapa COM e implementações de método esqueleto para uma classe existente.

> [!NOTE]
>  Talvez seja necessário ajustar a classe base gerada para que os números de versão principal e secundária da biblioteca de tipos são passados como argumentos de modelo para seu `IDispatchImpl` classe base. O Assistente de implementação de Interface não verifica o número de versão da biblioteca de tipo para você.

## <a name="implementing-idispatch"></a>Implementar IDispatch

Você pode usar um `IDispatchImpl` classe para fornecer uma implementação de um dispinterface apenas especificando a entrada apropriada no mapa COM base (usando o [COM_INTERFACE_ENTRY2](reference/com-interface-entry-macros.md#com_interface_entry2) ou [COM_INTERFACE_ENTRY_IID](reference/com-interface-entry-macros.md#com_interface_entry_iid) macro) desde que você tem uma biblioteca de tipos que descreve uma interface dupla correspondente. É muito comum para implementar o `IDispatch` interface dessa forma, por exemplo. O Assistente de Interface de implementar ambos pressupõem que você pretende implementar e o ATL Simple Object Wizard `IDispatch` dessa forma, portanto, eles adicionará a entrada apropriada ao mapa.

> [!NOTE]
>  ATL oferece o [IDispEventImpl](../atl/reference/idispeventimpl-class.md) e [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md) classes para ajudar a implementar dispinterfaces sem a necessidade de uma biblioteca de tipos que contém a definição de uma interface dupla compatível.

## <a name="see-also"></a>Consulte também

[Interfaces duplas e a ATL](../atl/dual-interfaces-and-atl.md)

