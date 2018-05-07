---
title: Mover o local da definição | Microsoft Docs
ms.custom: ''
ms.date: 11/16/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
ms.assetid: c6d507ac-c61e-4da2-95c8-d504b42e2520
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 44211105429e33c136999a7877ac6ee42af29f17
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="move-definition-location"></a>Mover o local da definição
**O que:** permite mover imediatamente uma definição de função para o arquivo de cabeçalho correspondente.

**Quando:** têm uma função que você deseja mover para um arquivo de cabeçalho.  

**Motivo:** manualmente, você pode mover a função, mas esse recurso moverá automaticamente, criando o arquivo de cabeçalho, se necessário.

**Como:**

1. Coloque o cursor de texto ou o mouse sobre a função para a qual você deseja mover.

   ![Código realçado](images/movedefinition_highlight.png)

1. Depois, siga um destes procedimentos:
   * **Teclado**
     * Pressione **Ctrl +.** para disparar o **ações rápidas e refatorações** menu e selecione **mover definição local** no menu de contexto.
   * **Mouse**
     * Clique com botão direito e selecione o **ações rápidas e refatorações** menu e selecione **mover definição local** no menu de contexto.

1. A função será movida para o arquivo de cabeçalho correspondente, que você verá na janela de visualização pop-up.  Se o arquivo de cabeçalho não existir, ele também será criado e colocado no projeto.

   ![Criar declaração / definição de resultado](images/movedefinition_result.png)
