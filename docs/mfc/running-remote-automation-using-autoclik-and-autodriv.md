---
title: "Executando automa&#231;&#227;o remota usando AUTOCLIK e AUTODRIV | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Exemplo de AUTOCLIK [MFC]"
ms.assetid: 8900c0de-8dba-4f0a-8d9e-7db77a1f4f46
caps.latest.revision: 10
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Executando automa&#231;&#227;o remota usando AUTOCLIK e AUTODRIV
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

AUTOCLIK é um aplicativo de exemplo simples do servidor de automação que você pode usar como uma base da qual obter mais informações sobre a automação remoto.  AUTODRIV é um aplicativo cliente simples de automação que as unidades AUTOCLIK.  Você pode usá\-los para demonstrar a automação remoto.  
  
#### Para instalar AUTOCLIK.EXE em dois computadores e levá\-lo que usa a automação remoto  
  
1.  Instalar o aplicativo de exemplo de [AUTOCLIK](../top/visual-cpp-samples.md) no computador de desenvolvimento.  
  
2.  Criar AUTOCLIK.EXE.  
  
3.  Executar AUTOCLIK.EXE na forma autônoma e feche\-o em para baixo.  Isso registrar\-o\-&z como um servidor de automação.  
  
4.  Copiar AUTOCLIK.EXE a um computador remoto, executá\-lo lá, e feche\-o em para baixo.  
  
5.  Executar AUTODRIV.EXE no computador local e verifique se inicie o executando AUTOCLIK.EXE.  Para saber mais sobre AUTODRIV.EXE, consulte [AUTOCLIK](../top/visual-cpp-samples.md).  
  
6.  No computador remoto, inicie AUTMGR32.EXE \(gerenciador de automação\).  
  
7.  No computador remoto, inicie RACMGR32.EXE \(gerenciador de conexões de automação remoto\).  
  
8.  No gerenciador de conexões remoto de automação, AutoClik.Document selecione na lista de **OLE Classes** .  
  
9. Escolha uma política de segurança do sistema da guia de **Acesso para cliente** para conceder acesso de cliente a AutoClik.Document.  
  
10. No computador local, inicie o RACMGR32.EXE e selecione AutoClik.Document de **OLE Classes** lista.  
  
11. Na guia de **Conexão do Servidor** , escolha o endereço de rede do computador remoto e o protocolo de rede apropriado.  
  
12. Com o AutoClik.Document ainda selecionado na caixa de listagem de **OLE Classes** , escolha o comando de **Remoto** no menu de `Register` .  
  
13. No computador local, AUTODRIV.EXE na execução ou no projeto do Visual Basic equivalente AUTOCLIK.MAK se você quer ter o Visual Basic, em vez de um MFC, o cliente.  
  
 No computador remoto, agora você deve ver AUTOCLIK que executa comandos iniciado de cliente local.  
  
## Consulte também  
 [Automação remota](../mfc/remote-automation.md)