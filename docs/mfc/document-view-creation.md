---
title: "Criação do modo de exibição de documentos | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- documents [MFC], creating
- views [MFC], and frame windows
- views [MFC], creating
- tables [MFC]
- MFC, views
- document/view architecture [MFC], creating document/view
- object creators
- MFC, documents
- tables [MFC], objects each MFC object creates
ms.assetid: bda14f41-ed50-439d-af9e-591174e7dd64
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: e98f6e4b1b9ecd5848c2701043aa9b0b7dcea7d4
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="documentview-creation"></a>Criação de documento/exibição
A estrutura fornece implementações do `New` e **abrir** comandos (entre outros) no **arquivo** menu. A criação de um novo documento e a exibição associada e a janela do quadro é um esforço de colaboração entre o objeto de aplicativo, um modelo de documento, o documento criado recentemente e a janela do quadro recém-criado. A tabela a seguir resume os objetos que criam o que.  
  
### <a name="object-creators"></a>Criadores de objeto  
  
|Criador|Cria|  
|-------------|-------------|  
|Objeto de aplicativo|Modelo de documento|  
|Modelo de documento|Documento|  
|Modelo de documento|Janela do quadro|  
|Janela do quadro|Exibir|  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de documento e o processo de criação de documento/exibição](../mfc/document-templates-and-the-document-view-creation-process.md)   
 [Criação do modelo de documento](../mfc/document-template-creation.md)   
 [Relações entre objetos MFC](../mfc/relationships-among-mfc-objects.md)   
 [Criando novos documentos, janelas e exibições](../mfc/creating-new-documents-windows-and-views.md)

