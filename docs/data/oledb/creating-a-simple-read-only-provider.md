---
title: Criando um provedor somente leitura simples | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- OLE DB providers, creating
- OLE DB provider templates, creating providers
ms.assetid: ade8ccdd-9ea4-4e46-a964-18460c2a2401
caps.latest.revision: "8"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 6b5f840a6f401d8eb1bcca598d86622deb8f86cb
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-a-simple-read-only-provider"></a>Criando um provedor somente leitura simples
Quando você tiver criado um provedor OLE DB usando o Assistente de projeto de ATL e ATL OLE DB Provider assistente, você pode adicionar outra funcionalidade que você deseja dar suporte. Começar a criar seu provedor examinando o tipo de dados que você está enviando para o consumidor e sob que condições. É especialmente importante determinar se é necessário dar suporte a comandos, transações e outros objetos opcionais. Um bom design adiantado irão acelerar a implementação e teste.  
  
 O exemplo é apresentado em duas partes:  
  
-   O primeiro mostra parte como [criar um provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md) que lê um par de cadeias de caracteres.  
  
-   O segundo mostra parte como [aprimorar o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md) adicionando o `IRowsetLocate` interface.  
  
## <a name="see-also"></a>Consulte também  
 [Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)