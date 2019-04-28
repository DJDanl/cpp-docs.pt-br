---
title: Adicionando Pontos de Conexão a um Objeto
ms.date: 11/04/2016
helpviewer_keywords:
- connection points [C++], adding to ATL objects
- Implement Connection Point ATL wizard
ms.assetid: 843531be-4a36-4db0-9d54-e029b1a72a8b
ms.openlocfilehash: 7341e69852ed804122e0196b51d305f5af0c35b9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62223513"
---
# <a name="adding-connection-points-to-an-object"></a>Adicionando Pontos de Conexão a um Objeto

O [Tutorial da ATL](../atl/active-template-library-atl-tutorial.md) demonstra como criar um controle com suporte para pontos de conexão, como adicionar eventos e como implementar o ponto de conexão. ATL implementa pontos de conexão com o [IConnectionPointImpl](../atl/reference/iconnectionpointimpl-class.md) classe.

Para implementar um ponto de conexão, você tem duas opções:

- Implemente sua própria fonte de evento de saída, com a adição de um ponto de conexão para o controle ou objeto.

- Reutilize uma interface de ponto de conexão definida em outra biblioteca de tipos.

Em ambos os casos, o Assistente de implementação de ponto de Conexão usa uma biblioteca de tipos para fazer seu trabalho.

### <a name="to-add-a-connection-point-to-a-control-or-object"></a>Para adicionar um ponto de conexão a um controle ou objeto

1. Defina um dispinterface no bloco de biblioteca do arquivo. idl. Se você tiver habilitado o suporte para pontos de conexão quando você criou o controle com o Assistente de controle do ATL, a dispinterface já será criada. Se você não tiver habilitado o suporte para pontos de conexão quando você criou o controle, adicione manualmente um dispinterface no arquivo. idl. O exemplo a seguir é um exemplo de um dispinterface. Interfaces de saída não são necessários para ser interfaces de expedição, mas muitas linguagens de script como VBScript e JScript requerem isso, portanto, este exemplo usa dois dispinterfaces:

   [!code-cpp[NVC_ATL_Windowing#81](../atl/codesnippet/cpp/adding-connection-points-to-an-object_1.idl)]

   Use o utilitário uuidgen.exe ou guidgen.exe para gerar um GUID.

2. Adicionar a dispinterface como o `[default,source]` interface em coclass para o objeto no arquivo. IDL do projeto. Novamente, se você tiver habilitado o suporte para pontos de conexão quando você criou o controle, o Assistente de controle ATL criará o `[default,source`] entrada. Para adicionar manualmente essa entrada, adicione a linha em negrito:

   [!code-cpp[NVC_ATL_Windowing#82](../atl/codesnippet/cpp/adding-connection-points-to-an-object_2.idl)]

   Consulte o arquivo. idl na [c](../overview/visual-cpp-samples.md) exemplo ATL para obter um exemplo.

3. Use o modo de exibição de classe para adicionar propriedades e métodos para a interface de eventos. A classe no modo de exibição de classe com o botão direito, aponte para **Add** no menu de atalho e clique em **Adicionar ponto de Conexão**.

4. No **Interfaces de origem** caixa de listagem do Assistente de ponto de Conexão a implementar, selecione **interfaces do projeto**. Se você escolher uma interface para o controle e pressione **Okey**, você irá:

   - Gere um arquivo de cabeçalho com uma classe de proxy de evento que implementa o código que fará as chamadas de saída para o evento.

   - Adicione uma entrada para o mapa de ponto de conexão.

   Você também verá uma lista de todas as bibliotecas de tipo em seu computador. Você só deve usar uma dessas outras bibliotecas de tipo para definir o ponto de conexão, se você quiser implementar a interface de saída mesma exata encontrada em outra biblioteca de tipos.

### <a name="to-reuse-a-connection-point-interface-defined-in-another-type-library"></a>Para reutilizar uma interface de ponto de conexão definida em outra biblioteca de tipos

1. No modo de exibição de classe, clique com botão direito a uma classe que implementa um **BEGIN_COM_MAP** macro, aponte para **Add** no menu de atalho e clique em **Adicionar ponto de Conexão**.

2. No Assistente de ponto de Conexão de implementar, selecione uma biblioteca de tipos e uma interface na biblioteca de tipos e clique em **adicionar**.

3. Edite o arquivo. IDL para qualquer um:

   - Copie a dispinterface de arquivo. IDL para o objeto cuja origem do evento está sendo usada.

   - Use o **importlib** instruções sobre como essa biblioteca de tipos.

## <a name="see-also"></a>Consulte também

[Ponto de Conexão](../atl/atl-connection-points.md)
