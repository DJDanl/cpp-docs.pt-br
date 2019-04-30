---
title: 'Controles ActiveX MFC: Métodos'
ms.date: 11/04/2016
helpviewer_keywords:
- MFC ActiveX controls [MFC], methods
ms.assetid: e20271de-6ffa-4ba0-848b-bafe6c9e510c
ms.openlocfilehash: 71c4cdd5ea07b3468b7878a221129a0de5eb4974
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62386363"
---
# <a name="mfc-activex-controls-methods"></a>Controles ActiveX MFC: Métodos

Um controle ActiveX aciona eventos para se comunicar entre si e seu contêiner de controle. Um contêiner também pode se comunicar com um controle por meio de métodos e propriedades. Métodos também são chamados de funções.

Métodos e propriedades fornecem uma interface de exportado para uso por outros aplicativos, como clientes de automação e contêineres de controle ActiveX. Para obter mais informações sobre propriedades do controle ActiveX, consulte o artigo [controles ActiveX MFC: Propriedades](../mfc/mfc-activex-controls-properties.md).

Métodos são semelhantes em uso e a finalidade para as funções de membro de uma classe C++. Há dois tipos de métodos de seu controle pode implementar: estoque e personalizadas. Semelhantes a eventos de estoque, métodos de estoque são os métodos para os quais [COleControl](../mfc/reference/colecontrol-class.md) fornece uma implementação. Para obter mais informações sobre métodos de estoque, consulte o artigo [controles ActiveX MFC: Adicionando métodos de estoque](../mfc/mfc-activex-controls-adding-stock-methods.md). Métodos personalizados, definidos pelo desenvolvedor, permitem a personalização adicional do controle. Para obter mais informações, consulte o artigo [controles ActiveX MFC: Adicionando métodos personalizados](../mfc/mfc-activex-controls-adding-custom-methods.md).

O Microsoft Foundation Class Library (MFC) implementa um mecanismo que permite que o controle dar suporte a ações e métodos personalizados. A primeira parte é a classe `COleControl`. Derivado `CWnd`, `COleControl` funções de membro dão suporte a métodos de estoque que são comuns a todos os controles ActiveX. A segunda parte desse mecanismo é o mapa de expedição. Um mapa de expedição é semelhante a um mapa de mensagem No entanto, em vez de uma função de mapeamento para uma ID de mensagem do Windows, um mapa de expedição mapeia as funções de membro virtual para IDS de IDispatch.

Para um controle dar suporte a vários métodos corretamente, sua classe deve declarar um mapa de expedição. Isso é feito usando a seguinte linha de código localizado no cabeçalho de classe de controle (. H) arquivo:

[!code-cpp[NVC_MFC_AxUI#13](../mfc/codesnippet/cpp/mfc-activex-controls-methods_1.h)]

É a principal finalidade do mapa de expedição estabelecer a relação entre os nomes do método usado por um chamador externo (por exemplo, o contêiner) e as funções de membro da classe do controle que implementam os métodos. Depois que o mapa de expedição foi declarado, ele precisa ser definido na implementação do controle (. Arquivo CPP). As seguintes linhas de código definem o mapa de expedição:

[!code-cpp[NVC_MFC_AxUI#14](../mfc/codesnippet/cpp/mfc-activex-controls-methods_2.cpp)]
[!code-cpp[NVC_MFC_AxUI#15](../mfc/codesnippet/cpp/mfc-activex-controls-methods_3.cpp)]

Se você tiver usado o [Assistente de controle ActiveX MFC](../mfc/reference/mfc-activex-control-wizard.md) para criar o projeto, essas linhas foram adicionadas automaticamente. Se o Assistente de controle de ActiveX do MFC não tiver sido usado, você deve adicionar essas linhas manualmente.

Os artigos a seguir abordam métodos em detalhes:

- [Controles ActiveX MFC: adicionar métodos de estoque](../mfc/mfc-activex-controls-adding-stock-methods.md)

- [Controles ActiveX MFC: adicionar métodos personalizados](../mfc/mfc-activex-controls-adding-custom-methods.md)

- [Controles ActiveX MFC: retornar códigos de erro a partir de um método](../mfc/mfc-activex-controls-returning-error-codes-from-a-method.md)

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)
