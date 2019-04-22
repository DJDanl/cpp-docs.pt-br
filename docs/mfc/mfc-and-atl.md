---
title: MFC e ATL
ms.date: 01/24/2018
ms.assetid: 31b1a3a8-4154-4c4a-af10-fafc23ecdc5c
ms.openlocfilehash: c2cfb77f0e3885e0b315ddfe38bf942ec157375a
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58780243"
---
# <a name="mfc-and-atl"></a>MFC e ATL

Microsoft Foundation Classes (MFC) fornecem um wrapper de orientada a objeto C++ sobre Win32 para o desenvolvimento rápido de aplicativos nativos de área de trabalho. A biblioteca ATL (Active Template) é uma biblioteca de wrappers que simplifica o desenvolvimento COM e é amplamente usada para a criação de controles ActiveX.

Você pode criar programas MFC ou ATL com o Visual Studio Community Edition ou superior. As edições Express não dão suporte a MFC ou ATL.

No Visual Studio 2015, Visual C++ é um componente opcional e componentes MFC e ATL são componentes opcionais de subpropriedades em Visual C++. Se você não selecionar esses componentes ao instalar o Visual Studio, você será solicitado a instalá-los na primeira vez que você tentar criar ou abrir um projeto MFC ou ATL.

No Visual Studio 2017 e posterior, MFC e ATL são opcionais subcomponentes sob o **desenvolvimento para Desktop com C++** carga de trabalho no programa instalador do Visual Studio. Você pode instalar suporte ATL sem MFC ou combinado de suporte do MFC e ATL (MFC depende do ATL). Para obter mais informações sobre as cargas de trabalho e componentes, consulte [instalar o Visual Studio 2017](/visualstudio/install/install-visual-studio).

## <a name="related-articles"></a>Artigos relacionados

|Título|Descrição|
|-----------|-----------------|
|[Aplicativos da área de trabalho MFC](../mfc/mfc-desktop-applications.md)|Microsoft Foundation Classes fornece um wrapper de orientada a objeto fino no Win32 para ativar o rápido desenvolvimento de aplicativos de GUI em C++.|
|[Componentes de área de trabalho COM da ATL](../atl/atl-com-desktop-components.md)|ATL fornece modelos de classe e outros constructos de uso para simplificar a criação de objetos COM em C++.|
|[Classes compartilhadas ATL/MFC](../atl-mfc-shared/atl-mfc-shared-classes.md)|Faz referência para [classe CStringT](../atl-mfc-shared/reference/cstringt-class.md) e outras classes que são compartilhadas por MFC e ATL.|
|[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)|O editor de recursos permite editar os recursos de interface do usuário, como cadeias de caracteres, imagens e caixas de diálogo.|
|[Visual C++](../overview/visual-cpp-in-visual-studio.md)|Tópico pai para todo o conteúdo de C++ na biblioteca MSDN.|