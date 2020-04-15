---
title: 'Controles ActiveX MFC: adicionando métodos personalizados'
ms.date: 09/12/2018
helpviewer_keywords:
- MFC ActiveX controls [MFC], methods
- PtInCircle custom method [MFC]
ms.assetid: 8f8dc344-44a0-4021-8db5-4cdd3d700e18
ms.openlocfilehash: 88d486248eab5d980463764db34bf40b05b830dc
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81364707"
---
# <a name="mfc-activex-controls-adding-custom-methods"></a>Controles ActiveX MFC: adicionando métodos personalizados

Os métodos personalizados diferem dos métodos de `COleControl`estoque, pois ainda não são implementados por . Você deve fornecer a implementação para cada método personalizado que você adicionar ao seu controle.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituim o ActiveX, consulte [ActiveX Controls](activex-controls.md).

Um usuário de controle ActiveX pode chamar um método personalizado a qualquer momento para executar ações específicas de controle. A entrada do mapa de despacho para métodos personalizados é do formulário DISP_FUNCTION.

## <a name="adding-a-custom-method-with-the-add-method-wizard"></a><a name="_core_adding_a_custom_method_with_classwizard"></a>Adicionando um método personalizado com o assistente de método de adicionar

O procedimento a seguir demonstra a adição do método personalizado PtInCircle ao código esqueleto de um controle ActiveX. O PtInCircle determina se as coordenadas passadas para o controle estão dentro ou fora do círculo. Este mesmo procedimento também pode ser usado para adicionar outros métodos personalizados. Substitua o nome do método personalizado e seus parâmetros pelo nome e parâmetros do método PtInCircle.

> [!NOTE]
> Este exemplo `InCircle` usa a função do artigo Eventos. Para obter mais informações sobre esta função, consulte o artigo [MFC ActiveX Controls: Adding Custom Events to a ActiveX Control](../mfc/mfc-activex-controls-adding-custom-events.md).

#### <a name="to-add-the-ptincircle-custom-method-using-the-add-method-wizard"></a>Para adicionar o método personalizado PtInCircle usando o Assistente de Método de Adicionar

1. Carregue o projeto do controle.

1. Em Class View, expanda o nó de biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó de interface para o seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, clique **em Adicionar** e clique em **Adicionar método**.

   Isso abre o Assistente de Método de Adicionar.

1. Na caixa Nome do **método,** digite *PtInCircle*.

1. Na caixa **Nome Interno,** digite o nome da função interna do método ou use o valor padrão (neste caso, *PtInCircle*).

1. Na caixa **Tipo de retorno,** clique **em VARIANT_BOOL** para o tipo de retorno do método.

1. Usando os controles **Tipo de parâmetro** e nome do **parâmetro,** adicione um parâmetro chamado *xCoord* (tipo *OLE_XPOS_PIXELS*).

1. Usando os controles **Tipo de parâmetro** e nome do **parâmetro,** adicione um parâmetro chamado *yCoord* (tipo *OLE_YPOS_PIXELS*).

1. Clique em **Concluir**.

## <a name="add-method-wizard-changes-for-custom-methods"></a><a name="_core_classwizard_changes_for_custom_methods"></a>Adicionar alterações do assistente de método para métodos personalizados

Quando você adiciona um método personalizado, o Assistente de Método adicionar faz algumas alterações no cabeçalho da classe de controle (. H) e implementação (. CPP) arquivos. A linha a seguir é adicionada à declaração do mapa de despacho no cabeçalho da classe de controle (. Arquivo H:

[!code-cpp[NVC_MFC_AxUI#18](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-methods_1.h)]

Este código declara um manipulador `PtInCircle`de método de despacho chamado . Esta função pode ser chamada pelo usuário `PtInCircle`de controle usando o nome externo .

A linha a seguir é adicionada ao controle. Arquivo IDL:

[!code-cpp[NVC_MFC_AxUI#19](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-methods_2.idl)]

Esta linha atribui `PtInCircle` ao método um número de ID específico, a posição do método na lista de métodos e propriedades do Assistente de Método de Adicionar. Como o Assistente de Método de adicionar foi usado para adicionar o método personalizado, a entrada para ele foi adicionada automaticamente ao do projeto . Arquivo IDL.

Além disso, a seguinte linha, localizada na implementação (. CPP) arquivo da classe de controle, é adicionado ao mapa de despacho do controle:

[!code-cpp[NVC_MFC_AxUI#20](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-methods_3.cpp)]

A macro DISP_FUNCTION `PtInCircle` mapeia o método `PtInCircle`para a função de manipulador do controle, declara o tipo de `PtInCircle`retorno a ser **VARIANT_BOOL**e declara dois parâmetros de **VTS_XPOS_PIXELS** tipo e **VTS_YPOSPIXELS** a serem passados para .

Finalmente, o Assistente de Método `CSampleCtrl::PtInCircle` de adicionar adiciona a função stub à parte inferior da implementação do controle (. CPP) arquivo. Para `PtInCircle` funcionar como dito anteriormente, ele deve ser modificado da seguinte forma:

[!code-cpp[NVC_MFC_AxUI#21](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-methods_4.cpp)]

## <a name="see-also"></a>Confira também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Ícones de visualização de classe e navegador de objetos](/visualstudio/ide/class-view-and-object-browser-icons)
