---
title: Criar um novo projeto do C++ Linux no Visual Studio | Microsoft Docs
ms.custom: ''
ms.date: 07/20/2018
ms.technology:
- cpp-linux
ms.tgt_pltfrm: Linux
ms.topic: conceptual
ms.assetid: 5d7c1d67-bc31-4f96-8622-2b4cf91372fd
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
- linux
ms.openlocfilehash: f64f8eaf09e92df3dd776180db5904af039d6ad7
ms.sourcegitcommit: 7eadb968405bcb92ffa505e3ad8ac73483e59685
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/23/2018
ms.locfileid: "39207964"
---
# <a name="create-a-new-linux-project"></a>Criar um novo projeto do Linux
Ao codificar C++ em Visual Studio para Linux, você tem a opção de criar um projeto do Visual Studio ou um projeto do CMake. Este tópico descreve como criar um projeto do Visual Studio. Para obter mais informações sobre projetos do CMake, consulte [Configurar um projeto do CMake Linux ](cmake-linux-project.md).

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

