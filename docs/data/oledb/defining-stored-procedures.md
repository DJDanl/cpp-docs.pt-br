---
title: Definindo procedimentos armazenados
ms.date: 10/24/2018
helpviewer_keywords:
- stored procedures, syntax
- OLE DB, stored procedures
- stored procedures, defining
- stored procedures, OLE DB
ms.assetid: 54949b81-3275-4dd9-96e4-3eda1ed755f2
ms.openlocfilehash: 47f68bcf5c62aa54cc5ee60de166e1085f5a3fc5
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91500934"
---
# <a name="defining-stored-procedures"></a>Definindo procedimentos armazenados

Antes de chamar um procedimento armazenado, você deve primeiro defini-lo, usando a macro [DEFINE_COMMAND](./macros-and-global-functions-for-ole-db-consumer-templates.md#define_command) . Quando você define o comando, denota os parâmetros com um ponto de interrogação (?) como o marcador de parâmetro:

```cpp
DEFINE_COMMAND_EX(CMySProcAccessor, _T("{INSERT {name, phone} INTO shippers (?,?)}"))
```

A sintaxe (o uso de chaves e assim por diante) usada nos exemplos de código neste tópico é específica para SQL Server. A sintaxe que você usa em seus procedimentos armazenados pode variar de acordo com o provedor usado.

Em seguida, no mapa de parâmetros, especifique os parâmetros que você usou no comando, listando os parâmetros na ordem em que eles ocorrem no comando:

```cpp
BEGIN_PARAM_MAP(CMySProcAccessor)
   SET_PARAM_TYPE(DBPARAMIO_INPUT)
   COLUMN_ENTRY(1, m_Name)   // name corresponds to first '?' param
   SET_PARAM_TYPE(DBPARAMIO_INPUT)
   COLUMN_ENTRY(2, m_Phone)  // phone corresponds to second '?' param
END_PARAM_MAP()
```

O exemplo anterior define um procedimento armazenado como ele vai. Normalmente, para uma reutilização eficiente de código, um banco de dados contém um conjunto de procedimentos armazenados predefinidos com nomes como `Sales by Year` ou `dt_adduserobject` . Você pode exibir suas definições usando o Gerenciador de SQL Server Enterprise. Você os chama da seguinte maneira (o posicionamento do *?* os parâmetros dependem da interface do procedimento armazenado):

```cpp
DEFINE_COMMAND_EX(CMySProcAccessor, _T("{CALL \"Sales by Year\" (?,?) }"))
DEFINE_COMMAND_EX(CMySProcAccessor, _T("{CALL dbo.dt_adduserobject (?,?) }"))
```

Em seguida, declare a classe de comando:

```cpp
class CMySProc : public CCommand<CAccessor<CMySProcAccessor>>
```

Por fim, chame o procedimento armazenado no da `OpenRowset` seguinte maneira:

```cpp
CSession m_session;

HRESULT OpenRowset()
{
   return CCommand<CAccessor<CMySProcAccessor>>::Open(m_session);
}
```

Observe também que você pode definir um procedimento armazenado usando o atributo de banco de dados [db_command](../../windows/attributes/db-command.md) da seguinte maneira:

```cpp
db_command("{ ? = CALL dbo.dt_adduserobject }")
```

## <a name="see-also"></a>Consulte também

[Usando procedimentos armazenados](../../data/oledb/using-stored-procedures.md)
