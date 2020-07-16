---
title: Configurações de controle, Assistente de Controle ActiveX MFC
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.mfc.ctl.settings
helpviewer_keywords:
- MFC ActiveX Control Wizard, control settings
ms.assetid: 2ccaa4fc-0d52-413e-afa3-ecd474c3f6f0
ms.openlocfilehash: 1578ca7f4134e51e0ba0d3c2b247dcafcb0fbd67
ms.sourcegitcommit: 6b3d793f0ef3bbb7eefaf9f372ba570fdfe61199
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/15/2020
ms.locfileid: "86405007"
---
# <a name="control-settings-mfc-activex-control-wizard"></a>Configurações de controle, Assistente de Controle ActiveX MFC

Use esta página do assistente para especificar como você deseja que o controle se comporte. Por exemplo, você pode basear o controle em tipos de controle padrão do Windows, otimizar seu comportamento e aparência ou indicar que o controle pode atuar como um contêiner para outros controles.

Para obter mais informações sobre como selecionar opções nessa página para maximizar a eficiência do controle, consulte [controles ActiveX do MFC: otimização](../../mfc/mfc-activex-controls-optimization.md).

## <a name="uielement-list"></a>Lista de elementos de interface do usuário

- **Criar controle com base em**

   Nessa lista, você pode selecionar o tipo de controle do qual seu controle deve herdar. A lista é um subconjunto das classes de controle que estão disponíveis para `CreateWindowEx` controles comuns adicionais que são especificados em commctrl. h. Sua seleção determina o estilo do controle na `PreCreateWindow` função no arquivo de CTRL. cpp do *ProjName*. Para obter mais informações, consulte [controles ActiveX do MFC: subclasse de um controle do Windows](../../mfc/mfc-activex-controls-subclassing-a-windows-control.md).

   |Control|Descrição|
   |-------------|-----------------|
   |**BUTTON**|Um controle de botão do Windows|
   |**COMBOBOX**|Um controle de caixa de combinação do Windows|
   |**EDITAR**|Um controle de caixa de edição do Windows|
   |**CAIXAS**|Um controle de caixa de listagem do Windows|
   |**ROLAGEM**|Um controle de barra de rolagem do Windows|
   |**AUTO-estática**|Um controle estático do Windows|
   |**msctls_hotkey32**|Um controle comum de tecla de atalho|
   |**msctls_progress32**|Um controle comum de barra de progresso|
   |**msctls_statusbar32**|Um controle comum de barra de status|
   |**msctls_trackbar32**|Um controle comum de barra de controle|
   |**msctls_updown32**|Um botão de rotação (ou de cima para baixo) controle comum|
   |**SysAnimate32**|Um controle comum de animação|
   |**SysHeader32**|Um controle comum de cabeçalho|
   |**SysListView32**|Um controle comum de exibição de lista|
   |**SysTabControl32**|Um controle comum de guia|
   |**SysTreeView32**|Um controle comum de exibição de árvore|

- **Ativa quando visível**

   Especifica que uma janela é criada para o controle quando é acessada. Por padrão, a opção **ativa quando visível** está selecionada. Se você quiser adiar a ativação do controle até que o contêiner o exija (por exemplo, quando um usuário clicar no mouse), desmarque essa opção. Quando esse recurso estiver desativado, o controle não incorrerá na despesa de criação de janela até que seja necessário. Para obter mais informações, consulte [desativando a opção Ativar quando visível](../../mfc/turning-off-the-activate-when-visible-option.md).

- **Invisível em tempo de execução**

   Especifica que o controle não tem nenhuma interface do usuário em tempo de execução. Um temporizador é um tipo de controle que talvez você queira invisíveis.

- **Tem uma caixa de diálogo sobre**

   Especifica que o controle tem a caixa de diálogo **sobre** o Windows padrão, que exibe o número de versão e informações de direitos autorais.

   > [!NOTE]
   > Como o usuário acessa a ajuda para o controle depende de como você implementou a ajuda e se você integrou a ajuda de controle com a ajuda do contêiner.

   Quando você seleciona essa opção, ela insere o `AboutBox` método de controle na classe de controle de projeto (C*ProjName*Ctrl. cpp) e adiciona AboutBox ao mapa de expedição do projeto. Por padrão, essa opção é selecionada.

- **Código de desenho otimizado**

   Especifica que o contêiner restaura os objetos GDI originais automaticamente depois que todos os controles de contêiner, que são desenhados para o mesmo contexto de dispositivo, foram desenhados. Para obter mais informações sobre esse recurso, consulte [otimizando o desenho de controle](../../mfc/optimizing-control-drawing.md).

- **Ativação sem janela**

   Especifica que o controle não produz uma janela quando é ativado. A ativação sem janela permite controles não retangulares ou transparentes, e um controle sem janela requer menos sobrecarga do sistema do que um controle que tenha uma janela necessária. Um controle sem janela não permite um contexto de dispositivo não recortado ou uma ativação sem cintilação. Os contêineres criados antes de 1996 não dão suporte à ativação sem janela. Para obter mais informações sobre como usar essa opção, consulte [fornecendo ativação sem janela](../../mfc/providing-windowless-activation.md).

- **Contexto de dispositivo não recortado**

   Substitui [COleControl:: GetControlFlags](../../mfc/reference/colecontrol-class.md#getcontrolflags) no cabeçalho de controle (*ProjName*Ctrl. h) para desabilitar a chamada `IntersectClipRect` feita por `COleControl` . Quando você seleciona essa opção, ela fornece uma vantagem de velocidade pequena. Se você selecionar **ativação sem janela**, esse recurso não estará disponível. Para obter mais informações, consulte [usando um contexto de dispositivo não recortado](../../mfc/using-an-unclipped-device-context.md).

- **Ativação sem cintilação**

   Elimina as operações de desenho e a cintilação visual que ocorre entre os Estados ativo e inativo do controle. Se você selecionar **ativação sem janela**, esse recurso não estará disponível. Quando você define essa opção, o `noFlickerActivate` sinalizador é um dos sinalizadores retornados por [COleControl:: GetControlFlags](../../mfc/reference/colecontrol-class.md#getcontrolflags). Para obter mais informações, consulte [fornecendo ativação sem cintilação](../../mfc/providing-flicker-free-activation.md).

- **Disponível na caixa de diálogo Inserir objeto**

   Especifica que o controle estará disponível na caixa de diálogo **Inserir objeto** para contêineres habilitados. Quando você seleciona essa opção, o `afxRegInsertable` sinalizador é um dos sinalizadores retornados pelo `AfxOleRegisterControlClass` . Usando a caixa de diálogo **Inserir objeto** , um usuário pode inserir objetos recém-criados ou existentes em um documento composto.

- **Notificações do ponteiro do mouse quando inativo**

   Permite que o controle processe as notificações do ponteiro do mouse, se o controle está ativo ou não. Quando você seleciona essa opção, o `pointerInactive` sinalizador é um dos sinalizadores retornados por [COleControl:: GetControlFlags](../../mfc/reference/colecontrol-class.md#getcontrolflags). Para obter mais informações sobre como usar essa opção, consulte [fornecendo interação com o mouse enquanto estiver inativo](../../mfc/providing-mouse-interaction-while-inactive.md).

- **Atua como um controle de quadro simples**

   Especifica que o controle é um contêiner para outros controles definindo o OLEMISC_SIMPLEFRAME bit para o controle. Para obter mais informações, consulte [confinamento de site de quadro simples](/windows/win32/com/simple-frame-site-containment).

- **Carrega Propriedades de forma assíncrona**

   Habilita uma redefinição de quaisquer dados assíncronos anteriores e inicia uma nova carga da propriedade assíncrona do controle.

## <a name="see-also"></a>Confira também

[Assistente de controle ActiveX MFC](../../mfc/reference/mfc-activex-control-wizard.md)<br/>
[Configurações do aplicativo, Assistente de Controle ActiveX MFC](../../mfc/reference/application-settings-mfc-activex-control-wizard.md)<br/>
[Nomes de controle, Assistente de controle ActiveX do MFC](../../mfc/reference/control-names-mfc-activex-control-wizard.md)
