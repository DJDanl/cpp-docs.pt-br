---
title: Recursos avançados, Assistente de Aplicativo MFC
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.mfc.exe.advanced
helpviewer_keywords:
- MFC Application Wizard, advanced features
ms.assetid: 8a6681c5-6576-4b12-841a-6862beee76fa
ms.openlocfilehash: dc2b745bf97dff65a3612c29745c9d0e455a347d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69507801"
---
# <a name="advanced-features-mfc-application-wizard"></a>Recursos avançados, Assistente de Aplicativo MFC

Este tópico lista as opções para recursos adicionais para seu aplicativo, como a Ajuda, suporte para impressão e assim por diante. Em cada seção, especifique o suporte adicional para esses recursos avançados.

- **Ajuda contextual (HTML)**

   Gera um conjunto de arquivos de ajuda para a ajuda contextual, disponível usando F1 e um menu de ajuda, ou clicando em um botão **ajuda** em uma caixa de diálogo. O suporte para ajuda requer o compilador de ajuda. Se você não tiver o compilador de ajuda, poderá instalá-lo executando novamente a instalação.

   Consulte [a ajuda em HTML: Ajuda contextual para seus programas](../../mfc/html-help-context-sensitive-help-for-your-programs.md) e arquivos de [ajuda (ajuda HTML)](../../build/reference/help-files-html-help.md) para obter mais informações.

- **Impressão e visualização de impressão**

   Gera o código para lidar com os comandos Print e Print da visualização, chamando funções de membro na [classe cvisualização](../../mfc/reference/cview-class.md) da biblioteca do MFC. O assistente também adiciona comandos dessas funções ao menu do aplicativo. O suporte à impressão está disponível somente para aplicativos que especificam **suporte à arquitetura de documento/exibição** na página [tipo de aplicativo, assistente de aplicativo MFC](../../mfc/reference/application-type-mfc-application-wizard.md) do assistente. Por padrão, os aplicativos de documento/exibição têm suporte para impressão.

- **Automação**

   Especifica que o aplicativo pode lidar com os objetos que são implementados em outro aplicativo, ou expõe o aplicativo a clientes de automação.

- **Controles ActiveX**

   Oferece suporte para controles ActiveX (padrão). Se você não selecionar essa opção e posteriormente quiser inserir controles ActiveX em seu projeto, deverá adicionar uma chamada para [AfxEnableControlContainer](ole-initialization.md#afxenablecontrolcontainer) na função membro [CWinApp:: InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) do seu aplicativo.

- **MAPI (API de mensagens)**

   Especifica que o aplicativo pode criar, manipular, transferir e armazenar mensagens de email.

- **Windows Sockets**

   Oferece suporte ao Windows Sockets, que você pode usar para escrever aplicativos que se comuniquem por redes TCP/IP.

- **Acessibilidade Ativa**

   Adiciona suporte para [IAccessible](/windows/win32/api/oleacc/nn-oleacc-iaccessible) a classes derivadas de [CWnd](../../mfc/reference/cwnd-class.md), que você pode usar para personalizar a interface do usuário para melhor interação com clientes de acessibilidade.

- **Manifesto de controle comum**

   Habilitado por padrão. Gera um manifesto de aplicativo para habilitar a DLL de Controle Comum que é fornecida com o Microsoft Windows XP e sistemas operacionais mais recentes.

   A versão 6 da DLL de Controle Comum não atualiza automaticamente a versão anterior dos Controles Comuns que seus aplicativos existentes usam. Para usar a versão 6 da DLL de Controle Comum, você deve criar um manifesto de aplicativo que direcione o aplicativo para carregar a DLL. Essa DLL de Controle Comum também oferece suporte aos temas do Windows XP.

   Um manifesto de aplicativo também pode especificar outros DLLs e versões que seu aplicativo precisa. Para obter mais informações sobre manifestos de aplicativo, consulte [aplicativos isolados e assemblies](/windows/win32/SbsCs/isolated-applications-and-side-by-side-assemblies-portal) lado a lado no SDK do Windows.

- **Gerenciador de reinicialização de suporte**

   Adiciona suporte para o [Gerenciador](/windows/win32/RstMgr/using-restart-manager)de reinicializações do Windows. Este vídeo mostra como usar o Gerenciador de reinicialização do MFC: [Como faço para: Use o novo Gerenciador](/previous-versions/visualstudio/visual-studio-2010/dd831853(v%3dvs.100))de reinicialização.

- **Painéis de quadros avançados**

   |Opção|Descrição|
   |------------|-----------------|
   |**Painel de encaixe do Explorer**|Cria um painel de encaixe que se assemelha ao **Gerenciador de soluções** do Visual Studio à esquerda da janela do quadro principal.|
   |**Quadro de encaixe de saída**|Cria um painel de encaixe que se assemelha ao painel de **saída** do Visual Studio localizado na janela do quadro principal.|
   |**Painel de encaixe de propriedades**|Cria um painel de encaixe que se assemelha ao painel de **Propriedades** do Visual Studio à direita da janela do quadro principal.|
   |**Painel de navegação**|Cria um painel de encaixe semelhante ao da barra de navegação do Outlook e está localizado à esquerda da janela principal do quadro.|
   |**Barra de legenda**|Cria uma barra de legenda do estilo do Office acima da janela do quadro principal.|

- **Número de arquivos na lista de arquivos recentes**

   Especifica o número de arquivos a serem relacionados na lista de itens usados mais recentemente. O número padrão é 4.

## <a name="see-also"></a>Consulte também

[Assistente de aplicativo do MFC](../../mfc/reference/mfc-application-wizard.md)
