---
title: Bibliotecas estáticas (C++/CX)
ms.date: 02/03/2017
ms.assetid: 7faf53c8-fa21-42cc-8246-d32533ef9dfa
ms.openlocfilehash: f62ef03cfdf2f424fd4a50c2e866d73b5bdce7fc
ms.sourcegitcommit: 069e3833bd821e7d64f5c98d0ea41fc0c5d22e53
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/21/2019
ms.locfileid: "74302947"
---
# <a name="static-libraries-ccx"></a>Bibliotecas estáticas (C++/CX)

Uma biblioteca estática que é usada em um aplicativo de Plataforma Universal do Windows (UWP) pode conter código ISO C++ -Standard, incluindo tipos STL, e também chamadas para APIs Win32 que não são excluídas da plataforma Windows Runtime aplicativo. Uma biblioteca estática consome componentes Windows Runtime e pode criar Windows Runtime componentes com determinadas restrições.

## <a name="creating-static-libraries"></a>Criando bibliotecas estáticas


As instruções para criar um novo projeto variam de acordo com a versão do Visual Studio instalada. Verifique se você tem o seletor de versão no canto superior esquerdo definido como a versão correta.

::: moniker range="vs-2019"

### <a name="to-create-a-uwp-static-library-in-visual-studio-2019"></a>Para criar uma biblioteca estática UWP no Visual Studio 2019

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um novo projeto**.

1. Na parte superior da caixa de diálogo, defina idioma **C++** como, defina **plataforma** para **Windows**e defina **tipo de projeto** como **UWP**. 

1. Na lista filtrada de tipos de projeto, escolha **biblioteca estática (universal do C++Windows-/CX)** e escolha **Avançar**. Na próxima página, dê um nome ao projeto e especifique o local do projeto, se desejado.

1. Escolha o botão **Criar** para criar o projeto.

::: moniker-end

::: moniker range="<=vs-2017"

### <a name="to-create-a-uwp-static-library-in-visual-studio-2017-or-visual-studio-2015"></a>Para criar uma biblioteca estática UWP no Visual Studio 2017 ou no Visual Studio 2015

1. Na barra de menus, selecione **Arquivo** > **Novo** > **Projeto**. Em **Visual C++**  > **Windows universal** , escolha **biblioteca estática (universal do Windows)** .

1. No **Gerenciador de Soluções**, abra o menu de atalho para o projeto e escolha **Propriedades**. Na caixa de diálogo **Propriedades** , na página **Propriedades de configuração** > **CC++ /** , defina a **extensão consumir Windows Runtime** como **Sim (/ZW)** .

::: moniker-end

Quando você compila uma nova biblioteca estática, se fizer uma chamada para uma API do Win32 que é excluída para aplicativos UWP, o compilador gerará o erro C3861, "identificador não encontrado". Para procurar um método alternativo com suporte para o Windows Runtime, consulte [alternativas para APIs do Windows em aplicativos UWP](/uwp/win32-and-com/alternatives-to-windows-apis-uwp).

Se você adicionar um C++ projeto de biblioteca estática a uma solução de aplicativo UWP, talvez seja necessário atualizar as configurações de Propriedade do projeto de biblioteca para que a propriedade de suporte UWP seja definida como **Sim**. Sem essa configuração, o código cria e vincula, mas ocorre um erro quando você tenta verificar o aplicativo para o Microsoft Store. A biblioteca estática deve ser compilada com as mesmas configurações do compilador do projeto que a consome.

Se você consumir uma biblioteca estática que cria classes públicas `ref` , as classes de interface pública ou as classes de valor público, o vinculador gerará este aviso:

> **aviso LNK4264:** arquivo de objeto de arquivamento compilado com/zw em uma biblioteca estática; Observe que, ao criar Windows Runtime tipos, não é recomendável vincular a uma biblioteca estática que contenha Windows Runtime metadados.

Você pode ignorar o aviso com segurança apenas se a biblioteca estática não estiver produzindo Windows Runtime componentes consumidos fora da própria biblioteca. Se a biblioteca não consumir um componente que ela definir, o vinculador poderá otimizar a implementação mesmo que os metadados públicos contenham as informações de tipo. Isso significa que os componentes públicos em uma biblioteca estática serão compilados, mas não serão ativados no tempo de execução. Por esse motivo, qualquer componente Windows Runtime destinado ao consumo por outros componentes ou aplicativos deve ser implementado em uma DLL (biblioteca de vínculo dinâmico).

## <a name="see-also"></a>Consulte também

[Threading e Marshaling](../cppcx/threading-and-marshaling-c-cx.md)
