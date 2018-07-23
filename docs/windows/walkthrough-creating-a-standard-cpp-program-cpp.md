---
title: 'Passo a passo: Criando um programa padrão do C++ (C++) | Microsoft Docs'
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
f1_keywords:
- vcfirstapp
- vccreatefirst
dev_langs:
- C++
helpviewer_keywords:
- command-line applications [C++], standard
- standard applications [C++]
ms.assetid: 48217e35-d892-46b7-93e3-f6f0b7e2da35
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: ac1fac3c7f96c9f8d718efa54810f4155b1ddac5
ms.sourcegitcommit: c0ffdff538eb961f786809eb547b35846190ee48
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/05/2018
ms.locfileid: "34800080"
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
  
2.  No **Visual C++** painel tipos de projeto, clique em **Windows Desktop**e, em seguida, clique em **aplicativo de Console do Windows**.  
  
3.  Digite um nome para o projeto.  
  
     Por padrão, a solução que contém o projeto tem o mesmo nome que o projeto, mas você pode digitar um nome diferente. Você também pode digitar um local diferente para o projeto.  
  
     Clique em **OK** para criar o projeto.  
  
4.  Se **Solution Explorer** não for exibido, no **exibição** menu, clique em **Gerenciador de soluções**.  
  
5.  Adicione um novo arquivo de origem para o projeto, da seguinte maneira.  
  
    1.  Em **Solution Explorer**, com o botão direito do **arquivos de origem** pasta, aponte para **adicionar**e, em seguida, clique em **Novo Item**.  
  
    2.  No **código** nó, clique em **C++ arquivo (. cpp)**, digite um nome para o arquivo e, em seguida, clique em **adicionar**.  
  
     O arquivo. cpp aparece na pasta de arquivos de origem em **Solution Explorer**, e o arquivo é aberto no editor do Visual Studio.  
  
6.  No arquivo no editor, digite um programa válido do C++ que usa a biblioteca padrão C++, ou copie um dos programas de exemplo e cole-o no arquivo.  
  
7.  Salve o arquivo.  
  
8. No menu **Compilar**, clique em **Compilar Solução**.  
  
     O **saída** janela exibe informações sobre o progresso da compilação, por exemplo, o local do log de compilação e uma mensagem que indica o status da compilação.  
  
9. Sobre o **depurar** menu, clique em **iniciar sem depuração**.  
  
     Se você usou o programa de exemplo, uma janela de comando é exibida e mostra se determinados inteiros são encontrados no conjunto.  
  
## <a name="next-steps"></a>Próximas etapas  
 **Anterior:** [Console aplicativos em Visual C++](../windows/console-applications-in-visual-cpp.md). **Em seguida:**[passo a passo: compilando um programa C++ nativo na linha de comando](../build/walkthrough-compiling-a-native-cpp-program-on-the-command-line.md).  
  
## <a name="see-also"></a>Consulte também  
 [Referência da linguagem C++](../cpp/cpp-language-reference.md)   
 [Biblioteca Padrão do C++](../standard-library/cpp-standard-library-reference.md)
