---
title: Adicionando uma propriedade ao controle (Tutorial ATL, parte 3)
ms.custom: get-started-article
ms.date: 09/26/2018
ms.assetid: f775fe34-103b-4f07-9999-400e987ee030
ms.openlocfilehash: b5f9f9c8fde44dd67a9a05aeae0f91fb7b5f2f4d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62252600"
---
# <a name="adding-a-property-to-the-control-atl-tutorial-part-3"></a>Adicionando uma propriedade ao controle (Tutorial ATL, parte 3)

`IPolyCtl` é a interface que contém métodos do controle e propriedades personalizados, e você irá adicionar uma propriedade a ele.

### <a name="to-add-the-property-definitions-to-your-project"></a>Para adicionar as definições de propriedade ao seu projeto

1. Na **Class View**, expanda o `Polygon` branch.

1. Clique com botão direito `IPolyCtl`.

1. No menu de atalho, clique em **Add**e, em seguida, clique em **adicionar propriedade**. O **adicionar propriedade** assistente será exibida.

1. Tipo de `Sides` como o **nome da propriedade**.

1. Na lista suspensa de **tipo de propriedade**, selecione `short`.

1. Clique em **Okey** para terminar de adicionar a propriedade.

1. Partir **Gerenciador de soluções**, abra Polygon.idl e substitua as seguintes linhas no final do `IPolyCtl : IDispatch` interface:

    ```cpp
    short get_Sides();
    void set_Sides(short value);
    ```

    with

    ```cpp
    [propget, id(1), helpstring("property Sides")] HRESULT Sides([out, retval] short *pVal);
    [propput, id(1), helpstring("property Sides")] HRESULT Sides([in] short newVal);
    ```

1. Partir **Gerenciador de soluções**, abra o polyctl. H e adicione as seguintes linhas após a definição da `m_clrFillColor`:

    [!code-cpp[NVC_ATL_Windowing#44](../atl/codesnippet/cpp/adding-a-property-to-the-control-atl-tutorial-part-3_1.h)]

Embora agora você tem funções esqueleto para definir e recuperar a propriedade e uma variável para armazenar a propriedade, você deve implementar as funções adequadamente.

### <a name="to-update-the-get-and-put-methods"></a>Atualizar get e put métodos

1. Defina o valor padrão de `m_nSides`. Fazer com que o padrão de forma um triângulo com a adição de uma linha para o construtor em polyctl. H:

    [!code-cpp[NVC_ATL_Windowing#45](../atl/codesnippet/cpp/adding-a-property-to-the-control-atl-tutorial-part-3_2.h)]

1. Implemente os métodos `Get` e `Put`. O `get_Sides` e `put_Sides` declarações de função foram adicionadas ao polyctl. H. Agora, adicione o código para `get_Sides` e `put_Sides` para PolyCtl.cpp com o seguinte:

    [!code-cpp[NVC_ATL_Windowing#46](../atl/codesnippet/cpp/adding-a-property-to-the-control-atl-tutorial-part-3_3.cpp)]

O `get_Sides` método retorna o valor atual da `Sides` propriedade por meio de `pVal` ponteiro. No `put_Sides` método, o código garante que o usuário está definindo o `Sides` propriedade para um valor aceitável. O mínimo deve ser 3 e como uma matriz de pontos será usada para cada lado, 100 é um limite razoável para um valor máximo.

Agora você tem uma propriedade chamada `Sides`. Na próxima etapa, você irá alterar o código de desenho para usá-lo.

[Volte para a etapa 2](../atl/adding-a-control-atl-tutorial-part-2.md) &#124; [para a etapa 4](../atl/changing-the-drawing-code-atl-tutorial-part-4.md)

## <a name="see-also"></a>Consulte também

[Tutorial](../atl/active-template-library-atl-tutorial.md)
