---
title: Converter a cadeia de caracteres Literal | Microsoft Docs
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
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="convert-to-raw-string-literal"></a>Converter a cadeia de caracteres Literal
**O que:** permite que você ative qualquer cadeia de caracteres em uma cadeia de caracteres bruta de C++ literal.

**Quando:** você tiver uma cadeia de caracteres com caracteres de escape que não devem ser processados como caracteres de escape.

**Motivo:** pôde caracteres de escape duplo, mas isso geralmente leva a cadeias de caracteres confusas e ilegíveis.  Usar literais de cadeia de caracteres bruta torna muito mais fácil ler cadeias de caracteres.

**Como:**

1. Coloque o cursor de texto ou o mouse sobre a cadeia de caracteres de escape para converter.

   ![Código realçado](images/stringliteral_highlight.png)

1. Depois, siga um destes procedimentos:
   * **Teclado**
     * Pressione **Ctrl +.** para disparar o **ações rápidas e refatorações** menu e selecione **converter em Literal de cadeia de caracteres bruto** no menu de contexto.
   * **Mouse**
     * Clique com botão direito do código, selecione o **ações rápidas e refatorações** menu e selecione **converter em Literal de cadeia de caracteres bruto** no menu de contexto.
     * Clique o ![Lightbulb](images/bulb.png) ícone que aparece na margem esquerda e selecione **converter em Literal de cadeia de caracteres bruto** no menu de contexto.

1. A cadeia de caracteres serão imediatamente convertida em um literal de cadeia bruto.  

   ![Resultado de cadeia de caracteres Literal bruto](images/stringliteral_result.png)