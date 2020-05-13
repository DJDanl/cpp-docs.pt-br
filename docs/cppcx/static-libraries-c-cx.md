---
title: Bibliotecas estáticas (C++/CX)
ms.date: 02/03/2017
ms.assetid: 7faf53c8-fa21-42cc-8246-d32533ef9dfa
ms.openlocfilehash: 3c4bfd28b805903a2e596ef6d648ff31b0b8261c
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81358104"
---
# <a name="static-libraries-ccx"></a>Bibliotecas estáticas (C++/CX)

Uma biblioteca estática usada em um aplicativo Universal Windows Platform (UWP) pode conter código C++ padrão ISO, incluindo tipos de STL, e também chamadas para APIs Win32 que não são excluídas da plataforma do aplicativo Windows Runtime. Uma biblioteca estática consome componentes do Windows Runtime e pode criar componentes do Windows Runtime com certas restrições.

## <a name="creating-static-libraries"></a>Criando bibliotecas estáticas

As instruções para criar um novo projeto variam dependendo da versão do Visual Studio que você instalou. Para ver a documentação da sua versão preferida do Visual Studio, use o controle do seletor **de versão.** É encontrado no topo da tabela de conteúdo nesta página.

::: moniker range="vs-2019"

### <a name="to-create-a-uwp-static-library-in-visual-studio-2019"></a>Para criar uma biblioteca estática UWP no Visual Studio 2019

1. Na barra de menus, escolha **Arquivo** > **Novo** > **Projeto** para abrir a caixa de diálogo **Criar um novo projeto**.

1. Na parte superior da caixa de diálogo, defina **o Idioma** como **C++**, defina **plataforma** para **Windows**e defina o tipo **de projeto** como **UWP**.

1. Na lista filtrada de tipos de projeto, escolha **Biblioteca Estática (Universal Windows - C++/CX)** e escolha **Next**. Na página seguinte, dê um nome ao projeto e especifique o local do projeto, se desejar.

1. Escolha o botão **Criar** para criar o projeto.

::: moniker-end

::: moniker range="<=vs-2017"

### <a name="to-create-a-uwp-static-library-in-visual-studio-2017-or-visual-studio-2015"></a>Para criar uma biblioteca estática UWP no Visual Studio 2017 ou Visual Studio 2015

1. Na barra de menu, escolha **Arquivo** > **Novo** > **Projeto**. Em **Visual C++** > **Windows Universal** escolha Static Library **(Universal Windows)**.

1. No **Solution Explorer,** abra o menu de atalho para o projeto e escolha **Propriedades**. Na caixa de diálogo **Propriedades,** na página **Propriedades** > de configuração**C/C++,** defina **consumir extensão de tempo de execução do Windows** como Sim **(/ZW)**.

::: moniker-end

Quando você compila uma nova biblioteca estática, se fizer uma chamada para uma API Win32 excluída para aplicativos UWP, o compilador aumentará o erro C3861, "Identificador não encontrado". Para procurar um método alternativo que seja suportado para o Windows Runtime, consulte [Alternativas às APIs do Windows em aplicativos UWP](/uwp/win32-and-com/alternatives-to-windows-apis-uwp).

Se você adicionar um projeto de biblioteca estática C++ a uma solução de aplicativo UWP, você poderá ter que atualizar as configurações de propriedade do projeto da biblioteca para que a propriedade de suporte ao UWP seja definida como **Sim**. Sem essa configuração, o código cria e vincula, mas um erro ocorre quando você tenta verificar o aplicativo para a Microsoft Store. A biblioteca estática deve ser compilada com as mesmas configurações do compilador do projeto que a consome.

Se você consumir uma biblioteca estática que cria classes públicas `ref` , as classes de interface pública ou as classes de valor público, o vinculador gerará este aviso:

> **aviso LNK4264:** arquivamento de arquivo de objeto compilado com /ZW em uma biblioteca estática; observe que ao criar tipos de Tempo de Execução do Windows não é recomendável vincular-se a uma biblioteca estática que contenha metadados do Windows Runtime.

Você só pode ignorar o aviso com segurança se a biblioteca estática não estiver produzindo componentes do Windows Runtime que são consumidos fora da própria biblioteca. Se a biblioteca não consumir um componente que ela definir, o vinculador poderá otimizar a implementação mesmo que os metadados públicos contenham as informações de tipo. Isso significa que os componentes públicos em uma biblioteca estática serão compilados, mas não serão ativados no tempo de execução. Por essa razão, qualquer componente do Windows Runtime destinado ao consumo de outros componentes ou aplicativos deve ser implementado em uma biblioteca de links dinâmicos (DLL).

## <a name="see-also"></a>Confira também

[Threading e Marshaling](../cppcx/threading-and-marshaling-c-cx.md)
