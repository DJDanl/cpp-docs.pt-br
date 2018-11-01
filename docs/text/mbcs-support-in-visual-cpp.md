---
title: Suporte de MBCS no Visual C++
ms.date: 11/04/2016
f1_keywords:
- _mbcs
helpviewer_keywords:
- tools [C++], MBCS support
- Asian languages [C++]
- Code Editor [C++], MBCS support
- IME [C++]
- Chinese characters [C++]
- Input Method Editor [C++], MBCS
- resource editors [C++], MBCS support
- debugger [C++], MBCS support
- character sets [C++], multibyte
- Japanese characters [C++]
- multibyte characters [C++]
- Kanji character support [C++]
- NMAKE program, MBCS support
- double-byte character sets [C++]
- IME [C++], MBCS
- Input Method Editor [C++]
- MBCS [C++], enabling
ms.assetid: 6179f6b7-bc61-4a48-9267-fb7951223e38
ms.openlocfilehash: 0108068f15132fea38189e17371490a7c0dd5d8b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50465222"
---
# <a name="mbcs-support-in-visual-c"></a>Suporte de MBCS no Visual C++

Quando executado em uma versão do Windows habilitada MBCS, o sistema de desenvolvimento do Visual C++ (incluindo as ferramentas de editor, depurador e linha de comando de código do código-fonte integrado) está habilitado para MBCS, com exceção da janela de memória.

A janela de memória não interpreta os bytes de dados como caracteres MBCS, mesmo que ele pode interpretá-los como caracteres ANSI ou Unicode. Caracteres ANSI são sempre 1 byte de tamanho e caracteres Unicode têm tamanho de 2 bytes. Com o MBCS, os caracteres podem ser 1 ou 2 bytes de tamanho e sua interpretação depende de qual página de código está em uso. Por isso, é difícil para a janela de memória exibir com confiança caracteres MBCS. A janela de memória não pode saber quais byte é o início de um caractere. O desenvolvedor pode exibir os valores de bytes na janela de memória e pesquisar o valor nas tabelas para determinar a representação de caracteres. Isso é possível porque o desenvolvedor sabe o endereço inicial de uma cadeia de caracteres com base no código-fonte.

Visual C++ aceita caracteres de byte duplo, onde for apropriado para isso. Isso inclui nomes de caminhos e nomes de arquivo nas caixas de diálogo e as entradas de texto no editor de recursos do Visual C++ (por exemplo, texto estático no editor de caixa de diálogo) e entradas de texto estático no editor de ícone. Além disso, o pré-processador reconhece algumas diretivas de byte duplo — por exemplo, arquivo nomes na `#include` instruções e como argumentos para o `code_seg` e `data_seg` pragmas. No editor de código fonte, são aceitos caracteres de byte duplo em comentários e literais de cadeia de caracteres, embora não estejam em elementos de linguagem C/C++ (como nomes de variáveis).

##  <a name="_core_support_for_the_input_method_editor_.28.ime.29"></a> Suporte para o Editor de método de entrada (IME)

Aplicativos escritos para mercados do Leste Asiático que usam MBCS (por exemplo, Japão) normalmente o IME do Windows de suporte para a inserção de ambos os caracteres de byte único e duplo. O ambiente de desenvolvimento do Visual C++ contém suporte completo para o IME.

Os teclados japoneses não suportam diretamente caracteres Kanji. O IME converterá uma cadeia de caracteres fonética inserida em uma dos alfabetos outros japonês (Romaji, Katakana ou Hiragana) em suas representações de Kanji possíveis. Caso haja ambiguidade, você pode selecionar entre várias alternativas. Quando você tiver selecionado o caractere de Kanji pretendido, o IME passa dois `WM_CHAR` mensagens para o aplicativo de controle.

O IME, ativado por ALT +\` combinação de teclas, aparece como um conjunto de botões (um indicador) e uma janela de conversão. O aplicativo posiciona a janela no ponto de inserção de texto. O aplicativo deve tratar `WM_MOVE` e `WM_SIZE` mensagens pelo reposicionamento a janela de conversão em conformidade com o novo local ou o tamanho da janela de destino.

Se você quiser que os usuários do seu aplicativo para ter a capacidade de inserir caracteres Kanji, o aplicativo deve tratar as mensagens do IME do Windows. Para obter mais informações sobre a programação do IME, consulte [Input Method Manager](/windows/desktop/intl/input-method-manager).

## <a name="visual-c-debugger"></a>Depurador do Visual C++

O depurador do Visual C++ fornece a capacidade de definir pontos de interrupção em mensagens IME. Além disso, a janela de memória pode exibir caracteres de byte duplo.

## <a name="command-line-tools"></a>Ferramentas de linha de comando

As ferramentas de linha de comando do Visual C++, incluindo o compilador, NMAKE e o compilador de recursos (RC. EXE), são habilitados para MBCS. Você pode usar a opção de /c do compilador de recurso para alterar a página de código padrão durante a compilação de recursos de seu aplicativo.

Para alterar a localidade padrão em tempo de compilação do código fonte, use [#pragma setlocale](../preprocessor/setlocale.md).

## <a name="graphical-tools"></a>Ferramentas gráficas

As ferramentas baseadas em Windows do Visual C++, como o Spy + + e o recurso de edição de ferramentas, suportam completo a cadeias de caracteres do IME.

## <a name="see-also"></a>Consulte também

[Suporte para MBCSs (conjuntos de caracteres multibyte)](../text/support-for-multibyte-character-sets-mbcss.md)<br/>
[Dicas de programação do MBCS](../text/mbcs-programming-tips.md)