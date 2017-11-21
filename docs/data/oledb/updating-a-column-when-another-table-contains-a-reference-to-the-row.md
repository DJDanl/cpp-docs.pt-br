---
title: "Atualizar uma coluna quando outra tabela contém uma referência para a linha | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords: rowsets, column updates
ms.assetid: abb5db69-055d-431f-b12d-ad2940a661ba
caps.latest.revision: "7"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: cac57f2f4a1175fa1d9f4009e10fd3d0fae2a3b0
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="updating-a-column-when-another-table-contains-a-reference-to-the-row"></a>Atualizando uma coluna quando outra tabela contém uma referência para a linha
Alguns provedores podem detectar quais colunas na linha alterada, mas não de muitos provedores. Como resultado, atualizando uma coluna pode resultar em um erro quando há uma referência para a linha que você está tentando atualizar. Para resolver esse problema, crie um acessador separado que contém apenas as colunas que você deseja alterar. Passe o número desse acessador para `SetData`.  
  
## <a name="see-also"></a>Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)