---
title: Renomear | Microsoft Docs
ms.custom: ''
ms.date: 11/16/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
ms.assetid: 64b42a88-3bd9-4399-8b96-75bceffc353b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7a064527f6afcbf91be3fb4e51180be647c1f506
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
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

1. No **Renomear** janela pop-up, digite o novo nome para o item selecionado e clique o **visualização** botão.  Alterar o **escopo da pesquisa** se você precisar aumentar ou restringir o escopo de renomeação.

   ![Renomear a caixa de diálogo](images/rename_dialog.png)

   > [!TIP]
   > Você pode ignorar a visualização, verificando o **visualização Ignorar alterações se as referências forem confirmadas** opção.

1. Quando o **visualizar alterações - Renomear** janela aparece, certifique-se de que as alterações que você está solicitando estão sendo feitas adequadamente.  Use as caixas de seleção na parte superior da janela para habilitar ou desabilitar a renomeação de qualquer item.

   ![Renomear a visualização](images/rename_preview.png)

1. Quando tudo estiver correto, clique no **aplicar** botão e o item serão renomeados no seu código-fonte.
