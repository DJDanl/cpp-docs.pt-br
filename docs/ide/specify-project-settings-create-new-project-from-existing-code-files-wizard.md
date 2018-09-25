---
title: Especificar Configurações de Projeto, Assistente para Criar Novo Projeto com base em Arquivos de Código Existentes | Microsoft Docs
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
ms.openlocfilehash: f86361bf947a5a6117c53ce2c92c40ef1abb7117
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46387816"
---
# <a name="specify-project-settings-create-new-project-from-existing-code-files-wizard"></a>Especificar configurações do projeto, Assistente para Criar Novo Projeto de Arquivos de Código Existentes

Use esta página do Assistente para Criar Novo Projeto com base em Arquivos de Código Existentes para especificar:

- O ambiente de build para o novo projeto

- Configurações de build para corresponder a um tipo específico de novo projeto a ser gerado

## <a name="task-list"></a>Lista de Tarefas

[Como criar um projeto do C++ a partir do código existente](../ide/how-to-create-a-cpp-project-from-existing-code.md)

## <a name="uielement-list"></a>Lista UIElement

- **Usar o Visual Studio**

   Especifica o uso das ferramentas de build incluídas no Visual Studio para compilar o novo projeto. Essa opção é habilitada por padrão.

- **Tipo de Projeto**

   Especifica o tipo de projeto que será gerado pelo assistente.

- **Projeto de aplicativo do Windows**

   Indica que o assistente gerará um projeto para um aplicativo executável do Windows. Essa opção está disponível na caixa de listagem suspensa **Tipo de Projeto**.

- **Projeto de aplicativo de console**

   Indica que o assistente gerará um projeto para um aplicativo de console. Essa opção está disponível na caixa de listagem suspensa **Tipo de Projeto**.

- **Projeto de DLL (biblioteca de vínculo dinâmico)**

   Indica que o assistente gerará um projeto para um aplicativo de biblioteca de vínculo dinâmico vazio. Essa opção está disponível na caixa de listagem suspensa **Tipo de Projeto**.

- **Projeto de LIB (biblioteca estática)**

   Indica que o assistente gerará um projeto para um aplicativo de biblioteca estática. Essa opção está disponível na caixa de listagem suspensa **Tipo de Projeto**.

- **Adicionar suporte para ATL**

   Adiciona o suporte para ATL ao novo projeto.

- **Adicionar suporte para MFC**

   Adiciona o suporte para MFC ao novo projeto.

- **Adicionar suporte para o Common Language Runtime**

   Adiciona o suporte para a programação CLR ao novo projeto.

- **Common Language Runtime**

   Especifica que o novo projeto esteja em conformidade com as funcionalidades de CLR.

- **Common Language Runtime (sintaxe antiga)**

   Especifica que o novo projeto esteja em conformidade com a sintaxe do Managed Extensions for C++, que é a sintaxe de programação CLR anterior ao Visual C++ 2005.

- **Usar sistema de build externo**

   Especifica o uso das ferramentas de build não incluídas no Visual Studio para compilar o novo projeto. Quando essa opção é selecionada, você pode especificar as linhas de comando de build nas páginas **Especificar Definições de Configuração de Depuração** e **Especificar Configurações de Versão**.

   > [!NOTE]
   > Quando a opção **Usar sistema de build externo** é marcada, o IDE não compila o novo projeto e, portanto, as opções /D, /I, /FI, /AI ou /FU não são necessárias para a compilação. No entanto, essas opções precisam ser definidas corretamente para o funcionamento correto do IntelliSense.

## <a name="see-also"></a>Consulte também

[Especificar definições de configuração da depuração, Assistente para Criar Novo Projeto de Arquivos de Código Existentes](../ide/specify-debug-configuration-settings.md)<br>
[Especificar definições de configuração da versão, Assistente para Criar Novo Projeto de Arquivos de Código Existentes](../ide/specify-release-configuration.md)