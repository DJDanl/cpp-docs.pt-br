---
title: MFC e ATL
ms.date: 01/24/2018
ms.assetid: 31b1a3a8-4154-4c4a-af10-fafc23ecdc5c
ms.topic: overview
ms.openlocfilehash: 2fd109792bde0717c88222d5d53be3a26df95239
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84619928"
---
# <a name="mfc-and-atl"></a>MFC e ATL

O MFC (MFC) fornece um wrapper C++ orientado a objeto no Win32 para o desenvolvimento rápido de aplicativos de desktop nativos. A Active Template Library (ATL) é uma biblioteca de wrapper que simplifica o desenvolvimento COM e é usada extensivamente para a criação de controles ActiveX.

Você pode criar programas MFC ou ATL com o Visual Studio Community Edition ou superior. As Express Editions não dão suporte a MFC ou ATL.

No Visual Studio 2015, Visual C++ é um componente opcional, e os componentes MFC e ATL são subcomponentes opcionais em Visual C++. Se você não selecionar esses componentes ao instalar o Visual Studio pela primeira vez, será solicitado a instalá-los na primeira tentativa de criar ou abrir um projeto MFC ou ATL.

No Visual Studio 2017 e posterior, o MFC e o ATL são subcomponentes opcionais no **desenvolvimento de desktop com** carga de trabalho do C++ no programa de instalador do Visual Studio. Você pode instalar o suporte ATL sem MFC ou MFC combinado e suporte ATL (o MFC depende da ATL). Para obter mais informações sobre cargas de trabalho e componentes, consulte [instalar o Visual Studio](/visualstudio/install/install-visual-studio).

## <a name="related-articles"></a>Artigos relacionados

|Title|Descrição|
|-----------|-----------------|
|[Aplicativos da área de trabalho MFC](mfc-desktop-applications.md)|MFC fornecer um wrapper fino orientado a objeto sobre o Win32 para permitir o rápido desenvolvimento de aplicativos de GUI em C++.|
|[Componentes de área de trabalho COM da ATL](../atl/atl-com-desktop-components.md)|A ATL fornece modelos de classe e outras construções de uso para simplificar a criação de objetos COM em C++.|
|[Classes compartilhadas ATL/MFC](../atl-mfc-shared/atl-mfc-shared-classes.md)|Referências para [classe CStringT](../atl-mfc-shared/reference/cstringt-class.md) e outras classes que são compartilhadas por MFC e ATL.|
|[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)|O editor de recursos permite que você edite recursos de interface do usuário, como cadeias de caracteres, imagens e caixas de diálogo.|
|[C++ no Visual Studio](../overview/visual-cpp-in-visual-studio.md)|Tópico pai para todo o conteúdo C++ na biblioteca MSDN.|
