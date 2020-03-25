---
title: Alterar assinatura
ms.date: 11/16/2016
ms.assetid: 8daaa060-7305-4035-99d2-8b460b4f4454
ms.openlocfilehash: 1599a7900e33db61994ea75581f9d87b1aee83f9
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80171899"
---
# <a name="change-signature"></a>Alterar assinatura

**O quê:** permite modificar os parâmetros de uma função.

**Quando:** você deseja reordenar, adicionar, remover ou modificar os parâmetros de uma função que está sendo usada em uma variedade de locais.

**Por quê:** você pode alterar esses parâmetros manualmente por conta própria e, em seguida, encontrar todas as chamadas a essa função e alterá-las uma por uma, mas isso pode levar a erros.  Essa ferramenta de refatoração executará a tarefa automaticamente.

**Como:**

1. Coloque o cursor de texto ou do mouse dentro do nome do método a ser modificado, ou um de seus usos:

   ![Código realçado](images/changesignature_highlight.png)

1. Depois, siga um destes procedimentos:
   * **Teclado**
     * Pressione **Ctrl+R** e, em seguida, **Ctrl+O**.  (Observe que o atalho de teclado pode ser diferente com base no perfil selecionado.)
     * Pressione **Ctrl +.** para disparar o menu **Ações Rápidas e Refatorações** e selecione **Alterar Assinatura** no menu de contexto.
   * **Mouse**
     * Selecione **Editar > Refatorar > Reordenar Parâmetros**.
     * Clique com o botão direito do mouse no código, selecione o menu **Ações Rápidas e Refatorações** e selecione **Alterar Assinatura** no menu de contexto.

1. Na caixa de diálogo **Alterar Assinatura** que aparecer, você pode usar os botões à direita para alterar a assinatura do método:

   ![Caixa de diálogo Alterar Assinatura](images/changesignature_dialog.png)

   | Botão | DESCRIÇÃO
   | ------ | ---
   | **Para cima/baixo**    | Mova o parâmetro selecionado para cima e para baixo na lista
   | **Adicionar**        | Adicionar um novo parâmetro à lista
   | **Remover**     | Remova o parâmetro selecionado da lista
   | **Modificar**     | Modifica o parâmetro selecionado alterando seu tipo, nome e indica se ele é opcional e qual seu valor injetado
   | **Reverter**     | Restaura o parâmetro selecionado para seu estado original
   | **Reverter Tudo** | Restaura todos os parâmetros para seu estado original

   > [!TIP]
   > Use a caixa de seleção **Ignorar visualização das alterações de referência se todas as referências forem confirmadas** para fazer as alterações imediatamente sem primeiro exibir a janela de visualização.

   Ao adicionar ou modificar um parâmetro, você verá a janela **Adicionar Parâmetro** ou **Editar Parâmetro**.

   ![Adicionar/Modificar parâmetro](images/changesignature_addmodify.png)

   Aqui, você pode fazer o seguinte:

   | Entrada | DESCRIÇÃO
   | ----- | ---
   | **Tipo**               | O tipo do parâmetro (int, double, float, etc.)
   | **Nome**               | O nome do parâmetro
   | **Parâmetro Opcional** | Torna o parâmetro opcionalmente especificado
   | **Valor Injetado**     | O valor inserido em chamadas à função, em que o parâmetro não é especificado (válido somente para **Adicionar**)
   | **Valor padrão**      | O valor usado pela função se o chamador não especifica um (válido somente para **Parâmetros Opcionais**)

1. Use a lista suspensa **Escopo da Pesquisa** para selecionar se as alterações serão aplicadas ao projeto ou à solução inteira.

1. Quando tiver terminado, pressione o botão **OK** para fazer as alterações.  Verifique se as alterações que você está solicitando estão sendo feitas adequadamente.  Use as caixas de seleção na parte superior da janela para habilitar ou desabilitar a renomeação de qualquer item.

   ![Visualização de Alterar Assinatura](images/changesignature_preview.png)

1. Quando tudo estiver correto, clique no botão **Aplicar** e a função será alterada no código-fonte.

   ![Resultado de Alterar Assinatura](images/changesignature_result.png)
