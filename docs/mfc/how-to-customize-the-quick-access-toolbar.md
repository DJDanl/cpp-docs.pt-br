---
title: 'Como: Personalizar a barra de ferramentas de acesso rápido'
ms.date: 11/19/2018
helpviewer_keywords:
- quick access toolbar [MFC], customization
ms.assetid: 2554099b-0c89-4605-9249-31bf9cbcefe0
ms.openlocfilehash: c53e405eafe310c0bfc03a916ab85181ae67a34b
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57300698"
---
# <a name="how-to-customize-the-quick-access-toolbar"></a>Como: Personalizar a barra de ferramentas de acesso rápido

A barra de ferramentas de acesso rápido (QAT) é uma barra de ferramentas personalizável que contém um conjunto de comandos que são que uma exibida ao lado do botão de aplicativo ou sob as guias de categoria. A ilustração a seguir mostra um típico de ferramentas de acesso rápido.

![Ferramentas de acesso rápido de faixa de opções do MFC](../mfc/media/quick_access_toolbar.png "ferramentas de acesso rápido de faixa de opções do MFC")

Para personalizar a barra de ferramentas de acesso rápido, abri-lo na **propriedades** janela, modifique seus comandos e, em seguida, o controle de faixa de opções de visualização.

### <a name="to-open-the-quick-access-toolbar-in-the-properties-window"></a>Para abrir a barra de ferramentas de acesso rápido na janela Propriedades

1. No Visual Studio, sobre o **modo de exibição** menu, clique em **exibição de recurso**.

1. Na **exibição de recurso**, clique duas vezes no recurso de faixa de opções para exibi-lo na superfície de design.

1. Na superfície de design, clique com botão direito no menu de ferramentas de acesso rápido e, em seguida, clique em **propriedades**.

## <a name="quick-access-toolbar-properties"></a>Propriedades da barra de ferramentas de acesso rápido

A tabela a seguir define as propriedades da barra de ferramentas de acesso rápido.

|Propriedade|Definição|
|--------------|----------------|
|Posição QAT|Especifica a posição da barra de ferramentas de acesso rápido quando o aplicativo é iniciado. A posição pode ser **acima** ou **abaixo** o controle de faixa de opções.|
|Itens QAT|Especifica os comandos que estão disponíveis para a barra de ferramentas de acesso rápido.|

#### <a name="to-add-or-remove-commands-on-the-quick-access-toolbar"></a>Para adicionar ou remover comandos na barra de ferramentas de acesso rápido

1. No **propriedades** janela, clique em **itens QAT**e, em seguida, clique no botão de reticências **(...)** .

1. No **Editor de itens QAT** caixa de diálogo, use o **Add** e **remover** botões para modificar a lista de comandos na barra de ferramentas de acesso rápido.

1. Se você quiser um comando apareça na barra de ferramentas de acesso rápido e o menu de ferramentas de acesso rápido, marque a caixa ao lado de comando. Se você quiser que o comando apareça somente no menu, desmarque a caixa.

## <a name="previewing-the-ribbon"></a>Visualizar a faixa de opções

Comandos de barra de ferramentas de acesso rápidos não aparecem na superfície de design. Para exibi-los, você deve visualizar a faixa de opções ou executar o aplicativo.

#### <a name="to-preview-the-ribbon-control"></a>Para visualizar o controle de faixa de opções

- Sobre o **barra de ferramentas do Editor de faixa de opções**, clique em **faixa de opções de teste**.

## <a name="see-also"></a>Consulte também

[Designer da faixa de opções (MFC)](../mfc/ribbon-designer-mfc.md)
