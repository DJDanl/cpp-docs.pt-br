---
title: Recursos avançados, Assistente de aplicativo MFC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- vc.appwiz.mfc.exe.advanced
dev_langs:
- C++
helpviewer_keywords:
- MFC Application Wizard, advanced features
ms.assetid: 8a6681c5-6576-4b12-841a-6862beee76fa
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c5a3746116679ba8cfee086b42359cce8003b282
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43198120"
---
# <a name="advanced-features-mfc-application-wizard"></a>Funcionalidades avançadas, Assistente de Aplicativo MFC
Este tópico lista as opções para recursos adicionais para seu aplicativo, como a Ajuda, suporte para impressão e assim por diante. Em cada seção, especifique o suporte adicional para esses recursos avançados.  
  
 **Ajuda contextual (HTML)**  
 Gera um conjunto de arquivos de ajuda para obter ajuda contextual, disponíveis usando F1 e um menu de Ajuda, ou clicando em um **ajudar** botão em uma caixa de diálogo. O suporte para ajuda requer o compilador de ajuda. Se você não tiver o compilador de ajuda, poderá instalá-lo executando novamente a instalação.  
  
 Ver [Ajuda em HTML: sensível ao contexto de ajuda para seus programas](../../mfc/html-help-context-sensitive-help-for-your-programs.md) e [arquivos de Ajuda (Ajuda HTML)](../../ide/help-files-html-help.md) para obter mais informações.  
  
 **Impressão e visualização de impressão**  
 Gera o código para lidar com a impressão, configuração de impressão e comandos de visualização de impressão chamando funções de membro na [classe CView](../../mfc/reference/cview-class.md) da biblioteca do MFC. O assistente também adiciona comandos dessas funções ao menu do aplicativo. Suporte de impressão está disponível somente para aplicativos que especificam **suporte de arquitetura de documento/exibição** na [tipo de aplicativo, Assistente de aplicativo MFC](../../mfc/reference/application-type-mfc-application-wizard.md) página do assistente. Por padrão, os aplicativos de documento/exibição têm suporte para impressão.  
  
 **Automação**  
 Especifica que o aplicativo pode lidar com os objetos que são implementados em outro aplicativo, ou expõe o aplicativo a clientes de automação.  
  
 **Controles ActiveX**  
 Oferece suporte para controles ActiveX (padrão). Se você não selecionar essa opção e depois quiser inserir controles ActiveX em seu projeto, você deve adicionar uma chamada para [AfxEnableControlContainer](ole-initialization.md#afxenablecontrolcontainer) em seu aplicativo [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) membro função.  
  
 **MAPI (API de mensagens)**  
 Especifica que o aplicativo pode criar, manipular, transferir e armazenar mensagens de email.  
  
 **Soquetes do Windows**  
 Oferece suporte ao Windows Sockets, que você pode usar para escrever aplicativos que se comuniquem por redes TCP/IP.  
  
 **Acessibilidade ativa**  
 Adiciona suporte para [IAccessible](/windows/desktop/api/oleacc/nn-oleacc-iaccessible) à [CWnd](../../mfc/reference/cwnd-class.md)-classes derivadas, que você pode usar para personalizar a interface do usuário para melhorar a interação com clientes de acessibilidade.  
  
 **Manifesto de controle comum**  
 Habilitado por padrão. Gera um manifesto de aplicativo para habilitar a DLL de Controle Comum que é fornecida com o Microsoft Windows XP e sistemas operacionais mais recentes.  
  
 A versão 6 da DLL de Controle Comum não atualiza automaticamente a versão anterior dos Controles Comuns que seus aplicativos existentes usam. Para usar a versão 6 da DLL de Controle Comum, você deve criar um manifesto de aplicativo que direcione o aplicativo para carregar a DLL. Essa DLL de Controle Comum também oferece suporte aos temas do Windows XP.  
  
 Um manifesto de aplicativo também pode especificar outros DLLs e versões que seu aplicativo precisa. Para obter mais informações sobre manifestos de aplicativo, consulte [aplicativos isolados e Assemblies lado a lado](/windows/desktop/SbsCs/isolated-applications-and-side-by-side-assemblies-portal) no SDK do Windows.  
  
 **Suporte ao Gerenciador de reinicialização**  
 Adiciona suporte para o [Gerenciador de reinicialização do Windows](/windows/desktop/RstMgr/using-restart-manager). Este vídeo mostra como usar o Gerenciador de reinicialização do MFC: [como fazer: usar o novo Gerenciador de reinicialização](https://msdn.microsoft.com/vstudio/ee886407).  
  
 **Painéis de quadros avançados**  
 |Opção|Descrição|  
|------------|-----------------|  
|**Painel de encaixe do Explorer**|Cria um painel de encaixe que se parece com o Visual Studio **Gerenciador de soluções** à esquerda da janela principal do quadro.|  
|**Quadro de encaixe saída**|Cria um painel de encaixe que se parece com o Visual Studio **saída** painel está localizado sob a janela do quadro principal.|  
|**Painel de encaixe propriedades**|Cria um painel de encaixe que se parece com o Visual Studio **propriedades** painel à direita da janela principal do quadro.|  
|**Painel de navegação**|Cria um painel de encaixe semelhante ao da barra de navegação do Outlook e está localizado à esquerda da janela principal do quadro.|  
|**Barra de legenda**|Cria uma barra de legenda do estilo do Office acima da janela do quadro principal.|  
  
 **Número de arquivos na lista de arquivos recentes**  
 Especifica o número de arquivos a serem relacionados na lista de itens usados mais recentemente. O número padrão é 4.  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de aplicativo do MFC](../../mfc/reference/mfc-application-wizard.md)

