---
title: 'Arrastar e soltar: Personalizando | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- drag and drop [MFC], implementing in non-OLE applications
- drag and drop [MFC], customizing behavior
- drag and  [MFC], COleDataSource object
- drag and drop [MFC], calling DoDragDrop
- OLE drag and drop [MFC], customizing behavior
ms.assetid: 03369d3e-46bf-4140-b58c-d0c9657cf38a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7dd7e88d6843ec3d95538e482c6c05a3d853f4d1
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46390754"
---
# <a name="drag-and-drop-customizing"></a>Arrastar e soltar: personalizando

A implementação padrão do recurso de arrastar e soltar é suficiente para a maioria dos aplicativos. No entanto, alguns aplicativos podem exigir que esse comportamento padrão ser alterado. Este artigo explica as etapas necessárias para alterar esses padrões. Além disso, você pode usar essa técnica para estabelecer a aplicativos que não dão suporte a documentos compostos como fontes de soltar.

Se estiver personalizando o comportamento de arrastar e soltar OLE padrão ou se você tiver um aplicativo não são OLE, você deve criar um `COleDataSource` objeto para conter os dados. Quando o usuário inicia uma operação de arrastar e soltar, o seu código deverá chamar o `DoDragDrop` função deste objeto, em vez de outras classes que dão suporte a operações de arrastar e soltar.

Opcionalmente, você pode criar um `COleDropSource` objeto para controlar o posicionamento e substituir algumas de suas funções, dependendo do tipo de comportamento que você deseja alterar. Esse objeto de origem de soltar, em seguida, é passado para `COleDataSource::DoDragDrop` para alterar o comportamento padrão dessas funções. Essas opções diferentes permitem uma grande quantidade de flexibilidade em como dar suporte a operações de arrastar e soltar em seu aplicativo. Para obter mais informações sobre fontes de dados, consulte o artigo [objetos de dados e fontes de dados (OLE)](../mfc/data-objects-and-data-sources-ole.md).

Você pode substituir as funções a seguir para personalizar as operações de arrastar e soltar:

|Substituições|Para personalizar|
|--------------|------------------|
|`OnBeginDrag`|Como arrastar for iniciado depois de chamar `DoDragDrop`.|
|`GiveFeedback`|Comentários visuais, como a aparência do cursor, para soltar diferentes resultados.|
|`QueryContinueDrag`|O encerramento de uma operação de arrastar e soltar. Essa função permite que você verifique estados principais de modificador durante a operação de arrastar.|

## <a name="see-also"></a>Consulte também

[Arrastar e soltar (OLE)](../mfc/drag-and-drop-ole.md)<br/>
[Classe COleDropSource](../mfc/reference/coledropsource-class.md)<br/>
[Classe COleDataSource](../mfc/reference/coledatasource-class.md)
