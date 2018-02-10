---
title: -TSAWARE (criar aplicativo com reconhecimento de servidor de Terminal) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- /tsaware
- VC.Project.VCLinkerTool.TerminalServerAware
dev_langs:
- C++
helpviewer_keywords:
- Terminal Server
- /TSAWARE linker option
- Terminal Server, Terminal Server-aware applications
- -TSAWARE linker option
- TSAWARE linker option
ms.assetid: fe1c1846-de5b-4839-b562-93fbfe36cd29
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2956bd2ed8aa0c36e730468a15856cecfaf7e23f
ms.sourcegitcommit: a5916b48541f804a79891ff04e246628b5f9a24a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/09/2018
---
# <a name="tsaware-create-terminal-server-aware-application"></a>/TSAWARE (criar aplicativo com reconhecimento do Terminal Server)
```  
/TSAWARE[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 A opção /TSAWARE define um sinalizador no campo DllCharacteristics IMAGE_OPTIONAL_HEADER cabeçalho opcional da imagem do programa. Quando esse sinalizador estiver definido, o servidor Host da Sessão da Área de Trabalho Remota não fará certas alterações no aplicativo.  
  
 Quando um aplicativo não é Terminal Server aware (também conhecido como um aplicativo herdado), o servidor de Terminal faz algumas modificações para o aplicativo herdado para funcionar corretamente em um ambiente multiusuário. Por exemplo, Terminal Server criará uma pasta virtual do Windows, de modo que cada usuário obtenha uma pasta do Windows em vez de obter o diretório do Windows do sistema. Isso fornece aos usuários acesso aos seus próprios arquivos INI. Além disso, o servidor de Terminal torna alguns ajustes no registro para um aplicativo herdado. Essas modificações de carregamento lento do aplicativo herdado no servidor de Terminal.  
  
 Se um aplicativo com reconhecimento do Terminal Server, ele deve se basear em arquivos INI nem gravar o **HKEY_CURRENT_USER** registro durante a instalação.  
  
 Se você usar /TSAWARE e o aplicativo use arquivos INI, os arquivos serão compartilhados por todos os usuários do sistema. Se for aceitável, você ainda pode vincular seu aplicativo com /TSAWARE; Caso contrário, você precisará usar /TSAWARE: no.  
  
 A opção /TSAWARE é habilitada por padrão para o Windows e aplicativos de console. Consulte [/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) e [/VERSION](../../build/reference/version-version-information.md) para obter informações.  
  
 /TSAWARE não é válido para drivers, VxDs ou DLLs.  
  
 Se um aplicativo foi vinculado com /TSAWARE, DUMPBIN [/HEADERS](../../build/reference/headers.md) exibirá informações para esse efeito.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração Visual C++ Project Properties](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **sistema** página de propriedades.  
  
4.  Modificar o **do Terminal Server** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.TerminalServerAware%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)   
 [Armazenar informações específicas do usuário](http://msdn.microsoft.com/library/aa383452)   
 [Aplicativos herdados em um ambiente de serviços de Terminal](https://msdn.microsoft.com/en-us/library/aa382957.aspx)