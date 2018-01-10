---
title: Implementar virtuais puros | Microsoft Docs
ms.custom: 
ms.date: 11/16/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: ea9b4719-34a3-474a-b4ec-05b1859f80f1
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: f311c2e5832754bfd785084b9aa930b5dbe43845
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="implement-pure-virtuals"></a>Implementar virtuais puros
**O que:** permite gerar imediatamente o código necessário para implementar todos os métodos virtual puros em uma classe. 

**Quando:** você deseja herdar de uma classe com funções virtuais puras.  

**Motivo:** pode implementar manualmente funções virtuais puras todos os um por um, no entanto, esse recurso gerará automaticamente todas as assinaturas de método.

**Como:**

1. Coloque o cursor de texto ou o mouse sobre a classe na qual você deseja implementar as funções virtuais puras da classe base.

   ![Código realçado](images/virtuals_highlight.png)

1. Em seguida, siga um destes procedimentos:
   * **Teclado**
     * Pressione **Ctrl +.** para disparar o **ações rápidas e refatorações** menu e selecione  **implementar todos os virtuais puros para a classe*ClassName*' * * no menu de contexto, onde  *Nome da classe* é o nome da classe selecionada.
   * **Mouse**
     * Clique com botão direito e selecione o **ações rápidas e refatorações** menu e selecione  **implementar todos os virtuais puros para a classe*ClassName*' * * no menu de contexto, onde  *Nome da classe* é o nome da classe selecionada.

1. As assinaturas de método virtual puro será criado automaticamente, pronto para ser implementada.

   ![Implementar virtuais puros resultados](images/virtuals_result.png)
