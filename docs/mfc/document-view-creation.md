---
title: "Cria&#231;&#227;o de documento/exibi&#231;&#227;o | Microsoft Docs"
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
  - "arquitetura de documento/exibição, criando documento/exibição"
  - "documentos, criando"
  - "MFC, documentos"
  - "MFC, modos de exibição"
  - "criadores de objeto"
  - "tabelas [C++]"
  - "tabelas [C++], objetos que cada objeto MFC cria"
  - "modos de exibição, e janelas com moldura"
  - "modos de exibição, criando"
ms.assetid: bda14f41-ed50-439d-af9e-591174e7dd64
caps.latest.revision: 9
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Cria&#231;&#227;o de documento/exibi&#231;&#227;o
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A estrutura fornece implementações dos comandos de `New` e de **Abrir** \(entre outros\) no menu de **Arquivo** .  A criação de um novo documento e da janela de exibição associado e do quadro é uma busca cooperativo entre o objeto do aplicativo, um modelo de documento, o documento recém\-criado, e a janela recém\-criado do quadro.  A tabela a seguir resume os objetos que criam.  
  
### Designers do objeto  
  
|Designer|Cria|  
|--------------|----------|  
|Objeto de aplicativo|Modelo de documento|  
|Modelo de documento|Documento|  
|Modelo de documento|Janela do quadro|  
|Janela do quadro|View|  
  
## Consulte também  
 [Modelos de documento e o processo de criação de documento\/exibição](../mfc/document-templates-and-the-document-view-creation-process.md)   
 [Criação do modelo de documento](../Topic/Document%20Template%20Creation.md)   
 [Relacionamentos entre objetos MFC](../mfc/relationships-among-mfc-objects.md)   
 [Criando novos documentos, janelas e exibições](../Topic/Creating%20New%20Documents,%20Windows,%20and%20Views.md)