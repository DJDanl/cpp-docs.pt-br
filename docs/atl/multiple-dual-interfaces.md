---
title: Múltiplas Interfaces duplas | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- multiple dual interfaces
- COM_INTERFACE_ENTRY2 macro
- dual interfaces, exposing multiple
- multiple dual interfaces, exposing with ATL
- IDispatchImpl class, multiple dual interfaces
- COM_INTERFACE_ENTRY_IID macro
ms.assetid: 7fea86e6-247f-4063-be6e-85588a9e3719
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 80bc2d4cc112c87c5c7a4e7d30f680631c1a1506
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43758281"
---
# <a name="multiple-dual-interfaces"></a>Múltiplas Interfaces duplas

Talvez você queira combinar as vantagens de uma interface dupla (ou seja, a flexibilidade de vtable e associação tardia, tornando a classe disponíveis para linguagens de script, bem como o C++) com as técnicas de herança múltipla.

Embora seja possível expor várias interfaces de duplos em um único objeto COM, não é recomendável. Se houver múltiplas interfaces duplas, deve haver apenas um `IDispatch` interface exposta. As técnicas disponíveis para garantir que esse é o caso carregam penalidades como perda de função ou complexidade aumentada de códigos. O desenvolvedor considerando essa abordagem deve avaliar com cuidado as vantagens e desvantagens.

## <a name="exposing-a-single-idispatch-interface"></a>Expor uma única Interface IDispatch

É possível expor várias interfaces duplas em um único objeto, derivando de duas ou mais especializações de `IDispatchImpl`. No entanto, se você permitir que os clientes de consulta para o `IDispatch` interface, você precisará usar o [COM_INTERFACE_ENTRY2](reference/com-interface-entry-macros.md#com_interface_entry2) macro (ou [COM_INTERFACE_ENTRY_IID](reference/com-interface-entry-macros.md#com_interface_entry_iid))) para especificar qual classe base a ser usado para o implementação de `IDispatch`.

[!code-cpp[NVC_ATL_COM#23](../atl/codesnippet/cpp/multiple-dual-interfaces_1.h)]

Porque apenas um `IDispatch` interface é exposta, clientes que só podem acessar seus objetos através de `IDispatch` interface não poderão acessar os métodos ou propriedades em qualquer outra interface.

## <a name="combining-multiple-dual-interfaces-into-a-single-implementation-of-idispatch"></a>Combinando várias Interfaces duplas em uma única implementação de IDispatch

ATL não fornece nenhum suporte para combinar várias interfaces duplas em uma única implementação de `IDispatch`. No entanto, há várias abordagens conhecidas para combinar manualmente as interfaces, como a criação de uma classe de modelo que contém uma união de separada `IDispatch` interfaces, criando um novo objeto para executar o `QueryInterface` função, ou usando um a implementação baseada em TypeInfo de objetos aninhados para criar o `IDispatch` interface.

Essas abordagens têm problemas com possíveis conflitos de namespace, bem como a complexidade do código e a facilidade de manutenção. Não é recomendável que você crie múltiplas interfaces duplas.

## <a name="see-also"></a>Consulte também

[Interfaces duplas e a ATL](../atl/dual-interfaces-and-atl.md)

