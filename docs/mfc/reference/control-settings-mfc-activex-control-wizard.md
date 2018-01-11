---
title: "Configurações de controle, Assistente de controle ActiveX MFC | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.appwiz.mfc.ctl.settings
dev_langs: C++
helpviewer_keywords: MFC ActiveX Control Wizard, control settings
ms.assetid: 2ccaa4fc-0d52-413e-afa3-ecd474c3f6f0
caps.latest.revision: "16"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 60828b7f40009a5fd88c7f0a7f820ede3de4aa93
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="control-settings-mfc-activex-control-wizard"></a>Configurações de controle, Assistente de Controle ActiveX MFC
Use esta página do Assistente para especificar como você deseja que o controle se comporta. Por exemplo, base de controle em tipos de controle padrão do Windows, otimizar seu comportamento e aparência ou indicar que o controle pode agir como um contêiner para outros controles.  
  
 Para obter mais informações sobre como selecionar as opções desta página para maximizar a eficiência do controle, consulte [controles ActiveX MFC: otimização](../../mfc/mfc-activex-controls-optimization.md).  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Criar um controle com base em**  
 Nessa lista, você pode selecionar o tipo de controle do qual o controle deve herdar. A lista é um subconjunto das classes de controle que estão disponíveis para `CreateWindowEx` e controles comuns adicionais que são especificados em commctrl. h. Sua seleção determina o estilo do controle no `PreCreateWindow` funcionar a *NomeDoProjeto*Ctrl.cpp arquivo. Para obter mais informações, consulte [controles ActiveX MFC: subclasses de um controle de Windows](../../mfc/mfc-activex-controls-subclassing-a-windows-control.md).  
  
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
|**msctls_trackbar32**|Um controle de barra de controle comum|  
|**msctls_updown32**|Um botão de rotação (ou para cima para baixo) controle comum|  
|**SysAnimate32**|Um controle comum de animação|  
|**SysHeader32**|Um controle comum do cabeçalho|  
|**SysListView32**|Um controle comum do modo de exibição de lista|  
|**SysTabControl32**|Um controle de guia comum|  
|**SysTreeView32**|Um controle comum do modo de exibição de árvore|  
  
 **Ativar quando visível**  
 Especifica que uma janela é criada para o controle quando ele é acessado. Por padrão, o **ativa quando visível** opção é selecionada. Se você deseja adiar a ativação do controle até que o contêiner requer a ele (por exemplo, quando um usuário clica com o mouse), desmarque essa opção. Quando esse recurso está desativado, o controle não incorrerá em despesas de criação de janela até que seja necessário. Para obter mais informações, consulte [desativar a opção Ativar quando visível](../../mfc/turning-off-the-activate-when-visible-option.md).  
  
 **Invisível em tempo de execução**  
 Especifica que o controle não tem nenhuma interface do usuário em tempo de execução. Um temporizador é um tipo de controle que talvez você queira invisível.  
  
 **Tem uma caixa de diálogo sobre**  
 Especifica que o controle tem o padrão do Windows **sobre** caixa de diálogo que exibe o número de versão e informações sobre direitos autorais.  
  
> [!NOTE]
>  Como o usuário acessar a Ajuda para o controle depende de como você implementou a Ajuda e se você tiver integrado a Ajuda de controle com a Ajuda do contêiner. Para obter mais informações sobre como integrar o ajuda, o [MSDN Library](http://go.microsoft.com/fwlink/p/?linkid=150542) site, procure "Adicionando sensível ao contexto ajuda para um controle ActiveX MFC".  
  
 Quando você seleciona essa opção, ele insere o `AboutBox` controlar o método na classe de controle de projeto (C*NomeDoProjeto*Ctrl.cpp) e adiciona AboutBox ao mapa de expedição do projeto. Por padrão, essa opção é selecionada.  
  
 **Código de desenho otimizado**  
 Especifica que o contêiner restaura os objetos GDI automaticamente depois que todos os controles de contêiner, que são desenhadas para o mesmo contexto de dispositivo, foram emitidas. Para obter mais informações sobre esse recurso, consulte [otimizando o desenho de controle](../../mfc/optimizing-control-drawing.md).  
  
 **Ativação sem janelas**  
 Especifica que o controle não produz uma janela quando ele está ativado. Ativação sem janelas permite controles não retangulares ou transparentes, e um controle sem janelas requer requer menos sobrecarga do sistema que um controle que tem uma janela. Um controle sem janelas não permite a um contexto de dispositivo não recortado ou a ativação sem cintilação. Contêineres que foram criados antes de 1996 não dão suporte a ativação sem janelas. Para obter mais informações sobre como usar essa opção, consulte [fornecendo ativação sem janelas](../../mfc/providing-windowless-activation.md).  
  
 **Contexto de dispositivo não recortado**  
 Substitui [COleControl::GetControlFlags](../../mfc/reference/colecontrol-class.md#getcontrolflags) no cabeçalho de controle (*NomeDoProjeto*ctrl.h) para desabilitar a chamada para `IntersectClipRect` feitas por `COleControl`. Quando você seleciona essa opção, ele fornece uma vantagem de velocidade pequeno. Se você selecionar **ativação sem janelas**, esse recurso não está disponível. Para obter mais informações, consulte [usando um contexto de dispositivo não recortado](../../mfc/using-an-unclipped-device-context.md).  
  
 **Ativação sem cintilação**  
 Elimina as operações de desenho e a oscilação visual que ocorrem entre os estados ativos e inativos do controle. Se você selecionar **ativação sem janelas**, esse recurso não está disponível. Quando você definir essa opção, o `noFlickerActivate` sinalizador é um dos sinalizadores que são retornados pelo [COleControl::GetControlFlags](../../mfc/reference/colecontrol-class.md#getcontrolflags). Para obter mais informações, consulte [fornecendo ativação sem cintilação](../../mfc/providing-flicker-free-activation.md).  
  
 **Disponível na caixa de diálogo Inserir objeto**  
 Especifica que o controle estará disponível no **Inserir objeto** caixa de diálogo para contêineres habilitados. Quando você seleciona essa opção, o `afxRegInsertable` sinalizador é um dos sinalizadores que são retornados pelo `AfxOleRegisterControlClass`. Usando o **Inserir objeto** caixa de diálogo, um usuário pode inserir recém-criado ou objetos existentes em um documento composto.  
  
 **Notificações do ponteiro do mouse quando inativo**  
 Permite que o controle processar notificações de ponteiro do mouse, se o controle está ativo ou não. Quando você seleciona essa opção, o `pointerInactive` sinalizador é um dos sinalizadores que são retornados pelo [COleControl::GetControlFlags](../../mfc/reference/colecontrol-class.md#getcontrolflags). Para obter mais informações sobre como usar essa opção, consulte [fornecendo Mouse interação enquanto inativo](../../mfc/providing-mouse-interaction-while-inactive.md).  
  
 **Atua como um controle de quadro simples**  
 Especifica que o controle é um contêiner para outros controles, definindo o `OLEMISC_SIMPLEFRAME` bit para o controle. Para obter mais informações, sobre o [MSDN Library](http://go.microsoft.com/fwlink/p/?linkid=150542) site, procure "Contenção de Site de quadro simples".  
  
 **Carrega as propriedades de forma assíncrona**  
 Permite a reinicialização de quaisquer dados assíncronos anteriores e inicia uma nova carga da propriedade assíncrona do controle.  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de controle ActiveX MFC](../../mfc/reference/mfc-activex-control-wizard.md)   
 [Configurações do aplicativo, Assistente de controle ActiveX MFC](../../mfc/reference/application-settings-mfc-activex-control-wizard.md)   
 [Nomes de controle, Assistente de controle ActiveX do MFC](../../mfc/reference/control-names-mfc-activex-control-wizard.md)

