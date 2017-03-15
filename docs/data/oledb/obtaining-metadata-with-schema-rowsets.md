---
title: "Obtendo metadados com conjuntos de linhas de esquema | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "metadados, obtendo (Modelos OLE DB)"
  - "Modelos de consumidor OLE DB, obtendo metadados de provedor"
  - "conjuntos de linhas do esquema, obtendo metadados de provedor OLE DB"
ms.assetid: 6b448461-82fb-4acf-816b-3cbb0ca1d186
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Obtendo metadados com conjuntos de linhas de esquema
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Às vezes você precisa obter informações sobre o provedor, linhas, tabela, colunas ou outras informações do banco de dados sem abrir o conjunto de linhas.  Dados sobre a estrutura de banco de dados são chamados de metadados e podem ser recuperados por um número de métodos diferentes.  Um método é usar conjuntos de linhas do esquema.  
  
 Modelos OLE DB fornecem um conjunto de classes para recuperar informações de esquema. Essas classes criar conjuntos de linhas de esquema predefinido e são listadas na [Classes de conjunto de linhas de esquema e Typedef](../Topic/Schema%20Rowset%20Classes%20and%20Typedef%20Classes.md).  
  
> [!NOTE]
>  Se você estiver usando o OLAP e alguns de seus conjuntos de linhas não são suportados pelas classes de conjunto de linhas de esquema \(por exemplo, se você tiver um número variável de colunas\), você deve considerar o uso `CManualAccessor` ou `CDynamicAccessor`.  Você pode percorrer as colunas e use instruções case para tratar os possíveis tipos de dados para cada coluna.  
  
## Modelo de esquema do catálogo  
 ANSI SQL define um modelo de esquema do catálogo para armazenamentos de dados; OLE DB usa esse modelo.  Nesse modelo, catálogos \(bancos de dados\) contêm esquemas e esquemas contêm tabelas.  
  
-   **Catálogo** um catálogo é outro nome de um banco de dados.  É uma coleção de esquemas relacionadas.  Para listar os catálogos \(bancos de dados\) que pertencem a uma determinada fonte de dados, use [CCatalog](../../data/oledb/ccatalogs-ccataloginfo.md).  Como muitos bancos de dados têm apenas um catálogo, metadados é chamado às vezes, apenas informações de esquema.  
  
-   **Esquema** um esquema é uma coleção de objetos de banco de dados que são de propriedade ou que foram criadas por um usuário específico.  Para listar os esquemas de propriedade de um determinado usuário, use [CSchemata](../../data/oledb/cschemata-cschematainfo.md).  
  
     Em termos de Microsoft SQL Server e o ODBC 2. x, um esquema é um proprietário \(por exemplo, dbo é um nome comum de esquema\).  Além disso, o SQL Server armazena metadados em um conjunto de tabelas: uma tabela contém uma lista de todas as tabelas e outra tabela contém uma lista de todas as colunas.  Não há nenhum equivalente a um esquema em um banco de dados do Microsoft Access.  
  
-   **Tabela** tabelas são conjuntos de colunas organizadas em pedidos específicos.  Para listar as tabelas definidas em um determinado catálogo \(banco de dados\) e obter informações sobre essas tabelas, use [CTables](../../data/oledb/ctables-ctableinfo.md)\).  
  
## Restrições  
 Quando você consulta para obter informações de esquema, você pode usar restrições para especificar o tipo de informação no qual você está interessado.  Você pode pensar restrições como um filtro ou qualificador em uma consulta.  Por exemplo, na consulta:  
  
```  
SELECT * FROM authors where l_name = 'pivo'  
```  
  
 `l_name` é uma restrição.  Este é um exemplo muito simple, com apenas uma restrição; as classes de conjunto de linhas de esquema oferecem suporte a várias restrições.  
  
 O [classes de typedef de conjunto de linhas de esquema](../Topic/Schema%20Rowset%20Classes%20and%20Typedef%20Classes.md) encapsular todos os conjuntos de linhas da esquema de banco de dados OLE para que você possa acessar um conjunto de linhas de esquema como qualquer outro conjunto de linhas instanciando e abri\-lo.  Por exemplo, a classe typedef [CColumns](../../data/oledb/ccolumns-ccolumnsinfo.md) é definido como:  
  
```  
CRestrictions<CAccessor<CColumnsInfo>  
```  
  
 O [CRestrictions](../Topic/CRestrictions%20Class.md) classe fornece o suporte de restrição.  Depois de criar uma instância do conjunto de linhas de esquema, chamada [crestrictions:: Open](../../data/oledb/crestrictions-open.md).  Este método retorna um conjunto de resultados com base nas restrições que você especificar.  
  
 Para especificar restrições, consulte [conjuntos de linhas do esquema do apêndice b:](http://go.microsoft.com/fwlink/?LinkId=64681) e consultar o conjunto de linhas que você está usando.  Por exemplo, **CColumns** corresponde do [conjunto de linhas COLUMNS](http://go.microsoft.com/fwlink/?LinkId=64682); Esse tópico lista as colunas de restrição no conjunto de linhas COLUMNS: TABLE\_CATALOG, TABLE\_SCHEMA, TABLE\_NAME, COLUMN\_NAME.  Você deve seguir a ordem para especificar as restrições.  
  
 Assim, por exemplo, se você quiser restringir o nome da tabela, observe que TABLE\_NAME é a terceira coluna de restrição e, em seguida, chame **Abrir**, especificando o nome da tabela desejada como o terceiro parâmetro de restrição, conforme mostrado no exemplo a seguir.  
  
#### Usar conjuntos de linhas de esquema  
  
1.  Você deve incluir o arquivo de cabeçalho Atldbsch.h \(é claro, você precisa Atldbcli.h para suporte de consumidor\).  
  
2.  Criar uma instância de um objeto de conjunto de linhas do esquema do cliente ou do documento arquivo de cabeçalho.  Se desejar obter informações de tabela, declarar uma **CTables** objeto; se você quiser obter informações de coluna, declarar uma **CColumns** objeto.  Este exemplo mostra como recuperar as colunas na tabela de autores:  
  
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
  
3.  Para buscar as informações, acessar o membro de dados apropriado do objeto de conjunto de linhas de esquema, por exemplo, `ColumnSchemaRowset.m_szColumnName`.  Isso corresponde ao nome da coluna.  Para ver cada membro de dados corresponde à coluna OLE DB, consulte [CColumns](../../data/oledb/ccolumns-ccolumnsinfo.md).  
  
 Para a referência do conjunto de linhas de esquema, classes typedef fornecidos nos modelos OLE DB \(consulte [Classes de conjunto de linhas de esquema e Typedef](../Topic/Schema%20Rowset%20Classes%20and%20Typedef%20Classes.md)\).  
  
 Para obter mais informações sobre conjuntos de linhas de esquema de OLE DB, incluindo colunas de restrição, consulte [conjuntos de linhas do esquema do apêndice b:](http://go.microsoft.com/fwlink/?LinkId=64681) na referência do OLE DB do programador.  
  
 Para obter exemplos mais complexos de como usar classes rowset do esquema, consulte o [CatDB](http://msdn.microsoft.com/pt-br/003d516b-2bf6-444e-8be5-4ebaa0b66046) e [DBViewer](http://msdn.microsoft.com/pt-br/07620f99-c347-4d09-9ebc-2459e8049832) exemplos.  
  
 Para obter informações sobre o suporte do provedor de conjuntos de linhas de esquema, consulte [suporte a conjuntos de linhas de esquema](../../data/oledb/supporting-schema-rowsets.md).  
  
## Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)