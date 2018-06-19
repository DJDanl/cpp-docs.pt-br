---
title: caso (C++) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.case
dev_langs:
- C++
helpviewer_keywords:
- case attribute
ms.assetid: 6fb883c3-0526-4932-a901-b4564dcaeb7d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 30d665861688054a4f6b7491f449014afe646c71
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33860951"
---
# <a name="case-c"></a>case (C++)
Usado com o [switch_type](../windows/switch-type.md) atributo em uma **união**.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      [ case(  
   value  
) ]  
```  
  
#### <a name="parameters"></a>Parâmetros  
 *value*  
 Um valor de entrada possíveis para o qual você deseja fornecer processamento. O tipo de **valor** pode ser um dos seguintes tipos:  
  
-   `int`  
  
-   `char`  
  
-   `boolean`  
  
-   `enum`  
  
 ou um identificador desse tipo.  
  
## <a name="remarks"></a>Comentários  
 O **caso** atributo C++ tem a mesma funcionalidade que o **caso** atributo MIDL. Esse atributo é usado apenas com o [switch_type](../windows/switch-type.md) atributo.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra um uso de **caso** atributo:  
  
```  
// cpp_attr_ref_case.cpp  
// compile with: /LD  
#include <unknwn.h>  
[export]  
struct SizedValue2 {  
   [switch_type(char), switch_is(kind)] union {  
      [case(1), string]  
          wchar_t* wval;  
      [default, string]  
          char* val;  
   };  
    char kind;  
};  
[module(name="ATLFIRELib")];  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|Membro de um **classe** ou `struct`|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos IDL](../windows/idl-attributes.md)   
 [TypeDef, Enum, Union e Struct atributos](../windows/typedef-enum-union-and-struct-attributes.md)   
 [Atributos de classe](../windows/class-attributes.md)   
