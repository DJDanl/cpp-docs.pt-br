---
title: "Implementando uma interface dupla | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "interfaces duais, implementando"
  - "Classe de IDispatchImpl, implementando interfaces duais"
ms.assetid: d1da3633-b445-4dcd-8a0a-3efdafada3ea
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Implementando uma interface dupla
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode implementar uma interface dupla usando a classe de [IDispatchImpl](../atl/reference/idispatchimpl-class.md) , que fornece uma implementação padrão dos métodos de `IDispatch` em uma interface dupla.  Para mais informações, consulte [Implementing the IDispatch Interface](http://msdn.microsoft.com/pt-br/0e171f7f-0022-4e9b-ac8e-98192828e945).  
  
 Para usar esta classe:  
  
-   Defina sua interface dupla em uma biblioteca de tipo.  
  
-   A classe deriva de uma especialização de `IDispatchImpl` \(informações de passagem sobre a biblioteca de interface e como argumentos de tipo de modelo\).  
  
-   Adicione uma entrada \(ou entradas\) ao mapa COM para expor a interface dupla com `QueryInterface`.  
  
-   Implementar a parte vtable de interface em sua classe.  
  
-   Certifique\-se de que a biblioteca de tipos que contém a definição de interface está disponível para os objetos em tempo de execução.  
  
## Assistente simples de objeto de ATL  
 Se você desejar criar uma nova interface e uma nova classe para implementar, você pode usar [ATL adiciona a caixa de diálogo de classe](../ide/add-class-dialog-box.md), e então [Assistente simples de objeto de ATL](../atl/reference/atl-simple-object-wizard.md).  
  
## Assistente de interface de implementam  
 Se você tiver uma interface existente, você pode usar [Assistente de interface de implementam](../Topic/Adding%20a%20New%20Interface%20in%20an%20ATL%20Project.md) para adicionar as entradas necessárias da classe base, o mapa COM, e implementações de esqueleto de métodos a uma classe existente.  
  
> [!NOTE]
>  Você talvez precise ajustar a classe base gerado para que os números de versão principal e secundário da biblioteca de tipos a serem passados como argumentos de modelo a sua classe base de `IDispatchImpl` .  O assistente de interface de implementar não verifica o número de versão da biblioteca de tipo para você.  
  
## Implementando IDispatch  
 Você pode usar uma classe base de `IDispatchImpl` para fornecer uma implementação de um dispinterface apenas especificando a entrada apropriado no mapa COM \(usando a macro de [COM\_INTERFACE\_ENTRY2](../Topic/COM_INTERFACE_ENTRY2.md) ou de [COM\_INTERFACE\_ENTRY\_IID](../Topic/COM_INTERFACE_ENTRY_IID.md) \) como você tiver uma biblioteca de tipo que descreve uma interface dupla correspondente.  É muito comum implementar a interface de `IDispatch` essa maneira, por exemplo.  O assistente e implementam simples de objeto de ATL interface o assistente que ambos presumem que você pretende implementar essa maneira `IDispatch` , o que irão aumentar a entrada apropriado ao mapa.  
  
> [!NOTE]
>  ATL oferece as classes de [IDispEventImpl](../atl/reference/idispeventimpl-class.md) e de [IDispEventSimpleImpl](../atl/reference/idispeventsimpleimpl-class.md) ajudá\-lo a implementação dispinterfaces sem exigir uma biblioteca de tipo que contém a definição de uma interface dupla correspondente.  
  
## Consulte também  
 [Interfaces duais e ATL](../atl/dual-interfaces-and-atl.md)