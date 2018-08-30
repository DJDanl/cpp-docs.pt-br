---
title: -TSAWARE (criar aplicativo com reconhecimento do Terminal Server) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 9caf6c9a47a667b57220b6bf577080d3548e94e9
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43198544"
---
# <a name="tsaware-create-terminal-server-aware-application"></a>/TSAWARE (criar aplicativo com reconhecimento do Terminal Server)
```  
/TSAWARE[:NO]  
```  
  
## <a name="remarks"></a>Comentários  
 A opção /TSAWARE define um sinalizador no campo IMAGE_OPTIONAL_HEADER DllCharacteristics no cabeçalho opcional da imagem do programa. Quando esse sinalizador estiver definido, o servidor Host da Sessão da Área de Trabalho Remota não fará certas alterações no aplicativo.  
  
 Quando um aplicativo não é Terminal Server aware (também conhecido como um aplicativo herdado), o servidor de Terminal faz algumas modificações para o aplicativo herdado para fazê-lo funcionar corretamente em um ambiente multiusuário. Por exemplo, o Terminal Server criará uma pasta virtual do Windows, de modo que cada usuário obtém uma pasta do Windows em vez de obter o diretório do Windows do sistema. Isso fornece aos usuários acesso aos seus próprios arquivos INI. Além disso, o servidor de Terminal faz alguns ajustes para o registro para um aplicativo herdado. Essas modificações o carregamento lento do aplicativo herdado no servidor de Terminal.  
  
 Se um aplicativo está ciente do Terminal Server, ele deve contar com arquivos INI nem gravar o **HKEY_CURRENT_USER** registro durante a instalação.  
  
 Se você usar /TSAWARE e seu aplicativo ainda usa arquivos INI, os arquivos serão compartilhados por todos os usuários do sistema. Se for aceitável, você ainda pode vincular seu aplicativo com /TSAWARE; Caso contrário, você precisará usar /TSAWARE: no.  
  
 A opção /TSAWARE é habilitada por padrão para Windows e aplicativos de console. Ver [/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) e [/VERSION](../../build/reference/version-version-information.md) para obter informações.  
  
 /TSAWARE não é válido para drivers, VxDs ou DLLs.  
  
 Se um aplicativo foi vinculado com /TSAWARE, DUMPBIN [/HEADERS](../../build/reference/headers.md) exibirá informações sobre isso.  
  
### <a name="to-set-this-linker-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [configuração de propriedades do projeto Visual C++](../../ide/working-with-project-properties.md).  
  
2.  Clique o **vinculador** pasta.  
  
3.  Clique o **sistema** página de propriedades.  
  
4.  Modificar a **Terminal Server** propriedade.  
  
### <a name="to-set-this-linker-option-programmatically"></a>Para definir esta opção do vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.TerminalServerAware%2A>.  
  
## <a name="see-also"></a>Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções do vinculador](../../build/reference/linker-options.md)   
 [Armazenar informações específicas do usuário](/windows/desktop/TermServ/storing-user-specific-information)   
 [Aplicativos herdados em um ambiente de serviços de Terminal](https://msdn.microsoft.com/library/aa382957.aspx)