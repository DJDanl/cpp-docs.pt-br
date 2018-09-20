---
title: Atributos de consumidor do OLE DB | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
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
ms.openlocfilehash: 07b129e2810b7b1310eb8988ca60fbd6e5dcad5a
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46391913"
---
# <a name="ole-db-consumer-attributes"></a>Atributos de consumidor de banco de dados OLE
Os atributos de consumidor do OLE DB injetam código, com base nas [OLE DB modelos de consumidor](../data/oledb/ole-db-consumer-templates-reference.md), para criar um trabalho do OLE DB consumidor que executa tarefas como abrir tabelas, executar comandos e acesso a dados.
  
|Atributo|Descrição|
|---------------|-----------------|
|[db_accessor](../windows/db-accessor.md)|Associa as colunas em um conjunto de linhas e associa-os para os mapas de acessador correspondente.|
|[db_column](../windows/db-column.md)|Associa uma coluna especificada para o conjunto de linhas.|
|[db_command](../windows/db-command.md)|Executa um comando OLE DB.|
|[db_param](../windows/db-param.md)|Associa a variável de membro especificado com um parâmetro de entrada ou saído.|
|[db_source](../windows/db-source.md)|Cria e encapsula uma conexão, por meio de um provedor, a fonte de dados.|
|[db_table](../windows/db-table.md)|Abre uma tabela de OLE DB.|
  
## <a name="see-also"></a>Consulte também

[Atributos por grupo](../windows/attributes-by-group.md)