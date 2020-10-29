---
title: Assistente de consumidor OLE DB da ATL
ms.date: 07/02/2019
helpviewer_keywords:
- ATL projects, adding ATL OLE DB consumers
ms.assetid: dcb68ed1-2224-422f-9f7b-108a74864204
ms.openlocfilehash: 490335f1f61987fc6e5b0b3806ee8e39c82f336f
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92923753"
---
# <a name="atl-ole-db-consumer-wizard"></a>Assistente de consumidor OLE DB da ATL

::: moniker range="msvc-160"

Esse assistente não está disponível no Visual Studio 2019 e versões posteriores.

::: moniker-end

::: moniker range="<=msvc-150"

Esse assistente configura uma classe de consumidor do OLE DB com as associações de dados necessárias para acessar a fonte de dados especificada por meio do provedor OLE DB especificado.

> [!NOTE]
> Esse assistente exige que você clique no botão **Fonte de Dados** para selecionar uma fonte de dados antes de inserir os nomes nos campos `Class` e **arquivo.h** .

## <a name="uielement-list"></a>Lista de elementos de interface do usuário

- **Fonte de Dados**

   O botão **Fonte de Dados** permite que você configure a fonte de dados especificada usando o provedor OLE DB especificado. Quando você clica nesse botão, a caixa de diálogo **Propriedades do Link de Dados** é exibida. Saiba mais sobre como criar cadeias de conexão e a caixa de diálogo **Propriedades do Link de Dados** em [Visão geral da API do link de dados](/previous-versions/windows/desktop/ms718102(v=vs.85)) na documentação de SDK do Windows.

   As informações adicionais a seguir descrevem as guias na caixa de diálogo **Propriedades do Link de Dados** .

  - Guia **Provedor**

      Selecione um provedor apropriado para gerenciar a conexão com a fonte de dados. O tipo do provedor normalmente é determinado pelo tipo de banco de dados ao qual você está se conectando. Clique no botão **Avançar** ou clique na guia **Conexão** .

  - Guia **conexão**

      O conteúdo dessa guia depende do provedor selecionado. Embora existam muitos tipos de provedores, esta seção aborda conexões para os dois dados mais comuns: SQL e ODBC. Os outros são variações semelhantes nos campos descritos aqui.

      Para dados do SQL:

      1. **Selecione ou insira um nome de servidor:** Clique no menu de lista suspensa para exibir todos os servidores de dados registrados na rede e selecione um.

      1. **Insira as informações para fazer logon no servidor:** Insira um nome de usuário e uma senha para fazer logon no servidor de dados.

         > [!NOTE]
         > Há um problema de segurança com o recurso "Permitir salvamento de senha" da caixa de diálogo Propriedades do Link de Dados. Em "Digite as informações para fazer logon no servidor", há dois botões de opção:
         >
         > - **Usar a segurança integrada do Windows NT**
         > - **Usar nome de usuário e senha específicos**
         >
         > Selecionando **Usar nome de usuário e senha específicos** , você terá a opção de salvar a senha (usando a caixa de seleção "Permitir salvamento de senha"). No entanto, essa opção não é segura. É recomendável selecionar **Usar segurança integrada do Windows NT** . Essa opção é segura porque criptografa a senha.
         > Pode haver situações em que você queira selecionar "Permitir salvamento de senha". Por exemplo, se estiver liberando uma biblioteca com uma solução de banco de dados particular, você não deverá acessar o banco de dados diretamente, mas em vez disso, usar um aplicativo de camada intermediária para verificar o usuário (por meio de qualquer esquema de autenticação escolhido) e, em seguida, limitar a classificação de dados disponível para o usuário.

      1. **Selecione o banco de dados no servidor:** Clique no menu de lista suspensa para exibir todos os bancos de dados registrados no servidor e selecione um.

         \- ou –

         **Anexar um arquivo de banco de dados como um nome de banco de dados:** Especifique um arquivo a ser usado como banco de dados; Insira o nome de caminho explícito.

      Para dados ODBC:

      1. **Especifique a fonte de dados:** Você pode usar um nome de fonte de dados ou uma cadeia de conexão.

         **Usar nome da fonte de dados:** Essa lista suspensa exibe as fontes de dados registradas em seu computador. Você pode configurar fontes de dados antecipadamente usando o Administrador de Fonte de Dados ODBC

         \- ou –

         **Usar cadeia de conexão:** Insira uma cadeia de conexão que você já obteve ou clique no botão **Compilar** ; a caixa de diálogo **selecionar fonte de dados** é exibida. Selecione uma fonte de dados de computador ou arquivo e clique em **OK** .

         > [!NOTE]
         > Você pode obter uma cadeia de conexão ao exibir as propriedades de uma conexão existente no **Gerenciador de Servidores** ou criar uma conexão clicando duas vezes em **Adicionar Conexão** no **Gerenciador de Servidores** .

      1. **Insira as informações para fazer logon no servidor:** Insira um nome de usuário e uma senha para fazer logon no servidor de dados.

      1. Insira o catálogo inicial a ser usado.

      1. Clique em **Testar Conexão** ; se o teste for bem-sucedido, clique em **OK** . Caso contrário, verifique suas informações de logon, tente outro banco de dados ou tente outro servidor de dados.

  - Guia **avançado**

      **Configurações de rede:** Especifique o **nível de representação** (o nível de representação que o servidor pode usar ao representar o cliente; corresponde diretamente aos níveis de representação RPC) e **nível de proteção** (o nível de proteção dos dados enviados entre o cliente e o servidor; corresponde diretamente aos níveis de proteção de RPC).

      **Outros:** Em **tempo limite de conexão** , especifique o número de segundos de tempo ocioso permitido antes que ocorra um tempo limite. Em **Permissões de acesso** , especifique as permissões de acesso na conexão de dados.

      Saiba mais sobre propriedades de inicialização avançadas na documentação fornecida com cada provedor OLE DB específico.

  - Guia **Todos**

      Essa guia exibe um resumo das propriedades de inicialização para a fonte de dados e a conexão que você especificou. Você pode editar esses valores.

      Clique em **OK** para concluir. A caixa de diálogo **Selecionar Objeto do Banco de Dados** é exibida. Nessa caixa de diálogo, selecione a tabela, a exibição ou o procedimento armazenado que o consumidor usará.

- **Classe**

   Depois de selecionar uma fonte de dados, essa caixa é preenchida com um nome de classe padrão com base na tabela ou no procedimento armazenado selecionado (confira **Selecionar uma fonte de dados** abaixo). É possível editar o nome da classe.

- **Arquivo .h**

   Depois de selecionar uma fonte de dados, essa caixa é preenchida com um nome de classe de cabeçalho padrão com base na tabela ou no procedimento armazenado selecionado (confira **Selecionar uma fonte de dados** abaixo). Você pode editar o nome do arquivo de cabeçalho ou selecionar um arquivo de cabeçalho existente.

- **Atribuído**

   Essa opção especifica se o assistente criará as classes de consumidor usando atributos ou declarações de modelo. Quando essa opção é selecionada, o assistente usa atributos em vez de declarações de modelo (essa é a opção padrão). Quando você desmarca essa opção, o assistente usa declarações de modelo em vez de atributos.

  - Se você selecionar um consumidor **Tipo** de **Tabela** , o assistente usará os atributos `db_source` e `db_table` para criar a tabela e as declarações de classe do acessador de tabela, assim como usará `db_column` para criar o mapa de coluna. Por exemplo, ele cria este mapa:

    ```cpp
    // Inject table class and table accessor class declarations
    [db_source("<initialization_string>"), db_table("dbo.Orders")]
    ...
    // Column map
    [ db_column(1, status=m_dwOrderIDStatus, length=m_dwOrderIDLength) ] LONG m_OrderID;
    [ db_column(2, status=m_dwCustomerIDStatus, length=m_dwCustomerIDLength) ] TCHAR m_CustomerID[6];
    ...
    ```

     em vez de usar a classe de modelo `CTable` para declarar a tabela e a classe de acessador da tabela, e as macros BEGIN_COLUMN_MAP e END_COLUMN_MAP para criar o mapa de coluna, como neste exemplo:

    ```cpp
    // Table accessor class
        class COrdersAccessor; // Table class
        class COrders : public CTable<CAccessor<COrdersAccessor>>;
    // ...
    // Column map
        BEGIN_COLUMN_MAP(COrderDetailsAccessor)
            COLUMN_ENTRY_LENGTH_STATUS(1, m_OrderID, m_dwOrderIDLength, m_dwOrderIDStatus)
            COLUMN_ENTRY_LENGTH_STATUS(2, m_CustomerID, m_dwCustomerIDLength, m_dwCustomerIDStatus)
            // ...
        END_COLUMN_MAP()
    ```

  - Se você selecionar um consumidor **Tipo** de **Comando** , o assistente usará os atributos `db_source` e `db_command`, bem como usará `db_column` para criar o mapa de coluna. Por exemplo, ele cria este mapa:

    ```cpp
    [db_source("<initialization_string>"), db_command("SQL_command")]
    ...
    // Column map using db_column is the same as for consumer type of 'table'
    ```

     em vez de usar o comando e as declarações de classe do acessador de comando no arquivo. h da classe de comando, por exemplo:

    ```cpp
    // Command accessor class:
        class CListOrdersAccessor;
    // Command class:
        class CListOrders : public CCommand<CAccessor<CListOrdersAccessor>>;
    // ...
    // Column map using BEGIN_COLUMN_MAP ... END_COLUMN_MAP is the same as
    // for consumer type of 'table'
    ```

     Consulte [mecânica básica de atributos](../../windows/attributes/cpp-attributes-com-net.md#basic-mechanics-of-attributes) para obter mais informações.

- **Tipo**

   Selecione um desses botões de opção para especificar se a classe de consumidor será derivada de `CTable` ou `CCommand` (padrão).

  - **Tabela**

      Selecione essa opção se quiser usar `CTable` ou `db_table` para criar a tabela e a definição de classe do acessador de tabela.

  - **Comando**

      Selecione essa opção se quiser usar `CCommand` ou `db_command` para criar o comando e as declarações de classe do acessador de comando. Essa é a seleção padrão.

- **Suporte**

   Marque as caixas de seleção para especificar os tipos de atualização a ser suportados no consumidor (o padrão é nenhum). Cada um definirá [DBPROP_IRowsetChange](/previous-versions/windows/desktop/ms715892(v=vs.85)) e as entradas apropriadas para [DBPROP_UPDATABILITY](/previous-versions/windows/desktop/ms722676(v=vs.85)) no mapa do conjunto de propriedades.

  - **Alteração**

      Especifica que o consumidor é compatível com as atualizações dos dados da linha no conjunto de linhas.

  - **Inserção**

      Especifica que o consumidor é compatível com a inserção de linhas no conjunto de linhas.

  - **Excluir**

      Especifica que o consumidor é compatível com a exclusão de linhas do conjunto de linhas.

::: moniker-end

## <a name="see-also"></a>Veja também

[Consumidor OLE DB da ATL](../../atl/reference/adding-an-atl-ole-db-consumer.md)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Cadeias de conexão e links de dados (OLE DB)](/previous-versions/windows/desktop/ms718376(v=vs.85))
