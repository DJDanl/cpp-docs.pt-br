---
title: "Suporte do ATL para controles DHTML | Microsoft Docs"
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
  - "Controles HTML, suporte ATL"
  - "Controles DHTML, suporte ATL"
  - "controles DHTML"
ms.assetid: 4ba98098-da5d-4362-96ad-8372f816c307
caps.latest.revision: 10
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Suporte do ATL para controles DHTML
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Usando a ATL, você pode criar um controle com o recurso de HTML dinâmico \(DHTML\). Um controle DHTML ATL:  
  
-   Hospede o controle WebBrowser.  
  
-   Especifica o uso de HTML, a interface do usuário \(IU\) do controle DHTML.  
  
-   Acessa o objeto WebBrowser e seus métodos por meio de sua interface [IWebBrowser2](https://msdn.microsoft.com/en-us/library/aa752127.aspx).  
  
-   Gerencia a comunicação entre o código C\+\+ e HTML.  
  
 Um controle DHTML é semelhante a qualquer outro controle ATL, exceto o controle DHTML inclui uma interface de expedição adicionais. Consulte a figura em [identifica os elementos do projeto de controle DHTML](../atl/identifying-the-elements-of-the-dhtml-control-project.md) para obter uma ilustração as interfaces fornecidas no projeto DHTML padrão.  
  
 Você pode exibir o controle DHTML ATL em um navegador da Web ou outro contêiner, como o contêiner de teste do controle ActiveX.  
  
## Nesta seção  
 [Identificar os elementos do projeto de controle DHTML](../atl/identifying-the-elements-of-the-dhtml-control-project.md)  
 Descreve os elementos de um projeto de controle DHTML.  
  
 [Chamando código de C\+\+ do DHTML](../Topic/Calling%20C++%20Code%20from%20DHTML.md)  
 Fornece um exemplo de código C\+\+ de chamada de um controle DHTML.  
  
 [Criando um controle DHTML ATL](../atl/creating-an-atl-dhtml-control.md)  
 Lista as etapas para criar um controle DHTML.  
  
 [Testando o controle DHTML ATL](../atl/testing-the-atl-dhtml-control.md)  
 Mostra como criar e testar o projeto inicial do controle DHTML.  
  
 [Modificando o controle DHTML ATL](../atl/modifying-the-atl-dhtml-control.md)  
 Mostra como adicionar funcionalidade ao controle.  
  
 [Testando o controle alterado DHTML ATL](../atl/testing-the-modified-atl-dhtml-control.md)  
 Mostra como criar e testar a funcionalidade do controle adicionado.  
  
## Seções relacionadas  
 [ATL](../atl/active-template-library-atl-concepts.md)  
 Fornece links para tópicos conceituais sobre como programar usando o Active Template Library.