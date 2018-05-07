---
title: Criar declaração / definição | Microsoft Docs
ms.custom: ''
ms.date: 11/16/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
ms.assetid: 6b1cdcb2-765e-4b93-8cef-92b861f64eba
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 60d583ec47a3f9c5b61599a5945e3cfa0d375b1d
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="create-declaration--definition"></a>Criar declaração / definição
**O que:** permite gerar imediatamente da declaração ou definição de uma função.

**Quando:** têm uma função que precisa de um delcaration, ou vice-versa.  

**Motivo:** você pode criar manualmente a declaração/definição, mas isso vai criá-lo automaticamente, criar o arquivo de código do cabeçalho, se necessário.

**Como:**

1. Coloque o cursor de texto ou o mouse sobre a função para a qual você deseja criar a declaração ou definição.

   ![Código realçado](images/createdefinition_highlight.png)

1. Depois, siga um destes procedimentos:
   * **Teclado**
     * Pressione **Ctrl +.** para disparar o **ações rápidas e refatorações** menu e selecione **Criar declaração / definição** no menu de contexto.
   * **Mouse**
     * Clique com botão direito e selecione o **ações rápidas e refatorações** menu e selecione **Criar declaração / definição** no menu de contexto.

1. Declaração/definição da função será criada no arquivo de origem ou o cabeçalho, você verá em uma janela pop-up de visualização.  Se o arquivo de origem ou o cabeçalho não existir, ele também será criado e colocado no projeto.

   ![Criar declaração / definição de resultado](images/createdefinition_result.png)
