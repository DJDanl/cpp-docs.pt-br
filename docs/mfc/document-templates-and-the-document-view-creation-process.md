---
title: Modelos de documento e o processo de criação do modo de exibição de documentos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- icons, for multiple document templates
- document templates [MFC], and views
- document/view architecture [MFC], creating document/view
- single document template
- MFC, document templates
- multiple document template
- CDocTemplate class [MFC]
- templates [MFC], document templates
ms.assetid: 311ce4cd-fbdf-4ea1-a51b-5bb043abbcee
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f2d8308e69cf53db4be51f6ce742df41edaa89ea
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="document-templates-and-the-documentview-creation-process"></a>Modelos de documento e o processo de criação de documento/exibição
Para gerenciar o processo complexo de criação de documentos com suas exibições associadas e janelas com moldura, a estrutura usa duas classes de modelo de documento: [CSingleDocTemplate](../mfc/reference/csingledoctemplate-class.md) para aplicativos SDI e [CMultiDocTemplate ](../mfc/reference/cmultidoctemplate-class.md) para aplicativos MDI. Um `CSingleDocTemplate` pode criar e armazenar um documento de um tipo de cada vez. Um `CMultiDocTemplate` mantém uma lista de vários documentos abertos de um tipo.  
  
 Alguns aplicativos oferecem suporte a vários tipos de documento. Por exemplo, um aplicativo pode dar suporte a documentos de texto e elementos gráficos. No aplicativo, quando o usuário escolhe o novo comando no menu Arquivo, uma caixa de diálogo mostra uma lista de possíveis novos tipos de documento para abrir. Para cada tipo de documento com suporte, o aplicativo usa um objeto de modelo de documento distintos. A figura a seguir ilustra a configuração de um aplicativo MDI que dá suporte a dois tipos de documento e mostra vários documentos abertos.  
  
 ![Aplicativos MDI que tem dois tipos de documento](../mfc/media/vc387h1.gif "vc387h1")  
Um aplicativo MDI com dois tipos de documento  
  
 Modelos de documento são criados e mantidos pelo objeto de aplicativo. Uma das principais tarefas executadas durante o seu aplicativo `InitInstance` função é criar um ou mais modelos de documento do tipo apropriado. Esse recurso é descrito em [criação do modelo de documento](../mfc/document-template-creation.md). O objeto de aplicativo armazena um ponteiro para cada modelo de documento em sua lista de modelo e fornece uma interface para adicionar modelos de documento.  
  
 Se você precisar dar suporte a dois ou mais tipos de documento, você deve adicionar uma chamada adicional para [AddDocTemplate](../mfc/reference/cwinapp-class.md#adddoctemplate) para cada tipo de documento.  
  
 Um ícone é registrado para cada modelo de documento com base em sua posição na lista da aplicação de modelos de documento. A ordem dos modelos de documento é determinada pela ordem em que eles são adicionados a chamadas para `AddDocTemplate`. MFC pressupõe que o primeiro recurso de ícone do aplicativo é o ícone do aplicativo, o recurso de ícone próximo é o primeiro ícone de documento e assim por diante.  
  
 Por exemplo, um modelo de documento é o terceiro de três para o aplicativo. Se houver um recurso de ícone do aplicativo no índice 3, esse ícone é usado para o modelo de documento. Caso contrário, o ícone no índice 0 é usado como padrão.  
  
## <a name="see-also"></a>Consulte também  
 [Tópicos MFC gerais](../mfc/general-mfc-topics.md)   
 [Criação do modelo de documento](../mfc/document-template-creation.md)   
 [Criação de documento/exibição](../mfc/document-view-creation.md)   
 [Relações entre objetos MFC](../mfc/relationships-among-mfc-objects.md)   
 [Criando novos documentos, janelas e exibições](../mfc/creating-new-documents-windows-and-views.md)

