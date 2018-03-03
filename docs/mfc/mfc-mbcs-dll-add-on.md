---
title: Suplemento MFC MBCS DLL | Microsoft Docs
ms.custom: 
ms.date: 1/04/2018
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- MBCS
- MFC
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d6f134110ff95956cc37d6e038a680ff27cbc298
ms.sourcegitcommit: 56f6fce7d80e4f61d45752f4c8512e4ef0453e58
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/12/2018
---
# <a name="mfc-mbcs-dll-add-on"></a>Suplemento MFC MBCS DLL

Suporte para MFC e suas bibliotecas (MBCS) do conjunto de caracteres multibyte exige uma etapa adicional durante a instalação do Visual Studio no Visual Studio 2013, 2015 e 2017.

**Visual Studio 2013**: por padrão, as bibliotecas MFC instaladas no Visual Studio 2013 somente suporte ao desenvolvimento de Unicode. Você precisa as DLLs de MBCS para compilar um projeto no Visual Studio 2013 que tenha o **do conjunto de caracteres** propriedade definida como **do conjunto de caracteres multibyte Use** ou **não definido**. Baixe o DLL em [biblioteca MFC Multibyte para Visual Studio 2013](https://www.microsoft.com/en-us/download/details.aspx?id=40770).

**Visual Studio 2015**: tanto Unicode e MBCS MFC DLLs são incluídos nos componentes de instalação do Visual C++, mas o suporte para MFC não está instalado por padrão. Visual C++ e MFC são configurações de instalação opcional na instalação do Visual Studio. Para certificar-se de que o MFC é instalado, escolha **personalizado** na instalação e, em **linguagens de programação**, certifique-se de que **Visual C++** e **Microsoft Foundation Classes para C++** estão selecionados. Se você já tiver instalado o Visual Studio, você deverá instalar o Visual C++ e/ou MFC quando você tenta criar um projeto MFC.

**2017 do Visual Studio**: O Unicode e MBCS MFC DLLs são instalados com o **desenvolvimento de área de trabalho com C++** carga de trabalho quando você seleciona **suportam a MFC e ATL** do  **Componentes opcionais** painel. Se a instalação não incluir esses componentes, você pode iniciar o instalador do **novos projetos** caixa de diálogo usando o **abrir instalador do Visual Studio** link.

## <a name="see-also"></a>Consulte também

[Versões de biblioteca do MFC](../mfc/mfc-library-versions.md)

