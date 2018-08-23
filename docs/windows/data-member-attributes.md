---
title: Atributos de membro de dados | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- attributes [C++], reference topics
- data members [C++], attributes
- data members [C++]
ms.assetid: 95b2397d-1daf-4ae4-8cd0-06956d005b13
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5eb54889cb6e2590c334ad4e9aed497a945cc99d
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42601777"
---
# <a name="data-member-attributes"></a>Atributos de membro de dados

Os atributos a seguir se aplicam para os membros de dados em uma classe, coclass ou interface.

|Atributo|Descrição|
|---------------|-----------------|
|[db_accessor](../windows/db-accessor.md)|Grupos `db_column` atributos que participam de `IAccessor`-com base em associação.|
|[db_column](../windows/db-column.md)|Associa uma coluna especificada para o conjunto de linhas.|
|[db_command](../windows/db-command.md)|Cria um comando OLE DB.|
|[db_param](../windows/db-param.md)|Associa a variável de membro especificado com um parâmetro de entrada ou saído e delimita a variável.|
|[db_source](../windows/db-source.md)|Cria uma conexão a uma fonte de dados.|
|[db_table](../windows/db-table.md)|Abre uma tabela de OLE DB.|
|[defaultbind](../windows/defaultbind.md)|Indica a única propriedade associável que melhor representa o objeto.|
|[displaybind](../windows/displaybind.md)|Indica uma propriedade que deve ser exibida para o usuário como associável.|
|[id](../windows/id.md)|Especifica um DISPID para uma função de membro (uma propriedade ou um método, em uma interface ou dispinterface).|
|[range](../windows/range-cpp.md)|Especifica um intervalo de valores permitidos para argumentos ou campos cujos valores são definidos em tempo de execução.|
|[rdx](../windows/rdx.md)|Cria uma chave do registro ou modifica uma chave do registro existente.|
|[readonly](../windows/readonly-cpp.md)|Proíbe a atribuição a um membro de dados.|
|[requestedit](../windows/requestedit.md)|Indica que a propriedade oferece suporte a `OnRequestEdit` notificação.|

## <a name="see-also"></a>Consulte também

[Atributos por uso](../windows/attributes-by-usage.md)