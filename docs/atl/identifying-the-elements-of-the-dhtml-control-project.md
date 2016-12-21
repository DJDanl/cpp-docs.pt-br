---
title: "Identificar os elementos do projeto de controle DHTML | Microsoft Docs"
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
ms.assetid: b627547a-3768-4346-9900-4b7a21fb8e27
caps.latest.revision: 11
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Identificar os elementos do projeto de controle DHTML
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A maioria dos códigos de controle DHTML exatamente como esse é criado para qualquer controle ATL. Para obter um entendimento básico do código genérico, trabalhar com o [tutorial da ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md), e leia as seções [Criando um projeto ATL](../atl/reference/creating-an-atl-project.md) e [conceitos básicos de ATL COM objetos](../atl/fundamentals-of-atl-com-objects.md).  
  
 Um controle DHTML é semelhante a qualquer controle ATL, exceto:  
  
-   Além das interfaces regulares que implementa um controle, ele implementa uma interface adicional que é usada para comunicação entre o código C\+\+ e a interface do usuário HTML \(UI\). A interface do usuário HTML chama código C\+\+ usando esta interface.  
  
-   Ele cria um recurso HTML para o controle da interface do usuário.  
  
-   Ele permite o acesso ao modelo de objeto DHTML através da variável de membro `m_spBrowser`, que é um ponteiro inteligente do tipo [IWebBrowser2](https://msdn.microsoft.com/en-us/library/aa752127.aspx). Use esse ponteiro para acessar qualquer parte do modelo de objeto DHTML.  
  
 O gráfico a seguir ilustra o relacionamento entre sua DLL, o controle DHTML, o navegador da Web e o recurso HTML.  
  
 ![De DHTMLcontrolProjectElements](../atl/media/vc52en1.png "vc52EN1")  
  
> [!NOTE]
>  Os nomes nesse gráfico são espaços reservados. Os nomes de seus recursos HTML e as interfaces expostas no seu controle baseiam\-se nos nomes de que atribuí\-los no Assistente de controle ATL.  
  
 Neste gráfico, os elementos são:  
  
-   **Minha DLL** DLL criado usando o Assistente de projeto ATL.  
  
-   **Controle DHTML** \(`m_spBrowser`\) controle o DHTML, criado usando o Assistente de objeto ATL. Esse controle acessa o objeto de navegador da Web e seus métodos por meio da interface do objeto de navegador da Web, **IWebBrowser2**. O próprio controle expõe duas interfaces a seguir, além de outras interfaces padrão necessários para um controle.  
  
    -   **IDHCTL1** a interface exposta pelo controle para uso somente pelo contêiner.  
  
    -   **IDHCTLUI1** a interface de distribuição para comunicação entre o código C\+\+ e a interface do usuário HTML. O navegador da Web usa a interface de expedição do controle para exibir o controle. Você pode chamar vários métodos dessa interface de expedição da interface de usuário do controle invocando `window.external`, seguido pelo nome do método nesta interface de distribuição que você deseja chamar. Você acessaria `window.external` de uma marca SCRIPT no HTML que compõe a interface do usuário para este controle. Para obter mais informações sobre como invocar métodos externos no arquivo de recurso, consulte [chamando código C\+\+ do DHTML](../Topic/Calling%20C++%20Code%20from%20DHTML.md).  
  
-   **IDR\_CTL1** a ID de recurso do recurso em HTML. Seu nome de arquivo, nesse caso, é DHCTL1UI.htm. O controle DHTML usa um recurso HTML que contém marcas HTML padrão e comandos de expedição de janela externa que você pode editar usando o editor de texto.  
  
-   **Navegador da web** o navegador exibe da interface do usuário do controle, com base em HTML no recurso de HTML. Um ponteiro para o navegador da Web **IWebBrowser2** interface está disponível no controle DHTML para permitir o acesso ao modelo de objeto DHTML.  
  
 O Assistente de controle ATL gera um controle com o código padrão no recurso HTML e o arquivo. cpp. Você pode compilar e executar o controle como gerado pelo assistente e, em seguida, exibir o controle no navegador da Web ou o contêiner de teste do controle ActiveX. A figura abaixo mostra o padrão de controle DHTML ATL com três botões exibidos no contêiner de teste:  
  
 ![Controle DHTML ATL](../Image/vc52EN2.gif "vc52EN2")  
  
 Consulte [Criando um controle de DHTML ATL](../atl/creating-an-atl-dhtml-control.md) para começar a criar um controle DHTML. Consulte [Testando propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md) para obter informações sobre como acessar o contêiner de teste.  
  
## Consulte também  
 [Suporte para controle DHTML](../atl/atl-support-for-dhtml-controls.md)