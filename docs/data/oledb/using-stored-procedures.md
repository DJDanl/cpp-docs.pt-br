---
title: Usando procedimentos armazenados | Microsoft Docs
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
- OLE DB, stored procedures
- stored procedures, Visual C++
- stored procedures, about stored procedures
- OLE DB provider templates, stored procedures
- stored procedures, OLE DB
ms.assetid: 90507e4c-eca2-46c9-ad8c-07e10dc1d41b
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 2a79ca28b3ae509ef5e493a23222ac76ad2352c9
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="using-stored-procedures"></a>Usando procedimentos armazenados
Um procedimento armazenado é um objeto executável armazenado em um banco de dados. Chamar um procedimento armazenado é semelhante a chamar um comando SQL. Usando procedimentos armazenados na fonte de dados (em vez de executar ou preparar uma instrução no aplicativo cliente) pode fornecer várias vantagens, incluindo o melhor desempenho, sobrecarga de rede reduzida e maior consistência e precisão.  
  
 Um procedimento armazenado pode ter qualquer número de (incluindo zero) entrada ou parâmetros de saída e pode passar um valor de retorno. Você pode qualquer um dos valores de parâmetro de codificar como valores de dados específicos ou usam um marcador de parâmetro (um ponto de interrogação '?').  
  
> [!NOTE]
>  CLR SQL Server, procedimentos armazenados criados usando o Visual C++ devem ser compilados com o **/CLR: safe** opção de compilador.  
  
 O provedor OLE DB para SQL Server (SQLOLEDB) suporta os seguintes mecanismos que armazenados o uso de procedimentos para retornar dados:  
  
-   Cada instrução SELECT no procedimento gera um conjunto de resultados.  
  
-   O procedimento pode retornar dados por meio de parâmetros de saída.  
  
-   O procedimento pode ter um número inteiro de código de retorno.  
  
> [!NOTE]
>  Você não pode usar procedimentos armazenados com o provedor OLE DB para Jet porque esse provedor não dá suporte a procedimentos armazenados; somente constantes são permitidas em cadeias de caracteres de consulta.  
  
## <a name="see-also"></a>Consulte também  
 [Trabalhando com modelos de consumidor do OLE DB](../../data/oledb/working-with-ole-db-consumer-templates.md)