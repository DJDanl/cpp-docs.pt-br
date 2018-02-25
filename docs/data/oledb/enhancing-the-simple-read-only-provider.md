---
title: Melhorando o provedor somente leitura simples | Microsoft Docs
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
- read-only poviders [C++]
- IRowsetLocate class
- IRowsetLocate class, adding to OLE DB template providers
- simple read-only poviders [C++]
ms.assetid: cba0e09f-44c1-41c1-9456-332aa13dc158
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 6eb3c583d217e421909236c09ccac6c406cf6a7c
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="enhancing-the-simple-read-only-provider"></a>Melhorando o provedor somente leitura simples
Esta seção mostra como aprimorar a [provedor somente leitura simples](../../data/oledb/implementing-the-simple-read-only-provider.md) criado na seção anterior. `IRowsetLocateImpl` cria uma implementação para o `IRowsetLocate` de interface e adiciona suporte a indicadores para você.  
  
 Quando você tiver um provedor de trabalho, você talvez queira aprimorá-lo para fazer a atualização do provedor, manipular transações ou melhorar o desempenho do algoritmo de busca de linhas. A maioria dos aprimoramentos de provedor envolvem a inclusão de uma interface para um objeto COM existente.  
  
 O exemplo nos tópicos a seguir aumenta o mecanismo de busca de linhas, adicionando o `IRowsetLocate` interface `CAgentRowset`. Os tópicos mostram como para:  
  
-   [Verifique RMyProviderRowset herdam IRowsetLocate](../../data/oledb/modifying-the-inheritance-of-rmyproviderrowset.md).  
  
-   [Determinar dinamicamente as colunas retornadas ao consumidor](../../data/oledb/dynamically-determining-columns-returned-to-the-consumer.md).  
  
## <a name="see-also"></a>Consulte também  
 [Criando um provedor somente leitura simples](../../data/oledb/creating-a-simple-read-only-provider.md)