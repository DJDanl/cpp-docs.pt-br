---
title: "Como: usar o Windows 10 SDK em um aplicativo de área de trabalho do Windows | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: get-started-article
dev_langs: C++
ms.assetid: eed6421e-9355-44a6-9582-3f1d453a6d44
caps.latest.revision: "4"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1f5e6f09b371c4d295b4bcdff469396a2671d22a
ms.sourcegitcommit: 54035dce0992ba5dce0323d67f86301f994ff3db
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/03/2018
---
# <a name="how-to-use-the-windows-10-sdk-in-a-windows-desktop-application"></a>Como: usar o Windows 10 SDK em um aplicativo de área de trabalho do Windows
Quando você cria um projeto de área de trabalho clássico do Windows no Visual Studio de 2017, ela é configurada por padrão para compilar com a versão do SDK do Windows 10 foi instalado quando a carga de trabalho de área de trabalho do C++ foi instalada ou atualizado pela última vez. Esta versão do SDK do Windows é compatível com todas as versões recentes do Windows. Se você deseja direcionar uma versão anterior do SDK, você pode abrir o projeto | Propriedades e escolha entre as outras versões do SDK disponíveis na lista suspensa de versão de SDK do Windows.  
  
 A partir do Visual Studio 2015 e o SDK do Windows 10, a biblioteca CRT foi separada em duas partes, um (ucrtbase) que contém as funções que são aceitáveis para ser usado em aplicativos Universal do Windows e outro que contém todo o resto (vcruntime140). Como o SDK do Windows 10 contém novas funções, como muitas funções de C99, você precisa siga estas etapas para usar essas funções. Consulte [Recursos da biblioteca CRT](../c-runtime-library/crt-library-features.md).  
  
### <a name="to-target-the-windows-10-sdk"></a>Para direcionar o SDK do Windows 10  
  
1.  Verifique se que o SDK do Windows 10 está instalado. O SDK do Windows 10 é instalado como parte do [ferramentas para Windows 10](http://go.microsoft.com/fwlink/p/?linkid=617631).  
  
2.  Abra o menu de atalho para o nó do projeto e escolha **redirecionar SDK versão**.  
  
     ![Redirecionar a versão do SDK](../windows/media/retargetingwindowssdk1.PNG "RetargetingWindowsSDK1")  
  
     O **ações de solução de análise** caixa de diálogo é exibida.  
  
     ![Examine as ações de solução](../windows/media/retargetingwindowssdk2.PNG "RetargetingWindowsSDK2")  
  
3.  No **versão da plataforma de destino** lista suspensa, escolha a versão do SDK do Windows 10 que você deseja como destino. Escolha o botão Okey para aplicar a alteração.  
  
     Observe que 8.1 neste contexto refere-se para a versão do SDK do Windows, que também tem compatibilidade com o Windows 8, Windows Server 2012, Windows 7, Windows Server 2008 e Windows Vista.  
  
     Se essa etapa for bem-sucedida, o seguinte texto é exibido na janela de saída:  
  
     `Retargeting End: 1 completed, 0 failed, 0 skipped`  
  
4.  Abra as propriedades do projeto e no **propriedades de configuração, em geral** seção, observe os valores de **versão de plataforma de destino do Windows**. Alterando o valor tem o mesmo efeito que esse procedimento. Consulte [página de propriedade geral (projeto)](../ide/general-property-page-project.md).  
  
     ![Versão da plataforma de destino](../windows/media/retargetingwindowssdk3.PNG "RetargetingWindowsSDK3")  
  
     Esta ação altera os valores de macros de projeto que incluem caminhos para arquivos de biblioteca e arquivos de cabeçalho. Para ver o que mudou, na seção de diretórios do Visual C++ da caixa de diálogo Propriedades do projeto, escolha uma das propriedades, como os diretórios de inclusão, escolha Abrir a lista suspensa e escolha \<Editar >. O **diretórios de inclusão** caixa de diálogo é exibida.  
  
     ![Incluir a caixa de diálogo diretórios](../windows/media/retargetingwindowssdk4.PNG "RetargetingWindowsSDK4")  
  
     Escolha o **Macros >>** botão e role para baixo na lista de macros para as macros do SDK do Windows para ver os novos valores.  
  
     ![Macros SDK do Windows](../windows/media/retargetingwindowssdk5.PNG "RetargetingWindowsSDK5")  
  
5.  Repita para outros projetos, conforme necessário e, em seguida, recompile a solução.  
  
### <a name="to-target-the-windows-81-sdk"></a>Para direcionar o SDK do Windows 8.1  
  
1.  Abra o menu de atalho para o nó do projeto e escolha **redirecionar SDK versão**.  
  
2.  Na lista suspensa de versão da plataforma de destino, escolha 8.1.  
  
## <a name="see-also"></a>Consulte também  
 [Aplicativos de área de trabalho do Windows (Visual C++)](../windows/how-to-use-the-windows-10-sdk-in-a-windows-desktop-application.md)
