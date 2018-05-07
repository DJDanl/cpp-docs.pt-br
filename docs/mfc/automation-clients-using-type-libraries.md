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
ms.openlocfilehash: 67fa0f5d164ae325caff576fb41695fc8689fda0
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="automation-clients-using-type-libraries"></a>Clientes de automação: usando bibliotecas de tipo
Clientes de automação devem ter informações sobre propriedades e métodos de objetos de servidor se os clientes são manipular objetos do servidor. Propriedades têm tipos de dados. métodos geralmente valores de retorno e aceitam parâmetros. O cliente requer informações sobre os tipos de dados de tudo isso para vincular estaticamente para o tipo de objeto de servidor.  
  
 Essas informações de tipo podem ser feitas conhecidas de várias maneiras. A maneira recomendada é criar uma biblioteca de tipos.  
  
 Para obter informações sobre [MkTypLib](http://msdn.microsoft.com/library/windows/desktop/aa366797), consulte o SDK do Windows.  
  
 Visual C++ pode ler um arquivo de biblioteca de tipos e criar uma classe de expedição derivada de [COleDispatchDriver](../mfc/reference/coledispatchdriver-class.md). Um objeto dessa classe tiver propriedades e operações para duplicar do objeto de servidor. O aplicativo chama esse objeto propriedades e operações e funcionalidade herdada do `COleDispatchDriver` encaminha essas chamadas para o sistema OLE, que por sua vez direciona para o objeto de servidor.  
  
 Visual C++ mantém automaticamente esse arquivo de biblioteca de tipos para você, se você optar por incluir automação quando o projeto foi criado. Como parte de cada compilação, o arquivo. tlb será criado com MkTypLib.  
  
### <a name="to-create-a-dispatch-class-from-a-type-library-tlb-file"></a>Para criar uma classe de expedição de um arquivo de biblioteca de tipos (. tlb)  
  
1.  No modo de exibição de classe ou no Gerenciador de soluções, clique com o botão direito e clique em **adicionar** e, em seguida, clique em **Adicionar classe** no menu de atalho.  
  
2.  No **Adicionar classe** caixa de diálogo, selecione o **Visual c++ c++ MFC** pasta no painel esquerdo. Selecione o **classe do MFC de TypeLib** ícone no painel direito e clique em **abrir**.  
  
3.  No **Adicionar classe de Typelib assistente** caixa de diálogo, selecione uma biblioteca de tipos do **bibliotecas de tipo disponível** lista suspensa. O **Interfaces** caixa exibe as interfaces disponíveis para a biblioteca de tipo selecionado.  
  
    > [!NOTE]
    >  Você pode selecionar as interfaces de mais de uma biblioteca de tipos.  
  
     Selecione as interfaces, clique duas vezes neles ou clique no **adicionar** botão. Quando você fizer isso, os nomes das classes de expedição serão exibidos no **classes geradas** caixa. Você pode editar os nomes de classe no `Class` caixa.  
  
     O **arquivo** caixa exibe o arquivo no qual a classe será declarada. (você pode editar este nome de arquivo). Você também pode usar o botão Procurar para selecionar outros arquivos, se você preferir ter as informações de cabeçalho e de implementação gravadas em arquivos existentes ou em um diretório diferente do diretório do projeto.  
  
    > [!NOTE]
    >  Todas as classes de expedição de interfaces selecionadas serão colocadas no arquivo especificado aqui. Se você quiser que as interfaces para ser declarada em cabeçalhos separados, você deve executar este assistente para cada arquivo de cabeçalho que você deseja criar.  
  
    > [!NOTE]
    >  Algumas informações de biblioteca de tipo podem ser armazenadas em arquivos com. DLL. OCX, ou. Extensões de arquivo OLB.  
  
4.  Clique em **Finalizar**.  
  
     O assistente, em seguida, irá escrever o código para as classes de expedição usando a classe especificada e nomes de arquivo.  
  
## <a name="see-also"></a>Consulte também  
 [Clientes de automação](../mfc/automation-clients.md)

