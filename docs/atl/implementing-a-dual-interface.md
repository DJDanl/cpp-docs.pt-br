---
title: Implementando uma interface dual (ATL)
ms.date: 11/04/2016
helpviewer_keywords:
- IDispatchImpl class, implementing dual interfaces
- dual interfaces, implementing
ms.assetid: d1da3633-b445-4dcd-8a0a-3efdafada3ea
ms.openlocfilehash: 97d8cd912c85a74f3550a9ca6c7b87a9717d4075
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91499550"
---
# <a name="implementing-a-dual-interface"></a>Implementando uma interface dupla

Você pode implementar uma interface dupla usando a classe [IDispatchImpl](../atl/reference/idispatchimpl-class.md) , que fornece uma implementação padrão dos `IDispatch` métodos em uma interface dupla. Para obter mais informações, consulte [implementando a interface IDispatch](/previous-versions/windows/desktop/automat/implementing-the-idispatch-interface).

Para usar esta classe:

- Defina a interface dupla em uma biblioteca de tipos.

- Derive sua classe de uma especialização `IDispatchImpl` (passe as informações sobre a interface e a biblioteca de tipos como os argumentos do modelo).

- Adicione uma entrada (ou entradas) ao mapa COM para expor a interface dupla por meio do `QueryInterface` .

- Implemente a parte vtable da interface em sua classe.

- Verifique se a biblioteca de tipos que contém a definição de interface está disponível para seus objetos em tempo de execução.

## <a name="atl-simple-object-wizard"></a>Assistente de objeto simples da ATL

Se você quiser criar uma nova interface e uma nova classe para implementá-la, você pode usar a [caixa de diálogo ATL Adicionar classe](../ide/adding-a-class-visual-cpp.md#add-class-dialog-box)e, em seguida, o [Assistente de objeto simples do ATL](../atl/reference/atl-simple-object-wizard.md).

## <a name="implement-interface-wizard"></a>Assistente de Implementação de Interface

Se você tiver uma interface existente, poderá usar o [Assistente para implementar interface](../atl/reference/adding-a-new-interface-in-an-atl-project.md) para adicionar a classe base necessária, as entradas de mapa com e as implementações de método esqueleto a uma classe existente.

> [!NOTE]
> Talvez seja necessário ajustar a classe base gerada para que os números de versão principal e secundária da biblioteca de tipos sejam passados como argumentos de modelo para sua `IDispatchImpl` classe base. O assistente para implementar interface não verifica o número de versão da biblioteca de tipos para você.

## <a name="implementing-idispatch"></a>Implementando o IDispatch

Você pode usar uma `IDispatchImpl` classe base para fornecer uma implementação de uma dispinterface apenas especificando a entrada apropriada no mapa com (usando a macro [COM_INTERFACE_ENTRY2](reference/com-interface-entry-macros.md#com_interface_entry2) ou [COM_INTERFACE_ENTRY_IID](reference/com-interface-entry-macros.md#com_interface_entry_iid) ), contanto que você tenha uma biblioteca de tipos que descreva uma interface dupla correspondente. É muito comum implementar a `IDispatch` interface dessa forma, por exemplo. O assistente de objeto simples do ATL e o assistente de implementação de interface pressupõem que você pretende implementar `IDispatch` dessa forma, para que eles adicionem a entrada apropriada ao mapa.

> [!NOTE]
> A ATL oferece as classes [IDispEventImpl](../atl/reference/idispeventimpl-class.md) e [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md) para ajudá-lo a implementar dispinterfaces sem a necessidade de uma biblioteca de tipos que contenha a definição de uma interface dupla compatível.

## <a name="see-also"></a>Consulte também

[Interfaces duplas e ATL](../atl/dual-interfaces-and-atl.md)
