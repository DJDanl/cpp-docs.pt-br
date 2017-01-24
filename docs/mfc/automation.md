---
title: "Automa&#231;&#227;o | Microsoft Docs"
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
  - "Servidores de automação, sobre servidores de automação"
  - "clientes de automação"
  - "controle programático [C++]"
  - "Propriedades [MFC], automação"
  - "O MFC [C++], COM suporte"
  - "Automação OLE"
  - "Automação"
  - "servidores [C++], automação"
  - "Clientes de automação"
  - "aplicativos de exemplo [MFC], automação"
  - "métodos [MFC]"
  - "passando parâmetros de automação"
  - "Método Automation"
  - "Automação, passando parâmetros"
  - "Propriedade de automação"
  - "COM MFC, automação"
  - "métodos [MFC], automação"
ms.assetid: 329117f0-c1aa-4680-a901-bfb71277dfba
caps.latest.revision: 13
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Automa&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Automação \(anteriormente conhecida como automação OLE\) torna possível para um aplicativo para manipular objetos implementados em outro aplicativo ou expor objetos para que eles podem ser manipulados.  
  
 Um [servidor de automação](../mfc/automation-servers.md) é um aplicativo \(um tipo de servidor COM\) que expõe sua funcionalidade por meio de interfaces COM para outros aplicativos, chamados [clientes de automação](../mfc/automation-clients.md). A exposição permite que os clientes de automação automatizar determinadas funções diretamente acessar objetos e usando os serviços que eles fornecem.  
  
 Clientes e servidores de automação usam interfaces COM que sempre são derivados de `IDispatch` e levar e retornar um conjunto específico de tipos de dados, chamados de tipos de automação. Você pode automatizar qualquer objeto que expõe uma interface de automação, fornecendo métodos e propriedades que você pode acessar de outros aplicativos. Automação está disponível para objetos OLE e COM. O objeto automatizado pode ser local ou remoto \(em outra máquina acessível em uma rede\). Portanto, há duas categorias de automação:  
  
-   Automação \(local\).  
  
-   [Automação remota](../mfc/remote-automation.md) \(em uma rede, usando DCOM ou o DCOM\).  
  
 Expondo objetos é útil quando os aplicativos fornecem funcionalidades úteis para outros aplicativos. Por exemplo, um controle ActiveX é um tipo do servidor de automação. o aplicativo que hospeda o controle ActiveX é o cliente de automação do controle.  
  
 Como outro exemplo, um processador de texto pode expor sua funcionalidade de verificação ortográfica para outros programas. Exposição de objetos permite que fornecedores de aprimorar seus aplicativos usando a funcionalidade pronta de outros aplicativos. Dessa forma, a automação se aplica alguns dos princípios de programação orientada a objeto, como a capacidade de reutilização e encapsulamento, no nível dos próprios aplicativos.  
  
 Mais importante é o suporte a automação fornece aos usuários e fornecedores de soluções. Expondo a funcionalidade do aplicativo por meio de uma interface comum e bem definida, automação torna possível criar soluções abrangentes em uma única geral linguagem de programação, como o Microsoft Visual Basic, em vez de em idiomas diferentes macro específicas do aplicativo.  
  
 Muitos aplicativos comerciais, como o Microsoft Excel e Microsoft Visual C\+\+, permitem automatizar grande parte de sua funcionalidade. Por exemplo, no Visual C\+\+, você pode escrever [VBScript](vtoriVBScript) macros para automatizar compilações, aspectos de código editando ou tarefas de depuração.  
  
##  <a name="_core_passing_parameters_in_automation"></a> Passando parâmetros de automação  
 Uma dificuldade na criação de métodos de automação está ajudando a fornecer um mecanismo uniforme "seguro" para passar dados entre clientes e servidores de automação. Automação usa o **VARIANT** tipo de dados. O **VARIANT** tipo é uma união marcada. Ele tem um membro de dados para o valor \(essa é uma união C\+\+ anônima\) e um membro de dados que indica o tipo de informações armazenadas na União. O **VARIANT** tipo oferece suporte a vários tipos de dados padrão: 2 e 4 bytes, números de ponto flutuante de 4 e 8 bytes, cadeias de caracteres e valores booleanos. Além disso, ele oferece suporte a `HRESULT` \(códigos de erro OLE\), **moeda** \(um ponto fixo tipo numérico\), e **data** tipos \(absoluta data e hora\), bem como ponteiros para **IUnknown** e `IDispatch` interfaces.  
  
 O **VARIANT** tipo é encapsulado no [COleVariant](../mfc/reference/colevariant-class.md) classe. O suporte **moeda** e **data** encapsuladas em classes de [COleCurrency](../Topic/COleCurrency%20Class.md) e [COleDateTime](../atl-mfc-shared/reference/coledatetime-class.md) classes.  
  
## Exemplos de automação  
  
-   [AUTOCLIK](../top/visual-cpp-samples.md) usar esse exemplo para aprender técnicas de automação e como base para automação remota de aprendizado.  
  
-   [ACDUAL](../top/visual-cpp-samples.md) adiciona interfaces duplas para um aplicativo de servidor de automação.  
  
-   [CALCDRIV](../top/visual-cpp-samples.md) aplicativo de cliente de automação, orientando MFCCALC.  
  
-   [INPROC](../top/visual-cpp-samples.md) demonstra um aplicativo de servidor em processo de automação.  
  
-   [IPDRIVE](../top/visual-cpp-samples.md) aplicativo de cliente de automação, orientando INPROC.  
  
-   [MFCCALC](../top/visual-cpp-samples.md) demonstra um aplicativo de cliente de automação.  
  
## O que você deseja saber mais sobre?  
  
-   [Clientes de automação](../mfc/automation-clients.md)  
  
-   [Servidores de automação](../mfc/automation-servers.md)  
  
-   [Automação remota](../mfc/remote-automation.md)  
  
-   [OLE](../mfc/ole-in-mfc.md)  
  
-   [Tecnologia ativa](../mfc/mfc-com.md)  
  
## O que você deseja fazer?  
  
-   [Adicionar uma classe de automação](../mfc/automation-servers.md)  
  
-   [Usar bibliotecas de tipo](../Topic/Automation%20Clients:%20Using%20Type%20Libraries.md)  
  
-   [Passar parâmetros de automação](#_core_automation_topics)  
  
-   [Servidores de automação de acesso](../mfc/automation-servers.md)  
  
-   [Clientes de automação de gravação em C\+\+](../mfc/automation-clients.md)  
  
## Consulte também  
 [MFC COM](../mfc/mfc-com.md)