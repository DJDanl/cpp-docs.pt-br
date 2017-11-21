---
title: "Interfaces duplas vários | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- multiple dual interfaces
- COM_INTERFACE_ENTRY2 macro
- dual interfaces, exposing multiple
- multiple dual interfaces, exposing with ATL
- IDispatchImpl class, multiple dual interfaces
- COM_INTERFACE_ENTRY_IID macro
ms.assetid: 7fea86e6-247f-4063-be6e-85588a9e3719
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 426109958cf9b34829c23ac0bfd59743f1681e72
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="multiple-dual-interfaces"></a>Várias Interfaces duplas
Talvez você queira combinar as vantagens de uma interface dupla (ou seja, a flexibilidade de vtable e associação tardia, tornando a classe disponíveis para linguagens de script, bem como C++) com as técnicas de várias heranças.  
  
 Embora seja possível expor várias interfaces duplas em um único objeto COM, não é recomendável. Se houver várias interfaces duplas, deve haver apenas um `IDispatch` interface exposta. As técnicas disponíveis para garantir que esse é o caso execute penalidades como perda de função ou complexidade aumentada de códigos. O desenvolvedor considerar essa abordagem deve avaliar cuidadosamente as vantagens e desvantagens.  
  
## <a name="exposing-a-single-idispatch-interface"></a>Expor uma Interface IDispatch  
 É possível expor várias interfaces duplas em um único objeto derivando de dois ou mais especializações de `IDispatchImpl`. No entanto, se você permitir que os clientes consultar o `IDispatch` interface, você precisará usar o [COM_INTERFACE_ENTRY2](reference/com-interface-entry-macros.md#com_interface_entry2) macro (ou [COM_INTERFACE_ENTRY_IID](reference/com-interface-entry-macros.md#com_interface_entry_iid))) para especificar qual classe base a ser usado para o implementação de `IDispatch`.  
  
 [!code-cpp[NVC_ATL_COM#23](../atl/codesnippet/cpp/multiple-dual-interfaces_1.h)]  
  
 Porque somente um `IDispatch` interface é exposta, clientes que podem acessar somente seus objetos por meio de `IDispatch` interface não poderão acessar os métodos ou propriedades em qualquer outra interface.  
  
## <a name="combining-multiple-dual-interfaces-into-a-single-implementation-of-idispatch"></a>Combinando várias Interfaces duplas em uma única implementação de IDispatch  
 ATL não fornece nenhum suporte para combinar várias interfaces duplas em uma única implementação de `IDispatch`. No entanto, há várias abordagens conhecidas para combinar manualmente as interfaces, como a criação de uma classe de modelo que contém uma união de separadas `IDispatch` interfaces, criando um novo objeto para executar o `QueryInterface` função, ou usando um a implementação baseada em TypeInfo de objetos aninhados para criar o `IDispatch` interface.  
  
 Essas abordagens têm problemas potenciais colisões de namespace, bem como a complexidade de código e facilidade de manutenção. Não é recomendável que você crie várias interfaces duplas.  
  
## <a name="see-also"></a>Consulte também  
 [Interfaces duplas e a ATL](../atl/dual-interfaces-and-atl.md)

