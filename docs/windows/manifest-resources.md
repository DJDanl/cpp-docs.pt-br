---
title: Recursos do manifesto (C++)
ms.date: 11/04/2016
helpviewer_keywords:
- manifest resources [C++]
- resources [C++], manifest
- resources [C++], opening
ms.assetid: 8615334c-22a0-44c0-93e0-5924528c9917
ms.openlocfilehash: 2d135cb2d512313f107eef7e95ec90d7972b68b4
ms.sourcegitcommit: bd637e9c39650cfd530520ea978a22fa4caa0e42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/07/2019
ms.locfileid: "55850184"
---
# <a name="manifest-resources-c"></a>Recursos do manifesto (C++)

Em projetos do C++ da área de trabalho, recursos de manifesto são arquivos XML que descrevem as dependências que um aplicativo usa. Por exemplo, no Visual Studio, o arquivo de manifesto gerado pelo assistente MFC define quais do controle comum do Windows DLLs o aplicativo deve usar, versão 5.0 ou 6.0:

```xml
<description>Your app description here</description>
<dependency>
    <dependentAssembly>
        <assemblyIdentity
            type="win32"
            name="Microsoft.Windows.Common-Controls"
            version="6.0.0.0"
            processorArchitecture="X86"
            publicKeyToken="6595b64144ccf1df"
            language="*"
        />
    </dependentAssembly>
</dependency>
```

Para um aplicativo do Windows XP ou Windows Vista, o recurso de manifesto não só especifica que o aplicativo usar a versão mais atual dos controles comuns do Windows (v 6.0, como mostrado acima), mas ele também dá suporte a [controle Syslink](/windows/desktop/Controls/syslink-overview).

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*.

Para exibir a versão e digite as informações contidas em um recurso de manifesto, você pode abrir o arquivo em um visualizador XML ou no editor de texto do Visual Studio. Se você abrir um recurso de manifesto da [exibição de recurso](../windows/resource-view-window.md), o recurso será aberto no formato binário. Para exibir o conteúdo de um recurso de manifesto em um formato mais visível, você deve abrir o recurso a partir **Gerenciador de soluções**.

## <a name="to-open-a-manifest-resource-in-the-text-editor"></a>Para abrir um recurso de manifesto no Editor de texto

1. Com o projeto aberto no **Gerenciador de soluções**, expanda o **arquivos de recurso** pasta.

1. Clique duas vezes o arquivo. manifest.

   O recurso de manifesto é aberto na **Editor de texto**.

## <a name="to-open-a-manifest-resource-in-another-editor"></a>Para abrir um recurso de manifesto em outro editor

1. Na **Gerenciador de soluções**, o arquivo. manifest com o botão direito e escolha **abrir com...**  no menu de atalho.

1. No **abrir com** caixa de diálogo, especifique o editor que você gostaria de usar e selecione **abrir**.

## <a name="limitations"></a>Limitações

Você pode ter apenas um recurso de manifesto por módulo.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Controles](../mfc/controls-mfc.md)<br/>
[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)