---
title: Colocando o controle em uma página da Web (ATL Tutorial, parte 7) | Microsoft Docs
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 50dc4c95-c95b-4006-b88a-9826f7bdb222
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0cd4076ac34af6ee4b19687f401376265bf0e872
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32362578"
---
# <a name="putting-the-control-on-a-web-page-atl-tutorial-part-7"></a>Colocando o controle em uma página da Web (Tutorial ATL, parte 7)
O controle está concluído. Para ver o controle de trabalho em uma situação real, coloque-o em uma página da Web. Um arquivo HTML que contém o controle foi criado quando você definiu seu controle. Abra o arquivo PolyCtl.htm **Solution Explorer**, e você pode ver o controle em uma página da Web.  
  
 Nesta etapa, você será o script a página da Web para responder a eventos. Você também modificará o controle para permitir que o Internet Explorer saibam que o controle é seguro para script.  
  
## <a name="scripting-the-web-page"></a>A página da Web de script  
 O controle não fazer nada ainda, portanto, altere a página da Web para responder aos eventos que você enviar.  
  
#### <a name="to-script-the-web-page"></a>Para gerar script de página da Web  
  
1.  Abra PolyCtl.htm e selecione o modo de exibição HTML. Adicione as seguintes linhas ao código HTML. Eles devem ser adicionados depois `</OBJECT>` mas antes `</BODY>`.  
  
 ```  
 
 <SCRIPT LANGUAGE="VBScript">  
 <!--  
    Sub PolyCtl_ClickIn(x, y)  
    PolyCtl.Sides = PolyCtl.Sides + 1  
    End Sub  
    Sub PolyCtl_ClickOut(x, y)  
    PolyCtl.Sides = PolyCtl.Sides - 1  
    End Sub  
 -->  
 </SCRIPT>  
 ```  
  
2.  Salve o arquivo HTM.  
  
 Você adicionou um código VBScript que obtém a propriedade lados do controle e aumenta o número de lados por um se clique dentro do controle. Se você clicar fora do controle, você reduzir o número de lados por um.  
  
## <a name="indicating-that-the-control-is-safe-for-scripting"></a>Indicando que o controle é seguro para script  
 Você pode exibir a página da Web com o controle no Internet Explorer ou, mais conveniente, usam a exibição do navegador da Web embutida no Visual C++. Para ver seu controle no modo de exibição de navegador da Web, clique com botão direito PolyCtl.htm e clique em **exibir no navegador**.  
  
 Com base em suas configurações de segurança do Internet Explorer, você poderá receber um alerta de segurança caixa de diálogo informando que o controle pode não ser seguro para script e pode potencialmente danificar. Por exemplo, se você tivesse um controle que é exibido um arquivo, mas também tinha uma `Delete` método excluiu um arquivo, seria seguro se apenas exibidos em uma página. Não seria seguro para script, no entanto, porque alguém poderia chamar o `Delete` método.  
  
> [!IMPORTANT]
>  Para este tutorial, você pode alterar as configurações de segurança no Internet Explorer para executar controles ActiveX não marcados como seguros. No painel de controle, clique em **propriedades da Internet** e clique em **segurança** para alterar as configurações apropriadas. Quando você concluiu o tutorial, altere as configurações de segurança para seu estado original.  
  
 Você pode programaticamente de alerta do Internet Explorer que isso não é necessário exibir a caixa de diálogo de alerta de segurança para este controle específico. Você pode fazer isso com o `IObjectSafety` interface e ATL fornece uma implementação desta interface na classe [IObjectSafetyImpl](../atl/reference/iobjectsafetyimpl-class.md). Para adicionar a interface para o controle, adicione `IObjectSafetyImpl` à lista de classes herdadas e adicione uma entrada para ele em seu mapa de COM.  
  
#### <a name="to-add-iobjectsafetyimpl-to-the-control"></a>Para adicionar IObjectSafetyImpl ao controle  
  
1.  Adicione a seguinte linha ao final da lista de classes herdadas em PolyCtl.h e adicione uma vírgula para a linha anterior:  
  
 [!code-cpp[NVC_ATL_Windowing#62](../atl/codesnippet/cpp/putting-the-control-on-a-web-page-atl-tutorial-part-7_1.h)]  
  
2.  Adicione a seguinte linha ao mapa em PolyCtl.h COM:  
  
 [!code-cpp[NVC_ATL_Windowing#63](../atl/codesnippet/cpp/putting-the-control-on-a-web-page-atl-tutorial-part-7_2.h)]  
  
## <a name="building-and-testing-the-control"></a>Compilar e testar o controle  
 Crie o controle. Depois que a compilação for concluída, abra novamente PolyCtl.htm na exibição do navegador. Neste momento, a página da Web deve ser exibida diretamente sem a caixa de diálogo alerta de segurança. Clique dentro do polígono; o número de lados aumenta em um. Clique fora do polígono para reduzir o número de lados. Se você tentar reduzir o número de lados abaixo três, você verá a mensagem de erro que você definir.  
  
 [Para a etapa 6](../atl/adding-a-property-page-atl-tutorial-part-6.md)  
  
## <a name="next-steps"></a>Próximas etapas  
 Isso conclui o tutorial da ATL. Para obter links para obter mais informações sobre ATL, consulte o [página inicial do ATL](../atl/active-template-library-atl-concepts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Tutorial](../atl/active-template-library-atl-tutorial.md)

