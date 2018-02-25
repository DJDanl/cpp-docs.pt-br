---
title: 'Ccommand:: Close | Microsoft Docs'
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- CCommand.Close
- CCommand::Close
dev_langs:
- C++
helpviewer_keywords:
- Close method
ms.assetid: 4da9c02c-7082-4e47-a0fa-78b546f0f7d2
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 3d25c726ef5961f7504eb72fef230a94588e7734
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="ccommandclose"></a>CCommand::Close
Libera o conjunto de linhas de acessador associado ao comando.  
  
## <a name="syntax"></a>Sintaxe

```cpp
void Close();  
```  
  
## <a name="remarks"></a>Comentários  
 Um comando usa um conjunto de linhas, o acessador de conjunto de resultados e (opcionalmente) um acessador de parâmetro (ao contrário das tabelas, que não oferecem suporte a parâmetros e não é necessário um acessador de parâmetro).  
  
 Quando você executar um comando, você deve chamar ambos `Close` e [ReleaseCommand](../../data/oledb/ccommand-releasecommand.md) após o comando.  
  
 Quando você quiser executar o mesmo comando repetidamente, você deve liberar cada acessador de conjunto de resultados chamando `Close` antes de chamar `Execute`. No final da série, você deve liberar o acessador de parâmetro ao chamar `ReleaseCommand`. Outro cenário comum é chamar um procedimento armazenado que tem parâmetros de saída. Em muitos provedores (como o provedor OLE DB para SQL Server) os valores de parâmetro de saída não estará acessíveis quando você fechar o acessador de conjunto de resultados. Chamar `Close` para fechar o conjunto de linhas retornado e o acessador de conjunto de resultados, mas não o acessador de parâmetro, permitindo que você recupere os valores de parâmetro de saída.  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir mostra como você pode chamar `Close` e `ReleaseCommand` quando você executa o mesmo comando repetidamente.  
  
 [!code-cpp[NVC_OLEDB_Consumer#2](../../data/oledb/codesnippet/cpp/ccommand-close_1.cpp)]  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** atldbcli.h  
  
## <a name="see-also"></a>Consulte também  
 [Classe CCommand](../../data/oledb/ccommand-class.md)   
 [CCommand::ReleaseCommand](../../data/oledb/ccommand-releasecommand.md)