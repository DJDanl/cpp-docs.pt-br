---
title: include() | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: include()
dev_langs: C++
helpviewer_keywords: include() attribute
ms.assetid: 86c9dcb2-d9e0-4fd5-97d7-0bb3e23d6ecc
caps.latest.revision: "5"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 794152aa30c57f22bc611ef758af23b2f205b7b5
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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