---
title: Obtendo metadados com conjuntos de linhas de esquema
ms.date: 10/24/2018
helpviewer_keywords:
- schema rowsets, getting OLE DB provider metadata
- OLE DB consumer templates, getting provider metadata
- metadata, getting (OLE DB Templates)
ms.assetid: 6b448461-82fb-4acf-816b-3cbb0ca1d186
ms.openlocfilehash: 37418cc91913ed840d1601aab9005b476bf29ee0
ms.sourcegitcommit: a1676bf6caae05ecd698f26ed80c08828722b237
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/29/2020
ms.locfileid: "91508981"
---
# <a name="obtaining-metadata-with-schema-rowsets"></a>Obtendo metadados com conjuntos de linhas de esquema

Às vezes, você precisa obter informações sobre o provedor, conjunto de linhas, tabela, colunas ou outras informações do banco de dados sem abrir o conjunto de linhas. Os dados sobre a estrutura do banco de dado são chamados de metadados e podem ser recuperados por vários métodos diferentes. Um método é usar conjuntos de linhas de esquema.

Os modelos de OLE DB fornecem um conjunto de classes para recuperar informações de esquema; Essas classes criam conjuntos de linhas de esquema predefinidos e são listadas em classes de conjunto de itens de [esquema e classes de typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md).

> [!NOTE]
> Se você estiver usando o OLAP e alguns dos seus conjuntos de linhas não forem suportados pelas classes de conjunto de colunas de esquema (por exemplo, você tem um número variável), considere usar `CManualAccessor` ou `CDynamicAccessor` . Você pode percorrer as colunas e as instruções Case de uso para manipular os possíveis tipos de dados para cada coluna.

## <a name="catalogschema-model"></a>Modelo de catálogo/esquema

O ANSI SQL define um modelo de catálogo/esquema para armazenamentos de dados; OLE DB usa esse modelo. Nesse modelo, os catálogos (bancos de dados) têm esquemas e esquemas têm tabelas.

- **Catálogo** Um catálogo é outro nome para um banco de dados. É uma coleção de esquemas relacionados. Para listar os catálogos (bancos de dados) que pertencem a uma determinada fonte, use [CCatalog](./schema-rowset-classes-and-typedef-classes.md#catalog). Como muitos bancos de dados têm apenas um catálogo, os metadados às vezes são chamados de informações de esquema.

- **Esquema** do Um esquema é uma coleção de objetos de banco de dados que são de propriedade ou que foram criados por um usuário específico. Para listar os esquemas de propriedade de um determinado usuário, use [CSchemata](./schema-rowset-classes-and-typedef-classes.md#schemata).

   Nos termos Microsoft SQL Server e ODBC 2. x, um esquema é um proprietário (por exemplo, dbo é um nome de esquema típico). Além disso, SQL Server armazena metadados em um conjunto de tabelas: uma tabela contém uma lista de todas as tabelas e outra tabela contém uma lista de todas as colunas. Não há equivalente a um esquema em um banco de dados do Microsoft Access.

- **Tabela** As tabelas são coleções de colunas organizadas em ordens específicas. Para listar as tabelas definidas em um determinado catálogo (banco de dados) e informações sobre essas tabelas, use [CTables](./schema-rowset-classes-and-typedef-classes.md#table)).

## <a name="restrictions"></a>Restrições

Ao consultar informações de esquema, você pode usar restrições para especificar o tipo de informações em que está interessado. Você pode considerar as restrições como um filtro ou qualificador em uma consulta. Por exemplo, na consulta:

```sql
SELECT * FROM authors WHERE l_name = 'pivo'
```

`l_name` é uma restrição. Este é um exemplo simples com apenas uma restrição; as classes de conjunto de linhas de esquema dão suporte a várias restrições.

As [classes de typedef do conjunto de linhas de esquema](../../data/oledb/schema-rowset-classes-and-typedef-classes.md) encapsulam todos os conjuntos de itens de esquema de OLE DB para que você possa acessar um conjunto de linhas de esquema, assim como qualquer outro conjunto de linhas, instanciando e abrindo-o. Por exemplo, a classe typedef [CColumns](./schema-rowset-classes-and-typedef-classes.md#columns) é definida como:

```cpp
CRestrictions<CAccessor<CColumnsInfo>
```

A classe [cRestrictions](../../data/oledb/crestrictions-class.md) fornece o suporte de restrição. Depois de criar uma instância do conjunto de linhas de esquema, chame [CRestrictions:: Open](./crestrictions-class.md#open). Esse método retorna um conjunto de resultados com base nas restrições que você especificar.

Para especificar restrições, consulte o [Apêndice B: conjuntos](/previous-versions/windows/desktop/ms712921(v=vs.85)) de linhas de esquema e pesquise o conjunto de itens que você está usando. Por exemplo, `CColumns` corresponde ao [conjunto de linhas de colunas](/previous-versions/windows/desktop/ms723052(v=vs.85)); esse tópico lista as colunas de restrição no conjunto de linhas de colunas: TABLE_CATALOG, TABLE_SCHEMA, TABLE_NAME column_name. Você deve seguir essa ordem na especificação de suas restrições.

Portanto, por exemplo, se você quiser restringir pelo nome da tabela, TABLE_NAME será a terceira coluna de restrição e, em seguida, chamará `Open` , especificando o nome da tabela desejada como o terceiro parâmetro de restrição, conforme mostrado no exemplo a seguir.

### <a name="to-use-schema-rowsets"></a>Para usar conjuntos de linhas de esquema

1. Inclua o arquivo de cabeçalho `Atldbsch.h` (você `Atldbcli.h` também precisa do suporte ao consumidor).

1. Crie uma instância de um objeto de conjunto de linhas de esquema no arquivo de cabeçalho do consumidor ou do documento. Se você quiser informações de tabela, declare um `CTables` objeto; se desejar informações de coluna, declare um `CColumns` objeto. Este exemplo mostra como recuperar as colunas na tabela autores:

    ```cpp
    CDataSource ds;
    ds.Open();
    CSession ss;
    ss.Open(ds);
    CColumns columnSchemaRowset;
    // TABLE_NAME is the third restriction column, so
    // specify "authors" as the third restriction parameter:
    HRESULT hr = columnSchemaRowset.Open(ss, NULL, NULL, L"authors");
    hr = columnSchemaRowset.MoveFirst();
    while (hr == S_OK)
    {
       hr = columnSchemaRowset.MoveNext();
    }
    ```

1. Para buscar as informações, acesse o membro de dados apropriado do objeto conjunto de linhas de esquema, por exemplo, `ColumnSchemaRowset.m_szColumnName` . Este membro de dados corresponde a COLUMN_NAME. Para ver a qual OLE DB coluna cada membro de dados corresponde, consulte [CColumns](./schema-rowset-classes-and-typedef-classes.md#columns).

Para a referência do conjunto de linhas de esquema, classes de typedef fornecidas nos modelos de OLE DB (consulte [classes de conjunto de linhas de esquema e classes de typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md)).

Para obter mais informações sobre conjuntos de linhas de esquema OLE DB, incluindo colunas de restrição, consulte o [Apêndice B: conjuntos](/previous-versions/windows/desktop/ms712921(v=vs.85)) de itens de esquema na **referência do programador de OLE DB**.

Para obter exemplos mais complexos de como usar classes de conjunto de linhas de esquema, consulte os exemplos de [CatDB](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Consumer) e [DBViewer](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/ATL/OLEDB/Consumer) .

Para obter informações sobre o suporte do provedor para conjuntos de linhas de esquema, consulte [dando suporte a conjuntos](../../data/oledb/supporting-schema-rowsets.md)de linhas de esquema.

## <a name="see-also"></a>Consulte também

[Usando acessadores](../../data/oledb/using-accessors.md)
