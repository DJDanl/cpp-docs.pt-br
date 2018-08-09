---
title: vi_progid | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.vi_progid
dev_langs:
- C++
helpviewer_keywords:
- vi_progid attribute
ms.assetid: a52449be-b93e-4111-b883-44bb8da53261
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 96843c9d977b15d7fe2c645c8f655cd59a42e401
ms.sourcegitcommit: 37a10996022d738135999cbe71858379386bab3d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/08/2018
ms.locfileid: "39642036"
---
# <a name="viprogid"></a>vi_progid
Especifica uma forma independente de versão do ProgID.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[ vi_progid(  
   name  
) ];  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *name*  
 O ProgID independente de versão que representa o objeto.  
  
 ProgIDs apresentar uma versão legível do identificador de classe (CLSID) usado para identificar objetos ActiveX/COM.  
  
## <a name="remarks"></a>Comentários  
 O **vi_progid** atributo C++ permite que você especifique um ProgID independente de versão para um objeto COM. Um ProgID tem o formato *name1.name2.version*. Um ProgID independente de versão não tem um *versão*. É possível especificar ambos os `progid` e o **vi_progid** atributos em um `coclass`. Se você não especificar **vi_progid**, a versão de ProgID é o valor especificado pela [progid](../windows/progid.md) atributo.  
  
 **vi_progid** implica a `coclass` do atributo, ou seja, se você especificar **vi_progid**, é a mesma coisa que especificando a `coclass` e **vi_progid** atributos.  
  
 O **vi_progid** atributo faz com que uma classe a ser registrado automaticamente no nome especificado. O arquivo. idl gerado não exibirá o valor de ProgID.  
  
 Em projetos ATL, se o [coclass](../windows/coclass.md) atributo também estiver presente, o ProgID especificado é usado pelo `GetVersionIndependentProgID` função (inserido pelo `coclass` atributo).  
  
## <a name="example"></a>Exemplo  
 Consulte a [coclass](../windows/coclass.md) exemplo para uso do exemplo **vi_progid**.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|**classe**, **struct**|  
|**Repetível**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [TypeDef, Enum, Union e Struct atributos](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   
 [Chave progID](http://msdn.microsoft.com/library/windows/desktop/dd542719)   