---
title: 'Controles ActiveX MFC: métodos'
ms.date: 11/04/2016
helpviewer_keywords:
- MFC ActiveX controls [MFC], methods
ms.assetid: e20271de-6ffa-4ba0-848b-bafe6c9e510c
ms.openlocfilehash: 9f9ec06852ed0376583363df7649331a0be02105
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84621231"
---
# <a name="mfc-activex-controls-methods"></a>Controles ActiveX MFC: métodos

Um controle ActiveX dispara eventos para se comunicar entre si mesmo e seu contêiner de controle. Um contêiner também pode se comunicar com um controle por meio de métodos e propriedades. Os métodos também são chamados de funções.

Os métodos e as propriedades fornecem uma interface exportada para uso por outros aplicativos, como clientes de automação e contêineres de controle ActiveX. Para obter mais informações sobre as propriedades do controle ActiveX, consulte o artigo [controles ActiveX do MFC: Propriedades](mfc-activex-controls-properties.md).

Os métodos são semelhantes em uso e finalidade para as funções de membro de uma classe C++. Há dois tipos de métodos que seu controle pode implementar: Stock e Custom. Semelhante aos eventos de estoque, os métodos de ações são aqueles métodos para os quais o [COleControl](reference/colecontrol-class.md) fornece uma implementação. Para obter mais informações sobre os métodos de ações, consulte o artigo [controles ActiveX do MFC: adicionando métodos de ações](mfc-activex-controls-adding-stock-methods.md). Os métodos personalizados, definidos pelo desenvolvedor, permitem a personalização adicional do controle. Para obter mais informações, consulte o artigo [controles ActiveX do MFC: adicionando métodos personalizados](mfc-activex-controls-adding-custom-methods.md).

A biblioteca MFC (MFC) implementa um mecanismo que permite que seu controle dê suporte a ações e a métodos personalizados. A primeira parte é a classe `COleControl` . Derivado de `CWnd` , `COleControl` as funções de membro dão suporte a métodos de ações que são comuns a todos os controles ActiveX. A segunda parte desse mecanismo é o mapa de expedição. Um mapa de expedição é semelhante a um mapa de mensagens; no entanto, em vez de mapear uma função para uma ID de mensagem do Windows, um mapa de expedição mapeia funções de membro virtual para IDS de IDispatch.

Para que um controle dê suporte a vários métodos corretamente, sua classe deve declarar um mapa de expedição. Isso é feito pela linha de código a seguir localizada no cabeçalho da classe de controle (. H) arquivo:

[!code-cpp[NVC_MFC_AxUI#13](codesnippet/cpp/mfc-activex-controls-methods_1.h)]

A principal finalidade do mapa de expedição é estabelecer a relação entre os nomes de método usados por um chamador externo (como o contêiner) e as funções de membro da classe do controle que implementam os métodos. Depois que o mapa de expedição tiver sido declarado, ele precisará ser definido na implementação do controle (. CPP). As linhas de código a seguir definem o mapa de expedição:

[!code-cpp[NVC_MFC_AxUI#14](codesnippet/cpp/mfc-activex-controls-methods_2.cpp)]
[!code-cpp[NVC_MFC_AxUI#15](codesnippet/cpp/mfc-activex-controls-methods_3.cpp)]

Se você usou o [Assistente de controle ActiveX do MFC](reference/mfc-activex-control-wizard.md) para criar o projeto, essas linhas foram adicionadas automaticamente. Se o assistente de controle ActiveX do MFC não foi usado, você deve adicionar essas linhas manualmente.

Os artigos a seguir discutem os métodos em detalhes:

- [Controles ActiveX do MFC: adicionando métodos de estoque](mfc-activex-controls-adding-stock-methods.md)

- [Controles ActiveX do MFC: adicionando métodos personalizados](mfc-activex-controls-adding-custom-methods.md)

- [Controles ActiveX MFC: retornando códigos de erro a partir de um método](mfc-activex-controls-returning-error-codes-from-a-method.md)

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)
