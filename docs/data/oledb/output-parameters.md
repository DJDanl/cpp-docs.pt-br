---
title: Parâmetros de saída
ms.date: 10/24/2018
helpviewer_keywords:
- OLE DB, stored procedures
- stored procedures, calling
- stored procedures, parameters
- procedure calls
- procedure calls, stored procedures
ms.assetid: 4f7c2700-1c2d-42f3-8c9f-7e83962b2442
ms.openlocfilehash: ece626eb7fbecae9b90321ccc2569607897cf520
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80209853"
---
# <a name="output-parameters"></a>Parâmetros de saída

Chamar um procedimento armazenado é semelhante a executar um comando SQL. A principal diferença é que os procedimentos armazenados usam parâmetros de saída (ou "Parameters") e retornam valores.

No procedimento armazenado a seguir, o primeiro "?" é o valor de retorno (telefone) e o segundo "?" é o parâmetro de entrada (nome):

```cpp
DEFINE_COMMAND_EX(CMySProcAccessor, _T("{ ? = SELECT phone FROM shippers WHERE name = ? }"))
```

Você especifica os parâmetros in e out no mapa de parâmetros:

```cpp
BEGIN_PARAM_MAP(CMySProcAccessor)
   SET_PARAM_TYPE(DBPARAMIO_OUTPUT)
   COLUMN_ENTRY(1, m_Phone)   // Phone is the return value
   SET_PARAM_TYPE(DBPARAMIO_INPUT)
   COLUMN_ENTRY(2, m_Name)   // Name is the input parameter
END_PARAM_MAP()
```

Seu aplicativo deve manipular a saída retornada de procedimentos armazenados. Provedores do OLE DB diferentes retornam parâmetros de saída e valores de retorno em horários diferentes durante o processamento de resultados. Por exemplo, o provedor de OLE DB da Microsoft para SQL Server (SQLOLEDB) não fornece parâmetros de saída e códigos de retorno até que o consumidor tenha recuperado ou cancelado os conjuntos de resultados retornados pelo procedimento armazenado. A saída é retornada no último pacote TDS do servidor.

## <a name="row-count"></a>Contagem de Linhas

Se você usar os modelos de consumidor OLE DB para executar um procedimento armazenado que tem os parâmetros, a contagem de linhas não será definida até que você feche o conjunto de linhas.

Por exemplo, considere um procedimento armazenado com um conjunto de linhas e um outparameter:

```sql
create procedure sp_test
   @_rowcount integer output
as
   select top 50 * from test
   @_rowcount = @@rowcount
return 0
```

O `@_rowcount` outparameter relata quantas linhas foram retornadas da tabela de teste. No entanto, esse procedimento armazenado limita o número de linhas a 50. Por exemplo, se houver 100 linhas em teste, o número de linhas seria 50 (porque esse código recupera apenas as 50 linhas superiores). Se houver apenas 30 linhas na tabela, o número de linhas seria 30. Certifique-se de chamar `Close` ou `CloseAll` para popular o outparameter antes de buscar seu valor.

## <a name="see-also"></a>Confira também

[Usando procedimentos armazenados](../../data/oledb/using-stored-procedures.md)
