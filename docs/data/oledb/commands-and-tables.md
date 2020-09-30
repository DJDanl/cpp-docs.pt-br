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
ms.openlocfilehash: f65bd0f90832039d453d84ab9765781c30750318
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91507369"
---
# <a name="commands-and-tables"></a>Comandos e tabelas

Os comandos e as tabelas permitem acessar conjuntos de linhas; ou seja, abrir conjuntos de linhas, executar comandos e associar colunas. As classes [CCommand](../../data/oledb/ccommand-class.md) e [CTable](../../data/oledb/ctable-class.md) instanciam os objetos Command e Table, respectivamente. Essas classes derivam de [CAccessorRowset](../../data/oledb/caccessorrowset-class.md) , conforme mostrado na figura a seguir.

![CCommand e CTable](../../data/oledb/media/vccommandstables.gif "CCommand e CTable")<br/>
Classes de comando e de tabela

Na tabela anterior, `TAccessor` pode ser qualquer tipo de acessador listado em [tipos de acessadores](../../data/oledb/accessors-and-rowsets.md). `TRowset` pode ser qualquer tipo de conjunto de linhas listado em [tipos de conjunto de linhas](../../data/oledb/accessors-and-rowsets.md). `TMultiple` Especifica o tipo de resultado (um conjunto de resultados único ou múltiplo).

O [Assistente de consumidor do ATL OLE DB](../../atl/reference/atl-ole-db-consumer-wizard.md) permite que você especifique se deseja um comando ou objeto de tabela.

- Para fontes de dados sem comandos, você pode usar a `CTable` classe. Em geral, você o usa para conjuntos de linhas simples que não especificam parâmetros e não exigem vários resultados. Essa classe simples abre uma tabela em uma fonte de dados usando um nome de tabela que você especificar.

- Para fontes de dados que dão suporte a comandos, você pode usar a `CCommand` classe em vez disso. Para executar um comando, chame [Open](./ccommand-class.md#open) nessa classe. Como alternativa, você pode chamar `Prepare` para preparar um comando que você deseja executar mais de uma vez.

   `CCommand` tem três argumentos de template: um tipo de acessador, um tipo de conjunto de linhas e um tipo de resultado ( `CNoMultipleResults` por padrão, ou `CMultipleResults` ). Se você especificar `CMultipleResults` , a `CCommand` classe dará suporte à `IMultipleResults` interface e manipulará vários conjuntos de linhas. O exemplo de [DBViewer](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Consumer) mostra como lidar com os vários resultados.

## <a name="see-also"></a>Consulte também

[Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)
