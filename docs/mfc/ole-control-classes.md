---
title: "Classes de controle OLE | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.classes.ole"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classes ActiveX [C++]"
  - "Classes de controle ActiveX [C++]"
  - "Controles ActiveX [C++], Classes de controle OLE"
  - "controles personalizados [MFC], Classes "
  - "Classes de controle OLE [C++]"
  - "Controles OLE [C++], Classes "
  - "classes de componentes reutilizáveis"
ms.assetid: 96495ec3-319e-4163-b839-1af0428ed9dd
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classes de controle OLE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essas são as classes principais que você usa para gravar controladores OLE.  A classe de `COleControlModule` em um módulo de controlador OLE é como a classe de [CWinApp](../mfc/reference/cwinapp-class.md) em um aplicativo.  Cada módulo implementa um ou vários controladores; OLE esses controles são representados por objetos de `COleControl` .  Esses controles se comunicam com seus contêineres usando objetos de `CConnectionPoint` .  
  
 As classes de `CPictureHolder` e de `CFontHolder` encapsulam interfaces COM para imagens e fontes, quando as classes de `COlePropertyPage` e de `CPropExchange` o ajudarem a implementar páginas de propriedades e persistência da propriedade para o controle.  
  
 [COleControlModule](../mfc/reference/colecontrolmodule-class.md)  
 Substitui a classe de `CWinApp` para o módulo de controlador OLE.  Derivar da classe de `COleControlModule` para desenvolver um objeto do módulo de controlador OLE.  O fornece funções de membro para inicializar o módulo de controlador OLE.  
  
 [COleControl](../mfc/reference/colecontrol-class.md)  
 Derivar da classe de `COleControl` para desenvolver um controlador OLE.  Derivada de `CWnd`, esta classe é herdada toda a funcionalidade de um objeto da janela do windows mais a funcionalidade específica OLE\- adicionais, como o acionamento do evento e a capacidade de dar suporte a métodos e propriedades.  
  
 [CConnectionPoint](../Topic/CConnectionPoint%20Class.md)  
 A classe de `CConnectionPoint` define um tipo especial de interface usada para se comunicar com outros objetos OLE, chamado em um ponto de conexão.  Um ponto de conexão implementa uma interface de saída que possa iniciar ações em outros objetos, como eventos de acionamento e notificações de alteração.  
  
 [CPictureHolder](../mfc/reference/cpictureholder-class.md)  
 Encapsula a funcionalidade de um objeto da imagem do windows e da interface de `IPicture` COM; usados para implementar a propriedade personalizada da imagem de um controlador OLE.  
  
 [CFontHolder](../mfc/reference/cfontholder-class.md)  
 Encapsula a funcionalidade de um objeto de fonte do windows e da interface de `IFont` COM; usados para implementar a propriedade de estoque de fonte de um controlador OLE.  
  
 [COlePropertyPage](../mfc/reference/colepropertypage-class.md)  
 Exibe as propriedades de um controlador OLE em uma interface gráfica, semelhantes a uma caixa de diálogo.  
  
 [CPropExchange](../Topic/CPropExchange%20Class.md)  
 Oferece suporte a implementação de persistência de propriedade para os controladores OLE.  Análoga a [CDataExchange](../Topic/CDataExchange%20Class.md) para caixas de diálogo.  
  
 [CMonikerFile](../Topic/CMonikerFile%20Class.md)  
 Usa um moniker, ou uma representação de cadeia de caracteres que pode fazer em um moniker, de forma síncrona e o associa ao fluxo para o qual o moniker é um nome.  
  
 [CAsyncMonikerFile](../mfc/reference/casyncmonikerfile-class.md)  
 Funciona de modo semelhante a `CMonikerFile`; no entanto, o associará o moniker de forma assíncrona para o fluxo para o qual o moniker é um nome.  
  
 [CDataPathProperty](../mfc/reference/cdatapathproperty-class.md)  
 Implementa uma propriedade de controle OLE que pode ser carregada de forma assíncrona.  
  
 [CCachedDataPathProperty](../mfc/reference/ccacheddatapathproperty-class.md)  
 Implementa uma propriedade de controle OLE transferida de forma assíncrona e armazenada em cache em um arquivo de memória.  
  
 [COleCmdUI](../mfc/reference/colecmdui-class.md)  
 Permite um documento ativo receber os comandos que se originam na interface de usuário de seu contêiner \(como FileNew, abra, imprime, e assim por diante\), e permite que um contêiner recebe comandos que se originam na interface de usuário ativa do documento.  
  
 [COleSafeArray](../mfc/reference/colesafearray-class.md)  
 Funciona com matrizes do tipo e a dimensão arbitrários.  
  
## Consulte também  
 [Visão geral da classe](../mfc/class-library-overview.md)