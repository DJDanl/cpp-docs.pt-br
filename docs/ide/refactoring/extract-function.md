---
title: Extrair Função
ms.date: 11/16/2016
ms.assetid: e31d1249-9705-4511-acbd-9f6fe73bdf2d
ms.openlocfilehash: ec3b9a0aeaef9e418b457bafdfb9bb1bbd2edffc
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51692314"
---
# <a name="extract-function"></a>Extrair Função

**O quê:** permite transformar um fragmento de código em sua própria função.

**Quando:** você tem um fragmento de código existente em uma função que precisa ser chamado por meio de outra função.

**Por quê:** você poderia copiar/colar esse código, mas que poderia levar à eliminação de duplicação.  A melhor solução é refatorar esse fragmento em sua própria função, que pode ser chamada livremente por qualquer outra função.

**Como:**

1. realce o código a ser extraído:

   ![Código realçado](images/extractfunction_highlight.png)

1. Depois, siga um destes procedimentos:
   * **Teclado**
     * Pressione **Ctrl+R**, em seguida, **Ctrl+M**.  (Observe que o atalho de teclado pode ser diferente com base no perfil selecionado.)
     * Pressione **Ctrl +.** para disparar o menu **Ações Rápidas e Refatorações** e selecione **Extrair Função (Experimental)** no menu de contexto.
   * **Mouse**
     * Selecione **Editar > Refatorar > Extrair Função (Experimental)**.
     * Clique com o botão direito do mouse no código, selecione o menu **Ações Rápidas e Refatorações** e selecione **Extrair Função (Experimental)** no menu de contexto.
     * Clique no ícone de ![Lâmpada](images/bulb.png) exibido na margem esquerda e selecione **Extrair Função (Experimental)** no menu de contexto.

1. Na janela **Extrair Função/Método (Experimental)**, insira o novo nome da função, selecione o local em que deseja que o código seja colocado e clique no botão **OK**.

   ![Caixa de diálogo Extrair função](images/extractfunction_dialog.png)

1. A nova função será criada quando especificado, um protótipo de função no arquivo de cabeçalho correspondente, e o código original será alterado para chamar essa função.

   ![Resultado de Extrair função](images/extractfunction_result.png)
