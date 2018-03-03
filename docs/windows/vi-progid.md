---
title: vi_progid | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- vc-attr.vi_progid
dev_langs:
- C++
helpviewer_keywords:
- vi_progid attribute
ms.assetid: a52449be-b93e-4111-b883-44bb8da53261
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: b7581a4a10d9f101526aeb1a17ba7e26c4646b39
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="viprogid"></a>vi_progid
Especifica uma forma independente de versão de ProgID.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ vi_progid(  
   name  
) ];  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *name*  
 A versão de ProgID que representa o objeto.  
  
 ProgIDs apresentam uma versão legível do identificador de classe (CLSID) usado para identificar objetos ActiveX/COM.  
  
## <a name="remarks"></a>Comentários  
 O **vi_progid** atributo C++ permite que você especifique uma versão de ProgID para um objeto COM. Um ProgID tem o formato *name1.name2.version*. Um ProgID independentes de versão não tem um *versão*. É possível especificar tanto o **progid** e **vi_progid** atributos em uma coclass. Se você não especificar **vi_progid**, a versão de ProgID é o valor especificado pelo [progid](../windows/progid.md) atributo.  
  
 **vi_progid** implica o **coclass** atributo, ou seja, se você especificar **vi_progid**, é a mesma coisa que especificar o **coclass** e **vi_progid** atributos.  
  
 O **vi_progid** atributo faz com que uma classe seja automaticamente registrado no nome especificado. O arquivo. idl gerado não exibirá o valor de ProgID.  
  
 Em projetos ATL, se o [coclass](../windows/coclass.md) atributo também estiver presente, o ProgID especificado é usado pelo **GetVersionIndependentProgID** função (inseridas pelo **coclass** atributo).  
  
## <a name="example"></a>Exemplo  
 Consulte o [coclass](../windows/coclass.md) exemplo para uso do exemplo **vi_progid**.  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|**classe**,`struct`|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [TypeDef, Enum, Union e Struct atributos](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   
 [Chave progID](http://msdn.microsoft.com/library/windows/desktop/dd542719)   
