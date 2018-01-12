---
title: Comandos e tabelas | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
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
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: c42422c156a51cac161f0cc75dfd1947b92eb20e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="commands-and-tables"></a>Comandos e tabelas
Comandos e tabelas permitem que você acesse conjuntos de linhas; ou seja, abrir conjuntos de linhas, executar comandos e associar colunas. O [CCommand](../../data/oledb/ccommand-class.md) e [CTable](../../data/oledb/ctable-class.md) classes instanciar os objetos de comando e tabela, respectivamente. Essas classes derivam [CAccessorRowset](../../data/oledb/caccessorrowset-class.md) conforme mostrado na figura a seguir.  
  
 ![CCommand e CTable](../../data/oledb/media/vccommandstables.gif "vccommandstables")  
Classes de tabela e de comando  
  
 Na tabela anterior, `TAccessor` pode ser qualquer tipo de acessador listado na [tipos de acessador](../../data/oledb/accessors-and-rowsets.md). *TRowset* pode ser qualquer tipo de conjunto de linhas listado na [tipos de conjunto de linhas](../../data/oledb/accessors-and-rowsets.md). *TMultiple* Especifica o tipo de resultado (um único ou vários do conjunto de resultados).  
  
 O [ATL OLE DB Assistente de consumidor](../../atl/reference/atl-ole-db-consumer-wizard.md) permite que você especifique se deseja que um objeto de comando ou uma tabela.  
  
-   Para fontes de dados sem comandos, você pode usar o `CTable` classe. Você geralmente usá-lo para conjuntos de linhas simples que não especificar nenhum parâmetro e não exigem nenhum vários resultados. Essa classe simple abre uma tabela em uma fonte de dados usando um nome de tabela que você especificar.  
  
-   Para fontes de dados que oferece suporte a comandos, você pode usar o `CCommand` classe em vez disso. Para executar um comando, chame [abrir](../../data/oledb/ccommand-open.md) nessa classe. Como alternativa, você pode chamar `Prepare` para preparar um comando que você deseja executar mais de uma vez.  
  
     **CCommand** tem três argumentos de modelo: um tipo de resultado de um tipo de acessador e um tipo de conjunto de linhas (`CNoMultipleResults`, por padrão, ou `CMultipleResults`). Se você especificar `CMultipleResults`, o `CCommand` classe oferece suporte a **IMultipleResults** de interface e gerencia vários conjuntos de linhas. O [DBVIEWER](http://msdn.microsoft.com/en-us/07620f99-c347-4d09-9ebc-2459e8049832) exemplo mostra como tratar vários resultados.  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de consumidor OLE DB](../../data/oledb/ole-db-consumer-templates-cpp.md)