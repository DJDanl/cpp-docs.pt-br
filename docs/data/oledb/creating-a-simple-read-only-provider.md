---
title: Criando um provedor somente leitura simples
ms.date: 05/09/2019
helpviewer_keywords:
- OLE DB providers, creating
- OLE DB provider templates, creating providers
ms.assetid: ade8ccdd-9ea4-4e46-a964-18460c2a2401
ms.openlocfilehash: c0f31818002ce4611926d942b3bc556e31c1ae6f
ms.sourcegitcommit: 00e26915924869cd7eb3c971a7d0604388abd316
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/10/2019
ms.locfileid: "65524717"
---
# <a name="creating-a-simple-read-only-provider"></a>Criando um provedor somente leitura simples

::: moniker range="vs-2019"

O assistente de Provedor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores.

::: moniker-end

::: moniker range="vs-2017"

Ao criar um provedor de OLE DB usando o **Assistente de Projeto da ATL** e o **Assistente de Provedor ATL OLE DB**, você pode adicionar outras funcionalidades desejadas. Para começar a projetar seu provedor, examine o tipo de dados que você enviará para o consumidor e sob quais condições. É especialmente importante determinar se é necessário dar suporte a comandos, transações e outros objetos opcionais. Um bom design criado com antecedência acelera a implementação e o teste.

O exemplo é apresentado em duas partes:

- A primeira parte mostra como [criar um provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md) que lê um par de cadeias de caracteres.

- A segunda parte mostra como [aprimorar o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md) adicionando a interface `IRowsetLocate`.

::: moniker-end

## <a name="see-also"></a>Consulte também

[Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)<br/>
