---
title: Como personalizar a barra de ferramentas de acesso rápido
ms.date: 09/07/2019
helpviewer_keywords:
- quick access toolbar [MFC], customization
ms.assetid: 2554099b-0c89-4605-9249-31bf9cbcefe0
ms.openlocfilehash: 5d168fc395e27eea3705fc8e69c88569ecb0f7ee
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84620026"
---
# <a name="how-to-customize-the-quick-access-toolbar"></a>Como personalizar a barra de ferramentas de acesso rápido

A barra de ferramentas de acesso rápido (QAT) é uma barra de ferramentas personalizável que contém um conjunto de comandos que são exibidos ao lado do botão aplicativo ou sob as guias categoria. A ilustração a seguir mostra uma barra de ferramentas de acesso rápido típica.

![Barra de ferramentas de acesso rápido do MFC Ribbon](../mfc/media/quick_access_toolbar.png "Barra de ferramentas de acesso rápido do MFC Ribbon")

Para personalizar a barra de ferramentas de acesso rápido, abra-a na janela **Propriedades** , modifique seus comandos e, em seguida, visualize o controle faixa de faixas.

### <a name="to-open-the-quick-access-toolbar-in-the-properties-window"></a>Para abrir a barra de ferramentas de acesso rápido no janela Propriedades

1. No Visual Studio, no menu **Exibir** , clique em **modo de exibição de recursos**.

1. Em **modo de exibição de recursos**, clique duas vezes no recurso da faixa de bits para exibi-lo na superfície de design.

1. Na superfície de design, clique com o botão direito do mouse no menu da barra de ferramentas acesso rápido e clique em **Propriedades**.

## <a name="quick-access-toolbar-properties"></a>Propriedades da barra de ferramentas de acesso rápido

A tabela a seguir define as propriedades da barra de ferramentas de acesso rápido.

|Propriedade|Definição|
|--------------|----------------|
|Posição QAT|Especifica a posição da barra de ferramentas de acesso rápido quando o aplicativo é iniciado. A posição pode estar **acima** ou **abaixo** do controle da faixa de opções.|
|QAT itens|Especifica os comandos que estão disponíveis para a barra de ferramentas de acesso rápido.|

#### <a name="to-add-or-remove-commands-on-the-quick-access-toolbar"></a>Para adicionar ou remover comandos na barra de ferramentas de acesso rápido

1. Na janela **Propriedades** , clique em **qat itens**e, em seguida, clique no botão de reticências **(...)**.

1. Na caixa de diálogo **Editor de itens qat** , use os botões **Adicionar** e **remover** para modificar a lista de comandos na barra de ferramentas de acesso rápido.

1. Se você quiser que um comando apareça na barra de ferramentas de acesso rápido e no menu de barra de ferramentas de acesso rápido, selecione a caixa ao lado do comando. Se você quiser que o comando apareça somente no menu, desmarque a caixa.

## <a name="previewing-the-ribbon"></a>Visualizando a faixa de visão

Os comandos da barra de ferramentas de acesso rápido não aparecem na superfície de design. Para exibi-los, você deve Visualizar a faixa de opções ou executar o aplicativo.

#### <a name="to-preview-the-ribbon-control"></a>Para visualizar o controle da faixa de faixas

- Na **barra de ferramentas do editor da faixa de faixas**, clique em **testar faixa**de medida.

## <a name="see-also"></a>Consulte também

[Designer de faixa de Ribbon (MFC)](ribbon-designer-mfc.md)
