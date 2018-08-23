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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b63801ac98027f490463f36df23541993528d33b
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42596192"
---
# <a name="international-enabling"></a>Habilitação internacional
Código mais tradicional de C e C++ faz suposições sobre manipulação de caracteres e cadeia de caracteres que não funcionam bem para aplicativos internacionais. Embora o MFC e a biblioteca de tempo de execução suportam Unicode ou MBCS, ainda há trabalho a fazer. Para guiá-lo, esta seção explica o significado de "habilitação internacional" no Visual C++:  
  
-   Unicode e MBCS são habilitados por meio de tipos de dados portáteis no MFC listas de parâmetros de função e tipos de retorno. Esses tipos são definidos condicionalmente das maneiras apropriado, dependendo se sua compilação define o símbolo `_UNICODE` ou o símbolo `_MBCS` (o que significa DBCS). Variantes diferentes das bibliotecas MFC serão vinculados automaticamente a seu aplicativo, dependendo de qual desses dois símbolos define sua compilação.  
  
-   Código de biblioteca de classe usa funções de tempo de execução portátil e outros meios para garantir comportamento correto de Unicode ou MBCS.  
  
-   Você ainda deve tratar certos tipos de tarefas de internacionalização em seu código:  
  
    -   Use as mesmas funções de tempo de execução portátil que portabilizados MFC em qualquer ambiente.  
  
    -   Portabilizados cadeias de caracteres literais e caracteres em um ambiente usando o `_T` macro. Para obter mais informações, consulte [mapeamentos de texto genéricos em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md).  
  
    -   Tome precauções durante a análise de cadeias de caracteres em MBCS. Essas precauções não são necessários em Unicode. Para obter mais informações, consulte [dicas de programação MBCS](../text/mbcs-programming-tips.md).  
  
    -   Tome cuidado se você combinar ANSI (8 bits) e caracteres Unicode (16 bits) em seu aplicativo. É possível usar caracteres de ANSI em algumas partes do seu programa e caracteres Unicode em outros, mas não é possível combiná-los na mesma cadeia de caracteres.  
  
    -   Fazer não codificar cadeias de caracteres em seu aplicativo. Em vez disso, torne-os recursos STRINGTABLE adicionando-as ao arquivo. RC do aplicativo. Seu aplicativo, em seguida, pode ser localizado sem a necessidade de alterações de código de origem ou a recompilação. Para obter mais informações sobre os recursos de STRINGTABLE, consulte [Editor de cadeia de caracteres](../windows/string-editor.md).  
  
> [!NOTE]
>  Conjuntos de caracteres Europeu e MBCS têm alguns caracteres, como letras acentuadas, com códigos de caracteres maiores que 0x80. Como a maioria dos códigos usa caracteres com sinal, esses caracteres maiores que 0x80 são estendido com sinal quando convertido em **int**. Isso é um problema para indexação de matriz porque os caracteres de assinatura estendida, sendo negativo, indexa fora da matriz. Idiomas que usam MBCS, como japonês, também são exclusivos. Como um caractere pode consistir em 1 ou 2 bytes, você sempre deve manipular ambos os bytes ao mesmo tempo.  
  
## <a name="see-also"></a>Consulte também  
 [Unicode e MBCS](../text/unicode-and-mbcs.md)   
 [Estratégias de internacionalização](../text/internationalization-strategies.md)