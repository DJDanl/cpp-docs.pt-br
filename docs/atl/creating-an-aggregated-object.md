---
title: Criando um objeto agregado | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- aggregation [C++], creating aggregated objects
- aggregate objects [C++], creating
ms.assetid: fc29d7aa-fd53-4276-9c2f-37379f71b179
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8f6ff5a0fdcff62d62469f17388f633b83739a09
ms.sourcegitcommit: 26fff80635bd1d51bc51899203fddfea8b29b530
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/05/2018
ms.locfileid: "37850820"
---
# <a name="creating-an-aggregated-object"></a>Criando um objeto agregado
Delegados de agregação `IUnknown` chamadas, fornecendo um ponteiro para o objeto externo `IUnknown` para o objeto interno.  
  
### <a name="to-create-an-aggregated-object"></a>Para criar um objeto agregado  
  
1.  Adicionar um `IUnknown` ponteiro para sua classe de objeto e inicializá-lo como NULL no construtor.  
  
2.  Substituir [FinalConstruct](../atl/reference/ccomobjectrootex-class.md#finalconstruct) para criar a agregação.  
  
3.  Use o `IUnknown` ponteiro, definido na etapa 1, como o segundo parâmetro para o [COM_INTERFACE_ENTRY_AGGREGATE](reference/com-interface-entry-macros.md#com_interface_entry_aggregate) macros.  
  
4.  Substituir [FinalRelease](../atl/reference/ccomobjectrootex-class.md#finalrelease) para liberar o `IUnknown` ponteiro.  
  
> [!NOTE]
>  Se você usar e liberar uma interface do objeto agregado durante `FinalConstruct`, você deve adicionar a [DECLARE_PROTECT_FINAL_CONSTRUCT](reference/aggregation-and-class-factory-macros.md#declare_protect_final_construct) macro à definição de seu objeto de classe.  
  
## <a name="see-also"></a>Consulte também  
 [Princípios básicos de objetos COM da ATL](../atl/fundamentals-of-atl-com-objects.md)

