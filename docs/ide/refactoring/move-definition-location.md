---
title: "Mover o local da definição | Microsoft Docs"
ms.custom: 
ms.date: 11/16/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: c6d507ac-c61e-4da2-95c8-d504b42e2520
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: cb2d07ab7d7434bdf06ddb8f004881289492882a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="move-definition-location"></a>Mover o local da definição
**O que:** permite mover imediatamente uma definição de função para o arquivo de cabeçalho correspondente.

**Quando:** têm uma função que você deseja mover para um arquivo de cabeçalho.  

**Motivo:** manualmente, você pode mover a função, mas esse recurso moverá automaticamente, criando o arquivo de cabeçalho, se necessário.

**Como:**

1. Coloque o cursor de texto ou o mouse sobre a função para a qual você deseja mover.

   ![Código realçado](images/movedefinition_highlight.png)

1. Em seguida, siga um destes procedimentos:
   * **Teclado**
     * Pressione **Ctrl +.** para disparar o **ações rápidas e refatorações** menu e selecione **mover definição local** no menu de contexto.
   * **Mouse**
     * Clique com botão direito e selecione o **ações rápidas e refatorações** menu e selecione **mover definição local** no menu de contexto.

1. A função será movida para o arquivo de cabeçalho correspondente, que você verá na janela de visualização pop-up.  Se o arquivo de cabeçalho não existir, ele também será criado e colocado no projeto.

   ![Criar declaração / definição de resultado](images/movedefinition_result.png)
