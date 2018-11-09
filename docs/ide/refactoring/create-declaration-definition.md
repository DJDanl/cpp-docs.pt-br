---
title: Criar Declaração/Definição
ms.date: 10/19/2018
ms.assetid: 6b1cdcb2-765e-4b93-8cef-92b861f64eba
ms.openlocfilehash: 56f15ba040314b07450dc8730a913a18361e092f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50456960"
---
# <a name="create-declaration--definition"></a>Criar Declaração/Definição
**O quê:** permite gerar imediatamente a declaração ou a definição de uma função.

**Quando:** você tem uma função que precisa de uma declaração ou vice-versa.

**Por quê:** você pode criar a declaração/definição manualmente, mas isso vai criá-la automaticamente, criando o arquivo de código/cabeçalho, se necessário.

**Como:**

1. Coloque o cursor de texto ou do mouse sobre a função para a qual você deseja criar a declaração ou a definição.

   ![Código realçado](images/createdefinition_highlight.png)

1. Depois, siga um destes procedimentos:
   * **Teclado**
     * Pressione **Ctrl +.** para disparar o menu **Ações Rápidas e Refatorações** e selecione **Criar Declaração/Definição** no menu de contexto.
   * **Mouse**
     * Clique com o botão direito do mouse, selecione o menu **Ações Rápidas e Refatorações** e selecione **Criar Declaração/Definição** no menu de contexto.

1. A declaração/definição da função será criada no arquivo de origem ou de cabeçalho, que você verá em uma janela pop-up de visualização.  Caso o arquivo de origem ou de cabeçalho não exista, ele também será criado e colocado no projeto.

   ![Resultado de Criar Declaração/Definição](images/createdefinition_result.png)
