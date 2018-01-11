---
title: Alterar assinatura | Microsoft Docs
ms.custom: 
ms.date: 11/16/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 8daaa060-7305-4035-99d2-8b460b4f4454
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5280b4940c2a52fc6e72b397300040ca4c1ac92e
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="change-signature"></a>Alterar assinatura
**O que:** permite que você modifique os parâmetros da função.

**Quando:** você deseja reordenar, adicionar, remover ou modificar os parâmetros da função que está sendo usado em uma variedade de locais.  

**Motivo:** você pode manualmente alterar esses parâmetros e, em seguida, localizar todas as chamadas para essa função e alterá-los um por um, mas que poderiam levar a erros.  Essa ferramenta refatoração executará a tarefa automaticamente.

**Como:**

1. Posicione o cursor do mouse ou texto dentro do nome do método para modificar, ou um de seus usos:

   ![Código realçado](images/changesignature_highlight.png)

1. Em seguida, siga um destes procedimentos:
   * **Teclado**
     * Pressione **Ctrl + R**, em seguida, **Ctrl + O**.  (Observe que o atalho de teclado pode ser diferente com base no perfil selecionado.)
     * Pressione **Ctrl +.** para disparar o **ações rápidas e refatorações** menu e selecione **alterar assinatura** no menu de contexto.
   * **Mouse**
     * Selecione **Editar > Refatorar > reordenar parâmetros**.
     * Clique com botão direito do código, selecione o **ações rápidas e refatorações** menu e selecione **alterar assinatura** no menu de contexto.

1. No **alterar assinatura** caixa de diálogo que aparecer, você pode usar os botões à direita para alterar a assinatura do método:

   ![Caixa de diálogo Alterar assinatura](images/changesignature_dialog.png)

   | Botão | Descrição
   | ------ | ---
   | **Para cima/baixo**    | Mova o parâmetro selecionado para cima e lista
   | **Adicionar**        | Adicionar um novo parâmetro à lista
   | **Removerr**     | Remova o parâmetro selecionado da lista
   | **Modificar**     | Modifique o parâmetro selecionado alterando seu tipo, nome e se ele é opcional, e que seu valor injetado seriam
   | **Reverter**     | Restaurar o parâmetro selecionado em seu estado original
   | **Reverta todas** | Restaurar todos os parâmetros para seu estado original

   > [!TIP]
   > Use o **de referência de visualização ignorar altera se todas as referências forem confirmadas** caixa de seleção para tornar as alterações imediatamente sem a janela de visualização estão aparecendo primeiro.

   Ao adicionar ou modificar um parâmetro, você verá o **Adicionar parâmetro** ou **Editar parâmetro** janela.

   ![Adicionar/modificar o parâmetro](images/changesignature_addmodify.png)

   Aqui, você pode fazer o seguinte:

   | Entrada | Descrição
   | ----- | ---
   | **Tipo**               | O tipo do parâmetro (int, clique duas vezes, float, etc.)
   | **Nome**               | O nome do parâmetro
   | **Parâmetro opcional** | Faz com que o parâmetro opcionalmente especificado
   | **Valor injetado**     | O valor inserido em qualquer chamada para a função em que o parâmetro não for especificado (válido somente para **adicionar**)
   | **Valor padrão**      | O valor usado pela função se o chamador não especificar uma (válido somente para **parâmetros opcionais**)

1. Use o **escopo da pesquisa** lista suspensa para selecionar se as alterações serão aplicadas para o projeto ou solução inteira.

1. Quando tiver terminado, pressione a **Okey** botão para fazer as alterações.  Certifique-se de que as alterações que você está solicitando estão sendo feitas adequadamente.  Use as caixas de seleção na parte superior da janela para habilitar ou desabilitar a renomeação de qualquer item.

   ![Alterar a visualização de assinatura](images/changesignature_preview.png)

1. Quando tudo estiver correto, clique no **aplicar** botão e a função serão alterados em seu código-fonte.

   ![Alterar o resultado de assinatura](images/changesignature_result.png)