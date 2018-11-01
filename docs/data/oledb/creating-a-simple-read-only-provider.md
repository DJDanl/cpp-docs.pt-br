---
title: Criando um provedor somente leitura simples
ms.date: 10/26/2018
helpviewer_keywords:
- OLE DB providers, creating
- OLE DB provider templates, creating providers
ms.assetid: ade8ccdd-9ea4-4e46-a964-18460c2a2401
ms.openlocfilehash: 2ac8e45ca06a5566923141adf5a22dc6710eeeab
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50432598"
---
# <a name="creating-a-simple-read-only-provider"></a>Criando um provedor somente leitura simples

Quando você criar um provedor OLE DB usando o **ATL Project Wizard** e **ATL OLE DB Provider Wizard**, você pode adicionar outras funcionalidades que você deseja dar suporte. Começar a projetar seu provedor, examinando o tipo de dados será enviado para o consumidor e sob quais condições. É especialmente importante determinar se é necessário dar suporte a comandos, transações e outros objetos opcionais. Um bom design com antecedência irá acelerar a implementação e teste.

O exemplo é apresentado em duas partes:

- O primeiro mostra parte como [criar um provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md) que lê um par de cadeias de caracteres.

- O segundo mostra parte como [aprimorar o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md) adicionando o `IRowsetLocate` interface.

## <a name="see-also"></a>Consulte também

[Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)<br/>
