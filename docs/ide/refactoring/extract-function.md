---
title: "Função Extract | Microsoft Docs"
ms.custom: 
ms.date: 11/16/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: e31d1249-9705-4511-acbd-9f6fe73bdf2d
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: dbcd323292e301857c65d908047ab14948b86573
ms.sourcegitcommit: 9239c52c05e5cd19b6a72005372179587a47a8e4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2018
---
# <a name="extract-function"></a>Função Extract
**O que:** permite transformar um fragmento de código em sua própria função.

**Quando:** tiver um fragmento de código existente em uma função que precisa ser chamado a partir de outra função.  

**Por quê:** você poderia copiar/colar esse código, mas que poderia levar à eliminação de duplicação.  É a melhor solução refatorar esse fragmento em sua própria função que pode ser chamada gratuitamente por qualquer outra função.

**Como:**

1. realce o código a ser extraído:

   ![Código realçado](images/extractfunction_highlight.png)

1. Depois, siga um destes procedimentos:
   * **Teclado**
     * Pressione **Ctrl+R**, em seguida, **Ctrl+M**.  (Observe que o atalho de teclado pode ser diferente com base no perfil selecionado.)
     * Pressione **Ctrl +.** para disparar o **ações rápidas e refatorações** menu e selecione **extrair função (Experimental)** no menu de contexto.
   * **Mouse**
     * Selecione **Editar > Refatorar > Extrair função (Experimental)**.
     * Clique com botão direito do código, selecione o **ações rápidas e refatorações** menu e selecione **extrair função (Experimental)** no menu de contexto.
     * Clique o ![Lightbulb](images/bulb.png) ícone que aparece na margem esquerda e selecione **extrair função (Experimental)** no menu de contexto.

1. No **extrair função/método (Experimental)** janela, digite o novo nome de função, selecione onde você deseja que o código seja colocado e clique no **Okey** botão.  

   ![Extrair a função de função](images/extractfunction_dialog.png)

1. A nova função será criada quando especificado, um protótipo de função no arquivo de cabeçalho correspondente, e o código original será alterado para chamar essa função.

   ![Extrair o resultado da função](images/extractfunction_result.png)