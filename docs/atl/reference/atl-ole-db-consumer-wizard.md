---
title: "Assistente do consumidor do OLE DB ATL | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "vc.codewiz.class.atl.consumer.overview"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente do consumidor do OLE DB ATL"
  - "Projetos de ATL, adicionando os consumidores do OLE DB ATL"
  - "cadeias de conexão [C++], Os clientes do OLE DB"
ms.assetid: dcb68ed1-2224-422f-9f7b-108a74864204
caps.latest.revision: 13
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Assistente do consumidor do OLE DB ATL
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este assistente configura de uma classe de consumidor do OLE DB com associações de dados necessárias para acessar a fonte de dados especificada pelo provedor do OLE DB especificado.  
  
> [!NOTE]
>  Este assistente requer que você clique no botão de **Fonte de Dados** selecionar uma fonte de dados antes de inserir nomes em campos de `Class` e de **.h file** .  
  
## Lista UIElement  
 **Data Source**  
 O botão de **Fonte de Dados** permite que você configure a fonte de dados especificada usando o provedor OLE DB especificado.  Quando você clica no botão, a caixa de diálogo de **Propriedades de associação de dados** aparece.  Para obter mais informações sobre cadeias de conexão a compilação e da caixa de diálogo de **Propriedades de associação de dados** , consulte [Visão geral da API de link de dados](https://msdn.microsoft.com/en-us/library/ms718102.aspx) na documentação de [!INCLUDE[winsdkshort](../../atl/reference/includes/winsdkshort_md.md)] .  
  
> [!NOTE]
>  Em versões anteriores, SHIFT\- clique no botão de **Fonte de Dados** abrir uma caixa de diálogo abrir Arquivo para permitir que você selecione um arquivo de data link \(.udl\).  Essa funcionalidade não são mais suportadas.  
  
 a caixa de diálogo tem quatro guias:  
  
-   Guia de**Provedor**  
  
-   Guia de**Conexão**  
  
-   Guia de**Avançado**  
  
-   Guia de**Todos**  
  
     As seguintes informações adicionais descreve as guias na caixa de diálogo de **Propriedades de associação de dados** .  
  
     Clique **OK** para concluir.  a caixa de diálogo de **Selecionar Objeto do Banco de Dados** aparece.  Esta caixa de diálogo, selecione a tabela, a exibição, ou procedimento armazenado que o consumidor usará.  
  
     **Provider**  
     Selecione um provedor apropriado para gerenciar a conexão com a fonte de dados.  O tipo de provedor normalmente é determinado pelo tipo de banco de dados que você está se conectando.  Clique no botão de `Next` ou clique na guia de **Conexão** .  
  
     **Conexão**  
     O conteúdo de este guia dependem do provedor que você selecionou.  Embora existam diversos tipos de provedores, conexões de esta seção aborda para os dois mais comum: Dados do SQL e ODBC.  As outras são variações semelhantes nos campos descritos aqui.  
  
     Para dados do SQL:  
  
    1.  Clique no menu de**Select or enter a server name:** da lista suspensa para exibir todos os servidores de dados registrados na rede, e selecionar um.  
  
    2.  **Enter information to log on to the server:** insere um nome de usuário e senha para efetuar logon no servidor de dados.  
  
    3.  Clique no menu de**Select the database on the server:** da lista suspensa para exibir todos os bancos de dados registrados no servidor de dados, e selecionar um.  
  
         \-  ou  \-  
  
         **Attach a database file as a database name:** especifica um arquivo a ser usado como o banco de dados; digite o nome de caminho específico.  
  
        > [!NOTE]
        >  Há um problema de segurança com “permite salvar o recurso de senha” da caixa de diálogo data link properties.  Em “insira as informações para fazer logon no servidor,” há dois botões de opção:  
  
         **Use Windows NT integrated security**  
  
         **Use a specific user name and password**  
  
         Se você selecionar **Usar nome de usuário e senha específicos**, você tem a opção de salvar a senha \(usando a caixa de seleção para “allow salvar a senha”\); no entanto, esta opção não é seguro.  É recomendável que você seleciona **Usar Segurança Integrada do Windows NT**; essa opção é seguro porque criptografe a senha.  
  
         Pode haver situações em que você deseja selecionar “reserva salvar a senha.” Por exemplo, se você estiver liberando uma biblioteca com uma solução particular do banco de dados, você não deve acessar o banco de dados diretamente mas usar um aplicativo de camada intermediária verifique se o usuário \(por meio o esquema de autenticação que você escolher\) e limitar no meio os dados disponíveis para o usuário.  
  
         Para dados ODBC:  
  
         1.  **Specify the source of data:** você pode usar um nome da fonte de dados ou uma cadeia de conexão.  
  
         **Use data source name:** esta lista suspensa exibe fontes de dados registradas no seu computador.  Você pode configurar as fontes de dados de maneira que usam [ODBC Data Source Administrator](!Alink("dasdkODBCDataSourceAdmin")). \- ou**Usar cadeia de conexão:** inserir uma cadeia de conexão que você já tiver obtido, ou clique no botão de **Compilar** ; a caixa de diálogo de **Selecionar fonte de dados** aparece.  Selecione uma fonte de dados de arquivo ou do computador e clique **OK**.  
  
        > [!NOTE]
        >  Você pode obter uma cadeia de conexão exibindo as propriedades de uma conexão existente no server Explorer, ou você pode criar uma conexão clicando duas vezes **Adicionar Conexão** no server Explorer.  
  
         2.  **Enter information to log on to the server:** insere um nome de usuário e senha para efetuar logon no servidor de dados.  
  
         3.  Insira o catálogo inicial para usar.  
  
         4.  Clique **Testar conexão**; se o teste tiver êxito, clique **OK**.  Caso contrário, verifique suas informações de logon, tente outro banco de dados, ou tente outro servidor de dados.  
  
     **Avançado**  
     **Network settings:** especifica [Impersonation level](!Alink("_com_Impersonation_Levels")) \(o nível de representação que é permitido para o servidor usar para representar o cliente; corresponde diretamente aos níveis de representação de RPC\) e o **Nível de proteção** \(o nível de proteção de dados enviados entre o cliente e o servidor; corresponde diretamente aos níveis de proteção de RPC\).  
  
     **Other:** em **Tempo Limite de Conexão**, especifica o número de segundos de tempo ocioso reservados antes que um tempo limite ocorra.  Em **Permissões de acesso**, especifique as permissões de acesso na conexão de dados.  
  
     Para obter mais informações sobre propriedades de inicialização avançadas, consulte a documentação fornecida com cada provedor do OLE DB específico.  
  
     **Todos**  
     Este guia exibe um resumo das propriedades de inicialização para a fonte de dados e a conexão que você especificou.  Você pode editar esses valores.  
  
     Clique **OK** para concluir.  a caixa de diálogo de **Selecionar Objeto do Banco de Dados** aparece.  Esta caixa de diálogo, selecione a tabela, a exibição, ou procedimento armazenado que o consumidor usará.  
  
 `Class`  
 Depois que você selecionar uma fonte de dados, essa caixa é preenchida com um nome de classe padrão baseado na tabela ou o procedimento armazenado selecionado \(consulte **Selecione uma fonte de dados** abaixo\).  Você pode editar o nome da classe.  
  
 **.h file**  
 Depois que você selecionar uma fonte de dados, essa caixa é preenchida com um nome de classe padrão de cabeçalho baseado na tabela ou o procedimento armazenado selecionado \(consulte **Selecione uma fonte de dados** abaixo\).  Você pode editar o nome de arquivo de cabeçalho ou selecione um arquivo de cabeçalho existente.  
  
 **Attributed**  
 Esta opção especifica se o assistente criará classes do consumidor usando atributos ou declarações de modelo.  Quando você seleciona essa opção, o assistente usa atributos em vez das declarações do modelo \(esta é a opção padrão\).  Quando você desmarca a opção, o assistente usa declarações de modelo em vez de atributos.  
  
-   Se você selecionar um consumidor **Tipo** da tabela, o assistente usa os atributos de `db_source` e de **db\_table** para criar as declarações da classe da tabela e do acessador da tabela, e usa **db\_column** para criar o mapa de coluna, por exemplo:  
  
    ```  
    // Inject table class and table accessor class declarations  
    [  
        db_source("<initialization_string>"),  
        db_table("dbo.Orders")  
    ]  
    ...  
    // Column map  
        [ db_column(1, status=m_dwOrderIDStatus,         length=m_dwOrderIDLength) ] LONG m_OrderID;  
        [ db_column(2, status=m_dwCustomerIDStatus,         length=m_dwCustomerIDLength) ] TCHAR m_CustomerID[6];  
        ...  
    ```  
  
     em vez de usar o modelo de `CTable` classe para declarar a classe de tabela e do acessador da tabela, e macros de BEGIN\_COLUMN\_MAP e de END\_COLUMN\_MAP para criar o mapa de coluna, por exemplo:  
  
    ```  
    // Table accessor class  
    class COrdersAccessor;  
    // Table class  
    class COrders : public CTable<CAccessor<COrdersAccessor> >;  
    ...  
    // Column map  
    BEGIN_COLUMN_MAP(COrderDetailsAccessor)  
        COLUMN_ENTRY_LENGTH_STATUS(1, m_OrderID,         m_dwOrderIDLength, m_dwOrderIDStatus)  
        COLUMN_ENTRY_LENGTH_STATUS(2, m_CustomerID,         m_dwCustomerIDLength, m_dwCustomerIDStatus)  
        ...  
    END_COLUMN_MAP()  
    ```  
  
-   Se você selecionar um consumidor **Tipo** de comando, o assistente usa os atributos de `db_source` e de **db\_command** , e usa **db\_column** para criar o mapa de coluna, por exemplo:  
  
    ```  
    [  
        db_source("<initialization_string>"),  
        db_command("SQL_command")  
    ]  
    ...  
    // Column map using db_column is the same as for consumer type of 'table'  
    ```  
  
     em vez de usar as declarações da classe de comando e acessadores de comando em .h as classes de comando arquivo, por exemplo:  
  
    ```  
    Command accessor class:  
    class CListOrdersAccessor;  
    Command class:  
    class CListOrders : public CCommand<CAccessor<CListOrdersAccessor> >;  
    ...  
    // Column map using BEGIN_COLUMN_MAP ... END_COLUMN_MAP is the same as  
    // for consumer type of 'table'  
    ```  
  
 Consulte [Basic Mechanics of Attributes](../../windows/basic-mechanics-of-attributes.md) para maiores informações.  
  
 **Tipo**  
 Selecione um de esses botões de opção para especificar se a classe do consumidor seja derivada de `CTable` ou de `CCommand` \(padrão\).  
  
 **Tabela**  
 Selecione esta opção se você deseja usar `CTable` ou **db\_table** para criar as declarações da classe da tabela e do acessador da tabela.  
  
 **Comando**  
 Selecione esta opção se você deseja usar `CCommand` ou **db\_command** para criar as declarações da classe de comando e acessadores de comando.  Esta é a seleção padrão.  
  
 **Suporte**  
 Marque as caixas de seleção para especificar os tipos das atualizações para ser suportados pelo consumidor \(a opção não é possível\).  Cada um dos seguintes [DBPROP\_IRowsetChange](https://msdn.microsoft.com/en-us/library/ms715892.aspx) irá definir e as entradas apropriadas para [DBPROP\_UPDATABILITY](https://msdn.microsoft.com/en-us/library/ms722676.aspx) no mapa set da propriedade.  
  
 **Alterar**  
 Especifica que as atualizações de suporte do consumidor de dados de linha em rowset.  
  
 **Inserir**  
 Especifica que a inserção de suporte do consumidor de linhas no rowset.  
  
 **Excluir**  
 Especifica que a exclusão de suporte do consumidor de linhas de rowset.  
  
## Consulte também  
 [Consumidor de ATL o OLE DB](../../atl/reference/adding-an-atl-ole-db-consumer.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Cadeias de conexão e vínculos de dados \(o OLE DB\)](https://msdn.microsoft.com/en-us/library/ms718376.aspx)