---
title: Suplemento MFC MBCS DLL
ms.date: 1/04/2018
helpviewer_keywords:
- MBCS
- MFC
ms.openlocfilehash: 2fdbb5dd862c7d1a8845813c6234fea9e902c1f9
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62238523"
---
# <a name="mfc-mbcs-dll-add-on"></a>Suplemento MFC MBCS DLL

Suporte para MFC e suas bibliotecas do caractere multibyte (MBCS) do conjunto exige uma etapa adicional durante a instalação do Visual Studio no Visual Studio 2013, 2015 e 2017.

**Visual Studio 2013**: Por padrão, as bibliotecas MFC instaladas no Visual Studio 2013 oferece suporte somente Unicode de desenvolvimento. Você precisa as DLLs MBCS a fim de criar um projeto MFC no Visual Studio 2013 que tem o **do conjunto de caracteres** propriedade definida como **usar conjunto de caracteres multibyte** ou **não definido**. Baixe o DLL em [Multibyte MFC Library para Visual Studio 2013](https://www.microsoft.com/download/details.aspx?id=40770).

**Visual Studio 2015**: DLLs de MFC MBCS e Unicode estão incluídos nos componentes de instalação do Visual C++, mas o suportam para MFC não está instalado por padrão. O Visual C++ e MFC são configurações de instalação opcional na instalação do Visual Studio. Para certificar-se de que o MFC é instalado, escolha **personalizado** na instalação e, em **linguagens de programação**, verifique se **Visual C++** e **Microsoft Foundation Classes para C++** estão selecionados. Se você já tiver instalado o Visual Studio, você precisará instalar o Visual C++ e/ou MFC quando você tenta criar um projeto MFC.

**Visual Studio 2017**: O Unicode e MBCS MFC DLLs são instalados com o **desenvolvimento para Desktop com C++** carga de trabalho quando você seleciona **dar suporte a MFC e ATL** do **componentes opcionais** painel. Se a instalação não incluir esses componentes, navegue até o **arquivo | Novos projetos** caixa de diálogo e clique em de **abrir instalador do Visual Studio** link.

## <a name="see-also"></a>Consulte também

[Versões de biblioteca do MFC](../mfc/mfc-library-versions.md)
