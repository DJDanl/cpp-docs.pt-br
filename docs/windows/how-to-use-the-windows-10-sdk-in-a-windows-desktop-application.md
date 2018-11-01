---
title: 'Como: usar o Windows 10 SDK em um aplicativo de área de trabalho do Windows'
ms.custom: get-started-article
ms.date: 07/12/2018
ms.assetid: eed6421e-9355-44a6-9582-3f1d453a6d44
ms.openlocfilehash: ed860a229866991b01266093058b71cc2ae84986
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50669112"
---
# <a name="how-to-use-the-windows-10-sdk-in-a-windows-desktop-application"></a>Como: usar o Windows 10 SDK em um aplicativo de área de trabalho do Windows

Quando você cria um projeto de área de trabalho clássico do Windows no Visual Studio 2017, ele é configurado por padrão para compilar com a versão do SDK do Windows 10 foi instalado quando a carga de trabalho de área de trabalho do C++ foi instalada ou atualizado pela última vez. Esta versão do SDK do Windows é compatível com o Windows 7 e posterior. Ver [usando os cabeçalhos do Windows](/windows/desktop/WinProg/using-the-windows-headers) para obter mais informações sobre destinados a versões específicas do Windows.

Se você quiser direcionar uma versão anterior do SDK, você pode abrir **projeto | Propriedades** e escolher entre as outras versões do SDK disponíveis no menu suspenso de versão de SDK do Windows.

Começando com o Visual Studio 2015 e o SDK do Windows 10, a biblioteca de CRT foram separada em duas partes, uma (ucrtbase) que contém as funções que são aceitáveis para ser usado em aplicativos universais do Windows e outra que contém todo o resto (vcruntime140). Uma vez que o SDK do Windows 10 contém novas funções, como muitas funções C99, você precisará siga estas etapas para usar essas funções. Consulte [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md).

### <a name="to-target-the-windows-10-sdk"></a>Para direcionar o SDK do Windows 10

1. Verifique se que o SDK do Windows 10 está instalado. SDK do Windows 10 é instalado como parte dos **desenvolvimento para Desktop com C++** carga de trabalho. Uma versão autônoma está disponível em [Downloads e ferramentas para Windows 10](https://developer.microsoft.com/windows/downloads).

2. Abra o menu de atalho do nó do projeto e escolha **redirecionar SDK versão**.

   ![Redirecionar a versão do SDK](../windows/media/retargetingwindowssdk1.PNG "RetargetingWindowsSDK1")

   O **ações de solução de análise** caixa de diálogo é exibida.

   ![Examine as ações de solução](../windows/media/retargetingwindowssdk2.PNG "RetargetingWindowsSDK2")

3. No **versão da plataforma de destino** lista suspensa, escolha a versão do SDK do Windows 10 de destino. Escolha o botão Okey para aplicar a alteração.

   Observe que 8.1 neste contexto refere-se para a versão do SDK do Windows, que também tem compatibilidade com o Windows 8, Windows Server 2012, Windows 7, Windows Server 2008 e Windows Vista.

   Se essa etapa for bem-sucedida, o texto a seguir será exibida na janela de saída:

   `Retargeting End: 1 completed, 0 failed, 0 skipped`

4. Abra as propriedades do projeto e, na **propriedades de configuração, geral** seção, observe os valores de **versão de plataforma de destino do Windows**. Alterar o valor aqui tem o mesmo efeito que esse procedimento. Ver [página de propriedades gerais (projeto)](../ide/general-property-page-project.md).

   ![Versão da plataforma de destino](../windows/media/retargetingwindowssdk3.PNG "RetargetingWindowsSDK3")

   Esta ação altera os valores das macros de projeto que incluem caminhos para arquivos de biblioteca e arquivos de cabeçalho. Para ver o que mudou na **diretórios do Visual C++** seção o **propriedades do projeto** caixa de diálogo, escolha uma das propriedades, como o **diretórios de inclusão**, optar por Abra a lista suspensa e escolha \<Editar >. O **diretórios de inclusão** caixa de diálogo é exibida.

   ![Incluir caixa de diálogo de diretórios](../windows/media/retargetingwindowssdk4.PNG "RetargetingWindowsSDK4")

   Escolha o **Macros >>** botão e role para baixo na lista de macros para as macros do SDK do Windows para ver os novos valores.

   ![Macros SDK do Windows](../windows/media/retargetingwindowssdk5.PNG "RetargetingWindowsSDK5")

5. Repita para outros projetos, conforme necessário e recompile a solução.

### <a name="to-target-the-windows-81-sdk"></a>Para direcionar o SDK do Windows 8.1

1. Abra o menu de atalho do nó do projeto e escolha **redirecionar SDK versão**.

2. No **versão da plataforma de destino** dropdown, escolha **8.1**.

## <a name="see-also"></a>Consulte também

[Aplicativos da área de trabalho do Windows (Visual C++)](../windows/how-to-use-the-windows-10-sdk-in-a-windows-desktop-application.md)