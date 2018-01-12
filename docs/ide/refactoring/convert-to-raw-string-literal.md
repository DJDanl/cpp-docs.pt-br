---
title: Converter a cadeia de caracteres Literal | Microsoft Docs
ms.custom: 
ms.date: 11/16/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: fffbfee4-66ee-42ba-aeb9-df07fb702c51
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 12aa512270ecce4564561634f99be9cbf155448a
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="convert-to-raw-string-literal"></a>Converter a cadeia de caracteres Literal
**O que:** permite que você ative qualquer cadeia de caracteres em uma cadeia de caracteres bruta de C++ literal.

**Quando:** você tiver uma cadeia de caracteres com caracteres de escape que não devem ser processados como caracteres de escape.

**Motivo:** pôde caracteres de escape duplo, mas isso geralmente leva a cadeias de caracteres confusas e ilegíveis.  Usar literais de cadeia de caracteres bruta torna muito mais fácil ler cadeias de caracteres.

**Como:**

1. Coloque o cursor de texto ou o mouse sobre a cadeia de caracteres de escape para converter.

   ![Código realçado](images/stringliteral_highlight.png)

1. Em seguida, siga um destes procedimentos:
   * **Teclado**
     * Pressione **Ctrl +.** para disparar o **ações rápidas e refatorações** menu e selecione **converter em Literal de cadeia de caracteres bruto** no menu de contexto.
   * **Mouse**
     * Clique com botão direito do código, selecione o **ações rápidas e refatorações** menu e selecione **converter em Literal de cadeia de caracteres bruto** no menu de contexto.
     * Clique o ![Lightbulb](images/bulb.png) ícone que aparece na margem esquerda e selecione **converter em Literal de cadeia de caracteres bruto** no menu de contexto.

1. A cadeia de caracteres serão imediatamente convertida em um literal de cadeia bruto.  

   ![Resultado de cadeia de caracteres Literal bruto](images/stringliteral_result.png)