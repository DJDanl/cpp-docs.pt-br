---
title: Criando um aplicativo MFC no estilo de navegador da Web
ms.date: 06/25/2018
f1_keywords:
- vc.appwiz.mfcweb.project
helpviewer_keywords:
- MFC, Web applications
- Web browsers, creating from MFC architecture
- Web browsers
- Web applications [MFC], creating
ms.assetid: 257f8c03-33c3-428c-832e-0b70aff6168d
ms.openlocfilehash: e02e928f65ab4cd918e730135abc62ed3237decf
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80215118"
---
# <a name="creating-a-web-browser-style-mfc-application"></a>Criando um aplicativo MFC no estilo de navegador da Web

Um aplicativo de estilo de navegador da Web pode acessar informações da Internet (como documentos HTML ou ativos) ou uma intranet, bem como pastas no sistema de arquivos local e em uma rede. Derivando a classe de exibição do aplicativo de [CHtmlView](../../mfc/reference/chtmlview-class.md), efetivamente você torna o aplicativo um navegador da Web fornecendo a exibição com o controle WebBrowser.

## <a name="to-create-a-web-browser-application-based-on-the-mfc-documentview-architecture"></a>Para criar um aplicativo de navegador da Web baseado na arquitetura de documento/exibição do MFC

1. Siga as instruções em [criando um aplicativo MFC](../../mfc/reference/creating-an-mfc-application.md).

1. Na página [tipo de aplicativo](../../mfc/reference/application-type-mfc-application-wizard.md) do assistente de aplicativo MFC, certifique-se de que a caixa de **arquitetura de documento/exibição** esteja selecionada. (Você pode escolher um **único documento** ou **vários documentos**, mas não **com base na caixa de diálogo**.)

1. Na página [examinar classes geradas](../../mfc/reference/generated-classes-mfc-application-wizard.md) , use o menu suspenso **classe Base** para selecionar `CHtmlView`.

1. Selecione qualquer outra opção que você queira embutir no aplicativo esqueleto.

1. Clique em **Concluir**.

O controle WebBrowser dá suporte à navegação na Web por meio de hiperlinks e navegação por URL (Uniform Resource Locator). O controle mantém uma lista de histórico que permite ao usuário navegar para frente e para trás por meio de sites, pastas e documentos navegados anteriormente. O controle lida diretamente com a navegação, os hiperlinks, as listas de histórico, os favoritos e a segurança. Os aplicativos podem usar o controle WebBrowser como um contêiner de documento ativo para hospedar documentos ativos também. Assim, documentos com formatação avançada, como planilhas do Microsoft Excel ou documentos do Word, podem ser abertos e editados no lugar de dentro do controle WebBrowser. O controle WebBrowser também é um contêiner de controle ActiveX que pode hospedar qualquer controle ActiveX.

> [!NOTE]
> O controle ActiveX do WebBrowser (e, portanto, `CHtmlView`) está disponível somente para aplicativos executados em versões do Windows nas quais o Internet Explorer 4,0 ou posterior foi instalado.

Como `CHtmlView` simplesmente implementa o controle Microsoft Web browser, seu suporte para impressão não é como outras classes derivadas de [cvisualização](../../mfc/reference/cview-class.md). Em vez disso, o controle WebBrowser implementa a interface do usuário da impressora e a impressão. Como resultado, `CHtmlView` não dá suporte à visualização de impressão, e a estrutura não fornece outras funções de suporte de impressão: por exemplo, [cvisualização:: OnPreparePrinting](../../mfc/reference/cview-class.md#onprepareprinting), [Cvisualização:: OnBeginPrinting](../../mfc/reference/cview-class.md#onbeginprinting)e [cvisualização:: OnEndPrinting](../../mfc/reference/cview-class.md#onendprinting), que estão disponíveis em outros aplicativos MFC.

`CHtmlView` atua como um wrapper para o controle do navegador da Web, que fornece ao seu aplicativo uma exibição em uma página da Web ou em HTML. O assistente cria uma substituição para a função [OnInitialUpdate](../../mfc/reference/cview-class.md#oninitialupdate) na classe View, fornecendo um link de navegação para o site da Microsoft C++ Visual:

```cpp
void CWebView::OnInitialUpdate()
{
    CHtmlView::OnInitialUpdate();

    // TODO: This code navigates to a popular spot on the web.
    // Change the code to go where you'd like.
    Navigate2(_T("http://www.docs.microsoft.com/"),
        NULL,
        NULL);
}
```

Você pode substituir este site por um de seus próprios ou pode usar a função de membro [LoadFromResource](../../mfc/reference/chtmlview-class.md#loadfromresource) para abrir uma página HTML que reside no script de recurso do projeto como o conteúdo padrão para a exibição. Por exemplo:

```cpp
void CWebView::OnInitialUpdate()
{
    CHtmlView::OnInitialUpdate();

    // TODO: This code navigates to a popular spot on the web.
    // Change the code to go where you'd like.
    LoadFromResource(IDR_HTML1);
}
```

## <a name="see-also"></a>Confira também

[Exemplo de MFCIE do MFC](https://github.com/Microsoft/VCSamples/tree/master/VC2010Samples/MFC/internet)<br/>
[Assistente de aplicativo do MFC](../../mfc/reference/mfc-application-wizard.md)<br/>
[Defina propriedades de build e compilador](../../build/working-with-project-properties.md)<br/>
[Páginas de propriedade](../../build/reference/property-pages-visual-cpp.md)<br/>
[Defina propriedades de build e compilador](../../build/working-with-project-properties.md)
