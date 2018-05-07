---
title: Especificar configurações do projeto, criar o novo projeto de Assistente de arquivos de código existentes | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
f1_keywords:
- vc.appwiz.importwiz.appsettings
dev_langs:
- C++
helpviewer_keywords:
- Create New Project From Existing Code Files Wizard, project settings
ms.assetid: 9b8860c9-d35f-4f18-9565-2934d3d7f569
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f0f59b802b5a24c1b449f78cccee4744538a5a0e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="specify-project-settings-create-new-project-from-existing-code-files-wizard"></a>Especificar configurações do projeto, Assistente para Criar Novo Projeto de Arquivos de Código Existentes
Use esta página do Assistente para criar novo projeto de arquivos de código existentes para especificar:  
  
-   O ambiente de compilação para o novo projeto  
  
-   Criar configurações para que correspondam a um tipo específico de novo projeto para gerar  
  
## <a name="task-list"></a>Lista de Tarefas  
 [Como criar um projeto do C++ a partir do código existente](../ide/how-to-create-a-cpp-project-from-existing-code.md)  
  
## <a name="uielement-list"></a>Lista UIElement  
 **Use o Visual Studio**  
 Especifica para usar as ferramentas de compilação são incluídas no Visual Studio para criar o novo projeto. Essa opção é habilitada por padrão.  
  
 **Tipo de projeto**  
 Especifica o tipo de projeto que o assistente irá gerar.  
  
 **Projeto de aplicativo do Windows**  
 Indica que o assistente irá gerar um projeto para um aplicativo executável do Windows. Essa opção está disponível na **tipo de projeto** caixa de listagem suspensa.  
  
 **Projeto de aplicativo de console**  
 Indica que o assistente irá gerar um projeto para um aplicativo de console. Essa opção está disponível na **tipo de projeto** caixa de listagem suspensa.  
  
 **Projeto de biblioteca de vínculos dinâmicos (DLL)**  
 Indica que o assistente irá gerar um projeto para um aplicativo de biblioteca de vínculo dinâmico vazio. Essa opção está disponível na **tipo de projeto** caixa de listagem suspensa.  
  
 **Projeto de biblioteca estática (LIB)**  
 Indica que o assistente irá gerar um projeto para um aplicativo de biblioteca estática. Essa opção está disponível na **tipo de projeto** caixa de listagem suspensa.  
  
 **Adicionar suporte ATL**  
 Adiciona o suporte ATL ao novo projeto.  
  
 **Adicionar suporte para MFC**  
 Adiciona o suporte do MFC para o novo projeto.  
  
 **Adicionar suporte a Common Language Runtime**  
 Adiciona suporte para o novo projeto de programação de CLR.  
  
 **Common Language Runtime**  
 Especifica o novo projeto para ser compatível com recursos de CLR.  
  
 **Common Language Runtime (sintaxe antiga)**  
 Especifica o novo projeto para ser compatível com extensões gerenciadas para obter a sintaxe de C++, o que é a sintaxe de programação CLR antes do Visual C++ 2005.  
  
 **Use o sistema de compilação externo**  
 Especifica o uso de ferramentas de compilação que não estão incluídas no Visual Studio para criar o novo projeto. Quando essa opção é selecionada, você pode especificar as linhas de comando de compilação no **especificar configurações de depuração** e **especificar configurações de versão** páginas.  
  
> [!NOTE]
>  Quando o **sistema de compilação externo Use** opção estiver marcada, o IDE não cria o novo projeto, portanto, o /D, I, /FI, /AI ou /FU opções não são necessárias para a compilação. No entanto, essas opções devem ser definidas corretamente para que o IntelliSense funcione corretamente.  
  
## <a name="see-also"></a>Consulte também  
 [Especificar configurações de depuração, criar novo projeto de Assistente de arquivos de código existentes](../ide/specify-debug-configuration-settings.md)   
 [Especificar definições de configuração da versão, Assistente para Criar Novo Projeto de Arquivos de Código Existentes](../ide/specify-release-configuration.md)