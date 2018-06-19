---
title: 'Fonte de dados: Gerenciando conexões (ODBC) | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 100c06773a8f0ffa79631339384bd4ec42fa4b52
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33091823"
---
# <a name="data-source-managing-connections-odbc"></a>Fonte de dados: gerenciando conexões (ODBC)
Este tópico se aplica às classes MFC ODBC.  
  
 Este tópico explica:  
  
-   [Como configurar uma fonte de dados](#_core_configuring_a_data_source).  
  
-   [Como um ambiente multiusuário afeta uma fonte de dados e seus conjuntos de registros](#_core_working_in_a_multiuser_environment).  
  
-   [Por que generalizar uma cadeia de caracteres de conexão para uma fonte de dados](#_core_generalizing_the_connection_string).  
  
-   [Como se conectar a uma fonte de dados](#_core_connecting_to_a_specific_data_source).  
  
-   [Como desconectar de uma fonte de dados](#_core_disconnecting_from_a_data_source).  
  
-   [Como a reutilização de um objeto de CDatabase](#_core_reusing_a_cdatabase_object).  
  
 Conectando a uma fonte de dados significa estabelecer comunicações com um DBMS para acessar os dados. Quando você se conectar a uma fonte de dados de um aplicativo por meio de um driver ODBC, o driver faz a conexão para você, localmente ou em uma rede.  
  
 Você pode se conectar a qualquer fonte de dados em que você tenha um driver ODBC. Os usuários do seu aplicativo também devem ter o mesmo driver ODBC para sua fonte de dados. Para obter mais informações sobre a redistribuição drivers ODBC, consulte [redistribuindo componentes ODBC para os seus clientes](../../data/odbc/redistributing-odbc-components-to-your-customers.md).  
  
##  <a name="_core_configuring_a_data_source"></a> Configurar uma fonte de dados  
 Administrador de ODBC é usado para configurar suas fontes de dados. Você também pode usar o administrador ODBC após a instalação para adicionar ou remover fontes de dados. Quando você cria aplicativos, ou você pode direcionar os usuários para o administrador de ODBC que você adicione fontes de dados ou você pode criar essa funcionalidade em seu aplicativo por meio de chamadas diretas de instalação ODBC. Para obter mais informações, consulte [administrador ODBC](../../data/odbc/odbc-administrator.md).  
  
 Você pode usar um arquivo do Excel como uma fonte de dados, e você precisa configurar o arquivo para que ele está registrado e aparece no **Selecionar fonte de dados** caixa de diálogo.  
  
#### <a name="to-use-an-excel-file-as-a-data-source"></a>Para usar um arquivo do Excel como uma fonte de dados  
  
1.  Configure o arquivo com o administrador de fonte de dados ODBC.  
  
2.  Sobre o **DSN de arquivo** , clique em **adicionar**.  
  
3.  No **criar nova fonte de dados** caixa de diálogo, selecione um driver do Excel e, em seguida, clique em **próximo**.  
  
4.  Clique em **procurar**e selecione o nome do arquivo a ser usado como uma origem de dados.  
  
> [!NOTE]
>  Talvez você precise selecionar **todos os arquivos** no menu suspenso para exibir os arquivos. xls.  
  
1.  Clique em **Avançar**e em **Concluir**.  
  
2.  No **Configurar ODBC para Microsoft Excel** caixa de diálogo, selecione a versão do banco de dados e a pasta de trabalho.  
  
##  <a name="_core_working_in_a_multiuser_environment"></a> Trabalhando em um ambiente multiusuário  
 Se vários usuários estiverem conectados a uma fonte de dados, eles podem alterar dados enquanto você estiver manipulando-lo em seu conjunto de registros. Da mesma forma, as alterações podem afetar o conjunto de registros de outros usuários. Para obter mais informações, consulte [conjunto de registros: como conjuntos de registros atualização registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md) e [transação (ODBC)](../../data/odbc/transaction-odbc.md).  
  
##  <a name="_core_generalizing_the_connection_string"></a> Generalizar a cadeia de caracteres de Conexão  
 Os assistentes de usam uma cadeia de caracteres de conexão padrão para estabelecer uma conexão com uma fonte de dados. Você pode usar essa conexão para exibir tabelas e colunas, enquanto você estiver desenvolvendo seu aplicativo. No entanto, essa cadeia de caracteres de conexão padrão não pode ser apropriada para conexões de seus usuários para a fonte de dados por meio do aplicativo. Por exemplo, sua fonte de dados e o caminho para o local podem ser diferentes daquele usado no desenvolvimento de seu aplicativo. Nesse caso, você deve reimplementar a [CRecordset::GetDefaultConnect](../../mfc/reference/crecordset-class.md#getdefaultconnect) membro funcionar de maneira mais genérica e descartar a implementação do assistente. Por exemplo, use uma das seguintes abordagens:  
  
-   Registrar e gerenciar as cadeias de caracteres de conexão usando o administrador ODBC.  
  
-   Edite a cadeia de caracteres de conexão e remova o nome da fonte de dados. A estrutura fornece ODBC como a fonte de dados; em tempo de execução ODBC exibe uma caixa de diálogo solicitando as informações de conexão necessários nome e qualquer outra fonte de dados.  
  
-   Forneça o nome da fonte de dados somente. ODBC solicita a ID de usuário e senha, se necessário. Por exemplo, antes de generalizar, a cadeia de caracteres de conexão tem esta aparência:  
  
    ```  
    CString CApp1Set::GetDefaultConnect()  
    {  
       return "ODBC;DSN=afx;Trusted_Connection=Yes;";  
    }  
    ```  
  
     Essa cadeia de caracteres de conexão Especifica uma conexão confiável, que usa a segurança integrada do Windows NT. Você deve evitar codificar uma senha ou especificar uma senha em branco, porque isso cria uma vulnerabilidade de segurança principal. Em vez disso, você pode dar `GetDefaultConnect` uma conexão nova cadeia de caracteres para que ele consulta para uma ID de usuário e senha.  
  
    ```  
    // User must select data source and supply user ID and password:  
        return "ODBC;";  
    // User ID and password required:  
        return "ODBC;DSN=mydb;";  
    // Password required (myuserid must be replaced with a valid user ID):  
        return "ODBC;DSN=mydb;UID=myuserid;";  
    // Hard-coded user ID and password (SECURITY WEAKNESS--AVOID):  
        return "ODBC;DSN=mydb;UID=sa;PWD=777;";  
    ```  
  
##  <a name="_core_connecting_to_a_specific_data_source"></a> Conectando a uma fonte de dados específicos  
 Para se conectar a uma fonte de dados específica, sua fonte de dados deve ser configurada com [administrador ODBC](../../data/odbc/odbc-administrator.md).  
  
#### <a name="to-connect-to-a-specific-data-source"></a>Para se conectar a uma fonte de dados específicos  
  
1.  Construir um `CDatabase` objeto.  
  
2.  Chamar o `OpenEx` ou **abrir** função de membro.  
  
 Para obter mais informações sobre como especificar a fonte de dados, se for diferente do especificado com um assistente, consulte [CDatabase::OpenEx](../../mfc/reference/cdatabase-class.md#openex) ou [CDatabase::Open](../../mfc/reference/cdatabase-class.md#open) no *MFC Referência*.  
  
##  <a name="_core_disconnecting_from_a_data_source"></a> Desconectando de uma fonte de dados  
 Você deve fechar qualquer conjunto de registros aberto antes de chamar o **fechar** função de membro `CDatabase`. Em conjuntos de registros associados a `CDatabase` do objeto que deseja fechar pendentes `AddNew` ou **editar** instruções são canceladas e todas as transações pendentes serão revertidas.  
  
#### <a name="to-disconnect-from-a-data-source"></a>Para se desconectar de uma fonte de dados  
  
1.  Chamar o `CDatabase` do objeto [fechar](../../mfc/reference/cdatabase-class.md#close) função de membro.  
  
2.  Destrua o objeto, a menos que você quiser reutilizá-lo.  
  
##  <a name="_core_reusing_a_cdatabase_object"></a> Reutilizando um objeto CDatabase  
 Você pode reutilizar uma `CDatabase` objeto após a desconexão, se você usá-lo para reconectar-se à mesma fonte de dados ou para se conectar a uma fonte de dados diferente.  
  
#### <a name="to-reuse-a-cdatabase-object"></a>Para reutilizar um objeto CDatabase  
  
1.  Feche a conexão original do objeto.  
  
2.  Em vez de destruir o objeto, chame seu `OpenEx` ou **abrir** novamente a função de membro.  
  
## <a name="see-also"></a>Consulte também  
 [Fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md)   
 [Fonte de dados: Determinando o esquema da fonte de dados (ODBC)](../../data/odbc/data-source-determining-the-schema-of-the-data-source-odbc.md)   
 [Classe CRecordset](../../mfc/reference/crecordset-class.md)