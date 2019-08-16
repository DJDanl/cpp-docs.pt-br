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
ms.openlocfilehash: b5f2b6dd56d3a755ee73058c024152e12157a6bd
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69501942"
---
# <a name="mbcs-support-in-visual-c"></a>Suporte de MBCS no Visual C++

Quando executado em uma versão habilitada para MBCS do Windows, o C++ sistema de desenvolvimento Visual (incluindo o editor de código-fonte integrado, o depurador e as ferramentas de linha de comando) é habilitado para MBCS, com exceção da janela de memória.

A janela memória não interpreta bytes de dados como caracteres MBCS, embora possa interpretá-los como caracteres ANSI ou Unicode. Os caracteres ANSI são sempre de 1 byte e os caracteres Unicode têm 2 bytes de tamanho. Com MBCS, os caracteres podem ter 1 ou 2 bytes de tamanho e sua interpretação depende de qual página de código está em uso. Por isso, é difícil para a janela de memória exibir os caracteres MBCS de maneira confiável. A janela memória não pode saber qual byte é o início de um caractere. O desenvolvedor pode exibir os valores de byte na janela de memória e pesquisar o valor em tabelas para determinar a representação de caracteres. Isso é possível porque o desenvolvedor sabe o endereço inicial de uma cadeia de caracteres com base no código-fonte.

O C++ Visual aceita caracteres de byte duplo onde quer que seja apropriado. Isso inclui nomes de caminho e nomes de arquivo em caixas de diálogo e entradas de C++ texto no editor de recursos visuais (por exemplo, texto estático no editor de caixa de diálogo e entradas de texto estáticos no editor de ícone). Além disso, o pré-processador reconhece algumas diretivas de byte duplo — por exemplo, nomes de arquivo em `#include` instruções, e como argumentos para os `code_seg` pragmas `data_seg` e. No editor de código-fonte, caracteres de byte duplo em comentários e literais de cadeia de caracteres são aceitos,C++ embora não estejam em elementos C/Language (como nomes de variáveis).

##  <a name="_core_support_for_the_input_method_editor_.28.ime.29"></a>Suporte para o IME (editor de método de entrada)

Os aplicativos escritos para mercados do leste asiático que usam MBCS (por exemplo, Japão) normalmente dão suporte ao Windows IME para inserir caracteres de byte único e de dois bytes. O ambiente C++ de desenvolvimento Visual contém suporte completo para o IME.

Os teclados japoneses não dão suporte direto a caracteres kanji. O IME converte uma cadeia de caracteres fonética, inserida em um dos outros alfabetos japoneses (romaji, Katakana ou hiragana) em suas representações de kanji possíveis. Se houver ambiguidade, você poderá selecionar entre várias alternativas. Quando você tiver selecionado o caractere kanji pretendido, o IME passará duas `WM_CHAR` mensagens para o aplicativo de controle.

O IME, ativado pela combinação Alt +\` tecla, é exibido como um conjunto de botões (um indicador) e uma janela de conversão. O aplicativo posiciona a janela no ponto de inserção de texto. O aplicativo deve tratar `WM_MOVE` e `WM_SIZE` mensagens Reposicionando a janela de conversão para estar de acordo com o novo local ou o tamanho da janela de destino.

Se você quiser que os usuários do seu aplicativo tenham a capacidade de inserir caracteres kanji, o aplicativo deverá manipular as mensagens do Windows IME. Para obter mais informações sobre a programação do IME, consulte [Gerenciador de métodos de entrada](/windows/win32/intl/input-method-manager).

## <a name="visual-c-debugger"></a>Depurador C++ Visual

O depurador C++ Visual fornece a capacidade de definir pontos de interrupção em mensagens do IME. Além disso, a janela memória pode exibir caracteres de byte duplo.

## <a name="command-line-tools"></a>Ferramentas de linha de comando

As ferramentas C++ de linha de comando do Visual, incluindo o compilador, NMAKE e o compilador de recurso (RC. EXE), estão habilitados para MBCS. Você pode usar a opção/c do compilador de recurso para alterar a página de código padrão ao compilar os recursos do aplicativo.

Para alterar a localidade padrão no momento da compilação do código-fonte, use [#pragma](../preprocessor/setlocale.md)setlocale.

## <a name="graphical-tools"></a>Ferramentas gráficas

As ferramentas C++ baseadas no Windows Visual, como Spy + + e as ferramentas de edição de recursos, oferecem suporte total a cadeias de caracteres do IME.

## <a name="see-also"></a>Consulte também

[Suporte para MBCSs (conjuntos de caracteres multibyte)](../text/support-for-multibyte-character-sets-mbcss.md)<br/>
[Dicas de programação do MBCS](../text/mbcs-programming-tips.md)
