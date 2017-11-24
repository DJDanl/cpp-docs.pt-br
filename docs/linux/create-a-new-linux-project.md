---
title: Criar um novo projeto do C++ Linux no Visual Studio | Microsoft Docs
ms.custom: 
ms.date: 11/15/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-linux
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 5d7c1d67-bc31-4f96-8622-2b4cf91372fd
author: corob-msft
ms.author: corob
manager: ghogen
ms.openlocfilehash: 31309f961b392cb7548c3114e1af8604ac872cf3
ms.sourcegitcommit: 1b480aa74886930b3bd0435d71cfcc3ccda36424
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2017
---
# <a name="create-a-new-linux-project"></a>Criar um novo projeto do Linux
Ao codificar para Linux, você tem a opção de criar um projeto do Visual Studio ou um projeto do CMake. Este tópico descreve como criar um projeto do Visual Studio. Para obter mais informações sobre projetos do CMake, consulte [Configurar um projeto do CMake Linux ](cmake-linux-project.md).

Para criar um novo projeto do Linux no Visual Studio, faça o seguinte:

1. Selecione **Arquivo > Novo Projeto** no Visual Studio ou pressione **Ctrl + Shift + N**.
1. Selecione o nó **Visual C++ > Multiplataforma > Linux**, em seguida, selecione o tipo de projeto que você deseja criar, insira um Nome/Local e clique em OK.

   ![Novo projeto do Linux](media/newproject.png)

   | Tipo de Projeto | Descrição
   | ------------ | ---
   | **Intermitência (Raspberry)**           | Projeto direcionado a um dispositivo Raspberry Pi com o código de exemplo gravado para piscar um LED
   | **Aplicativo de console (Linux)** | Projeto direcionado a qualquer computador Linux com o código de exemplo gravado no texto de saída do console
   | **Projeto vazio (Linux)**       | Projeto direcionado a qualquer computador Linux sem nenhum código de exemplo gravado
   | **Projeto Makefile (Linux)**    | Projeto direcionado a qualquer computador Linux que será compilado usando um sistema de build do Makefile padrão

