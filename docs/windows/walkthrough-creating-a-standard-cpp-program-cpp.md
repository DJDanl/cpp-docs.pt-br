---
title: "Passo a passo: Criando um programa padrão do C++ (C++) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: get-started-article
f1_keywords:
- vcfirstapp
- vccreatefirst
dev_langs:
- C++
helpviewer_keywords:
- command-line applications [C++], standard
- standard applications [C++]
ms.assetid: 48217e35-d892-46b7-93e3-f6f0b7e2da35
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 52066be1d67bddb7173841e9df6c5013c86ac0dd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="walkthrough-creating-a-standard-c-program-c"></a>Passo a passo: Criando um programa padrão do C++ (C++)
Você pode usar o Visual C++ no ambiente de desenvolvimento integrado (IDE) do Visual Studio para criar programas C++ padrão. Seguindo as etapas neste passo a passo, você pode criar um projeto, adicione um novo arquivo ao projeto, modifique o arquivo para adicionar o código C++ e, em seguida, compilar e executar o programa usando [!INCLUDE[vsprvs](../assembler/masm/includes/vsprvs_md.md)].  
  
 Você pode digitar o seu próprio programa C++ ou use um dos programas de exemplo. O programa de exemplo neste passo a passo é um aplicativo de console. Este aplicativo usa o `set` contêiner na biblioteca C++ padrão.  
  
 Visual C++ está em conformidade com o padrão de C++ de 2003, com estas exceções principais: pesquisa de nome de dois estágios, especificações de exceção e exportar. Além disso, o Visual C++ dá suporte a vários recursos C + + 0x, por exemplo, lambdas, auto, static_assert, referências a rvalue e modelos externo.  
  
> [!NOTE]
>  Se a conformidade com o padrão é necessária, use o **/Za** opção de compilador desabilitar extensões da Microsoft para o padrão. Para obter mais informações, consulte [/Za, /Ze (desabilitar extensões de linguagem)](../build/reference/za-ze-disable-language-extensions.md).  
  
## <a name="prerequisites"></a>Pré-requisitos  
 Para concluir este passo a passo, você deve compreender os fundamentos da linguagem C++.  
  
### <a name="to-create-a-project-and-add-a-source-file"></a>Para criar um projeto e adicionar um arquivo de origem  
  
1.  Criar um projeto, basta apontar para **novo** no **arquivo** menu e, em seguida, clicando em **projeto**.  
  
2.  No **Visual C++** painel tipos de projeto, clique em **Win32**e, em seguida, clique em **aplicativo do Console Win32**.  
  
3.  Digite um nome para o projeto.  
  
     Por padrão, a solução que contém o projeto tem o mesmo nome que o projeto, mas você pode digitar um nome diferente. Você também pode digitar um local diferente para o projeto.  
  
     Clique em **Okey** para criar o projeto.  
  
4.  No **Assistente de aplicativo Win32**, clique em **próximo**, selecione **projeto vazio**e, em seguida, clique em **concluir**.  
  
5.  Se **Solution Explorer** não for exibido, no **exibição** menu, clique em **Gerenciador de soluções**.  
  
6.  Adicione um novo arquivo de origem para o projeto, da seguinte maneira.  
  
    1.  Em **Solution Explorer**, com o botão direito do **arquivos de origem** pasta, aponte para **adicionar**e, em seguida, clique em **Novo Item**.  
  
    2.  No **código** nó, clique em **C++ arquivo (. cpp)**, digite um nome para o arquivo e, em seguida, clique em **adicionar**.  
  
     O arquivo. cpp aparece na pasta de arquivos de origem em **Solution Explorer**, e o arquivo é aberto no editor do Visual Studio.  
  
7.  No arquivo no editor, digite um programa válido do C++ que usa a biblioteca padrão C++, ou copie um dos programas de exemplo e cole-o no arquivo.  
  
8.  Salve o arquivo.  
  
9. No menu **Compilar**, clique em **Compilar Solução**.  
  
     O **saída** janela exibe informações sobre o progresso da compilação, por exemplo, o local do log de compilação e uma mensagem que indica o status da compilação.  
  
10. Sobre o **depurar** menu, clique em **iniciar sem depuração**.  
  
     Se você usou o programa de exemplo, uma janela de comando é exibida e mostra se determinados inteiros são encontrados no conjunto.  
  
## <a name="next-steps"></a>Próximas etapas  
 **Anterior:** [Console aplicativos em Visual C++](../windows/console-applications-in-visual-cpp.md). **Em seguida:**[passo a passo: compilando um programa C++ nativo na linha de comando](../build/walkthrough-compiling-a-native-cpp-program-on-the-command-line.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)