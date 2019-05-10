---
title: Bibliotecas estáticas (C++/CX)
ms.date: 02/03/2017
ms.assetid: 7faf53c8-fa21-42cc-8246-d32533ef9dfa
ms.openlocfilehash: 188ba06518bf6cdd154b7d6bd61216ed1e4ffad3
ms.sourcegitcommit: 18d3b1e9cdb4fc3a76f7a650c31994bdbd2bde64
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/29/2019
ms.locfileid: "64877249"
---
# <a name="static-libraries-ccx"></a>Bibliotecas estáticas (C++/CX)

Uma biblioteca estática que é usada em um aplicativo da plataforma Universal do Windows (UWP) pode conter código de C++ padrão ISO, incluindo tipos STL e chamadas para APIs do Win32 que não são excluídas da plataforma de aplicativos do tempo de execução do Windows. Uma biblioteca estática consome componentes de tempo de execução do Windows e pode criar componentes de tempo de execução do Windows com algumas restrições.

## <a name="creating-static-libraries"></a>Criando bibliotecas estáticas


Instruções para criar um novo projeto variam, dependendo de qual versão do Visual Studio que você instalou. Verifique se que você tem o seletor de versão no canto superior esquerdo definido para a versão correta.

::: moniker range="vs-2019"

### <a name="to-create-a-uwp-static-library-in-visual-studio-2019"></a>Para criar uma biblioteca estática da UWP no Visual Studio de 2019

1. Na barra de menus, escolha **arquivo** > **New** > **projeto** para abrir o **criar um novo projeto** caixa de diálogo.

1. Na parte superior da caixa de diálogo, defina **linguagem** à **C++**, defina **plataforma** para **Windows**e defina **tipodeprojeto** ao **UWP**. 

1. Na lista filtrada de tipos de projeto, escolha **biblioteca estática (Universal Windows - C++/CX)** , em seguida, escolha **próxima**. Na próxima página, dê um nome ao projeto e especifique o local do projeto, se desejado.

1. Escolha o **criar** botão para criar o projeto.

::: moniker-end

::: moniker range="<=vs-2017"

### <a name="to-create-a-uwp-static-library-in-visual-studio-2017-or-visual-studio-2015"></a>Para criar uma biblioteca estática da UWP no Visual Studio 2017 ou Visual Studio 2015

1. Na barra de menus, selecione **Arquivo** > **Novo** > **Projeto**. Sob **Visual C++** > **Windows Universal** escolha **biblioteca estática (Universal Windows)**.

1. No **Gerenciador de Soluções**, abra o menu de atalho para o projeto e escolha **Propriedades**. No **propriedades** caixa de diálogo do **propriedades de configuração** > **C/C++** , defina **consumir uma extensão de tempo de execução do Windows** ao **Sim (/ZW)**.

::: moniker-end

Quando você compila uma nova biblioteca estática, se você fizer uma chamada para a API do Win32 que foi excluída para aplicativos UWP, o compilador gerará o erro c3861: "Identificador não encontrado". Para procurar um método alternativo que tem suporte para o tempo de execução do Windows, consulte [alternativas para APIs do Windows em aplicativos UWP](/uwp/win32-and-com/alternatives-to-windows-apis-uwp).

Se você adicionar um projeto de biblioteca estática C++ em uma solução de aplicativo UWP, você talvez precise atualizar configurações de propriedade do projeto de biblioteca para que a propriedade de suporte da UWP é definida como **Sim**. Sem essa configuração, compila o código e links, mas um erro ocorre quando você tenta verificar o aplicativo para a Microsoft Store. A biblioteca estática deve ser compilada com as mesmas configurações do compilador do projeto que a consome.

Se você consumir uma biblioteca estática que cria classes públicas `ref` , as classes de interface pública ou as classes de valor público, o vinculador gerará este aviso:

> **Warning LNK4264:** arquivamento do arquivo de objeto compilado com /ZW em uma biblioteca estática; Observe que ao criar tipos de tempo de execução do Windows-não é recomendável vincular a uma biblioteca estática que contém metadados de tempo de execução do Windows.

Você pode ignorar com segurança o aviso somente se a biblioteca estática não estiver produzindo componentes de tempo de execução do Windows que são consumidos fora da própria biblioteca. Se a biblioteca não consumir um componente que ela definir, o vinculador poderá otimizar a implementação mesmo que os metadados públicos contenham as informações de tipo. Isso significa que os componentes públicos em uma biblioteca estática serão compilados, mas não serão ativados no tempo de execução. Por esse motivo, qualquer componente de tempo de execução do Windows que é destinado ao consumo por outros componentes ou aplicativos deve ser implementada em uma biblioteca de vínculo dinâmico (DLL).

## <a name="see-also"></a>Consulte também

[Threading e Marshaling](../cppcx/threading-and-marshaling-c-cx.md)
