---
title: Redistribuindo aplicativos de cliente Web
ms.date: 11/04/2016
helpviewer_keywords:
- Web applications [C++], redistributing
- deploying applications [C++], Web applications
- Internet applications [C++], redistributing
- application deployment [C++], Web applications
ms.assetid: fe05988b-dee8-4a46-b381-016b5103a6bf
ms.openlocfilehash: 37ff666493ada7dada19f5731e6581603d3cb57e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50512405"
---
# <a name="redistributing-web-client-applications"></a>Redistribuindo aplicativos de cliente Web

Se o aplicativo usa as classes MFC que implementam o controle WebBrowser (por exemplo, `CHtmlView` ou `CHtmlEditView`), o Microsoft Internet Explorer 4.0 ou posterior precisa, pelo menos, estar minimamente instalado no computador de destino.

A instalação da última versão do Internet Explorer também garante que o computador de destino tenha os últimos arquivos de controle comum. Para saber mais, confira [Instalar e implantar o Internet Explorer 11](/internet-explorer/ie11-deploy-guide/install-and-deploy-ie11).

## <a name="see-also"></a>Consulte também

[Implantando aplicativos da área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)