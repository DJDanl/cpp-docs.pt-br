---
title: Habilitação internacional | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- globalization [C++], character sets
- strings [C++], international enabling
- localization [C++], character sets
- MBCS [C++], enabling
- Unicode [C++], enabling
ms.assetid: b077f4ca-5865-40ef-a46e-d9e4d686ef21
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 2f4edcae610f17409c319c7b4bd39dc137e1211e
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
---
# <a name="international-enabling"></a>Habilitação internacional
Código C e C++ mais tradicional faz suposições sobre manipulação de caracteres e cadeia de caracteres que não funcionam bem para aplicativos internacionais. Enquanto MFC e a biblioteca de tempo de execução oferecem suporte a Unicode ou MBCS, ainda há trabalho para fazer. Para guiá-lo, esta seção explica o significado de "habilitação internacional" no Visual C++:  
  
-   Unicode e MBCS são habilitados por meio de tipos de dados portátil em listas de parâmetros de função MFC e tipos de retorno. Esses tipos são definidos condicionalmente das maneiras apropriada, dependendo se sua compilação define o símbolo **Unicode** ou o símbolo **MBCS** (o que significa DBCS). Variantes diferentes das bibliotecas MFC são vinculados automaticamente com o seu aplicativo, dependendo de qual desses dois símbolos define sua compilação.  
  
-   Código de biblioteca de classe usa funções de tempo de execução portátil e outros meios para verificar o comportamento correto de Unicode ou MBCS.  
  
-   Você ainda deve tratar determinados tipos de tarefas de internacionalização no seu código:  
  
    -   Use as mesmas funções de tempo de execução portátil que tornam o MFC portátil em qualquer ambiente.  
  
    -   Tornar cadeias de caracteres literais e caracteres portátil em um ambiente usando o **t** macro. Para obter mais informações, consulte [mapeamentos de texto genéricos em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md).  
  
    -   Tome precauções durante a análise de cadeias de caracteres em MBCS. Essas medidas não são necessários em Unicode. Para obter mais informações, consulte [dicas de programação MBCS](../text/mbcs-programming-tips.md).  
  
    -   Tome cuidado se você combinar ANSI (8 bits) e caracteres Unicode (16 bits) em seu aplicativo. É possível usar caracteres de ANSI em algumas partes do seu programa e caracteres Unicode em outras, mas você não pode misturá-los na mesma cadeia de caracteres.  
  
    -   Faça não codificar cadeias de caracteres em seu aplicativo. Em vez disso, torne-os recursos STRINGTABLE ao adicioná-los para o arquivo do aplicativo. rc. Seu aplicativo, em seguida, pode ser localizado sem a necessidade de alterações de código fonte ou a recompilação. Para obter mais informações sobre os recursos de STRINGTABLE, consulte [Editor de cadeia de caracteres](../windows/string-editor.md).  
  
> [!NOTE]
>  Conjuntos de caracteres Europeu e MBCS têm alguns caracteres, como letras acentuadas, com códigos de caracteres maiores que 0x80. Como grande parte do código usa caracteres assinados, esses caracteres maiores 0x80 são estendidos de entrada quando convertido em `int`. Isso é um problema para indexação de matriz porque os caracteres de assinatura estendida, sendo negativo, índices fora da matriz. Idiomas que usam MBCS, como japonês, também são exclusivos. Como um caractere pode consistir em 1 ou 2 bytes, você sempre deve manipular ambos os bytes ao mesmo tempo.  
  
## <a name="see-also"></a>Consulte também  
 [Unicode e MBCS](../text/unicode-and-mbcs.md)   
 [Estratégias de internacionalização](../text/internationalization-strategies.md)