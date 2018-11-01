---
title: Configurações de controle, Assistente de Controle ActiveX MFC
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.mfc.ctl.settings
helpviewer_keywords:
- MFC ActiveX Control Wizard, control settings
ms.assetid: 2ccaa4fc-0d52-413e-afa3-ecd474c3f6f0
ms.openlocfilehash: 3eedf24fa4b0bb527b374dbc9f538408f20de953
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50548233"
---
# <a name="control-settings-mfc-activex-control-wizard"></a>Configurações de controle, Assistente de Controle ActiveX MFC

Use esta página do Assistente para especificar como você deseja que o controle a se comportar. Por exemplo, o controle em tipos de controle padrão do Windows de base, otimizar sua aparência e comportamento ou indicar que o controle pode agir como um contêiner para outros controles.

Para obter mais informações sobre como selecionar as opções desta página para maximizar a eficiência do controle, consulte [controles ActiveX MFC: otimização](../../mfc/mfc-activex-controls-optimization.md).

## <a name="uielement-list"></a>Lista UIElement

- **Criar um controle com base em**

   Nesta lista, você pode selecionar o tipo de controle do qual o controle deve ser herdada. A lista é um subconjunto das classes de controle que estão disponíveis para `CreateWindowEx` e controles comuns adicionais que são especificados em commctrl. h. Sua seleção determina o estilo do controle na `PreCreateWindow` funcionar a *NomeDoProjeto*Ctrl.cpp arquivo. Para obter mais informações, consulte [controles ActiveX MFC: subclasses de um controle de Windows](../../mfc/mfc-activex-controls-subclassing-a-windows-control.md).

   |Controle|Descrição|
   |-------------|-----------------|
   |**BOTÃO**|Um controle de botão do Windows|
   |**CAIXA DE COMBINAÇÃO**|Um controle de caixa de combinação do Windows|
   |**EDITAR**|Um controle de caixa de edição do Windows|
   |**CAIXA DE LISTAGEM**|Um controle de caixa de listagem do Windows|
   |**BARRA DE ROLAGEM**|Um controle de barra de rolagem do Windows|
   |**ESTÁTICO**|Um controle estático do Windows|
   |**msctls_hotkey32**|Um controle comum chave de acesso|
   |**msctls_progress32**|Uma barra de controle comum de progresso|
   |**msctls_statusbar32**|Uma barra de controle comum de status|
   |**msctls_trackbar32**|Uma faixa da barra de controle comum|
   |**msctls_updown32**|Um botão de rotação (ou superior / inferior) controle comum|
   |**SysAnimate32**|Um controle comum de animação|
   |**SysHeader32**|Um controle de cabeçalho comum|
   |**SysListView32**|Um controle comum de exibição de lista|
   |**SysTabControl32**|Um controle de guia comum|
   |**SysTreeView32**|Um controle comum de exibição de árvore|

- **Ativo quando visível**

   Especifica que uma janela é criada para o controle quando ele é acessado. Por padrão, o **ativo quando visível** opção está selecionada. Se você deseja adiar a ativação do controle até que o contêiner exige que ele (por exemplo, quando um usuário clica com o mouse), desmarque essa opção. Quando esse recurso está desativado, o controle não incorre a despesa de criação da janela até que ele seja necessário. Para obter mais informações, consulte [desativando a opção Ativar quando visível](../../mfc/turning-off-the-activate-when-visible-option.md).

- **Invisível em tempo de execução**

   Especifica que o controle não tem nenhuma interface do usuário em tempo de execução. Um temporizador é um tipo de controle que talvez você queira ser invisível.

- **Tem uma caixa de diálogo sobre**

   Especifica que o controle tem o Windows standard **sobre** caixa de diálogo que exibe o número de versão e informações de direitos autorais.

   > [!NOTE]
   > Como o usuário acessa a Ajuda para o controle depende de como você implementou a Ajuda e se você tiver integrado a Ajuda de controle com a Ajuda do contêiner. Para obter mais informações sobre como integrar o ajuda, o [biblioteca MSDN](http://go.microsoft.com/fwlink/p/?linkid=150542) site, pesquise por "Adicionando contextual ajuda para um controle ActiveX do MFC".

   Quando você seleciona essa opção, ele insere o `AboutBox` controlar o método na classe de controle de projeto (C*NomeDoProjeto*Ctrl.cpp) e adiciona AboutBox ao mapa de expedição do projeto. Por padrão, essa opção é selecionada.

- **Código de desenho otimizado**

   Especifica que o contêiner restaura os objetos GDI automaticamente depois que todos os controles de contêiner, que são desenhadas para o mesmo contexto de dispositivo, foram emitidas. Para obter mais informações sobre esse recurso, consulte [otimizando o desenho de controle](../../mfc/optimizing-control-drawing.md).

- **Ativação sem janelas**

   Especifica que o controle não produz uma janela quando ele for ativado. Ativação sem janelas permite que controles não retangulares ou transparentes e um controle sem janelas requer menos sobrecarga do sistema que um controle que tem uma janela exige. Um controle sem janelas não permite para um contexto de dispositivo não recortado ou ativação sem cintilação. Contêineres que foram criados antes de 1996 não dão suporte a ativação sem janelas. Para obter mais informações sobre como usar essa opção, consulte [fornecendo ativação sem janelas](../../mfc/providing-windowless-activation.md).

- **Contexto de dispositivo não recortado**

   Substitui [COleControl::GetControlFlags](../../mfc/reference/colecontrol-class.md#getcontrolflags) no cabeçalho do controle (*NomeDoProjeto*ctrl.h) para desabilitar a chamada para `IntersectClipRect` feitas pelo `COleControl`. Quando você seleciona essa opção, ele fornece uma vantagem da velocidade de pequenos. Se você selecionar **ativação sem janelas**, esse recurso não está disponível. Para obter mais informações, consulte [usando um contexto de dispositivo não recortado](../../mfc/using-an-unclipped-device-context.md).

- **Ativação sem cintilação**

   Elimina as operações de desenho e a cintilação de visual que acompanha este artigo que ocorrem entre os estados ativos e inativos do controle. Se você selecionar **ativação sem janelas**, esse recurso não está disponível. Quando você definir essa opção, o `noFlickerActivate` sinalizador é um dos sinalizadores que são retornados pelo [COleControl::GetControlFlags](../../mfc/reference/colecontrol-class.md#getcontrolflags). Para obter mais informações, consulte [fornecendo ativação sem cintilação](../../mfc/providing-flicker-free-activation.md).

- **Disponível na caixa de diálogo Inserir objeto**

   Especifica que o controle estará disponível na **Inserir objeto** caixa de diálogo para contêineres habilitados. Quando você seleciona essa opção, o `afxRegInsertable` sinalizador é um dos sinalizadores que são retornados pelo `AfxOleRegisterControlClass`. Usando o **Inserir objeto** caixa de diálogo, um usuário pode inserir recém-criado ou objetos existentes em um documento composto.

- **Notificações do ponteiro do mouse quando inativo**

   Permite que o controle para processar notificações de ponteiro do mouse, se o controle está ativo ou não. Quando você seleciona essa opção, o `pointerInactive` sinalizador é um dos sinalizadores que são retornados pelo [COleControl::GetControlFlags](../../mfc/reference/colecontrol-class.md#getcontrolflags). Para obter mais informações sobre como usar essa opção, consulte [fornecendo Mouse interação enquanto inativo](../../mfc/providing-mouse-interaction-while-inactive.md).

- **Atua como um controle de quadro simples**

   Especifica que o controle é um contêiner para outros controles, definindo o OLEMISC_SIMPLEFRAME bit para o controle. Para obter mais informações, sobre o [biblioteca MSDN](http://go.microsoft.com/fwlink/p/?linkid=150542) site, pesquise por "Confinamento simples do quadro de Site".

- **Carrega as propriedades de forma assíncrona**

   Habilita uma redefinição de todos os dados anteriores assíncronas e inicia uma nova carga da propriedade assíncrona do controle.

## <a name="see-also"></a>Consulte também

[Assistente de controle ActiveX do MFC](../../mfc/reference/mfc-activex-control-wizard.md)<br/>
[Configurações do aplicativo, Assistente de controle ActiveX do MFC](../../mfc/reference/application-settings-mfc-activex-control-wizard.md)<br/>
[Nomes de controle, Assistente de controle ActiveX do MFC](../../mfc/reference/control-names-mfc-activex-control-wizard.md)

