---
title: Adicionando um controle (ATL Tutorial, parte 2) | Microsoft Docs
ms.custom: get-started-article
ms.date: 11/04/2016
ms.technology:
- cpp-atl
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: c9575a75-1064-41f1-9697-7aada560c669
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d3b8c7eb59579363ce3580c7319b80be2557a30d
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
ms.locfileid: "32358570"
---
# <a name="adding-a-control-atl-tutorial-part-2"></a>Adicionando um controle (Tutorial ATL, parte 2)
Nesta etapa, você adicionar um controle ao seu projeto, compilá-lo e testá-lo em uma página da Web.  
  
## <a name="procedures"></a>Procedimentos  
  
#### <a name="to-add-an-object-to-an-atl-project"></a>Para adicionar um objeto para um projeto de ATL  
  
1.  No modo de exibição de classe, clique com botão direito no projeto de polígono.  
  
2.  Aponte para **adicionar** no menu de atalho e clique em **Novo Item** no submenu.  
  
     A caixa de diálogo **Adicionar Novo Item** é exibida. As categorias de outro objeto são listadas na estrutura de árvore à esquerda.  
  
3.  Clique o **ATL** pasta.  
  
4.  Na lista de modelos no lado direito, selecione **controle ATL**. Clique em **Adicionar**. O Assistente de controle ATL será aberto e você pode configurar o controle.  
  
5.  Tipo `PolyCtl` como o nome curto e observe que os outros campos são preenchidos automaticamente. Não clique **concluir** ainda, pois você precisa fazer algumas alterações.  
  
 O Assistente de controle ATL **nomes** página contém os seguintes campos:  
  
|Campo|Conteúdo|  
|-----------|--------------|  
|**Nome curto**|O nome inserido para o controle.|  
|**Class**|O nome de classe C++ criado para implementar o controle.|  
|**arquivo. h**|O arquivo criado para conter a definição de classe do C++.|  
|**arquivo. cpp**|O arquivo criado para conter a implementação da classe C++.|  
|**CoClass**|O nome da classe de componente para este controle.|  
|**Interface**|O nome da interface em que o controle implementar suas propriedades e métodos personalizados.|  
|**Tipo**|Uma descrição para o controle.|  
|**ProgID**|O nome legível que pode ser usado para pesquisar o CLSID do controle.|  
  
 Será necessário fazer configurações adicionais no Assistente de controle ATL.  
  
#### <a name="to-enable-support-for-rich-error-information-and-connection-points"></a>Para habilitar o suporte para as informações de erros e conexão pontos  
  
1.  Clique em **opções** para abrir o **opções** página.  
  
2.  Selecione o **pontos de Conexão** caixa de seleção. Isso criará o suporte para uma interface de saída no arquivo IDL.  
  
 Você também pode fazer o controle inserível, o que significa que ele pode ser inserido em aplicativos que dão suporte a objetos inseridos, como Excel ou Word.  
  
#### <a name="to-make-the-control-insertable"></a>Para tornar o controle inserível  
  
1.  Clique em **aparência** para abrir o **aparência** página.  
  
2.  Selecione o **inserível** caixa de seleção.  
  
 O polígono exibido pelo objeto terá uma cor sólida, você precisará adicionar um `Fill Color` propriedade de estoque.  
  
#### <a name="to-add-a-fill-color-stock-property-and-create-the-control"></a>Para adicionar uma propriedade de estoque de cor de preenchimento e criar o controle  
  
1.  Clique em **propriedades de estoque** para abrir o **propriedades de estoque** página.  
  
2.  Em **não tem suporte**, role para baixo a lista de propriedades de estoque possíveis. Clique duas vezes em `Fill Color` movê-lo para o **com suporte** lista.  
  
3.  Isso conclui as opções para o controle. Clique em **Finalizar**.  
  
 Como o Assistente para criar o controle, várias alterações de código e adições de arquivos ocorreram. Os seguintes arquivos foram criados:  
  
|Arquivo|Descrição|  
|----------|-----------------|  
|PolyCtl.h|Contém a maior parte da implementação da classe C++ `CPolyCtl`.|  
|PolyCtl.cpp|Contém as partes restantes do `CPolyCtl`.|  
|PolyCtl.rgs|Um arquivo de texto que contém o script de registro usado para registrar o controle.|  
|PolyCtl.htm|Uma página da Web que contém uma referência para o controle recém-criado.|  
  
 O assistente também executou as seguintes alterações de código:  
  
-   Adicionado um `#include` instrução aos arquivos Stdafx. h e stdafx.cpp para incluir o ATL arquivos necessária para dar suporte aos controles.  
  
-   Polygon.idl alterada para incluir os detalhes do novo controle.  
  
-   Adicionado o novo controle ao mapa de objeto em Polygon.cpp.  
  
 Agora você pode criar o controle para ver em ação.  
  
## <a name="building-and-testing-the-control"></a>Compilar e testar o controle  
  
#### <a name="to-build-and-test-the-control"></a>Para compilar e testar o controle  
  
1.  No **criar** menu, clique em **criar polígono**.  
  
     Quando o controle termina a criação, clique com botão direito PolyCtl.htm em **Solution Explorer** e selecione **exibir no navegador**. A página da Web em HTML que contém o controle será exibida. Você deve ver uma página com o título "Página de teste 8.0 ATL para objeto PolyCtl" e o texto **PolyCtl**. Este é seu controle.  
  
> [!NOTE]
>  Quando concluir este tutorial, se você receber uma mensagem de erro onde o arquivo DLL não pode ser criado, feche o arquivo PolyCtl.htm e o contêiner de teste do controle ActiveX e compile a solução novamente. Se você ainda não é possível criar a DLL, reinicialize o computador ou fazer logoff (se você estiver usando os serviços de Terminal).  
  
 Em seguida, você irá adicionar uma propriedade personalizada para o controle.  
  
 [Para a etapa 1](../atl/creating-the-project-atl-tutorial-part-1.md) &#124; [na etapa 3](../atl/adding-a-property-to-the-control-atl-tutorial-part-3.md)  
  
## <a name="see-also"></a>Consulte também  
 [Tutorial](../atl/active-template-library-atl-tutorial.md)

