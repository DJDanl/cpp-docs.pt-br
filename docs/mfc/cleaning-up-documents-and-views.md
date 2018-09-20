---
title: Limpando documentos e exibições | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- views [MFC], cleaning up
- documents [MFC], cleaning up
- documents [MFC], closing
ms.assetid: 0c454db2-3644-434d-9e53-8108a7aedfe1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f4325b0de10861fc76ee9ab816376f40ba0ba587
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46437411"
---
# <a name="cleaning-up-documents-and-views"></a>Limpando documentos e exibições

Quando um documento está sendo fechado, o framework chama primeiro seu [DeleteContents](../mfc/reference/cdocument-class.md#deletecontents) função de membro. Se você tiver atribuído qualquer memória no heap no decorrer da operação do documento, `DeleteContents` é o melhor lugar para desalocá-la.

> [!NOTE]
>  Você não deverá desalocar os dados de documentos no destruidor do documento. No caso de um aplicativo SDI, o objeto do documento poderá ser reutilizado.

Você pode substituir o destruidor do modo de exibição para desalocar toda a memória alocada no heap.

## <a name="see-also"></a>Consulte também

[Inicializando e limpando documentos e exibições](../mfc/initializing-and-cleaning-up-documents-and-views.md)

