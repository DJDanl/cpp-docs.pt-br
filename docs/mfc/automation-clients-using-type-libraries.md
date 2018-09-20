---
title: 'Clientes de automação: Usando bibliotecas de tipo | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: conceptual
f1_keywords:
- MkTypLib
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 421040024e5dd95fb39bdc78cd54f3f7dc49bf83
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46377702"
---
# <a name="automation-clients-using-type-libraries"></a>Clientes de automação: usando bibliotecas de tipo

Clientes de automação devem ter informações sobre propriedades e métodos de objetos de servidor se os clientes são manipular objetos dos servidores. Propriedades têm tipos de dados; Geralmente, os métodos retornam valores e aceitam parâmetros. O cliente requer informações sobre os tipos de dados de tudo isso para vincular estaticamente para o tipo de objeto de servidor.

Essas informações de tipo podem ser feitas conhecidas de várias maneiras. A maneira recomendada é criar uma biblioteca de tipos.

Para obter informações sobre [MkTypLib](/windows/desktop/Midl/differences-between-midl-and-mktyplib), consulte o SDK do Windows.

Visual C++ pode ler um arquivo de biblioteca de tipos e criar uma classe de expedição derivada de [COleDispatchDriver](../mfc/reference/coledispatchdriver-class.md). Um objeto dessa classe tem propriedades e operações duplicação do objeto de servidor. O aplicativo chama esse objeto propriedades e operações e funcionalidade herdada de `COleDispatchDriver` encaminha essas chamadas para o sistema OLE, que por sua vez, encaminha-as para o objeto de servidor.

Visual C++ mantém automaticamente esse arquivo de biblioteca de tipos para você, se você optar por incluir automação quando o projeto foi criado. Como parte de cada compilação, o arquivo. tlb será compilado com MkTypLib.

### <a name="to-create-a-dispatch-class-from-a-type-library-tlb-file"></a>Para criar uma classe de expedição de um arquivo de biblioteca de tipos (. tlb)

1. No modo de exibição de classe ou no Gerenciador de soluções, clique com botão direito no projeto e clique em **Add** e, em seguida, clique em **Adicionar classe** no menu de atalho.

1. No **Add Class** caixa de diálogo, selecione o **Visual c++ /Visual c++ /CLI MFC** pasta no painel esquerdo. Selecione o **MFC a classe de TypeLib** ícone no painel direito e clique **abrir**.

1. No **Adicionar classe de Typelib assistente** caixa de diálogo, selecione uma biblioteca de tipos dos **bibliotecas de tipos disponíveis** lista suspensa. O **Interfaces** caixa exibe as interfaces disponíveis para a biblioteca de tipo selecionado.

    > [!NOTE]
    >  Você pode selecionar as interfaces de mais de uma biblioteca de tipos.

     Selecione as interfaces, clique duas vezes neles ou clique no **adicionar** botão. Quando você fizer isso, os nomes das classes de expedição serão exibidos na **classes geradas** caixa. Você pode editar os nomes de classe a `Class` caixa.

     O **arquivo** caixa exibe o arquivo no qual a classe será declarada. (você pode editar esse nome de arquivo). Você também pode usar o botão Procurar para selecionar outros arquivos, se você preferir ter as informações de cabeçalho e de implementação escritas em arquivos existentes ou em um diretório que não seja o diretório do projeto.

    > [!NOTE]
    >  Todas as classes de expedição de interfaces selecionadas serão colocadas no arquivo especificado aqui. Se você quiser que as interfaces sejam declaradas nos cabeçalhos separados, você deve executar esse assistente para cada arquivo de cabeçalho que você deseja criar.

    > [!NOTE]
    >  Algumas informações de biblioteca de tipo podem ser armazenadas em arquivos com. DLL. OCX, ou. Extensões de arquivo OLB.

1. Clique em **Finalizar**.

     O assistente, em seguida, irá escrever o código para as suas classes de expedição usando a classe especificada e os nomes de arquivo.

## <a name="see-also"></a>Consulte também

[Clientes de automação](../mfc/automation-clients.md)

