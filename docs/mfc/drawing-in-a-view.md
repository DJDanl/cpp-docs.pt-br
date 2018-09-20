---
title: Desenhando uma exibição | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- drawing [MFC], in views
- views [MFC], printing
- views [MFC], updating
- printing [MFC], views
- views [MFC], rendering
- printing views [MFC]
- paint messages in view class [MFC]
- device contexts, screen drawings
ms.assetid: e3761db6-0f19-4482-a4cd-ac38ef7c4d3a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d3df6ac176669114c70ebdd17985068d6b383c37
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46398801"
---
# <a name="drawing-in-a-view"></a>Desenhando uma exibição

Quase todos os de desenho em seu aplicativo ocorre no modo de exibição `OnDraw` função de membro, você deve substituir em sua classe de exibição. (A exceção é o mouse para desenhar, discutido em [Interpretando usuário entrada por meio de exibições](../mfc/interpreting-user-input-through-a-view.md).) Seu `OnDraw` substituir:

1. Obtém dados chamando funções de membro que você fornecer para o documento.

1. Exibe os dados, chamando funções de membro de um objeto de contexto de dispositivo que o framework passa para `OnDraw`.

Quando os dados de um documento é alterado de alguma forma, o modo de exibição deve ser redesenhado para refletir as alterações. Normalmente, isso acontece quando o usuário fizer uma alteração por meio de um modo de exibição no documento. Nesse caso, o modo de exibição chama o documento [UpdateAllViews](../mfc/reference/cdocument-class.md#updateallviews) a função de membro para notificar a todas as exibições no mesmo documento para atualizar-se. `UpdateAllViews` chama cada modo de exibição [OnUpdate](../mfc/reference/cview-class.md#onupdate) função de membro. A implementação padrão de `OnUpdate` invalida a área de cliente inteira da exibição. Você pode substituí-la para invalidar somente essas regiões da área de cliente que são mapeados para as partes modificadas do documento.

O `UpdateAllViews` função de membro da classe `CDocument` e o `OnUpdate` a função de membro da classe `CView` permitem que você passe informações que descrevem quais partes do documento foram modificadas. Esse mecanismo de "dica" permite limitar a área que o modo de exibição deve redesenhar. `OnUpdate` leva dois argumentos de "dica". A primeira *lHint*, do tipo **LPARAM**, permite que você passe todos os dados que desejar, enquanto o segundo *pHint*, do tipo `CObject`*, permite que você passe um ponteiro para qualquer objeto derivado de `CObject`.

Quando um modo de exibição se torna inválido, Windows envia um **WM_PAINT** mensagem. O modo de exibição [OnPaint](../mfc/reference/cwnd-class.md#onpaint) função de manipulador responde à mensagem com a criação de um objeto de contexto de dispositivo da classe [CPaintDC](../mfc/reference/cpaintdc-class.md) e chama seu modo de exibição `OnDraw` função de membro. Normalmente não é necessário gravar um substituindo `OnPaint` função do manipulador.

Um [contexto de dispositivo](../mfc/device-contexts.md) é uma estrutura de dados do Windows que contém informações sobre os atributos de desenho de um dispositivo como uma exibição ou uma impressora. Todas as chamadas de desenho são feitas por meio de um objeto de contexto de dispositivo. Para desenhar na tela, `OnDraw` é passado um `CPaintDC` objeto. Para desenhar em uma impressora, ela é passada uma [CDC](../mfc/reference/cdc-class.md) objeto definido para a impressora atual.

Primeiro, seu código para desenhar no modo de exibição recupera um ponteiro para o documento e faz chamadas de desenho por meio do contexto do dispositivo. O simples a seguir `OnDraw` exemplo ilustra o processo:

[!code-cpp[NVC_MFCDocView#1](../mfc/codesnippet/cpp/drawing-in-a-view_1.cpp)]

Neste exemplo, você definiria o `GetData` funcionar como um membro da sua classe derivada de documento.

O exemplo imprime qualquer cadeia de caracteres que ele recebe do documento, centralizado na exibição. Se o `OnDraw` chamada é para o desenho da tela, o `CDC` objeto passado *pDC* é um `CPaintDC` cujo construtor já tiver sido chamado `BeginPaint`. Chamadas para funções de desenho são feitas através do ponteiro de contexto de dispositivo. Para obter informações sobre contextos de dispositivo e chamadas de desenho, consulte a classe [CDC](../mfc/reference/cdc-class.md) na *referência da MFC* e [trabalhando com objetos de janela](../mfc/working-with-window-objects.md).

Para obter mais exemplos de como escrever `OnDraw`, consulte o [exemplos de MFC](../visual-cpp-samples.md).

## <a name="see-also"></a>Consulte também

[Usando exibições](../mfc/using-views.md)

