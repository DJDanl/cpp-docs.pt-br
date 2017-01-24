---
title: "Configura&#231;&#245;es de controle, Assistente de Controle ActiveX MFC | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "vc.appwiz.mfc.ctl.settings"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de controle ActiveX MFC, configurações de controle"
ms.assetid: 2ccaa4fc-0d52-413e-afa3-ecd474c3f6f0
caps.latest.revision: 16
caps.handback.revision: 12
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Configura&#231;&#245;es de controle, Assistente de Controle ActiveX MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Use esta página do assistente para especificar como você deseja que o controle para se comportar.  Por exemplo, você pode basear o controle em tipos padrão de controle do windows, otimizar seu comportamento e a aparência, ou para indicar que o controle pode atuar como um contêiner para outros controles.  
  
 Para obter mais informações sobre como selecionar opções desta página maximizar a eficiência de controle, consulte [Controles ActiveX MFC: otimização](../../mfc/mfc-activex-controls-optimization.md).  
  
## Lista UIElement  
 **Crie o controle baseia**  
 Nessa lista, você pode selecionar o tipo de controle do seu controle deve ser herdada.  A lista é um subconjunto das classes de controle que estão disponíveis para `CreateWindowEx` e os controles comuns adicionais que são especificados em commctrl.h.  Sua seleção determina o estilo de controle na função de `PreCreateWindow` no arquivo de *ProjName*Ctrl.cpp.  Para obter mais informações, consulte [Controles ActiveX MFC: subclasses de um controle do Windows](../../mfc/mfc-activex-controls-subclassing-a-windows-control.md).  
  
|Controle|Descrição|  
|--------------|---------------|  
|**BOTÃO**|Um controle de botão do windows|  
|**CAIXA FROM COMBINAÇÃO**|Um controle da caixa de combinação do windows|  
|**EDIÇÃO**|Um controle da caixa de edição do windows|  
|**LISTBOX**|Um controle na caixa de listagem do windows|  
|**BARRA DE ROLAGEM**|Um controle da barra de rolagem do windows|  
|**STATIC**|Um controle estático do windows|  
|**msctls\_hotkey32**|Um controle comuns de tecla de acesso|  
|**msctls\_progress32**|Um controle comuns da barra de progresso|  
|**msctls\_statusbar32**|Um controle comuns da barra de status|  
|**msctls\_trackbar32**|Um controle terrestres comuns da barra de controle|  
|**msctls\_updown32**|Um controle mais comum do botão de rotação \(ou o up\-down\)|  
|**SysAnimate32**|Um controle comuns de animação|  
|**SysHeader32**|Um controle mais comum do cabeçalho|  
|**SysListView32**|Um controle comuns de exibição de lista|  
|**SysTabControl32**|Um controle comuns da guia|  
|**SysTreeView32**|Um controle comuns de exibição de árvore|  
  
 **Ativa quando visível**  
 Especifica que uma janela é criada para o controle quando é acessada.  Por padrão, a opção de **Ativa quando visível** é selecionada.  Se você deseja adiar a ativação de controle até que o contêiner para exigir \(por exemplo, quando um usuário clica no mouse\), desmarque essa opção.  Quando esse recurso está, o controle não imponha a despesa de criação da janela até que seja necessário.  Para obter mais informações, consulte [Desativando a opção Ativar Quando Visível](../../mfc/turning-off-the-activate-when-visible-option.md).  
  
 **Invisível em tempo de execução**  
 Especifica que o controle não tem nenhuma interface do usuário em tempo de execução.  Um timer é um tipo de controle que talvez você queira ser invisível.  
  
 **Tem cerca de uma caixa de diálogo da caixa**  
 Especifica que o controle tiver a caixa de diálogo padrão de **Sobre** do windows, que exibe informações de número de versão e os direitos reservados.  
  
> [!NOTE]
>  Como os acessa o ajuda do controle depende de como você implementar a ajuda e se você tem a ajuda do controle com a ajuda do contêiner.  Para obter mais informações sobre como integrar a ajuda, [A Biblioteca MSDN](http://go.microsoft.com/fwlink/?linkID=150542) no site, procure “adicionando ajuda contextual a um controle ActiveX de MFC”.  
  
 Quando você selecionar essa opção, insere o método de controle de `AboutBox` na classe do controle de projeto \(2.0*ProjName*Ctrl.cpp C\) e adiciona AboutBox no mapa da expedição do projeto.  Por padrão, esta opção é selecionada.  
  
 **Código otimizado de desenho**  
 Especifica que o contêiner restaura os objetos originais de GDI automaticamente depois que todos os controles de contêineres, que são desenhados no mesmo contexto do dispositivo, foram extraídos.  Para obter mais informações sobre esse recurso, consulte [Otimizando o desenho de controle](../../mfc/optimizing-control-drawing.md).  
  
 **Ativação sem o windows**  
 Especifica que o controle não gerencia uma janela quando está ativado.  A ativação sem o windows permite controles nonrectangular ou transparentes, e um controle sem o windows requer menos sobrecarga do sistema do que um controle que tem uma janela necessário.  Um controle sem o windows não permite um contexto unclipped de dispositivo ou uma ativação cintilação\- livre.  Os contêineres que foram criados antes de 1996 não dão suporte à ativação sem o windows.  Para obter mais informações sobre como usar essa opção, consulte [Fornecendo ativação sem janelas](../../mfc/providing-windowless-activation.md).  
  
 **Contexto Unclipped de dispositivo**  
 As substituições [COleControl::GetControlFlags](../Topic/COleControl::GetControlFlags.md) no cabeçalho de controle \(*projname*ctrl.h\) para desabilitar a chamada a `IntersectClipRect` feitas por `COleControl`.  Quando você selecionar essa opção, fornece uma pequena vantagem da velocidade.  Se você selecionar **Ativação sem o windows**, este recurso não está disponível.  Para obter mais informações, consulte [Usando um contexto de dispositivo não recortado](../../mfc/using-an-unclipped-device-context.md).  
  
 **ativação Cintilação\-livre**  
 Eliminar as operações de desenho e a cintilação visual de rastreamento que ocorrem entre os estados ativas e inativas do controle.  Se você selecionar **Ativação sem o windows**, este recurso não está disponível.  Quando você definir esta opção, o sinalizador de `noFlickerActivate` é um dos sinalizadores que são retornados por [COleControl::GetControlFlags](../Topic/COleControl::GetControlFlags.md).  Para obter mais informações, consulte [Fornecendo ativação sem cintilação](../../mfc/providing-flicker-free-activation.md).  
  
 **Disponível na caixa de diálogo do objeto de inserção**  
 Especifica que o controle estará disponível na caixa de diálogo de **Inserir objeto** para contêineres habilitados.  Quando você selecionar essa opção, o sinalizador de `afxRegInsertable` é um dos sinalizadores que são retornados por `AfxOleRegisterControlClass`.  Usando a caixa de diálogo **Inserir objeto** , um usuário pode inserir objetos criados recentemente ou existentes em um documento composto.  
  
 **Notificações do ponteiro do mouse em quando inativo**  
 Habilita o controle para processar mensagens de notificação do ponteiro do mouse em, se o controle está ativo ou não.  Quando você selecionar essa opção, o sinalizador de `pointerInactive` é um dos sinalizadores que são retornados por [COleControl::GetControlFlags](../Topic/COleControl::GetControlFlags.md).  Para obter mais informações sobre como usar essa opção, consulte [Fornecendo interação do mouse enquanto inativo](../Topic/Providing%20Mouse%20Interaction%20While%20Inactive.md).  
  
 **Atua como um controle simples do quadro**  
 Especifica que o controle é um contêiner para outros controles definindo o bit de `OLEMISC_SIMPLEFRAME` para o controle.  Para obter mais informações, [A Biblioteca MSDN](http://go.microsoft.com/fwlink/?linkID=150542) no site, pesquise “a retenção simples de sites do quadro”.  
  
 **Carrega propriedades de forma assíncrona**  
 Habilita uma redefinição de todos os dados assíncronas anteriores e inicia uma nova carga da propriedade assíncrono do controle.  
  
## Consulte também  
 [Assistente de controle ActiveX MFC](../../mfc/reference/mfc-activex-control-wizard.md)   
 [Configurações do aplicativo, Assistente de Controle ActiveX MFC](../../mfc/reference/application-settings-mfc-activex-control-wizard.md)   
 [Nomes de controle, Assistente de Controle ActiveX MFC](../../mfc/reference/control-names-mfc-activex-control-wizard.md)