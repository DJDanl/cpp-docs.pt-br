---
title: Exportar | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.export
dev_langs:
- C++
helpviewer_keywords:
- export attribute
ms.assetid: 70b3e848-fad6-4e09-8c72-be60ca72a4df
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 48c4a645456e3b3c0556dfed268ce911e5799fc3
ms.sourcegitcommit: d5d6bb9945c3550b8e8864b22b3a565de3691fde
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/06/2018
ms.locfileid: "39569411"
---
# <a name="export"></a>export
Faz com que uma estrutura de dados a serem colocados no arquivo. idl.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
[export]  
```  
  
## <a name="remarks"></a>Comentários  
 O **exportar** C++ atributo faz com que uma estrutura de dados a serem colocados no arquivo. idl e, em seguida, esteja disponível na biblioteca de tipos em um formato compatível com o binário que o torna disponível para uso com qualquer linguagem.  
  
 Não é possível aplicar a **exportar** a uma classe de atributo, mesmo se a classe tem somente membros públicos (o equivalente a um **struct**).  
  
 Se você exportar sem-nome **enum**s ou **struct**s, elas receberão nomes que começam com **Unnamed * * * x*, onde *x* é um sequencial número.  
  
 As definições de tipo válidas para a exportação são tipos base, estruturas, uniões, enumerações, ou identificadores de tipo.  Ver [typedef](http://msdn.microsoft.com/library/windows/desktop/aa367287) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra como usar o **exportar** atributo:  
  
```cpp  
// cpp_attr_ref_export.cpp  
// compile with: /LD  
[module(name="MyLibrary")];  
  
[export]  
struct MyStruct {  
   int i;  
};  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Atributo de contexto  
  
|||  
|-|-|  
|**Aplica-se a**|**União**, **typedef**, **enum**, **struct**, ou **interface**|  
|**Repetível**|Não|  
|**Atributos obrigatórios**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de compilador](../windows/compiler-attributes.md)   
 [Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)   