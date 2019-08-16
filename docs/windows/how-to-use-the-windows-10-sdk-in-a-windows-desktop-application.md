---
title: 'Como: Usar o SDK do Windows 10 em um aplicativo de área de trabalho do Windows'
ms.custom: get-started-article
ms.date: 07/12/2018
ms.assetid: eed6421e-9355-44a6-9582-3f1d453a6d44
ms.openlocfilehash: 8dbf18d24c0369507743c3c1da624838f9ab4703
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69513826"
---
# <a name="how-to-use-the-windows-10-sdk-in-a-windows-desktop-application"></a>Como: Usar o SDK do Windows 10 em um aplicativo de área de trabalho do Windows

Quando você cria um projeto de área de trabalho do Windows clássico no Visual Studio 2017, ele é configurado por padrão para compilar com a versão do SDK do Windows 10 que foi C++ instalada quando a carga de trabalho de desktop foi instalada ou atualizada pela última vez. Esta versão do SDK do Windows é compatível com o Windows 7 e posterior. Consulte [usando os cabeçalhos do Windows](/windows/win32/WinProg/using-the-windows-headers) para obter mais informações sobre como direcionar versões específicas do Windows.

Se você quiser ter como destino uma versão anterior do SDK, poderá abrir o **projeto | Propriedades** e escolha entre as outras versões do SDK disponíveis no menu suspenso versão do SDK do Windows.

A partir do Visual Studio 2015 e do SDK do Windows 10, a biblioteca CRT foi separada em duas partes, uma (ucrtbase) que contém as funções que são aceitáveis para serem usadas em aplicativos universais do Windows e uma que contém todo o resto (vcruntime140). Como o SDK do Windows 10 contém novas funções, como muitas funções C99, você precisa seguir estas etapas para usar essas funções. Consulte [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md).

### <a name="to-target-the-windows-10-sdk"></a>Para direcionar o SDK do Windows 10

1. Verifique se o SDK do Windows 10 está instalado. O SDK do Windows 10 é instalado como parte do **desenvolvimento de desktop C++ com** carga de trabalho. Uma versão autônoma está disponível em [downloads e ferramentas para Windows 10](https://developer.microsoft.com/windows/downloads).

2. Abra o menu de atalho para o nó do projeto e escolha redirecionar **versão do SDK**.

   ![Redirecionar versão do SDK](../windows/media/retargetingwindowssdk1.PNG "RetargetingWindowsSDK1")

   A caixa de diálogo **examinar ações da solução** é exibida.

   ![Examinar ações da solução](../windows/media/retargetingwindowssdk2.PNG "RetargetingWindowsSDK2")

3. Na lista suspensa **versão da plataforma de destino** , escolha a versão do SDK do Windows 10 que você deseja direcionar. Escolha o botão OK para aplicar a alteração.

   Observe que 8,1 neste contexto refere-se à versão SDK do Windows, que também é compatível com versões anteriores do Windows 8, Windows Server 2012, Windows 7, Windows Server 2008 e Windows Vista.

   Se essa etapa for bem-sucedida, o texto a seguir aparecerá na janela de saída:

   `Retargeting End: 1 completed, 0 failed, 0 skipped`

4. Abra as propriedades do projeto e, na seção **Propriedades de configuração, geral** , observe os valores da **versão da plataforma de destino do Windows**. A alteração do valor aqui tem o mesmo efeito do seguinte procedimento. Consulte a [página de propriedades geral (projeto)](../build/reference/general-property-page-project.md).

   ![Versão da plataforma de destino](../windows/media/retargetingwindowssdk3.PNG "RetargetingWindowsSDK3")

   Essa ação altera os valores de macros do projeto que incluem caminhos para arquivos de cabeçalho e arquivos de biblioteca. Para ver o que mudou, na **seção C++ diretórios visuais** da caixa de diálogo **Propriedades do projeto** , escolha uma das propriedades, como os **diretórios de inclusão**, escolha abrir a lista suspensa e escolha \<Editar >. A caixa de diálogo **incluir diretórios** é exibida.

   ![Caixa de diálogo incluir diretórios](../windows/media/retargetingwindowssdk4.PNG "RetargetingWindowsSDK4")

   Escolha o botão **macros > >** e role para baixo na lista de macros para as macros SDK do Windows para ver todos os novos valores.

   ![SDK do Windows macros](../windows/media/retargetingwindowssdk5.PNG "RetargetingWindowsSDK5")

5. Repita para outros projetos, conforme necessário, e recompile a solução.

### <a name="to-target-the-windows-81-sdk"></a>Para direcionar o SDK do Windows 8.1

1. Abra o menu de atalho para o nó do projeto e escolha redirecionar **versão do SDK**.

2. Na lista suspensa **versão da plataforma de destino** , escolha **8,1**.

## <a name="see-also"></a>Consulte também

[Aplicativos da área de trabalho C++do Windows (Visual)](../windows/how-to-use-the-windows-10-sdk-in-a-windows-desktop-application.md)