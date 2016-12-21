---
title: "Criando um consumidor sem usar um assistente | Microsoft Docs"
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
  - "Consumidores OLE DB, criando"
ms.assetid: e8241cfe-5faf-48f8-9de3-241203de020b
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Criando um consumidor sem usar um assistente
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O exemplo a seguir assume que você está adicionando suporte do consumidor OLE DB a um projeto existente de ATL.  Se você deseja adicionar suporte ao consumidor OLE DB a um aplicativo de MFC, execute o assistente de aplicativo MFC, que cria qualquer suporte necessário e invoca as rotinas de MFC necessárias para executar o aplicativo.  
  
 Para adicionar suporte ao consumidor OLE DB sem usar o assistente do consumidor de ATL OLE DB:  
  
-   Em seu arquivo de Stdafx.h, acrescente as seguintes instruções de `#include` :  
  
    ```  
    #include <atlbase.h>  
    #include <atldbcli.h>  
    #include <atldbsch.h> // if you are using schema templates  
    ```  
  
 Programaticamente, um consumidor executa normalmente a seguinte sequência de operações:  
  
-   Crie uma classe de registro do usuário que associa as colunas para variáveis locais.  Neste exemplo, `CMyTableNameAccessor` é a classe de registro do usuário \(consulte [Registros de usuário](../../data/oledb/user-records.md)\).  Esta classe contém o mapa da coluna e o mapa do parâmetro.  Declare um membro de dados na classe de registro do usuário para cada campo que você especifica em seu mapa de coluna; para cada um desses membros de dados, também declarar um membro de dados de status e um membro de dados de comprimento.  Para obter mais informações, consulte [Coloque membros de dados de status em acessadores script gerados](../Topic/Field%20Status%20Data%20Members%20in%20Wizard-Generated%20Accessors.md).  
  
    > [!NOTE]
    >  Se você escrever seu próprio consumidor, variáveis de dados devem vir antes de variáveis de status e comprimento.  
  
-   Criar uma fonte de dados e uma sessão.  Decida quais tipo de acessador e de conjunto de linhas para usar e criar uma instância em um conjunto de linhas usando [CCommand](../../data/oledb/ccommand-class.md) ou [CTable](../../data/oledb/ctable-class.md):  
  
    ```  
    CDataSource ds;  
    CSession ss;  
    class CMyTableName : public CCommand<CAccessor<CMyTableNameAccessor> >  
    ```  
  
-   Chame **CoInitialize** para inicializar o.  Isso normalmente é chamado no código principal.  Por exemplo:  
  
    ```  
    HRESULT hr = CoInitialize(NULL);  
    ```  
  
-   Chame [CDataSource::Open](../../data/oledb/cdatasource-open.md) ou uma de suas variações.  
  
-   Abra uma conexão com a fonte de dados, abra a sessão, e abra e inicializar o conjunto de linhas \(e se um comando, também o executa\):  
  
    ```  
    hr = ds.Open();  
    hr = ss.Open(ds);  
    hr = rs.Open();            // (Open also executes the command)  
    ```  
  
-   Opcionalmente, defina as propriedades de conjunto de linhas usando `CDBPropSet::AddProperty` e transmiti\-los como um parâmetro para `rs.Open`.  Para obter um exemplo de como isso é feito, consulte GetRowsetProperties em [Métodos gerados para o consumidor\)](../Topic/Consumer%20Wizard-Generated%20Methods.md).  
  
-   Agora você pode usar o conjunto de linhas para recuperar e manipular os dados.  
  
-   Quando o aplicativo for feito, fechar a conexão, a sessão, e o conjunto de linhas:  
  
    ```  
    rs.Close();  
    ss.Close();  
    ds.Close();  
    ```  
  
     Se você estiver usando um comando, talvez você queira chamar `ReleaseCommand` depois de **Fechar**.  O exemplo de código em [CCommand::Close](../Topic/CCommand::Close.md) mostra como chamar **Fechar** e `ReleaseCommand`.  
  
-   Chame para **CoUnInitialize** não inicializar COM.  Isso normalmente é chamado no código principal.  
  
    ```  
    CoUninitialize();  
    ```  
  
## Consulte também  
 [Criando um consumidor de banco de dados OLE](../../data/oledb/creating-an-ole-db-consumer.md)