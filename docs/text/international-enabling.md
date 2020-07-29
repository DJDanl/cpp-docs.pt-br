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
ms.openlocfilehash: ff0fb4102a0453b900b5b406739492a9420a5b07
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87228083"
---
# <a name="international-enabling"></a>Habilitação internacional

O código C e C++ mais tradicional faz suposições sobre a manipulação de caracteres e cadeias de caracteres que não funcionam bem para aplicativos internacionais. Embora o MFC e a biblioteca de tempo de execução ofereçam suporte a Unicode ou MBCS, ainda há trabalho a ser feito. Para orientá-lo, esta seção explica o significado da "habilitação internacional" no Visual C++:

- Tanto o Unicode quanto o MBCS são habilitados por meio de tipos de dados portáteis em listas de parâmetros de função do MFC e tipos de retorno. Esses tipos são definidos condicionalmente de maneira apropriada, dependendo se sua compilação define o símbolo `_UNICODE` ou o símbolo `_MBCS` (que significa DBCS). Variantes diferentes das bibliotecas MFC são automaticamente vinculadas ao seu aplicativo, dependendo de quais desses dois símbolos seu Build define.

- O código da biblioteca de classes usa funções de tempo de execução portáteis e outros meios para garantir o comportamento correto de Unicode ou MBCS.

- Você ainda deve lidar com determinados tipos de tarefas de internacionalização em seu código:

  - Use as mesmas funções de tempo de execução portátil que tornam o MFC portátil em qualquer ambiente.

  - Torne cadeias de caracteres literais e de dispositivos portáteis em qualquer ambiente, usando a `_T` macro. Para obter mais informações, consulte [mapeamentos de texto genérico em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md).

  - Tome precauções ao analisar cadeias de caracteres em MBCS. Essas precauções não são necessárias em Unicode. Para obter mais informações, consulte [dicas de programação MBCS](../text/mbcs-programming-tips.md).

  - Tome cuidado se você misturar caracteres ANSI (8 bits) e Unicode (16 bits) em seu aplicativo. É possível usar caracteres ANSI em algumas partes do seu programa e caracteres Unicode em outros, mas você não pode misturá-los na mesma cadeia de caracteres.

  - Não codifique cadeias de caracteres em seu aplicativo. Em vez disso, torne-os recursos STRINGTABLE adicionando-os ao arquivo. rc do aplicativo. Seu aplicativo pode ser localizado sem a necessidade de alterações de código-fonte ou recompilação. Para obter mais informações sobre os recursos do STRINGTABLE, consulte [Editor de cadeia de caracteres](../windows/string-editor.md).

> [!NOTE]
> Os conjuntos de caracteres Europeu e MBCS têm alguns caracteres, como letras acentuadas, com códigos de caracteres maiores que 0x80. Como a maioria dos códigos usa caracteres assinados, esses caracteres maiores que 0x80 são estendidos quando convertidos em **`int`** . Esse é um problema para a indexação de matriz porque os caracteres de assinatura estendida, sendo negativos, os índices fora da matriz. Os idiomas que usam MBCS, como o japonês, também são exclusivos. Como um caractere pode consistir em 1 ou 2 bytes, você sempre deve manipular ambos os bytes ao mesmo tempo.

## <a name="see-also"></a>Confira também

[Unicode e MBCS](../text/unicode-and-mbcs.md)<br/>
[Estratégias de internacionalização](../text/internationalization-strategies.md)
