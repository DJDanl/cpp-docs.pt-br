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
ms.openlocfilehash: 107a5e20b70f67be74b6e6f861bd539446e9d4ee
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374526"
---
# <a name="data-source-managing-connections-odbc"></a>Fonte de dados: gerenciando conexões (ODBC)

Este tópico aplica-se às classes ODBC do MFC.

Este tópico explica:

- [Como configurar uma fonte de dados](#_core_configuring_a_data_source).

- [Como um ambiente multiusuário afeta uma fonte de dados e seus conjuntos de registros](#_core_working_in_a_multiuser_environment).

- [Por que você generaliza uma seqüência de conexão a uma fonte de dados](#_core_generalizing_the_connection_string).

- [Como se conectar a uma fonte de dados](#_core_connecting_to_a_specific_data_source).

- [Como desconectar-se de uma fonte de dados](#_core_disconnecting_from_a_data_source).

- [Como reutilizar um objeto CDatabase](#_core_reusing_a_cdatabase_object).

Conectar-se a uma fonte de dados significa estabelecer comunicações com um DBMS para acessar os dados. Quando você se conecta a uma fonte de dados de um aplicativo através de um driver ODBC, o driver faz a conexão para você, localmente ou através de uma rede.

Você pode se conectar a qualquer fonte de dados para a qual você tenha um driver ODBC. Os usuários do seu aplicativo também devem ter o mesmo driver ODBC para sua fonte de dados. Para obter mais informações sobre a redistribuição de drivers ODBC, consulte [Redistribuindo componentes ODBC para seus clientes](../../data/odbc/redistributing-odbc-components-to-your-customers.md).

## <a name="configuring-a-data-source"></a><a name="_core_configuring_a_data_source"></a>Configurando uma fonte de dados

O administrador ODBC é usado para configurar suas fontes de dados. Você também pode usar o Administrador ODBC após a instalação para adicionar ou remover fontes de dados. Ao criar aplicativos, você pode direcionar seus usuários para o administrador do ODBC para permitir que eles adicionem fontes de dados ou você pode construir essa funcionalidade em seu aplicativo fazendo chamadas diretas de instalação do ODBC. Para obter mais informações, consulte [Administrador oDBC](../../data/odbc/odbc-administrator.md).

Você pode usar um arquivo Excel como fonte de dados e precisa configurar o arquivo para que ele seja registrado e apareça na caixa de diálogo **Selecionar fonte de dados.**

#### <a name="to-use-an-excel-file-as-a-data-source"></a>Para usar um arquivo Excel como fonte de dados

1. Configure o arquivo com o administrador de origem de dados ODBC.

1. Na **guia Arquivo DSN,** clique **em Adicionar**.

1. Na caixa de diálogo **Criar nova fonte de dados,** selecione um driver do Excel e clique em **Next**.

1. Clique **em Procurar**e selecione o nome do arquivo a ser usado como fonte de data.

> [!NOTE]
> Você pode precisar selecionar **Todos os Arquivos** no menu suspenso para exibir os arquivos .xls.

1. Clique em **Avançar** e em **Concluir**.

1. Na caixa de diálogo **ODBC Microsoft Excel Setup,** selecione a versão do banco de dados e a pasta de trabalho.

## <a name="working-in-a-multiuser-environment"></a><a name="_core_working_in_a_multiuser_environment"></a>Trabalhando em um ambiente multiusuário

Se vários usuários estiverem conectados a uma fonte de dados, eles podem alterar os dados enquanto você os manipula em seus conjuntos de registros. Da mesma forma, suas alterações podem afetar os conjuntos de registros de outros usuários. Para obter mais informações, consulte [Recordset: How Recordsets Update Records (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md) e [Transaction (ODBC)](../../data/odbc/transaction-odbc.md).

## <a name="generalizing-the-connection-string"></a><a name="_core_generalizing_the_connection_string"></a>Generalizando a cadeia de conexão

Os assistentes usam uma seqüência de conexão padrão para estabelecer uma conexão com uma fonte de dados. Você usa essa conexão para visualizar tabelas e colunas enquanto estiver desenvolvendo seu aplicativo. No entanto, essa seqüência de conexão padrão pode não ser apropriada para as conexões de seus usuários com a fonte de dados através de seu aplicativo. Por exemplo, sua fonte de dados e o caminho para sua localização podem ser diferentes do usado no desenvolvimento de sua aplicação. Nesse caso, você deve reimplementar a função de membro [CRecordset::GetDefaultConnect](../../mfc/reference/crecordset-class.md#getdefaultconnect) de forma mais genérica e descartar a implementação do assistente. Por exemplo, use uma das seguintes abordagens:

- Registre e gerencie as strings de conexão usando o administrador ODBC.

- Edite a seqüência de conexões e remova o nome da fonte de dados. A estrutura fornece o ODBC como fonte de dados; no tempo de execução, o ODBC exibe uma caixa de diálogo pedindo o nome da fonte de dados e quaisquer outras informações de conexão necessárias.

- Forneça apenas o nome da fonte de dados. A ODBC pede o ID do usuário e a senha, se necessário. Por exemplo, antes de generalizar, a seqüência de conexões se parece com isso:

    ```cpp
    CString CApp1Set::GetDefaultConnect()
    {
       return "ODBC;DSN=afx;Trusted_Connection=Yes;";
    }
    ```

   Esta seqüência de conexões especifica uma conexão confiável, que usa a segurança integrada do Windows NT. Você deve evitar codificar uma senha ou especificar uma senha em branco, porque isso cria uma grande fraqueza de segurança. Em vez disso, você pode dar `GetDefaultConnect` uma nova seqüência de conexão para que ele consultasse um ID de usuário e senha.

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

## <a name="connecting-to-a-specific-data-source"></a><a name="_core_connecting_to_a_specific_data_source"></a>Conectando-se a uma fonte de dados específica

Para se conectar a uma fonte de dados específica, sua fonte de dados já deve ter sido configurada com [o Administrador ODBC](../../data/odbc/odbc-administrator.md).

#### <a name="to-connect-to-a-specific-data-source"></a>Para se conectar a uma fonte de dados específica

1. Construa `CDatabase` um objeto.

1. Ligue `OpenEx` para `Open` a função ou membro.

Para obter mais informações sobre como especificar a fonte de dados se for algo diferente do que você especificou com um assistente, consulte [CDatabase::OpenEx](../../mfc/reference/cdatabase-class.md#openex) ou [CDatabase::Abrir](../../mfc/reference/cdatabase-class.md#open) na *referência do MFC*.

## <a name="disconnecting-from-a-data-source"></a><a name="_core_disconnecting_from_a_data_source"></a>Desconectando-se de uma fonte de dados

Você deve fechar quaisquer conjuntos `Close` de `CDatabase`registros abertos antes de chamar a função de membro de . Em conjuntos de `CDatabase` registros associados ao objeto `AddNew` `Edit` que você deseja fechar, quaisquer pendências ou declarações são canceladas e todas as transações pendentes são revertidas.

#### <a name="to-disconnect-from-a-data-source"></a>Para desconectar-se de uma fonte de dados

1. Ligue `CDatabase` para a função de membro [close](../../mfc/reference/cdatabase-class.md#close) do objeto.

1. Destrua o objeto a menos que queira reutilizá-lo.

## <a name="reusing-a-cdatabase-object"></a><a name="_core_reusing_a_cdatabase_object"></a>Reutilização de um objeto CDatabase

Você pode reutilizar um `CDatabase` objeto depois de se desconectar dele, se você usá-lo para se reconectar à mesma fonte de dados ou para se conectar a uma fonte de dados diferente.

#### <a name="to-reuse-a-cdatabase-object"></a>Para reutilizar um objeto CDatabase

1. Feche a conexão original do objeto.

1. Em vez de destruir o `OpenEx` `Open` objeto, chame sua função ou membro novamente.

## <a name="see-also"></a>Confira também

[Fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md)<br/>
[Fonte de dados: determinando o esquema da fonte de dados (ODBC)](../../data/odbc/data-source-determining-the-schema-of-the-data-source-odbc.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)
