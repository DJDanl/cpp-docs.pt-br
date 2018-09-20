---
title: Criação de exibição de documento | Microsoft Docs
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
ms.openlocfilehash: 0deb187a6540af71a1dc72b730347374bc25f963
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46423046"
---
# <a name="documentview-creation"></a>Criação de documento/exibição

O framework fornece implementações da **New** e **aberto** comandos (entre outros) nos **arquivo** menu. Criação de um novo documento e a exibição associada e a janela do quadro é um esforço cooperativo entre o objeto de aplicativo, um modelo de documento, o documento recém-criado e a janela do quadro recém-criado. A tabela a seguir resume quais objetos de criar o que.

### <a name="object-creators"></a>Criadores de objeto

|Criador|Cria|
|-------------|-------------|
|Objeto de aplicativo|Modelo de documento|
|Modelo de documento|Documento|
|Modelo de documento|Janela do quadro|
|Janela do quadro|Exibir|

## <a name="see-also"></a>Consulte também

[Modelos de documento e o processo de criação de documento/exibição](../mfc/document-templates-and-the-document-view-creation-process.md)<br/>
[Criação do modelo de documento](../mfc/document-template-creation.md)<br/>
[Relacionamentos entre objetos MFC](../mfc/relationships-among-mfc-objects.md)<br/>
[Criando novos documentos, janelas e exibições](../mfc/creating-new-documents-windows-and-views.md)

