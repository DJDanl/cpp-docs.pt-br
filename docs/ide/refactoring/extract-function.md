---
title: Extrair Função | Microsoft Docs
ms.custom: ''
ms.date: 11/16/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
ms.assetid: e31d1249-9705-4511-acbd-9f6fe73bdf2d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: e032c2f1579294431b01d5a7695bf2c8a35aa421
ms.sourcegitcommit: 072e12d6b7a242765bdcc9afe4a14a284ade01fc
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/26/2018
ms.locfileid: "50136114"
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
