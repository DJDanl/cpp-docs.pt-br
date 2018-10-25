---
title: Criando um provedor somente leitura simples | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, creating
- OLE DB provider templates, creating providers
ms.assetid: ade8ccdd-9ea4-4e46-a964-18460c2a2401
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: b32517e8254f383e624c5262f3a806e66ed28824
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50056250"
---
# <a name="creating-a-simple-read-only-provider"></a>Criando um provedor somente leitura simples

Quando você tiver criado um provedor OLE DB usando o Assistente da ATL OLE DB Provider e o ATL Project Wizard, você pode adicionar outras funcionalidades que você deseja dar suporte. Começar a projetar seu provedor, examinando o tipo de dados que você está enviando para o consumidor e sob quais condições. É especialmente importante determinar se é necessário dar suporte a comandos, transações e outros objetos opcionais. Um bom design com antecedência irá acelerar a implementação e teste.

O exemplo é apresentado em duas partes:

- O primeiro mostra parte como [criar um provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md) que lê um par de cadeias de caracteres.

- O segundo mostra parte como [aprimorar o provedor somente leitura simples](../../data/oledb/enhancing-the-simple-read-only-provider.md) adicionando o `IRowsetLocate` interface.

## <a name="see-also"></a>Consulte também

[Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)