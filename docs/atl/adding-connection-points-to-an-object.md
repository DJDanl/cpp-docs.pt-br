---
title: "Adicionando pontos de conex&#227;o a um objeto | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "pontos de conexão [C++], adicionar objetos de ATL"
  - "Assistente de ponto de conexão ATL de implementam"
ms.assetid: 843531be-4a36-4db0-9d54-e029b1a72a8b
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Adicionando pontos de conex&#227;o a um objeto
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

[tutorial de ATL](../Topic/Active%20Template%20Library%20\(ATL\)%20Tutorial.md) demonstra como criar um controle com suporte para pontos de conexão, como adicionar eventos e em seguida, como implementar o ponto de conexão.  ATL implementa pontos de conexão com a classe de [IConnectionPointImpl](../Topic/IConnectionPointImpl%20Class.md) .  
  
 Para implementar um ponto de conexão, você tem duas opções:  
  
-   Implementar sua própria fonte de evento de saída, adicionando um ponto de conexão para o controle ou o objeto.  
  
-   Reutilizar uma interface de ponto de conexão definida em outra biblioteca de tipo.  
  
 Em ambos os casos, o assistente de ponto de conexão de implementar usa uma biblioteca de tipo para tornar seu trabalho.  
  
### Para adicionar um ponto de conexão a um objeto ou controle  
  
1.  Defina um dispinterface no bloco de biblioteca do arquivo de .idl.  Se você tiver habilitado suporte para pontos de conexão quando você criou o controle com o assistente de controle de ATL, o dispinterface já será criado.  Se você não tiver habilitado suporte para pontos de conexão quando você criou o controle, você deve adicionar manualmente um dispinterface para o arquivo de .idl.  O exemplo a seguir é um exemplo de um dispinterface.  As interfaces de saída não precisam ser interfaces de distribuição mas muitas linguagens de script como VBScript JScript e exigem isso, para que este exemplo usa dois dispinterfaces:  
  
     [!code-cpp[NVC_ATL_Windowing#81](../atl/codesnippet/CPP/adding-connection-points-to-an-object_1.idl)]  
  
     Use o uuidgen.exe e o utilitário de guidgen.exe para gerar um GUID.  
  
2.  Adicione o dispinterface como a interface de `[default,source]` em coclass para o objeto no arquivo de .idl do projeto.  Além de isso, se você tiver habilitado suporte para pontos de conexão quando você criou o controle, o assistente de controle de ATL criará a entrada de `[default,source`\].  Para adicionar manualmente a entrada, adicione a linha em negrito:  
  
     [!code-cpp[NVC_ATL_Windowing#82](../atl/codesnippet/CPP/adding-connection-points-to-an-object_2.idl)]  
  
     Consulte o arquivo de .idl no exemplo de [Circ](../top/visual-cpp-samples.md) ATL para um exemplo.  
  
3.  Use o modo da classe para adicionar métodos e propriedades para a interface de evento.  Clique com o botão direito do mouse na classe no modo da classe, aponte **Adicionar** a no menu de atalho, clique **AdicionarConnection Point**.  
  
4.  Em a caixa de listagem de **Source Interfaces** do assistente de ponto de conexão de **Project's interfaces**implementam, selecione.  Se você escolher uma interface para o controle e pressione **OK**, você:  
  
    -   Gerar um arquivo de cabeçalho com uma classe de proxy de evento que implementa o código que irá fazer chamadas de saída para o evento.  
  
    -   Adicione uma entrada ao mapeamento de ponto de conexão.  
  
     Você também verá uma lista de todas as bibliotecas de tipo no seu computador.  Você deve usar uma de essas outras bibliotecas de tipo para definir seu ponto de conexão se você deseja implementar eatamente a mesma interface de saída encontrada em outra biblioteca de tipo.  
  
### Para reutilizar uma interface de ponto de conexão definida em outra biblioteca de tipo  
  
1.  Em o modo da classe, clique com o botão direito do mouse uma classe que implementa uma macro de **BEGIN\_COM\_MAP** , aponte\-o para a **Adicionar** no menu de atalho, clique **AdicionarConnection Point**.  
  
2.  Em o assistente de ponto de conexão de implementar, selecione uma biblioteca de tipos e uma interface na biblioteca de tipos e clique **Adicionar**.  
  
3.  Edite o arquivo de .idl para qualquer pessoa:  
  
    -   Copie o dispinterface do arquivo de .idl para o objeto cuja fonte do evento está sendo usado.  
  
    -   Use a declaração de **importlib** na biblioteca de tipos.  
  
## Consulte também  
 [Ponto de conexão](../atl/atl-connection-points.md)