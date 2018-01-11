---
title: Suplemento MFC MBCS DLL | Microsoft Docs
ms.custom: 
ms.date: 08/20/2017
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- MBCS
- MFC
ms.assetid: bebec0ff-e019-42ca-b5df-8c218ac5b54a
caps.latest.revision: "17"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 176ed47b4d6a799cf53d2a1cea8cb232f1c2c4aa
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="mfc-mbcs-dll-add-on"></a>Suplemento MFC MBCS DLL
 Você precisa as DLLs multibyte para compilar um projeto no Visual Studio 2015 que tem o **do conjunto de caracteres** propriedade definida como **do conjunto de caracteres multibyte Use** ou **não definido**.  

**Visual Studio 2013**: baixar o DLL em [biblioteca MFC Multibyte para Visual Studio 2013](https://www.microsoft.com/en-us/download/details.aspx?id=40770).

**Visual Studio 2015**: A DLL está incluída nos componentes de instalação do Visual C++. Visual C++ e MFC são configurações de instalação opcional na instalação do Visual Studio. Para certificar-se de que o MFC é instalado, escolha **personalizado** na instalação e, em **linguagens de programação**, certifique-se de que **Visual C++** e **Microsoft Foundation Classes para C++** estão selecionados. Se você já tiver instalado o Visual Studio, você deverá instalar o Visual C++ e/ou MFC quando você tenta criar um projeto MFC.  
  
**2017 do Visual Studio**: A DLL é instalada com o **desenvolvimento de área de trabalho com C++** carga de trabalho quando você seleciona **suporte MFC e ATL** do **decomponentesopcionais** painel.

  
## <a name="see-also"></a>Consulte também  
 [Versões de biblioteca do MFC](../mfc/mfc-library-versions.md)

