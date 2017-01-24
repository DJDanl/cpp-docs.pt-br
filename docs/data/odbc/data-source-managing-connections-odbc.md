---
title: "Fonte de dados: gerenciando conex&#245;es (ODBC) | Microsoft Docs"
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
  - "cadeias de conexão [C++], generalizando"
  - "conexões [C++], fonte de dados"
  - "fonte de dados [C++], conectando a"
  - "conexões de banco de dados [C++], criando"
  - "conexões de banco de dados [C++], Classes MFC ODBC"
  - "bancos de dados [C++], conectando a"
  - "desconectando de fontes de dados"
  - "generalizando cadeias de conexão"
  - "Método GetDefaultConnect"
  - "ODBC [C++], desconectando de fontes de dados"
  - "Conexões ODBC [C++], configurando"
  - "Conexões ODBC [C++], conectando a fonte de dados"
  - "Conexões ODBC [C++], desconectando"
  - "Fonte de dados ODBC [C++], conexões"
  - "Fonte de dados ODBC [C++], ambientes multiusuário"
ms.assetid: c0adbcdd-c000-40c6-b199-09ffdc7b6ef2
caps.latest.revision: 10
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fonte de dados: gerenciando conex&#245;es (ODBC)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico se aplica às classes ODBC do MFC.  
  
 Este tópico explica:  
  
-   [Como configurar uma fonte de dados](#_core_configuring_a_data_source).  
  
-   [Como um ambiente multiusuários afeta uma fonte de dados e seus conjuntos de registros](#_core_working_in_a_multiuser_environment).  
  
-   [Porque você generaliza uma cadeia de conexão para uma fonte de dados](#_core_generalizing_the_connection_string).  
  
-   [Como conectar\-se a uma fonte de dados](#_core_connecting_to_a_specific_data_source).  
  
-   [Como desconectar\-se de uma fonte de dados](#_core_disconnecting_from_a_data_source).  
  
-   [Como reutilizar um objeto CDatabase](#_core_reusing_a_cdatabase_object).  
  
 Conectar a uma fonte de dados significa estabelecer comunicação com um DBMS para acessar os dados.  Quando você se conecta a uma fonte de dados de um aplicativo através de um driver ODBC, o driver fazer a conexão para você, localmente ou através de uma rede.  
  
 É possível se conectar a qualquer fonte de dados para a qual você tem um driver ODBC.  Os usuários do seu aplicativo também devem ter o mesmo driver ODBC para sua fonte de dados.  Para obter mais informações sobre a redistribuição de drivers ODBC, consulte [Redistribuir componentes ODBC para seus clientes](../../data/odbc/redistributing-odbc-components-to-your-customers.md).  
  
##  <a name="_core_configuring_a_data_source"></a> Configurando uma fonte de dados  
 O Administrador de ODBC é usado para configurar suas fontes de dados.  Você também pode usar o administrador de ODBC após a instalação para adicionar ou remover fontes de dados.  Ao criar aplicativos, você pode direcionar os usuários para o administrador de ODBC para deixá\-los adicionar fontes de dados ou pode criar essa funcionalidade em seu aplicativo fazendo chamadas diretas de instalação de ODBC.  Para obter mais informações, consulte [Administrador de ODBC](../../data/odbc/odbc-administrator.md).  
  
 É possível usar um arquivo do Excel como uma fonte de dados, e é necessário configurar o arquivo para que seja registrado e apareça na caixa de diálogo **Selecionar Fonte de Dados**.  
  
#### Para usar um arquivo do Excel como uma fonte de dados  
  
1.  Configure o arquivo com o Administrador de Fonte de Dados ODBC.  
  
2.  Na guia **DSN de Arquivo**, clique em **Adicionar**.  
  
3.  Na caixa de diálogo **Criar Nova Fonte de Dados**, selecione um driver do Excel e clique em **Avançar**.  
  
4.  Clique em **Procurar** e selecione o nome do arquivo a ser usado como uma fonte de data.  
  
> [!NOTE]
>  Pode ser necessário selecionar **Todos os Arquivos** no menu suspenso para exibir os arquivos .xls.  
  
1.  Clique em **Avançar** e em **Concluir**.  
  
2.  Na caixa de diálogo **Instalação ODBC para Microsoft Excel**, selecione a versão e a pasta de trabalho do banco de dados.  
  
##  <a name="_core_working_in_a_multiuser_environment"></a> Trabalhar em um ambiente multiusuário  
 Se vários usuários estão conectados a uma fonte de dados, eles podem modificar dados enquanto você manipula\-os em seus conjuntos de registros.  Da mesma forma, suas alterações poderão afetar os conjuntos de registros de outros usuários.  Para obter mais informações, consulte [Conjunto de registros: Como registros de conjuntos atualizam Registros \(ODBC\)](../../data/odbc/recordset-how-recordsets-update-records-odbc.md) e [Transação \(ODBC\)](../../data/odbc/transaction-odbc.md).  
  
##  <a name="_core_generalizing_the_connection_string"></a> Generalizar a Cadeia de conexão  
 Os assistentes usam uma cadeia de conexão padrão para estabelecer uma conexão com uma fonte de dados.  Você usa essa conexão para exibir tabelas e colunas enquanto estiver desenvolvendo seu aplicativo.  No entanto, essa cadeia de conexão padrão pode não ser adequada às conexões dos seus usuários para a fonte de dados por meio do aplicativo.  Por exemplo, sua fonte de dados e o caminho para a sua localização podem ser diferentes daqueles usados ao desenvolver seu aplicativo.  Nesse caso, você deve reimplementar a função de membro [CRecordset::GetDefaultConnect](../Topic/CRecordset::GetDefaultConnect.md) em uma forma mais genérica e descartar a implementação do assistente.  Por exemplo, use uma das seguintes abordagens:  
  
-   Registre e gerencie as cadeias de conexão usando o Administrador de ODBC.  
  
-   Editar a cadeia de conexão e remova o nome da fonte de dados.  A estrutura fornece ODBC como a fonte de dados; em tempo de execução, o ODBC exibe uma caixa de diálogo que solicita o nome da fonte de dados e qualquer outra informação de conexão necessária.  
  
-   Forneça somente o nome da fonte de dados.  ODBC solicita a identificação de usuário e a senha, se necessário.  Por exemplo, antes de generalizar, a cadeia de conexão tem esta aparência:  
  
    ```  
    CString CApp1Set::GetDefaultConnect()  
    {  
       return "ODBC;DSN=afx;Trusted_Connection=Yes;";  
    }  
    ```  
  
     Essa cadeia de conexão especifica uma conexão confiável, que usa segurança integrada do Windows NT.  Você deve evitar a codificação de uma senha ou a especificação de uma senha em branco, uma vez que isso cria uma grande fraqueza de segurança.  Em vez disso, você pode dar a `GetDefaultConnect` uma nova cadeia de conexão para que ela peça uma identificação de usuário e senha.  
  
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
  
##  <a name="_core_connecting_to_a_specific_data_source"></a> Conectando\-se a uma fonte de dados específica  
 Para se conectar a uma fonte de dados específica, sua fonte de dados deve ter sido configurada com o [Administrador de ODBC](../../data/odbc/odbc-administrator.md).  
  
#### Para conectar a uma fonte de dados específica  
  
1.  Construa um objeto `CDatabase`.  
  
2.  Chame sua função de membro `OpenEx` ou **Open**.  
  
 Para obter mais informações sobre como especificar a fonte de dados se for algo diferente do que você especificou a um assistente, consulte [CDatabase::OpenEx](../Topic/CDatabase::OpenEx.md) ou [CDatabase::Open](../Topic/CDatabase::Open.md) na *Referência MFC*.  
  
##  <a name="_core_disconnecting_from_a_data_source"></a> Desconectando\-se de uma fonte de dados  
 Você deve fechar os conjuntos de registros abertos antes de chamar a função membro **Fechar** de `CDatabase`.  Em conjuntos de registros associados com o objeto `CDatabase` que você deseja fechar, quaisquer instruções pendentes `AddNew` ou **Editar** são canceladas e todas as transações pendentes são revertidas.  
  
#### Para desconectar\-se de uma fonte de dados  
  
1.  Chame a função de membro de [Close](../Topic/CDatabase::Close.md) do objeto `CDatabase`.  
  
2.  Destrua o objeto, a menos que você queira reutilizá\-lo.  
  
##  <a name="_core_reusing_a_cdatabase_object"></a> Reutilizando um objeto de CDatabase  
 É possível reutilizar um objeto de `CDatabase` após se desconectar dele, independente se usá\-lo para reconectar à mesma fonte de dados ou para se conectar a uma fonte de dados diferente.  
  
#### Para reutilizar um objeto de CDatabase  
  
1.  Feche a conexão original do objeto.  
  
2.  Em vez de destruir o objeto, chame a função de membro `OpenEx` ou **Abrir** novamente.  
  
## Consulte também  
 [Fonte de dados \(ODBC\)](../../data/odbc/data-source-odbc.md)   
 [Fonte de dados: determinando o esquema da fonte de dados \(ODBC\)](../../data/odbc/data-source-determining-the-schema-of-the-data-source-odbc.md)   
 [Classe de CRecordset](../Topic/CRecordset%20Class.md)