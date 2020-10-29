---
title: Bibliotecas estáticas (C++/CX)
ms.date: 02/03/2017
ms.assetid: 7faf53c8-fa21-42cc-8246-d32533ef9dfa
ms.openlocfilehash: 756f8d2c1af2c6be414ad39b4a96fa6cc7ccfb02
ms.sourcegitcommit: 9c2b3df9b837879cd17932ae9f61cdd142078260
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/29/2020
ms.locfileid: "92924711"
---
# <a name="static-libraries-ccx"></a>Bibliotecas estáticas (C++/CX)

Uma biblioteca estática que é usada em um aplicativo Plataforma Universal do Windows (UWP) pode conter código C++ padrão ISO, incluindo tipos STL, e também chamadas para APIs do Win32 que não são excluídas da plataforma Windows Runtime aplicativo. Uma biblioteca estática consome componentes Windows Runtime e pode criar Windows Runtime componentes com determinadas restrições.

## <a name="creating-static-libraries"></a>Criando bibliotecas estáticas

As instruções para criar um novo projeto variam de acordo com a versão do Visual Studio instalada. Para ver a documentação da sua versão preferida do Visual Studio, use o controle seletor de **versão** . Ele é encontrado na parte superior do Sumário nesta página.

::: moniker range="msvc-160"

### <a name="to-create-a-uwp-static-library-in-visual-studio-2019"></a>Para criar uma biblioteca estática UWP no Visual Studio 2019

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um novo projeto** .

1. Na parte superior da caixa de diálogo, defina  **idioma** como **C++** , **defina plataforma** para **Windows** e defina **tipo de projeto** como **UWP** .

1. Na lista filtrada de tipos de projeto, escolha **biblioteca estática (universal do Windows-C++/CX)** e, em seguida, escolha **Avançar** . Na próxima página, dê um nome ao projeto e especifique o local do projeto, se desejado.

1. Escolha o botão **Criar** para criar o projeto.

::: moniker-end

::: moniker range="<=msvc-150"

### <a name="to-create-a-uwp-static-library-in-visual-studio-2017-or-visual-studio-2015"></a>Para criar uma biblioteca estática UWP no Visual Studio 2017 ou no Visual Studio 2015

1. Na barra de menus, escolha **arquivo**  >  **novo**  >  **projeto** . Em **Visual C++**  >  **Windows universal** , escolha **biblioteca estática (universal do Windows)** .

1. No **Gerenciador de soluções** , abra o menu de atalho do projeto e, em seguida, escolha **Propriedades** . Na caixa de diálogo **Propriedades** , na página **Propriedades de configuração**  >  **C/C++** , defina **consumir Windows Runtime extensão** como **Sim (/ZW)** .

::: moniker-end

Quando você compila uma nova biblioteca estática, se fizer uma chamada para uma API do Win32 que é excluída para aplicativos UWP, o compilador gerará o erro C3861, "identificador não encontrado". Para procurar um método alternativo com suporte para o Windows Runtime, consulte [alternativas para APIs do Windows em aplicativos UWP](/uwp/win32-and-com/alternatives-to-windows-apis-uwp).

Se você adicionar um projeto de biblioteca estática C++ a uma solução de aplicativo UWP, talvez seja necessário atualizar as configurações de Propriedade do projeto de biblioteca para que a propriedade de suporte UWP seja definida como **Sim** . Sem essa configuração, o código cria e vincula, mas ocorre um erro quando você tenta verificar o aplicativo para o Microsoft Store. A biblioteca estática deve ser compilada com as mesmas configurações do compilador do projeto que a consome.

Se você consumir uma biblioteca estática que cria classes públicas `ref` , as classes de interface pública ou as classes de valor público, o vinculador gerará este aviso:

> **aviso LNK4264:** arquivo de objeto de arquivamento compilado com/zw em uma biblioteca estática; Observe que, ao criar Windows Runtime tipos, não é recomendável vincular a uma biblioteca estática que contenha Windows Runtime metadados.

Você pode ignorar o aviso com segurança apenas se a biblioteca estática não estiver produzindo Windows Runtime componentes consumidos fora da própria biblioteca. Se a biblioteca não consumir um componente que ela definir, o vinculador poderá otimizar a implementação mesmo que os metadados públicos contenham as informações de tipo. Isso significa que os componentes públicos em uma biblioteca estática serão compilados, mas não serão ativados no tempo de execução. Por esse motivo, qualquer componente Windows Runtime destinado ao consumo por outros componentes ou aplicativos deve ser implementado em uma DLL (biblioteca de vínculo dinâmico).

## <a name="see-also"></a>Veja também

[Threading e marshaling](../cppcx/threading-and-marshaling-c-cx.md)
