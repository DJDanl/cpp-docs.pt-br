---
title: Implementando uma Interface Dupla (ATL)
ms.date: 11/04/2016
helpviewer_keywords:
- IDispatchImpl class, implementing dual interfaces
- dual interfaces, implementing
ms.assetid: d1da3633-b445-4dcd-8a0a-3efdafada3ea
ms.openlocfilehash: a85597adad045bee3edb5cc3ed63c72a22fa08fe
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319463"
---
# <a name="implementing-a-dual-interface"></a>Implementando uma interface dupla

Você pode implementar uma interface dupla usando a classe [IDispatchImpl,](../atl/reference/idispatchimpl-class.md) que fornece uma implementação padrão dos `IDispatch` métodos em uma interface dupla. Para obter mais informações, consulte [Implementando a interface iDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface).

Para usar esta classe:

- Defina sua interface dupla em uma biblioteca de tipos.

- Obtenha sua classe a `IDispatchImpl` partir de uma especialização de (passe informações sobre a interface e a biblioteca de tipos como os argumentos do modelo).

- Adicione uma entrada (ou entradas) ao mapa COM `QueryInterface`para expor a interface dupla através de .

- Implemente a parte vtable da interface em sua classe.

- Certifique-se de que a biblioteca de tipos que contém a definição de interface esteja disponível para seus objetos em tempo de execução.

## <a name="atl-simple-object-wizard"></a>Assistente de objeto simples da ATL

Se você quiser criar uma nova interface e uma nova classe para implementá-la, você pode usar a [caixa de diálogo ATL Add Class](../ide/add-class-dialog-box.md)e, em seguida, o ASSISTENTE DE OBJETO SIMPLES [ATL](../atl/reference/atl-simple-object-wizard.md).

## <a name="implement-interface-wizard"></a>Assistente de Implementação de Interface

Se você tiver uma interface existente, você pode usar o [Assistente de Interface de Implemento](../atl/reference/adding-a-new-interface-in-an-atl-project.md) para adicionar a classe base necessária, entradas de mapa COM e implementações de método esqueleto a uma classe existente.

> [!NOTE]
> Você pode precisar ajustar a classe base gerada para que os números de versão principal `IDispatchImpl` e menor da biblioteca do tipo sejam passados como argumentos de modelo para sua classe base. O Assistente de Interface de Implemento não verifica o número da versão da biblioteca do tipo para você.

## <a name="implementing-idispatch"></a>Implementando o IDispatch

Você pode `IDispatchImpl` usar uma classe base para fornecer uma implementação de uma dispinterface apenas especificando a entrada apropriada no mapa COM (usando a [COM_INTERFACE_ENTRY2](reference/com-interface-entry-macros.md#com_interface_entry2) ou [COM_INTERFACE_ENTRY_IID](reference/com-interface-entry-macros.md#com_interface_entry_iid) macro) desde que você tenha uma biblioteca de tipos descrevendo uma interface dupla correspondente. É bastante comum `IDispatch` implementar a interface dessa forma, por exemplo. O ASSISTENTE DE OBJETO Simples ATL e o `IDispatch` Assistente de Interface de Implemento assumem que você pretende implementar desta forma, para que eles adicionem a entrada apropriada ao mapa.

> [!NOTE]
> A ATL oferece as classes [IDispEventImpl](../atl/reference/idispeventimpl-class.md) e [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md) para ajudá-lo a implementar dispinterfaces sem exigir uma biblioteca de tipos contendo a definição de uma interface dupla compatível.

## <a name="see-also"></a>Confira também

[Interfaces duplas e ATL](../atl/dual-interfaces-and-atl.md)
