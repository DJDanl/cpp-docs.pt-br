---
title: Comandos e tabelas
ms.date: 11/19/2018
helpviewer_keywords:
- OLE DB consumer templates, table support
- CCommand class, OLE DB consumer templates
- commands [C++], OLE DB Consumer Templates
- CTable class
- CAccessorRowset class, command and table classes
- rowsets, accessing
- tables [C++], OLE DB Consumer Templates
- OLE DB consumer templates, command support
ms.assetid: 4bd3787b-6d26-40a9-be0c-083080537c12
ms.openlocfilehash: b2cdf7a2b439af3a564f5801e015f6064fb141dc
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59041410"
---
# <a name="commands-and-tables"></a>Comandos e tabelas

Comandos e tabelas permitem acessar conjuntos de linhas; ou seja, abra a conjuntos de linhas, executar comandos e associar colunas. O [CCommand](../../data/oledb/ccommand-class.md) e [CTable](../../data/oledb/ctable-class.md) classes instancia os objetos de comando e tabela, respectivamente. Essas classes derivam [CAccessorRowset](../../data/oledb/caccessorrowset-class.md) conforme mostrado na figura a seguir.

![CCommand e CTable](../../data/oledb/media/vccommandstables.gif "CCommand e CTable")<br/>
Comando e as Classes Table

Na tabela anterior, `TAccessor` pode ser qualquer tipo de acessador listado na [tipos de acessador](../../data/oledb/accessors-and-rowsets.md). `TRowset` pode ser qualquer tipo de conjunto de linhas listado na [tipos de conjunto de linhas](../../data/oledb/accessors-and-rowsets.md). `TMultiple` Especifica o tipo de resultado (um único ou vários conjunto de resultados).

O [ATL OLE DB Assistente de consumidor](../../atl/reference/atl-ole-db-consumer-wizard.md) permite que você especifique se deseja que um objeto de comando ou tabela.

- Para fontes de dados sem comandos, você pode usar o `CTable` classe. Geralmente, usá-lo para conjuntos de linhas simples que não especificam outros parâmetros e não exigem nenhuma vários resultados. Essa classe simple abre uma tabela em uma fonte de dados usando um nome de tabela que você especificar.

- Para fontes de dados que dão suporte a comandos, você pode usar o `CCommand` classe em vez disso. Para executar um comando, chame [abrir](../../data/oledb/ccommand-open.md) nessa classe. Como alternativa, você pode chamar `Prepare` para preparar um comando que você deseja executar mais de uma vez.

   `CCommand` tem três argumentos de modelo: um tipo de acessador, um tipo de conjunto de linhas e um tipo de resultado (`CNoMultipleResults`, por padrão, ou `CMultipleResults`). Se você especificar `CMultipleResults`, o `CCommand` classe oferece suporte a `IMultipleResults` de interface e lida com vários conjuntos de linhas. O [DBVIEWER](https://github.com/Microsoft/VCSamples) exemplo mostra como lidar com vários resultados.

## <a name="see-also"></a>Consulte também

[Modelos de consumidor de banco de dados OLE](../../data/oledb/ole-db-consumer-templates-cpp.md)