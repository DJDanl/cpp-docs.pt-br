---
title: "Recursos avançados, Assistente de aplicativo MFC | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- devlang-cpp
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.appwiz.mfc.exe.advanced
dev_langs:
- C++
helpviewer_keywords:
- MFC Application Wizard, advanced features
ms.assetid: 8a6681c5-6576-4b12-841a-6862beee76fa
caps.latest.revision: 17
author: mikeblome
ms.author: mblome
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
translationtype: Machine Translation
ms.sourcegitcommit: bb94e24657d16b2a3eda3a770c2b6ae734c6006f
ms.openlocfilehash: 9a291af4641742cd9b771c80a7ea0770fab6de06
ms.lasthandoff: 04/12/2017

---
# <a name="advanced-features-mfc-application-wizard"></a>Funcionalidades avançadas, Assistente de Aplicativo MFC
Este tópico lista as opções para recursos adicionais para seu aplicativo, como a Ajuda, suporte para impressão e assim por diante. Em cada seção, especifique o suporte adicional para esses recursos avançados.  
  
 **Ajuda contextual (HTML)**  
 Gera um conjunto de arquivos de ajuda para obter ajuda contextual, disponíveis por meio de um menu de Ajuda e F1 ou clicando em um **ajuda** botão em uma caixa de diálogo. O suporte para ajuda requer o compilador de ajuda. Se você não tiver o compilador de ajuda, poderá instalá-lo executando novamente a instalação.  
  
 Consulte [ajuda HTML: Ajuda sensível ao contexto de seus programas](../../mfc/html-help-context-sensitive-help-for-your-programs.md) e [arquivos de Ajuda (Ajuda HTML)](../../ide/help-files-html-help.md) para obter mais informações.  
  
 **Impressão e visualização de impressão**  
 Gera o código para lidar com a impressão, imprimir a instalação e comandos de visualização de impressão chamando funções de membro [classe CView](../../mfc/reference/cview-class.md) da biblioteca do MFC. O assistente também adiciona comandos dessas funções ao menu do aplicativo. Suporte de impressão está disponível somente para aplicativos que especifiquem **suporte para a arquitetura de documento/exibição** no [tipo de aplicativo, Assistente de aplicativo MFC](../../mfc/reference/application-type-mfc-application-wizard.md) página do assistente. Por padrão, os aplicativos de documento/exibição têm suporte para impressão.  
  
 **Automação**  
 Especifica que o aplicativo pode lidar com os objetos que são implementados em outro aplicativo, ou expõe o aplicativo a clientes de automação.  
  
 **Controles ActiveX**  
 Oferece suporte para controles ActiveX (padrão). Se você não selecionar essa opção e depois quiser inserir controles ActiveX em seu projeto, você deve adicionar uma chamada para [AfxEnableControlContainer](ole-initialization.md#afxenablecontrolcontainer) em seu aplicativo [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) função de membro.  
  
 **MAPI (API de mensagens)**  
 Especifica que o aplicativo pode criar, manipular, transferir e armazenar mensagens de email.  
  
 **Soquetes do Windows**  
 Oferece suporte ao Windows Sockets, que você pode usar para escrever aplicativos que se comuniquem por redes TCP/IP.  
  
 **Acessibilidade ativa**  
 Adiciona suporte para [IAccessible](http://msdn.microsoft.com/library/windows/desktop/dd318466) para [CWnd](../../mfc/reference/cwnd-class.md)-classes derivadas, que você pode usar para personalizar a interface do usuário para melhor interação com clientes de acessibilidade.  
  
 **Manifesto de controle comum**  
 Habilitado por padrão. Gera um manifesto de aplicativo para habilitar a DLL de Controle Comum que é fornecida com o Microsoft Windows XP e sistemas operacionais mais recentes.  
  
 A versão 6 da DLL de Controle Comum não atualiza automaticamente a versão anterior dos Controles Comuns que seus aplicativos existentes usam. Para usar a versão 6 da DLL de Controle Comum, você deve criar um manifesto de aplicativo que direcione o aplicativo para carregar a DLL. Essa DLL de Controle Comum também oferece suporte aos temas do Windows XP.  
  
 Um manifesto de aplicativo também pode especificar outros DLLs e versões que seu aplicativo precisa. Para obter mais informações sobre manifestos de aplicativo, consulte [aplicativos isolados e Assemblies lado a lado](http://msdn.microsoft.com/library/dd408052) no [!INCLUDE[winsdkshort](../../atl-mfc-shared/reference/includes/winsdkshort_md.md)].  
  
 **Gerenciador de reinicialização de suporte**  
 Adiciona suporte para o [Gerenciador de reinicialização do Windows](http://msdn.microsoft.com/library/windows/desktop/aa373680\(v=vs.85\).aspx). Este vídeo mostra como usar o Gerenciador de reinicialização do MFC: [como fazer: usar o novo Gerenciador de reinicialização](http://msdn.microsoft.com/vstudio/ee886407).  
  
 **Painéis de quadros avançado**  
 |Opção|Descrição|  
|------------|-----------------|  
|**Painel de encaixe do Explorer**|Cria um painel que se parece com o Visual Studio **Solution Explorer** à esquerda da janela do quadro principal.|  
|**Quadro de encaixe de saída**|Cria um painel que se parece com o Visual Studio **saída** painel está localizado sob a janela do quadro principal.|  
|**Encaixar o painel de propriedades**|Cria um painel que se parece com o Visual Studio **propriedades** painel à direita da janela do quadro principal.|  
|**Painel de navegação**|Cria um painel de encaixe semelhante ao da barra de navegação do Outlook e está localizado à esquerda da janela principal do quadro.|  
|**Barra de legenda**|Cria uma barra de legenda do estilo do Office acima da janela do quadro principal.|  
  
 **Número de arquivos na lista de arquivos recentes**  
 Especifica o número de arquivos a serem relacionados na lista de itens usados mais recentemente. O número padrão é 4.  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de aplicativo do MFC](../../mfc/reference/mfc-application-wizard.md)


