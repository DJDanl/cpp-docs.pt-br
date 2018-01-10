---
title: Ferramentas de vinculador LNK1201 erro | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords: LNK1201
dev_langs: C++
helpviewer_keywords: LNK1201
ms.assetid: 64c3f496-a428-4b54-981e-faa82ef9c8a1
caps.latest.revision: "7"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 44e2ad811645889cd655bf297f6f8b9492574def
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="linker-tools-error-lnk1201"></a>Erro das Ferramentas de Vinculador LNK1201
Erro ao gravar no banco de dados do programa 'filename'; verificar se há espaço em disco insuficiente, caminho inválido ou privilégio insuficiente  
  
 LINK não foi possível gravar no banco de dados do programa (PDB) para o arquivo de saída.  
  
### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir  
  
1.  Arquivo está corrompido. Exclua o arquivo PDB e vincular novamente.  
  
2.  Espaço insuficiente em disco para gravar o arquivo.  
  
3.  Unidade não estiver disponível, possivelmente devido a um problema de rede.  
  
4.  O depurador está ativo no programa que você está tentando se vincular.  
  
5.  Não há espaço de pilha.  Consulte [C1060](../../error-messages/compiler-errors-1/fatal-error-c1060.md) para obter mais informações.