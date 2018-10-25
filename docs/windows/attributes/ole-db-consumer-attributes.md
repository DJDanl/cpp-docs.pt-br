---
title: Atributos de consumidor do OLE DB (COM C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- attributes [C++/CLI], database
- attributes [C++/CLI], data access
- databases [C++], attributes
- OLE DB consumers [C++], attributes
- database attributes [C++/CLI]
- attributes [C++/CLI], OLE DB consumer
ms.assetid: 017b591f-8f9a-42b4-84d5-cc42a21ab0cc
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 19c3e441ff4130d30f3aeb7957c5af85576fb9e1
ms.sourcegitcommit: a9dcbcc85b4c28eed280d8e451c494a00d8c4c25
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/25/2018
ms.locfileid: "50065857"
---
# <a name="ole-db-consumer-attributes"></a>Atributos de consumidor de banco de dados OLE
Os atributos de consumidor do OLE DB injetam código, com base nas [OLE DB modelos de consumidor](../../data/oledb/ole-db-consumer-templates-reference.md), para criar um trabalho do OLE DB consumidor que executa tarefas como abrir tabelas, executar comandos e acesso a dados.

|Atributo|Descrição|
|---------------|-----------------|
|[db_accessor](db-accessor.md)|Associa as colunas em um conjunto de linhas e associa-os para os mapas de acessador correspondente.|
|[db_column](db-column.md)|Associa uma coluna especificada para o conjunto de linhas.|
|[db_command](db-command.md)|Executa um comando OLE DB.|
|[db_param](db-param.md)|Associa a variável de membro especificado com um parâmetro de entrada ou saído.|
|[db_source](db-source.md)|Cria e encapsula uma conexão, por meio de um provedor, a fonte de dados.|
|[db_table](db-table.md)|Abre uma tabela de OLE DB.|

## <a name="see-also"></a>Consulte também

[Atributos por grupo](attributes-by-group.md)