---
title: Criação do modo de exibição de documentos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cb89180db8e1a6cce2c40bbb4bae0965b972afa2
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33343512"
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

