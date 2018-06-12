---
title: Converter em literal de cadeia de caracteres bruta | Microsoft Docs
ms.custom: ''
ms.date: 11/16/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
ms.assetid: fffbfee4-66ee-42ba-aeb9-df07fb702c51
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b98825719e7b3c0d8eb760a2ec50644b5eddd54e
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33328403"
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