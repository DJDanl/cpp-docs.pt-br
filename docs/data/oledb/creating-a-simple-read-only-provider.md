---
title: Criando um provedor somente leitura simples
ms.date: 05/09/2019
helpviewer_keywords:
- OLE DB providers, creating
- OLE DB provider templates, creating providers
ms.assetid: ade8ccdd-9ea4-4e46-a964-18460c2a2401
ms.openlocfilehash: c7c6c5bb2691a110a6368decd875f5a5a06b11b5
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92919183"
---
# <a name="creating-a-simple-read-only-provider"></a>Criando um provedor somente leitura simples

::: moniker range="msvc-160"

O assistente de Provedor OLE DB da ATL não está disponível no Visual Studio 2019 e posteriores.

::: moniker-end

::: moniker range="<=msvc-150"

Ao criar um provedor de OLE DB usando o **Assistente de Projeto da ATL** e o **Assistente de Provedor ATL OLE DB** , você pode adicionar outras funcionalidades desejadas. Para começar a projetar seu provedor, examine o tipo de dados que você enviará para o consumidor e sob quais condições. É especialmente importante determinar se é necessário dar suporte a comandos, transações e outros objetos opcionais. Um bom design criado com antecedência acelera a implementação e o teste.

O exemplo é apresentado em duas partes:

- A primeira parte mostra como [criar um provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md) que lê um par de cadeias de caracteres.

- A segunda parte mostra como [aprimorar o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md) adicionando a interface `IRowsetLocate`.

::: moniker-end

## <a name="see-also"></a>Veja também

[Criando um provedor de OLE DB](../../data/oledb/creating-an-ole-db-provider.md)<br/>
