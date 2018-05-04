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
ms.openlocfilehash: 34cc55e4466dba094bf70e734340b40237207f3c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="implementing-a-dual-interface"></a>Implementando uma Interface dupla
Você pode implementar uma interface dupla usando o [IDispatchImpl](../atl/reference/idispatchimpl-class.md) classe, que fornece uma implementação padrão de `IDispatch` métodos em uma interface dupla. Para obter mais informações, consulte [Implementando a IDispatch Interface](http://msdn.microsoft.com/en-us/0e171f7f-0022-4e9b-ac8e-98192828e945).  
  
 Para usar essa classe:  
  
-   Defina sua interface dupla em uma biblioteca de tipos.  
  
-   Derive a classe de uma especialização de `IDispatchImpl` (passar informações sobre a biblioteca de interface e o tipo como argumentos de modelo).  
  
-   Adicionar uma entrada (ou entradas) para o mapa de COM para expor a interface dupla por meio de `QueryInterface`.  
  
-   Implemente a parte vtable da interface em sua classe.  
  
-   Certifique-se de que a biblioteca de tipos que contém a definição da interface está disponível para os objetos em tempo de execução.  
  
## <a name="atl-simple-object-wizard"></a>Assistente de objeto simples de ATL  
 Se você quiser criar uma nova interface e uma nova classe para implementá-lo, você pode usar o [caixa de diálogo Adicionar classe de ATL](../ide/add-class-dialog-box.md)e, em seguida, o [ATL Simple Object Wizard](../atl/reference/atl-simple-object-wizard.md).  
  
## <a name="implement-interface-wizard"></a>Assistente de Implementação de Interface  
 Se você tiver uma interface existente, você pode usar o [Assistente de implementação de Interface](../atl/reference/adding-a-new-interface-in-an-atl-project.md) para adicionar a classe base necessária, entradas do mapa COM e implementações de método esqueleto a uma classe existente.  
  
> [!NOTE]
>  Talvez seja necessário ajustar a classe base gerada para que os números de versão primária e secundária da biblioteca de tipos são transmitidos como argumentos de modelo para sua `IDispatchImpl` classe base. O Assistente de implementação de Interface não verifica o número de versão da biblioteca de tipo para você.  
  
## <a name="implementing-idispatch"></a>Implementar IDispatch  
 Você pode usar um `IDispatchImpl` classe para fornecer uma implementação de um dispinterface apenas especificando a entrada apropriada no mapa COM base (usando o [COM_INTERFACE_ENTRY2](reference/com-interface-entry-macros.md#com_interface_entry2) ou [COM_INTERFACE_ENTRY_IID](reference/com-interface-entry-macros.md#com_interface_entry_iid) macro) desde que você tiver uma biblioteca de tipos que descreve uma interface dupla correspondente. É muito comum para implementar o `IDispatch` interface dessa forma, por exemplo. O Assistente de objeto ATL simples e o Assistente de Interface de implementar ambos pressupõem que você pretende implementar `IDispatch` dessa forma, portanto eles adicionará a entrada apropriada para o mapa.  
  
> [!NOTE]
>  ATL oferece o [IDispEventImpl](../atl/reference/idispeventimpl-class.md) e [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md) classes para ajudá-lo a implementar dispinterfaces sem a necessidade de uma biblioteca de tipos que contém a definição de uma interface dupla compatível.  
  
## <a name="see-also"></a>Consulte também  
 [Interfaces duplas e a ATL](../atl/dual-interfaces-and-atl.md)

