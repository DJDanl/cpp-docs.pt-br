---
title: "/TSAWARE (criar aplicativo com reconhecimento do Terminal Server) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "/tsaware"
  - "VC.Project.VCLinkerTool.TerminalServerAware"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Opção de vinculador /TSAWARE"
  - "Terminal Server"
  - "Terminal Server, aplicativos com reconhecimento de Terminal Server"
  - "opção de vinculador TSAWARE"
  - "opção de vinculador -TSAWARE"
ms.assetid: fe1c1846-de5b-4839-b562-93fbfe36cd29
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# /TSAWARE (criar aplicativo com reconhecimento do Terminal Server)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

```  
/TSAWARE[:NO]  
```  
  
## Comentários  
 As opções definidas de \/TSAWARE um sinalizador no campo de IMAGE\_OPTIONAL\_HEADER DllCharacteristics no cabeçalho opcional da imagem do programa.  Quando esse sinalizador é definido, o servidor de terminal não fará determinadas alterações no aplicativo.  
  
 Quando um aplicativo não esteja ciente o terminal server \(também conhecido como um aplicativo herdado\), o servidor de terminal faz determinadas alterações no aplicativo herdado fazê\-lo funcionar corretamente em um ambiente multiusuário.  Por exemplo, o servidor de terminal criará uma pasta virtual do windows, de modo que cada usuário obtém uma pasta do windows em vez de obter o diretório do Windows do sistema.  Isso concede acesso de usuários a seus próprios arquivos INI.  Além disso, o servidor de terminal torna alguns ajustes o Registro para um aplicativo herdado.  Essas alterações tornam a carga do aplicativo herdado no servidor de terminal.  
  
 Se um aplicativo é o terminal server ciente, nem deve confiar em arquivos INI ou gravar no Registro de **HKEY\_CURRENT\_USER** durante a instalação.  
  
 Se você usar \/TSAWARE e seu aplicativo ainda usa arquivos INI, os arquivos serão compartilhados por todos os usuários do sistema.  Se isso for aceitável, você ainda pode vincular seu aplicativo com \/TSAWARE; se não for necessário usar \/TSAWARE:NO.  
  
 A opção \/TSAWARE é habilitada por padrão para o Windows 2000 e versões posteriores, para o windows e aplicativos do console.  Consulte [\/SUBSYSTEM](../../build/reference/subsystem-specify-subsystem.md) e [\/VERSION](../Topic/-VERSION%20\(Version%20Information\).md) para obter informações.  
  
 \/TSAWARE não é válido para drivers, VxDs, ou DLL.  
  
 Se um aplicativo tiver sido vinculado com \/TSAWARE, o DUMPBIN [\/HEADERS](../../build/reference/headers.md) exibirá informações para esse efeito.  
  
### Para definir esta opção do vinculador no ambiente de desenvolvimento do Visual Studio  
  
1.  Abra a caixa de diálogo **Páginas de Propriedade** do projeto.  Para obter detalhes, consulte [Configurando as propriedades de projeto do Visual C\+\+](../../ide/working-with-project-properties.md).  
  
2.  Clique na pasta **Vinculador**.  
  
3.  Clique na página de propriedades de **Sistema** .  
  
4.  Modifique a propriedade de **Terminal Server** .  
  
### Para definir essa opção de vinculador por meio de programação  
  
-   Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCLinkerTool.TerminalServerAware%2A>.  
  
## Consulte também  
 [Definindo opções de vinculador](../../build/reference/setting-linker-options.md)   
 [Opções de vinculador](../../build/reference/linker-options.md)   
 [Storing User\-Specific Information](http://msdn.microsoft.com/library/aa383452)   
 [Legacy Applications in a Terminal Services Environment](https://msdn.microsoft.com/en-us/library/aa382957.aspx)