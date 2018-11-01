---
title: Criação do modelo de documento
ms.date: 11/04/2016
helpviewer_keywords:
- document templates [MFC]
- constructors [MFC], document template
- document templates [MFC], creating
- MFC, document templates
- templates [MFC], document templates
ms.assetid: c87f1821-7cbf-442e-9690-f126ae7fb783
ms.openlocfilehash: f5c0691deab3d475a72cda0e86d681ea0c4ddfa0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50480165"
---
# <a name="document-template-creation"></a>Criação do modelo de documento

Ao criar um novo documento em resposta a um **New** ou **abra** comando da **arquivo** menu, o modelo de documento também cria uma nova janela de quadro por meio da qual exibir o documento.

O construtor de modelo de documento especifica quais tipos de documentos, janelas e exibições que o modelo poderá ser capaz de criar. Isso é determinado pelos argumentos que você passa para o construtor de modelo de documento. O código a seguir ilustra a criação de um [CMultiDocTemplate](../mfc/reference/cmultidoctemplate-class.md) para um aplicativo de exemplo:

[!code-cpp[NVC_MFCDocView#7](../mfc/codesnippet/cpp/document-template-creation_1.cpp)]

O ponteiro para uma nova `CMultiDocTemplate` objeto é usado como um argumento para [AddDocTemplate](../mfc/reference/cwinapp-class.md#adddoctemplate). Argumentos para o `CMultiDocTemplate` construtor incluem a ID do recurso associada com o tipo de documento menus e aceleradores e três usos do [RUNTIME_CLASS](../mfc/reference/run-time-object-model-services.md#runtime_class) macro. `RUNTIME_CLASS` Retorna o [CRuntimeClass](../mfc/reference/cruntimeclass-structure.md) objeto para a classe C++ chamado como seu argumento. Os três `CRuntimeClass` objetos passados para o construtor de modelo de documento fornecem as informações necessárias para criar novos objetos das classes especificados durante o processo de criação de documento. O exemplo mostra a criação de um modelo de documento que cria `CScribDoc` objetos com `CScribView` objetos anexados. Os modos de exibição são moldados por padrão janelas de quadro filho MDI.

## <a name="see-also"></a>Consulte também

[Modelos de documento e o processo de criação de documento/exibição](../mfc/document-templates-and-the-document-view-creation-process.md)<br/>
[Criação de documento/exibição](../mfc/document-view-creation.md)<br/>
[Relacionamentos entre objetos MFC](../mfc/relationships-among-mfc-objects.md)<br/>
[Criando novos documentos, janelas e exibições](../mfc/creating-new-documents-windows-and-views.md)

