---
title: Criando um provedor somente leitura simples | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, creating
- OLE DB provider templates, creating providers
ms.assetid: ade8ccdd-9ea4-4e46-a964-18460c2a2401
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 830ba99037607f4fc8ceac9bad451381c30c7786
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="creating-a-simple-read-only-provider"></a>Criando um provedor somente leitura simples
Quando você tiver criado um provedor OLE DB usando o Assistente de projeto de ATL e ATL OLE DB Provider assistente, você pode adicionar outra funcionalidade que você deseja dar suporte. Começar a criar seu provedor examinando o tipo de dados que você está enviando para o consumidor e sob que condições. É especialmente importante determinar se é necessário dar suporte a comandos, transações e outros objetos opcionais. Um bom design adiantado irão acelerar a implementação e teste.  
  
 O exemplo é apresentado em duas partes:  
  
-   O primeiro mostra parte como [criar um provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md) que lê um par de cadeias de caracteres.  
  
-   O segundo mostra parte como [aprimorar o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md) adicionando o `IRowsetLocate` interface.  
  
## <a name="see-also"></a>Consulte também  
 [Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)