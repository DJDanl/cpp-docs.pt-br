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
ms.openlocfilehash: 9f3bd3c7019c98f1be163ee31264b9fef0c52ac5
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="building-external-projects"></a>Compilando projetos externos
Um projeto externo é um projeto do Visual C++ que usa um makefile ou outros recursos que estão fora (externa ou externa) o ambiente de desenvolvimento do Visual C++.  
  
 Se você tiver um projeto externo (por exemplo, um projeto makefile) que você deseja compilar no ambiente de desenvolvimento do Visual C++, crie um projeto Makefile e especifique seu projeto de compilação comando e saída no Assistente do aplicativo Makefile. Para obter mais informações, consulte [criando um projeto Makefile](../ide/creating-a-makefile-project.md).  
  
 Observe que o Visual C++ não suporta a capacidade de exportar um makefile para o projeto ativo no ambiente de desenvolvimento. Use [opções de linha de comando Devenv](/visualstudio/ide/reference/devenv-command-line-switches) para compilar projetos do Visual Studio na linha de comando.  
  
## <a name="see-also"></a>Consulte também  
 [Compilando projetos do C++ no Visual Studio](../ide/building-cpp-projects-in-visual-studio.md)