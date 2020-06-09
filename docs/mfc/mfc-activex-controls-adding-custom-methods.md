---
title: 'Controles ActiveX MFC: adicionando métodos personalizados'
ms.date: 09/12/2018
helpviewer_keywords:
- MFC ActiveX controls [MFC], methods
- PtInCircle custom method [MFC]
ms.assetid: 8f8dc344-44a0-4021-8db5-4cdd3d700e18
ms.openlocfilehash: e32a1c372d89fc4ade414b20a0f77fa162807250
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626153"
---
# <a name="mfc-activex-controls-adding-custom-methods"></a>Controles ActiveX MFC: adicionando métodos personalizados

Os métodos personalizados diferem dos métodos de ações, pois eles ainda não foram implementados pelo `COleControl` . Você deve fornecer a implementação para cada método personalizado que você adicionar ao seu controle.

>[!IMPORTANT]
> O ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre as tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

Um usuário de controle ActiveX pode chamar um método personalizado a qualquer momento para executar ações específicas do controle. A entrada do mapa de expedição para métodos personalizados está no formato DISP_FUNCTION.

## <a name="adding-a-custom-method-with-the-add-method-wizard"></a><a name="_core_adding_a_custom_method_with_classwizard"></a>Adicionando um método personalizado com o assistente para adicionar método

O procedimento a seguir demonstra como adicionar o método personalizado PtInCircle a um código esqueleto do controle ActiveX. PtInCircle determina se as coordenadas passadas para o controle estão dentro ou fora do círculo. Esse mesmo procedimento também pode ser usado para adicionar outros métodos personalizados. Substitua o nome do método personalizado e seus parâmetros para o nome do método PtInCircle e os parâmetros.

> [!NOTE]
> Este exemplo usa a `InCircle` função do artigo Events. Para obter mais informações sobre essa função, consulte o artigo [controles ActiveX do MFC: adicionar eventos personalizados a um controle ActiveX](mfc-activex-controls-adding-custom-events.md).

#### <a name="to-add-the-ptincircle-custom-method-using-the-add-method-wizard"></a>Para adicionar o método personalizado PtInCircle usando o assistente para adicionar método

1. Carregue o projeto do controle.

1. Em Modo de Exibição de Classe, expanda o nó biblioteca do seu controle.

1. Clique com o botão direito do mouse no nó da interface do seu controle (o segundo nó do nó da biblioteca) para abrir o menu de atalho.

1. No menu de atalho, clique em **Adicionar** e, em seguida, clique em **Adicionar método**.

   Isso abre o assistente para adicionar método.

1. Na caixa **nome do método** , digite *PtInCircle*.

1. Na caixa **nome interno** , digite o nome da função interna do método ou use o valor padrão (nesse caso, *PtInCircle*).

1. Na caixa **tipo de retorno** , clique em **VARIANT_BOOL** para o tipo de retorno do método.

1. Usando o **tipo de parâmetro** e os controles de **nome de parâmetro** , adicione um parâmetro chamado *xCoord* (Type *OLE_XPOS_PIXELS*).

1. Usando o **tipo de parâmetro** e os controles de **nome de parâmetro** , adicione um parâmetro chamado *yCoord* (Type *OLE_YPOS_PIXELS*).

1. Clique em **Concluir**.

## <a name="add-method-wizard-changes-for-custom-methods"></a><a name="_core_classwizard_changes_for_custom_methods"></a>Adicionar alterações do assistente de método para métodos personalizados

Quando você adiciona um método personalizado, o assistente para adicionar método faz algumas alterações no cabeçalho da classe de controle (. H) e implementação (. CPP). A linha a seguir é adicionada à declaração do mapa de expedição no cabeçalho da classe de controle (. H) arquivo:

[!code-cpp[NVC_MFC_AxUI#18](codesnippet/cpp/mfc-activex-controls-adding-custom-methods_1.h)]

Esse código declara um manipulador de método de expedição chamado `PtInCircle` . Essa função pode ser chamada pelo usuário de controle usando o nome externo `PtInCircle` .

A linha a seguir é adicionada ao controle do. Arquivo IDL:

[!code-cpp[NVC_MFC_AxUI#19](codesnippet/cpp/mfc-activex-controls-adding-custom-methods_2.idl)]

Essa linha atribui o método a `PtInCircle` um número de ID específico, a posição do método na lista de métodos e propriedades do assistente para adicionar método. Como o assistente para adicionar método foi usado para adicionar o método personalizado, a entrada para ele foi adicionada automaticamente para o projeto. Arquivo IDL.

Além disso, a linha a seguir, localizada na implementação (. CPP) da classe Control, é adicionado ao mapa de expedição do controle:

[!code-cpp[NVC_MFC_AxUI#20](codesnippet/cpp/mfc-activex-controls-adding-custom-methods_3.cpp)]

A macro DISP_FUNCTION mapeia o método `PtInCircle` para a função de manipulador do controle, `PtInCircle` , declara o tipo de retorno a ser **VARIANT_BOOL**e declara dois parâmetros do tipo **VTS_XPOS_PIXELS** e **VTS_YPOSPIXELS** a serem passados para `PtInCircle` .

Por fim, o assistente para adicionar método adiciona a função de stub `CSampleCtrl::PtInCircle` à parte inferior da implementação do controle (. CPP). Para `PtInCircle` o para funcionar conforme mencionado anteriormente, ele deve ser modificado da seguinte maneira:

[!code-cpp[NVC_MFC_AxUI#21](codesnippet/cpp/mfc-activex-controls-adding-custom-methods_4.cpp)]

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](mfc-activex-controls.md)<br/>
[Ícones de pesquisador de objetos e Modo de Exibição de Classe](/visualstudio/ide/class-view-and-object-browser-icons)
