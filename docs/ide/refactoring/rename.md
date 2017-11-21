---
title: Renomear | Microsoft Docs
ms.custom: 
ms.date: 11/16/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 64b42a88-3bd9-4399-8b96-75bceffc353b
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: d8e4152a1c920a243be9d4aa23712420893e29f5
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="rename"></a>Renomear
**O que:** permite renomear identificadores para símbolos de código, como campos, variáveis locais, métodos, namespaces, propriedades e tipos.

**Quando:** você deseja renomear algo a com segurança sem a necessidade de localizar todas as instâncias e copiar/colar o novo nome.  

**Motivo:** copiando e colando o novo nome em um projeto inteiro provavelmente resultar em erros.  Essa ferramenta refatoração com precisão executará a ação de renomeação.

**Como:**

1. Realçar ou coloque o cursor do texto dentro do item a ser renomeado:

   ![Código realçado](images/rename_highlight.png)

1. Em seguida, siga um destes procedimentos:
   * **Teclado**
     * Pressione **Ctrl + R**, em seguida, **Ctrl + R**.  (Observe que o atalho de teclado pode ser diferente com base no perfil selecionado.)
   * **Mouse**
     * Selecione **Editar > Refatorar > Renomear**.
     * O código e selecione **Renomear**.

1. No **Renomear** janela pop-up, digite o novo nome para o item selecionado e clique o **visualização** botão.  Alterar o **escopo da pesquisa** se você precisar aumentar ou restringir o escopo de renomeação.

   ![Renomear a caixa de diálogo](images/rename_dialog.png)

   > [!TIP]
   > Você pode ignorar a visualização, verificando o **visualização Ignorar alterações se as referências forem confirmadas** opção.

1. Quando o **visualizar alterações - Renomear** janela aparece, certifique-se de que as alterações que você está solicitando estão sendo feitas adequadamente.  Use as caixas de seleção na parte superior da janela para habilitar ou desabilitar a renomeação de qualquer item.

   ![Renomear a visualização](images/rename_preview.png)

1. Quando tudo estiver correto, clique no **aplicar** botão e o item serão renomeados no seu código-fonte.
