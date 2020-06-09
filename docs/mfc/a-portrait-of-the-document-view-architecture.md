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
ms.openlocfilehash: f0e71c42004b5409eeb6f5e2ddabd33296cf5f49
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623442"
---
# <a name="a-portrait-of-the-documentview-architecture"></a>Um retrato da arquitetura de documento/exibição

Os documentos e as exibições são emparelhados em um aplicativo típico do MFC. Os dados são armazenados no documento, mas a exibição tem acesso privilegiado aos dados. A separação do documento da exibição separa o armazenamento e a manutenção dos dados de sua exibição.

## <a name="gaining-access-to-document-data-from-the-view"></a>Obtendo acesso aos dados do documento da exibição

A exibição acessa os dados do documento com a função [GetDocument](reference/cview-class.md#getdocument) , que retorna um ponteiro para o documento ou torna a classe View um C++ `friend` da classe Document. Em seguida, a exibição usa seu acesso aos dados para obter os dados quando estiver pronto para desenhar ou, de outra forma, manipulá-los.

Por exemplo, na função de membro [OnDraw](reference/cview-class.md#ondraw) da exibição, o modo de exibição usa `GetDocument` para obter um ponteiro de documento. Em seguida, ele usa esse ponteiro para acessar um `CString` membro de dados no documento. A exibição passa a cadeia de caracteres para a `TextOut` função. Para ver o código deste exemplo, consulte [desenho em uma exibição](drawing-in-a-view.md).

## <a name="user-input-to-the-view"></a>Entrada do usuário para a exibição

A exibição também pode interpretar um clique do mouse dentro dele mesmo como uma seleção ou edição de dados. Da mesma forma, ele pode interpretar pressionamentos de teclas como entrada ou edição de dados. Suponha que o usuário digita uma cadeia de caracteres em uma exibição que gerencia o texto. A exibição Obtém um ponteiro para o documento e usa o ponteiro para passar os novos dados para o documento, que os armazena em alguma estrutura de dados.

## <a name="updating-multiple-views-of-the-same-document"></a>Atualizando várias exibições do mesmo documento

Em um aplicativo com várias exibições do mesmo documento — como uma janela divisora em um editor de texto — a exibição primeiro passa os novos dados para o documento. Em seguida, ele chama a função de membro [UpdateAllViews](reference/cdocument-class.md#updateallviews) do documento, que informa todas as exibições do documento a serem atualizadas, refletindo os novos dados. Isso sincroniza as exibições.

### <a name="what-do-you-want-to-know-more-about"></a>Do que você deseja saber mais sobre

- [Vantagens da arquitetura de documento/exibição](advantages-of-the-document-view-architecture.md)

- [Alternativas para a arquitetura de documento/exibição](alternatives-to-the-document-view-architecture.md)

## <a name="see-also"></a>Consulte também

[Arquitetura de documento/exibição](document-view-architecture.md)
