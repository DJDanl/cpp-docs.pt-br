---
title: "Instru&#231;&#245;es passo a passo: compilando um programa C++ que se destina ao CLR no Visual Studio | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "aplicações de linha de comando [C++], código gerenciado"
  - "compilando programas [C++]"
  - "código gerenciado [C++]"
  - "Visual C++, código gerenciado"
ms.assetid: 339f89df-a5d2-4040-831a-ddbe25b5dce4
caps.latest.revision: 40
caps.handback.revision: 40
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: compilando um programa C++ que se destina ao CLR no Visual Studio
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Você pode criar programas do Visual C\+\+ que usam classes do .NET e as criam usando o ambiente de desenvolvimento do Visual Studio.  
  
 Para esse procedimento você pode digitar seu próprio programa Visual C\+\+ ou use um dos programas de exemplo.  O programa de exemplo que usamos neste procedimento é um arquivo de texto denominado textfile.txt e salva\-o no diretório do projeto.  
  
## Pré-requisitos  
 Esses tópicos supõem que você entender os conceitos básicos de linguagem C\+\+.  
  
### Para criar um novo projeto no Visual Studio e adicionar um novo arquivo de origem  
  
1.  Crie um novo projeto.  No menu de **Arquivo** , aponte para **Novo**, e clique em **Projeto…**.  
  
2.  Tipos de projeto do Visual C\+\+, clique em **CLR**, e clique em **Projeto CLR Vazio**.  
  
3.  Digite um nome para o projeto.  
  
     Por padrão, a solução que contém o projeto a mesma o mesmo nome que o novo projeto do, mas pode digitar um nome diferente.  Você pode entrar em um local diferente para o projeto se você deseja.  
  
     Clique em **OK** para criar o novo projeto.  
  
4.  Se Solution Explorer não estiver visível, clique em **Gerenciador de Soluções** no menu de **Exibir** .  
  
5.  Adicionar um novo arquivo de origem ao projeto:  
  
    -   Clique com o botão direito do mouse na pasta de **Arquivos de Origem** no Solution Explorer, aponte para e clique **AdicionarNovo item…**.  
  
    -   Clique **C\+\+ \(Arquivo .cpp\)** e digite um nome de arquivo e clique em **Adicionar**.  
  
     O arquivo de **.cpp** aparece na pasta de **Arquivos de Origem** no Solution Explorer e uma janela com guias aparece onde você digita o código que você deseja nesse arquivo.  
  
6.  Clique na guia recém\-criado no Visual Studio e digite um programa válida do Visual C\+\+, ou copie e cole um dos programas de exemplo.  
  
     Por exemplo, você pode usar o programa de exemplo de [Como escrever um arquivo de texto](../Topic/How%20to:%20Write%20a%20Text%20File%20\(C++-CLI\).md) \(no nó de **Arquivo a manipulação e o E\/S** da guia de programação\).  
  
     Se você usar o programa de exemplo, observe que você usa a palavra\-chave de `gcnew`em vez de `new` ao criar um objeto do .NET, e que `gcnew` retorna um identificador \(`^`\) ao invés de um ponteiro \(`*`\):  
  
     `StreamWriter^ sw = gcnew StreamWriter(fileName);`  
  
     Para obter mais informações sobre a nova sintaxe do Visual C\+\+, consulte [Component Extensions for Runtime Platforms](../windows/component-extensions-for-runtime-platforms.md).  
  
7.  No menu **Compilar**, clique em **Compilar Solução**.  
  
     Exibe informações da janela de **Saída** sobre o progresso da compilação, como o local do log de compilação e uma mensagem que indica o status de compilação.  
  
     Se você fizer alterações e executa o programa sem fazer uma construção, uma caixa de diálogo pode indicar que o projeto estiver expirado.  Marque a caixa de seleção nesta caixa de diálogo antes de clicar em **OK** se você quiser que o Visual Studio para usar sempre as versões atuais dos arquivos em vez de acesso de cada vez que cria o aplicativo.  
  
8.  No menu **Depurar**, clique em **Iniciar sem Depuração**.  
  
9. Se você usou o programa de exemplo, quando você executa o programa uma janela de comando será exibida que indica que o arquivo de texto esteve criado.  Pressione qualquer tecla para fechar a janela de comando.  
  
     O arquivo de texto de **textfile.txt** agora está localizado no diretório do projeto.  Você pode abrir o arquivo usando o Bloco De Notas.  
  
    > [!NOTE]
    >  Escolhendo CLR vazia modelo de projeto define automaticamente a opção do compilador de **\/clr** .  Para verificar isso, clique com o botão direito do mouse em **Gerenciador de Soluções** e clique em **Propriedades**, e verifique a opção de **Suporte a Common Language Runtime** no nó de **Geral** de **Propriedades de Configuração**.  
  
## O Que Mais Há  
 **Anterior:** [Instruções passo a passo: compilando um programa do C\+\+ nativo na linha de comando](../build/walkthrough-compiling-a-native-cpp-program-on-the-command-line.md) &#124; **Próxima:** [Instruções passo a passo: compilando um programa em C na linha de comando](../Topic/Walkthrough:%20Compiling%20a%20C%20Program%20on%20the%20Command%20Line.md)  
  
## Consulte também  
 [Visual C\+\+ Guided Tour](http://msdn.microsoft.com/pt-br/499cb66f-7df1-45d6-8b6b-33d94fd1f17c)   
 [Referência de linguagem C\+\+](../cpp/cpp-language-reference.md)   
 [Compilando programas do C\/C\+\+](../build/building-c-cpp-programs.md)