---
title: "Criação do modelo de documento | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- document templates [MFC]
- constructors [MFC], document template
- document templates [MFC], creating
- MFC, document templates
- templates [MFC], document templates
ms.assetid: c87f1821-7cbf-442e-9690-f126ae7fb783
caps.latest.revision: "9"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 04950601a74b1ed3e44b236e1d07dcdff997eca6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="document-template-creation"></a>Criação do modelo de documento
Ao criar um novo documento em resposta a um `New` ou **abrir** comando o **arquivo** menu, o modelo de documento também cria uma nova janela do quadro através da qual exibir o documento.  
  
 O construtor de modelo de documento especifica quais tipos de documentos, janelas e modos de exibição que do modelo poderá ser capaz de criar. Isso é determinado pelos argumentos que você passa para o construtor de modelo de documento. O código a seguir ilustra a criação de um [CMultiDocTemplate](../mfc/reference/cmultidoctemplate-class.md) para um aplicativo de exemplo:  
  
 [!code-cpp[NVC_MFCDocView#7](../mfc/codesnippet/cpp/document-template-creation_1.cpp)]  
  
 O ponteiro para um novo `CMultiDocTemplate` o objeto é usado como um argumento para [AddDocTemplate](../mfc/reference/cwinapp-class.md#adddoctemplate). Argumentos para o `CMultiDocTemplate` construtor incluem a ID de recurso associada com o tipo de documento menus e aceleradores e três usos da [RUNTIME_CLASS](../mfc/reference/run-time-object-model-services.md#runtime_class) macro. `RUNTIME_CLASS`Retorna o [CRuntimeClass](../mfc/reference/cruntimeclass-structure.md) objeto para a classe do C++ denominada como seu argumento. Os três `CRuntimeClass` objetos passados para o construtor de modelo de documento fornecem as informações necessárias para criar novos objetos das classes especificados durante o processo de criação de documento. O exemplo mostra a criação de um modelo de documento que cria `CScribDoc` objetos com `CScribView` objetos anexados. As exibições são formuladas pelo padrão janelas de quadro filho MDI.  
  
## <a name="see-also"></a>Consulte também  
 [Modelos de documento e o processo de criação de documento/exibição](../mfc/document-templates-and-the-document-view-creation-process.md)   
 [Criação de documento/exibição](../mfc/document-view-creation.md)   
 [Relações entre objetos MFC](../mfc/relationships-among-mfc-objects.md)   
 [Criando novos documentos, janelas e exibições](../mfc/creating-new-documents-windows-and-views.md)

