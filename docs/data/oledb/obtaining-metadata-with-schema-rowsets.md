---
title: Obtendo metadados com conjuntos de linhas de esquema
ms.date: 10/24/2018
helpviewer_keywords:
- schema rowsets, getting OLE DB provider metadata
- OLE DB consumer templates, getting provider metadata
- metadata, getting (OLE DB Templates)
ms.assetid: 6b448461-82fb-4acf-816b-3cbb0ca1d186
ms.openlocfilehash: 12c3de79626411b76a402a7f5407f40a7b054318
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59025997"
---
# <a name="obtaining-metadata-with-schema-rowsets"></a>Obtendo metadados com conjuntos de linhas de esquema

Às vezes você precisa obter informações sobre o provedor, conjunto de linhas, tabela, colunas ou outras informações de banco de dados sem abrir o conjunto de linhas. Dados sobre a estrutura de banco de dados são chamados de metadados e podem ser recuperados por um número de métodos diferentes. Um método é usar conjuntos de linhas de esquema.

Modelos OLE DB fornecer um conjunto de classes para recuperar informações de esquema; Essas classes criar conjuntos de linhas do esquema predefinido e são listadas na [Classes de conjunto de linhas de esquema e Typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md).

> [!NOTE]
> Se você estiver usando o OLAP e alguns de seus conjuntos de linhas não são suportados pelas classes de conjunto de linhas de esquema (por exemplo, se você tiver um número variável de colunas), você deve considerar o uso `CManualAccessor` ou `CDynamicAccessor`. Você pode percorrer as colunas e usar instruções case para tratar os possíveis tipos de dados para cada coluna.

## <a name="catalogschema-model"></a>Modelo de esquema do catálogo

ANSI SQL define um modelo de esquema do catálogo para armazenamentos de dados; OLE DB usa esse modelo. Nesse modelo, os catálogos (bancos de dados) têm esquemas e esquemas têm tabelas.

- **Catálogo** um catálogo é outro nome de um banco de dados. É uma coleção de esquemas relacionadas. Para listar os catálogos (bancos de dados) que pertencem a uma determinada fonte de dados, use [CCatalog](../../data/oledb/ccatalogs-ccataloginfo.md). Como muitos bancos de dados têm apenas um catálogo, metadados é às vezes chamado de informações de esquema.

- **Esquema** um esquema é uma coleção de objetos de banco de dados que são de propriedade ou ter sido criado por um determinado usuário. Para listar os esquemas de propriedade de um determinado usuário, use [CSchemata](../../data/oledb/cschemata-cschematainfo.md).

   Em termos de Microsoft SQL Server e o ODBC 2. x, um esquema é um proprietário (por exemplo, dbo é um nome de esquema comum). Além disso, o SQL Server armazena metadados em um conjunto de tabelas: uma tabela contém uma lista de todas as tabelas e outra tabela contém uma lista de todas as colunas. Não há nenhum equivalente a um esquema em um banco de dados do Microsoft Access.

- **Tabela** tabelas são conjuntos de colunas organizados em pedidos específicos. Para listar as tabelas definidas em um determinado catálogo (banco de dados) e informações sobre essas tabelas, use [CTables](../../data/oledb/ctables-ctableinfo.md)).

## <a name="restrictions"></a>Restrições

Quando você consulta para obter informações de esquema, você pode usar restrições para especificar o tipo de informação no qual você está interessado. Você pode considerar restrições como um qualificador em uma consulta ou um filtro. Por exemplo, na consulta:

```sql
SELECT * FROM authors WHERE l_name = 'pivo'
```

`l_name` é uma restrição. Este é um exemplo simples com apenas uma restrição; as classes de conjunto de linhas de esquema dão suporte a várias restrições.

O [classes de typedef do conjunto de linhas de esquema](../../data/oledb/schema-rowset-classes-and-typedef-classes.md) encapsular todas as linhas do esquema de OLE DB para que você possa acessar um conjunto de linhas de esquema assim como qualquer outro conjunto de linhas instanciando e abri-lo. Por exemplo, a classe de typedef [CColumns](../../data/oledb/ccolumns-ccolumnsinfo.md) é definida como:

```cpp
CRestrictions<CAccessor<CColumnsInfo>
```

O [CRestrictions](../../data/oledb/crestrictions-class.md) classe fornece o suporte de restrição. Depois de criar uma instância do conjunto de linhas de esquema, chame [crestrictions:: Open](../../data/oledb/crestrictions-open.md). Esse método retorna um conjunto de resultados com base nas restrições que você especificar.

Para especificar restrições, consulte [apêndice b: Conjuntos de linhas de esquema](/previous-versions/windows/desktop/ms712921(v=vs.85)) e consultar o conjunto de linhas que você está usando. Por exemplo, `CColumns` corresponde do [conjunto de linhas COLUMNS](/previous-versions/windows/desktop/ms723052(v=vs.85)); esse tópico lista as colunas de restrição no conjunto de linhas de colunas: TABLE_CATALOG, TABLE_SCHEMA, TABLE_NAME, COLUMN_NAME. Você deve seguir nessa ordem no especificando suas restrições.

Portanto, por exemplo, se você quiser restringir por nome de tabela, TABLE_NAME é a terceira coluna de restrição e, em seguida, chame `Open`, especificando o nome da tabela desejada como o terceiro parâmetro de restrição, conforme mostrado no exemplo a seguir.

### <a name="to-use-schema-rowsets"></a>Para usar conjuntos de linhas de esquema

1. Incluir o arquivo de cabeçalho `Atldbsch.h` (você precisa `Atldbcli.h` para suporte de consumidor).

1. Criar uma instância de um objeto de conjunto de linhas de esquema do consumidor ou do documento arquivo de cabeçalho. Se você quiser que as informações de tabela, declarar uma `CTables` objeto; se você quiser que as informações de coluna, declare um `CColumns` objeto. Este exemplo mostra como recuperar as colunas na tabela de autores:

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

1. Para buscar as informações, acessar o membro de dados apropriado do objeto de conjunto de linhas de esquema, por exemplo, `ColumnSchemaRowset.m_szColumnName`. Este membro de dados corresponde ao nome da coluna. Para ver qual coluna de banco de dados OLE, cada membro de dados corresponde ao, consulte [CColumns](../../data/oledb/ccolumns-ccolumnsinfo.md).

Para a referência do conjunto de linhas de esquema, classes typedef fornecida nos modelos do OLE DB (consulte [Classes de conjunto de linhas de esquema e Typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md)).

Para obter mais informações sobre conjuntos de linhas de esquema de OLE DB, incluindo colunas de restrição, consulte [apêndice b: Conjuntos de linhas de esquema](/previous-versions/windows/desktop/ms712921(v=vs.85)) no **referência do programador do OLE DB**.

Para obter exemplos mais complexos de como usar classes rowset do esquema, consulte o [CatDB](https://github.com/Microsoft/VCSamples) e [DBViewer](https://github.com/Microsoft/VCSamples) exemplos.

Para obter informações sobre o suporte do provedor de conjuntos de linhas de esquema, consulte [que dão suporte a conjuntos de linhas de esquema](../../data/oledb/supporting-schema-rowsets.md).

## <a name="see-also"></a>Consulte também

[Usando acessadores](../../data/oledb/using-accessors.md)