---
title: Atributos de membro de dados (COM C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- attributes [C++/CLI], reference topics
- data members [C++], attributes
- data members [C++]
ms.assetid: 95b2397d-1daf-4ae4-8cd0-06956d005b13
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5019503bed9dd0012d8aafc1ade4abd3107335ac
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48790115"
---
# <a name="data-member-attributes"></a>Atributos de membro de dados

Os atributos a seguir se aplicam para os membros de dados em uma classe, coclass ou interface.

|Atributo|Descrição|
|---------------|-----------------|
|[db_accessor](db-accessor.md)|Grupos `db_column` atributos que participam de `IAccessor`-com base em associação.|
|[db_column](db-column.md)|Associa uma coluna especificada para o conjunto de linhas.|
|[db_command](db-command.md)|Cria um comando OLE DB.|
|[db_param](db-param.md)|Associa a variável de membro especificado com um parâmetro de entrada ou saído e delimita a variável.|
|[db_source](db-source.md)|Cria uma conexão a uma fonte de dados.|
|[db_table](db-table.md)|Abre uma tabela de OLE DB.|
|[defaultbind](defaultbind.md)|Indica a única propriedade associável que melhor representa o objeto.|
|[displaybind](displaybind.md)|Indica uma propriedade que deve ser exibida para o usuário como associável.|
|[id](id.md)|Especifica um DISPID para uma função de membro (uma propriedade ou um método, em uma interface ou dispinterface).|
|[range](range-cpp.md)|Especifica um intervalo de valores permitidos para argumentos ou campos cujos valores são definidos em tempo de execução.|
|[rdx](rdx.md)|Cria uma chave do registro ou modifica uma chave do registro existente.|
|[readonly](readonly-cpp.md)|Proíbe a atribuição a um membro de dados.|
|[requestedit](requestedit.md)|Indica que a propriedade oferece suporte a `OnRequestEdit` notificação.|

## <a name="see-also"></a>Consulte também

[Atributos por uso](attributes-by-usage.md)