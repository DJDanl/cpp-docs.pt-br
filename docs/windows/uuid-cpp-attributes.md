---
title: UUID (atributos C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.uuid
dev_langs:
- C++
helpviewer_keywords:
- uuid attribute
ms.assetid: 90562a94-5e28-451b-a4b0-cadda7f66efe
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: e56793855b278e0631c39ebfcdc51669a001a24b
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33891526"
---
# <a name="uuid-c-attributes"></a>uuid (atributos C++)
Especifica a ID exclusiva de uma classe ou interface.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ uuid(  
   "uuid"  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *uuid*  
 Um identificador exclusivo, de 128 bits.  
  
## <a name="remarks"></a>Comentários  
 Se a definição de uma interface ou classe não especifica o `uuid` atributo C++, em seguida, o compilador do Visual C++ fornecerá um. Quando você especifica um `uuid`, você deve incluir as aspas.  
  
 Se você não especificar `uuid`, em seguida, o compilador gerará o mesmo GUID para interfaces ou classes com o mesmo nome em projetos de atributo diferente em um computador.  
  
 Você pode usar Uuidgen.exe ou Guidgen.exe para gerar seus próprio identificações exclusivas. (Para executar uma dessas ferramentas, clique em **iniciar** e clique em **executar** no menu. Em seguida, digite o nome da ferramenta necessária.)  
  
 Quando usado em um projeto que não usa também ATL, especificando o `uuid` atributo é o mesmo que especificar o [uuid](../cpp/uuid-cpp.md) modificador declspec. Para recuperar o `uuid` de uma classe, você pode usar [uuidof](../cpp/uuidof-operator.md)  
  
## <a name="example"></a>Exemplo  
 Consulte o [associável](../windows/bindable.md) exemplo para uso do exemplo `uuid`.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|**classe**, `struct`, `interface`, **união**, `enum`|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [Atributos de interface](../windows/interface-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   
 [TypeDef, Enum, Union e Struct atributos](../windows/typedef-enum-union-and-struct-attributes.md)   
 [uuid](http://msdn.microsoft.com/library/windows/desktop/aa367302)   
