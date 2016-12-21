---
title: "Suporte de MBCS no Visual C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "_mbcs"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Idiomas asiáticos [C++]"
  - "conjunto de caracteres [C++], multibyte"
  - "Caracteres chineses [C++]"
  - "Editor de Código [C++], Suporte MBCS"
  - "depurador [C++], Suporte MBCS"
  - "conjuntos de caracteres de bytes [C++]"
  - "IME [C++]"
  - "IME [C++], MBCS"
  - "IME [C++]"
  - "IME [C++], MBCS"
  - "Caracteres japoneses [C++]"
  - "Suporte a caracteres de Kanji [C++]"
  - "MBCS [C++], ativando"
  - "caracteres multibyte [C++]"
  - "programa NMAKE, Suporte MBCS"
  - "editores de recursos [C++], Suporte MBCS"
  - "ferramentas [C++], Suporte MBCS"
ms.assetid: 6179f6b7-bc61-4a48-9267-fb7951223e38
caps.latest.revision: 7
caps.handback.revision: 7
author: "ghogen"
ms.author: "ghogen"
manager: "ghogen"
---
# Suporte de MBCS no Visual C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando executado em uma versão MBCS\- habilitada do sistema operacional Windows 2000 ou Windows XP, o sistema de desenvolvimento do Visual C\+\+ \(que inclui o editor de origem, o depurador, e as ferramentas integradas de linha de comando\) MBCS\- estiver habilitado, com exceção da janela de memória.  
  
 A janela de memória não interpreta bytes de dados como caracteres de MBCS, mesmo que pode interpretar como os caracteres ANSI ou Unicode.  Os caracteres ANSI é sempre 1 bytes de tamanho e os caracteres Unicode são 2 bytes de tamanho.  Com o MBCS, os caracteres podem ter 1 ou 2 bytes de tamanho e a interpretação dependem da página de código está em uso.  Por isso, é difícil para exibir a janela de memória de caracteres de MBCS.  A janela de memória não pode saber quais byte é o início de um caractere.  O desenvolvedor pode exibir os valores de bytes na janela de memória e pesquisar o valor nas tabelas para determinar a representação de caractere.  Isso é possível porque o desenvolvedor souber o endereço inicial de uma cadeia de caracteres com base no código\-fonte.  
  
 Visual C\+\+ aceita caracteres de dois bytes sempre que é apropriado fazer isso.  Isso inclui nomes e nomes de arquivo de caminho em caixas de diálogo e nas entradas de texto no editor de recursos do Visual C\+\+ \(por exemplo, um texto estático no publicador da caixa de diálogo e as entradas de texto estático no publicador do ícone\).  Além disso, o reconhece pré\-processador algumas políticas de byte duplo — por exemplo, nomes de arquivos em instruções de `#include` , e como argumentos para pragmas de **code\_seg** e de **data\_seg** .  No editor de origem, os caracteres de dois bytes em comentários e os literais são aceitos, embora não em elementos de linguagem C\/C\+\+ \(como nomes de variável\).  
  
##  <a name="_core_support_for_the_input_method_editor_.28.ime.29"></a> Suporte para o publicador \(IME\) do método de entrada  
 Aplicativos escritos para os mercados do leste asiático que usam o suporte de MBCS \(por exemplo, Japão\) normalmente as janelas IME para o logon único e caracteres de dois bytes.  O ambiente de desenvolvimento do Visual C\+\+ contém o suporte para a IME.  Para obter mais informações, consulte [Exemplo de IME: Demonstra como controlar o modo de IME e implementar o nível 3 de IME](http://msdn.microsoft.com/pt-br/87ebdf65-cef0-451d-a6fc-d5fb64178b14).  
  
 Os teclados japoneses não dão suporte diretamente de caracteres Kanji.  O IME converte uma cadeia de caracteres fonética, inserida em um dos outros alfabetos Romaji Katakana japoneses \(, ou\) Hiragana em suas representações possíveis de Kanji.  Se houver uma ambiguidade, você pode selecionar várias de backup.  Quando você selecionou o caractere de Kanji pretendido, o IME passa duas mensagens de `WM_CHAR` ao aplicativo de controle.  
  
 O IME, ativado pela combinação de teclas \`de ALT\+, aparece como um conjunto de botões \(\) um indicador e uma janela de conversão.  O aplicativo coloca a janela no ponto de inserção de texto.  O aplicativo deve tratar `WM_MOVE` e mensagens de `WM_SIZE` reposicionando a janela de conversão pelo novo local ou tamanho da janela de destino.  
  
 Se você desejar que os usuários de seu aplicativo ter a capacidade de inserir caracteres de Kanji, o aplicativo deve tratar mensagens do windows IME.  Para obter mais informações sobre a programação de IME, consulte [Editor do método de entrada](https://msdn.microsoft.com/en-us/library/ms776145.aspx).  
  
## Depurador do Visual C\+\+  
 O depurador do Visual C\+\+ fornece a capacidade de definir pontos de interrupção em mensagens de IME.  Além disso, a janela de memória pode exibir caracteres de dois bytes.  
  
## Ferramentas de linha de comando  
 As ferramentas de linha de comando do Visual C\+\+, incluindo o compilador, NMAKE, e o compilador de recursos \(RC.EXE\), MBCS\- são habilitadas.  Você pode usar a opção \/c do compilador de recursos alterar a página de código padrão durante a criação dos recursos do seu aplicativo.  
  
 Para alterar a localidade padrão em tempo de compilação do código\-fonte, use [setlocale de \#pragma](../preprocessor/setlocale.md).  
  
## Ferramentas gráficas  
 As ferramentas baseados no Windows do Visual C\+\+, como Spy\+\+ e as ferramentas de edição de recursos, dão suporte total a cadeias de caracteres de IME.  
  
## Consulte também  
 [Suporte para Conjuntos de Caracteres Multibyte \(MBCSs\)](../text/support-for-multibyte-character-sets-mbcss.md)   
 [Dicas de programação MBCS](../Topic/MBCS%20Programming%20Tips.md)