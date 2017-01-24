---
title: "Recursos avan&#231;ados, Assistente de Aplicativo MFC | Microsoft Docs"
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
  - "vc.appwiz.mfc.exe.advanced"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Assistente de aplicativo MFC, recursos avançados"
ms.assetid: 8a6681c5-6576-4b12-841a-6862beee76fa
caps.latest.revision: 17
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Recursos avan&#231;ados, Assistente de Aplicativo MFC
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Este tópico lista as opções para recursos adicionais para seu aplicativo, como a Ajuda, suporte para impressão e assim por diante.  Em cada seção, especifique o suporte adicional para esses recursos avançados.  
  
 **Ajuda contextual \(HTML\)**  
 Gera um conjunto de arquivos de ajuda contextual, disponíveis usando F1 e um menu Ajuda, ou clicando em um botão **Ajuda** em uma caixa de diálogo.  O suporte para ajuda requer o compilador de ajuda.  Se você não tiver o compilador de ajuda, poderá instalá\-lo executando novamente a instalação.  
  
 Consulte [Ajuda em HTML: ajuda contextual para os programas](../../mfc/html-help-context-sensitive-help-for-your-programs.md) e [Arquivos de ajuda \(ajuda HTML\)](../../ide/help-files-html-help.md) para obter mais informações.  
  
 **Impressão e visualização de impressão**  
 Gera o código para lidar com a impressão, configuração de impressão e comandos de visualização de impressão chamando funções de membro no [Classe de CView](../Topic/CView%20Class.md) de biblioteca MFC.  O assistente também adiciona comandos dessas funções ao menu do aplicativo.  Suporte de impressão está disponível somente para aplicativos que especificam **suporte à arquitetura de documento\/exibição** no [Tipo de aplicativo, Assistente de Aplicativo MFC](../Topic/Application%20Type,%20MFC%20Application%20Wizard.md) página do assistente.  Por padrão, os aplicativos de documento\/exibição têm suporte para impressão.  
  
 **Automação**  
 Especifica que o aplicativo pode lidar com os objetos que são implementados em outro aplicativo, ou expõe o aplicativo a clientes de automação.  
  
 **Controles do ActiveX**  
 Oferece suporte para controles ActiveX \(padrão\).  Se você não selecionar essa opção e depois quiser inserir controles ActiveX em seu projeto, você deve adicionar uma chamada para [AfxEnableControlContainer](../Topic/AfxEnableControlContainer.md) em seu aplicativo [CWinApp::InitInstance](../Topic/CWinApp::InitInstance.md) função de membro.  
  
 **MAPI \(API de mensagens\)**  
 Especifica que o aplicativo pode criar, manipular, transferir e armazenar mensagens de email.  
  
 **Windows Sockets**  
 Oferece suporte ao Windows Sockets, que você pode usar para escrever aplicativos que se comuniquem por redes TCP\/IP.  
  
 **Acessibilidade Ativa**  
 Adiciona suporte para [IAccessible](http://msdn.microsoft.com/library/windows/desktop/dd318466) a classes derivadas de [CWnd](../Topic/CWnd%20Class.md), que você pode usar para personalizar a interface de usuário para melhorar a interação com clientes de acessibilidade.  
  
 **Manifesto de Controle Comum**  
 Habilitado por padrão.  Gera um manifesto de aplicativo para habilitar a DLL de Controle Comum que é fornecida com o Microsoft Windows XP e sistemas operacionais mais recentes.  
  
 A versão 6 da DLL de Controle Comum não atualiza automaticamente a versão anterior dos Controles Comuns que seus aplicativos existentes usam.  Para usar a versão 6 da DLL de Controle Comum, você deve criar um manifesto de aplicativo que direcione o aplicativo para carregar a DLL.  Essa DLL de Controle Comum também oferece suporte aos temas do Windows XP.  
  
 Um manifesto de aplicativo também pode especificar outros DLLs e versões que seu aplicativo precisa.  Para obter mais informações sobre manifestos de aplicativo, consulte [Aplicativos isolados e assemblies lado a lado](http://msdn.microsoft.com/library/dd408052) em [!INCLUDE[winsdkshort](../../atl/reference/includes/winsdkshort_md.md)].  
  
 **Oferecer Suporte ao Gerenciador de Reinicialização**  
 Adiciona suporte para o [Gerenciador de reinicialização do Windows](http://msdn.microsoft.com/library/windows/desktop/aa373680\(v=vs.85\).aspx).  Este vídeo mostra como usar o Gerenciador de reinicialização do MFC: [como fazer: usar o novo Gerenciador de reinicialização?](http://msdn.microsoft.com/vstudio/ee886407).  
  
 **Painéis de quadros avançados**  
 |Opção|Descrição|  
|-----------|---------------|  
|**Painel de encaixe Gerenciador de Soluções**|Cria um painel de encaixe semelhante ao do **Gerenciador de Soluções** do Visual Studio à esquerda da janela principal do quadro.|  
|**Quadro de encaixe Saída**|Cria um painel de encaixe semelhante ao painel **Saída** do Visual Studio que está localizado na janela principal do quadro.|  
|**Painel de encaixe Propriedades**|Cria um painel de encaixe semelhante ao painel **Propriedades** do Visual Studio à direita da janela principal do quadro.|  
|**Painel de navegação**|Cria um painel de encaixe semelhante ao da barra de navegação do Outlook e está localizado à esquerda da janela principal do quadro.|  
|**Barra de legenda**|Cria uma barra de legenda do estilo do Office acima da janela do quadro principal.|  
  
 **Número de arquivos na lista de arquivos recentes**  
 Especifica o número de arquivos a serem relacionados na lista de itens usados mais recentemente.  O número padrão é 4.  
  
## Consulte também  
 [Assistente de aplicativo MFC](../Topic/MFC%20Application%20Wizard.md)