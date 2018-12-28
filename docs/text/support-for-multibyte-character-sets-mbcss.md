---
title: Suporte para Conjuntos de Caracteres Multibyte (MBCSs)
ms.date: 11/04/2016
f1_keywords:
- _mbcs
helpviewer_keywords:
- MBCS [C++], about MBCS
- character sets [C++], multibyte
- multibyte characters [C++]
- MBCS [C++]
ms.assetid: b498733c-a1e1-45e3-8f26-d6da3cb5f2dd
ms.openlocfilehash: 9f309f6d7147b37691564d3d72c151da90055c6a
ms.sourcegitcommit: ff3cbe4235b6c316edcc7677f79f70c3e784ad76
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/19/2018
ms.locfileid: "53627339"
---
# <a name="support-for-multibyte-character-sets-mbcss"></a>Suporte para Conjuntos de Caracteres Multibyte (MBCSs)

Conjuntos de caracteres multibyte (MBCSs) são uma abordagem mais antiga para a necessidade de dar suporte a conjuntos de caracteres, como japonês e chinês, o que não podem ser representado em um único byte. Se você estiver fazendo o desenvolvimento de novos, você deve usar Unicode para todas as cadeias de caracteres de texto, exceto talvez sistema cadeias de caracteres que não são vistas pelos usuários finais. MBCS é uma tecnologia herdada e não é recomendado para novo desenvolvimento.

A implementação mais comum de MBCS é conjuntos de caracteres de byte duplo (DBCSs). Visual C++ em geral e o MFC em especial, é totalmente habilitado para DBCS.

Para obter exemplos, consulte os arquivos de código de origem do MFC.

Para plataformas usadas em mercados cujas linguagens usam conjuntos de caracteres grandes, a melhor alternativa para Unicode é MBCS. MFC dá suporte a MBCS, usando tipos de dados internationalizable e funções de tempo de execução C. Você deve fazer o mesmo em seu código.

Em MBCS, os caracteres são codificados em 1 ou 2 bytes. Em caracteres de 2 bytes, o primeiro ou o byte inicial, sinaliza que ele e o byte seguinte devem ser interpretadas como um caractere. O primeiro byte vem de um intervalo de códigos de reservado para uso como bytes iniciais. Quais intervalos de bytes podem ser bytes iniciais depende da página de código em uso. Por exemplo, a página de código japonesa 932 usa o intervalo 0x81 a 0x9F como bytes iniciais, mas a página de código coreano 949 usa um intervalo diferente.

Considere a seguinte em sua programação de MBCS.

Caracteres MBCS nos caracteres MBCS ambiente podem aparecer em cadeias de caracteres como nomes de arquivo e diretório.

### <a name="editing-operations"></a>Operações de edição

Edição de operações em aplicativos de MBCS deve operar em caracteres, não em bytes. O cursor não Divida um caractere, o **seta para a direita** chave deverá mover um caractere à direita e assim por diante. **Excluir** deve excluir um caractere. **Desfazer** deve inseri-lo novamente.

### <a name="string-handling"></a>Manipulação de cadeia de caracteres

Em um aplicativo que usa MBCS, manipulação de cadeia de caracteres apresenta problemas especiais. Caracteres de ambas as larguras são combinados em uma única cadeia de caracteres; Portanto, você deve se lembrar verificar se há bytes iniciais.

### <a name="run-time-library-support"></a>Suporte de biblioteca de tempo de execução

Byte único, MBCS e Unicode dão suporte a biblioteca em tempo de execução C e o MFC de programação. Cadeias de caracteres de byte único são processadas com o `str` família de funções de tempo de execução, cadeias de caracteres MBCS são processados com correspondente `_mbs` funções e cadeias de caracteres Unicode são processados com correspondente `wcs` funções. Implementações de função de membro de classe MFC usam funções de tempo de execução portátil que mapeiam, sob determinadas circunstâncias, como o normal `str` família de funções, as funções MBCS ou as funções do Unicode, conforme descrito em "Portabilidade MBCS/Unicode".

### <a name="mbcsunicode-portability"></a>Portabilidade MBCS/Unicode

Usando o arquivo de cabeçalho TCHAR. h, você pode criar um byte, MBCS e Unicode aplicativos das mesmas origens. TCHAR. h define o prefixo de macros *_tcs* , que mapeiam para `str`, `_mbs`, ou `wcs` funções, conforme apropriado. Para compilar o MBCS, defina o símbolo `_MBCS`. Para compilar o Unicode, defina o símbolo `_UNICODE`. Por padrão, `_UNICODE` está definido para aplicativos MFC. Para obter mais informações, consulte [mapeamentos de texto genéricos em TCHAR. h](../text/generic-text-mappings-in-tchar-h.md).

> [!NOTE]
>  Comportamento será indefinido se você definir ambos `_UNICODE` e `_MBCS`.

Os arquivos de cabeçalho mbctype e mbstring definem funções específicas de MBCS e macros, que talvez seja necessário em alguns casos. Por exemplo, `_ismbblead` informa se um byte específico em uma cadeia de caracteres é um byte inicial.

Para fins de portabilidade internacionais, o código de seu programa com [Unicode](../text/support-for-unicode.md) ou conjuntos de caracteres multibyte (MBCSs).

## <a name="what-do-you-want-to-do"></a>O que você deseja fazer?

- [Habilitar MBCS em meu programa](../text/international-enabling.md)

- [Habilitar Unicode e MBCS em meu programa](../text/internationalization-strategies.md)

- [Uso MBCS para criar um programa internacionalizado](../text/mbcs-programming-tips.md)

- [Veja um resumo de programação do MBCS](../text/mbcs-programming-tips.md)

- [Saiba mais sobre mapeamentos de texto genérico para portabilidade de largura de byte](../text/generic-text-mappings-in-tchar-h.md)

## <a name="see-also"></a>Consulte também

[Texto e cadeias de caracteres](../text/text-and-strings-in-visual-cpp.md)<br/>
[Suporte a MBCS no Visual C++](../text/mbcs-support-in-visual-cpp.md)
