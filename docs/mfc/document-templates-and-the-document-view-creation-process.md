---
title: "Modelos de documento e o processo de cria&#231;&#227;o de documento/exibi&#231;&#227;o | Microsoft Docs"
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
  - "Classe CDocTemplate"
  - "modelos de documento, e exibições"
  - "arquitetura de documento/exibição, criando documento/exibição"
  - "ícones, para vários modelos de documento"
  - "MFC, modelos de documento"
  - "vários modelos de documento"
  - "único modelo de documento"
  - "modelos, modelos de documento"
ms.assetid: 311ce4cd-fbdf-4ea1-a51b-5bb043abbcee
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Modelos de documento e o processo de cria&#231;&#227;o de documento/exibi&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para gerenciar o processo complexo de criar documentos com as exibições e janelas associadas do quadro, usa dois da estrutura documentam classes de modelo: [CSingleDocTemplate](../mfc/reference/csingledoctemplate-class.md) para aplicativos de SDI e [CMultiDocTemplate](../mfc/reference/cmultidoctemplate-class.md) para aplicativos MDI.  `CSingleDocTemplate` pode criar e armazenar um documento de um tipo de cada vez.  `CMultiDocTemplate` mantém uma lista de vários documentos abertos de um tipo.  
  
 Alguns aplicativos dão suporte a vários tipos de documento.  Por exemplo, um aplicativo pode oferecer suporte a documentos de texto e documentos de gráficos.  Nesse aplicativo, quando o usuário escolha o novo comando no menu arquivo, mostra quais de uma caixa de diálogo uma lista de documento novo possível digitar para abrir o.  Para cada tipo de documento com suporte, o aplicativo usa um objeto distinto de modelo de documento.  A figura a seguir ilustra a configuração de um aplicativo MDI que o da suporte a dois tipos de documento e mostra a vários documentos abertos.  
  
 ![Com 2 tipos de aplicativo MDI](../mfc/media/vc387h1.png "vc387H1")  
Um aplicativo MDI com dois tipos de documento  
  
 Os modelos do documento são criados e mantidos pelo objeto do aplicativo.  Uma das tarefas principais executadas durante a função de `InitInstance` de seu aplicativo for construir um ou mais modelos do documento de tipo apropriado.  Esse recurso é descrito em [Criação de modelo de documento](../Topic/Document%20Template%20Creation.md).  O objeto do aplicativo armazena um ponteiro para cada modelo de documento em sua lista de modelo e fornece uma interface para adicionar modelos do documento.  
  
 Se precisar dar suporte a dois ou mais tipos de documento, você deve adicionar uma chamada adicional a [AddDocTemplate](../Topic/CWinApp::AddDocTemplate.md) para cada tipo de documento.  
  
 Um ícone é registrado para cada modelo de documento com base em sua posição na lista de aplicativos de modelos do documento.  A ordem dos modelos do documento é determinada pela ordem em que são adicionados com chamadas a `AddDocTemplate`.  O MFC supõe que o primeiro recurso do ícone no aplicativo é o ícone de aplicativo, o próximo recurso de ícone é o primeiro ícone de documento, e assim por diante.  
  
 Por exemplo, um modelo de documento é a terceira de três para o aplicativo.  Se houver um recurso do ícone no aplicativo no índice 3, esse ícone é usado para o modelo de documento.  Caso contrário, o ícone no índice 0 é usado como padrão.  
  
## Consulte também  
 [Tópicos MFC gerais](../mfc/general-mfc-topics.md)   
 [Criação do modelo de documento](../Topic/Document%20Template%20Creation.md)   
 [Criação de documento\/exibição](../mfc/document-view-creation.md)   
 [Relacionamentos entre objetos MFC](../mfc/relationships-among-mfc-objects.md)   
 [Criando novos documentos, janelas e exibições](../Topic/Creating%20New%20Documents,%20Windows,%20and%20Views.md)