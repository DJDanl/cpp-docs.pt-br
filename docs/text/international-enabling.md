---
title: Habilitação internacional
ms.date: 11/04/2016
helpviewer_keywords:
- globalization [C++], character sets
- strings [C++], international enabling
- localization [C++], character sets
- MBCS [C++], enabling
- Unicode [C++], enabling
ms.assetid: b077f4ca-5865-40ef-a46e-d9e4d686ef21
ms.openlocfilehash: b6c645bafef87ed0b2d43903f4752ef659d79f89
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375800"
---
# <a name="international-enabling"></a>Habilitação internacional

O código C e C++ tradicional faz suposições sobre manipulação de caracteres e cordas que não funcionam bem para aplicações internacionais. Embora tanto o MFC quanto a biblioteca de tempo de execução suportem unicode ou MBCS, ainda há trabalho para você fazer. Para guiá-lo, esta seção explica o significado de "habilitação internacional" no Visual C++:

- Tanto o Unicode quanto o MBCS são habilitados por meio de tipos de dados portáteis em listas de parâmetros de função MFC e tipos de retorno. Esses tipos são condicionados definidos da maneira apropriada, dependendo `_UNICODE` se `_MBCS` sua compilação define o símbolo ou o símbolo (o que significa DBCS). Diferentes variantes das bibliotecas MFC são automaticamente ligadas ao seu aplicativo, dependendo de qual desses dois símbolos sua compilação define.

- O código de biblioteca de classe usa funções portáteis de tempo de execução e outros meios para garantir o comportamento unicode correto ou MBCS.

- Você ainda deve lidar com certos tipos de tarefas de internacionalização em seu código:

  - Use as mesmas funções portáteis de tempo de execução que tornam o MFC portátil em qualquer ambiente.

  - Faça seqüências literais e `_T` caracteres portáteis em ambos os ambientes, usando a macro. Para obter mais informações, consulte [Mapeamentos de texto genéricos em tchar.h](../text/generic-text-mappings-in-tchar-h.md).

  - Tome precauções ao analisar as cordas sob MBCS. Essas precauções não são necessárias sob unicode. Para obter mais informações, consulte [dicas de programação do MBCS](../text/mbcs-programming-tips.md).

  - Tome cuidado se você misturar caracteres ANSI (8 bits) e Unicode (16 bits) em sua aplicação. É possível usar caracteres ANSI em algumas partes do seu programa e caracteres Unicode em outros, mas você não pode misturá-los na mesma seqüência.

  - Não codifique as strings em sua aplicação. Em vez disso, faça-os recursos STRINGTABLE adicionando-os ao arquivo .rc do aplicativo. Seu aplicativo pode então ser localizado sem exigir alterações de código-fonte ou recompilação. Para obter mais informações sobre os recursos STRINGTABLE, consulte [String Editor](../windows/string-editor.md).

> [!NOTE]
> Os conjuntos de caracteres europeus e MBCS têm alguns caracteres, como letras acentuadas, com códigos de caracteres maiores que 0x80. Como a maioria dos caracteres de código usa caracteres assinados, esses caracteres maiores que 0x80 são estendidos por sinal quando convertidos **em int**. Este é um problema para indexação de matrizes porque os caracteres estendidos por sinal, sendo negativos, índices fora da matriz. Línguas que usam MBCS, como o japonês, também são únicas. Como um personagem pode consistir de 1 ou 2 bytes, você deve sempre manipular ambos os bytes ao mesmo tempo.

## <a name="see-also"></a>Confira também

[Unicode e MBCS](../text/unicode-and-mbcs.md)<br/>
[Estratégias de Internacionalização](../text/internationalization-strategies.md)
