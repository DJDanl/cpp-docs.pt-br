---
title: "Controles ActiveX MFC: criando um servidor de automa&#231;&#227;o | Microsoft Docs"
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
  - "Controles ActiveX [C++], Servidor de automação"
  - "Servidores de automação [C++], Controles ActiveX MFC"
  - "Controles ActiveX MFC [C++], Servidor de automação"
ms.assetid: e0c24ed2-d61c-49ad-a4fa-4e1098d1d39b
caps.latest.revision: 11
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Controles ActiveX MFC: criando um servidor de automa&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode desenvolver um controle ActiveX de MFC como um servidor de automação programaticamente com a finalidade de inserir esse controle em outro aplicativo e de chamar métodos no controle do aplicativo.  Esse controle ainda podem estar disponível para ser hospedado em um contêiner do controle ActiveX.  
  
### Para criar um controle como um servidor de automação  
  
1.  [Crie](../mfc/reference/mfc-activex-control-wizard.md) o controle.  
  
2.  [Adicionar métodos](../mfc/mfc-activex-controls-methods.md).  
  
3.  Substituição [IsInvokeAllowed](../Topic/COleControl::IsInvokeAllowed.md).  Artigo da Base de Dados de Conhecimento de Q146120 Para obter mais informações, consulte.  
  
4.  Compilar o controle.  
  
### Para acessar o programaticamente os métodos em um servidor de automação  
  
1.  Crie um aplicativo, por exemplo, [MFC exe](../Topic/MFC%20Application%20Wizard.md).  
  
2.  No início da função de `InitInstance` , adicione a seguinte linha:  
  
     [!code-cpp[NVC_MFC_AxCont#17](../mfc/codesnippet/CPP/mfc-activex-controls-creating-an-automation-server_1.cpp)]  
  
3.  Na exibição da classe, clique com o botão direito do mouse no nó e selecione **Add class from typelib** para importar a biblioteca de tipos.  
  
     Isso adiciona arquivos com as extensões de nome de arquivo .h e .cpp ao projeto.  
  
4.  No arquivo de cabeçalho da classe em que você chamará um ou mais métodos no controle ActiveX, adicione a seguinte linha: `#include filename.h`, onde o nome do arquivo é o nome do arquivo de cabeçalho que foi criado quando você importou a biblioteca de tipos.  
  
5.  Na função em que será feita uma chamada para um método no controle ActiveX, adicione o código que cria um objeto da classe de invólucro de controle e crie o objeto do ActiveX.  Por exemplo, o seguinte código MFC cria uma instância de um controle de `CCirc` , obtém a propriedade de legenda, e exibe o resultado quando o botão OK é clicado em uma caixa de diálogo:  
  
     [!code-cpp[NVC_MFC_AxCont#18](../mfc/codesnippet/CPP/mfc-activex-controls-creating-an-automation-server_2.cpp)]  
  
 Se você adiciona métodos ao controle ActiveX depois que você usa em um aplicativo, você pode começar a usar a versão mais recente de controle no aplicativo excluindo arquivos criados quando importou a biblioteca de tipos.  Importe a biblioteca de tipos novamente.  
  
## Consulte também  
 [Controles ActiveX MFC](../mfc/mfc-activex-controls.md)