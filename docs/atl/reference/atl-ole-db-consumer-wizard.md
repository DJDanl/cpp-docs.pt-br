---
title: Assistente de cliente ATL OLE DB | Microsoft Docs
ms.custom: ''
ms.date: 08/31/2018
ms.technology:
- cpp-atl
ms.topic: reference
f1_keywords:
- vc.codewiz.class.atl.consumer.overview
dev_langs:
- C++
helpviewer_keywords:
- ATL projects, adding ATL OLE DB consumers
- connection strings [C++], OLE DB consumers
- ATL OLE DB Consumer Wizard
ms.assetid: dcb68ed1-2224-422f-9f7b-108a74864204
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2555bdd9c1de130cd692131c12b7b2afc37537be
ms.sourcegitcommit: 3a141cf07b5411d5f1fdf6cf67c4ce928cf389c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/11/2018
ms.locfileid: "49083033"
---
# <a name="atl-ole-db-consumer-wizard"></a>Assistente de consumidor OLE DB da ATL

Este assistente define uma classe de consumidor do OLE DB com as associações de dados necessário para acessar a fonte de dados especificado por meio do provedor OLE DB especificado.

> [!NOTE]
> Este assistente exige que você clique o **fonte de dados** botão para selecionar uma fonte de dados antes de inserir os nomes na `Class` e **arquivo. h** campos.

## <a name="uielement-list"></a>Lista UIElement

- **Fonte de dados**

   O **fonte de dados** botão permite que você defina a fonte de dados especificado usando o provedor OLE DB especificado. Quando você clica nesse botão, o **propriedades de vínculo de dados** caixa de diálogo é exibida. Para obter mais informações sobre a criação de cadeias de caracteres de conexão e o **propriedades de vínculo de dados** caixa de diálogo, consulte [visão geral da API de Link de dados](/previous-versions/windows/desktop/ms718102) na documentação do SDK do Windows.

   As informações adicionais a seguir descrevem as guias na **propriedades de vínculo de dados** caixa de diálogo.

   - **Provedor** guia

      Selecione um provedor apropriado para gerenciar a conexão à fonte de dados. O tipo do provedor normalmente é determinado pelo tipo de banco de dados ao qual você está se conectando. Clique o **próxima** botão ou clique no **Conexão** guia.

   - **Conexão** guia

      O conteúdo dessa guia depende do provedor selecionado. Embora haja muitos tipos de provedores, esta seção aborda as conexões para as duas mais comuns: dados SQL e ODBC. Os outros são semelhantes variações nos campos descritos aqui.

      Para dados do SQL:

      1. **Selecione ou insira um nome de servidor:** clique no menu de lista suspensa para exibir todos os servidores de dados registrados na rede e selecione um.

      1. **Insira informações para fazer logon no servidor:** Insira um nome de usuário e senha para fazer logon no servidor de dados.

         > [!NOTE]
         > Há um problema de segurança com o recurso de "Permitir salvamento de senha" da caixa de diálogo Propriedades do Link de dados. "Insira as informações de logon para o servidor", há dois botões de opção:
         >
         > - **Usar segurança integrada do Windows NT**
         > - **Use um nome de usuário específico e uma senha**
         >
         > Se você selecionar **usar um determinado nome de usuário e senha**, você tem a opção de salvar a senha (usando a caixa de seleção para "Permitir salvamento de senha"); no entanto, essa opção não é segura. É recomendável que você selecione **a segurança integrada Use Windows NT**; essa opção é segura porque ele criptografa a senha.
         > Pode haver situações em que você deseja selecionar "Permitir salvamento de senha". Por exemplo, se você estiver liberando uma biblioteca com uma solução de banco de dados particular, você deve não acessar o banco de dados diretamente, mas em vez disso, use um aplicativo de camada intermediária para verificar se o usuário (por meio de qualquer esquema de autenticação escolhido) e, em seguida, limitar a classificação de dados disponível para o usuário.

      1. **Selecione o banco de dados no servidor:** clique no menu de lista suspensa para exibir todos os bancos de dados no servidor de data e selecione um.

         \- ou -

         **Anexar um arquivo de banco de dados como um nome de banco de dados:** especificar um arquivo a ser usado como o banco de dados; Insira o nome do caminho explícito.

      Para dados ODBC:

      1. **Especifique a fonte de dados:** você pode usar um nome de fonte de dados ou uma cadeia de caracteres de conexão.

         **Nome de fonte de dados de uso:** essa lista suspensa exibe fontes de dados registrados no seu computador. Você pode configurar fontes de dados antes do tempo usando o administrador de fonte de dados ODBC

         \- ou -

         **Usar cadeia de caracteres de conexão:** insira uma cadeia de caracteres de conexão já tenham obtido, ou clique em de **compilar** botão; o **Selecionar fonte de dados** caixa de diálogo é exibida. Selecione uma fonte de dados de arquivo ou de máquina e clique em **Okey**.

         > [!NOTE]
         > Você pode obter uma cadeia de caracteres de conexão ao exibir as propriedades de uma conexão existente na **Gerenciador de servidores**, ou você pode criar uma conexão clicando duas vezes em **Adicionar Conexão** em **Server Explorer**.

      1. **Insira informações para fazer logon no servidor:** Insira um nome de usuário e senha para fazer logon no servidor de dados.

      1. Insira o catálogo inicial a ser usado.

      1. Clique em **Testar Conexão**; se o teste for bem-sucedido, clique em **Okey**. Caso contrário, verifique suas informações de logon, tente outro banco de dados ou tente outro servidor de dados.

   - **Advanced** guia

      **Configurações de rede:** especifique o **nível de representação** (o nível de representação que o servidor tem permissão para usar ao representar o cliente; corresponde diretamente aos níveis de representação do RPC) e  **Nível de proteção** (o nível de proteção de dados enviados entre cliente e servidor; corresponde diretamente aos níveis de proteção do RPC).

      **Outros:** na **tempo limite de conexão**, especifique o número de segundos de tempo ocioso permitido antes que ocorra um tempo limite. Na **permissões de acesso**, especifique as permissões de acesso na conexão de dados.

       Para obter mais informações sobre propriedades de inicialização avançadas, consulte a documentação fornecida com cada provedor do OLE DB específico.

   - **Todos os** guia

      Essa guia exibe um resumo das propriedades de inicialização para a fonte de dados e a conexão que você especificou. Você pode editar esses valores.

   Clique em **Okey** para concluir. O **Selecionar objeto de banco de dados** caixa de diálogo é exibida. Na caixa de diálogo, selecione a tabela, exibição ou procedimento armazenado que o consumidor usará.

- **Class**

   Depois de selecionar uma fonte de dados, essa caixa é preenchida com um nome de classe padrão com base na tabela ou procedimento armazenado que você selecionou (consulte **selecionar uma fonte de dados** abaixo). Você pode editar o nome da classe.

- **Arquivo .h**

   Depois de selecionar uma fonte de dados, essa caixa é preenchida com um nome de classe de cabeçalho padrão com base na tabela ou procedimento armazenado que você selecionou (consulte **selecionar uma fonte de dados** abaixo). Você pode editar o nome do arquivo de cabeçalho ou selecionar um arquivo de cabeçalho existente.

- **Atribuído**

   Esta opção especifica se o assistente criará as classes de consumidor usando atributos ou declarações de modelo. Quando você seleciona essa opção, o assistente usa atributos em vez de declarações de modelo (Isso é a opção padrão). Quando você desmarca essa opção, o assistente usa declarações de modelo em vez de atributos.

   - Se você selecionar um consumidor **tipo** de **tabela**, o assistente usa os `db_source` e `db_table` atributos para criar a tabela e o acessador de tabela de declarações de classe e usa `db_column` para Crie o mapa de coluna. Por exemplo, ele cria esse mapa:

        ```cpp
        // Inject table class and table accessor class declarations
        [db_source("<initialization_string>"), db_table("dbo.Orders")]
        ...
        // Column map
        [ db_column(1, status=m_dwOrderIDStatus, length=m_dwOrderIDLength) ] LONG m_OrderID;
        [ db_column(2, status=m_dwCustomerIDStatus, length=m_dwCustomerIDLength) ] TCHAR m_CustomerID[6];
        ...
        ```

      em vez de usar o `CTable` classe de modelo para declarar a tabela e a classe de acessador de tabela e as macros BEGIN_COLUMN_MAP e END_COLUMN_MAP para criar o mapa de coluna, como neste exemplo:

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

   - Se você selecionar um consumidor **tipo** de **comando**, o assistente usa os `db_source` e `db_command` atributos e usa `db_column` para criar o mapa de coluna. Por exemplo, ele cria esse mapa:

        ```cpp
        [db_source("<initialization_string>"), db_command("SQL_command")]
        ...
        // Column map using db_column is the same as for consumer type of 'table'
        ```

      em vez de usar o comando e declarações de classe de acessador de comando no arquivo. h a classe de comando, por exemplo:

        ```cpp
        // Command accessor class:
            class CListOrdersAccessor;
        // Command class:
            class CListOrders : public CCommand<CAccessor<CListOrdersAccessor>>;
        // ...
        // Column map using BEGIN_COLUMN_MAP ... END_COLUMN_MAP is the same as
        // for consumer type of 'table'
        ```

      Ver [mecânica básica de atributos](../../windows/basic-mechanics-of-attributes.md) para obter mais informações.

- **Tipo**

   Selecione um desses botões de opção para especificar se a classe de consumidor será derivada de `CTable` ou `CCommand` (padrão).

   - **Tabela**

      Selecione esta opção se você quiser usar `CTable` ou `db_table` para criar a tabela e o acessador de tabela de declarações de classe.

   - **Comando**

      Selecione esta opção se você quiser usar `CCommand` ou `db_command` para criar o comando e o acessador de comando declarações de classe. Essa é a seleção padrão.

- **Suporte**

   Marque as caixas de seleção para especificar os tipos de atualizações com suporte no consumidor (o padrão é none). Cada um dos seguintes definirá [DBPROP_IRowsetChange](/previous-versions/windows/desktop/ms715892) e as entradas apropriadas para [DBPROP_UPDATABILITY](/previous-versions/windows/desktop/ms722676) no conjunto de propriedades mapa.

   - **Alteração**

      Especifica que o consumidor dão suporte a atualizações de dados de linha no conjunto de linhas.

   - **Inserir**

      Especifica que o consumidor dá suporte a inserção de linhas no conjunto de linhas.

   - **Excluir**

      Especifica que o consumidor dá suporte a exclusão de linhas do conjunto de linhas.

## <a name="see-also"></a>Consulte também

[Consumidor do OLE DB da ATL](../../atl/reference/adding-an-atl-ole-db-consumer.md)<br/>
[Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)<br/>
[Cadeias de caracteres de Conexão e Links de dados (OLE DB)](/previous-versions/windows/desktop/ms718376)
