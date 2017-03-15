---
title: "Sequ&#234;ncia de opera&#231;&#245;es para cria&#231;&#227;o de aplicativos OLE | Microsoft Docs"
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
  - "aplicativos [OLE]"
  - "aplicativos [OLE], criando"
  - "Aplicativos OLE [C++]"
  - "Aplicativos OLE [C++], criando"
ms.assetid: 84b0f606-36c1-4253-9cea-44427f0074b9
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Sequ&#234;ncia de opera&#231;&#245;es para cria&#231;&#227;o de aplicativos OLE
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A tabela a seguir mostra a função e a função da estrutura na criação de OLE que vincula e que insere aplicativos.  Esses representam as opções disponíveis em vez de uma sequência de etapas para executar.  
  
### Criando aplicativos OLE  
  
|Tarefa|Você fizer|A estrutura faz|  
|------------|----------------|---------------------|  
|Crie um componente COM.|Execute o assistente de aplicativo MFC.  Escolha **Full\-server** ou **Mini\-server** na guia de **Compound Document Support** .|A estrutura gerenciar um aplicativo do esqueleto com o recurso do componente COM habilitado.  Qualquer recurso de COM pode ser transferido para o seu aplicativo existente com apenas um pouco alteração.|  
|Crie um aplicativo de contêiner a partir do zero.|Execute o assistente de aplicativo MFC.  Escolha **Contêiner** na guia de **Compound Document Support** .  Usar a exibição da classe, vai para o editor de origem.  Preencha o código para suas funções de manipulador da.|A estrutura gerenciar um aplicativo do esqueleto que pode inserir os objetos COM criados por aplicativos de componente COM \(servidor\).|  
|Crie um aplicativo que oferece suporte à automação a partir do zero.|Execute o assistente de aplicativo MFC.  Escolha **Automação** da guia de **Recursos Avançados** .  Use a exibição da classe para expor métodos e propriedades em seu aplicativo para a automação.|A estrutura gerenciar um aplicativo do esqueleto que pode ser ativado e automatizado por outros aplicativos.|  
  
## Consulte também  
 [Aproveitando o Framework](../mfc/building-on-the-framework.md)   
 [Sequência de operações para compilação de aplicativos MFC](../mfc/sequence-of-operations-for-building-mfc-applications.md)   
 [Sequência de operações para criação de controles ActiveX](../mfc/sequence-of-operations-for-creating-activex-controls.md)   
 [Sequência de operações para criação de aplicativos de banco de dados](../mfc/sequence-of-operations-for-creating-database-applications.md)