---
title: "Adicionando um consumidor de ATL o OLE DB | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Os clientes de ATL o OLE DB"
  - "Projetos de ATL, adicionando os consumidores do OLE DB ATL"
  - "OLE DB, adicionando o consumidor de ATL OLE DB para projetos"
ms.assetid: f940a513-4e42-4148-b521-dd0d7dc89fa2
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando um consumidor de ATL o OLE DB
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Use o assistente para adicionar um consumidor de ATL o OLE DB a um projeto.  Um consumidor de ATL o OLE DB consiste nas associações do OLE DB do acessador de uma classe e dados necessárias para acessar uma fonte de dados.  O projeto deve ter sido criado como um aplicativo de ATL COM, ou como um aplicativo MFC ou do Win32 que contém o suporte de ATL \(que o assistente do consumidor de ATL o OLE DB adiciona automaticamente\).  
  
 **Observação** Você pode adicionar um consumidor do OLE DB a um projeto MFC.  Se você fizer isso, o assistente do consumidor de ATL o OLE DB adiciona suporte necessário COM para seu projeto.  Isso pressupõe que quando você criou o projeto MFC, você marcar a caixa de seleção de **Controles ActiveX** \(na página de **recursos avançados** do assistente de projeto do aplicativo MFC\), que é verificada por padrão.  Selecione esta opção garante que o aplicativo chama **CoInitialize** e **CoUninitialize**.  Se não tiver selecionado **Controles ActiveX** quando você criou o projeto MFC, você precisará chamar **CoInitialize** e **CoUninitialize** no seu código principal.  
  
### Para adicionar um consumidor de ATL o OLE DB ao seu projeto  
  
1.  Em o modo da classe, clique com o botão direito do mouse no projeto.  Em o menu de atalho, clique **Adicionar** e clique em **Adicionar Classe**.  
  
2.  Em a pasta Visual C\+\+, clique duas vezes no ícone de **ATL OLE DB Consumer** ou selecione e clique em **Abrir**.  
  
     O assistente do consumidor de ATL o OLE DB abre.  
  
3.  Defina configurações como descrito em [Assistente do consumidor do OLE DB ATL](../../atl/reference/atl-ole-db-consumer-wizard.md).  
  
4.  Clique em **Finish** para fechar o assistente.  O código recém\-criado do consumidor do OLE DB será inserido no seu projeto.  
  
## Consulte também  
 [Adicionando funcionalidade com assistentes de código](../../ide/adding-functionality-with-code-wizards-cpp.md)