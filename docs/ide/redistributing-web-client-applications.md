---
title: Redistribuindo aplicativos cliente Web | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-ide
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- Web applications [C++], redistributing
- deploying applications [C++], Web applications
- Internet applications [C++], redistributing
- application deployment [C++], Web applications
ms.assetid: fe05988b-dee8-4a46-b381-016b5103a6bf
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e764e42cb558d2e13e0609cb139e9538a72d09ed
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="redistributing-web-client-applications"></a>Redistribuindo aplicativos de cliente Web
Se seu aplicativo usa as classes MFC implementar o controle WebBrowser (por exemplo, `CHtmlView` ou `CHtmlEditView`), Microsoft Internet Explorer 4.0 ou posterior, pelo menos, deve ser no mínimo instalado no computador de destino.  
  
 Instalar a versão mais recente do Internet Explorer também garante que o computador de destino tem os arquivos de controle comum mais recentes.  
  
 Informações sobre como instalar os componentes mínimos do Internet Explorer estão disponíveis no seguinte artigo da Base de dados de Conhecimento:  
  
-   Q185375, como: Criar uma instalação de único EXE do Internet Explorer ([http://support.microsoft.com/support/kb/articles/q185/3/75.asp](http://support.microsoft.com/support/kb/articles/q185/3/75.asp))  
  
 Você pode encontrar artigos da Base de dados de Conhecimento na MSDN Library ou no [http://support.microsoft.com](http://support.microsoft.com).  
  
## <a name="see-also"></a>Consulte também  
 [Implantando aplicativos de área de trabalho](../ide/deploying-native-desktop-applications-visual-cpp.md)