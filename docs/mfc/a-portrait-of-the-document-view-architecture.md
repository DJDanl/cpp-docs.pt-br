---
title: Um retrato da arquitetura de exibição de documento
ms.date: 11/04/2016
helpviewer_keywords:
- documents [MFC], views
- multiple views [MFC], updating from document
- document/view architecture [MFC]
- views [MFC], and user input
- documents [MFC], accessing data from view
- views [MFC], updating
- input [MFC], view class
- documents [MFC], multiple views
- document/view architecture [MFC], accessing data from view
- document/view architecture [MFC], about document/view architecture
- views [MFC], accessing document data from
ms.assetid: 4e7f65dc-b166-45d8-bcd5-9bb0d399b946
ms.openlocfilehash: a4d89189b5389685be6b69c8502ffedb8aa731e6
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50567096"
---
# <a name="a-portrait-of-the-documentview-architecture"></a>Um retrato da arquitetura de documento/exibição

Documentos e exibições são combinadas em um aplicativo típico do MFC. Dados são armazenados no documento, mas o modo de exibição tem acesso aos dados privilegiado. A separação do documento do modo de exibição separa o armazenamento e a manutenção de dados da sua exibição.

## <a name="gaining-access-to-document-data-from-the-view"></a>Obter acesso aos dados da exibição de documento

O modo de exibição acessa dados do seu documento com o [GetDocument](../mfc/reference/cview-class.md#getdocument) de função, que retorna um ponteiro para o documento ou fazendo com que o modo de exibição de classe um C++ `friend` da classe do documento. O modo de exibição, em seguida, usa o acesso aos dados para obter os dados quando ele está pronto para desenhar ou manipulá-lo.

Por exemplo, a partir da exibição [OnDraw](../mfc/reference/cview-class.md#ondraw) função de membro, a exibição usa `GetDocument` para obter um ponteiro de documento. Em seguida, ele usa esse ponteiro para acessar um `CString` membro de dados no documento. O modo de exibição passa a cadeia de caracteres para o `TextOut` função. Para ver o código para este exemplo, consulte [desenhando uma exibição](../mfc/drawing-in-a-view.md).

## <a name="user-input-to-the-view"></a>Entrada do usuário para o modo de exibição

O modo de exibição também pode interpretar um clique do mouse em si mesmo como seleção ou edição de dados. Da mesma forma, ele poderá interpretá pressionamentos de tecla como entrada de dados ou de edição. Suponha que o usuário digita uma cadeia de caracteres em uma exibição que gerencia o texto. A exibição obtém um ponteiro para o documento e usa o ponteiro para passar os novos dados para o documento, que armazena em algumas estruturas de dados.

## <a name="updating-multiple-views-of-the-same-document"></a>Atualizando vários modos de exibição do mesmo documento

Em um aplicativo com várias exibições do mesmo documento — como uma janela separadora em um editor de texto — o modo de exibição passa pela primeira vez os novos dados para o documento. Em seguida, ele chama o documento [UpdateAllViews](../mfc/reference/cdocument-class.md#updateallviews) a função de membro, que faz com que todos os modos de exibição de documento para atualizar a mesmos, refletindo os novos dados. Isso sincroniza os modos de exibição.

### <a name="what-do-you-want-to-know-more-about"></a>O que você deseja saber mais sobre

- [Vantagens da arquitetura de documento/exibição](../mfc/advantages-of-the-document-view-architecture.md)

- [Alternativas à arquitetura de documento/exibição](../mfc/alternatives-to-the-document-view-architecture.md)

## <a name="see-also"></a>Consulte também

[Arquitetura de documento/exibição](../mfc/document-view-architecture.md)

