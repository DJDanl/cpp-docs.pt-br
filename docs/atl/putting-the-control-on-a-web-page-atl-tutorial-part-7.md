---
title: Colocando o controle em uma página da Web (Tutorial ATL, parte 7)
ms.custom: get-started-article
ms.date: 05/06/2019
ms.assetid: 50dc4c95-c95b-4006-b88a-9826f7bdb222
ms.openlocfilehash: db6dcc57ff9f3748d802e76617ef18dea8f9506c
ms.sourcegitcommit: 6cf0c67acce633b07ff31b56cebd5de3218fd733
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/24/2019
ms.locfileid: "67344351"
---
# <a name="putting-the-control-on-a-web-page-atl-tutorial-part-7"></a>Colocando o controle em uma página da Web (Tutorial ATL, parte 7)

O controle está concluído. Para ver seu controle funcionar em uma situação de mundo real, coloque-o em uma página da Web. Um arquivo HTML que contém o controle foi criado quando você definiu o seu controle. Abrir o arquivo Polyctl **Gerenciador de soluções**, e você pode ver seu controle em uma página da Web.

Nesta etapa, você adicionar funcionalidade ao controle e a página da Web para responder a eventos de script. Você também modificará o controle para permitir que o Internet Explorer sabe que o controle é seguro para script.

## <a name="adding-new-functionality"></a>Adicionando novas funcionalidades

### <a name="to-add-control-features"></a>Para adicionar recursos de controle

1. Abra PolyCtl.cpp e substitua o código a seguir:

    ```cpp
    if (PtInRegion(hRgn, xPos, yPos))
        Fire_ClickIn(xPos, yPos);
    else
        Fire_ClickOut(xPos, yPos);
    ```

    with

    ```cpp
    short temp = m_nSides;
    if (PtInRegion(hRgn, xPos, yPos))
    {
        Fire_ClickIn(xPos, yPos);
        put_Sides(++temp);
    }
    else
    {
        Fire_ClickOut(xPos, yPos);
        put_Sides(--temp);
    }
    ```

A forma agora adicionará ou removerá os lados, dependendo de onde você clicar.

## <a name="scripting-the-web-page"></a>A página da Web de script

O controle não faz nada ainda, portanto, altere a página da Web para responder aos eventos que você enviar.

### <a name="to-script-the-web-page"></a>Para gerar script de página da Web

1. Abra o Polyctl. e selecione o modo de exibição HTML. Adicione as seguintes linhas ao código HTML. Eles devem ser adicionados após `</OBJECT>` , mas antes `</BODY>`.

    ```html
    <SCRIPT LANGUAGE="VBScript">
    <!--
        Sub PolyCtl_ClickIn(x, y)
            MsgBox("Clicked (" & x & ", " & y & ") - adding side")
        End Sub
        Sub PolyCtl_ClickOut(x, y)
            MsgBox("Clicked (" & x & ", " & y & ") - removing side")
        End Sub
    -->
    </SCRIPT>
    ```

1. Salve o arquivo HTM.

Você adicionou código VBScript que obtém a propriedade dos lados do controle. Ele aumenta o número de lados por um se você clicar no controle. Se você clicar fora do controle, você reduzir o número de lados por um.

## <a name="indicating-that-the-control-is-safe-for-scripting"></a>Que indica que o controle é seguro para script

Você pode exibir a página da Web com o controle apenas no Internet Explorer. Outros navegadores não dão suporte a controles ActiveX devido a vulnerabilidades de segurança.

> [!NOTE]
> Se o controle não estiver visível, sabe que alguns navegadores exigem ajustes de configurações para executar controles ActiveX. Consulte a documentação do navegador sobre como habilitar os controles ActiveX.

Com base em suas configurações de segurança atuais do Internet Explorer, você pode receber uma caixa de diálogo de alerta de segurança. Ele declara que o controle pode não ser seguro para script e poderia potencialmente causar danos. Por exemplo, se você tivesse um controle que exibia um arquivo, mas também tinha um `Delete` método que um arquivo excluído, seria seguro se você simplesmente o exibisse em uma página. Não seria seguro criar um script, no entanto, porque alguém poderia chamar o `Delete` método.

> [!IMPORTANT]
> Para este tutorial, você pode alterar as configurações de segurança no Internet Explorer para executar controles ActiveX não marcados como seguros. No painel de controle, clique em **propriedades da Internet** e clique em **segurança** para alterar as configurações apropriadas. Quando você concluiu o tutorial, altere as configurações de segurança para seu estado original.

Você pode programaticamente alertar do Internet Explorer que não precisa exibir a caixa de diálogo de alerta de segurança para este controle específico. Você pode fazer isso usando o `IObjectSafety` interface. ATL fornece uma implementação dessa interface na classe [IObjectSafetyImpl](../atl/reference/iobjectsafetyimpl-class.md). Para adicionar a interface ao seu controle, adicione `IObjectSafetyImpl` à sua lista de classes herdadas e adicione uma entrada para ele no seu mapa COM.

### <a name="to-add-iobjectsafetyimpl-to-the-control"></a>Para adicionar IObjectSafetyImpl ao controle

1. Adicione a seguinte linha ao final da lista de classes herdadas em polyctl. H e adicione uma vírgula na linha anterior:

    [!code-cpp[NVC_ATL_Windowing#62](../atl/codesnippet/cpp/putting-the-control-on-a-web-page-atl-tutorial-part-7_1.h)]

1. Adicione a seguinte linha ao mapa de COM em polyctl. H:

    [!code-cpp[NVC_ATL_Windowing#63](../atl/codesnippet/cpp/putting-the-control-on-a-web-page-atl-tutorial-part-7_2.h)]

## <a name="building-and-testing-the-control"></a>Compilação e teste do controle

Compile o controle. Depois que a compilação for concluída, abra Polyctl no modo de exibição de navegador novamente. Neste momento, a página da Web deve ser exibida diretamente sem a **alerta de segurança** caixa de diálogo. Se você clicar dentro do polígono, o número de lados aumenta em um. Clique fora do polígono para reduzir o número de lados.

[Volte para a etapa 6](../atl/adding-a-property-page-atl-tutorial-part-6.md)

## <a name="next-steps"></a>Próximas etapas

Esta etapa conclui o tutorial da ATL. Para obter links para obter mais informações sobre o ATL, consulte o [página inicial do ATL](../atl/active-template-library-atl-concepts.md).

## <a name="see-also"></a>Consulte também

[Tutorial](../atl/active-template-library-atl-tutorial.md)
