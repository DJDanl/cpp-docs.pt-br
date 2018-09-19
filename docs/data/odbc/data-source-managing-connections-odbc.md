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
ms.openlocfilehash: a8f5a57b1ef97b38b6756931038ec18045aea746
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46053720"
---
# <a name="data-source-managing-connections-odbc"></a>Fonte de dados: gerenciando conexões (ODBC)

Este tópico se aplica às classes ODBC do MFC.  
  
Este tópico explica:  
  
- [Como configurar uma fonte de dados](#_core_configuring_a_data_source).  
  
- [Como um ambiente multiusuários afeta uma fonte de dados e seus conjuntos de registros](#_core_working_in_a_multiuser_environment).  
  
- [Porque você generaliza uma cadeia de caracteres de conexão a uma fonte de dados](#_core_generalizing_the_connection_string).  
  
- [Como se conectar a uma fonte de dados](#_core_connecting_to_a_specific_data_source).  
  
- [Como desconectar de uma fonte de dados](#_core_disconnecting_from_a_data_source).  
  
- [Como reutilizar um objeto de CDatabase](#_core_reusing_a_cdatabase_object).  
  
Conectando a uma fonte de dados significa estabelecer comunicação com um DBMS para acessar os dados. Quando você se conectar a uma fonte de dados de um aplicativo por meio de um driver ODBC, o driver faz a conexão para você, localmente ou em uma rede.  
  
Você pode se conectar a qualquer fonte de dados para o qual você tem um driver ODBC. Os usuários do seu aplicativo também devem ter o mesmo driver ODBC para sua fonte de dados. Para obter mais informações sobre a redistribuição de drivers ODBC, consulte [redistribuir componentes ODBC para seus clientes](../../data/odbc/redistributing-odbc-components-to-your-customers.md).  
  
##  <a name="_core_configuring_a_data_source"></a> Configurando uma fonte de dados  

Administrador de ODBC é usado para configurar suas fontes de dados. Você também pode usar o administrador de ODBC após a instalação para adicionar ou remover fontes de dados. Quando você cria aplicativos, você pode direcionar os usuários para o administrador de ODBC para deixá-los adicionar fontes de dados, ou você pode criar essa funcionalidade em seu aplicativo fazendo chamadas diretas de instalação de ODBC. Para obter mais informações, consulte [administrador de ODBC](../../data/odbc/odbc-administrator.md).  
  
Você pode usar um arquivo do Excel como uma fonte de dados, e você precisará configurar o arquivo de forma que ele é registrado e apareça na **Selecionar fonte de dados** caixa de diálogo.  
  
#### <a name="to-use-an-excel-file-as-a-data-source"></a>Para usar um arquivo do Excel como uma fonte de dados  
  
1. Configure o arquivo com o administrador de fonte de dados ODBC.  
  
1. Sobre o **DSN de arquivo** , clique em **Add**.  
  
1. No **criar nova fonte de dados** caixa de diálogo, selecione um driver do Excel e, em seguida, clique em **próxima**.  
  
1. Clique em **procurar**e selecione o nome do arquivo a ser usado como uma origem de dados.  
  
> [!NOTE]
>  Talvez você precise selecionar **todos os arquivos** no menu suspenso para exibir os arquivos. xls.  
  
1. Clique em **Avançar**e em **Concluir**.  
  
1. No **instalação ODBC do Microsoft Excel** caixa de diálogo, selecione a versão do banco de dados e a pasta de trabalho.  
  
##  <a name="_core_working_in_a_multiuser_environment"></a> Trabalhando em um ambiente multiusuário  

Se vários usuários estiverem conectados a uma fonte de dados, eles podem alterar dados enquanto você manipula-os em conjuntos de registros. Da mesma forma, as alterações poderão afetar os conjuntos de registros de outros usuários. Para obter mais informações, consulte [conjunto de registros: como conjuntos de registros atualizam registros (ODBC)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md) e [transação (ODBC)](../../data/odbc/transaction-odbc.md).  
  
##  <a name="_core_generalizing_the_connection_string"></a> Generalizar a cadeia de caracteres de Conexão  

Os assistentes usam uma cadeia de caracteres de conexão padrão para estabelecer uma conexão a uma fonte de dados. Você pode usar essa conexão para exibir tabelas e colunas, enquanto você estiver desenvolvendo seu aplicativo. No entanto, essa cadeia de caracteres de conexão padrão pode não ser adequada para conexões de seus usuários com a fonte de dados por meio de seu aplicativo. Por exemplo, sua fonte de dados e o caminho para o local podem ser diferentes daquele usado no desenvolvimento de seu aplicativo. Nesse caso, você deve reimplementar a [crecordset:: Getdefaultconnect](../../mfc/reference/crecordset-class.md#getdefaultconnect) membro de função de uma forma mais genérica e descartar a implementação do assistente. Por exemplo, use uma das seguintes abordagens:  
  
- Registre e gerencie as cadeias de caracteres de conexão usando o administrador ODBC.  
  
- Edite a cadeia de caracteres de conexão e remova o nome da fonte de dados. A estrutura fornece ODBC como fonte de dados; em tempo de execução, o ODBC exibe uma caixa de diálogo solicitando as informações de nome e qualquer outra conexão necessária da fonte de dados.  
  
- Forneça o nome da fonte de dados somente. ODBC solicita a ID de usuário e senha, se necessário. Por exemplo, antes de generalizar, a cadeia de caracteres de conexão fica assim:  
  
    ```cpp  
    CString CApp1Set::GetDefaultConnect()  
    {  
       return "ODBC;DSN=afx;Trusted_Connection=Yes;";  
    }  
    ```  
  
     Essa cadeia de caracteres de conexão Especifica uma conexão confiável, que usa segurança integrada do Windows NT. Você deve evitar embutir uma senha ou especificar uma senha em branco, porque isso cria uma grande fraqueza de segurança. Em vez disso, você pode dar `GetDefaultConnect` uma nova conexão de cadeia de caracteres, de modo que ela peça uma identificação de usuário e senha.  
  
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
  
##  <a name="_core_connecting_to_a_specific_data_source"></a> Conectando a uma fonte de dados específicos  

Para se conectar a uma fonte de dados específicos, sua fonte de dados deve já ter sido configurada com [administrador de ODBC](../../data/odbc/odbc-administrator.md).  
  
#### <a name="to-connect-to-a-specific-data-source"></a>Para se conectar a uma fonte de dados específicos  
  
1. Construir um `CDatabase` objeto.  
  
1. Chamar sua `OpenEx` ou `Open` função de membro.  
  
Para obter mais informações sobre como especificar a fonte de dados se for algo diferente daquele especificado com um assistente, consulte [CDatabase:: Openex](../../mfc/reference/cdatabase-class.md#openex) ou [CDatabase:: Open](../../mfc/reference/cdatabase-class.md#open) no *MFC Referência*.  
  
##  <a name="_core_disconnecting_from_a_data_source"></a> Desconectando de uma fonte de dados  

Você deve fechar quaisquer conjuntos de registros abertos antes de chamar o `Close` função de membro de `CDatabase`. Em conjuntos de registros associados com o `CDatabase` objeto que deseja fechar, pendentes `AddNew` ou `Edit` instruções são canceladas e todas as transações pendentes são revertidas.  
  
#### <a name="to-disconnect-from-a-data-source"></a>Para desconectar de uma fonte de dados  
  
1. Chame o `CDatabase` do objeto [fechar](../../mfc/reference/cdatabase-class.md#close) função de membro.  
  
1. Destrua o objeto a menos que você deseje reutilizá-lo.  
  
##  <a name="_core_reusing_a_cdatabase_object"></a> Reutilizando um objeto de CDatabase  

Você pode reutilizar um `CDatabase` objeto depois de se desconectar dele, se você usá-lo para reconectar-se à mesma fonte de dados ou se conectar a uma fonte de dados diferentes.  
  
#### <a name="to-reuse-a-cdatabase-object"></a>Reutilizar um objeto de CDatabase  
  
1. Feche a conexão de original do objeto.  
  
1. Em vez de destruir o objeto, chame seu `OpenEx` ou `Open` novamente a função de membro.  
  
## <a name="see-also"></a>Consulte também  

[Fonte de dados (ODBC)](../../data/odbc/data-source-odbc.md)<br/>
[Fonte de dados: determinando o esquema da fonte de dados (ODBC)](../../data/odbc/data-source-determining-the-schema-of-the-data-source-odbc.md)<br/>
[Classe CRecordset](../../mfc/reference/crecordset-class.md)