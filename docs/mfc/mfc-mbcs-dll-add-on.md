---
title: Suplemento MFC MBCS DLL
ms.date: 12/02/2019
helpviewer_keywords:
- MBCS
- MFC
ms.openlocfilehash: fe74e0639664b6a6a86a4c3269f174de441002f4
ms.sourcegitcommit: 8762a3f9b5476b4dee03f0ee8064ea606550986e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/04/2019
ms.locfileid: "74810362"
---
# <a name="mfc-mbcs-dll-add-on"></a>Suplemento MFC MBCS DLL

O suporte para MFC e suas bibliotecas de MBCS (conjunto de caracteres multibyte) requer uma etapa adicional durante a instalação do Visual Studio no Visual Studio 2013 e posterior.

**Visual Studio 2013**: por padrão, as bibliotecas do MFC instaladas no Visual Studio 2013 só dão suporte ao desenvolvimento em Unicode. Você precisa das DLLs MBCS para criar um projeto MFC no Visual Studio 2013 que tenha a propriedade **conjunto de caracteres** definida para usar o conjunto de **caracteres de vários bytes** ou **não definido**. Baixe a DLL na [biblioteca MFC multibyte para Visual Studio 2013](https://www.microsoft.com/download/details.aspx?id=40770).

**Visual Studio 2015**: as DLLs do MFC Unicode e MBCS estão incluídas nos componentes C++ de instalação do Visual, mas o suporte ao MFC não está instalado por padrão. Visual C++ e MFC são configurações opcionais de instalação na instalação do Visual Studio. Para verificar se o MFC está instalado, escolha **personalizado** na instalação e, em **linguagens de programação**, certifique-se de que  **C++ Visual** e  **C++ MFC para** estão selecionados. Se você já tiver instalado o Visual Studio, será solicitado a instalar o Visual C++ e/ou MFC quando tentar criar um projeto do MFC.

**Visual Studio 2017 e posterior**: as DLLs do MFC Unicode e MBCS são instaladas com o **desenvolvimento C++ de desktop com** carga de trabalho quando você seleciona **suporte a MFC e ATL** no painel **componentes opcionais** no programa instalador do Visual Studio. Se a instalação não incluir esses componentes, navegue até o **arquivo | Diálogo novos projetos** e clique no link **abrir instalador do Visual Studio** . Para obter mais informações, consulte [instalar o Visual Studio](/visualstudio/install/install-visual-studio).

## <a name="see-also"></a>Consulte também

[Versões de biblioteca do MFC](../mfc/mfc-library-versions.md)
