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
ms.openlocfilehash: 952a383792eb3a4d0a4ed1b3e24dd82f7fa644cf
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615792"
---
# <a name="document-template-creation"></a>Criação do modelo de documento

Ao criar um novo documento em resposta a um comando **novo** ou **abrir** no menu **arquivo** , o modelo de documento também cria uma nova janela de quadro por meio da qual exibir o documento.

O Construtor documento-modelo especifica que tipos de documentos, janelas e exibições o modelo será capaz de criar. Isso é determinado pelos argumentos que você passa para o Construtor documento-modelo. O código a seguir ilustra a criação de um [CMultiDocTemplate](reference/cmultidoctemplate-class.md) para um aplicativo de exemplo:

[!code-cpp[NVC_MFCDocView#7](codesnippet/cpp/document-template-creation_1.cpp)]

O ponteiro para um novo `CMultiDocTemplate` objeto é usado como um argumento para [AddDocTemplate](reference/cwinapp-class.md#adddoctemplate). Os argumentos para o `CMultiDocTemplate` Construtor incluem a ID de recurso associada aos menus e aceleradores do tipo de documento, e três usos da macro [RUNTIME_CLASS](reference/run-time-object-model-services.md#runtime_class) . `RUNTIME_CLASS`Retorna o objeto [CRuntimeClass](reference/cruntimeclass-structure.md) para a classe C++ nomeada como seu argumento. Os três `CRuntimeClass` objetos passados para o Construtor documento-template fornecem as informações necessárias para criar novos objetos das classes especificadas durante o processo de criação do documento. O exemplo mostra a criação de um modelo de documento que cria `CScribDoc` objetos com `CScribView` objetos anexados. As exibições são emolduradas por janelas de quadros filho MDI padrão.

## <a name="see-also"></a>Consulte também

[Modelos de documento e o processo de criação de documento/exibição](document-templates-and-the-document-view-creation-process.md)<br/>
[Criação de documento/exibição](document-view-creation.md)<br/>
[Relacionamentos entre objetos MFC](relationships-among-mfc-objects.md)<br/>
[Criando novos documentos, janelas e exibições](creating-new-documents-windows-and-views.md)
