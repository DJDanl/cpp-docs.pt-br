---
title: Suplemento MFC MBCS DLL
ms.date: 12/02/2019
helpviewer_keywords:
- MBCS
- MFC
ms.openlocfilehash: 522bd5cf573aa3a0b24f14bc50f23b0d0e300d2e
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84625343"
---
# <a name="mfc-mbcs-dll-add-on"></a>Suplemento MFC MBCS DLL

O suporte para MFC e suas bibliotecas de MBCS (conjunto de caracteres multibyte) requer uma etapa adicional durante a instalação do Visual Studio no Visual Studio 2013 e posterior.

**Visual Studio 2013**: por padrão, as bibliotecas do MFC instaladas no Visual Studio 2013 só dão suporte ao desenvolvimento em Unicode. Você precisa das DLLs MBCS para criar um projeto MFC no Visual Studio 2013 que tenha a propriedade **conjunto de caracteres** definida para usar o conjunto de **caracteres de vários bytes** ou **não definido**. Baixe a DLL na [biblioteca MFC multibyte para Visual Studio 2013](https://www.microsoft.com/download/details.aspx?id=40770).

**Visual Studio 2015**: as DLLs do MFC Unicode e MBCS estão incluídas nos componentes de instalação do Visual C++, mas o suporte ao MFC não está instalado por padrão. Visual C++ e MFC são configurações opcionais de instalação na instalação do Visual Studio. Para verificar se o MFC está instalado, escolha **personalizado** na instalação e, em **linguagens de programação**, verifique se **Visual C++** e **MFC para C++** estão selecionados. Se você já tiver instalado o Visual Studio, será solicitado a instalar Visual C++ e/ou MFC quando tentar criar um projeto do MFC.

**Visual Studio 2017 e posterior**: as DLLs do MFC Unicode e MBCS são instaladas com o **desenvolvimento de desktop com carga de trabalho C++** quando você seleciona **suporte a MFC e ATL** no painel **componentes opcionais** no programa instalador do Visual Studio. Se a instalação não incluir esses componentes, navegue até o **arquivo | Diálogo novos projetos** e clique no link **abrir instalador do Visual Studio** . Para obter mais informações, consulte [instalar o Visual Studio](/visualstudio/install/install-visual-studio).

## <a name="see-also"></a>Consulte também

[Versões de biblioteca do MFC](mfc-library-versions.md)
