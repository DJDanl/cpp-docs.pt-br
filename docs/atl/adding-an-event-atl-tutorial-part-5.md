---
title: Adicionando um evento (Tutorial ATL, parte 5)
ms.custom: get-started-article
ms.date: 09/27/2018
ms.assetid: 2de12022-3148-4ce3-8606-8a9d4274f0e9
ms.openlocfilehash: 57fc2adaadcca52cfc25736b5f9010fcb65a2ff0
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57278633"
---
# <a name="adding-an-event-atl-tutorial-part-5"></a>Adicionando um evento (Tutorial ATL, parte 5)

Nesta etapa, você adicionará uma `ClickIn` e um `ClickOut` eventos ao seu controle ATL. Você será acionado a `ClickIn` evento se o usuário clica dentro do polígono e fogo `ClickOut` se o usuário clica fora. As tarefas para adicionar um evento são da seguinte maneira:

- Adicionando o `ClickIn` e `ClickOut` métodos

- Gerando a biblioteca de tipos

- Implementando as Interfaces de ponto de Conexão

## <a name="adding-the-clickin-and-clickout-methods"></a>Adicionando os métodos ClickIn e ClickOut

Quando você criou o controle ATL na etapa 2, você selecionou o **pontos de Conexão** caixa de seleção. Isso criou o `_IPolyCtlEvents` interface no arquivo Polygon.idl. Observe que o nome da interface começa com um sublinhado. Isso é uma convenção para indicar que a interface é uma interface interna. Portanto, programas que permitem que você procure objetos COM podem optar por não exibir a interface para o usuário. Observe também que a seleção **pontos de Conexão** adicionado a seguinte linha no arquivo para indicar que Polygon.idl `_IPolyCtlEvents` é a interface de origem padrão:

`[default, source] dispinterface _IPolyCtlEvents;`

O atributo de origem indica que o controle é a origem das notificações, portanto, ele chamará essa interface no contêiner.

Agora, adicione a `ClickIn` e `ClickOut` métodos para o `_IPolyCtlEvents` interface.

### <a name="to-add-the-clickin-and-clickout-methods"></a>Para adicionar os métodos ClickIn e ClickOut

1. Na **Gerenciador de soluções**, abra Polygon.idl e adicione o seguinte código sob `methods:` no `dispInterface_IPolyCtlEvents` declaração da biblioteca PolygonLib:

    ```cpp
   [id(1), helpstring("method ClickIn")] void ClickIn([in] LONG x,[in] LONG y);
   [id(2), helpstring("method ClickOut")] void ClickOut([in] LONG x,[in] LONG y);
    ```

O `ClickIn` e `ClickOut` take métodos x e as coordenadas y do ponto clicado como parâmetros.

## <a name="generating-the-type-library"></a>Gerando a biblioteca de tipos

Gere biblioteca de tipos neste ponto, porque o projeto usará para obter as informações necessárias para construir uma interface de ponto de conexão e uma interface de contêiner de ponto de conexão para o seu controle.

### <a name="to-generate-the-type-library"></a>Para gerar a biblioteca de tipos

1. Recompile o projeto.

     -ou-

1. O arquivo Polygon.idl no botão direito do mouse **Gerenciador de soluções** e clique em **compilar** no menu de atalho.

Isso criará o arquivo Polygon.tlb, que é a sua biblioteca de tipos. O arquivo Polygon.tlb não estiver visível no **Gerenciador de soluções**, porque ele é um arquivo binário e não pode ser exibido ou editado diretamente.

## <a name="implementing-the-connection-point-interfaces"></a>Implementando as Interfaces de ponto de Conexão

Implemente uma interface de ponto de conexão e uma interface de contêiner de ponto de conexão para o seu controle. No COM, os eventos são implementados por meio do mecanismo de pontos de conexão. Para receber eventos de um objeto COM, um contêiner estabelece uma conexão de consultoria para o ponto de conexão que implementa o objeto COM. Como um objeto COM pode ter vários pontos de conexão, o objeto COM também implementa uma interface de contêiner de ponto de conexão. Por meio dessa interface, o contêiner pode determinar quais pontos de conexão são suportados.

A interface que implementa um ponto de conexão é chamada `IConnectionPoint`, e a interface que implementa um contêiner de ponto de conexão é chamada `IConnectionPointContainer`.

Para ajudar a implementar `IConnectionPoint`, você usará o Assistente para implementar o ponto de Conexão. Esse assistente gera o `IConnectionPoint` interface lendo sua biblioteca de tipos e implementação de uma função para cada evento que pode ser acionado.

### <a name="to-implement-the-connection-points"></a>Para implementar os pontos de conexão

1. Na **Gerenciador de soluções**, abra _IPolyCtlEvents_CP.h e adicione o seguinte código sob a `public:` instrução no `CProxy_IPolyCtlEvents` classe:

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

Você verá que esse arquivo tem uma classe chamada `CProxy_IPolyCtlEvents` que deriva de `IConnectionPointImpl`. _IPolyCtlEvents_CP.h agora define dois métodos `Fire_ClickIn` e `Fire_ClickOut`, que usam os dois parâmetros de coordenadas. Você chama esses métodos quando você deseja disparar um evento de seu controle.

Criando o controle com **pontos de Conexão** opção selecionada, o arquivo _IPolyCtlEvents_CP.h foi gerada para você. Ele também adicionado `CProxy_PolyEvents` e `IConnectionPointContainerImpl` à lista de herança do seu controle vários e exposto `IConnectionPointContainer` para você, adicionando entradas apropriadas para o mapa COM.

Você terminar de implementar o código para dar suporte a eventos. Agora, adicione algum código para disparar os eventos no momento apropriado. Lembre-se de que você pretende acionar uma `ClickIn` ou `ClickOut` evento quando o usuário clica no botão esquerdo do mouse no controle. Para saber quando o usuário clica no botão, adicionar um manipulador para o `WM_LBUTTONDOWN` mensagem.

### <a name="to-add-a-handler-for-the-wmlbuttondown-message"></a>Para adicionar um manipulador para a mensagem WM_LBUTTONDOWN

1. Na **Class View**, com o botão direito do `CPolyCtl` classe e clique em **propriedades** no menu de atalho.

1. No **propriedades** janela, clique no **mensagens** ícone e clique `WM_LBUTTONDOWN` na lista à esquerda.

1. Na lista suspensa que aparece, clique em  **\<Adicionar > OnLButtonDown**. O `OnLButtonDown` declaração do manipulador será adicionada ao polyctl. H e a implementação do manipulador será adicionada ao PolyCtl.cpp.

Em seguida, modifique o manipulador.

### <a name="to-modify-the-onlbuttondown-method"></a>Para modificar o método OnLButtonDown

1. Alterar o código que inclui o `OnLButtonDown` método na PolyCtl.cpp (excluindo qualquer código colocado pelo Assistente) para que ele tem esta aparência:

    [!code-cpp[NVC_ATL_Windowing#57](../atl/codesnippet/cpp/adding-an-event-atl-tutorial-part-5_2.cpp)]

Isso faz com código que uso dos pontos é calculado na `OnDraw` função para criar uma região que detecta clica com o mouse do usuário com a chamada para `PtInRegion`.

O *uMsg* parâmetro é a ID da mensagem de Windows que está sendo manipulada. Isso permite que você tenha uma função que manipula um intervalo de mensagens. O *wParam* e o *lParam* parâmetros são os valores padrão para a mensagem que está sendo manipulado. O parâmetro *bHandled* permite que você especifique se a função manipulou a mensagem ou não. Por padrão, o valor é definido como TRUE para indicar que a função manipulou a mensagem, mas você pode defini-lo como FALSE. Isso fará com que o ATL continuar procurando por outra função de manipulador de mensagens enviar a mensagem.

## <a name="building-and-testing-the-control"></a>Compilar e testar o controle

Agora, experimente seus eventos. Criar o controle e inicie o contêiner de teste do controle ActiveX novamente. Desta vez, exiba a janela de log de eventos. Para encaminhar eventos para a janela de saída, clique em **registro em log** da **opções** menu e selecione **Log à janela de saída**. Inserir o controle e tente clicar na janela. Observe que `ClickIn` é acionado se você clicar em um polígono preenchido, e `ClickOut` é disparado quando você clica fora dele.

Em seguida, você adicionará uma página de propriedades.

[Volte para a etapa 4](../atl/changing-the-drawing-code-atl-tutorial-part-4.md) &#124; [para a etapa 6](../atl/adding-a-property-page-atl-tutorial-part-6.md)

## <a name="see-also"></a>Consulte também

[Tutorial](../atl/active-template-library-atl-tutorial.md)
