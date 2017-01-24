---
title: "ASP, o assistente do componente da p&#225;gina de ATL Active Server | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "vc.codewiz.class.atl.asp.asp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente do componente da página de ATL Active Server, ASP"
ms.assetid: 4d8cafd6-5e12-4461-8911-29288896af3c
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# ASP, o assistente do componente da p&#225;gina de ATL Active Server
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Use esta página do assistente componente da página de ATL Active Server para especificar configurações opcionais para manipular informações e para indicar relacionado ao seu componente ASP.  
  
 **Optional methods**  
 Adiciona métodos opcionais ASP, **OnStartPage** e **OnEndPage**, ao objeto.  Esta opção deve ser selecionada para definir todos os objetos do tipo intrínseco as páginas do Active Server.  Por padrão, é selecionada.  
  
-   **OnStartPage\/OnEndPage** [OnStartPage](https://msdn.microsoft.com/en-us/library/ms691624.aspx) é chamado na primeira vez que o script tenta acessar o objeto.  **OnEndPage** é chamado quando o objeto é concluído que processa o script.  
  
 **Intrinsic object**  
 Você deve selecionar a opção de **OnStartPage\/OnEndPage** definir todos os objetos do tipo intrínseco ASP.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**Solicitação**|Fornece acesso ao objeto intrínseco de **Solicitar** de páginas do Active Server.  O objeto de solicitação é usado para passar uma solicitação HTTP.|  
|**Resposta**|Fornece acesso ao objeto intrínseco de **Resposta** de páginas do Active Server.  Em resposta a uma solicitação, o objeto de resposta envia informações para o navegador para exibir ao usuário.|  
|**Sessão**|Fornece acesso ao objeto intrínseco de **Sessão** de páginas do Active Server.  O objeto de **Sessão** mantém informações sobre a sessão atual do usuário, incluindo armazenar e recuperar informações de estado.|  
|**Application**|Fornece acesso ao objeto intrínseco de **Aplicativo** de páginas do Active Server.  O objeto de **Aplicativo** gerenciar o estado que é compartilhado entre vários objetos ASP.|  
|**Server**|Fornece acesso ao objeto intrínseco de **Servidor** de páginas do Active Server.  O objeto de **Servidor** permite que você crie outros objetos ASP.|  
  
## Consulte também  
 [Assistente do componente da página de ATL Active Server](../../atl/reference/atl-active-server-page-component-wizard.md)   
 [Componente da página de ATL Active Server](../../atl/reference/adding-an-atl-active-server-page-component.md)