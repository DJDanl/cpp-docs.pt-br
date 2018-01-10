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
ms.workload: cplusplus
ms.openlocfilehash: c6997189f23ea7599dde0a1b19ba9f0ea350378d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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

