---
title: Vantagens da arquitetura de exibição de documento | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- views [MFC], advantages
- document/view architecture [MFC], advantages of
ms.assetid: 0bc27071-e120-4889-939c-ce1e61fb9cb3
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 213fc108b11d6056df6696f92658e74a736c4a16
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46392834"
---
# <a name="advantages-of-the-documentview-architecture"></a>Vantagens da arquitetura de documento/exibição

A principal vantagem de usar a arquitetura de exibição/documento MFC é que a arquitetura oferece suporte a vários modos de exibição do mesmo documento muito bem. (Se você não precisa de vários modos de exibição e a pequena sobrecarga de documento/exibição é excessiva em seu aplicativo, você pode evitar a arquitetura. [Alternativas à arquitetura de documento/exibição](../mfc/alternatives-to-the-document-view-architecture.md).)

Suponha que seu aplicativo, que permite aos usuários exibir dados numéricos na forma de planilha ou em formato de gráfico. Um usuário pode querer ver simultaneamente os dados brutos, no formulário de planilha e um gráfico que é o resultado dos dados. Você exibir esses modos de exibição separados em janelas com moldura separado ou em painéis de divisor dentro de uma única janela. Suponha que o usuário pode editar os dados na planilha e consulte agora as alterações refletem imediatamente no gráfico.

No MFC, o modo de exibição da planilha e o modo de exibição de gráfico seriam baseados em diferentes classes derivadas de CView. Ambos os modos de exibição será associados um objeto de documento único. O documento armazena os dados (ou talvez obtém-lo de um banco de dados). Ambos os modos de exibição acessá-lo e exibem os dados que recuperam dele.

Quando um usuário atualiza um dos modos de exibição, o que exibir chamadas de objeto `CDocument::UpdateAllViews`. Essa função notifica todos os modos de exibição do documento, e cada exibição atualiza a mesmo usando os dados mais recentes do documento. A única chamada para `UpdateAllViews` sincroniza as exibições diferentes.

Esse cenário seria difícil de código sem a separação dos dados da exibição, especialmente se os modos de exibição armazenado os dados em si. Documento/exibição, é fácil. A estrutura faz grande parte do trabalho de coordenação para você.

## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Alternativas ao documento/exibição](../mfc/alternatives-to-the-document-view-architecture.md)

- [CDocument](../mfc/reference/cdocument-class.md)

- [CView](../mfc/reference/cview-class.md)

- [CDocument::UpdateAllViews](../mfc/reference/cdocument-class.md#updateallviews)

- [CView::GetDocument](../mfc/reference/cview-class.md#getdocument)

## <a name="see-also"></a>Consulte também

[Arquitetura de documento/exibição](../mfc/document-view-architecture.md)

