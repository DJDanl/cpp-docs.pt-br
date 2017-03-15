---
title: "Objetos de janela | Microsoft Docs"
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
  - "janelas com moldura [C++], objetos de janela C++"
  - "HWND"
  - "HWND, objetos de janela"
  - "mensagens [C++], Janelas"
  - "MFC [C++], janelas"
  - "objetos [C++], janela"
  - "Visual C++, objetos de janela"
  - "mensagens de janela [C++]"
  - "objetos de janela [C++]"
  - "janelas [C++], objetos de janela C++"
  - "janela do Windows [C++]"
ms.assetid: 28b33ce2-af05-4617-9d03-1cb9a02be687
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Objetos de janela
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Classe [CWnd](../Topic/CWnd%20Class.md) de fontes MFC para encapsular o identificador de `HWND` de uma janela.  O objeto de `CWnd` é o objeto da janela criando c, distinto de `HWND` que representa uma janela do windows mas que contém a ela.  Use `CWnd` para derivar suas próprias classes da janela filho, ou use uma das classes derivadas de MFC `CWnd`.  A classe `CWnd` é a classe base para todas as janelas, inclusive o windows do quadro, caixas de diálogo, janelas filho, controles, e barras de controle como barras de ferramentas.  Um bom entendimento de [a relação entre o objeto da janela c e um HWND criando](../Topic/Relationship%20Between%20a%20C++%20Window%20Object%20and%20an%20HWND.md) é fundamental para programação efetivos com MFC.  
  
 MFC O fornece alguns funcionalidade e gerenciamento do windows padrão, mas você pode derivar sua própria classe de `CWnd` e usar as funções de membro para personalizar a funcionalidade fornecida.  Você pode criar janelas filho construindo um objeto de `CWnd` e chamando a função de membro de [Crie](../Topic/CWnd::Create.md) , então personalização das janelas filho usando as funções de membro de `CWnd` .  Você pode inserir os objetos derivados de [CView](../Topic/CView%20Class.md), como exibições de formulário ou modos de exibição de árvore, em uma janela do quadro.  E você pode dar suporte a várias exibições dos documentos pelos painéis do divisor, fornecidas pela classe [CSplitterWnd](../mfc/reference/csplitterwnd-class.md).  
  
 Cada objeto derivado da classe `CWnd` contém um mapa de mensagem, em que é possível mapear mensagens do windows ou IDs de comando com seus próprios manipuladores.  
  
 A literatura geral na programação do windows é um bom recursos para aprender a usar as funções de membro de `CWnd` , que encapsulam os APIs de `HWND` .  
  
## Funções para operar em um CWnd  
 `CWnd` e seu [classes derivadas da janela](../Topic/Derived%20Window%20Classes.md) fornecem construtores, destruidores, e as funções de membro para inicializar o objeto, para criar estruturas subjacentes do windows, e para acessar `HWND`encapsulado.  `CWnd` também fornece as funções de membro que encapsulam APIs do windows para enviar mensagens, acessando o estado da janela, convertendo coordenadas, atualizar, rolando, o acesso à área de transferência, e muitas outras tarefas.  A maioria das APIs do gerenciamento do windows que têm um argumento de `HWND` são encapsulados como funções de membro de `CWnd`.  Os nomes das funções e seus parâmetros são preservados na função de membro de `CWnd` .  Para obter detalhes sobre as APIs do windows encapsuladas por `CWnd`, consulte a classe [CWnd](../Topic/CWnd%20Class.md).  
  
## CWnd e mensagens do windows  
 Um dos objetivos principais de `CWnd` é fornecer uma interface para tratar mensagens do windows, como `WM_PAINT` ou `WM_MOUSEMOVE`.  Muitas das funções de membro de `CWnd` são manipuladores para mensagens padrão — essas começando com o identificador **afx\_msg** e o prefixo “on”, como `OnPaint` e **OnMouseMove**.  mensagens de coberturas de[Manipulando e mapeamento de mensagem](../mfc/message-handling-and-mapping.md) e manipulação de mensagens em detalhes.  Informações que se aplica ao e às da estrutura que você cria você mesmo para objetivos especiais.  
  
### Que você deseja saber mais?  
  
-   [A relação entre o objeto da janela c e um HWND criando](../Topic/Relationship%20Between%20a%20C++%20Window%20Object%20and%20an%20HWND.md)  
  
-   [Classes derivadas da janela](../Topic/Derived%20Window%20Classes.md)  
  
-   [Criando o windows](../Topic/Creating%20Windows.md)  
  
-   [Objetos de destruição da janela](../mfc/destroying-window-objects.md)  
  
-   [Desanexando um CWnd do HWND](../Topic/Detaching%20a%20CWnd%20from%20Its%20HWND.md)  
  
-   [Trabalhar com objetos da janela](../Topic/Working%20with%20Window%20Objects.md)  
  
-   [Contextos de dispositivo](../Topic/Device%20Contexts.md): objetos que fazem o windows que desenha o independentemente do dispositivo  
  
-   [Objetos gráficos](../mfc/graphic-objects.md): penalidades, escovas, fontes, bitmaps, paletas, regiões  
  
## Consulte também  
 [Janelas](../mfc/windows.md)