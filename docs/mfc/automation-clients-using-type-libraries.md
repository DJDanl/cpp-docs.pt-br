---
title: 'Clientes de automação: usando bibliotecas de tipo'
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
ms.openlocfilehash: e5f9ffcebc3725851c599e7b21369f45d0029d81
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84626096"
---
# <a name="automation-clients-using-type-libraries"></a>Clientes de automação: usando bibliotecas de tipo

Os clientes de automação devem ter informações sobre propriedades e métodos de objetos de servidor se os clientes forem manipular os objetos dos servidores. As propriedades têm tipos de dados; os métodos geralmente retornam valores e aceitam parâmetros. O cliente requer informações sobre os tipos de dados de todos eles para se associar estaticamente ao tipo de objeto de servidor.

Essas informações de tipo podem ser conhecidas de várias maneiras. A maneira recomendada é criar uma biblioteca de tipos.

Para obter informações sobre o [MkTypLib](/windows/win32/Midl/differences-between-midl-and-mktyplib), consulte a SDK do Windows.

Visual C++ pode ler um arquivo de biblioteca de tipos e criar uma classe de expedição derivada de [COleDispatchDriver](reference/coledispatchdriver-class.md). Um objeto dessa classe tem propriedades e operações que duplicam as do objeto de servidor. Seu aplicativo chama as propriedades e as operações desse objeto e a funcionalidade herdada das `COleDispatchDriver` rotas que essas chamadas para o sistema OLE, que, por sua vez, as roteia para o objeto Server.

Visual C++ mantém automaticamente esse arquivo de biblioteca de tipos para você se você optar por incluir a automação quando o projeto foi criado. Como parte de cada compilação, o arquivo. tlb será criado com MkTypLib.

### <a name="to-create-a-dispatch-class-from-a-type-library-tlb-file"></a>Para criar uma classe de expedição a partir de um arquivo de biblioteca de tipos (. tlb)

1. No Modo de Exibição de Classe ou Gerenciador de Soluções, clique com o botão direito do mouse no projeto e clique em **Adicionar** e em **Adicionar classe** no menu de atalho.

1. Na caixa de diálogo **Adicionar classe** , selecione a pasta **Visual C++/MFC** no painel esquerdo. Selecione a **classe MFC no** ícone de typelib no painel direito e clique em **abrir**.

1. Na caixa de diálogo **Adicionar classe do assistente de typelib** , selecione uma biblioteca de tipos na lista suspensa **bibliotecas de tipos disponíveis** . A caixa **interfaces** exibe as interfaces disponíveis para a biblioteca de tipos selecionada.

    > [!NOTE]
    >  Você pode selecionar interfaces de mais de uma biblioteca de tipos.

   Para selecionar interfaces, clique duas vezes nelas ou clique no botão **Adicionar** . Quando você fizer isso, os nomes das classes de expedição serão exibidos na caixa **classes geradas** . Você pode editar os nomes de classe na `Class` caixa.

   A caixa **arquivo** exibe o arquivo no qual a classe será declarada. (você também pode editar esse nome de arquivo). Você também pode usar o botão procurar para selecionar outros arquivos, se preferir ter as informações de cabeçalho e de implementação gravadas em arquivos existentes ou em um diretório diferente do diretório do projeto.

    > [!NOTE]
    >  Todas as classes de expedição para as interfaces selecionadas serão colocadas no arquivo especificado aqui. Se desejar que as interfaces sejam declaradas em cabeçalhos separados, você deverá executar esse assistente para cada arquivo de cabeçalho que deseja criar.

    > [!NOTE]
    >  Algumas informações de biblioteca de tipos podem ser armazenadas em arquivos com. DLL,. OCX ou. Extensões de arquivo OLB.

1. Clique em **Concluir**.

   O assistente gravará o código para suas classes de expedição usando os nomes de arquivo e de classe especificados.

## <a name="see-also"></a>Consulte também

[Clientes de automação](automation-clients.md)
