---
title: Converter em literal de cadeia de caracteres bruta
ms.date: 11/16/2016
ms.assetid: fffbfee4-66ee-42ba-aeb9-df07fb702c51
ms.openlocfilehash: 508ab52dc1ca41a97dd8c24df5c5d45c379ea265
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50509507"
---
# <a name="convert-to-raw-string-literal"></a>Converter em literal de cadeia de caracteres bruta
**O quê:** permite transformar qualquer cadeia de caracteres em um literal de cadeia de caracteres bruta C++.

**Quando:** você tem uma cadeia de caracteres com caracteres de escape que não devem ser processados como caracteres de escape.

**Por quê:** você pode fazer o escape duplo dos caracteres, mas, geralmente, isso leva a cadeias de caracteres confusas e ilegíveis.  O uso de literais de cadeia de caracteres bruta facilita muito a leitura das cadeias de caracteres.

**Como:**

1. Coloque o cursor de texto ou do mouse sobre a cadeia de caracteres de escape a ser convertida.

   ![Código realçado](images/stringliteral_highlight.png)

1. Depois, siga um destes procedimentos:
   * **Teclado**
     * Pressione **Ctrl +.** para disparar o menu **Ações Rápidas e Refatorações** e selecione **Converter em Literal de Cadeia de Caracteres Bruta** no menu de contexto.
   * **Mouse**
     * Clique com o botão direito do mouse no código, selecione o menu **Ações Rápidas e Refatorações** e selecione **Converter em Literal de Cadeia de Caracteres Bruta** no menu de contexto.
     * Clique no ícone de ![Lâmpada](images/bulb.png) exibido na margem esquerda e selecione **Converter em Literal de Cadeia de Caracteres Bruta** no menu de contexto.

1. A cadeia de caracteres será imediatamente convertida em um literal de cadeia de caracteres bruta.

   ![Resultado do Literal de Cadeia de Caracteres Bruta](images/stringliteral_result.png)