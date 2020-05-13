---
title: Suporte de MBCS no Visual C++
ms.date: 11/04/2016
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
ms.openlocfilehash: 404fcee5e48d8db28e56a005f24f8cac5892240e
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81375788"
---
# <a name="mbcs-support-in-visual-c"></a>Suporte de MBCS no Visual C++

Quando executado em uma versão habilitada para MBCS do Windows, o sistema de desenvolvimento Visual C++ (incluindo o editor de código-fonte integrado, depurador e ferramentas de linha de comando) é habilitado para MBCS, com exceção da janela de memória.

A janela de memória não interpreta bytes de dados como caracteres MBCS, embora possa interpretá-los como caracteres ANSI ou Unicode. Os caracteres ANSI são sempre 1 byte em tamanho e caracteres Unicode são 2 bytes de tamanho. Com o MBCS, os caracteres podem ter 1 ou 2 bytes de tamanho e sua interpretação depende de qual página de código está em uso. Por causa disso, é difícil para a janela de memória exibir de forma confiável caracteres MBCS. A janela de memória não pode saber qual byte é o início de um personagem. O desenvolvedor pode visualizar os valores de byte na janela de memória e procurar o valor em tabelas para determinar a representação do caractere. Isso é possível porque o desenvolvedor conhece o endereço inicial de uma string com base no código-fonte.

Visual C++ aceita caracteres de byte duplo onde quer que seja apropriado para fazê-lo. Isso inclui nomes de caminhoe nomes de arquivos em caixas de diálogo e entradas de texto no editor de recursos Visual C++ (por exemplo, texto estático no editor de diálogo e entradas de texto estático no editor de ícones). Além disso, o pré-processador reconhece algumas diretivas de byte `#include` duplo — por exemplo, nomes de arquivo em declarações e como argumentos para o `code_seg` e `data_seg` pragmas. No editor de código fonte, caracteres de byte duplo em comentários e literais de seqüência são aceitos, embora não em elementos de linguagem C/C++ (como nomes de variáveis).

## <a name="support-for-the-input-method-editor-ime"></a><a name="_core_support_for_the_input_method_editor_.28.ime.29"></a>Suporte para o IME (Input Method Editor, editor de método sinuoso)

Aplicativos escritos para mercados da Ásia Oriental que usam MBCS (por exemplo, Japão) normalmente suportam o Windows IME para inserir caracteres de um e dois bytes. O ambiente de desenvolvimento Visual C++ contém suporte total para o IME.

Os teclados japoneses não suportam diretamente caracteres Kanji. O IME converte uma corda fonética, inserida em um dos outros alfabetos japoneses (Romaji, Katakana ou Hiragana) em suas possíveis representações kanji. Se houver ambiguidade, você pode selecionar entre várias alternativas. Quando você seleciona o caractere Kanji pretendido, o IME passa duas `WM_CHAR` mensagens para o aplicativo de controle.

O IME, ativado pela\` combinação de teclas ALT+, aparece como um conjunto de botões (um indicador) e uma janela de conversão. O aplicativo posiciona a janela no ponto de inserção do texto. O aplicativo `WM_MOVE` deve `WM_SIZE` manusear e mensagens reposicionando a janela de conversão para estar em conformidade com o novo local ou tamanho da janela de destino.

Se você quiser que os usuários do seu aplicativo tenham a capacidade de inserir caracteres Kanji, o aplicativo deve lidar com mensagens Do Windows IME. Para obter mais informações sobre a programação do IME, consulte [Input Method Manager](/windows/win32/intl/input-method-manager).

## <a name="visual-c-debugger"></a>Depurador Visual C++

O depurador Visual C++ fornece a capacidade de definir pontos de interrupção em mensagens IME. Além disso, a janela Memória pode exibir caracteres de byte duplo.

## <a name="command-line-tools"></a>Ferramentas de linha de comando

As ferramentas de linha de comando Visual C++, incluindo o compilador, o NMAKE e o compilador de recursos (RC. EXE), são habilitados para MBCS. Você pode usar a opção /c do compilador de recursos para alterar a página de código padrão ao compilar os recursos do aplicativo.

Para alterar o local padrão no tempo de compilação do código-fonte, use [#pragma setlocale](../preprocessor/setlocale.md).

## <a name="graphical-tools"></a>Ferramentas Gráficas

As ferramentas baseadas no Visual C++ Windows, como o Spy++ e as ferramentas de edição de recursos, suportam totalmente as strings IME.

## <a name="see-also"></a>Confira também

[Suporte para Conjuntos de Caracteres Multibytes (MBCSs)](../text/support-for-multibyte-character-sets-mbcss.md)<br/>
[Dicas de programação MBCS](../text/mbcs-programming-tips.md)
