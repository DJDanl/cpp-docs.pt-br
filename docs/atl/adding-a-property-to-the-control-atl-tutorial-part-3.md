---
title: Adicionando uma propriedade ao controle (Tutorial ATL, parte 3)
ms.custom: get-started-article
ms.date: 09/26/2018
ms.assetid: f775fe34-103b-4f07-9999-400e987ee030
ms.openlocfilehash: c5f71880f780e793cd77eb5a7571d31de4a8d01a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87218995"
---
# <a name="adding-a-property-to-the-control-atl-tutorial-part-3"></a>Adicionando uma propriedade ao controle (Tutorial ATL, parte 3)

`IPolyCtl`é a interface que contém os métodos e as propriedades personalizados do controle, e você adicionará uma propriedade a ele.

### <a name="to-add-the-property-definitions-to-your-project"></a>Para adicionar as definições de propriedade ao seu projeto

1. Em **modo de exibição de classe**, expanda a `Polygon` ramificação.

1. Clique com o botão direito do mouse `IPolyCtl` .

1. No menu de atalho, clique em **Adicionar**e, em seguida, clique em **Adicionar Propriedade**. O assistente para **Adicionar Propriedade** será exibido.

1. Digite `Sides` como o **nome da propriedade**.

1. Na lista suspensa do **tipo de propriedade**, selecione **`short`** .

1. Clique em **OK** para concluir a adição da propriedade.

1. Em **Gerenciador de soluções**, abra Polygon. idl e substitua as seguintes linhas no final da `IPolyCtl : IDispatch` interface:

    ```cpp
    short get_Sides();
    void set_Sides(short value);
    ```

    por

    ```cpp
    [propget, id(1), helpstring("property Sides")] HRESULT Sides([out, retval] short *pVal);
    [propput, id(1), helpstring("property Sides")] HRESULT Sides([in] short newVal);
    ```

1. Em **Gerenciador de soluções**, abra PolyCtl. h e adicione as seguintes linhas após a definição de `m_clrFillColor` :

    [!code-cpp[NVC_ATL_Windowing#44](../atl/codesnippet/cpp/adding-a-property-to-the-control-atl-tutorial-part-3_1.h)]

Embora agora você tenha funções de esqueleto para definir e recuperar a propriedade e uma variável para armazenar a propriedade, você deve implementar as funções adequadamente.

### <a name="to-update-the-get-and-put-methods"></a>Para atualizar os métodos get e put

1. Defina o valor padrão de `m_nSides` . Transforme a forma padrão em um triângulo adicionando uma linha ao Construtor em PolyCtl. h:

    [!code-cpp[NVC_ATL_Windowing#45](../atl/codesnippet/cpp/adding-a-property-to-the-control-atl-tutorial-part-3_2.h)]

1. Implemente os métodos `Get` e `Put`. As `get_Sides` declarações de função e foram `put_Sides` adicionadas a PolyCtl. h. Agora, adicione o código para `get_Sides` e `put_Sides` para PolyCtl. cpp com o seguinte:

    [!code-cpp[NVC_ATL_Windowing#46](../atl/codesnippet/cpp/adding-a-property-to-the-control-atl-tutorial-part-3_3.cpp)]

O `get_Sides` método retorna o valor atual da `Sides` Propriedade por meio do `pVal` ponteiro. No `put_Sides` método, o código garante que o usuário esteja definindo a `Sides` propriedade com um valor aceitável. O mínimo deve ser 3 e, como uma matriz de pontos será usada para cada lado, 100 é um limite razoável para um valor máximo.

Agora você tem uma propriedade chamada `Sides` . Na próxima etapa, você alterará o código de desenho para usá-lo.

[Volte para a etapa 2](../atl/adding-a-control-atl-tutorial-part-2.md) &#124; [na etapa 4](../atl/changing-the-drawing-code-atl-tutorial-part-4.md)

## <a name="see-also"></a>Confira também

[Tutorial](../atl/active-template-library-atl-tutorial.md)
