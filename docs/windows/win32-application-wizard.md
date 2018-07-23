---
title: Assistente de aplicativo Win32 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vc.appwiz.win32.overview
dev_langs:
- C++
helpviewer_keywords:
- Win32 Application Wizard
- Win32 Project Wizard
ms.assetid: 5d7b3a5e-8461-479a-969a-67b7883725b9
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 18885e36b5f598a8b1dd6128c29a9e520128dcb2
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33891416"
---
# <a name="win32-application-wizard"></a>Assistente de aplicativo Win32
O Assistente de aplicativo do Visual C++ Win32 permite que você crie qualquer um dos quatro tipos de projetos (listados no título na tabela abaixo). Em cada caso, você pode especificar opções adicionais que são apropriadas para o tipo de projeto que você abrir. A tabela a seguir indica quais opções estão disponíveis para cada tipo de aplicativo.  
  
|Tipo de suporte|Aplicativo de console|Aplicativo executável (Windows)|Biblioteca de vínculo dinâmico|Biblioteca estática|  
|---------------------|-------------------------|----------------------------------------|---------------------------|--------------------|  
|**Projeto vazio**|Sim|Sim|Sim|Não|  
|**Símbolos de exportação**|Não|Não|Sim|Não|  
|**Cabeçalho pré-compilado**|Não|Não|Não|Sim|  
|**Suporte ATL**|Sim|Não|Não|Não|  
|**Suporte MFC**|Sim|Não|Não|Sim|  
  
## <a name="overview"></a>Visão geral  
 Esta página do assistente descreve as configurações do projeto atual para o aplicativo do Win32 que você está criando. Por padrão, as seguintes opções estão definidas:  
  
-   O projeto é um aplicativo do Windows.  
  
-   O projeto não está vazio.  
  
-   O projeto não contém nenhum símbolo de exportação.  
  
-   O projeto não usa um arquivo de cabeçalho pré-compilado (essa opção está disponível para projetos de biblioteca estática somente).  
  
-   O projeto inclui suporte para MFC, nem ATL.  
  
 Para alterar esses padrões, clique o [configurações de aplicativo](../windows/application-settings-win-32-project-wizard.md) guia na coluna à esquerda do assistente e faça as alterações desejadas.  
  
 Depois de criar um aplicativo de área de trabalho do Windows, você pode adicionar classes genéricas de C++ usando o [genérico](../ide/generic-cpp-class-wizard.md) Assistente de código. Você pode adicionar outros itens, como arquivos HTML, arquivos de cabeçalho, recursos ou arquivos de texto.  
  
> [!NOTE]
>  Você não pode adicionar classes ATL e você pode adicionar classes MFC apenas para esses tipos de aplicativo de desktop do Windows que oferecem suporte a MFC (consulte a tabela anterior).  
  
 Você pode exibir os arquivos que o assistente cria para seu projeto no **Gerenciador de soluções**. Para obter mais informações sobre os arquivos que o assistente cria para seu projeto, consulte o arquivo de projeto gerado Leiame. txt. Para obter mais informações sobre os tipos de arquivo, [tipos de arquivo criados para projetos do Visual C++](../ide/file-types-created-for-visual-cpp-projects.md).  
  
## <a name="see-also"></a>Consulte também  
 [Criando um aplicativo de área de trabalho do Windows vazio](../windows/creating-an-empty-windows-desktop-application.md)   
 [Tipos de projeto do Visual C++](../ide/visual-cpp-project-types.md)