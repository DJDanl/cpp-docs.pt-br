---
title: "Bibliotecas estáticas (C + + CX) | Microsoft Docs"
ms.custom: 
ms.date: 02/03/2017
ms.prod: windows-client-threshold
ms.technology: cpp-windows
ms.reviewer: 
ms.suite: 
ms.tgt_pltfrm: 
ms.topic: article
ms.assetid: 7faf53c8-fa21-42cc-8246-d32533ef9dfa
caps.latest.revision: "10"
author: ghogen
ms.author: ghogen
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: a68475447ed520298b0eab7949386c2e8d078ac6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="static-libraries-ccx"></a>Bibliotecas estáticas (C++/CX)
Uma biblioteca estática que é usada em um aplicativo de plataforma Universal do Windows pode conter código C++ padrão ISO, incluindo tipos STL e também chamadas a APIs Win32 que não são excluídas da plataforma do aplicativo de plataforma Universal do Windows. Uma biblioteca estática consome componentes do tempo de execução do Windows e pode criar componentes do Windows Runtime com algumas restrições.  
  
## <a name="creating-static-libraries"></a>Criando bibliotecas estáticas  
  
#### <a name="to-create-a-static-library-for-use-in-a-universal-windows-platform-app"></a>Para criar uma biblioteca estática para uso em um aplicativo de plataforma Universal do Windows  
  
1.  Na barra de menus, escolha **arquivo** > **novo** > **projeto** > **biblioteca estática em branco** para Windows Universal aplicativos de plataforma.  
  
2.  No **Gerenciador de Soluções**, abra o menu de atalho para o projeto e escolha **Propriedades**. No **propriedades** caixa de diálogo de **propriedades de configuração** > **geral** , defina o suporte de aplicativo da plataforma Universal do Windows  **Sim**.  
  
3.  Sobre o **propriedades de configuração** > **C/C++** , defina **consumir** tempo de execução do Windows **extensão** para **Sim (/ZW)**.  
  
 Quando você compila uma nova biblioteca estática, se você fizer uma chamada para a API do Win32 que foi excluída para aplicativos de plataforma Universal do Windows, o compilador gerará o erro c3861: "Identificador não encontrado". Para procurar um método alternativo que tem suporte para o tempo de execução do Windows, consulte [alternativas às APIs do Windows em aplicativos da Windows Store](http://msdn.microsoft.com/en-us/75568012-61e0-41cc-a4df-c698f54f21ec).  
  
 Se você adicionar um projeto de biblioteca estática C++ a uma solução de aplicativo da plataforma Universal do Windows, você talvez precise atualizar as configurações de propriedade do projeto de biblioteca para que a propriedade de suporte de plataforma Universal do Windows é definida como **Sim**. Sem essa configuração, o código a seguir é compilado e vinculado, mas um erro ocorre quando você tenta verificar o aplicativo para o [!INCLUDE[win8_appstore_long](../cppcx/includes/win8-appstore-long-md.md)]. A biblioteca estática deve ser compilada com as mesmas configurações do compilador do projeto que a consome.  
  
 Se você consumir uma biblioteca estática que cria classes públicas `ref` , as classes de interface pública ou as classes de valor público, o vinculador gerará este aviso:  
  
> **Aviso LNK4264:** arquivamento do arquivo de objeto compilado com /ZW em uma biblioteca estática; Observe que ao criar tipos de Windows Runtime não recomenda-se vincular a uma biblioteca estática que contém metadados de tempo de execução do Windows.  
  
 Você pode ignorar com segurança o aviso somente se a biblioteca estática não estiver produzindo componentes de tempo de execução do Windows que são consumidos fora da própria biblioteca. Se a biblioteca não consumir um componente que ela definir, o vinculador poderá otimizar a implementação mesmo que os metadados públicos contenham as informações de tipo. Isso significa que os componentes públicos em uma biblioteca estática serão compilados, mas não serão ativados no tempo de execução. Por esse motivo, qualquer componente de tempo de execução do Windows que é destinado ao consumo por outros componentes ou aplicativos deve ser implementada em uma biblioteca de vínculo dinâmico (DLL).  
  
## <a name="see-also"></a>Consulte também  
 [Threading e Marshaling](../cppcx/threading-and-marshaling-c-cx.md)