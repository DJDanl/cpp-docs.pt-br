---
title: Renomear
ms.date: 11/16/2016
ms.assetid: 64b42a88-3bd9-4399-8b96-75bceffc353b
ms.openlocfilehash: a747784f46341f130d1271fd0f15475b63d7b6d8
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51692535"
---
# <a name="rename"></a>Renomear

**O quê:** permite renomear identificadores para símbolos de código, como campos, variáveis locais, métodos, namespaces, propriedades e tipos.

**Quando:** você deseja renomear algo com segurança sem a necessidade de localizar todas as instâncias e copiar/colar o novo nome.

**Por quê:** copiar e colar o novo nome em um projeto inteiro provavelmente resultaria em erros.  Essa ferramenta de refatoração realizará com precisão a ação de renomeação.

**Como:**

1. realce ou coloque o cursor do texto dentro do item a ser renomeado:

   ![Código realçado](images/rename_highlight.png)

1. Depois, siga um destes procedimentos:
   * **Teclado**
     * Pressione **Ctrl+R**, em seguida, **Ctrl+R**.  (Observe que o atalho de teclado pode ser diferente com base no perfil selecionado.)
   * **Mouse**
     * Selecione **Editar > Refatorar > Renomear**.
     * Clique com o botão direito do mouse no código e selecione **Renomear**.

1. Na janela **Renomear** exibida, insira o novo nome do item selecionado e clique no botão **Visualização**.  Altere o **Escopo da pesquisa** se precisar ampliar ou restringir o escopo da renomeação.

   ![Caixa de diálogo Renomear](images/rename_dialog.png)

   > [!TIP]
   > Ignore a visualização marcando a opção **Ignorar alterações de visualização se as referências forem confirmadas**.

1. Quando a janela **Visualizar Alterações – Renomear** for exibida, verifique se as alterações solicitadas estão sendo feitas corretamente.  Use as caixas de seleção na parte superior da janela para habilitar ou desabilitar a renomeação de qualquer item.

   ![Visualização da renomeação](images/rename_preview.png)

1. Quando tudo estiver correto, clique no botão **Aplicar** e o item será renomeado no código-fonte.
