---
title: 'Como: usar o SDK do Windows 10 em um aplicativo de área de trabalho do Windows'
description: Como definir a versão do SDK de destino em um projeto de aplicativo da área de trabalho do Windows para usar o SDK do Windows 10.
ms.custom: get-started-article
ms.date: 01/22/2020
ms.assetid: eed6421e-9355-44a6-9582-3f1d453a6d44
ms.openlocfilehash: c1d71b591398453f7cee02aa22cd2e377991588f
ms.sourcegitcommit: b67b08472b6f1ee8f1c5684bba7056d3e0fc745f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/24/2020
ms.locfileid: "76725728"
---
# <a name="how-to-use-the-windows-10-sdk-in-a-windows-desktop-application"></a>Como: usar o SDK do Windows 10 em um aplicativo de área de trabalho do Windows

Quando você cria um novo projeto clássico do Windows desktop no Visual Studio, ele se destina ao SDK do Windows 10 por padrão. O Visual Studio instala uma versão desse SDK quando você instala a C++ carga de trabalho da área de trabalho. O SDK do Windows 10 dá suporte à gravação de código para o Windows 7 SP1 e posterior. Para obter mais informações sobre como direcionar versões específicas do Windows, consulte [usando os cabeçalhos do Windows](/windows/win32/WinProg/using-the-windows-headers) e [atualizar WINVER e _WIN32_WINNT](../porting/modifying-winver-and-win32-winnt.md).

Ao atualizar um projeto existente, você tem uma opção: você pode continuar usando o SDK do Windows de destino especificado em seu projeto. Ou, você pode redirecionar seu projeto para usar o SDK do Windows 10. Com o SDK do Windows 10, você obtém as vantagens do suporte para os sistemas operacionais e os padrões de linguagem mais recentes.

## <a name="use-the-right-windows-sdk-for-your-project"></a>Use o SDK do Windows correto para seu projeto

A partir do Visual Studio 2015, a biblioteca do C Runtime (CRT) foi separada em duas partes: uma parte, ucrtbase, contém as funções CRT padrão C e da Microsoft que você pode usar em aplicativos universais do Windows. Essa biblioteca agora é conhecida como CRT ou UCRT universal e foi movida para o SDK do Windows 10. O UCRT contém muitas funções novas, como funções do C99, necessárias para dar suporte aos C++ padrões de idioma mais recentes. A outra parte do CRT original é o vcruntime. Ele contém o suporte ao tempo de execução C, a inicialização e o código de encerramento e tudo o mais que não entraram no UCRT. A biblioteca vcruntime é instalada juntamente com o C++ compilador e o conjunto de ferramentas no Visual Studio. Para obter mais informações, consulte [recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md).

O UCRT agora é um componente do sistema instalado em todas as versões do Windows 10. Ele também está disponível como um componente instalável para todas as versões anteriores do Windows com suporte. Você pode usar o SDK do Windows 10 para direcionar todas as versões do Windows com suporte. Para obter uma lista completa dos sistemas operacionais com suporte, consulte [SDK do Windows 10](https://developer.microsoft.com/windows/downloads/windows-10-sdk).

Para redirecionar seus projetos para usar o SDK do Windows 10 ao atualizar de uma versão do projeto antes do Visual Studio 2015, siga estas etapas:

### <a name="to-target-the-windows-10-sdk"></a>Para direcionar o SDK do Windows 10

1. Verifique se o SDK do Windows 10 está instalado. O SDK do Windows 10 é instalado como parte do **desenvolvimento de desktop C++ com** carga de trabalho. Uma versão autônoma está disponível em [downloads e ferramentas para Windows 10](https://developer.microsoft.com/windows/downloads).

1. Abra o menu de atalho para o nó do projeto e escolha **redirecionar projetos**. (Em versões anteriores do Visual Studio, escolha **redirecionar versão do SDK**.) A caixa de diálogo **examinar ações da solução** é exibida.

   ![Examinar ações da solução](../windows/media/retargetingwindowssdk2.PNG "RetargetingWindowsSDK2")

1. Na lista suspensa **versão da plataforma de destino** , escolha a versão do SDK do Windows 10 que você deseja direcionar. Em geral, recomendamos que você escolha a versão mais recente instalada. Escolha o botão **OK** para aplicar a alteração.

   O 8,1 neste contexto refere-se ao SDK do Windows 8.1.

   Se essa etapa for bem-sucedida, o texto a seguir aparecerá na janela de saída:

   `Retargeting End: 1 completed, 0 failed, 0 skipped`

1. Abra a caixa de diálogo Propriedades do projeto. Na seção **Propriedades de configuração** > **geral** , observe os valores da **versão da plataforma de destino do Windows**. A alteração do valor aqui tem o mesmo efeito do seguinte procedimento. Para obter mais informações, confira [Página de propriedades Geral (projeto)](../build/reference/general-property-page-project.md).

   ![Versão da plataforma de destino](../windows/media/retargetingwindowssdk3.PNG "RetargetingWindowsSDK3")

   Essa ação altera os valores de macros do projeto que incluem caminhos para arquivos de cabeçalho e arquivos de biblioteca. Para ver o que mudou, abra a seção **diretórios C++ visuais** da caixa de diálogo **Propriedades do projeto** . Selecione uma das propriedades, como diretórios de **inclusão**. Em seguida, abra a lista suspensa do valor da propriedade e escolha **\<editar >** . A caixa de diálogo **incluir diretórios** é exibida.

   ![Caixa de diálogo incluir diretórios](../windows/media/retargetingwindowssdk4.PNG "RetargetingWindowsSDK4")

   Escolha o botão **macros > >** e role para baixo na lista de macros para as macros SDK do Windows para ver todos os novos valores.

   ![SDK do Windows macros](../windows/media/retargetingwindowssdk5.PNG "RetargetingWindowsSDK5")

1. Repita o procedimento de redirecionamento para outros projetos de solução, conforme necessário, e recompile a solução.

### <a name="to-target-the-windows-81-sdk"></a>Para direcionar o SDK do Windows 8.1

1. Abra o menu de atalho do nó do projeto no Gerenciador de Soluções e escolha **redirecionar projetos**. (Em versões anteriores do Visual Studio, escolha **redirecionar versão do SDK**.)

2. Na lista suspensa **versão da plataforma de destino** , escolha **8,1**.

## <a name="see-also"></a>Veja também

[Walkthrough: criar um aplicativo de área de trabalhoC++do Windows tradicional ()](../windows/walkthrough-creating-windows-desktop-applications-cpp.md)
