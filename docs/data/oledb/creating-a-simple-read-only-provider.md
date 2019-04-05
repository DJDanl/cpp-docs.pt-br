---
title: Criando um provedor somente leitura simples
ms.date: 10/26/2018
helpviewer_keywords:
- OLE DB providers, creating
- OLE DB provider templates, creating providers
ms.assetid: ade8ccdd-9ea4-4e46-a964-18460c2a2401
ms.openlocfilehash: a80678f6bc512c45c0df2ea5cbfc4708f1252ac0
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59035355"
---
# <a name="creating-a-simple-read-only-provider"></a>Criando um provedor somente leitura simples

Quando você criar um provedor OLE DB usando o **ATL Project Wizard** e **ATL OLE DB Provider Wizard**, você pode adicionar outras funcionalidades que você deseja dar suporte. Começar a projetar seu provedor, examinando o tipo de dados será enviado para o consumidor e sob quais condições. É especialmente importante determinar se é necessário dar suporte a comandos, transações e outros objetos opcionais. Um bom design com antecedência irá acelerar a implementação e teste.

O exemplo é apresentado em duas partes:

- O primeiro mostra parte como [criar um provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md) que lê um par de cadeias de caracteres.

- O segundo mostra parte como [aprimorar o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md) adicionando o `IRowsetLocate` interface.

## <a name="see-also"></a>Consulte também

[Criando um provedor de banco de dados OLE](../../data/oledb/creating-an-ole-db-provider.md)<br/>
