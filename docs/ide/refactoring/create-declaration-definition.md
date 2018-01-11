---
title: "Criar declaração / definição | Microsoft Docs"
ms.custom: 
ms.date: 11/16/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 6b1cdcb2-765e-4b93-8cef-92b861f64eba
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 889c8acf5e0ef0ed6a7ac90088a6188658d49d75
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="create-declaration--definition"></a>Criar declaração / definição
**O que:** permite gerar imediatamente da declaração ou definição de uma função.

**Quando:** têm uma função que precisa de um delcaration, ou vice-versa.  

**Motivo:** você pode criar manualmente a declaração/definição, mas isso vai criá-lo automaticamente, criar o arquivo de código do cabeçalho, se necessário.

**Como:**

1. Coloque o cursor de texto ou o mouse sobre a função para a qual você deseja criar a declaração ou definição.

   ![Código realçado](images/createdefinition_highlight.png)

1. Em seguida, siga um destes procedimentos:
   * **Teclado**
     * Pressione **Ctrl +.** para disparar o **ações rápidas e refatorações** menu e selecione **Criar declaração / definição** no menu de contexto.
   * **Mouse**
     * Clique com botão direito e selecione o **ações rápidas e refatorações** menu e selecione **Criar declaração / definição** no menu de contexto.

1. Declaração/definição da função será criada no arquivo de origem ou o cabeçalho, você verá em uma janela pop-up de visualização.  Se o arquivo de origem ou o cabeçalho não existir, ele também será criado e colocado no projeto.

   ![Criar declaração / definição de resultado](images/createdefinition_result.png)
