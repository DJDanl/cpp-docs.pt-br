---
title: ProgID | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.progid
dev_langs: C++
helpviewer_keywords: progid attribute
ms.assetid: afcf559c-e432-481f-aa9a-bd3bb72c02a8
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 862629af7e279cf1f03a5e9adc9424b330ee1d90
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="progid"></a>progid
Especifica o ProgID de um objeto COM.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ progid(  
   name  
) ];  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *name*  
 O ProgID que representa o objeto.  
  
 ProgIDs apresentam uma versão legível do identificador de classe (CLSID) usado para identificar objetos ActiveX/COM.  
  
## <a name="remarks"></a>Comentários  
 O **progid** atributo C++ permite que você especifique o ProgID de um objeto COM. Um ProgID tem o formato *name1.name2.version*. Se você não especificar um *versão* para um ProgID, a versão padrão é 1. Se você não especificar *name1.name2*, o nome padrão é *classname.classname*. Se você não especificar **progid** e você especificar **vi_progid**, *name1.name2* são tiradas **vi_progid** e (Avançar sequencial versão do número) será anexada.  
  
 Se um bloco de atributo que usa **progid** também não usa `uuid`, o compilador verificará o registro para ver se um `uuid` existe especificado **progid**. Se **progid** não for especificado, a versão (e o nome de coclass, se criar uma coclass) serão usados para gerar um **progid**.  
  
 **ProgID** implica o **coclass** atributo, ou seja, se você especificar **progid**, é a mesma coisa que especificar o **coclass** e  **ProgID** atributos.  
  
 O **progid** atributo faz com que uma classe seja automaticamente registrado no nome especificado. O arquivo. idl gerado não exibirá o **progid** valor.  
  
 Quando esse atributo é usado em um projeto que usa ATL, altera o comportamento do atributo. Além do comportamento acima, as informações especificadas com esse atributo são usadas no **GetProgID** função injetada pelo **coclass** atributo. Para obter mais informações, consulte o [coclass](../windows/coclass.md) atributo.  
  
## <a name="example"></a>Exemplo  
 Consulte o exemplo para [coclass](../windows/coclass.md) para uso do exemplo **progid**.  
  
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
 [Atributos de classe](../windows/class-attributes.md)   
 [TypeDef, Enum, Union e Struct atributos](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Chave progID](http://msdn.microsoft.com/library/windows/desktop/dd542719)   
