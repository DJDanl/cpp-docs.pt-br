---
title: no_injected_text | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.no_injected_text
dev_langs: C++
helpviewer_keywords: no_injected_text attribute
ms.assetid: 5256f808-e41e-4f4a-9ea5-e447919f5696
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 8c74d3134b5381be4ec330742726b26fea6155da
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="noinjectedtext"></a>no_injected_text
Impede que o compilador injeção de código como resultado do uso do atributo.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ no_injected_text(  
   boolean  
) ];  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `boolean`(opcional)  
 **True** não se desejar que nenhum código injetado, **false** para permitir que o código a ser inserida. **True** é o padrão.  
  
## <a name="remarks"></a>Comentários  
 O uso mais comum dos **no_injected_text** atributo C++ é o [/Fx](../build/reference/fx-merge-injected-code.md) opção de compilador, que insere o **no_injected_text** atributo para o arquivo. mrg.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|Em qualquer lugar|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de compilador](../windows/compiler-attributes.md)   
