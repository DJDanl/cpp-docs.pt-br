---
title: Compilando um programa C++ que tem como alvo o CLR | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- command-line applications [C++], managed code
- compiling programs [C++]
- Visual C++, managed code
- managed code [C++]
ms.assetid: 339f89df-a5d2-4040-831a-ddbe25b5dce4
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: eca6960d23c43fbe27d753ab4f79a27dea7bd7e5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="walkthrough-compiling-a-c-program-that-targets-the-clr-in-visual-studio"></a>Instruções passo a passo: compilando um programa C++ que se destina ao CLR no Visual Studio
Você pode criar programas Visual C++ que usam classes do .NET e compilação-los usando o ambiente de desenvolvimento do Visual Studio.  
  
 Para esse procedimento, você pode digitar o seu próprio programa Visual C++ ou use um dos programas de exemplo. O programa de exemplo que usamos neste procedimento cria um arquivo de texto chamado textfile.txt e salva-o para o diretório do projeto.  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Esses tópicos supõem que você entender os conceitos básicos da linguagem C++.  
  
### <a name="to-create-a-new-project-in-visual-studio-and-add-a-new-source-file"></a>Para criar um novo projeto no Visual Studio e adicionar um novo arquivo de origem  
  
1.  Crie um novo projeto. No menu **Arquivo**, aponte para **Novo** e clique em **Projeto**.  
  
2.  Entre os tipos de projeto do Visual C++, clique em **CLR**e, em seguida, clique em **projeto CLR vazio**.  
  
3.  Digite um nome de projeto.  
  
     Por padrão, a solução que contém o projeto tem o mesmo nome que o novo projeto, mas você pode inserir um nome diferente. Se desejar, você pode inserir um local diferente para o projeto.  
  
     Clique em **Okey** para criar o novo projeto.  
  
4.  Se o Gerenciador de soluções não estiver visível, clique em **Solution Explorer** no **exibição** menu.  
  
5.  Adicione um novo arquivo de origem para o projeto:  
  
    -   Clique com botão direito do **arquivos de origem** pasta no Gerenciador de soluções, aponte para **adicionar** e clique em **Novo Item**.  
  
    -   Clique em **C++ arquivo (. cpp)** e digite um nome de arquivo e, em seguida, clique em **adicionar**.  
  
     O **. cpp** arquivo aparece no **arquivos de origem** pasta no Gerenciador de soluções e uma janela com guias aparece onde você digita o código desejado nesse arquivo.  
  
6.  Clique na guia recém-criado no Visual Studio e digite um programa válido do Visual C++, ou copie e cole um dos programas de exemplo.  
  
     Por exemplo, você pode usar o [como: gravar um arquivo de texto (C + + CLI)](../dotnet/how-to-write-a-text-file-cpp-cli.md) programa de exemplo (no **tratamento de arquivos e e/s** nó do guia de programação).  
  
     Se você usar o programa de exemplo, observe que você use o `gcnew` palavra-chave em vez de `new` durante a criação de um objeto .NET e que `gcnew` retorna um identificador (`^`) em vez de um ponteiro (`*`):  
  
     `StreamWriter^ sw = gcnew StreamWriter(fileName);`  
  
     Para obter mais informações sobre a nova sintaxe Visual C++, consulte [extensões de componentes para plataformas de tempo de execução](../windows/component-extensions-for-runtime-platforms.md).  
  
7.  No menu **Compilar**, clique em **Compilar Solução**.  
  
     O **saída** janela exibe informações sobre o progresso da compilação, como o local do log de compilação e uma mensagem que indica o status da compilação.  
  
     Se você fizer alterações e executar o programa sem fazer uma compilação, uma caixa de diálogo pode indicar que o projeto está desatualizado. Selecione a caixa de seleção na caixa de diálogo antes de clicar em **Okey** se desejar que o Visual Studio para sempre usar as versões atuais dos arquivos em vez de solicitar cada vez que ele cria o aplicativo.  
  
8.  Sobre o **depurar** menu, clique em **iniciar sem depuração**.  
  
9. Se você usou o programa de exemplo, quando você executar o programa será exibida uma janela de comando que indica que o arquivo de texto foi criado. Pressione qualquer tecla para fechar a janela de comando.  
  
     O **textfile.txt** arquivo de texto agora está localizado no diretório do projeto. Você pode abrir esse arquivo usando o bloco de notas.  
  
    > [!NOTE]
    >  Escolhendo o CLR vazio o modelo de projeto definida automaticamente o **/clr** opção de compilador. Para verificar isso, clique com botão direito no projeto no **Solution Explorer** e clicando em **propriedades**e, em seguida, verifique o **suporte a Common Language Runtime** opção o  **Geral** nó de **propriedades de configuração**.  
  
## <a name="whats-next"></a>Novidades  
 **Anterior:** [passo a passo: compilando um programa C++ nativo na linha de comando](../build/walkthrough-compiling-a-native-cpp-program-on-the-command-line.md) &#124; **Próximo:**[passo a passo: compilar um programa em C na linha de comando](../build/walkthrough-compile-a-c-program-on-the-command-line.md)  
  
## <a name="see-also"></a>Consulte também  
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Compilando programas do C/C++](../build/building-c-cpp-programs.md)