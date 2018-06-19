---
title: MFC e ATL | Microsoft Docs
ms.custom: ''
ms.date: 01/24/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 31b1a3a8-4154-4c4a-af10-fafc23ecdc5c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 081414d3835a8a6efcc831b6c303b774361b743b
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33347728"
---
# <a name="mfc-and-atl"></a>MFC e ATL
O Microsoft Foundation Classes (MFC) fornecem um wrapper de orientada a objeto de C++ em Win32 para o desenvolvimento rápido de aplicativos de área de trabalho nativos. A biblioteca de modelo ativa (ATL) é uma biblioteca de conteúdo adicional que simplifica o desenvolvimento COM e é muito usada para criação de controles ActiveX.  
  
Você pode criar programas MFC ou do ATL com o Visual Studio Community Edition ou superior. As edições Express não dão suporte a MFC ou ATL. 

No Visual Studio 2015, Visual C++ é um componente opcional e componentes MFC e ATL são subcomponentes opcionais em Visual C++. Se você não selecionar esses componentes, quando você instala o Visual Studio, você será solicitado a instalá-lo na primeira vez que você tentar criar ou abrir um projeto MFC ou do ATL.  

No Visual Studio de 2017 e posterior, MFC e ATL são opcionais subcomponentes sob o **desenvolvimento de área de trabalho com C++** cargas de trabalho no programa de instalação do Visual Studio. Você pode instalar o suporte ATL sem MFC ou combinados suporte MFC e ATL (MFC depende do ATL). Para obter mais informações sobre as cargas de trabalho e componentes, consulte [instalar o Visual Studio 2017](/visualstudio/install/install-visual-studio).
  
## <a name="related-articles"></a>Artigos relacionados  
  
|Título|Descrição|  
|-----------|-----------------|  
|[Aplicativos da área de trabalho MFC](../mfc/mfc-desktop-applications.md)|Microsoft Foundation Classes fornecem um wrapper fino orientada a objeto Win32 para habilitar o rápido desenvolvimento de aplicativos de GUI em C++.|  
|[Componentes de área de trabalho COM da ATL](../atl/atl-com-desktop-components.md)|ATL fornece modelos de classe e outro uso construções para simplificar a criação de objetos COM em C++.|  
|[Classes compartilhadas do ATL/MFC](../atl-mfc-shared/atl-mfc-shared-classes.md)|Referências de [CStringT classe](../atl-mfc-shared/reference/cstringt-class.md) e outras classes que são compartilhados por MFC e ATL.|  
|[Trabalhando com arquivos de recurso](../windows/working-with-resource-files.md)|O editor de recursos permite editar os recursos de interface do usuário, como cadeias de caracteres, imagens e caixas de diálogo.|  
|[Visual C++](../visual-cpp-in-visual-studio.md)|Tópico pai para todo o conteúdo de C++ na biblioteca MSDN.|