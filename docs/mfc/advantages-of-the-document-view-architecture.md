---
title: Vantagens da arquitetura do modo de exibição de documentos | Microsoft Docs
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
ms.openlocfilehash: 45065b38128a2e3239b1fd10ded490fdcbcb3eac
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33340842"
---
# <a name="advantages-of-the-documentview-architecture"></a>Vantagens da arquitetura de documento/exibição
A vantagem principal de usar a arquitetura de documento/exibição MFC é que a arquitetura oferece suporte a várias exibições do mesmo documento muito bem. (Se você não precisa vários modos de exibição e pequena sobrecarga de documento/exibição é excessiva em seu aplicativo, você poderá evitar a arquitetura. [Alternativas à arquitetura de documento/exibição](../mfc/alternatives-to-the-document-view-architecture.md).)  
  
 Suponha que seu aplicativo, que permite aos usuários exibir dados numéricos em forma de planilha ou em formato de gráfico. Um usuário talvez queira visualizar simultaneamente ambos os dados brutos, no formulário de planilha e um gráfico que é o resultado dos dados. Você exibir essas exibições separadas em janelas com moldura separado ou em painéis de separador dentro de uma única janela. Agora suponha que o usuário pode editar os dados na planilha e veja as alterações imediatamente refletem no gráfico.  
  
 Em MFC, a exibição de planilha e o gráfico seriam baseados em diferentes classes derivadas de CView. Ambos os modos de exibição será associados um objeto de documento único. O documento armazena os dados (ou talvez obtém-lo de um banco de dados). Ambos os modos de exibição de acessá-lo e exibem os dados que eles recuperem dele.  
  
 Quando um usuário atualiza um dos modos de exibição, o que exibir chamadas do objeto `CDocument::UpdateAllViews`. Essa função notifica sobre todos os modos de exibição do documento, e cada exibição atualiza a mesmo usando os dados mais recentes do documento. A única chamada para `UpdateAllViews` sincroniza as exibições diferentes.  
  
 Este cenário seria difícil de código sem a separação dos dados da exibição, especialmente se os modos de exibição armazenaram os dados em si. Com a exibição de documentos, é fácil. A estrutura faz a maior parte do trabalho de coordenação para você.  
  
## <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre  
  
-   [Alternativas para documento/exibição](../mfc/alternatives-to-the-document-view-architecture.md)  
  
-   [CDocument](../mfc/reference/cdocument-class.md)  
  
-   [CView](../mfc/reference/cview-class.md)  
  
-   [CDocument::UpdateAllViews](../mfc/reference/cdocument-class.md#updateallviews)  
  
-   [CView::GetDocument](../mfc/reference/cview-class.md#getdocument)  
  
## <a name="see-also"></a>Consulte também  
 [Arquitetura de documento/exibição](../mfc/document-view-architecture.md)

