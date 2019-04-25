---
title: 'Controles ActiveX MFC: Adicionando métodos personalizados'
ms.date: 09/12/2018
helpviewer_keywords:
- MFC ActiveX controls [MFC], methods
- PtInCircle custom method [MFC]
ms.assetid: 8f8dc344-44a0-4021-8db5-4cdd3d700e18
ms.openlocfilehash: 4f5a7dc844d80ae94df8af7c0b2eea141376f9e9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62160140"
---
# <a name="mfc-activex-controls-adding-custom-methods"></a>Controles ActiveX MFC: Adicionando métodos personalizados

Métodos personalizados são diferentes de métodos de estoque em que eles já não são implementados por `COleControl`. Você deve fornecer a implementação para cada método personalizado que você adiciona ao controle.

>[!IMPORTANT]
> ActiveX é uma tecnologia herdada que não deve ser usada para novos desenvolvimentos. Para obter mais informações sobre tecnologias modernas que substituem o ActiveX, consulte [controles ActiveX](activex-controls.md).

Um usuário do controle ActiveX pode chamar um método personalizado a qualquer momento para executar ações específicas de controle. A entrada de mapa de expedição para métodos personalizados é da forma DISP_FUNCTION.

##  <a name="_core_adding_a_custom_method_with_classwizard"></a> Adicionando um método personalizado com o Assistente do método de adição

O procedimento a seguir demonstra como adicionar o método personalizado PtInCircle ao código de esqueleto de um controle ActiveX. PtInCircle determina se as coordenadas passadas para o controle são dentro ou fora do círculo. Esse mesmo procedimento também pode ser usado para adicionar outros métodos personalizados. Substitua o nome do método personalizado e seus parâmetros para os parâmetros e o nome do método PtInCircle.

> [!NOTE]
>  Este exemplo usa o `InCircle` função do artigo eventos. Para obter mais informações sobre esta função, consulte o artigo [controles ActiveX MFC: Adicionando eventos personalizados a um controle ActiveX](../mfc/mfc-activex-controls-adding-custom-events.md).

#### <a name="to-add-the-ptincircle-custom-method-using-the-add-method-wizard"></a>Para adicionar um método personalizado PtInCircle usando o Assistente para adicionar método

1. Carregar o projeto do controle.

1. No modo de exibição de classe, expanda o nó de biblioteca do seu controle.

1. Para abrir o menu de atalho, clique com botão direito no nó de interface para o seu controle (o segundo nó do nó de biblioteca).

1. No menu de atalho, clique em **Add** e, em seguida, clique em **Add Method**.

   Isso abre o Assistente para adição de método.

1. No **nome do método** , digite *PtInCircle*.

1. No **nome interno** caixa, digite o nome da função interna de um método ou usar o valor padrão (nesse caso, *PtInCircle*).

1. No **tipo de retorno** , clique em **VARIANT_BOOL** para o tipo de retorno do método.

1. Usando o **tipo de parâmetro** e **nome do parâmetro** controles, adicione um parâmetro chamado *xCoord* (tipo *OLE_XPOS_PIXELS*).

9. Usando o **tipo de parâmetro** e **nome do parâmetro** controles, adicione um parâmetro chamado *yCoord* (tipo *OLE_YPOS_PIXELS*).

10. Clique em **Finalizar**.

##  <a name="_core_classwizard_changes_for_custom_methods"></a> Adicionar Assistente altera o método para métodos personalizados

Quando você adiciona um método personalizado, o Assistente para adicionar método faz algumas alterações para o cabeçalho de classe de controle (. H) e implementação (. Arquivos CPP). A seguinte linha é adicionada à declaração de mapa de expedição no cabeçalho da classe de controle (. H) arquivo:

[!code-cpp[NVC_MFC_AxUI#18](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-methods_1.h)]

Esse código declara um manipulador de expedição de método chamado `PtInCircle`. Essa função pode ser chamada pelo usuário controle usando o nome externo `PtInCircle`.

A seguinte linha é adicionada para o controle. Arquivo IDL:

[!code-cpp[NVC_MFC_AxUI#19](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-methods_2.idl)]

Essa linha atribui o `PtInCircle` método um número específico de ID, a posição do método na lista de métodos e propriedades de Assistente para adição de método. Como o Assistente para adição de método foi usado para adicionar o método personalizado, a entrada para que ele foi adicionada automaticamente para o projeto. Arquivo IDL.

Além disso, a linha a seguir, localizados na implementação (. Arquivo CPP) da classe do controle, é adicionada ao mapa de expedição do controle:

[!code-cpp[NVC_MFC_AxUI#20](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-methods_3.cpp)]

A macro DISP_FUNCTION mapeia o método `PtInCircle` a função de manipulador do controle, `PtInCircle`, declara o tipo de retorno seja **VARIANT_BOOL**e declara dois parâmetros de tipo **VTS_XPOS_PIXELS** e **VTS_YPOSPIXELS** a serem passados para `PtInCircle`.

Por fim, o Assistente para adicionar método adiciona a função de stub `CSampleCtrl::PtInCircle` na parte inferior da implementação do controle (. Arquivo CPP). Para `PtInCircle` para funcionar conforme mencionado anteriormente, ele deve ser modificado da seguinte maneira:

[!code-cpp[NVC_MFC_AxUI#21](../mfc/codesnippet/cpp/mfc-activex-controls-adding-custom-methods_4.cpp)]

## <a name="see-also"></a>Consulte também

[Controles ActiveX do MFC](../mfc/mfc-activex-controls.md)<br/>
[Ícones do Pesquisador de Objetos e do Modo de Exibição de Classe](/visualstudio/ide/class-view-and-object-browser-icons)
