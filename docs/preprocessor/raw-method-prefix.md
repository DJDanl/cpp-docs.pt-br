---
title: raw_method_prefix | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- raw_method_prefix
dev_langs:
- C++
helpviewer_keywords:
- raw_method_prefix attribute
ms.assetid: 71490313-af78-4bb2-b28a-eee67950d30b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: fc2a37f587d3b5ac2b695171f5620db6521693d2
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46439673"
---
# <a name="rawmethodprefix"></a>raw_method_prefix
**Específico do C++**  
  
Especifica um prefixo diferente para evitar colisões de nome.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
raw_method_prefix("Prefix")  
```  
  
### <a name="parameters"></a>Parâmetros  
*Prefixo*  
O prefixo a ser usado.  
  
## <a name="remarks"></a>Comentários  
 
Métodos e propriedades de baixo nível são expostos por funções de membro nomeadas com o prefixo padrão **RAW _** para evitar colisões de nome com as funções de membro de tratamento de erros alto nível.  
  
> [!NOTE]
> Os efeitos do **raw_method_prefix** atributo não será alterado pela presença da [raw_interfaces_only](#_predir_raw_interfaces_only) atributo. O **raw_method_prefix** sempre tem precedência sobre `raw_interfaces_only` na especificação de um prefixo. Se ambos os atributos são usados na mesma `#import` instrução, em seguida, o prefixo especificado o **raw_method_prefix** atributo é usado.  
  
**FIM de específico de C++**  
  
## <a name="see-also"></a>Consulte também  
 
[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)