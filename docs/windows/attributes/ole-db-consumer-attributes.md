---
title: Atributos de consumidor do OLE DB (COM C++)
ms.date: 10/02/2018
helpviewer_keywords:
- attributes [C++/CLI], database
- attributes [C++/CLI], data access
- databases [C++], attributes
- OLE DB consumers [C++], attributes
- database attributes [C++/CLI]
- attributes [C++/CLI], OLE DB consumer
ms.assetid: 017b591f-8f9a-42b4-84d5-cc42a21ab0cc
ms.openlocfilehash: 036ac539fcac715ba12e4c7cf7fc83edd7a23c38
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50662925"
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