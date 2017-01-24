---
title: "A adi&#231;&#227;o de controles a uma caixa de di&#225;logo faz a caixa de di&#225;logo deixar de funcionar | Microsoft Docs"
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
  - "C++"
helpviewer_keywords: 
  - "controles comuns, solucionando problemas"
  - "controles [C++], solucionando problemas"
  - "controles de caixas de diálogo, solucionando problemas"
  - "caixas de diálogo, solucionando problemas"
  - "InitCommonControls"
  - "solucionando problemas de controles"
ms.assetid: b2dd4574-ea59-4343-8d65-b387cead5da6
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# A adi&#231;&#227;o de controles a uma caixa de di&#225;logo faz a caixa de di&#225;logo deixar de funcionar
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Depois de adicionar um controle comum ou um controle rich edit para uma caixa de diálogo, ela não aparecerá quando você testar a caixa de diálogo ou a própria caixa de diálogo não será exibida.  
  
 **Exemplo do problema**  
  
1.  Crie um projeto do Win32, modificando as configurações do aplicativo para que você criar um aplicativo do Windows \(e não um aplicativo de console\).  
  
2.  Em  [Exibição de recurso](../windows/resource-view-window.md), clique duas vezes no arquivo. rc.  
  
3.  Sob a opção de caixa de diálogo, clique duas vezes o  **sobre** caixa.  
  
4.  Adicionar um  **Controle de endereço IP** à caixa de diálogo.  
  
5.  Salvar e  **reconstruir todos**.  
  
6.  Execute o programa.  
  
7.  Na caixa de diálogo  **Help** menu, clique no  **sobre** de comando; nenhuma caixa de diálogo é exibida.  
  
 **A causa**  
  
 Atualmente, o editor de diálogo não adiciona automaticamente código ao seu projeto quando você arrasta e solta os seguintes controles comuns ou controles em uma caixa de diálogo de edição rico.  Nem o Visual Studio oferece um erro ou aviso quando esse problema ocorre.  Você deve adicionar manualmente o código para o controle.  
  
||||  
|-|-|-|  
|Controle deslizante|Controle de árvore|Selecionador de data hora|  
|Controle de rotação|Controle Tab|Calendário mensal|  
|Controle de progresso|Controle de animação|Controle de endereço IP|  
|Tecla de acesso|Controle de edição avançado|Caixa de combinação estendido|  
|Controle de lista|Controle Rich Edit 2.0|Custom Control|  
  
## A correção dos controles comuns  
 Para usar controles comuns em uma caixa de diálogo, você precisará chamar  [InitCommonControlsEx](http://msdn.microsoft.com/library/windows/desktop/bb775697) ou  **AFXInitCommonControls** antes de criar a caixa de diálogo.  
  
## A correção dos controles RichEdit  
 Você deve chamar  **LoadLibrary** para controles de edição avançados.  Para obter mais informações, consulte  [usando o controle de 1.0 RichEdit com MFC](../Topic/Using%20the%20RichEdit%201.0%20Control%20with%20MFC.md),  [Sobre como editar controles sofisticados de](http://msdn.microsoft.com/library/windows/desktop/bb787873) na [!INCLUDE[winsdkshort](../atl/reference/includes/winsdkshort_md.md)], e  [Visão geral do controle de edição de Rich](../mfc/overview-of-the-rich-edit-control.md).  
  
## Requisitos  
 Win32  
  
## Consulte também  
 [Solucionando problemas do Editor de Caixa de Diálogo](../mfc/troubleshooting-the-dialog-editor.md)   
 [Editor de Caixa de Diálogo](../mfc/dialog-editor.md)