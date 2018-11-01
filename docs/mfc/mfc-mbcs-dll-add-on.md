---
title: Suplemento MFC MBCS DLL
ms.date: 1/04/2018
helpviewer_keywords:
- MBCS
- MFC
ms.openlocfilehash: a78425ac92aa9ddfe7f0b1b61dde915b3e088383
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50558906"
---
# <a name="mfc-mbcs-dll-add-on"></a>Suplemento MFC MBCS DLL

Suporte para MFC e suas bibliotecas do caractere multibyte (MBCS) do conjunto exige uma etapa adicional durante a instalação do Visual Studio no Visual Studio 2013, 2015 e 2017.

**Visual Studio 2013**: por padrão, as bibliotecas MFC instaladas no Visual Studio 2013 oferece suporte somente Unicode de desenvolvimento. Você precisa as DLLs MBCS a fim de criar um projeto MFC no Visual Studio 2013 que tem o **do conjunto de caracteres** propriedade definida como **usar conjunto de caracteres multibyte** ou **não definido**. Baixe o DLL em [Multibyte MFC Library para Visual Studio 2013](https://www.microsoft.com/download/details.aspx?id=40770).

**Visual Studio 2015**: DLLs do MFC MBCS e Unicode tanto estão incluídos nos componentes de instalação do Visual C++, mas o suporte para MFC não está instalado por padrão. O Visual C++ e MFC são configurações de instalação opcional na instalação do Visual Studio. Para certificar-se de que o MFC é instalado, escolha **personalizado** na instalação e, em **linguagens de programação**, verifique se **Visual C++** e **Microsoft Foundation Classes para C++** estão selecionados. Se você já tiver instalado o Visual Studio, você precisará instalar o Visual C++ e/ou MFC quando você tenta criar um projeto MFC.

**Visual Studio 2017**: O Unicode e MBCS MFC DLLs são instalados com o **desenvolvimento para Desktop com C++** carga de trabalho quando você seleciona **dar suporte a MFC e ATL** do **opcional Componentes** painel. Se a instalação não incluir esses componentes, navegue até o **arquivo | Novos projetos** caixa de diálogo e clique em de **abrir instalador do Visual Studio** link.

## <a name="see-also"></a>Consulte também

[Versões de biblioteca do MFC](../mfc/mfc-library-versions.md)

