---
title: 'Como: criar aplicativos do Console CLR (C + + CLI) | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- console applications, templates
- CLR console applications, project template
ms.assetid: e89bce3c-706f-4ae0-8a90-cb1a0f674e70
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- dotnet
ms.openlocfilehash: ccb46ca7cd9cb7e1999a0be684eccf712006618e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="how-to-create-clr-console-applications-ccli"></a>Como criar aplicativos do console CLR (C++/CLI)
Você pode usar o modelo de aplicativo de Console para criar um projeto de aplicativo de console que já tenha arquivos e referências ao projeto essencial.  
  
 Normalmente, um aplicativo de console é compilado em um arquivo executável autônomo, mas não tem uma interface gráfica do usuário. Um usuário executa o aplicativo de console em um prompt de comando e usa o prompt de comando para instruções de problema para o aplicativo em execução. Também no prompt de comando, o aplicativo fornece informações de saída. A urgência de um aplicativo de console, é uma ótima maneira de aprender técnicas de programação sem precisar se preocupar para implementar uma interface do usuário.  
  
 Quando você usa o modelo de aplicativo de Console para criar um projeto, ele adiciona automaticamente essas referências e arquivos:  
  
-   Referências a esses namespaces do .NET Framework:  
  
    -   [Sistema](https://msdn.microsoft.com/en-us/library/system.appdomainmanager.appdomainmanager.aspx)— contém as classes fundamentais e classes base que definem comumente usados valores e tipos de dados de referência, eventos e manipuladores de eventos, interfaces, atributos e exceções de processamento.  
  
    -   mscorlib — o assembly DLL que dá suporte ao desenvolvimento do .NET Framework.  
  
-   Arquivos de origem:  
  
    -   Console (arquivo. cpp) — o ponto de entrada e de arquivo fonte principal no aplicativo que você acabou de criar. Identifica o arquivo. dll de projeto e o namespace do projeto. Fornece seu próprio código nesse arquivo.  
  
    -   Atributos de AssemblyInfo.cpp—Contains, arquivos, recursos, tipos, informações de controle de versão, as informações de assinatura e assim por diante que você pode usar para modificar metadados de assembly do projeto. Para obter mais informações, consulte [conteúdo de um Assembly](/dotnet/framework/app-domains/assembly-contents).  
  
    -   Stdafx.cpp—Used para criar um arquivo de cabeçalho pré-compilado chamado Win32.pch e um arquivo de tipos precompilados chamado StdAfx.obj.  
  
-   Arquivos de cabeçalho:  
  
    -   Stdafx.h—Used para criar um arquivo de cabeçalho pré-compilado chamado Win32.pch e um arquivo de tipos precompilados chamado StdAfx.obj.  
  
    -   Resource.h—A gerado incluir arquivo para app.rc.  
  
-   Arquivos de recurso:  
  
    -   arquivo de script de recurso de App.rc—the de um programa.  
  
    -   arquivo de ícone App.ico—the de um programa.  
  
-   ReadMe.txt—Describes os arquivos no projeto.  
  
## <a name="to-create-a-common-language-runtime-clr-console-app-project"></a>Para criar um projeto de aplicativo de console do common language runtime (CLR)  
  
1.  Na barra de menus, escolha **Arquivo**, **Novo**, **Projeto**.  
  
2.  No **novo projeto** caixa de diálogo **modelos instalados**, selecione o **Visual C++** nó, selecione o **CLR** nó e selecione o modelo de aplicativo de Console.  
  
3.  No **nome** , digite um nome exclusivo para seu aplicativo.  
  
     Você pode especificar outras configurações de projeto e solução, mas eles não são necessários.  
  
4.  Escolha o botão **OK**.  
  
## <a name="see-also"></a>Consulte também  
 [Projetos CLR](../ide/files-created-for-clr-projects.md)   


