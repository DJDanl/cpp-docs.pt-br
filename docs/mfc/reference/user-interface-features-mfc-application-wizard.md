---
title: "Recursos da interface do usu&#225;rio, Assistente de Aplicativo MFC | Microsoft Docs"
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
  - "vc.appwiz.mfc.exe.ui"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de aplicativo MFC, recursos de interface do usuário"
ms.assetid: 59e7b829-a665-42eb-be23-3f2a36eb2dad
caps.latest.revision: 12
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Recursos da interface do usu&#225;rio, Assistente de Aplicativo MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico explica as opções que você pode usar para especificar o aspecto de seu aplicativo.  Recursos da interface do usuário disponíveis para seu projeto dependem do tipo de aplicativo que você especificou na página de [Tipo de aplicativo, Assistente de Aplicativo MFC](../Topic/Application%20Type,%20MFC%20Application%20Wizard.md) do assistente de aplicativo MFC.  Por exemplo, se você criar um aplicativo da interface de um único documento, você não pode adicionar estilos filhos do quadro.  
  
 **Estilo do quadro principal**  
 Define os recursos do quadro de janela principal do seu aplicativo.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**Peça grosso**|Cria uma janela que tenha uma borda de dimensionamento.  A opção.|  
|**Minimizar a caixa**|Inclui uma caixa minimizar na janela principal do quadro.  A opção.|  
|**Maximizar a caixa**|Inclui uma caixa maximizar a janela principal do quadro.  A opção.|  
|**Minimizado**|Abre a janela do quadro principal como um ícone.|  
|**Maximizado**|Abre o tamanho da janela principal do quadro para o máximo de exibição.|  
|**Menu do sistema**|Inclui um menu de sistema na janela principal do quadro.  A opção.|  
|**Na caixa**|Inclui uma caixa de **Sobre** para o aplicativo.  O usuário pode acessar esta caixa no menu de **Ajuda** do aplicativo.  A opção, e inalterável a menos que você selecione **Caixa de diálogo baseada**, na página de [Tipo de aplicativo, Assistente de Aplicativo MFC](../Topic/Application%20Type,%20MFC%20Application%20Wizard.md) .<br /><br /> **Observação** Geralmente, uma opção indisponível indica que o assistente não aplica a opção ao projeto, se a caixa de seleção não estiver disponível no item está selecionada ou desmarcada.  Nesse caso, o assistente sempre adiciona uma caixa de **Sobre** ao projeto a menos que você especifique primeiro o projeto como a caixa de diálogo base e desmarque a caixa.|  
|**Barra de status inicial**|Adiciona uma barra de status ao aplicativo.  A barra de status contém indicadores automático para chaves de CAPS LOCK de teclado de bloqueio, NUMERIC, e de SCROLL LOCK e uma linha de mensagem que exibe cadeias de caracteres da ajuda para comandos de menu e botões da barra de ferramentas.  Clique nessa opção também adiciona comandos de menu exibir ou ocultar a barra de status.  Por padrão, um aplicativo tem uma barra de status.  Não disponível para tipos de aplicativos baseados diálogo\-.|  
|**Janela de divisão**|Fornece uma barra de divisão.  A barra de divisão divide as exibições principais do aplicativo.  Em um aplicativo \(MDI\) de interface de documentos, a janela filho do cliente do quadro MDI é uma janela do divisor, e um aplicativo \(SDI\) da interface de único documento e o aplicativo de nível superior do documento de múltiplas, a janela do cliente de peças principal é uma janela do separador.  Não disponível para tipos de aplicativos baseados diálogo\-.|  
  
 **Estilos filhos do quadro**  
 Especifica a aparência e o estado inicial de peças do filho em seu aplicativo.  Os estilos filhos do quadro estão disponíveis para aplicativos MDI somente.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**O filho minimiza a caixa**|Especifica se uma janela filho tiver um botão é habilitado \(por padrão\).|  
|**O filho maximiza a caixa**|Especifica se uma janela filho tiver um botão maximizar \(desabilitado por padrão\).|  
|**Maximizado filho**|Especifica se uma janela filho é maximizada inicialmente definir o sinalizador **WS\_MAXIMIZE** de cs.style na função de membro de [PreCreateWindow](../Topic/CWnd::PreCreateWindow.md) de `CChildFrame`.|  
  
 **Barras de comandos \(menu\/barra de ferramentas\/fita\)**  
 Indica se o seu aplicativo incluem menus, barras de ferramentas, e\/ou uma fita.  Não disponível para aplicativos baseados diálogo\-.  
  
|Opção|Descrição|  
|-----------|---------------|  
|**Use um menu clássico**|Especifica que o aplicativo contenha um menu clássico, non\-draggable.|  
|**Use uma barra de ferramentas clássica de encaixe**|Adiciona uma barra de ferramentas padrão do windows ao aplicativo.  A barra de ferramentas contém botões para criar um novo documento; abrindo arquivos e de documento de salvamento; cópia de divisão, colando, ou imprimir o texto; e digitando o modo de ajuda.  A habilitação dessa opção também adiciona comandos de menu exibir ou ocultar a barra de ferramentas.|  
|**Use uma barra de ferramentas de estilo do navegador**|Adiciona uma barra de ferramentas de Explorer\- estilo da Internet para o seu aplicativo.|  
|**Use uma barra de menus e uma barra de ferramentas**|Indica que o aplicativo contém uma barra de menus draggable e uma barra de ferramentas.|  
|**Barras de ferramentas definidos pelo usuário e imagens**|Permite que o usuário personalize a barra de ferramentas e a barra de ferramentas imagens em tempo de execução.|  
|**Comportamento personalizado no menu**|Especifica se o menu contém a lista completa de itens, quando aberto ou se ele contém apenas os comandos que o usuário usa com mais frequência.|  
|**Use uma fita**|Usa o Office 2007 como a fita em seu aplicativo em vez de uma barra de menus ou de uma barra de ferramentas.|  
  
 **Título da caixa de diálogo**  
 Para aplicativos baseados no de [Classe de CDialog](../../mfc/reference/cdialog-class.md), somente esse título é exibido na barra de título da caixa de diálogo.  Para editar esse campo, você deve primeiro selecionar a opção de **Caixa de diálogo baseada** em **Tipo de Aplicativo**.  Para obter mais informações, consulte [Tipo de aplicativo, Assistente de Aplicativo MFC](../Topic/Application%20Type,%20MFC%20Application%20Wizard.md).  
  
## Consulte também  
 [Assistente de aplicativo MFC](../Topic/MFC%20Application%20Wizard.md)