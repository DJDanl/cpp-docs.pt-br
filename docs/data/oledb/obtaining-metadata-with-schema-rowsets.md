---
title: Obtendo metadados com conjuntos de linhas de esquema | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- schema rowsets, getting OLE DB provider metadata
- OLE DB consumer templates, getting provider metadata
- metadata, getting (OLE DB Templates)
ms.assetid: 6b448461-82fb-4acf-816b-3cbb0ca1d186
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: da5a715be2ac6dc94ace25ee98781d2e9a4c5f8e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="obtaining-metadata-with-schema-rowsets"></a>Obtendo metadados com conjuntos de linhas de esquema
Às vezes você precisa obter informações sobre o provedor, conjunto de linhas, tabela, colunas ou outras informações do banco de dados sem abrir o conjunto de linhas. Dados sobre a estrutura de banco de dados são chamados de metadados e podem ser recuperados por um número de métodos diferentes. Um método é usar conjuntos de linhas de esquema.  
  
 Modelos OLE DB fornecer um conjunto de classes para recuperar informações de esquema. Essas classes criar conjuntos de linhas de esquema predefinido e são listadas na [Classes de conjunto de linhas de esquema e Typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md).  
  
> [!NOTE]
>  Se você estiver usando o OLAP e alguns de seus conjuntos de linhas não são suportados pelas classes de conjunto de linhas de esquema (por exemplo, se você tiver um número variável de colunas), considere o uso de `CManualAccessor` ou `CDynamicAccessor`. Você pode percorrer as colunas e use instruções case para tratar os possíveis tipos de dados para cada coluna.  
  
## <a name="catalogschema-model"></a>Modelo de esquema do catálogo  
 ANSI SQL define um modelo de esquema do catálogo para repositórios de dados; OLE DB usa esse modelo. Nesse modelo, os catálogos (bancos de dados) contêm os esquemas e os esquemas contêm tabelas.  
  
-   **Catálogo** um catálogo é outro nome de um banco de dados. É uma coleção de esquemas relacionadas. Para listar os catálogos (bancos de dados) que pertencem a uma determinada fonte de dados, use [CCatalog](../../data/oledb/ccatalogs-ccataloginfo.md). Como muitos bancos de dados têm apenas um catálogo, metadados, às vezes, simplesmente é chamado informações de esquema.  
  
-   **Esquema** um esquema é uma coleção de objetos de banco de dados que são de propriedade ou foram criadas por um usuário específico. Para listar os esquemas de propriedade de um determinado usuário, use [CSchemata](../../data/oledb/cschemata-cschematainfo.md).  
  
     Em termos de Microsoft SQL Server e ODBC 2. x, um esquema é um proprietário (por exemplo, dbo é um nome de esquema comuns). Além disso, o SQL Server armazena metadados em um conjunto de tabelas: uma tabela contém uma lista de todas as tabelas e outra tabela contém uma lista de todas as colunas. Não há nenhum equivalente a um esquema em um banco de dados do Microsoft Access.  
  
-   **Tabela** tabelas são conjuntos de colunas organizados em pedidos específicos. Para listar as tabelas definidas em um determinado catálogo (banco de dados) e informações sobre essas tabelas, use [CTables](../../data/oledb/ctables-ctableinfo.md)).  
  
## <a name="restrictions"></a>Restrições  
 Quando você consulta para obter informações de esquema, você pode usar restrições para especificar o tipo de informações que lhe interessam. Você pode pensar restrições como um filtro ou qualificador em uma consulta. Por exemplo, na consulta:  
  
```  
SELECT * FROM authors where l_name = 'pivo'  
```  
  
 `l_name` é uma restrição. Este é um exemplo muito simple, com apenas uma restrição; as classes de conjunto de linhas de esquema oferecem suporte a várias restrições.  
  
 O [classes de typedef de conjunto de linhas de esquema](../../data/oledb/schema-rowset-classes-and-typedef-classes.md) encapsular todas as linhas do esquema de banco de dados OLE para que você pode acessar um conjunto de linhas de esquema assim como qualquer outro conjunto de linhas, criando e abri-lo. Por exemplo, a classe typedef [CColumns](../../data/oledb/ccolumns-ccolumnsinfo.md) é definido como:  
  
```  
CRestrictions<CAccessor<CColumnsInfo>  
```  
  
 O [CRestrictions](../../data/oledb/crestrictions-class.md) classe fornece o suporte de restrição. Depois de criar uma instância do conjunto de linhas de esquema, chamada [crestrictions:: Open](../../data/oledb/crestrictions-open.md). Esse método retorna um conjunto de resultados com base nas restrições que você especificar.  
  
 Para especificar restrições, consulte [apêndice b: Schema Rowsets](http://go.microsoft.com/fwlink/p/?linkid=64681) e consultar o conjunto de linhas que você está usando. Por exemplo, **CColumns** corresponde do [conjunto de linhas COLUMNS](http://go.microsoft.com/fwlink/p/?linkid=64682); esse tópico lista as colunas de restrição no conjunto de linhas de colunas: TABLE_CATALOG, TABLE_SCHEMA, TABLE_NAME, COLUMN_NAME. Você deve seguir a ordem para especificar as restrições.  
  
 Assim, por exemplo, se você quiser restringir o nome da tabela, observe que TABLE_NAME é a terceira coluna de restrição e, em seguida, chamar **abrir**, especificando o nome da tabela desejado como o terceiro parâmetro de restrição, conforme mostrado no exemplo a seguir.  
  
#### <a name="to-use-schema-rowsets"></a>Para usar conjuntos de linhas de esquema  
  
1.  Você deve incluir o arquivo de cabeçalho Atldbsch.h (naturalmente, você precisa Atldbcli.h para suporte de consumidor também).  
  
2.  Criar uma instância de um objeto de conjunto de linhas de esquema do cliente ou o documento arquivo de cabeçalho. Se você quiser informações de tabela, declarar uma **CTables** objeto; se você quiser informações de coluna, declare um **CColumns** objeto. Este exemplo mostra como recuperar as colunas na tabela de autores:  
  
    ```  
    CDataSource ds;  
    ds.Open();  
    CSession ss;  
    ss.Open();  
    CColumns ColumnSchemaRowset;  
    // TABLE_NAME is the third restriction column, so  
    // specify "authors" as the third restriction parameter:  
    hr = ColumnSchemaRowset.Open(ss, NULL, NULL, "authors");  
    hr = ColumnSchemaRowset.MoveFirst();  
    while (hr == S_OK)  
    {  
       hr = ColumnSchemaRowset.MoveNext();  
    }  
    ```  
  
3.  Para obter as informações, acessar o membro de dados apropriado do objeto de conjunto de linhas do esquema, por exemplo, `ColumnSchemaRowset.m_szColumnName`. Isso corresponde ao nome da coluna. Para ver qual coluna de OLE DB, cada membro de dados corresponde ao, consulte [CColumns](../../data/oledb/ccolumns-ccolumnsinfo.md).  
  
 Para a referência do conjunto de linhas de esquema, classes de typedef fornecidas nos modelos OLE DB (consulte [Classes de conjunto de linhas de esquema e Typedef](../../data/oledb/schema-rowset-classes-and-typedef-classes.md)).  
  
 Para obter mais informações sobre conjuntos de linhas de esquema de OLE DB, incluindo colunas de restrição, consulte [apêndice b: Schema Rowsets](http://go.microsoft.com/fwlink/p/?linkid=64681) na referência do OLE DB do programador.  
  
 Para obter exemplos mais complexos de como usar classes rowset do esquema, consulte o [CatDB](http://msdn.microsoft.com/en-us/003d516b-2bf6-444e-8be5-4ebaa0b66046) e [DBViewer](http://msdn.microsoft.com/en-us/07620f99-c347-4d09-9ebc-2459e8049832) exemplos.  
  
 Para obter informações sobre o suporte do provedor de conjuntos de linhas de esquema, consulte [dando suporte a conjuntos de linhas de esquema](../../data/oledb/supporting-schema-rowsets.md).  
  
## <a name="see-also"></a>Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)