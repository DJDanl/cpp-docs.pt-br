---
title: "Atualizar uma coluna quando outra tabela contém uma referência para a linha | Microsoft Docs"
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
- rowsets, column updates
ms.assetid: abb5db69-055d-431f-b12d-ad2940a661ba
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: a5b4d4c041e1a6ad0f40107ef2bfb71293c05e5d
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="updating-a-column-when-another-table-contains-a-reference-to-the-row"></a>Atualizando uma coluna quando outra tabela contém uma referência para a linha
Alguns provedores podem detectar quais colunas na linha alterada, mas não de muitos provedores. Como resultado, atualizando uma coluna pode resultar em um erro quando há uma referência para a linha que você está tentando atualizar. Para resolver esse problema, crie um acessador separado que contém apenas as colunas que você deseja alterar. Passe o número desse acessador para `SetData`.  
  
## <a name="see-also"></a>Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)