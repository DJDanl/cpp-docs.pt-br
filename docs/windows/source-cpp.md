---
title: fonte (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.source
dev_langs:
- C++
helpviewer_keywords:
- source attribute
ms.assetid: 1878d05d-7709-4e97-b114-c62f38f5140e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 11ee58fb2d500a7194fb08ee18b1af5cc7897830
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33889856"
---
# <a name="source-c"></a>source (C++)
Em uma classe, especifica as interfaces de origem do objeto COM para pontos de conexão. Uma propriedade ou método, indica que o membro retorna um objeto ou uma VARIANTE é uma origem de eventos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ source(  
   interfaces  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `interfaces`  
 Uma ou mais interfaces que você especificar ao aplicar a fonte de atributo a uma classe. Esse parâmetro não é usado quando a fonte é aplicada a uma propriedade ou método.  
  
## <a name="remarks"></a>Comentários  
 O **fonte** atributo C++ tem a mesma funcionalidade que o [fonte](http://msdn.microsoft.com/library/windows/desktop/aa367166) atributo MIDL.  
  
 Você pode usar o [padrão](../windows/default-cpp.md) atributo para especificar a interface de origem padrão para um objeto.  
  
## <a name="example"></a>Exemplo  
  
```  
// cpp_attr_ref_source.cpp  
// compile with: /LD  
#include "windows.h"  
#include "unknwn.h"  
[module(name="MyLib")];  
  
[object, uuid(11111111-1111-1111-1111-111111111111)]  
__interface b  
{  
   [id(0), propget, bindable, displaybind, defaultbind, requestedit]  
   HRESULT get_I([out, retval]long *i);  
};  
  
[object, uuid(11111111-1111-1111-1111-111111111131)]  
__interface c  
{  
   [id(0), propget, bindable, displaybind, defaultbind, requestedit]   
   HRESULT et_I([out, retval]long *i);  
};  
  
[coclass, default(c), uuid(11111111-1111-1111-1111-111111111132)]  
class N : public b  
{  
};  
  
[coclass, source(c), default(b, c), uuid(11111111-1111-1111-1111-111111111133)]  
class NN : public b  
{  
};  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|**classe**, `struct`, `interface`|  
|**Repetível**|Não|  
|**Atributos necessários.**|**coclass** (quando aplicado a class ou struct)|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   
 [Atributos de método](../windows/method-attributes.md)   
 [coclass](../windows/coclass.md)   
