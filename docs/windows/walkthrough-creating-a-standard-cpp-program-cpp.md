---
title: "Instru&#231;&#245;es passo a passo: criando um programa de console Win32 (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/15/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
f1_keywords: 
  - "vcfirstapp"
  - "vccreatefirst"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "aplicações de linha de comando [C++], padrão"
  - "aplicativos padrão [C++]"
ms.assetid: 48217e35-d892-46b7-93e3-f6f0b7e2da35
caps.latest.revision: 36
caps.handback.revision: 36
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#245;es passo a passo: criando um programa de console Win32 (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

É possível usar o Visual C\+\+ no ambiente de desenvolvimento integrado do Visual Studio \(IDE\) para criar programas padrão do C\+\+.  Seguindo as etapas nessa explicação passo a passo, você pode criar um projeto, adicionar um novo arquivo ao projeto, modificar o arquivo para adicionar o código do C\+\+ e compilar e executar o programa usando o [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)].  
  
 Você pode digitar seu próprio programa de C\+\+ ou use um dos programas de exemplo.  O programa de exemplo nessa explicação passo a passo é um aplicativo de console.  Esse aplicativo usa o contêiner `set` na Biblioteca de Modelos Padrão \(STL\).  
  
 [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] obedece o padrão C\+\+ 2003, com as seguintes exceções principais: pesquisa de dois estágios de nome, especificações de exceção, e exportação.  Além disso, o [!INCLUDE[vcprvc](../build/includes/vcprvc_md.md)] suporta vários recursos do C\+\+0x, por exemplo, lambdas, automatic, static\_assert, referências de rvalue e modelos extern.  
  
> [!NOTE]
>  Se a conformidade com o padrão é necessária, use a opção de compilador **\/Za** para desativar extensões do Microsoft ao padrão.  Para obter mais informações, consulte [\/Za, \/Ze \(desabilitar extensões de linguagem\)](../build/reference/za-ze-disable-language-extensions.md).  
  
## Pré-requisitos  
 Para concluir esta explicação passo a passo, você deve compreender os fundamentos da linguagem C\+\+.  
  
### Para criar um projeto e adicionar um arquivo de origem  
  
1.  Crie um projeto apontando para **Novo** no menu **Arquivo** e clicando em **Projeto**.  
  
2.  No painel de tipos de projeto **Visual C\+\+**, clique em **Win32** e então clique em **Aplicativo do Console Win32**.  
  
3.  Digite um nome para o projeto.  
  
     Por padrão, a solução que contém o projeto tem o mesmo nome que o projeto, mas você pode digitar um nome diferente.  Você também pode digitar um local diferente para o projeto.  
  
     Clique em **OK** para criar o projeto.  
  
4.  Em **Assistente de Aplicação Win32**, clique em **Avançar**, selecione **Projeto Vazio**,e em seguida clique em **Concluir**.  
  
5.  Se o **Gerenciador de Soluções** não for exibido, clique em **Gerenciador de Soluções** no menu **Exibir**.  
  
6.  Adicione um novo arquivo de origem ao projeto, como segue.  
  
    1.  No **Gerenciador de Soluções**, clique com o botão direito do mouse na pasta **Arquivos de Origem**, aponte para **Adicionar** e em seguida, clique em **Novo Item**.  
  
    2.  No nó **Código**, clique em **Arquivo do C\+\+ \(.cpp\)**, digite um nome para o arquivo e clique em **Adicionar**.  
  
     O arquivo .cpp aparece na pasta Arquivos de Origem do **Gerenciador de Soluções** e o arquivo é aberto no editor do Visual Studio.  
  
7.  No arquivo no editor, digite um programa válido de C\+\+ que use a biblioteca do C\+\+ padrão, ou copie um dos programas exemplares e cole\-o no arquivo.  
  
     Por exemplo, você pode usar o programa de exemplo [set::find](../misc/set-find-stl-samples.md), que é um dos exemplos da Biblioteca de Modelo Padrão que são incluídos na Ajuda.  
  
     Caso você use o programa de exemplo, observe a diretiva `using namespace std;`.  Essa diretiva permite que o programa use `cout` e `endl` sem exigir nomes totalmente qualificados \(`std::cout` e `std::endl`\).  
  
8.  Salve o arquivo.  
  
9. No menu **Compilar**, clique em **Compilar Solução**.  
  
     A janela **Saída** exibe informações sobre o andamento da compilação, por exemplo, o local do log de compilação e uma mensagem que indica o status da compilação.  
  
10. No menu **Depurar**, clique em **Iniciar sem Depuração**.  
  
     Caso você tenha usado o programa de exemplo, uma janela de comando é exibida e mostra se determinados inteiros estão localizados no conjunto.  
  
## Próximas etapas  
 **Anterior:** [Creating Command\-Line Applications \(C\+\+\)](http://msdn.microsoft.com/pt-br/2505d9ed-aca4-426a-9071-078a2d707254).  **Próxima:** [Instruções passo a passo: compilando um programa do C\+\+ nativo na linha de comando](../build/walkthrough-compiling-a-native-cpp-program-on-the-command-line.md).  
  
## Consulte também  
 [Visual C\+\+ Guided Tour](http://msdn.microsoft.com/pt-br/499cb66f-7df1-45d6-8b6b-33d94fd1f17c)   
 [Referência de linguagem C\+\+](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão C\+\+](../standard-library/cpp-standard-library-reference.md)