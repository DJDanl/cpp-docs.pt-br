---
title: Implementar virtuais puros | Microsoft Docs
ms.custom: ''
ms.date: 11/16/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
ms.assetid: ea9b4719-34a3-474a-b4ec-05b1859f80f1
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: afce516f2718a76658846ed4f992aeabff75330b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="implement-pure-virtuals"></a>Implementar virtuais puros
**O que:** permite gerar imediatamente o código necessário para implementar todos os métodos virtual puros em uma classe. 

**Quando:** você deseja herdar de uma classe com funções virtuais puras.  

**Motivo:** pode implementar manualmente funções virtuais puras todos os um por um, no entanto, esse recurso gerará automaticamente todas as assinaturas de método.

**Como:**

1. Coloque o cursor de texto ou o mouse sobre a classe na qual você deseja implementar as funções virtuais puras da classe base.

   ![Código realçado](images/virtuals_highlight.png)

1. Depois, siga um destes procedimentos:
   * **Teclado**
     * Pressione **Ctrl +.** para disparar o **ações rápidas e refatorações** menu e selecione **implementar todos os virtuais puros para a classe*ClassName*'** no menu de contexto, onde  *Nome da classe* é o nome da classe selecionada.
   * **Mouse**
     * Clique com botão direito e selecione o **ações rápidas e refatorações** menu e selecione **implementar todos os virtuais puros para a classe*ClassName*'** no menu de contexto, onde  *Nome da classe* é o nome da classe selecionada.

1. As assinaturas de método virtual puro será criado automaticamente, pronto para ser implementada.

   ![Implementar virtuais puros resultados](images/virtuals_result.png)
