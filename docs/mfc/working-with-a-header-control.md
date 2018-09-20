---
title: Trabalhando com um controle de cabeçalho | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- header controls [MFC], working with
- header controls
ms.assetid: af3afb5c-bf97-451b-8fee-3adcb8257210
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 6da3ffd669ebd3d9cc02fc56a13acfa1fe804e7b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46381715"
---
# <a name="working-with-a-header-control"></a>Trabalhando com um controle de cabeçalho

A maneira fácil de usar um controle de cabeçalho ([CHeaderCtrl](../mfc/reference/cheaderctrl-class.md)) está em conjunto com um controle de lista, consulte [usando CListCtrl](../mfc/using-clistctrl.md) posterior nesta família de tópico. Você também pode usar um controle de cabeçalho por si só. MFC chama `InitCommonControls` para você. As tarefas principais são da seguinte maneira:

- [Criando o controle de cabeçalho](../mfc/creating-the-header-control.md)

- [Adicionando itens ao controle de cabeçalho](../mfc/adding-items-to-the-header-control.md)

- [Ordenando itens no controle de cabeçalho](../mfc/ordering-items-in-the-header-control.md)

- [Processando notificações de controle de cabeçalho](../mfc/processing-header-control-notifications.md)

Se o objeto de controle de cabeçalho é inserido em uma classe de exibição ou a caixa de diálogo pai, o controle é destruído quando o pai é destruído.

## <a name="see-also"></a>Consulte também

[Usando CHeaderCtrl](../mfc/using-cheaderctrl.md)<br/>
[Controles](../mfc/controls-mfc.md)

