---
title: Vantagens da arquitetura de exibição de documentos
ms.date: 11/04/2016
helpviewer_keywords:
- views [MFC], advantages
- document/view architecture [MFC], advantages of
ms.assetid: 0bc27071-e120-4889-939c-ce1e61fb9cb3
ms.openlocfilehash: 80f7141ec62d509defdea361586399bd375df0d1
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623271"
---
# <a name="advantages-of-the-documentview-architecture"></a>Vantagens da arquitetura de documento/exibição

A principal vantagem de usar a arquitetura de exibição/documento do MFC é que a arquitetura dá suporte a várias exibições do mesmo documento muito bem. (Se você não precisar de várias exibições e a pequena sobrecarga de documento/exibição for excessiva em seu aplicativo, você poderá evitar a arquitetura. [Alternativas para a arquitetura de documento/exibição](alternatives-to-the-document-view-architecture.md).)

Suponha que seu aplicativo permita que os usuários exibam dados numéricos em forma de planilha ou em formato de gráfico. Um usuário pode querer ver simultaneamente os dados brutos, em forma de planilha e um gráfico que resulta dos dados. Você exibe essas exibições separadas em janelas de quadros separadas ou em painéis de divisores dentro de uma única janela. Agora suponha que o usuário possa editar os dados na planilha e ver as alterações refletidas instantaneamente no gráfico.

No MFC, a exibição de planilha e a exibição de gráfico seriam baseadas em classes diferentes derivadas de Cvisualização. Ambos os modos de exibição seriam associados a um único objeto de documento. O documento armazena os dados (ou talvez os obtenha de um banco de dado). Ambos os modos de exibição acessam o documento e exibem os dados que eles recuperam dele.

Quando um usuário atualiza uma das exibições, essa exibição chama o objeto `CDocument::UpdateAllViews` . Essa função notifica todas as exibições do documento e cada exibição se atualiza usando os dados mais recentes do documento. A chamada única para `UpdateAllViews` sincroniza as diferentes exibições.

Esse cenário seria difícil de codificar sem a separação de dados da exibição, particularmente se as exibições armazenavam os dados em si. Com o documento/exibição, é fácil. A estrutura faz a maior parte do trabalho de coordenação para você.

## <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Alternativas para documento/exibição](alternatives-to-the-document-view-architecture.md)

- [CDocument](reference/cdocument-class.md)

- [CView](reference/cview-class.md)

- [CDocument:: UpdateAllViews](reference/cdocument-class.md#updateallviews)

- [Cvisualização:: GetDocument](reference/cview-class.md#getdocument)

## <a name="see-also"></a>Consulte também

[Arquitetura de documento/exibição](document-view-architecture.md)
