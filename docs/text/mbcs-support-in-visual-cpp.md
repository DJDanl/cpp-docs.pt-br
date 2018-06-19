---
title: Suporte MBCS no Visual C++ | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- _mbcs
dev_langs:
- C++
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
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 41d075edb01fc139660d8e72a7fe53f03ee9e80b
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33865830"
---
# <a name="mbcs-support-in-visual-c"></a>Suporte de MBCS no Visual C++
Quando executado em uma versão do Windows habilitada MBCS, o sistema de desenvolvimento do Visual C++ (incluindo as ferramentas de editor, o depurador e a linha de comando de código fonte integrado) está habilitado para MBCS, com exceção da janela de memória.  
  
 A janela de memória não interpreta os bytes de dados como caracteres MBCS, mesmo que ele pode interpretá-las como caracteres ANSI ou Unicode. Caracteres ANSI são sempre 1 bytes de tamanho e caracteres Unicode 2 bytes de tamanho. Com MBCS, caracteres podem ser 1 ou 2 bytes de tamanho e a interpretação depende de qual página de código está em uso. Por isso, é difícil para a janela de memória exibir com segurança caracteres MBCS. A janela de memória não é possível saber quais byte é o início de um caractere. O desenvolvedor pode exibir os valores de bytes na janela de memória e pesquisar o valor nas tabelas para determinar a representação de caractere. Isso é possível porque o desenvolvedor sabe o endereço inicial de uma cadeia de caracteres com base no código-fonte.  
  
 Visual C++ aceita caracteres de byte duplo, independentemente de onde ele é apropriado fazer isso. Isso inclui nomes de caminhos e nomes de arquivo nas caixas de diálogo e entradas de texto no editor de recursos do Visual C++ (por exemplo, texto estático no editor de caixa de diálogo) e entradas de texto estático no editor de ícone. Além disso, o pré-processador reconhece algumas diretivas de byte duplo — por exemplo, arquivo nomes em `#include` instruções e como argumentos para o **code_seg** e **data_seg** pragmas. No editor de código fonte, caracteres de byte duplo em comentários e literais de cadeia de caracteres forem aceitas, embora não estejam em elementos de linguagem C/C++ (como nomes de variável).  
  
##  <a name="_core_support_for_the_input_method_editor_.28.ime.29"></a> Suporte para Editor de método de entrada (IME)  
 Aplicativos escritos para mercados do Leste Asiático que usam MBCS (por exemplo, Japão) normalmente suportam o IME do Windows para inserir os dois caracteres de byte único e duplo. O ambiente de desenvolvimento do Visual C++ contém suporte completo para o IME. Para obter mais informações, consulte [exemplo IME: demonstra como modo de IME do controle e implementar IME nível 3](http://msdn.microsoft.com/en-us/87ebdf65-cef0-451d-a6fc-d5fb64178b14).  
  
 Teclados japonês diretamente não dão suporte a caracteres de Kanji. O IME converte uma cadeia fonética, inserida em um os outros japonês alfabetos (Romaji, Katakana e Hiragana) em suas representações Kanji possíveis. Caso haja ambiguidade, você pode selecionar várias alternativas. Quando você tiver selecionado o caractere Kanji pretendido, o IME passa dois `WM_CHAR` mensagens para o aplicativo de controle.  
  
 O IME ativado por ALT +\` combinação de teclas, aparece como um conjunto de botões (um indicador) e uma janela de conversão. O aplicativo posiciona a janela no ponto de inserção de texto. O aplicativo deve tratar `WM_MOVE` e `WM_SIZE` mensagens por reposicionar a janela de conversão de acordo com o novo local ou o tamanho da janela de destino.  
  
 Se você quiser que os usuários do seu aplicativo para ter a capacidade de inserir caracteres de Kanji, o aplicativo deve tratar mensagens de IME do Windows. Para obter mais informações sobre programação de IME, consulte [IME](https://msdn.microsoft.com/en-us/library/ms776145.aspx).  
  
## <a name="visual-c-debugger"></a>Depurador Visual C++  
 O depurador do Visual C++ fornece a capacidade de definir pontos de interrupção em mensagens IME. Além disso, a janela de memória pode exibir caracteres de byte duplo.  
  
## <a name="command-line-tools"></a>Ferramentas de linha de comando  
 As ferramentas de linha de comando do Visual C++, incluindo o compilador NMAKE e o compilador de recurso (RC. EXE), são habilitados para MBCS. Você pode usar a opção de /c do compilador de recurso para alterar a página de código padrão durante a compilação de recursos do aplicativo.  
  
 Para alterar a localidade padrão em tempo de compilação do código fonte, use [#pragma setlocale](../preprocessor/setlocale.md).  
  
## <a name="graphical-tools"></a>Ferramentas gráficas  
 As ferramentas baseadas no Windows do Visual C++, como Spy + + e o recurso de edição de ferramentas, dão suporte total a cadeias de caracteres do IME.  
  
## <a name="see-also"></a>Consulte também  
 [Suporte a conjuntos de caracteres Multibyte (MBCSs)](../text/support-for-multibyte-character-sets-mbcss.md)   
 [Dicas de programação do MBCS](../text/mbcs-programming-tips.md)