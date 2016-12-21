---
title: "Usando vincula&#231;&#227;o de dados RDO no Visual C++ | Microsoft Docs"
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
  - "associação de dados [C++], RDO"
  - "RDO [C++], associação de dados"
  - "Controle RemoteData RDO, associando dados no Visual C++"
  - "Controle RemoteData, associando dados no Visual C++"
ms.assetid: 02b9cfe7-7bbe-4a01-b075-e28d9536ac4b
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando vincula&#231;&#227;o de dados RDO no Visual C++
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Para usar RDO que databinding no Visual C\+\+, você precisa adicionar um controle e o ponto de RemoteData RDO a uma fonte de dados e uma origem de registro \(consulta SQL\).  Você também precisa adicionar um controle associada a dados de RDO, aponte para um controle de RemoteData RDO, e selecione os campos para associar a origem do registro de controle de RemoteData RDO.  
  
### Para usar RDO que databinding no Visual C\+\+  
  
1.  Configurar [Fonte de dados ODBC](../../data/ado-rdo/odbc-connections.md), se ainda não tiver feito isso.  
  
2.  Crie um aplicativo da caixa de diálogo MFC ou o aplicativo MFC Formview usando o assistente de aplicativo MFC.  
  
3.  Adicionar o controle do Microsoft RemoteData \(controle de RemoteData RDO\) para a caixa de diálogo; consulte [Inserindo o controle em um aplicativo do Visual C\+\+](../../data/ado-rdo/inserting-the-control-into-a-visual-cpp-application.md).  
  
4.  Aponte o controle de RemoteData RDO à fonte de dados ODBC.  
  
    1.  Clique com o botão direito do mouse no controle, e clique em **Propriedades**.  
  
    2.  Clique na guia de **Controle** .  
  
    3.  Definir **DataSource** à fonte de dados ODBC.  
  
    4.  Quando necessário, defina o nome de usuário e a senha da fonte de dados ODBC.  Ele deixe em branco se a fonte de dados não requer um nome de usuário ou senha.  
  
    5.  Digite uma consulta SQL na propriedade de **SQL** .  Os controles vinculadas a dados podem ser associadas aos resultados dessa consulta.  
  
5.  Definir outras propriedades de controle de RemoteData RDO quando necessário.  
  
6.  Adicionar um controle associada a dados.  Por exemplo, adicionar **DBGrid Control** e define a fonte de dados da seguinte maneira.  
  
    1.  Clique com o botão direito do mouse no DBGrid, e clique em **Propriedades**.  
  
    2.  Clique na guia de **Tudo** .  
  
    3.  Defina a propriedade de **DataSource** ao controle de RemoteData RDO.  Clique na caixa de combinação suspensa da propriedade e localizar a ID de controle de RemoteData RDO.  O nome padrão da ID é IDC\_REMOTEDATACTL1.  
  
7.  Para executar em modo de teste, use CTRL\+T.  Você pode rolar pelos dados.  Pressione a tecla ESC de ou fechar a caixa de diálogo para finalizar o modo de teste.  
  
 Se você compila e executa o programa, você pode rolar também com os dados.  
  
## Consulte também  
 [Associação de dados RDO](../../data/ado-rdo/rdo-databinding.md)   
 [Vinculação de dados com controles ActiveX no Visual C\+\+](../../data/ado-rdo/databinding-with-activex-controls-in-visual-cpp.md)