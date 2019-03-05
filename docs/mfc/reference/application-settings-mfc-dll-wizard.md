---
title: Configurações do aplicativo, Assistente de DLL MFC
ms.date: 11/04/2016
f1_keywords:
- vc.appwiz.mfc.dll.appset
helpviewer_keywords:
- MFC DLL Wizard, application settings
ms.assetid: 0a96b94f-ae36-4975-951b-c9ffb3def21c
ms.openlocfilehash: f021f2023af839413306c1e3d56dc741749cf216
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57276592"
---
# <a name="application-settings-mfc-dll-wizard"></a>Configurações do aplicativo, Assistente de DLL MFC

Use esta página do Assistente de DLL do MFC para criar e adicionar recursos básicos para um novo projeto de DLL do MFC.

## <a name="dll-type"></a>Tipo de DLL

Selecione o tipo de DLL que você deseja criar.

- **DLL MFC regular usando DLL compartilhada do MFC**

   Selecione esta opção para vincular a biblioteca do MFC para o seu programa como uma DLL compartilhada. Usando essa opção, é possível compartilhar objetos MFC entre sua DLL e o aplicativo de chamada. Seu programa faz chamadas para a biblioteca do MFC em tempo de execução. Essa opção reduz os requisitos de disco e memória do seu programa se ele é composto de vários arquivos de execução que usam a biblioteca MFC. Programas Win32 e o MFC podem chamar funções em sua DLL. Você deve redistribuir o MFC DLL com esse tipo de projeto.

- **DLL MFC regular com MFC vinculado estaticamente**

   Selecione esta opção para vincular o programa estaticamente para a biblioteca do MFC no momento da compilação. Programas Win32 e o MFC podem chamar funções em sua DLL. Embora essa opção aumenta o tamanho do seu programa, você não precisa redistribuir a DLL do MFC com esse tipo de projeto. É possível compartilhar objetos MFC entre sua DLL e o aplicativo de chamada.

- **DLL de extensão do MFC**

   Selecione esta opção se você deseja que o programa para fazer chamadas para a biblioteca do MFC em tempo de execução e se você deseja compartilhar objetos MFC entre sua DLL e o aplicativo de chamada. Essa opção reduz os requisitos de disco e memória do seu programa, se ele é composto de vários arquivos executáveis que usam a biblioteca do MFC. Somente os programas MFC podem chamar funções em sua DLL. Você deve redistribuir o MFC DLL com esse tipo de projeto.

## <a name="additional-features"></a>Recursos adicionais

Selecione se a DLL do MFC deve oferecer suporte à automação e se deve oferecer suporte a soquetes do Windows.

- **Automação**

   Selecione **automação** para permitir que seu programa manipular objetos implementados em outro programa. Selecionando **automação** também expõe seu programa para outros clientes de automação. Ver [automação](../../mfc/automation.md) para obter mais informações.

- **Soquetes do Windows**

   Selecione esta opção para indicar que seu programa oferece suporte a soquetes do Windows. Soquetes do Windows permitem que você escrever programas que se comunicam através de redes TCP/IP.

   Quando sua DLL do MFC com o Windows sockets suporte é criado, [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) inicializa o suporte para soquetes e o arquivo de cabeçalho MFC Stdafx. H inclui AfxSock.h.

## <a name="see-also"></a>Consulte também

[Assistente de DLL do MFC](../../mfc/reference/mfc-dll-wizard.md)<br/>
[Criando um projeto DLL do MFC](../../mfc/reference/creating-an-mfc-dll-project.md)
