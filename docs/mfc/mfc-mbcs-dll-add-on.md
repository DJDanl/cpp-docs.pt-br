---
title: Suplemento MFC MBCS DLL | Microsoft Docs
ms.custom: ''
ms.date: 1/04/2018
ms.technology:
- cpp-mfc
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- MBCS
- MFC
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: efcfac98c5ff36f84ec0b7c4d2fbd6ff40cbb0d4
ms.sourcegitcommit: 59afc95d0e494af658cf464503f7f89bd1a8d2ce
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/08/2018
ms.locfileid: "35239444"
---
# <a name="mfc-mbcs-dll-add-on"></a>Suplemento MFC MBCS DLL

Suporte para MFC e suas bibliotecas (MBCS) do conjunto de caracteres multibyte exige uma etapa adicional durante a instalação do Visual Studio no Visual Studio 2013, 2015 e 2017.

**Visual Studio 2013**: por padrão, as bibliotecas MFC instaladas no Visual Studio 2013 somente suporte ao desenvolvimento de Unicode. Você precisa as DLLs de MBCS para compilar um projeto no Visual Studio 2013 que tenha o **do conjunto de caracteres** propriedade definida como **do conjunto de caracteres multibyte Use** ou **não definido**. Baixe o DLL em [biblioteca MFC Multibyte para Visual Studio 2013](https://www.microsoft.com/en-us/download/details.aspx?id=40770).

**Visual Studio 2015**: tanto Unicode e MBCS MFC DLLs são incluídos nos componentes de instalação do Visual C++, mas o suporte para MFC não está instalado por padrão. Visual C++ e MFC são configurações de instalação opcional na instalação do Visual Studio. Para certificar-se de que o MFC é instalado, escolha **personalizado** na instalação e, em **linguagens de programação**, certifique-se de que **Visual C++** e **Microsoft Foundation Classes para C++** estão selecionados. Se você já tiver instalado o Visual Studio, você deverá instalar o Visual C++ e/ou MFC quando você tenta criar um projeto MFC.

**2017 do Visual Studio**: O Unicode e MBCS MFC DLLs são instalados com o **desenvolvimento de área de trabalho com C++** carga de trabalho quando você seleciona **suportam a MFC e ATL** do **opcional Componentes** painel. Se a instalação não incluir esses componentes, navegue até o **arquivo | Novos projetos** caixa de diálogo e clique no **abrir instalador do Visual Studio** link.

## <a name="see-also"></a>Consulte também

[Versões de biblioteca do MFC](../mfc/mfc-library-versions.md)

