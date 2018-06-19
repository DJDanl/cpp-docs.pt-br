---
title: Excluir (#import) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- exclude
dev_langs:
- C++
helpviewer_keywords:
- exclude attribute
ms.assetid: 0883248a-d4bf-420e-9848-807b28fa976e
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 8cbc9d6f5ae0dcb1f82264ff07d3ea93a71cab60
ms.sourcegitcommit: 96cdc2da0d8c3783cc2ce03bd280a5430e1ac01d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/10/2018
ms.locfileid: "33954122"
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