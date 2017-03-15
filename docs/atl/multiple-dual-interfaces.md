---
title: "V&#225;rias interfaces duais | Microsoft Docs"
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
  - "Macro de COM_INTERFACE_ENTRY_IID"
  - "Macro COM_INTERFACE_ENTRY2"
  - "interfaces duais, expõe várias"
  - "Classe de IDispatchImpl, várias interfaces duais"
  - "várias interfaces duais"
  - "várias interfaces duais, expor com ATL"
ms.assetid: 7fea86e6-247f-4063-be6e-85588a9e3719
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# V&#225;rias interfaces duais
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode desejar combinar as vantagens de uma interface dupla \(ou seja, a flexibilidade de vtable e de associação tardia, então fazendo a classe disponível para as linguagens de script bem como ao C\+\+\) com as técnicas de várias heranças.  
  
 Embora seja possível exibir várias interfaces duais em um único objeto COM, não é recomendável.  Se há várias interfaces duais, deve haver apenas uma interface de `IDispatch` expostas.  As técnicas disponíveis para garantir que este é o caso levam suspensa como perda de função ou de complexidade gerada de código.  O desenvolvedor que considera essa abordagem com cuidado deve avaliar as vantagens e desvantagens.  
  
## Expõe uma única interface de IDispatch  
 É possível exibir várias interfaces duais em um único objeto derivando de dois ou mais especializações de `IDispatchImpl`.  Em o entanto, se você permite que os clientes consulte para a interface de `IDispatch` , você precisará usar a macro de [COM\_INTERFACE\_ENTRY2](../Topic/COM_INTERFACE_ENTRY2.md) \(ou [COM\_INTERFACE\_ENTRY\_IID](../Topic/COM_INTERFACE_ENTRY_IID.md)\) para especificar que a classe base a usar para a implementação de `IDispatch`.  
  
 [!code-cpp[NVC_ATL_COM#23](../atl/codesnippet/CPP/multiple-dual-interfaces_1.h)]  
  
 Porque apenas uma interface de `IDispatch` é exposta, os clientes que só podem acessar seus objetos através da interface de `IDispatch` não poderão acessar os métodos ou propriedades em qualquer outro interface.  
  
## Combinando vários interfaces duais em uma única implementação de IDispatch  
 Fornece ATL não há suporte para combinar várias interfaces duais em uma única implementação de `IDispatch`.  Em o entanto, há várias abordagens conhecidas manualmente a combinar as interfaces, como a criação de uma classe de modelo que contém uma união das interfaces separadas de `IDispatch` , criando um novo objeto para executar a função de `QueryInterface` , ou usando uma implementação base typeinfo\- de objetos aninhados para criar a interface de `IDispatch` .  
  
 Essas abordagens têm possíveis problemas com colisões de namespace, bem como código complexidade e sustentabilidade.  Não é recomendável que você cria várias interfaces duais.  
  
## Consulte também  
 [Interfaces duais e ATL](../atl/dual-interfaces-and-atl.md)