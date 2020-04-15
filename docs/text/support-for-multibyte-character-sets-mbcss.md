---
title: Suporte para Conjuntos de Caracteres Multibyte (MBCSs)
ms.date: 11/04/2016
helpviewer_keywords:
- MBCS [C++], about MBCS
- character sets [C++], multibyte
- multibyte characters [C++]
- MBCS [C++]
ms.assetid: b498733c-a1e1-45e3-8f26-d6da3cb5f2dd
ms.openlocfilehash: 0b43168ec4331e99dea7e939b097674cc880804e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375760"
---
# <a name="support-for-multibyte-character-sets-mbcss"></a>Suporte para Conjuntos de Caracteres Multibyte (MBCSs)

Conjuntos de caracteres multibytes (MBCSs) são uma abordagem mais antiga da necessidade de suportar conjuntos de caracteres, como japoneses e chineses, que não podem ser representados em um único byte. Se você estiver fazendo um novo desenvolvimento, você deve usar unicode para todas as strings de texto, exceto talvez strings do sistema que não são vistos pelos usuários finais. O MBCS é uma tecnologia herdada e não é recomendado para novos desenvolvimentos.

A implementação mais comum do MBCS é o Conjunto de Caracteres de byte duplo (DBCSs). Visual C++ em geral, e MFC em particular, está totalmente habilitado para DBCS.

Para obter amostras, consulte os arquivos de código fonte do MFC.

Para plataformas utilizadas em mercados cujos idiomas usam grandes conjuntos de caracteres, a melhor alternativa ao Unicode é o MBCS. O MFC suporta o MBCS usando tipos de dados internacionalizáveis e funções de tempo de execução C. Você deve fazer o mesmo em seu código.

Em MBCS, os caracteres são codificados em 1 ou 2 bytes. Em caracteres de 2 bytes, o primeiro, ou byte principal, sinaliza que tanto ele quanto o byte seguinte devem ser interpretados como um personagem. O primeiro byte vem de uma série de códigos reservados para uso como bytes de chumbo. Quais faixas de bytes podem ser bytes de chumbo depende da página de código em uso. Por exemplo, a página de código japonês 932 usa a faixa 0x81 a 0x9F como bytes de chumbo, mas a página de código coreano 949 usa uma faixa diferente.

Considere todos os seguintes em sua programação MBCS.

Os caracteres MBCS no ambiente os caracteres MBCS podem aparecer em strings, como nomes de arquivos e diretórios.

### <a name="editing-operations"></a>Operações de edição

As operações de edição em aplicativos MBCS devem operar em caracteres, não em bytes. O cuidador não deve dividir um personagem, a **tecla Seta direita** deve mover-se para a direita um personagem, e assim por diante. **Excluir** deve excluir um caractere; **Desfazer** deve reinseri-lo.

### <a name="string-handling"></a>Manipulação de cadeia de caracteres

Em um aplicativo que usa MBCS, o manuseio de cordas apresenta problemas especiais. Os caracteres de ambas as larguras são misturados em uma única seqüência; portanto, você deve se lembrar de verificar se há bytes de chumbo.

### <a name="run-time-library-support"></a>Suporte à biblioteca em tempo de execução

A biblioteca c de tempo de execução e o MFC suportam programação single-byte, MBCS e Unicode. As seqüências de byte `str` único são processadas com a família de funções `_mbs` de tempo de execução, as `wcs` strings MBCS são processadas com funções correspondentes e as strings Unicode são processadas com funções correspondentes. As implementações de funções de membros da classe MFC usam funções `str` portáteis de tempo de execução que mapeiam, sob as circunstâncias certas, a família normal de funções, as funções MBCS ou as funções Unicode, conforme descrito em "portabilidade MBCS/Unicode".

### <a name="mbcsunicode-portability"></a>Portabilidade MBCS/Unicode

Usando o arquivo tchar.h header, você pode criar aplicativos single-byte, MBCS e Unicode a partir das mesmas fontes. Tchar.h define macros prefixadas com `str` *_tcs* , que mapeiam para , `_mbs`ou `wcs` funções, conforme apropriado. Para construir o MBCS, defina o símbolo `_MBCS`. Para construir unicode, `_UNICODE`defina o símbolo . Por padrão, `_UNICODE` é definido para aplicações MFC. Para obter mais informações, consulte [Mapeamentos de texto genéricos em tchar.h](../text/generic-text-mappings-in-tchar-h.md).

> [!NOTE]
> O comportamento é indefinido `_UNICODE` `_MBCS`se você definir ambos e .

Os arquivos de cabeçalho Mbctype.h e Mbstring.h definem funções e macros específicas do MBCS, que você pode precisar em alguns casos. Por exemplo, `_ismbblead` informa se um byte específico em uma seqüência é um byte de chumbo.

Para portabilidade internacional, codifique seu programa com Conjuntos de caracteres [Unicode](../text/support-for-unicode.md) ou multibytes (MBCSs).

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Habilitar MBCS no meu programa](../text/international-enabling.md)

- [Habilite unicode e MBCS no meu programa](../text/internationalization-strategies.md)

- [Use o MBCS para criar um programa internacionalizado](../text/mbcs-programming-tips.md)

- [Veja um resumo da programação do MBCS](../text/mbcs-programming-tips.md)

- [Aprender sobre mapeamentos de texto genérico para portabilidade de largura de byte](../text/generic-text-mappings-in-tchar-h.md)

## <a name="see-also"></a>Confira também

[Texto e Cordas](../text/text-and-strings-in-visual-cpp.md)<br/>
[Suporte de MBCS no Visual C++](../text/mbcs-support-in-visual-cpp.md)
