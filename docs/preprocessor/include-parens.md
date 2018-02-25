---
title: include() | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- include()
dev_langs:
- C++
helpviewer_keywords:
- include() attribute
ms.assetid: 86c9dcb2-d9e0-4fd5-97d7-0bb3e23d6ecc
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: da6a8bfc67f63caa8ee1f2699c8bb8675dbae775
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="include"></a>include()
**Específicas do C++**  
  
 Desabilita a exclusão automática.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
include("Name1"[,"Name2", ...])  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Name1`  
 Primeiro item a ser incluído de modo forçado.  
  
 `Name2`  
 O segundo item a ser incluído de modo forçado (se necessário).  
  
## <a name="remarks"></a>Comentários  
 As bibliotecas de tipos podem conter definições dos itens definidos em cabeçalhos do sistema ou em outras bibliotecas de tipos. `#import` tenta impedir vários erros de definição excluindo automaticamente esses itens. Se os itens foram excluídos, conforme indicado pelo [C4192 de aviso do compilador (nível 3)](../error-messages/compiler-warnings/compiler-warning-level-3-c4192.md), e não deve ter sido, esse atributo pode ser usado para desabilitar a exclusão automática. Esse atributo pode usar qualquer número de argumentos, cada um sendo o nome do item da biblioteca de tipos a ser incluído.  
  
 **TÉRMINO específicas do C++**  
  
## <a name="see-also"></a>Consulte também  
 [atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
 [#import diretiva](../preprocessor/hash-import-directive-cpp.md)