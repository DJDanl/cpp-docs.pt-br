---
title: Criar Declaração/Definição
ms.date: 10/19/2018
ms.assetid: 6b1cdcb2-765e-4b93-8cef-92b861f64eba
ms.openlocfilehash: 59ae3ebc23303554a35eea17c7e28850a4a1499a
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51693120"
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
