---
title: 'Arrastar e soltar: Implementando um destino de soltar | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- OLE drag and drop [MFC], implementing drop targets
- OLE drag and drop [MFC], drop target
- drag and drop [MFC], drop target
ms.assetid: 0689f1ec-5326-4008-b226-4b373c881358
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fae6a5ef0e25b0e81b21dce9069c599e59e1c431
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46377732"
---
# <a name="drag-and-drop-implementing-a-drop-target"></a>Arrastar e soltar: implementando um destino de soltar

Este artigo descreve como tornar seu aplicativo em um destino de soltar. Implementar um destino de soltar leva um pouco mais trabalhoso do que a implementação de uma origem para soltar, mas ele ainda é relativamente simple. Essas técnicas também se aplicam a aplicativos não são OLE.

#### <a name="to-implement-a-drop-target"></a>Para implementar um destino de soltar

1. Adicione uma variável de membro para cada modo de exibição no aplicativo que você deseja ser um destino de soltar. Essa variável de membro deve ser do tipo `COleDropTarget` ou a uma classe derivada.

1. Da função da sua classe de exibição que manipula o **WM_CREATE** mensagem (normalmente `OnCreate`), chamar a variável de membro novo `Register` função de membro. `Revoke` será chamado automaticamente para você quando o modo de exibição é destruído.

1. Substitua as funções a seguir. Se você quiser o mesmo comportamento em todo o aplicativo, substitua essas funções em sua classe de exibição. Se você quiser modificar o comportamento em casos isolados ou deseja habilitar descartando em não -`CView` windows, substitua essas funções em seu `COleDropTarget`-classe derivada.

    |Substituições|Para permitir|
    |--------------|--------------|
    |`OnDragEnter`|Descarte operações ocorra na janela. Chamado quando o cursor entra primeiro na janela.|
    |`OnDragLeave`|Comportamento especial quando a operação de arrastar deixa a janela especificada.|
    |`OnDragOver`|Descarte operações ocorra na janela. Chamado quando o cursor está sendo arrastado ao longo da janela.|
    |`OnDrop`|Manipulação de dados que está sendo soltas dentro da janela especificada.|
    |`OnScrollBy`|Comportamento especial quando rolagem é necessária na janela de destino.|

Consulte o MAINVIEW. CPP arquivo que é parte do exemplo OLE do MFC [OCLIENT](../visual-cpp-samples.md) para obter um exemplo de como funcionam essas funções.

Para obter mais informações, consulte:

- [Implementando uma origem para soltar](../mfc/drag-and-drop-implementing-a-drop-source.md)

- [Criação e destruição de objetos OLE e fontes de dados](../mfc/data-objects-and-data-sources-creation-and-destruction.md)

- [Manipulação de fontes de dados e objetos de dados OLE](../mfc/data-objects-and-data-sources-manipulation.md)

## <a name="see-also"></a>Consulte também

[Arrastar e soltar (OLE)](../mfc/drag-and-drop-ole.md)<br/>
[Classe COleDropTarget](../mfc/reference/coledroptarget-class.md)
