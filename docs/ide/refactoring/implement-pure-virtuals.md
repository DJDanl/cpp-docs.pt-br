---
title: Implementar Virtuais Puros
ms.date: 11/16/2016
ms.assetid: ea9b4719-34a3-474a-b4ec-05b1859f80f1
ms.openlocfilehash: 59e4519f57a1d9bd9ba1cee1ed6ae41bea785a9f
ms.sourcegitcommit: b032daf81cb5fdb1f5a988277ee30201441c4945
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/15/2018
ms.locfileid: "51692652"
---
# <a name="implement-pure-virtuals"></a>Implementar Virtuais Puros

**O quê:** permite gerar imediatamente o código necessário para implementar todos os métodos virtuais puros em uma classe.

**Quando:** você deseja herdar de uma classe com funções virtuais puras.

**Por quê:** você pode implementar todas as funções virtuais puras manualmente uma por uma; no entanto, esse recurso gerará todas as assinaturas de método automaticamente.

**Como:**

1. Coloque o cursor de texto ou do mouse sobre a classe na qual deseja implementar as funções virtuais puras da classe base.

   ![Código realçado](images/virtuals_highlight.png)

1. Depois, siga um destes procedimentos:
   * **Teclado**
     * Pressione **Ctrl +.** para disparar o menu **Ações Rápidas e Refatorações** e selecione **Implementar todos os Virtuais Puros para a classe '*ClassName*'** no menu de contexto, em que *ClassName* é o nome da classe selecionada.
   * **Mouse**
     * Clique com o botão direito do mouse, selecione o menu **Ações Rápidas e Refatorações** e selecione **Implementar todos os Virtuais Puros para a classe '*ClassName*'** no menu de contexto, em que *ClassName* é o nome da classe selecionada.

1. As assinaturas de método virtuais puras serão criadas automaticamente, prontas para serem implementadas.

   ![Resultado de Implementar Virtuais Puros](images/virtuals_result.png)
