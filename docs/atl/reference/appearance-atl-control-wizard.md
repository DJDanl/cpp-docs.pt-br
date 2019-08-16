---
title: Aparência, assistente de controle ATL
ms.date: 08/31/2018
f1_keywords:
- vc.codewiz.class.atl.control.misc
helpviewer_keywords:
- ATL Control Wizard, appearance
ms.assetid: cc16d7ff-74d7-4c15-9ebd-4b19201ff457
ms.openlocfilehash: e07dc017241848f1a670c17b12c2254de6d1b8e1
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69492182"
---
# <a name="appearance-atl-control-wizard"></a>Aparência, assistente de controle ATL

Use esta página do assistente para identificar opções de elemento de usuário adicionais para o controle. Esta página está disponível para controles identificados como **controles padrão** em **tipo de controle** na página [Opções, assistente de controle ATL](../../atl/reference/options-atl-control-wizard.md) .

## <a name="uielement-list"></a>Lista UIElement

- **Exibir status**

   Define a aparência do controle dentro do contêiner.

   - **Opaco**: Define o bit VIEWSTATUS_OPAQUE na enumeração [VIEWSTATUS](/windows/win32/api/ocidl/ne-ocidl-viewstatus) e desenha o retângulo de controle inteiro passado para o método [CComControlBase:: OnDraw](../../atl/reference/ccomcontrolbase-class.md#ondraw) . O controle aparece completamente opaco e nenhum dos contêineres é exibido atrás dos limites de controle.

      Essa configuração ajuda o contêiner a desenhar o controle mais rapidamente. Se essa opção não estiver selecionada, o controle poderá conter partes transparentes.

      Somente um controle opaco pode ter um plano de fundo sólido.

   - **Plano de fundo sólido**: Define o bit VIEWSTATUS_SOLIDBKGND na enumeração VIEWSTATUS. O plano de fundo do controle aparece como uma cor sólida sem padrão.

      Essa opção estará disponível somente se a opção **opaco** também estiver selecionada.

- **Adicionar controle com base em**

   Define o controle para ser baseado em um tipo de controle do Windows adicionando um membro de dados [CContainedWindow](ccontainedwindowt-class.md) à classe que implementa o controle. Ele também adiciona um mapa de mensagens e funções de manipulador de mensagens para manipular mensagens do Windows para o controle. Escolha na lista o tipo de controle do Windows que você deseja criar, se houver.

   - **Button**

   - **ListBox**

   - **SysAnimate32**

   - **SysListView32**

   - **ComboBox**

   - **RichEdit**

   - **SysDateTimePick32**

   - **SysMonthCal32**

   - **ComboBoxEx32**

   - **ScrollBar**

   - **SysHeader32**

   - **SysTabControl32**

   - **Editar**

   - **Estático**

   - **SysIPAddress32**

   - **SysTreeView32**

- **Status variado**

   Define opções adicionais de aparência e comportamento para o controle.

   - **Invisível em tempo de execução**: Define o controle como invisível no tempo de execução. Você pode usar controles invisíveis para executar operações em segundo plano, como acionar eventos em intervalos de tempo.

   - **Atua como o botão**: Define o bit OLEMISC_ACTSLIKEBUTTON na enumeração [OLEMISC](/windows/win32/api/oleidl/ne-oleidl-olemisc) para permitir que um controle atue como um botão. Se o contêiner tiver marcado o site do cliente do controle como um botão padrão, a seleção dessa opção permitirá que o controle de botão seja exibido como um botão padrão, desenhando-o com um quadro mais espesso. Consulte [CComControlBase:: GetAmbientDisplayAsDefault](../../atl/reference/ccomcontrolbase-class.md#getambientdisplayasdefault) para obter mais informações.

   - **Atua como o rótulo**: Define o bit OLEMISC_ACTSLIKELABEL na enumeração OLEMISC para habilitar um controle para substituir o rótulo nativo do contêiner. O contêiner determina o que fazer com esse sinalizador, se houver algo.

- **Outros**

   Define opções de comportamento adicionais para o controle.

   - **Controlador de domínio normalizado**: Define o controle para criar um contexto de dispositivo normalizado quando ele é chamado para desenhar a si mesmo. Essa ação padroniza a aparência do controle, mas torna o desenho menos eficiente.

   - **Somente janela**: Especifica que seu controle não pode ser sem janela. Se você não selecionar essa opção, seu controle será automaticamente sem janela em contêineres que dão suporte a objetos sem janela, e ele será automaticamente desmarcado em contêineres que não dão suporte a objetos sem janela. A seleção dessa opção força o controle a ser janelas, mesmo em contêineres que dão suporte a objetos sem janela.

   - **Insertável**: Selecione esta opção para que seu controle apareça na caixa de diálogo **Inserir objeto** de aplicativos, como Word e Excel. Em seguida, seu controle pode ser inserido por qualquer aplicativo que ofereça suporte a objetos inseridos por meio dessa caixa de diálogo.

## <a name="see-also"></a>Consulte também

[Assistente de Controle da ATL](../../atl/reference/atl-control-wizard.md)<br/>
[Exemplo de SUBEDIT: Superclasses de um controle padrão do Windows](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/Controls/SubEdit)
