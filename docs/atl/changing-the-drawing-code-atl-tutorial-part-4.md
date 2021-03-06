---
title: Alteração do código de desenho (Tutorial ATL, parte 4)
ms.custom: get-started-article
ms.date: 09/26/2018
helpviewer_keywords:
- _ATL_MIN_CRT macro
ms.assetid: 08ff14e8-aa49-4139-a110-5d071939cf1e
ms.openlocfilehash: 319a27b55c394349de751546457b0741c0799cfc
ms.sourcegitcommit: 2bc15c5b36372ab01fa21e9bcf718fa22705814f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/27/2020
ms.locfileid: "82167637"
---
# <a name="changing-the-drawing-code-atl-tutorial-part-4"></a>Alteração do código de desenho (Tutorial ATL, parte 4)

Por padrão, o código de desenho do controle exibe um quadrado e o texto **PolyCtl**. Nesta etapa, você vai alterar o código para exibir algo mais interessante. As seguintes tarefas estão envolvidas:

- Modificando o arquivo de cabeçalho

- Modificando `OnDraw` a função

- Adicionando um método para calcular os pontos do polígono

- Inicializando a cor de preenchimento

## <a name="modifying-the-header-file"></a>Modificando o arquivo de cabeçalho

Comece adicionando suporte para as funções `sin` matemáticas e `cos`, que serão usadas para calcular os pontos do polígono e criando uma matriz para armazenar posições.

### <a name="to-modify-the-header-file"></a>Para modificar o arquivo de cabeçalho

1. Adicione a linha `#include <math.h>` à parte superior de PolyCtl. h. A parte superior do arquivo deve ter a seguinte aparência:

    [!code-cpp[NVC_ATL_Windowing#47](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_1.cpp)]

1. Implemente `IProvideClassInfo` a interface para fornecer informações de método para o controle, adicionando o código a seguir a PolyCtl. h. Na `CPolyCtl` classe, substitua line:

    ```cpp
    public CComControl<CPolyCtl>
    ```

    por

    ```cpp
    public CComControl<CPolyCtl>,
    public IProvideClassInfo2Impl<&CLSID_PolyCtl, &DIID__IPolyCtlEvents, &LIBID_PolygonLib>
    ```

    e no `BEGIN_COM_MAP(CPolyCtl)`, adicione as linhas:

    ```cpp
    COM_INTERFACE_ENTRY(IProvideClassInfo)
    COM_INTERFACE_ENTRY(IProvideClassInfo2)
    ```

1. Depois que os pontos do polígono são calculados, eles serão armazenados em uma matriz `POINT`do tipo, portanto, adicione a matriz após `short m_nSides;` a instrução de definição em PolyCtl. h:

    [!code-cpp[NVC_ATL_Windowing#48](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_2.h)]

## <a name="modifying-the-ondraw-method"></a>Modificando o método OnDraw

Agora você deve modificar o `OnDraw` método em PolyCtl. h. O código que você adicionará cria uma nova caneta e um pincel com os quais desenhar o polígono e, em `Ellipse` seguida `Polygon` , chama as funções de API do Win32 para executar o desenho real.

### <a name="to-modify-the-ondraw-function"></a>Para modificar a função OnDraw

1. Substitua o método `OnDraw` existente em PolyCtl. h pelo seguinte código:

    [!code-cpp[NVC_ATL_Windowing#49](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_3.cpp)]

## <a name="adding-a-method-to-calculate-the-polygon-points"></a>Adicionando um método para calcular os pontos do polígono

Adicione um método, chamado `CalcPoints`, que calculará as coordenadas dos pontos que compõem o perímetro do polígono. Esses cálculos serão baseados na variável RECT que é passada para a função.

### <a name="to-add-the-calcpoints-method"></a>Para adicionar o método CalcPoints

1. Adicione a declaração de `CalcPoints` à seção `IPolyCtl` pública da `CPolyCtl` classe em PolyCtl. h:

    [!code-cpp[NVC_ATL_Windowing#50](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_4.h)]

    A última parte da seção pública da `CPolyCtl` classe terá a seguinte aparência:

    [!code-cpp[NVC_ATL_Windowing#51](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_5.h)]

1. Adicione essa implementação da `CalcPoints` função ao final de PolyCtl. cpp:

    [!code-cpp[NVC_ATL_Windowing#52](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_6.cpp)]

## <a name="initializing-the-fill-color"></a>Inicializando a cor de preenchimento

Inicialize `m_clrFillColor` com uma cor padrão.

### <a name="to-initialize-the-fill-color"></a>Para inicializar a cor de preenchimento

1. Use verde como a cor padrão adicionando essa linha ao `CPolyCtl` Construtor em PolyCtl. h:

    [!code-cpp[NVC_ATL_Windowing#53](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_7.h)]

O Construtor agora tem esta aparência:

[!code-cpp[NVC_ATL_Windowing#54](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_8.h)]

## <a name="building-and-testing-the-control"></a>Compilação e teste do controle

Recompile o controle. Verifique se o arquivo PolyCtl. htm está fechado se ainda estiver aberto e, em seguida, clique em **Compilar polígono** no menu **Compilar** . Você pode exibir o controle novamente na página PolyCtl. htm, mas desta vez use o contêiner de teste do controle ActiveX.

### <a name="to-use-the-activex-control-test-container"></a>Para usar o contêiner de teste do controle ActiveX

1. Crie e inicie o contêiner de teste do controle ActiveX. O [exemplo de TSTCON: contêiner de teste do controle ActiveX](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/ole/TstCon) pode ser encontrado no github.

    > [!NOTE]
    > Para erros envolvendo `ATL::CW2AEX`, em script. cpp, substitua linha `TRACE( "XActiveScriptSite::GetItemInfo( %s )\n", pszNameT );` por `TRACE( "XActiveScriptSite::GetItemInfo( %s )\n", pszNameT.m_psz );`e linha `TRACE( "Source Text: %s\n", COLE2CT( bstrSourceLineText ) );` por `TRACE( "Source Text: %s\n", bstrSourceLineText );`.<br/>
    > Para erros envolvendo `HMONITOR`, abra stdafx. h no `TCProps` projeto e substitua:
    >
    > ```cpp
    > #ifndef WINVER
    > #define WINVER 0x0400
    > #endif
    > ```
    >
    > por
    >
    > ```cpp
    > #ifndef WINVER
    > #define WINVER 0x0500
    > #define _WIN32_WINNT 0x0500
    > #endif
    > ```

1. No **contêiner de teste**, no menu **Editar** , clique em **Inserir novo controle**.

1. Localize seu controle, que será chamado `PolyCtl class`e clique em **OK**. Você verá um triângulo verde dentro de um círculo.

Tente alterar o número de lados seguindo o próximo procedimento. Para modificar propriedades em uma interface dupla a partir do **contêiner de teste**, use **métodos Invoke**.

### <a name="to-modify-a-controls-property-from-within-the-test-container"></a>Para modificar a propriedade de um controle de dentro do contêiner de teste

1. Em **contêiner de teste**, clique em **invocar métodos** no menu **controle** .

    A caixa de diálogo **método de invocação** é exibida.

1. Selecione a versão **propput** da propriedade **lados** na caixa de listagem suspensa **nome do método** .

1. Digite `5` na caixa **valor do parâmetro** , clique em **definir valor**e clique em **invocar**.

Observe que o controle não é alterado. Embora você tenha alterado o número de lados internamente definindo a `m_nSides` variável, isso não fazia com que o controle fosse redesenhado. Se você alternar para outro aplicativo e voltar para o **contêiner de teste**, verá que o controle foi repintado e tem o número correto de lados.

Para corrigir esse problema, adicione uma chamada à `FireViewChange` função, definida em `IViewObjectExImpl`, depois de definir o número de lados. Se o controle estiver em execução em sua própria janela `FireViewChange` , o chamará o `InvalidateRect` método diretamente. Se o controle estiver executando sem janela, o `InvalidateRect` método será chamado na interface do site do contêiner. Isso força o controle a ser redesenhado.

### <a name="to-add-a-call-to-fireviewchange"></a>Para adicionar uma chamada para FireViewChange

1. Atualize PolyCtl. cpp adicionando a chamada para `FireViewChange` ao `put_Sides` método. Quando você terminar, o `put_Sides` método deverá ser assim:

    [!code-cpp[NVC_ATL_Windowing#55](../atl/codesnippet/cpp/changing-the-drawing-code-atl-tutorial-part-4_9.cpp)]

Depois de `FireViewChange`adicionar, recompile e tente novamente o controle no contêiner de teste do controle ActiveX. Desta vez, quando você altera o número de lados e `Invoke`clica, você deve ver a alteração do controle imediatamente.

Na próxima etapa, você adicionará um evento.

[Voltar à etapa 3](../atl/adding-a-property-to-the-control-atl-tutorial-part-3.md) &#124; [na etapa 5](../atl/adding-an-event-atl-tutorial-part-5.md)

## <a name="see-also"></a>Confira também

[Tutorial](../atl/active-template-library-atl-tutorial.md)<br/>
[Testando Propriedades e eventos com contêiner de teste](../mfc/testing-properties-and-events-with-test-container.md)
