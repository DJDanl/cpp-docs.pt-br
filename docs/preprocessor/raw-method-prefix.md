---
title: raw_method_prefix | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: reference
f1_keywords:
- raw_method_prefix
dev_langs:
- C++
helpviewer_keywords:
- raw_method_prefix attribute
ms.assetid: 71490313-af78-4bb2-b28a-eee67950d30b
caps.latest.revision: 
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: dc80d1468d3ac33bf7506aab98945b9c2e610e51
ms.sourcegitcommit: d51ed21ab2b434535f5c1d553b22e432073e1478
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/23/2018
---
# <a name="rawmethodprefix"></a>raw_method_prefix
**Específicas do C++**  
  
 Especifica um prefixo diferente para evitar colisões de nome.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
raw_method_prefix("Prefix")  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `Prefix`  
 O prefixo a ser usado.  
  
## <a name="remarks"></a>Comentários  
 Métodos e propriedades de nível baixo são expostos pelas funções de membro nomeadas com o prefixo padrão **raw_** para evitar colisões de nome com as funções de membro de tratamento de erros alto nível.  
  
> [!NOTE]
>  Os efeitos da `raw_method_prefix` atributo não será alterado pela presença do [raw_interfaces_only](#_predir_raw_interfaces_only) atributo. `raw_method_prefix` sempre tem precedência sobre `raw_interfaces_only` na especificação de um prefixo. Se os dois atributos forem usados na mesma instrução `#import`, o prefixo especificado pelo atributo `raw_method_prefix` será usado.  
  
 **TÉRMINO específicas do C++**  
  
## <a name="see-also"></a>Consulte também  
 [atributos de #import](../preprocessor/hash-import-attributes-cpp.md)   
 [#import diretiva](../preprocessor/hash-import-directive-cpp.md)