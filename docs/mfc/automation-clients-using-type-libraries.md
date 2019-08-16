---
title: 'Clientes de automação: Usando bibliotecas de tipos'
ms.date: 11/04/2016
f1_keywords:
- MkTypLib
helpviewer_keywords:
- clients, Automation
- dispatch class [MFC]
- Automation clients, type libraries
- type libraries, Automation clients
- ODL (Object Description Language)
- ODL files
- classes [MFC], dispatch
- MkTypLib tool
- .odl files
ms.assetid: d405bc47-118d-4786-b371-920d035b2047
ms.openlocfilehash: 480f8fca46b13d445f372311ed837475c71a1e9d
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69509226"
---
# <a name="automation-clients-using-type-libraries"></a>Clientes de automação: Usando bibliotecas de tipos

Os clientes de automação devem ter informações sobre propriedades e métodos de objetos de servidor se os clientes forem manipular os objetos dos servidores. As propriedades têm tipos de dados; os métodos geralmente retornam valores e aceitam parâmetros. O cliente requer informações sobre os tipos de dados de todos eles para se associar estaticamente ao tipo de objeto de servidor.

Essas informações de tipo podem ser conhecidas de várias maneiras. A maneira recomendada é criar uma biblioteca de tipos.

Para obter informações sobre o [MkTypLib](/windows/win32/Midl/differences-between-midl-and-mktyplib), consulte a SDK do Windows.

O C++ visual pode ler um arquivo de biblioteca de tipos e criar uma classe de expedição derivada de [COleDispatchDriver](../mfc/reference/coledispatchdriver-class.md). Um objeto dessa classe tem propriedades e operações que duplicam as do objeto de servidor. Seu aplicativo chama as propriedades e as operações desse objeto e a funcionalidade herdada das `COleDispatchDriver` rotas que essas chamadas para o sistema OLE, que, por sua vez, as roteia para o objeto Server.

O C++ Visual mantém automaticamente esse arquivo de biblioteca de tipos para você se você optar por incluir a automação quando o projeto foi criado. Como parte de cada compilação, o arquivo. tlb será criado com MkTypLib.

### <a name="to-create-a-dispatch-class-from-a-type-library-tlb-file"></a>Para criar uma classe de expedição a partir de um arquivo de biblioteca de tipos (. tlb)

1. No Modo de Exibição de Classe ou Gerenciador de Soluções, clique com o botão direito do mouse no projeto e clique em **Adicionar** e em **Adicionar classe** no menu de atalho.

1. Na caixa de diálogo **Adicionar classe** , selecione a **pasta C++visual/MFC** no painel esquerdo. Selecione a **classe MFC no** ícone de typelib no painel direito e clique em **abrir**.

1. Na caixa de diálogo **Adicionar classe do assistente de typelib** , selecione uma biblioteca de tipos na lista suspensa **bibliotecas de tipos disponíveis** . A caixa **interfaces** exibe as interfaces disponíveis para a biblioteca de tipos selecionada.

    > [!NOTE]
    >  Você pode selecionar interfaces de mais de uma biblioteca de tipos.

   Para selecionar interfaces, clique duas vezes nelas ou clique no botão **Adicionar** . Quando você fizer isso, os nomes das classes de expedição serão exibidos na caixa **classes geradas** . Você pode editar os nomes de classe na `Class` caixa.

   A caixa **arquivo** exibe o arquivo no qual a classe será declarada. (você também pode editar esse nome de arquivo). Você também pode usar o botão procurar para selecionar outros arquivos, se preferir ter as informações de cabeçalho e de implementação gravadas em arquivos existentes ou em um diretório diferente do diretório do projeto.

    > [!NOTE]
    >  Todas as classes de expedição para as interfaces selecionadas serão colocadas no arquivo especificado aqui. Se desejar que as interfaces sejam declaradas em cabeçalhos separados, você deverá executar esse assistente para cada arquivo de cabeçalho que deseja criar.

    > [!NOTE]
    >  Algumas informações de biblioteca de tipos podem ser armazenadas em arquivos com. DLL,. OCX ou. Extensões de arquivo OLB.

1. Clique em **Finalizar**.

   O assistente gravará o código para suas classes de expedição usando os nomes de arquivo e de classe especificados.

## <a name="see-also"></a>Consulte também

[Clientes de automação](../mfc/automation-clients.md)
