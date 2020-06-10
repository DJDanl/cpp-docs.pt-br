---
title: Arrastando e soltando arquivos em uma janela com moldura
ms.date: 11/04/2016
helpviewer_keywords:
- drag and drop [MFC], files
- drag and drop [MFC], File Manager
- Windows Explorer [MFC]
- File Manager drag and drop support [MFC]
- files [MFC], drag and drop
- frame windows [MFC], dragging and dropping files in
- drag and drop [MFC], Windows Explorer
ms.assetid: 85560fe9-121b-4105-bd7b-216b966e19fa
ms.openlocfilehash: 42f21e2441f8ba3d2c6a13503c928880fe100f04
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623165"
---
# <a name="dragging-and-dropping-files-in-a-frame-window"></a>Arrastando e soltando arquivos em uma janela com moldura

A janela do quadro gerencia uma relação com o explorador de arquivos ou o Gerenciador de arquivos.

Ao adicionar algumas chamadas de inicialização em sua substituição da `CWinApp` função de membro `InitInstance` , conforme descrito em [CWinApp: a classe Application](cwinapp-the-application-class.md), você pode fazer com que a janela do quadro abra indiretamente os arquivos arrastados do explorador de arquivos ou do Gerenciador de arquivos e solto na janela do quadro. Consulte [arrastar e soltar do Gerenciador de arquivos](special-cwinapp-services.md).

## <a name="see-also"></a>Consulte também

[Usando janelas de quadros](using-frame-windows.md)
