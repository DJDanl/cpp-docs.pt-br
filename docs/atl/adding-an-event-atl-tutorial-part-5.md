---
title: Adicionando um evento (Tutorial ATL, parte 5)
ms.custom: get-started-article
ms.date: 09/27/2018
ms.assetid: 2de12022-3148-4ce3-8606-8a9d4274f0e9
ms.openlocfilehash: c9a7c6f38a2f47ec808081e440a200737ad1928a
ms.sourcegitcommit: a8ef52ff4a4944a1a257bdaba1a3331607fb8d0f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/11/2020
ms.locfileid: "77127568"
---
# <a name="adding-an-event-atl-tutorial-part-5"></a>Adicionando um evento (Tutorial ATL, parte 5)

Nesta etapa, você adicionará uma `ClickIn` e um evento `ClickOut` ao seu controle ATL. Você acionará o evento `ClickIn` se o usuário clicar no polígono e disparar `ClickOut` se o usuário clicar fora do. As tarefas para adicionar um evento são as seguintes:

- Adicionando os métodos de `ClickIn` e `ClickOut`

- Gerando a biblioteca de tipos

- Implementando as interfaces de ponto de conexão

## <a name="adding-the-clickin-and-clickout-methods"></a>Adicionando os métodos Click e ClickOut

Quando você criou o controle ATL na etapa 2, marcou a caixa de seleção **pontos de conexão** . Isso criou a interface `_IPolyCtlEvents` no arquivo Polygon. idl. Observe que o nome da interface começa com um sublinhado. Essa é uma Convenção para indicar que a interface é uma interface interna. Assim, os programas que permitem que você procure objetos COM podem optar por não exibir a interface para o usuário. Observe também que a seleção de **pontos de conexão** adicionou a seguinte linha no arquivo Polygon. idl para indicar que `_IPolyCtlEvents` é a interface de origem padrão:

`[default, source] dispinterface _IPolyCtlEvents;`

O atributo de origem indica que o controle é a origem das notificações, portanto, ele chamará essa interface no contêiner.

Agora, adicione os métodos `ClickIn` e `ClickOut` à interface `_IPolyCtlEvents`.

### <a name="to-add-the-clickin-and-clickout-methods"></a>Para adicionar os métodos Click e ClickOut

1. No **Gerenciador de soluções**, abra Polygon. idl e adicione o código a seguir em `methods:` na declaração `dispInterface_IPolyCtlEvents` da biblioteca PolygonLib:

    ```cpp
   [id(1), helpstring("method ClickIn")] void ClickIn([in] LONG x,[in] LONG y);
   [id(2), helpstring("method ClickOut")] void ClickOut([in] LONG x,[in] LONG y);
    ```

Os métodos `ClickIn` e `ClickOut` usam as coordenadas x e y do ponto clicado como parâmetros.

## <a name="generating-the-type-library"></a>Gerando a biblioteca de tipos

Gere a biblioteca de tipos neste ponto, porque o projeto a usará para obter as informações necessárias para construir uma interface de ponto de conexão e uma interface de contêiner de ponto de conexão para seu controle.

### <a name="to-generate-the-type-library"></a>Para gerar a biblioteca de tipos

1. Recompile o projeto.

     -ou-

1. Clique com o botão direito do mouse no arquivo Polygon. idl em **Gerenciador de soluções** e clique em **Compilar** no menu de atalho.

Isso criará o arquivo Polygon. tlb, que é sua biblioteca de tipos. O arquivo Polygon. tlb não é visível no **Gerenciador de soluções**, porque ele é um arquivo binário e não pode ser exibido ou editado diretamente.

## <a name="implementing-the-connection-point-interfaces"></a>Implementando as interfaces de ponto de conexão

Implemente uma interface de ponto de conexão e uma interface de contêiner de ponto de conexão para seu controle. No COM, os eventos são implementados por meio do mecanismo de pontos de conexão. Para receber eventos de um objeto COM, um contêiner estabelece uma conexão de consultoria para o ponto de conexão que o objeto COM implementa. Como um objeto COM pode ter vários pontos de conexão, o objeto COM também implementa uma interface de contêiner de ponto de conexão. Por meio dessa interface, o contêiner pode determinar quais pontos de conexão têm suporte.

A interface que implementa um ponto de conexão é chamada `IConnectionPoint`, e a interface que implementa um contêiner de ponto de conexão é chamada `IConnectionPointContainer`.

Para ajudar a implementar `IConnectionPoint`, você usará o assistente para implementar ponto de conexão. Esse assistente gera a interface `IConnectionPoint` lendo sua biblioteca de tipos e implementando uma função para cada evento que pode ser acionado.

### <a name="to-implement-the-connection-points"></a>Para implementar os pontos de conexão

1. No **Gerenciador de soluções**, abra _IPolyCtlEvents_CP. h e adicione o seguinte código sob a instrução `public:` na classe `CProxy_IPolyCtlEvents`:

    ```cpp
    VOID Fire_ClickIn(LONG x, LONG y)
    {
        T* pT = static_cast<T*>(this);
        int nConnectionIndex;
        CComVariant* pvars = new CComVariant[2];
        int nConnections = m_vec.GetSize();

        for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
        {
            pT->Lock();
            CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
            pT->Unlock();
            IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
            if (pDispatch != NULL)
            {
                pvars[1].vt = VT_I4;
                pvars[1].lVal = x;
                pvars[0].vt = VT_I4;
                pvars[0].lVal = y;
                DISPPARAMS disp = { pvars, NULL, 2, 0 };
                pDispatch->Invoke(0x1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
            }
        }
        delete[] pvars;

    }
    VOID Fire_ClickOut(LONG x, LONG y)
    {
        T* pT = static_cast<T*>(this);
        int nConnectionIndex;
        CComVariant* pvars = new CComVariant[2];
        int nConnections = m_vec.GetSize();

        for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
        {
            pT->Lock();
            CComPtr<IUnknown> sp = m_vec.GetAt(nConnectionIndex);
            pT->Unlock();
            IDispatch* pDispatch = reinterpret_cast<IDispatch*>(sp.p);
            if (pDispatch != NULL)
            {
                pvars[1].vt = VT_I4;
                pvars[1].lVal = x;
                pvars[0].vt = VT_I4;
                pvars[0].lVal = y;
                DISPPARAMS disp = { pvars, NULL, 2, 0 };
                pDispatch->Invoke(0x2, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
            }
        }
        delete[] pvars;

    }
    ```

Você verá que esse arquivo tem uma classe chamada `CProxy_IPolyCtlEvents` que deriva de `IConnectionPointImpl`. _IPolyCtlEvents_CP. h agora define os dois métodos `Fire_ClickIn` e `Fire_ClickOut`, que usam os dois parâmetros de coordenadas. Você chama esses métodos quando deseja acionar um evento do seu controle.

Ao criar o controle com a opção de **pontos de conexão** selecionada, o arquivo _IPolyCtlEvents_CP. h foi gerado para você. Ele também adicionou `CProxy_PolyEvents` e `IConnectionPointContainerImpl` à lista múltipla de herança do controle e o `IConnectionPointContainer` exposto para você adicionando entradas apropriadas ao mapa COM.

Você concluiu a implementação do código para dar suporte a eventos. Agora, adicione algum código para acionar os eventos no momento apropriado. Lembre-se de que você vai disparar um evento de `ClickIn` ou de `ClickOut` quando o usuário clicar no botão esquerdo do mouse no controle. Para descobrir quando o usuário clica no botão, adicione um manipulador para a mensagem de `WM_LBUTTONDOWN`.

### <a name="to-add-a-handler-for-the-wm_lbuttondown-message"></a>Para adicionar um manipulador para a mensagem de WM_LBUTTONDOWN

1. Em **modo de exibição de classe**, clique com o botão direito do mouse na classe `CPolyCtl` e clique em **Propriedades** no menu de atalho.

1. Na janela **Propriedades** , clique no ícone **mensagens** e, em seguida, clique em `WM_LBUTTONDOWN` na lista à esquerda.

1. Na lista suspensa exibida, clique em **\<adicionar > OnLButtonDown**. A declaração do manipulador de `OnLButtonDown` será adicionada a PolyCtl. h e a implementação do manipulador será adicionada a PolyCtl. cpp.

Em seguida, modifique o manipulador.

### <a name="to-modify-the-onlbuttondown-method"></a>Para modificar o método OnLButtonDown

1. Altere o código que compõe o método `OnLButtonDown` em PolyCtl. cpp (excluindo qualquer código colocado pelo assistente) para que fique assim:

    [!code-cpp[NVC_ATL_Windowing#57](../atl/codesnippet/cpp/adding-an-event-atl-tutorial-part-5_2.cpp)]

Esse código usa os pontos calculados na função `OnDraw` para criar uma região que detecta os cliques do mouse do usuário com a chamada para `PtInRegion`.

O parâmetro *uMsg* é a ID da mensagem do Windows que está sendo manipulada. Isso permite que você tenha uma função que lide com um intervalo de mensagens. Os parâmetros *wParam* e *lParam* são os valores padrão para a mensagem que está sendo manipulada. O parâmetro *bHandled* permite que você especifique se a função tratou ou não a mensagem. Por padrão, o valor é definido como TRUE para indicar que a função tratou a mensagem, mas você pode defini-la como FALSE. Isso fará com que a ATL continue procurando outra função de manipulador de mensagens para a qual enviar a mensagem.

## <a name="building-and-testing-the-control"></a>Compilação e teste do controle

Agora experimente seus eventos. Crie o controle e inicie o contêiner de teste do controle ActiveX novamente. Desta vez, exiba a janela log de eventos. Para encaminhar eventos para a janela de saída, clique em **log** no menu de **Opções** e selecione **log na janela de saída**. Insira o controle e tente clicar na janela. Observe que `ClickIn` será disparado se você clicar no polígono preenchido e `ClickOut` for acionado quando você clicar fora dele.

Em seguida, você adicionará uma página de propriedades.

[Voltar à etapa 4](../atl/changing-the-drawing-code-atl-tutorial-part-4.md) &#124; [para a etapa 6](../atl/adding-a-property-page-atl-tutorial-part-6.md)

## <a name="see-also"></a>Consulte também

[Tutorial](../atl/active-template-library-atl-tutorial.md)
