---
title: Arquivos gerados pelo assistente provedor | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: OLE DB providers, wizard-generated files
ms.assetid: 6e1ac94b-eb90-4abf-82b3-06944b947ebc
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: 24da0ab4b3ab27cdb9a70c0f9cc05e3ca86e117d
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="provider-wizard-generated-files"></a>Arquivos gerados pelo Assistente do Provedor
O OLE DB Provider assistente ATL gera os seguintes arquivos. Os tópicos a seguir usam o nome curto "MyProvider", mas os nomes de arquivo exatos dependem da escolha feita ao criar o provedor.  
  
|Nome do arquivo|Descrição|  
|---------------|-----------------|  
|MyProviderRS.cpp|Contém o auxiliar do comando `Execute` método e o mapa de coluna do provedor.|  
|Myproviderds. H|Implementa o objeto de fonte de dados. Esse arquivo de cabeçalho contém o mapa de propriedade para propriedades de fonte de dados.|  
|Myproviderrs. H|Implementa os objetos de comando e o conjunto de linhas. Esse arquivo de cabeçalho contém o mapa de propriedade para propriedades de conjunto de linhas e comando.|  
|Myprovidersess. H|Implementa o objeto de sessão. Esse arquivo de cabeçalho contém o mapa de propriedade para propriedades de sessão.|  
|MyProvider.rgs|Contém os objetos registrados gerados pelo Assistente do provedor de banco de dados OLE.|  
  
## <a name="see-also"></a>Consulte também  
 [Criando um provedor do OLE DB](../../data/oledb/creating-an-ole-db-provider.md)