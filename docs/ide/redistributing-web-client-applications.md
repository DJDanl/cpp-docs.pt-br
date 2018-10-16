---
title: Redistribuindo aplicativos cliente Web | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-ide
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- Web applications [C++], redistributing
- deploying applications [C++], Web applications
- Internet applications [C++], redistributing
- application deployment [C++], Web applications
ms.assetid: fe05988b-dee8-4a46-b381-016b5103a6bf
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d036f7d46e0db84b8572b26c747947c929972517
ms.sourcegitcommit: d3c41b16bf05af2149090e996d8e71cd6cd55c7a
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/09/2018
ms.locfileid: "48889926"
---
# <a name="redistributing-web-client-applications"></a>Redistribuindo aplicativos de cliente Web

Se o aplicativo usa as classes MFC que implementam o controle WebBrowser (por exemplo, `CHtmlView` ou `CHtmlEditView`), o Microsoft Internet Explorer 4.0 ou posterior precisa, pelo menos, estar minimamente instalado no computador de destino.

A instalação da última versão do Internet Explorer também garante que o computador de destino tenha os últimos arquivos de controle comum. Para saber mais, confira [Instalar e implantar o Internet Explorer 11](/internet-explorer/ie11-deploy-guide/install-and-deploy-ie11).

## <a name="see-also"></a>Consulte também

[Implantando aplicativos da área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)