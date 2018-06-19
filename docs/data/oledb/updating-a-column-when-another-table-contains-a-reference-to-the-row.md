---
title: Atualizar uma coluna quando outra tabela contém uma referência para a linha | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-data
ms.topic: reference
dev_langs:
- C++
helpviewer_keywords:
- rowsets, column updates
ms.assetid: abb5db69-055d-431f-b12d-ad2940a661ba
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- data-storage
ms.openlocfilehash: 17d260f522432a78729c9998c518398dfa41275a
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33102879"
---
# <a name="updating-a-column-when-another-table-contains-a-reference-to-the-row"></a>Atualizando uma coluna quando outra tabela contém uma referência para a linha
Alguns provedores podem detectar quais colunas na linha alterada, mas não de muitos provedores. Como resultado, atualizando uma coluna pode resultar em um erro quando há uma referência para a linha que você está tentando atualizar. Para resolver esse problema, crie um acessador separado que contém apenas as colunas que você deseja alterar. Passe o número desse acessador para `SetData`.  
  
## <a name="see-also"></a>Consulte também  
 [Usando acessadores](../../data/oledb/using-accessors.md)