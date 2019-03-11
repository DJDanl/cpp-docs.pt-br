---
title: Bibliotecas estáticas (C++/CX)
ms.date: 02/03/2017
ms.assetid: 7faf53c8-fa21-42cc-8246-d32533ef9dfa
ms.openlocfilehash: 242ba10b29a8efe0c3e9580f1d0d0c3be529a7d2
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57738938"
---
# <a name="static-libraries-ccx"></a>Bibliotecas estáticas (C++/CX)

Uma biblioteca estática que é usada em um aplicativo da plataforma Universal do Windows (UWP) pode conter código de C++ padrão ISO, incluindo tipos STL e chamadas para APIs do Win32 que não são excluídas da plataforma de aplicativos do tempo de execução do Windows. Uma biblioteca estática consome componentes de tempo de execução do Windows e pode criar componentes de tempo de execução do Windows com algumas restrições.

## <a name="creating-static-libraries"></a>Criando bibliotecas estáticas

#### <a name="to-create-a-static-library-for-use-in-a-uwp-app"></a>Para criar uma biblioteca estática para uso em um aplicativo UWP

1. Na barra de menus, selecione **Arquivo** > **Novo** > **Projeto**. Sob **Visual C++** > **Windows Universal** escolha **biblioteca estática (Universal Windows)**.

1. No **Gerenciador de Soluções**, abra o menu de atalho para o projeto e escolha **Propriedades**. No **propriedades** caixa de diálogo do **propriedades de configuração** > **C/C++** , defina **consumir uma extensão de tempo de execução do Windows** ao **Sim (/ZW)**.

Quando você compila uma nova biblioteca estática, se você fizer uma chamada para a API do Win32 que foi excluída para aplicativos UWP, o compilador gerará o erro c3861: "Identificador não encontrado". Para procurar um método alternativo que tem suporte para o tempo de execução do Windows, consulte [alternativas para APIs do Windows em aplicativos UWP](/uwp/win32-and-com/alternatives-to-windows-apis-uwp).

Se você adicionar um projeto de biblioteca estática C++ em uma solução de aplicativo UWP, você talvez precise atualizar configurações de propriedade do projeto de biblioteca para que a propriedade de suporte da UWP é definida como **Sim**. Sem essa configuração, compila o código e links, mas um erro ocorre quando você tenta verificar o aplicativo para a Microsoft Store. A biblioteca estática deve ser compilada com as mesmas configurações do compilador do projeto que a consome.

Se você consumir uma biblioteca estática que cria classes públicas `ref` , as classes de interface pública ou as classes de valor público, o vinculador gerará este aviso:

> **Warning LNK4264:** arquivamento do arquivo de objeto compilado com /ZW em uma biblioteca estática; Observe que ao criar tipos de tempo de execução do Windows-não é recomendável vincular a uma biblioteca estática que contém metadados de tempo de execução do Windows.

Você pode ignorar com segurança o aviso somente se a biblioteca estática não estiver produzindo componentes de tempo de execução do Windows que são consumidos fora da própria biblioteca. Se a biblioteca não consumir um componente que ela definir, o vinculador poderá otimizar a implementação mesmo que os metadados públicos contenham as informações de tipo. Isso significa que os componentes públicos em uma biblioteca estática serão compilados, mas não serão ativados no tempo de execução. Por esse motivo, qualquer componente de tempo de execução do Windows que é destinado ao consumo por outros componentes ou aplicativos deve ser implementada em uma biblioteca de vínculo dinâmico (DLL).

## <a name="see-also"></a>Consulte também

[Threading e Marshaling](../cppcx/threading-and-marshaling-c-cx.md)
