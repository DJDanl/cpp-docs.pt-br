---
title: "Administrador ODBC | Microsoft Docs"
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
  - "Administrador ODBC de administração"
  - "Administrador em ODBC"
  - "drivers [C++], ODBC"
  - "instalando ODBC"
  - "ODBC [C++], Administrador ODBC"
  - "Administrador ODBC [C++]"
  - "Fonte de dados ODBC [C++], Administrador ODBC"
  - "Drivers ODBC [C++], instalando"
ms.assetid: b8652790-3437-4e7d-bc83-6ea6981f008b
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Administrador ODBC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

O administrador ODBC registra e configurar [fontes de dados](../../data/odbc/data-source-odbc.md) disponível localmente para você ou por uma rede.  Informações de uso dos assistentes fornecida pelo administrador de ODBC para criar o código em seus aplicativos que conecta os usuários às fontes de dados.  
  
 Para configurar uma fonte de dados ODBC para uso com as classes de MFC ODBC ou as classes de \(DAO\) do objeto de acesso a dados de MFC, você deve primeiro registrar e configurar a fonte de dados.  Use o administrador ODBC para adicionar e remover fontes de dados.  Dependendo do driver ODBC do, você também pode criar novas fontes de dados.  
  
 O administrador ODBC é instalado durante a instalação.  Se você escolher a instalação de **Personalizar** e não selecionou nenhum drivers ODBC na caixa de diálogo de **Opções de Banco de Dados** , é necessário executar a instalação novamente para instalar os arquivos necessários.  
  
 Durante a instalação, selecione os drivers ODBC que deseja instalar.  Depois poderá instalar drivers adicionais fornecidos com o Visual C\+\+ usando o programa de instalação do Visual C\+\+.  
  
 Se você quiser instalar drivers ODBC que não são enviadas com Visual C\+\+, você deve executar o programa de instalação que acompanha o driver.  
  
#### Para instalar drivers ODBC fornecidos com o Visual C\+\+  
  
1.  Execute a instalação do CD de distribuição do Visual C\+\+.  
  
     A caixa de diálogo de abertura no programa de instalação será exibida.  
  
2.  Clique **Avançar** em cada caixa de diálogo até que você alcance a caixa de diálogo de **Opções de Instalação** .  **Personalizar**Selecione, e clique em `Next`.  
  
3.  Desmarque todas as caixas de seleção na caixa de diálogo de **Microsoft Visual C\+\+ Setup** exceto a caixa de seleção de **Opções de Banco de Dados** , e clique em **Detalhes** para exibir a caixa de diálogo de **Opções de Banco de Dados** .  
  
4.  Desmarque a caixa de seleção de **Microsoft Data Access Objects** , marque a caixa de seleção de **Microsoft ODBC Drivers** , e clique em **Detalhes**.  
  
     A caixa de diálogo de **Microsoft ODBC Drivers** é exibida.  
  
5.  Selecione os drivers que deseja instalar e, em seguida **OK** duas vezes em.  
  
6.  Clique **Avançar** nas caixas de diálogo restantes para iniciar a instalação.  A configuração notifica quando a instalação for concluída.  
  
 Quando os drivers instalados, você pode configurar a fonte de dados usando o administrador ODBC.  Você encontrará o ícone ODBC no painel de controle.  
  
## Consulte também  
 [Conectividade de banco de dados aberto \(ODBC\)](../Topic/Open%20Database%20Connectivity%20\(ODBC\).md)   
 [Fonte de dados \(ODBC\)](../../data/odbc/data-source-odbc.md)