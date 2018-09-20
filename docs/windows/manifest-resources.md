---
title: Recursos (C++) de manifesto | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- manifest resources [C++]
- resources [C++], manifest
ms.assetid: 8615334c-22a0-44c0-93e0-5924528c9917
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 2da93d1baaf95799c7ef68d6cc854d554fbe6c47
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46429559"
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

Para exibir a versão e digite as informações contidas em um recurso de manifesto, você pode abrir o arquivo em um visualizador XML ou no editor de texto do Visual Studio. Para obter mais informações, consulte [abrindo um recurso de manifesto no Editor de texto do Visual Studio](../windows/how-to-open-a-manifest-resource.md).

Para obter informações sobre como adicionar recursos a projetos gerenciados, consulte [recursos em aplicativos de área de trabalho](/dotnet/framework/resources/index) na *guia do desenvolvedor do .NET Framework*.

## <a name="limitations"></a>Limitações

Você pode ter apenas um recurso de manifesto por módulo.

## <a name="requirements"></a>Requisitos

Win32

## <a name="see-also"></a>Consulte também

[Controles](../mfc/controls-mfc.md)<br/>
[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)