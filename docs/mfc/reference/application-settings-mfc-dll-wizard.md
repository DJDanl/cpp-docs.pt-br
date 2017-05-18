---
title: "Configurações do aplicativo, Assistente de DLL MFC | Documentos do Microsoft"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- vc.appwiz.mfc.dll.appset
dev_langs:
- C++
helpviewer_keywords:
- MFC DLL Wizard, application settings
ms.assetid: 0a96b94f-ae36-4975-951b-c9ffb3def21c
caps.latest.revision: 9
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
ms.translationtype: Machine Translation
ms.sourcegitcommit: 040985df34f2613b4e4fae29498721aef15d50cb
ms.openlocfilehash: df1e3de3e1548fe4c4c340a30127d9916998ba64
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="application-settings-mfc-dll-wizard"></a>Configurações do aplicativo, Assistente de DLL MFC
Use esta página do Assistente de DLL MFC para criar e adicionar recursos básicos para um novo projeto de DLL do MFC.  
  
## <a name="dll-type"></a>Tipo DLL  
 Selecione o tipo da DLL que você deseja criar.  
  
 **DLL normal usando compartilhado DLL do MFC**  
 Selecione esta opção para vincular a biblioteca MFC para o programa como uma DLL compartilhada. Usando essa opção, é possível compartilhar objetos MFC entre sua DLL e o aplicativo de chamada. O programa faz chamadas para a biblioteca MFC em tempo de execução. Essa opção reduz os requisitos de disco e memória do seu programa se ele é composto de vários arquivos de execução que usam a biblioteca MFC. Programas Win32 e no MFC podem chamar funções em sua DLL. Você deve redistribuir o DLL do MFC com esse tipo de projeto.  
  
 **DLL regular com MFC vinculados estaticamente**  
 Selecione esta opção para vincular seu programa estaticamente a biblioteca MFC em tempo de compilação. Programas Win32 e no MFC podem chamar funções em sua DLL. Embora essa opção aumenta o tamanho do seu programa, você não precisa redistribuir a DLL do MFC com esse tipo de projeto. Você não pode compartilhar objetos MFC entre sua DLL e o aplicativo de chamada.  
  
 **DLL de extensão do MFC**  
 Selecione esta opção se você deseja que o programa para fazer chamadas para a biblioteca MFC em tempo de execução e se você quiser compartilhar objetos MFC entre sua DLL e o aplicativo de chamada. Essa opção reduz os requisitos de disco e memória do programa, se ele é composto de vários arquivos executáveis que usam a biblioteca MFC. Somente os programas MFC podem chamar funções em sua DLL. Você deve redistribuir o DLL do MFC com esse tipo de projeto.  
  
## <a name="additional-features"></a>Recursos adicionais  
 Selecione se a DLL do MFC deve dar suporte a automação e se ele deve oferecer suporte a Windows sockets.  
  
 **Automação**  
 Selecione **automação** para permitir que seu programa manipular objetos implementados em outro programa. Selecionando **automação** também expõe seu programa para outros clientes de automação. Consulte [automação](../../mfc/automation.md) para obter mais informações.  
  
 **Soquetes do Windows**  
 Selecione esta opção para indicar que o programa oferece suporte ao Windows sockets. Soquetes do Windows permitem que você escrever programas que se comunicam através de redes TCP/IP.  
  
 Quando a DLL do MFC com o Windows sockets suporte é criado, [CWinApp::InitInstance](../../mfc/reference/cwinapp-class.md#initinstance) inicializa o suporte para soquetes e o arquivo de cabeçalho Stdafx. H do MFC inclui AfxSock.h.  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de DLL MFC](../../mfc/reference/mfc-dll-wizard.md)   
 [Criando um projeto de DLL MFC](../../mfc/reference/creating-an-mfc-dll-project.md)


