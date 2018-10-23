---
title: Parâmetros de saída | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB, stored procedures
- stored procedures, calling
- stored procedures, parameters
- procedure calls
- procedure calls, stored procedures
ms.assetid: 4f7c2700-1c2d-42f3-8c9f-7e83962b2442
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 4a17ff7e6e78b21267b71ba495ba10a98e29cfe7
ms.sourcegitcommit: 0164af5615389ffb1452ccc432eb55f6dc931047
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/23/2018
ms.locfileid: "49808843"
---
# <a name="output-parameters"></a>Parâmetros de saída

Chamar um procedimento armazenado é semelhante à execução de um comando SQL. A principal diferença é que os procedimentos armazenados usam parâmetros de saída (ou "outparameters") e valores de retorno.

O seguinte procedimento armazenado, o primeiro '? 'é o valor de retorno (telefone) e o segundo'?' é o parâmetro de entrada (nome):

```  
DEFINE_COMMAND(CMySProcAccessor, _T("{ ? = SELECT phone FROM shippers WHERE name = ? }")  
```  

Especifique os parâmetros in e out no mapa de parâmetro:

```  
BEGIN_PARAM_MAP(CMySProcAccessor)  
   SET_PARAM_TYPE(DBPARAMIO_OUTPUT)  
   COLUMN_ENTRY(1, m_Phone)   // Phone is the return value
   SET_PARAM_TYPE(DBPARAMIO_INPUT)  
   COLUMN_ENTRY(2, m_Name)   // Name is the input parameter
END_PARAM_MAP()  
```  

Seu aplicativo deve tratar a saída retornada de procedimentos armazenados. Provedores OLE DB diferentes retornam parâmetros de saída e retornam valores em momentos diferentes durante o processamento do resultado. Por exemplo, o Microsoft OLE DB provider for SQL Server (SQLOLEDB) não fornecer parâmetros de saída e retornar códigos até depois que o consumidor tiver recuperado ou cancelado os conjuntos de resultados retornados pelo procedimento armazenado. A saída é retornada no último pacote TDS do servidor.

## <a name="row-count"></a>Contagem de linhas

Se você usar o OLE DB modelos de consumidor para executar um procedimento armazenado que tem outparameters, a contagem de linhas não é definida até que você feche o conjunto de linhas.

Por exemplo, considere um procedimento armazenado com um conjunto de linhas e um outparameter:

```sql
create procedure sp_test
   @_rowcount integer output
as
   select top 50 * from test
   @_rowcount = @@rowcount
return 0
```  

O \@_rowcount outparameter informa quantas linhas foram retornadas da tabela de teste. No entanto, esse procedimento armazenado limita o número de linhas como 50. Por exemplo, se houvesse 100 linhas no teste, o número de linhas seria 50 (porque esse código recupera apenas as primeiras 50 linhas). Se houver apenas 30 linhas na tabela, o número de linhas seria 30. Certifique-se de chamar `Close` ou `CloseAll` para preencher o outparameter antes de buscar o seu valor.

## <a name="see-also"></a>Consulte também

[Usando procedimentos armazenados](../../data/oledb/using-stored-procedures.md)