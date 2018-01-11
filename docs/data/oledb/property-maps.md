---
title: Mapas de propriedade | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- OLE DB providers, properties
- maps, property
- property maps
ms.assetid: 44abde56-90ad-4612-854e-d2fa5426fa80
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 05bd576e6e55c94306a8dd648c57a4d606bed696
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="property-maps"></a>Mapas de propriedade
Além da sessão, o conjunto de linhas e o objeto de comando opcional, cada provedor oferece suporte a uma ou mais propriedades. Essas propriedades são definidas no contidos nos arquivos de cabeçalho criados pelo OLE DB Provider Assistente de mapas de propriedade. Cada arquivo de cabeçalho contém um mapa para as propriedades do grupo de propriedade do OLE DB definido para o objeto ou objetos definidos no arquivo. O arquivo de cabeçalho que contém o objeto de fonte de dados também contém o mapa de propriedade para o [propriedades de fonte de dados](https://msdn.microsoft.com/en-us/library/ms724188\(v=vs.140\).aspx). Session.h contém o mapa de propriedade para o [propriedades de sessão](https://msdn.microsoft.com/en-us/library/ms714221.aspx). Os objetos de conjunto de linhas e o comando residem em um arquivo de cabeçalho único, chamado *projectname*RS.h. Essas propriedades são membros de [propriedades de conjunto de linhas](https://msdn.microsoft.com/en-us/library/ms711252.aspx) grupo.  
  
## <a name="see-also"></a>Consulte também  
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)