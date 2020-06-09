---
title: Modelos de documento e o processo de criação de exibição de documento
ms.date: 11/19/2018
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
ms.openlocfilehash: b96a11926927e89890ca268dcff7d347079b25fb
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84615771"
---
# <a name="document-templates-and-the-documentview-creation-process"></a>Modelos de documento e o processo de criação de documento/exibição

Para gerenciar o processo complexo de criação de documentos com suas exibições associadas e janelas de quadros, a estrutura usa duas classes de modelo de documento: [CSingleDocTemplate](reference/csingledoctemplate-class.md) para aplicativos SDI e [CMULTIDOCTEMPLATE](reference/cmultidoctemplate-class.md) para aplicativos MDI. Um `CSingleDocTemplate` pode criar e armazenar um documento de um tipo por vez. Um `CMultiDocTemplate` mantém uma lista de muitos documentos abertos de um tipo.

Alguns aplicativos dão suporte a vários tipos de documento. Por exemplo, um aplicativo pode dar suporte a documentos de texto e documentos gráficos. Nesse aplicativo, quando o usuário escolhe o comando novo no menu arquivo, uma caixa de diálogo mostra uma lista de possíveis tipos de documentos novos a serem abertos. Para cada tipo de documento com suporte, o aplicativo usa um objeto de modelo de documento distinto. A figura a seguir ilustra a configuração de um aplicativo MDI que dá suporte a dois tipos de documento e mostra vários documentos abertos.

![Aplicativo MDI que tem dois tipos de documento](../mfc/media/vc387h1.gif "Aplicativo MDI que tem dois tipos de documento") <br/>
Um aplicativo MDI com dois tipos de documento

Os modelos de documento são criados e mantidos pelo objeto de aplicativo. Uma das principais tarefas executadas durante a função do seu aplicativo `InitInstance` é construir um ou mais modelos de documento do tipo apropriado. Esse recurso é descrito em [criação de modelo de documento](document-template-creation.md). O objeto de aplicativo armazena um ponteiro para cada modelo de documento em sua lista de modelos e fornece uma interface para adicionar modelos de documento.

Se você precisar dar suporte a dois ou mais tipos de documento, deverá adicionar uma chamada extra para [AddDocTemplate](reference/cwinapp-class.md#adddoctemplate) para cada tipo de documento.

Um ícone é registrado para cada modelo de documento com base em sua posição na lista de modelos de documento do aplicativo. A ordem dos modelos de documento é determinada pela ordem em que são adicionados com chamadas para `AddDocTemplate` . O MFC pressupõe que o primeiro recurso de ícone no aplicativo é o ícone do aplicativo, o próximo ícone de recurso é o primeiro ícone de documento e assim por diante.

Por exemplo, um modelo de documento é o terceiro de três para o aplicativo. Se houver um recurso de ícone no aplicativo no índice 3, esse ícone será usado para o modelo de documento. Caso contrário, o ícone no índice 0 é usado como padrão.

## <a name="see-also"></a>Consulte também

[Tópicos MFC gerais](general-mfc-topics.md)<br/>
[Criação do modelo de documento](document-template-creation.md)<br/>
[Criação de documento/exibição](document-view-creation.md)<br/>
[Relacionamentos entre objetos MFC](relationships-among-mfc-objects.md)<br/>
[Criando novos documentos, janelas e exibições](creating-new-documents-windows-and-views.md)
