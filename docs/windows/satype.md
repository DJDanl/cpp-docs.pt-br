---
title: satype | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.satype
dev_langs: C++
helpviewer_keywords: satype attribute
ms.assetid: 1716590b-6bcb-4aba-b1bc-82f7335f02c3
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 9d4e083cfd0ee1a72992d3c400c4790f5cd50396
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="satype"></a>satype
Especifica o tipo de dados de **SAFEARRAY** estrutura.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ satype(  
   data_type  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *data_type*  
 O tipo de dados para o **SAFEARRAY** estrutura de dados que está sendo passada como um parâmetro para um método de interface.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|Parâmetro de interface, método de interface|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
## <a name="remarks"></a>Comentários  
 O **satype** atributo C++ Especifica o tipo de dados de **SAFEARRAY**.  
  
> [!NOTE]
>  Um nível de erro é descartado do **SAFEARRAY** ponteiro no arquivo. idl gerado a partir de como ele é declarado no arquivo. cpp.  
  
## <a name="example"></a>Exemplo  
  
```  
// cpp_attr_ref_satype.cpp  
// compile with: /LD  
#include "unknwn.h"  
[module(name="MyModule")];  
[dispinterface, uuid("00000000-0000-0000-0000-000000000001")]  
__interface A {  
   [id(1)] HRESULT MyMethod ([in, satype("BSTR")] SAFEARRAY **p);  
};  
```  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de compilador](../windows/compiler-attributes.md)   
 [Atributos de parâmetro](../windows/parameter-attributes.md)   
 [Atributos de método](../windows/method-attributes.md)   
 [id](../windows/id.md)   
