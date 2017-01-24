---
title: "Cont&#234;ineres de controle ActiveX: exibindo e modificando propriedades de controle | Microsoft Docs"
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
  - "Contêineres de controle ActiveX [C++], exibindo e modificando propriedades"
  - "Controles ActiveX [C++], propriedades"
  - "controles [MFC], propriedades"
  - "propriedades [MFC], exibindo e modificando"
  - "editores de recursos, exibindo e modificando controles ActiveX"
ms.assetid: 14ce5152-742b-4e0d-a9ab-c7b456e32918
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cont&#234;ineres de controle ActiveX: exibindo e modificando propriedades de controle
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando você insere um controle ActiveX em um projeto, é útil exibir e modificar as propriedades suportadas pelo controle ActiveX.  Este artigo descreve como usar o editor de recursos do Visual C\+\+ para fazer isso.  
  
 Se seu aplicativo de contêiner do controle ActiveX usa controles inseridos, você pode exibir e modificar as propriedades de controle quando no publicador do recurso.  Você também pode usar o editor de recursos para definir valores de propriedade durante o tempo de design.  O editor de recurso em salva automaticamente esses valores no arquivo de recurso do projeto.  Qualquer instância do controle terá em suas propriedades inicializadas a estes valores.  
  
 Este procedimento assume que você inseriu um controle em seu projeto.  Para obter mais informações, consulte [Contêiner do controle ActiveX: Inserindo um controle em um aplicativo de contêiner do controle](../mfc/inserting-a-control-into-a-control-container-application.md).  
  
 A primeira etapa para exibir as propriedades do controle é adicionar uma instância do controle para o modelo da caixa de diálogo do projeto.  
  
### Para exibir as propriedades de um controle  
  
1.  Na exibição de recursos, abra a pasta de **Caixa de Diálogo** .  
  
2.  Abra seu modelo principal da caixa de diálogo.  
  
3.  Inserir um controle ActiveX usando a caixa de diálogo **Inserir controle ActiveX** .  Para obter mais informações, consulte [Exibindo e adicionando controles ActiveX a uma caixa de diálogo](../mfc/viewing-and-adding-activex-controls-to-a-dialog-box.md).  
  
4.  Selecione o controle ActiveX na caixa de diálogo.  
  
5.  Na janela Propriedades, clique no botão de **Propriedades** .  
  
 Use a caixa de diálogo de **Propriedades** para alterar imediatamente e testar novos propriedades.  
  
## Consulte também  
 [Contêineres de controle ActiveX](../mfc/activex-control-containers.md)