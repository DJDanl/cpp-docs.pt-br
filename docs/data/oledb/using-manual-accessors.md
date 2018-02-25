---
title: Usando acessadores manuais | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- command handling, OLE DB Templates
- manual accessors
- accessors [C++], manual
ms.assetid: 29f00a89-0240-482b-8413-4120b9644672
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: e7d6bd8f0228103e4899e6bc24f6d67af0f3fdb4
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="using-manual-accessors"></a>Usando acessadores manuais
Há quatro tarefas a serem realizadas ao manipular um comando desconhecido:  
  
-   Determinar os parâmetros  
  
-   Execute o comando  
  
-   Determinar as colunas de saída  
  
-   Verificar se há vários conjuntos de linhas de retorno  
  
 Para fazer isso com o OLE DB modelos de consumidor, use o `CManualAccessor` de classe e siga estas etapas:  
  
1.  Abra um `CCommand` do objeto com `CManualAccessor` como um parâmetro de modelo.  
  
    ```  
    CCommand<CManualAccessor, CRowset, CMultipleResults> rs;  
    ```  
  
2.  Consultar a sessão para o **IDBSchemaRowset** interface e usar o conjunto de linhas de parâmetros de procedimento. Se o **IDBSchemaRowset** interface não estiver disponível, consultar o `ICommandWithParameters` interface. Chamar `GetParameterInfo` para obter informações. Se nenhuma interface estiver disponível, você pode presumir que não existem parâmetros.  
  
3.  Para cada parâmetro, chame `AddParameterEntry` para adicionar os parâmetros e defini-las.  
  
4.  Abra o conjunto de linhas, mas definir o parâmetro de associação para **false**.  
  
5.  Chamar `GetColumnInfo` para recuperar as colunas de saída. Use `AddBindEntry` para adicionar a coluna de saída para a associação.  
  
6.  Chamar `GetNextResult` para determinar se mais conjuntos de linhas estão disponíveis. Repita as etapas 2 a 5.  
  
 Para obter um exemplo de um acessador manual, consulte **CDBListView::CallProcedure** no [DBVIEWER](http://msdn.microsoft.com/en-us/07620f99-c347-4d09-9ebc-2459e8049832) exemplo.  
  
## <a name="see-also"></a>Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)