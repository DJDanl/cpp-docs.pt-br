---
title: Mapas de propriedade | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- OLE DB providers, properties
- maps, property
- property maps
ms.assetid: 44abde56-90ad-4612-854e-d2fa5426fa80
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 020479236bd86659ee4df783bf2056613cfac753
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="property-maps"></a>Mapas de propriedade
Além da sessão, o conjunto de linhas e o objeto de comando opcional, cada provedor oferece suporte a uma ou mais propriedades. Essas propriedades são definidas no contidos nos arquivos de cabeçalho criados pelo OLE DB Provider Assistente de mapas de propriedade. Cada arquivo de cabeçalho contém um mapa para as propriedades do grupo de propriedade do OLE DB definido para o objeto ou objetos definidos no arquivo. O arquivo de cabeçalho que contém o objeto de fonte de dados também contém o mapa de propriedade para o [propriedades de fonte de dados](https://msdn.microsoft.com/en-us/library/ms724188\(v=vs.140\).aspx). Session.h contém o mapa de propriedade para o [propriedades de sessão](https://msdn.microsoft.com/en-us/library/ms714221.aspx). Os objetos de conjunto de linhas e o comando residem em um arquivo de cabeçalho único, chamado *projectname*RS.h. Essas propriedades são membros de [propriedades de conjunto de linhas](https://msdn.microsoft.com/en-us/library/ms711252.aspx) grupo.  
  
## <a name="see-also"></a>Consulte também  
 [Arquitetura de modelo do provedor do OLE DB](../../data/oledb/ole-db-provider-template-architecture.md)