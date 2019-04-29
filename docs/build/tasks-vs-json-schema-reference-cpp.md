---
title: Referência de esquema Tasks.vs.json (C++)
ms.date: 02/11/2019
helpviewer_keywords:
- Open Folder Projects in Visual C++
ms.assetid: abd1985e-3717-4338-9e80-869db5435175
ms.openlocfilehash: d0f62f6cddf3701da391880532bd2f554cc19130
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62315047"
---
# <a name="tasksvsjson-c"></a>Tasks.vs.json (C++)

Um arquivo `tasks.vs.json` pode ser adicionado a um projeto Open Folder para definir qualquer tarefa arbitrária e então invocar o menu de contexto **Gerenciador de Soluções**. Projetos CMake normalmente não usam este arquivo porque todos os comandos de build são especificados em `CMakeLists.txt`. Para sistemas de build diferentes do CMake, esse é o local em que você pode especificar seus comandos de build e invocar scripts de build. Para obter informações gerais sobre como usar tasks.vs.json, confira [Personalizar o build e depurar tarefas para desenvolvimento "Open Folder"](/visualstudio/ide/customize-build-and-debug-tasks-in-visual-studio).

