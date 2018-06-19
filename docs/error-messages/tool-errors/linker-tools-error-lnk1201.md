---
title: Ferramentas de vinculador LNK1201 erro | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK1201
dev_langs:
- C++
helpviewer_keywords:
- LNK1201
ms.assetid: 64c3f496-a428-4b54-981e-faa82ef9c8a1
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 5ad83fecfe4df211cb7c5f301626454b5d2c9e47
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
ms.locfileid: "33298763"
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