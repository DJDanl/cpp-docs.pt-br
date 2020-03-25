---
title: 'Fonte de dados: gerenciando conexões (ODBC)'
ms.date: 11/04/2016
helpviewer_keywords:
- ODBC data sources [C++], multiuser environments
- generalizing connection strings
- ODBC [C++], disconnecting from data sources
- connection strings [C++], generalizing
- database connections [C++], creating
- GetDefaultConnect method
- connections [C++], data source
- ODBC connections [C++], configuring
- disconnecting from data sources
- databases [C++], connecting to
- ODBC connections [C++], disconnecting
- data sources [C++], connecting to
- ODBC connections [C++], connecting to data source
- ODBC data sources [C++], connections
- database connections [C++], MFC ODBC classes
ms.assetid: c0adbcdd-c000-40c6-b199-09ffdc7b6ef2
ms.openlocfilehash: 6186199ea51c1fc966783ed3c0a73496c6a307ee
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80213285"
---
# <a name="data-source-managing-connections-odbc"></a>Fonte de dados: gerenciando conexões (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Este tópico explica:

- [Como configurar uma fonte de dados](#_core_configuring_a_data_source).

- [Como um ambiente multiusuário afeta uma fonte de dados e seus conjuntos de registros](#_core_working_in_a_multiuser_environment).

- [Por que você generaliza uma cadeia de conexão para uma fonte de dados](#_core_generalizing_the_connection_string).

- [Como se conectar a uma fonte de dados](#_core_connecting_to_a_specific_data_source).

- [Como se desconectar de uma fonte de dados](#_core_disconnecting_from_a_data_source).

- [Como reutilizar um objeto CDatabase](#_core_reusing_a_cdatabase_object).

Conectar-se a uma fonte de dados significa estabelecer comunicações com um DBMS para acessar os dados. Quando você se conecta a uma fonte de dados de um aplicativo por meio de um driver ODBC, o driver faz a conexão para você, seja localmente ou através de uma rede.

Você pode se conectar a qualquer fonte de dados para a qual você tenha um driver ODBC. Os usuários do seu aplicativo também devem ter o mesmo driver ODBC para sua fonte de dados. Para obter mais informações sobre a redistribuição de drivers ODBC, consulte [redistribuindo componentes ODBC para seus clientes](../../data/odbc/redistributing-odbc-components-to-your-customers.md).

##  <a name="configuring-a-data-source"></a><a name="_core_configuring_a_data_source"></a>Configurando uma fonte de dados

O Administrador ODBC é usado para configurar suas fontes de dados. Você também pode usar o Administrador ODBC após a instalação para adicionar ou remover fontes de dados. Ao criar aplicativos, você pode direcionar os usuários para o Administrador ODBC para permitir que eles adicionem fontes de dados ou você possa criar essa funcionalidade em seu aplicativo fazendo chamadas diretas de instalação do ODBC. Para obter mais informações, consulte [ODBC Administrator](../../data/odbc/odbc-administrator.md).

Você pode usar um arquivo do Excel como uma fonte de dados e precisa configurar o arquivo para que ele seja registrado e exibido na caixa de diálogo **selecionar fonte de dados** .

#### <a name="to-use-an-excel-file-as-a-data-source"></a>Para usar um arquivo do Excel como uma fonte de dados

1. Configure o arquivo com o administrador de fonte de dados ODBC.

1. Na guia **DSN de arquivo** , clique em **Adicionar**.

1. Na caixa de diálogo **criar nova fonte de dados** , selecione um driver do Excel e clique em **Avançar**.

1. Clique em **procurar**e selecione o nome do arquivo a ser usado como uma fonte de dados.

> [!NOTE]
>  Talvez seja necessário selecionar **todos os arquivos** no menu suspenso para exibir os arquivos. xls.

1. Clique em **Avançar**e em **Concluir**.

1. Na caixa de diálogo **instalação do ODBC do Microsoft Excel** , selecione a versão do banco de dados e a pasta de trabalho.

##  <a name="working-in-a-multiuser-environment"></a><a name="_core_working_in_a_multiuser_environment"></a>Trabalhando em um ambiente multiusuário

Se vários usuários estiverem conectados a uma fonte de dados, eles poderão alterar os dados enquanto você os estiver manipulando em seus conjuntos de registros. Da mesma forma, suas alterações podem afetar os conjuntos de registros de outros usuários. Para obter mais informações, consulte conjunto de registros [: como os conjuntos de registros atualizam os registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md) e [transação (ODBC)](../../data/odbc/transaction-odbc.md).

##  <a name="generalizing-the-connection-string"></a><a name="_core_generalizing_the_connection_string"></a>Generalizando a cadeia de conexão

Os assistentes usam uma cadeia de conexão padrão para estabelecer uma conexão com uma fonte de dados. Você usa essa conexão para exibir tabelas e colunas enquanto estiver desenvolvendo seu aplicativo. No entanto, essa cadeia de conexão padrão pode não ser apropriada para as conexões de seus usuários com a fonte de dados por meio de seu aplicativo. Por exemplo, sua fonte de dados e o caminho para seu local podem ser diferentes daquele usado no desenvolvimento de seu aplicativo. Nesse caso, você deve reimplementar a função de membro [CRecordset:: GetDefaultConnect](../../mfc/reference/crecordset-class.md#getdefaultconnect) de maneira mais genérica e descartar a implementação do assistente. Por exemplo, use uma das seguintes abordagens:

- Registre e gerencie as cadeias de conexão usando o Administrador ODBC.

- Edite a cadeia de conexão e remova o nome da fonte de dados. A estrutura fornece o ODBC como a fonte de dados; em tempo de execução, o ODBC exibe uma caixa de diálogo solicitando o nome da fonte de dados e qualquer outra informação de conexão necessária.

- Forneça somente o nome da fonte de dados. O ODBC solicita a ID de usuário e a senha, se necessário. Por exemplo, antes de generalizar, a cadeia de conexão tem esta aparência:

    ```cpp
    CString CApp1Set::GetDefaultConnect()
    {
       return "ODBC;DSN=afx;Trusted_Connection=Yes;";
    }
    ```

   Essa cadeia de conexão especifica uma conexão confiável, que usa a segurança integrada do Windows NT. Você deve evitar embutir uma senha ou especificar uma senha em branco, pois isso cria uma grande fraqueza de segurança. Em vez disso, você pode dar `GetDefaultConnect` uma nova cadeia de conexão para que ela consulte uma ID de usuário e uma senha.

    ```cpp
    // User must select data source and supply user ID and password:
        return "ODBC;";
    // User ID and password required:
        return "ODBC;DSN=mydb;";
    // Password required (myuserid must be replaced with a valid user ID):
        return "ODBC;DSN=mydb;UID=myuserid;";
    // Hard-coded user ID and password (SECURITY WEAKNESS--AVOID):
        return "ODBC;DSN=mydb;UID=sa;PWD=777;";
    ```

##  <a name="connecting-to-a-specific-data-source"></a><a name="_core_connecting_to_a_specific_data_source"></a>Conectando-se a uma fonte de dados específica

Para se conectar a uma fonte de dados específica, sua fonte de dados já deve ter sido configurada com o [Administrador ODBC](../../data/odbc/odbc-administrator.md).

#### <a name="to-connect-to-a-specific-data-source"></a>Para se conectar a uma fonte de dados específica

1. Construa um objeto `CDatabase`.

1. Chame sua `OpenEx` ou `Open` função membro.

Para obter mais informações sobre como especificar a fonte de dados se ela for algo diferente daquele especificado com um assistente, consulte [CDatabase:: OpenEx](../../mfc/reference/cdatabase-class.md#openex) ou [CDatabase:: Open](../../mfc/reference/cdatabase-class.md#open) na *referência do MFC*.

##  <a name="disconnecting-from-a-data-source"></a><a name="_core_disconnecting_from_a_data_source"></a>Desconectando de uma fonte de dados

Você deve fechar todos os conjuntos de registros abertos antes de chamar a `Close` função membro de `CDatabase`. Nos conjuntos de registros associados ao objeto de `CDatabase` que você deseja fechar, qualquer instrução `AddNew` ou `Edit` pendentes é cancelada e todas as transações pendentes são revertidas.

#### <a name="to-disconnect-from-a-data-source"></a>Para desconectar-se de uma fonte de dados

1. Chame a função de membro [Close](../../mfc/reference/cdatabase-class.md#close) do objeto `CDatabase`.

1. Destrua o objeto, a menos que você queira reutilizá-lo.

##  <a name="reusing-a-cdatabase-object"></a><a name="_core_reusing_a_cdatabase_object"></a>Reutilizando um objeto CDatabase

Você pode reutilizar um objeto `CDatabase` depois de desconectar-se dele, se você usá-lo para se reconectar à mesma fonte de dados ou se conectar a uma fonte de dados diferente.

#### <a name="to-reuse-a-cdatabase-object"></a>Para reutilizar um objeto CDatabase

1. Feche a conexão original do objeto.

1. Em vez de destruir o objeto, chame sua `OpenEx` ou `Open` função membro novamente.

## <a name="see-also"></a>Confira também

[Fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md)<br/>
[Fonte de dados: determinando o esquema da fonte de dados (ODBC)](../../data/odbc/data-source-determining-the-schema-of-the-data-source-odbc.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)
