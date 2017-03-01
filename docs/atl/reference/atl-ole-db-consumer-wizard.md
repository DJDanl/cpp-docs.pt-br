---
title: Assistente de consumidor do ATL OLE DB | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
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
caps.latest.revision: 13
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: 5a0c6a1062330f952bb8fa52bc934f6754465513
ms.openlocfilehash: 6e35ce9038a8fd8f7aeeb00139511a8f45c1257d
ms.lasthandoff: 02/25/2017

---
# <a name="atl-ole-db-consumer-wizard"></a>Assistente de Cliente ATL OLE DB
Este assistente configura uma classe de consumidor OLE DB com as ligações de dados necessário para acessar a fonte de dados especificada por meio do provedor OLE DB especificado.  
  
> [!NOTE]
>  Este assistente exige que você clique o **fonte de dados** para selecionar uma fonte de dados antes de inserir os nomes na `Class` e **. h arquivo** campos.  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Fonte de dados**  
 O **fonte de dados** botão permite que você defina a fonte de dados especificado usando o provedor OLE DB especificado. Quando você clica nesse botão, o **propriedades de vínculo de dados** caixa de diálogo é exibida. Para obter mais informações sobre a criação de cadeias de caracteres de conexão e o **propriedades de vínculo de dados** caixa de diálogo, consulte [Data Link API Overview](https://msdn.microsoft.com/library/ms718102.aspx) no [!INCLUDE[winsdkshort](../../atl-mfc-shared/reference/includes/winsdkshort_md.md)] documentação.  
  
> [!NOTE]
>  Em versões anteriores, Shift + clique o **fonte de dados** botão Abrir uma caixa de diálogo Abrir arquivo para permitir que você selecione um arquivo de vínculo de dados (. udl). Não há suporte para essa funcionalidade.  
  
 A caixa de diálogo possui quatro guias:  
  
- **Provedor** guia  
  
- **Conexão** guia  
  
- **Advanced** guia  
  
- **Todos os** guia  
  
     As informações adicionais a seguir descrevem as guias a **propriedades de vínculo de dados** caixa de diálogo.  
  
     Clique em **Okey** para concluir. O **Selecionar objeto de banco de dados** caixa de diálogo é exibida. Na caixa de diálogo, selecione a tabela, exibição ou procedimento armazenado que o consumidor usará.  
  
 **Provedor**  
     Selecione um provedor apropriado para gerenciar a conexão à fonte de dados. O tipo de provedor geralmente é determinado pelo tipo de banco de dados ao qual você está se conectando. Clique o `Next` botão ou clique no **Conexão** guia.  
  
 **Conexão**  
     O conteúdo dessa guia depende do provedor selecionado. Embora haja muitos tipos de provedores, esta seção aborda conexões para os dois mais comuns: dados SQL e ODBC. Os outros são similares variações nos campos descritos aqui.  
  
     Para dados do SQL:  
  
    1. **Selecione ou insira um nome de servidor:** clique no menu da lista suspensa para exibir todos os servidores de dados registrados na rede e selecione uma.  
  
    2. **Insira as informações de logon para o servidor:** Insira um nome de usuário e senha para fazer logon no servidor de dados.  
  
    3. **Selecione o banco de dados no servidor:** clique no menu da lista suspensa para exibir todas as marcas de bancos de dados no servidor de dados e selecione um.  
  
         -ou-  
  
 **Anexar um arquivo de banco de dados como um nome de banco de dados:** especificar um arquivo a ser usado como o banco de dados, digite o caminho explícito.  
  
        > [!NOTE]
        >  There is a security problem with the "Allow saving of password" feature of the Data Link Properties dialog box. In "Enter information to log on to the server," there are two radio buttons:  
  
 **Usar segurança integrada do Windows NT**  
  
 **Usar um determinado nome de usuário e senha**  
  
         If you select **Use a specific user name and password**, you have the option of saving the password (using the check box for "Allow saving password"); however, this option is not secure. It is recommended that you select **Use Windows NT integrated security**; this option is secure because it encrypts the password.  
  
         There might be situations in which you want to select "Allow saving password." For example, if you are releasing a library with a private database solution, you should not access the database directly but instead use a middle-tier application to verify the user (through whatever authentication scheme you choose) and then limit the sort of data available to the user.  
  
         For ODBC data:  
  
         1. **Specify the source of data:** You can use a data source name or a connection string.  
  
 **Nome de fonte de dados de uso:** essa lista suspensa exibe fontes de dados registrados no seu computador. Você pode configurar fontes de dados antes do tempo usando o administrador de fonte de dados ODBC- ou -**usar cadeia de conexão:** digite uma cadeia de caracteres de conexão já tiver obtido, ou clique no **criar** botão; o **Selecionar fonte de dados** caixa de diálogo é exibida. Selecione uma fonte de dados de arquivo ou máquina e clique em **Okey**.  
  
        > [!NOTE]
        >  You can obtain a connection string by viewing the properties of an existing connection in Server Explorer, or you can create a connection by double-clicking **Add Connection** in Server Explorer.  
  
         2. **Enter information to log on to the server:** Enter a user name and password to log on to the data server.  
  
         3. Enter the initial catalog to use.  
  
         4. Click **Test Connection**; if the test succeeds, click **OK**. If not, check your logon information, try another database, or try another data server.  
  
 **Avançado**  
 **Configurações de rede:** especificar o **nível de representação** (o nível de representação que o servidor tem permissão para usar ao representar o cliente; corresponde diretamente aos níveis de representação de RPC) e **nível de proteção** (o nível de proteção de dados enviados entre cliente e servidor; corresponde diretamente aos níveis de proteção de RPC).  
  
 **Outros:** na **tempo limite da conexão**, especifique o número de segundos de tempo ocioso antes de um tempo limite ocorre. Em **permissões de acesso**, especifique as permissões de acesso na conexão de dados.  
  
     Para obter mais informações sobre propriedades de inicialização avançadas, consulte a documentação fornecida com cada provedor do OLE DB específico.  
  
 **All**  
     Essa guia exibe um resumo das propriedades de inicialização para a fonte de dados e a conexão que você especificou. Você pode editar esses valores.  
  
     Clique em **Okey** para concluir. O **Selecionar objeto de banco de dados** caixa de diálogo é exibida. Na caixa de diálogo, selecione a tabela, exibição ou procedimento armazenado que o consumidor usará.  
  
 `Class`  
 Depois de selecionar uma fonte de dados, esta caixa é preenchida com um nome de classe de padrão com base na tabela ou procedimento armazenado selecionado (consulte **selecionar uma fonte de dados** abaixo). Você pode editar o nome da classe.  
  
 **arquivo. h**  
 Depois de selecionar uma fonte de dados, esta caixa é preenchida com um nome de classe de cabeçalho padrão com base na tabela ou procedimento armazenado selecionado (consulte **selecionar uma fonte de dados** abaixo). Você pode editar o nome do arquivo de cabeçalho ou selecione um arquivo de cabeçalho existente.  
  
 **Atribuído**  
 Esta opção especifica se o assistente criará classes do consumidor usando atributos ou declarações de modelo. Quando você seleciona essa opção, o assistente usa atributos, em vez de declarações de modelo (essa é a opção padrão). Quando você desmarca essa opção, o assistente usa declarações de modelo em vez de atributos.  
  
-   Se você selecionar um consumidor **tipo** da tabela, o assistente usa a `db_source` e **db_table** atributos para criar a tabela e o acessador de tabela declarações de classe e usa **db_column** para criar o mapa de coluna, por exemplo:  
  
 ``` 
 // Inject table class and table accessor class declarations  
 [db_source("<initialization_string>"), db_table("dbo.Orders")]  
 ... 
 // Column map  
 [ db_column(1, status=m_dwOrderIDStatus, length=m_dwOrderIDLength) ] LONG m_OrderID;  
 [ db_column(2, status=m_dwCustomerIDStatus, length=m_dwCustomerIDLength) ] TCHAR m_CustomerID[6];  
 ...  
 ```  
  
     em vez de usar o `CTable` classe de modelo para declarar a tabela e classe de acessador de tabela e as macros BEGIN_COLUMN_MAP e END_COLUMN_MAP para criar o mapa de coluna, por exemplo:  
  
 ``` 
 // Table accessor class  
    class COrdersAccessor; *// Table class  
    class COrders : public CTable<CAccessor<COrdersAccessor>>;  
 ... 
 // Column map  
    BEGIN_COLUMN_MAP(COrderDetailsAccessor) 
    COLUMN_ENTRY_LENGTH_STATUS(1, m_OrderID, m_dwOrderIDLength, m_dwOrderIDStatus)  
    COLUMN_ENTRY_LENGTH_STATUS(2, m_CustomerID, m_dwCustomerIDLength, m_dwCustomerIDStatus)  
 ...  
    END_COLUMN_MAP() 
 ```  
  
-   Se você selecionar um consumidor **tipo** de comando, o assistente usa a `db_source` e **db_command** atributos e usa **db_column** para criar o mapa de coluna, por exemplo:  
  
 ```  
 [db_source("<initialization_string>"), db_command("SQL_command")]  
 ... 
 // Column map using db_column is the same as for consumer type of 'table'  
 ```  
  
     em vez de usar o comando e declarações de classe de acessador de comando no arquivo. h a classe de comando, por exemplo:  
  
 ```  
    Command accessor class:  
    class CListOrdersAccessor;  
    Command class:  
    class CListOrders : public CCommand<CAccessor<CListOrdersAccessor>>;  
 ... 
 // Column map using BEGIN_COLUMN_MAP ... END_COLUMN_MAP is the same as
 // for consumer type of 'table'  
 ```  
  
 Consulte [mecânica básica de atributos](../../windows/basic-mechanics-of-attributes.md) para obter mais informações.  
  
 **Tipo**  
 Selecione um desses botões de opção para especificar se a classe de consumidor será derivada do `CTable` ou `CCommand` (padrão).  
  
 **Tabela**  
 Selecione esta opção se você quiser usar `CTable` ou **db_table** para criar a tabela e o acessador de tabela declarações de classe.  
  
 **Comando**  
 Selecione esta opção se você quiser usar `CCommand` ou **db_command** para criar o comando e o acessador de comando declarações de classe. Essa é a seleção padrão.  
  
 **Suporte**  
 Marque as caixas de seleção para especificar os tipos de atualizações com suporte no consumidor (o padrão é none). Cada um dos seguintes definirá [DBPROP_IRowsetChange](https://msdn.microsoft.com/library/ms715892.aspx) e as entradas apropriadas para [DBPROP_UPDATABILITY](https://msdn.microsoft.com/library/ms722676.aspx) na propriedade definida no mapa.  
  
 **Alteração**  
 Especifica que o consumidor dão suporte a atualizações de dados de linha no conjunto de linhas.  
  
 **Inserir**  
 Especifica que o consumidor dar suporte à inserção de linhas no conjunto de linhas.  
  
 **Excluir**  
 Especifica que o consumidor dar suporte à exclusão de linhas do conjunto de linhas.  
  
## <a name="see-also"></a>Consulte também  
 [Consumidor ATL OLE DB](../../atl/reference/adding-an-atl-ole-db-consumer.md)   
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)   
 [Cadeias de caracteres de Conexão e Links de dados (OLE DB)](https://msdn.microsoft.com/library/ms718376.aspx)

