---
title: "Usando vincula&#231;&#227;o de dados ADO no Visual C++ | Microsoft Docs"
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
  - "ADO [C++], associação de dados"
  - "controles associados [C++], ADO"
  - "controles associados [C++], RDO"
  - "associação de dados [C++], ADO"
  - "associação de dados [C++], RDO"
ms.assetid: ad193919-3437-41ee-b41c-9d353f6274e5
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando vincula&#231;&#227;o de dados ADO no Visual C++
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Usar o ADO que databinding no Visual C\+\+ exige as seguintes etapas:  
  
-   Adicionar um controle de dados ADO.  
  
-   Aponte para uma fonte de dados.  
  
-   Especifique a origem do registro \(linguagem de consulta SQL ou de recuperação de dados\).  
  
-   Adicionar um controle associada a dados do ADO.  
  
-   Conecte o controle associada a dados ao controle de dados ADO.  
  
-   Selecione os campos para associar a origem do registro de controle de dados ADO.  
  
### Para usar o ADO que databinding no Visual C\+\+  
  
1.  Crie um aplicativo da caixa de diálogo MFC ou o aplicativo MFC Formview usando o assistente de aplicativo MFC.  
  
2.  Adicionar o controle de dados do Microsoft ADO para a caixa de diálogo; consulte [Inserindo o controle em um aplicativo do Visual C\+\+](../../data/ado-rdo/inserting-the-control-into-a-visual-cpp-application.md).  
  
3.  Apontar o controle de dados ADO a sua fonte de dados OLE DB.  
  
    1.  Clique com o botão direito do mouse no controle de dados ADO, e clique em **Propriedades**.  
  
    2.  Na guia de **Controle** , clique **Usar cadeia de conexão**.  Você pode usar o provedor fornecido ou poderá excluí\-lo.  
  
    3.  Clique em **Construir**.  Se você excluir um provedor de **Usar cadeia de conexão**, agora você pode definir um.  Depois que você definir o provedor, acessar as propriedades do controle de dados ADO novamente, e selecione **Compilar** novamente para continuar.  
  
         Se um provedor está definido em **Usar cadeia de conexão** antes de selecionar **Compilar**, você pode definir as propriedades de vínculo de dados.  Isso exibe o assistente inicial de dados.  
  
    4.  Alterar **Provedor** se necessário, e defina **Local** e valores de **Fonte de dados** , conforme apropriado para seu provedor.  Por exemplo, se você estiver usando um provedor do SQL Server, **Local** especifica o servidor de base de dados e **Fonte de dados** especifica o base de dados.  Se você estiver usando um provedor ODBC, **Fonte de dados** corresponde a um DSN ODBC.  
  
    5.  Clique na guia de **Autenticação** , e defina valores para **Nome de usuário** e **Senha**, se solicitado pela fonte de dados.  
  
    6.  Clique na guia de **Conexão** , e clique em **Testar Conexão** para testar a fonte de dados.  Role até o final da janela de resultados para ver se o teste não foi realizada com êxito.  Se com falha, verifique a configuração da fonte de dados.  Os erros comuns incluem senhas válidas e valores incorretos para os campos de **Local** e de **Fonte de dados** .  
  
    7.  Feche o assistente inicial de dados e retornar à folha de propriedade do controle de dados ADO.  
  
4.  Na guia de `RecordSource` , insira uma consulta de **Command Text \(SQL\)**.  Os controles vinculadas a dados podem ser associadas aos resultados dessa consulta.  A consulta é geralmente SQL.  No entanto, alguns provedores OLE DB não usam SQL.  
  
5.  Definir todas as outras propriedades holdout de dados ADO quando necessário e fecha a folha de propriedade do controle de dados ADO.  
  
6.  Adicionar um controle associada a dados.  Por exemplo, adicionar o controle de DataGrid, que é diferente do controle de DBGrid RDO.\)  
  
7.  Definir as propriedades de DataGrid.  
  
    1.  Clique com o botão direito do mouse no DataGrid, e clique em **Propriedades**.  
  
    2.  Clique na guia de **Tudo** , e defina a propriedade de **DataSource** ao controle de dados ADO.  Clique na lista suspensa de **DataSource** e localizar a ID do controle de dados ADO.  O nome padrão da ID é IDC\_ADODC1.  
  
8.  Para executar em modo de teste, pressione CTRL\+T.  Você pode rolar pelos dados.  Pressione a tecla ESC de ou fechar a caixa de diálogo para finalizar o modo de teste.  
  
 Se você compila e executa o programa, você pode rolar também com os dados.  
  
## Consulte também  
 [Associação de dados ADO](../../data/ado-rdo/ado-databinding.md)   
 [Vinculação de dados com controles ActiveX no Visual C\+\+](../../data/ado-rdo/databinding-with-activex-controls-in-visual-cpp.md)