---
title: Criando um objeto agregado
ms.date: 11/04/2016
helpviewer_keywords:
- aggregation [C++], creating aggregated objects
- aggregate objects [C++], creating
ms.assetid: fc29d7aa-fd53-4276-9c2f-37379f71b179
ms.openlocfilehash: 4be8d0e852da91b58125dc01d44eed4560b2b8d9
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57277515"
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
