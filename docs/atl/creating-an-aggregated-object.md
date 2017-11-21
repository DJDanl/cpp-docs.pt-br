---
title: "Criação de um objeto agregado | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- aggregation [C++], creating aggregated objects
- aggregate objects [C++], creating
ms.assetid: fc29d7aa-fd53-4276-9c2f-37379f71b179
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: b5446e4eb279e961ba59b5fd0b3713a7f976cef5
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="creating-an-aggregated-object"></a>Criação de um objeto agregado
Delegados de agregação **IUnknown** chamadas, fornecendo um ponteiro para o objeto externo **IUnknown** para o objeto interno.  
  
### <a name="to-create-an-aggregated-object"></a>Para criar um objeto agregado  
  
1.  Adicionar uma **IUnknown** ponteiro para a classe de objeto e inicializá-lo para **nulo** no construtor.  
  
2.  Substituir [FinalConstruct](../atl/reference/ccomobjectrootex-class.md#finalconstruct) para criar a agregação.  
  
3.  Use o **IUnknown** ponteiro, definido na etapa 1, como o segundo parâmetro para o [COM_INTERFACE_ENTRY_AGGREGATE](reference/com-interface-entry-macros.md#com_interface_entry_aggregate) macros.  
  
4.  Substituir [FinalRelease](../atl/reference/ccomobjectrootex-class.md#finalrelease) para liberar o **IUnknown** ponteiro.  
  
> [!NOTE]
>  Se você usar e liberar uma interface do objeto agregado durante `FinalConstruct`, você deve adicionar o [DECLARE_PROTECT_FINAL_CONSTRUCT](reference/aggregation-and-class-factory-macros.md#declare_protect_final_construct) macro à definição de seu objeto de classe.  
  
## <a name="see-also"></a>Consulte também  
 [Princípios básicos de objetos COM da ATL](../atl/fundamentals-of-atl-com-objects.md)

