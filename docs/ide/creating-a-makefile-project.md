---
title: Criando um projeto Makefile | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: vc.appwiz.makefile.project
dev_langs: C++
helpviewer_keywords:
- Makefile projects, creating
- project files [C++], Makefile projects
ms.assetid: dd077af3-97a8-48fb-baaa-cf7e07ddef61
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5e86bedbf83cd417cfc41317e5887304cda7ee76
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="creating-a-makefile-project"></a>Criando um projeto de makefile
Se você tiver um projeto compilado na linha de comando com um makefile, o ambiente de desenvolvimento do Visual Studio não reconhecerá seu projeto. Para abrir e criar seu projeto usando [!INCLUDE[vsUltShort](../ide/includes/vsultshort_md.md)], Visual Studio Professional ou Visual Studio Express para Windows Desktop, primeiro crie um projeto vazio, selecionando o modelo de projeto MakeFile. Você pode usar esse projeto para compilar seu projeto no ambiente de desenvolvimento do Visual Studio.  
  
 O projeto não mostra arquivos no Gerenciador de Soluções. O projeto especifica as configurações de compilação, que são refletidas na página de propriedades do projeto.  
  
 O arquivo de saída que você especifica no projeto não tem efeito no nome que o script de compilação gera; ele declara apenas uma intenção.  
  
### <a name="to-create-a-makefile-project"></a>Para criar um projeto Makefile  
  
1.  Siga as instruções no tópico da Ajuda [criando um projeto com um Assistente de aplicativo do Visual C++](../ide/creating-desktop-projects-by-using-application-wizards.md).  
  
2.  No **novo projeto** caixa de diálogo, selecione **projeto Makefile** no painel de modelos para abrir o assistente.  
  
3.  No [configurações de aplicativo](../ide/application-settings-makefile-project-wizard.md) página, fornece um comando, saída, limpar e recriar as informações.  
  
4.  Clique em **concluir** para fechar o assistente e abra o projeto recém-criado no **Gerenciador de soluções**.  
  
 Você pode ver e editar as propriedades do projeto em sua página de propriedades. Consulte [configuração Visual C++ Project Properties](../ide/working-with-project-properties.md) para obter informações sobre como exibir a página de propriedades.  
  
## <a name="see-also"></a>Consulte também  
 [Assistente de projeto makefile](../ide/makefile-project-wizard.md)   
 [Caracteres especiais em um Makefile](../build/special-characters-in-a-makefile.md)   
 [Conteúdo de um makefile](../build/contents-of-a-makefile.md)