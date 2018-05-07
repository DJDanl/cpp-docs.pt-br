---
title: Bibliotecas estáticas (C + + CX) | Microsoft Docs
ms.custom: ''
ms.date: 02/03/2017
ms.technology: cpp-windows
ms.topic: language-reference
ms.assetid: 7faf53c8-fa21-42cc-8246-d32533ef9dfa
author: ghogen
ms.author: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: ffa905cbe0fd49489bd3634cb927cce57ea4ddbc
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="static-libraries-ccx"></a>Bibliotecas estáticas (C++/CX)
Uma biblioteca estática que é usada em um aplicativo do Windows UWP (plataforma Universal) pode conter código C++ padrão ISO, incluindo tipos STL e também chamadas a APIs Win32 que não são excluídas da plataforma do aplicativo de tempo de execução do Windows. Uma biblioteca estática consome componentes do tempo de execução do Windows e pode criar componentes do Windows Runtime com algumas restrições.  
  
## <a name="creating-static-libraries"></a>Criando bibliotecas estáticas  
  
#### <a name="to-create-a-static-library-for-use-in-a-uwp-app"></a>Para criar uma biblioteca estática para uso em um aplicativo UWP  
  
1.  Na barra de menus, selecione **Arquivo** > **Novo** > **Projeto**. Em **Visual C++** > **Windows Universal** escolha **biblioteca estática (Universal do Windows)**.  
  
2.  No **Gerenciador de Soluções**, abra o menu de atalho para o projeto e escolha **Propriedades**. No **propriedades** caixa de diálogo de **propriedades de configuração** > **C/C++** , defina **consumir extensão de tempo de execução do Windows** para **Sim (/ZW)**.  
  
 Quando você compila uma nova biblioteca estática, se você fizer uma chamada para a API do Win32 que foi excluída para aplicativos UWP, o compilador gerará o erro c3861: "Identificador não encontrado". Para procurar um método alternativo que tem suporte para o tempo de execução do Windows, consulte [alternativas para APIs do Windows em aplicativos UWP](/uwp/win32-and-com/alternatives-to-windows-apis-uwp).  
  
 Se você adicionar um projeto de biblioteca estática C++ a uma solução de aplicativo UWP, você terá que atualizar as configurações de propriedade do projeto de biblioteca para que a propriedade de suporte UWP é definida como **Sim**. Sem essa configuração, o código compila e links, mas um erro ocorre quando você tenta verificar o aplicativo para o Microsoft Store. A biblioteca estática deve ser compilada com as mesmas configurações do compilador do projeto que a consome.  
  
 Se você consumir uma biblioteca estática que cria classes públicas `ref` , as classes de interface pública ou as classes de valor público, o vinculador gerará este aviso:  
  
> **Aviso LNK4264:** arquivamento do arquivo de objeto compilado com /ZW em uma biblioteca estática; Observe que ao criar tipos de Windows Runtime não recomenda-se vincular a uma biblioteca estática que contém metadados de tempo de execução do Windows.  
  
 Você pode ignorar com segurança o aviso somente se a biblioteca estática não estiver produzindo componentes de tempo de execução do Windows que são consumidos fora da própria biblioteca. Se a biblioteca não consumir um componente que ela definir, o vinculador poderá otimizar a implementação mesmo que os metadados públicos contenham as informações de tipo. Isso significa que os componentes públicos em uma biblioteca estática serão compilados, mas não serão ativados no tempo de execução. Por esse motivo, qualquer componente de tempo de execução do Windows que é destinado ao consumo por outros componentes ou aplicativos deve ser implementada em uma biblioteca de vínculo dinâmico (DLL).  
  
## <a name="see-also"></a>Consulte também  
 [Threading e Marshaling](../cppcx/threading-and-marshaling-c-cx.md)