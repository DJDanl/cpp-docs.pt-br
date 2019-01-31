---
title: Solução de problemas do Editor de caixa de diálogo (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- controls [C++], troubleshooting
- Dialog Editor [C++], troubleshooting
- dialog boxes [C++], troubleshooting
- InitCommonControls
- RichEdit 1.0 control
- rich edit controls [C++], RichEdit 1.0
ms.assetid: 21882868-5ac4-4a41-a4a6-eaaa059402ea
ms.openlocfilehash: fe0fe704b5c17d0db4e3419f29d21f0e60bc4211
ms.sourcegitcommit: 5270117dbecc4c49bca0cf10b927bae3c9930038
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/31/2019
ms.locfileid: "55484949"
---
# <a name="troubleshooting-the-dialog-editor-c"></a>Solução de problemas do Editor de caixa de diálogo (C++)

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*. Para obter informações sobre como adicionar manualmente os arquivos de recursos a projetos gerenciados, acessar recursos, exibir recursos estáticos e atribuir cadeias de caracteres de recurso a propriedades, consulte [criando arquivos de recursos para aplicativos de área de trabalho](/dotnet/framework/resources/creating-resource-files-for-desktop-apps). Para obter informações sobre globalização e localização de recursos em aplicativos gerenciados, consulte [Globalizing e Localizando aplicativos do .NET Framework](/dotnet/standard/globalization-localization/index).

Abaixo estão alguns problemas dos quais você deve estar ciente ao trabalhar em C++ **caixa de diálogo** editor:

## <a name="adding-controls-to-a-dialog-causes-the-dialog-to-no-longer-function"></a>Adicionando controles a uma caixa de diálogo faz com que a caixa de diálogo não funcionem

Depois de adicionar um controle comum ou um controle rich edit para uma caixa de diálogo, ela não aparecerá quando você testa a caixa de diálogo ou a própria caixa de diálogo não aparecerá.

### <a name="example-of-the-problem"></a>Exemplo do problema

1. Crie um projeto do Win32, modificando as configurações do aplicativo, portanto, você cria um aplicativo do Windows (não um aplicativo de console).

1. Na [exibição de recurso](../windows/resource-view-window.md), clique duas vezes no arquivo. rc.

1. Sob a opção de caixa de diálogo, clique duas vezes o **sobre** caixa.

1. Adicionar um **controle de endereço IP** à caixa de diálogo.

1. Salvar e **recompilar tudo**.

1. Execute o programa.

1. Na caixa de diálogo **ajudar** menu, clique no **sobre** comando; nenhuma caixa de diálogo caixa é exibida.

### <a name="the-cause"></a>A causa

Atualmente, o **caixa de diálogo** editor automaticamente não adiciona código ao seu projeto quando você arrasta e solta os seguintes controles comuns ou controles em uma caixa de diálogo de edição avançada. Nem o Visual Studio fornece um erro ou aviso quando esse problema ocorre. Para corrigir, adicione o código para o controle manualmente.

||||
|-|-|-|
|Controle deslizante|Controle de árvore|Seletor de data e hora|
|Controle de rotação|Controle de guia|Calendário mensal|
|Controle de progresso|Controle de animação|Controle de endereço IP|
|Tecla de acesso|Controle de edição avançada|Caixa de combinação estendida|
|Controle de lista|Controle de edição avançada 2.0|Controle personalizado|

### <a name="fix-for-common-controls"></a>Correção para controles comuns

Para usar controles comuns em uma caixa de diálogo, você precisará chamar [InitCommonControlsEx](/windows/desktop/api/commctrl/nf-commctrl-initcommoncontrolsex) ou `AFXInitCommonControls` antes de criar a caixa de diálogo.

### <a name="fix-for-richedit-controls"></a>Correção para controles RichEdit

Você deve chamar `LoadLibrary` para controles de edição avançados. Para obter mais informações, consulte [sobre como editar controles sofisticados](/windows/desktop/Controls/about-rich-edit-controls) no SDK do Windows e [visão geral do controle de edição de Rich](../mfc/overview-of-the-rich-edit-control.md).

### <a name="requirements"></a>Requisitos

Win32

## <a name="using-the-richedit-10-control-with-mfc"></a>Usando o controle RichEdit 1.0 com MFC

Para usar um controle RichEdit, você deve primeiro chamar [AfxInitRichEdit2](../mfc/reference/application-information-and-management.md#afxinitrichedit2) para carregar o controle RichEdit 2.0 (RICHED20. DLL), ou chamar [AfxInitRichEdit](../mfc/reference/application-information-and-management.md#afxinitrichedit) para carregar o controle de 1.0 RichEdit mais antigos (RICHED32. DLL).

Você pode usar o atual [CRichEditCtrl](../mfc/reference/cricheditctrl-class.md) classe com o controle RichEdit 1.0 mais antigo, mas `CRichEditCtrl` foi projetado apenas para dar suporte ao controle RichEdit 2.0. Como RichEdit 1.0 e 2.0 de RichEdit são semelhantes, a maioria dos métodos funcionará. No entanto, observe que há algumas diferenças entre os controles de 1.0 e 2.0, portanto, alguns métodos podem funcionar incorretamente ou não funcionar em todos os.

### <a name="requirements"></a>Requisitos

MFC

## <a name="see-also"></a>Consulte também

[Editor de caixa de diálogo](../windows/dialog-editor.md)