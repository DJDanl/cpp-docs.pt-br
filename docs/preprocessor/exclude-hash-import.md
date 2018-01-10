---
title: Excluir (#import) | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-tools
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords: exclude
dev_langs: C++
helpviewer_keywords: exclude attribute
ms.assetid: 0883248a-d4bf-420e-9848-807b28fa976e
caps.latest.revision: "4"
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: bd63eed4eea9404fd0a542c0be20f1770e461508
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="exclude-import"></a>exclude (#import)
**Específicas do C++**  
  
 Exclui itens dos arquivos de cabeçalho da biblioteca de tipos que estão sendo gerados.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
exclude("Name1"[, "Name2",...])  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Name1`  
 O primeiro item a ser excluído.  
  
 `Name2`  
 O segundo item a ser excluído (se necessário).  
  
## <a name="remarks"></a>Comentários  
 As bibliotecas de tipos podem conter definições dos itens definidos em cabeçalhos do sistema ou em outras bibliotecas de tipos. Esse atributo pode usar qualquer número de argumentos, cada um sendo um item da biblioteca de tipos de nível superior a ser excluído.  
  
 **TÉRMINO específicas do C++**  
  
## <a name="see-also"></a>Consulte também  
 [atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
 [#import diretiva](../preprocessor/hash-import-directive-cpp.md)