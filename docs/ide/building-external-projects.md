---
title: Compilando projetos externos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- external projects
- Visual C++ projects, external projects
- builds [C++], external projects
- projects [C++], external projects
- Makefile projects, external projects
ms.assetid: 650b7803-ea91-489d-bee3-8f3e990e223c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 97b6aa1e5939afe55644df6529bf75ba043f20bb
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33330340"
---
# <a name="building-external-projects"></a>Compilando projetos externos
Um projeto externo é um projeto do Visual C++ que usa um makefile ou outros recursos que estão fora (externos) do ambiente de desenvolvimento do Visual C++.  
  
 Caso você tenha um projeto externo (por exemplo, um projeto makefile) que deseja compilar no ambiente de desenvolvimento do Visual C++, crie um projeto Makefile e especifique o comando e a saída de build do projeto no Assistente de Aplicativo Makefile. Para obter mais informações, confira [Criando um projeto makefile](../ide/creating-a-makefile-project.md).  
  
 Observe que o Visual C++ não dá mais suporte à capacidade de exportar um makefile para o projeto ativo no ambiente de desenvolvimento. Use as [Opções de linha de comando Devenv](/visualstudio/ide/reference/devenv-command-line-switches) para compilar projetos do Visual Studio na linha de comando.  
  
## <a name="see-also"></a>Consulte também  
 [Compilando projetos do C++ no Visual Studio](../ide/building-cpp-projects-in-visual-studio.md)