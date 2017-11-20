---
title: "Adicionando uma página de propriedades (ATL Tutorial, parte 6) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: get-started-article
dev_langs: C++
ms.assetid: df80d255-e7ea-49d9-b940-3f012e90cf9b
caps.latest.revision: "15"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 90023486dd8e34195b2dd9f8a788f3f76235d407
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="adding-a-property-page-atl-tutorial-part-6"></a>Adicionando uma página de propriedades (Tutorial ATL, parte 6)
Páginas de propriedades são implementadas como objetos separados COM, que permitem que eles deve ser compartilhado, se necessário. Nesta etapa, você fará as seguintes tarefas para adicionar uma página de propriedades para o controle:  
  
-   Criando o recurso de página de propriedade  
  
-   Adicionando código para criar e gerenciar a página de propriedades  
  
-   Adicionando a página de propriedades para o controle  
  
## <a name="creating-the-property-page-resource"></a>Criando o recurso de página de propriedade  
 Para adicionar uma página de propriedades para o controle, use o Assistente para Adicionar classe do ATL.  
  
#### <a name="to-add-a-property-page"></a>Para adicionar uma página de propriedades  
  
1.  No Gerenciador de soluções, clique com botão direito polígono.  
  
2.  No menu de atalho, clique em **adicionar**e, em seguida, clique em **Adicionar classe**.  
  
3.  Na lista de modelos, selecione **página de propriedades ATL** e clique em **adicionar**.  
  
4.  Quando o Assistente de página de propriedades ATL for exibida, digite `PolyProp` como o **curto** nome.  
  
5.  Clique em **cadeias de caracteres** para abrir o **cadeias de caracteres** página e digite **& polígono** como o **título**.  
  
     O **título** da propriedade página é a cadeia de caracteres que aparece na guia da página. O **cadeia de caracteres Doc** é uma descrição que usa um quadro de propriedade para colocar em uma dica de ferramenta ou a linha de status. Observe que o quadro de propriedade padrão no momento não usar essa cadeia de caracteres, para que você pode deixá-la com o conteúdo padrão. Você não irá gerar um **arquivo de Ajuda** no momento, exclua a entrada na caixa de texto.  
  
6.  Clique em **concluir**, e o objeto de página de propriedade será criado.  
  
 São criados três arquivos a seguir:  
  
|Arquivo|Descrição|  
|----------|-----------------|  
|PolyProp.h|Contém a classe C++ `CPolyProp`, que implementa a página de propriedades.|  
|PolyProp.cpp|Inclui o arquivo PolyProp.h.|  
|PolyProp.rgs|O script de registro que registra o objeto de página de propriedade.|  
  
 As alterações de código a seguir também são feitas:  
  
-   A nova página de propriedade é adicionada ao mapa de entrada do objeto no Polygon.cpp.  
  
-   O `PolyProp` classe é adicionada ao arquivo Polygon.idl.  
  
-   O novo arquivo de script de registro PolyProp.rgs é adicionado para o recurso do projeto.  
  
-   Um modelo de caixa de diálogo é adicionado para o recurso de projeto para a página de propriedades.  
  
-   As cadeias de caracteres de propriedade que você especificou são adicionadas à tabela de cadeia de caracteres de recursos.  
  
 Agora, adicione os campos que você deseja exibir na página de propriedades.  
  
#### <a name="to-add-fields-to-the-property-page"></a>Para adicionar campos à página de propriedades  
  
1.  No Gerenciador de soluções, clique duas vezes no arquivo de recurso Polygon.rc. Isso abrirá a exibição de recursos.  
  
2.  No modo de exibição de recursos, expanda o nó de caixa de diálogo e clique duas vezes em IDD_POLYPROP. Observe que a caixa de diálogo que aparece está vazia, exceto um rótulo solicitando que você insira seus controles aqui.  
  
3.  Selecione esse rótulo e altere-o para ler `Sides:` alterando o **legenda** texto no **propriedades** janela.  
  
4.  Redimensione a caixa de rótulo para que ele se ajuste o tamanho do texto.  
  
5.  Arraste um controle de edição da caixa de ferramentas para a direita do rótulo.  
  
6.  Por fim, altere o **ID** do controle de edição para `IDC_SIDES` usando a janela Propriedades.  
  
 Isso conclui o processo de criação do recurso de página de propriedade.  
  
## <a name="adding-code-to-create-and-manage-the-property-page"></a>Adicionando código para criar e gerenciar a página de propriedades  
 Agora que você criou o recurso de página de propriedade, você precisa escrever o código de implementação.  
  
 Primeiro, habilite o `CPolyProp` classe para definir o número de lados em seu objeto quando o **aplicar** botão é pressionado.  
  
#### <a name="to-modify-the-apply-function-to-set-the-number-of-sides"></a>Para modificar a função aplicar para definir o número de lados  
  
1.  Substitua o `Apply` função em PolyProp.h com o código a seguir:  
  
     [!code-cpp[NVC_ATL_Windowing#58](../atl/codesnippet/cpp/adding-a-property-page-atl-tutorial-part-6_1.h)]  
  
 Uma página de propriedade pode ter mais de um cliente conectado a ele ao mesmo tempo, portanto, o `Apply` função efetua um loop e chama `put_Sides` em cada cliente com o valor recuperado da caixa de edição. Você está usando o [CComQIPtr](../atl/reference/ccomqiptr-class.md) classe, que executa o `QueryInterface` em cada objeto para obter o `IPolyCtl` de interface do **IUnknown** interface (armazenados no `m_ppUnk` matriz).  
  
 O código agora verifica a configuração de `Sides` propriedade funcionou. Se ele falhar, o código exibe uma caixa de mensagem exibindo detalhes do erro do **IErrorInfo** interface. Normalmente, um contêiner solicita um objeto para o **ISupportErrorInfo** interface e chamadas `InterfaceSupportsErrorInfo` primeiro para determinar se o objeto oferece suporte a informações de erro de configuração. Você pode ignorar esta tarefa.  
  
 [CComPtr](../atl/reference/ccomptr-class.md) ajuda a manipulando automaticamente a contagem de referência, portanto você não precisa chamar `Release` na interface. `CComBSTR`ajuda você com `BSTR` processamento, você não precisará executar o último `SysFreeString` chamar. Você também usar uma das várias classes de conversão de cadeia de caracteres, para que você pode converter o `BSTR` se necessário (Isso ocorre porque o `USES_CONVERSION` macro é o início da função).  
  
 Você também precisa definir o sinalizador da página de propriedades para indicar que o **aplicar** botão deve ser habilitado. Isso ocorre quando o usuário altera o valor de **lados** caixa de edição.  
  
#### <a name="to-handle-the-apply-button"></a>Para lidar com o botão Aplicar  
  
1.  No modo de exibição de classe, mouse CPolyProp e clique em **propriedades** no menu de atalho.  
  
2.  Na janela Propriedades, clique o **eventos** ícone.  
  
3.  Expanda o `IDC_SIDES` nó na lista de eventos.  
  
4.  Selecione `EN_CHANGE`e no menu suspenso para a direita, clique em  **\<Adicionar > OnEnChangeSides**. O `OnEnChangeSides` declaração do manipulador será adicionada ao Polyprop.h e a implementação de manipulador para Polyprop.cpp.  
  
 Em seguida, você modificará o manipulador.  
  
#### <a name="to-modify-the-onenchangesides-method"></a>Para modificar o método OnEnChangeSides  
  
1.  Adicione o seguinte código em Polyprop.cpp para o `OnEnChangeSides` método (excluindo qualquer código que o assistente inserido ali):  
  
     [!code-cpp[NVC_ATL_Windowing#59](../atl/codesnippet/cpp/adding-a-property-page-atl-tutorial-part-6_2.cpp)]  
  
 `OnEnChangeSides`será chamado quando um **WM_COMMAND** mensagem é enviada com o **EN_CHANGE** notificação para o `IDC_SIDES` controle. `OnEnChangeSides`em seguida, chama `SetDirty` e passa `TRUE` página agora foi alterada para indicar a propriedade e o **aplicar** botão deve ser habilitado.  
  
## <a name="adding-the-property-page-to-the-control"></a>Adicionando a página de propriedades para o controle  
 O Assistente para Adicionar classe do ATL e o Assistente de página de propriedades ATL não adicionam a página de propriedades para o controle para você automaticamente, porque pode haver vários controles em seu projeto. Você precisará adicionar uma entrada para mapa de propriedade do controle.  
  
#### <a name="to-add-the-property-page"></a>Para adicionar a página de propriedades  
  
1.  Abra PolyCtl.h e adicione esta linha ao mapa de propriedade:  
  
     [!code-cpp[NVC_ATL_Windowing#60](../atl/codesnippet/cpp/adding-a-property-page-atl-tutorial-part-6_3.h)]  
  
 Mapa de propriedade do controle agora tem essa aparência:  
  
 [!code-cpp[NVC_ATL_Windowing#61](../atl/codesnippet/cpp/adding-a-property-page-atl-tutorial-part-6_4.h)]  
  
 É possível adicionar um `PROP_PAGE` macro com CLSID de sua página de propriedades, mas se você usar o `PROP_ENTRY` macro conforme mostrado, o `Sides` o valor da propriedade também é salva quando o controle é salvo.  
  
 Os três parâmetros para a macro são a descrição da propriedade, o DISPID da propriedade e o CLSID da página de propriedades que tem a propriedade. Isso é útil se, por exemplo, você pode carregar o controle no Visual Basic e defina o número de lados em tempo de design. Como o número de lados é salva, quando você recarregar o projeto do Visual Basic, o número de lados será restaurado.  
  
## <a name="building-and-testing-the-control"></a>Compilar e testar o controle  
 Agora que o controle de compilação e inseri-lo no contêiner de teste do controle ActiveX. No contêiner de teste, no **editar** menu, clique em **PolyCtl objeto da classe**. A página de propriedades é exibido; Clique o **polígono** guia.  
  
 O **aplicar** botão é inicialmente desabilitado. Comece a digitar um valor na **lados** caixa e o **aplicar** botão será habilitado. Depois de terminar de inserir o valor, clique no **aplicar** botão. As alterações de exibição de controle e o **aplicar** botão novamente está desabilitado. Tente inserir um valor inválido. Você verá uma caixa de mensagem que contém a descrição do erro que você definir a partir de `put_Sides` função.  
  
 Em seguida, você colocará o controle em uma página da Web.  
  
 [Para a etapa 5](../atl/adding-an-event-atl-tutorial-part-5.md) &#124; [Na etapa 7](../atl/putting-the-control-on-a-web-page-atl-tutorial-part-7.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tutorial](../atl/active-template-library-atl-tutorial.md)

