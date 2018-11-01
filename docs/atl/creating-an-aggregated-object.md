---
title: Criando um objeto agregado
ms.date: 11/04/2016
helpviewer_keywords:
- aggregation [C++], creating aggregated objects
- aggregate objects [C++], creating
ms.assetid: fc29d7aa-fd53-4276-9c2f-37379f71b179
ms.openlocfilehash: 5c655b8ced7738b30bf13d088cfadf11b5c65ef0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50449849"
---
# <a name="creating-an-aggregated-object"></a>Criando um objeto agregado

Delegados de agregação `IUnknown` chamadas, fornecendo um ponteiro para o objeto externo `IUnknown` para o objeto interno.

## <a name="to-create-an-aggregated-object"></a>Para criar um objeto agregado

1. Adicionar um `IUnknown` ponteiro para sua classe de objeto e inicializá-lo como NULL no construtor.

1. Substituir [FinalConstruct](../atl/reference/ccomobjectrootex-class.md#finalconstruct) para criar a agregação.

1. Use o `IUnknown` ponteiro, definido na etapa 1, como o segundo parâmetro para o [COM_INTERFACE_ENTRY_AGGREGATE](reference/com-interface-entry-macros.md#com_interface_entry_aggregate) macros.

1. Substituir [FinalRelease](../atl/reference/ccomobjectrootex-class.md#finalrelease) para liberar o `IUnknown` ponteiro.

> [!NOTE]
> Se você usar e liberar uma interface do objeto agregado durante `FinalConstruct`, você deve adicionar a [DECLARE_PROTECT_FINAL_CONSTRUCT](reference/aggregation-and-class-factory-macros.md#declare_protect_final_construct) macro à definição de seu objeto de classe.

## <a name="see-also"></a>Consulte também

[Princípios básicos de objetos COM da ATL](../atl/fundamentals-of-atl-com-objects.md)

