---
title: Adicionar pontos de Conexão a um objeto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- connection points [C++], adding to ATL objects
- Implement Connection Point ATL wizard
ms.assetid: 843531be-4a36-4db0-9d54-e029b1a72a8b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 71f9d136ccdeded02303894195c7b8126acafd9c
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32356586"
---
# <a name="adding-connection-points-to-an-object"></a>Adicionando Pontos de Conexão a um Objeto
O [Tutorial da ATL](../atl/active-template-library-atl-tutorial.md) demonstra como criar um controle com suporte para pontos de conexão, como adicionar eventos e como implementar o ponto de conexão. ATL implementa os pontos de conexão com o [IConnectionPointImpl](../atl/reference/iconnectionpointimpl-class.md) classe.  
  
 Para implementar um ponto de conexão, você tem duas opções:  
  
-   Implemente sua própria fonte de evento de saída, com a adição de um ponto de conexão para o controle ou objeto.  
  
-   Reutilize uma interface de ponto de conexão definida em outra biblioteca de tipos.  
  
 Em ambos os casos, o Assistente de implementação de ponto de Conexão usa uma biblioteca de tipos para fazer seu trabalho.  
  
### <a name="to-add-a-connection-point-to-a-control-or-object"></a>Para adicionar um ponto de conexão para um controle ou um objeto  
  
1.  Defina um dispinterface no bloco de biblioteca do arquivo. idl. Se você tiver habilitado o suporte para pontos de conexão quando você criou o controle com o Assistente de controle ATL, o dispinterface já será criada. Se você não habilitou o suporte para pontos de conexão quando você criou o controle, adicione manualmente um dispinterface no arquivo. idl. Este é um exemplo de um dispinterface. Interfaces de saída não são necessárias para ser interfaces de expedição, mas muitas linguagens de script, como VBScript e JScript exigem isso, para que este exemplo usa dois dispinterfaces:  
  
     [!code-cpp[NVC_ATL_Windowing#81](../atl/codesnippet/cpp/adding-connection-points-to-an-object_1.idl)]  
  
     Use o utilitário de uuidgen.exe ou guidgen.exe para gerar um GUID.  
  
2.  Adicionar dispinterface como o `[default,source]` interface em coclass para o objeto em que o arquivo do projeto. idl. Novamente, se você tiver habilitado o suporte para pontos de conexão quando você criou o controle, o Assistente de controle ATL criará o `[default,source`] entrada. Para adicionar manualmente esta entrada, adicione a linha em negrito:  
  
     [!code-cpp[NVC_ATL_Windowing#82](../atl/codesnippet/cpp/adding-connection-points-to-an-object_2.idl)]  
  
     Consulte o arquivo. idl o [c](../visual-cpp-samples.md) exemplo ATL para obter um exemplo.  
  
3.  Use a exibição de classe para adicionar os métodos e propriedades para a interface de eventos. A classe no modo de exibição de classe de atalho, aponte para **adicionar** no menu de atalho e clique em **Adicionar ponto de Conexão**.  
  
4.  No **Interfaces de origem** caixa de listagem do Assistente de ponto de Conexão de implementar, selecione **interfaces do projeto**. Se você escolher uma interface para o controle e pressione **Okey**, você vai:  
  
    -   Gere um arquivo de cabeçalho com uma classe de proxy de evento que implementa o código que faça com que as chamadas de saída para o evento.  
  
    -   Adicione uma entrada para o mapa de ponto de conexão.  
  
     Você também verá uma lista de todas as bibliotecas de tipo no seu computador. Você só deve usar uma dessas outras bibliotecas de tipo para definir o ponto de conexão, se você deseja implementar a interface de saída mesmo exata encontrada em outra biblioteca de tipos.  
  
### <a name="to-reuse-a-connection-point-interface-defined-in-another-type-library"></a>Para reutilizar uma interface de ponto de conexão definidas em outra biblioteca de tipos  
  
1.  No modo de exibição de classe, clique em uma classe que implementa uma **BEGIN_COM_MAP** macro, aponte para **adicionar** no menu de atalho e clique em **Adicionar ponto de Conexão**.  
  
2.  No Assistente de ponto de Conexão de implementar, selecione uma biblioteca de tipos e uma interface na biblioteca de tipos e clique em **adicionar**.  
  
3.  Edite o arquivo IDL para o:  
  
    -   Copie a dispinterface de arquivo. IDL para o objeto cuja origem de evento está sendo usada.  
  
    -   Use o **importlib** instruções sobre essa biblioteca de tipos.  
  
## <a name="see-also"></a>Consulte também  
 [Ponto de Conexão](../atl/atl-connection-points.md)

