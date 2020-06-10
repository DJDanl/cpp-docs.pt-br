---
title: Criação de exibição de documento
ms.date: 11/04/2016
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
ms.openlocfilehash: 5441827188f5bff98638cc85cd29e2efd79f8ae8
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620336"
---
# <a name="documentview-creation"></a>Criação de documento/exibição

A estrutura fornece implementações dos comandos **novos** e **abertos** (entre outros) no menu **arquivo** . A criação de um novo documento e sua exibição e janela de quadro associadas são um esforço cooperativo entre o objeto de aplicativo, um modelo de documento, o documento recém-criado e a janela de quadros recém-criada. A tabela a seguir resume quais objetos criam o quê.

### <a name="object-creators"></a>Criadores de objeto

|Criador|Cria|
|-------------|-------------|
|Objeto de aplicativo|Modelo de documento|
|Modelo de documento|Document|
|Modelo de documento|Janela do quadro|
|Janela do quadro|Visualizar|

## <a name="see-also"></a>Consulte também

[Modelos de documento e o processo de criação de documento/exibição](document-templates-and-the-document-view-creation-process.md)<br/>
[Criação do modelo de documento](document-template-creation.md)<br/>
[Relacionamentos entre objetos MFC](relationships-among-mfc-objects.md)<br/>
[Criando novos documentos, janelas e exibições](creating-new-documents-windows-and-views.md)
