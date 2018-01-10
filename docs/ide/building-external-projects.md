---
title: Compilando projetos externos | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- external projects
- Visual C++ projects, external projects
- builds [C++], external projects
- projects [C++], external projects
- Makefile projects, external projects
ms.assetid: 650b7803-ea91-489d-bee3-8f3e990e223c
caps.latest.revision: "6"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 16b73349a220f392730dd5526fd5f3d59e59754d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="building-external-projects"></a>Compilando projetos externos
Um projeto externo é um projeto do Visual C++ que usa um makefile ou outros recursos que estão fora (externa ou externa) o ambiente de desenvolvimento do Visual C++.  
  
 Se você tiver um projeto externo (por exemplo, um projeto makefile) que você deseja compilar no ambiente de desenvolvimento do Visual C++, crie um projeto Makefile e especifique seu projeto de compilação comando e saída no Assistente do aplicativo Makefile. Para obter mais informações, consulte [criando um projeto Makefile](../ide/creating-a-makefile-project.md).  
  
 Observe que o Visual C++ não suporta a capacidade de exportar um makefile para o projeto ativo no ambiente de desenvolvimento. Use [opções de linha de comando Devenv](/visualstudio/ide/reference/devenv-command-line-switches) para compilar projetos do Visual Studio na linha de comando.  
  
## <a name="see-also"></a>Consulte também  
 [Compilando projetos do C++ no Visual Studio](../ide/building-cpp-projects-in-visual-studio.md)