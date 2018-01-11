---
title: "Executando automação remota usando AUTOCLIK e AUTODRIV | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: AUTOCLIK sample [MFC]
ms.assetid: 8900c0de-8dba-4f0a-8d9e-7db77a1f4f46
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 791655047eaf07732e1e006e8cc3ea8e7dec4727
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="running-remote-automation-using-autoclik-and-autodriv"></a>Executando automação remota usando AUTOCLIK e AUTODRIV
AUTOCLIK é um simple aplicativo de exemplo de servidor de automação que você pode usar como base da qual obter mais informações sobre a automação remota. AUTODRIV é um aplicativo de cliente de automação simple que unidades AUTOCLIK. Você pode usá-los para demonstrar a automação remota.  
  
#### <a name="to-install-autoclikexe-on-two-machines-and-drive-it-using-remote-automation"></a>Para instalar o AUTOCLIK. EXE em dois computadores e unidade usando a automação remota  
  
1.  Instalar o [AUTOCLIK](../visual-cpp-samples.md) exemplo de aplicativo em sua máquina de desenvolvimento.  
  
2.  Crie AUTOCLIK. EXE.  
  
3.  Execute AUTOCLIK. EXE no autônomo modo e desligá-lo. Isso irá registrá-lo como um servidor de automação.  
  
4.  Copie AUTOCLIK. EXE para um computador remoto, executá-lo lá e desligá-lo.  
  
5.  Execute AUTODRIV. EXE no local do computador e verifique se que em execução, ele inicia AUTOCLIK. EXE. Para saber mais sobre AUTODRIV. EXE, consulte [AUTOCLIK](../visual-cpp-samples.md).  
  
6.  No computador remoto, inicie o AUTMGR32. EXE (Gerenciador de automação).  
  
7.  No computador remoto, inicie o RACMGR32. EXE (Gerenciador de Conexão de automação remota).  
  
8.  No Gerenciador de Conexão de automação remota, selecione AutoClik.Document do **Classes OLE** lista.  
  
9. Escolha uma política de segurança do sistema o **acesso para cliente** tab para conceder acesso de cliente a AutoClik.Document.  
  
10. No computador local, inicie RACMGR32. EXE e selecione AutoClik.Document do **Classes OLE** lista.  
  
11. Do **Conexão de servidor** guia, selecione o endereço de rede do computador remoto e o protocolo de rede apropriado.  
  
12. Com AutoClik.Document ainda selecionada no **Classes OLE** caixa de listagem, escolha o **remoto** comando o `Register` menu.  
  
13. No computador local, execute AUTODRIV. EXE ou o AUTOCLIK equivalente. Projeto MAK Visual Basic, se você deseja ter um Visual Basic, em vez de um MFC, cliente.  
  
 No computador remoto, agora você deve ser capaz de ver AUTOCLIK executando comandos iniciados do cliente local.  
  
## <a name="see-also"></a>Consulte também  
 [Automação remota](../mfc/remote-automation.md)

