---
title: Aparência, assistente de controle ATL
ms.date: 08/31/2018
f1_keywords:
- vc.codewiz.class.atl.control.misc
helpviewer_keywords:
- ATL Control Wizard, appearance
ms.assetid: cc16d7ff-74d7-4c15-9ebd-4b19201ff457
ms.openlocfilehash: 3484fb5d0f919af0dfd18b584e96d4675e2baea8
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81319403"
---
# <a name="appearance-atl-control-wizard"></a>Aparência, assistente de controle ATL

Use esta página do assistente para identificar opções adicionais de elemento susceptino de elemento susceptino para o controle. Esta página está disponível para controles identificados como **controles Padrão** sob o **tipo Controle** na página [Opções, assistente de controle ATL.](../../atl/reference/options-atl-control-wizard.md)

## <a name="uielement-list"></a>Lista de elementos de interface do usuário

- **Exibir status**

   Define a aparência do controle dentro do recipiente.

  - **Opaco :** Define o VIEWSTATUS_OPAQUE bit na enumeração [VIEWSTATUS](/windows/win32/api/ocidl/ne-ocidl-viewstatus) e desenha todo o retângulo de controle passado para o método [CComControlBase::OnDraw.](../../atl/reference/ccomcontrolbase-class.md#ondraw) O controle parece completamente opaco, e nenhum dos contêineres aparece atrás dos limites de controle.

      Esta configuração ajuda o recipiente a desenhar o controle mais rapidamente. Se esta opção não for selecionada, o controle pode conter peças transparentes.

      Só um controle opaco pode ter um fundo sólido.

  - **Fundo sólido**: Define o bit VIEWSTATUS_SOLIDBKGND na enumeração VIEWSTATUS. O fundo do controle aparece como uma cor sólida sem padrão.

      Esta opção só está disponível se a opção **Opaque** também for selecionada.

- **Adicionar controle com base em**

   Define o controle a ser baseado em um tipo de controle do Windows adicionando um membro de dados [CContainedWindow](ccontainedwindowt-class.md) à classe que implementa o controle. Ele também adiciona um mapa de mensagens e funções de manipulador de mensagens para lidar com mensagens do Windows para o controle. Escolha na lista o tipo de controle do Windows que deseja criar, se houver.

  - **Botão**

  - **ListBox**

  - **SysAnimate32**

  - **SysListView32**

  - **ComboBox**

  - **Richedit**

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

- **Estado misc**

   Define opções adicionais de aparência e comportamento para o controle.

  - **Invisível no tempo de execução**: Define o controle para ser invisível no tempo de execução. Você pode usar controles invisíveis para executar operações em segundo plano, como eventos de disparo em intervalos cronometrados.

  - **Atua como um botão**: Define o OLEMISC_ACTSLIKEBUTTON bit na enumeração [OLEMISC](/windows/win32/api/oleidl/ne-oleidl-olemisc) para permitir que um controle aja como um botão. Se o contêiner tiver marcado o site do cliente do controle como um botão padrão, a seleção desta opção permite que o controle do botão se exiba como um botão padrão, desenhando-se com um quadro mais grosso. Consulte [CComControlBase::GetAmbientDisplayAsDefault](../../atl/reference/ccomcontrolbase-class.md#getambientdisplayasdefault) para obter mais informações.

  - **Atua como rótulo**: Define o OLEMISC_ACTSLIKELABEL bit na enumeração OLEMISC para permitir um controle para substituir o rótulo nativo do recipiente. O contêiner determina o que fazer com esta bandeira, se alguma coisa.

- **Outros**

   Define opções de comportamento adicionais para o controle.

  - **DC normalizado**: Define o controle para criar um contexto de dispositivo normalizado quando é chamado para desenhar-se. Esta ação padroniza a aparência do controle, mas torna o desenho menos eficiente.

  - **Somente janela**: Especifica que seu controle não pode ser sem janelas. Se você não selecionar essa opção, seu controle é automaticamente sem janelas em recipientes que suportam objetos sem janelas, e ele é automaticamente janelas em recipientes que não suportam objetos sem janelas. A seleção dessa opção força que seu controle seja janelasdo, mesmo em contêineres que suportam objetos sem janelas.

  - **Inseringível**: Selecione esta opção para que seu controle apareça na caixa de diálogo **Inserir objeto** de aplicativos como Word e Excel. Seu controle pode então ser inserido por qualquer aplicativo que suporte objetos incorporados através desta caixa de diálogo.

## <a name="see-also"></a>Confira também

[Assistente de controle ATL](../../atl/reference/atl-control-wizard.md)<br/>
[Subedit Sample: Superclasses um Controle Padrão do Windows](https://github.com/Microsoft/VCSamples/tree/master/VC2008Samples/ATL/Controls/SubEdit)
