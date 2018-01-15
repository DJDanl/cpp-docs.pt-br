---
title: Exportar | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords: vc-attr.export
dev_langs: C++
helpviewer_keywords: export attribute
ms.assetid: 70b3e848-fad6-4e09-8c72-be60ca72a4df
caps.latest.revision: "11"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 24619e3a0e707b40590b0ffb37b415629a18b1cd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="export"></a>export
Faz com que uma estrutura de dados a serem colocados no arquivo. idl.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
[export]  
  
```  
  
## <a name="remarks"></a>Comentários  
 O **exportar** C++ atributo faz com que uma estrutura de dados a serem colocados no arquivo. idl e esteja disponível na biblioteca de tipos em um formato compatível com o binário que o torna disponível para uso com qualquer linguagem.  
  
 Não é possível aplicar o **exportar** atributo a uma classe, mesmo se a classe tem somente membros públicos (o equivalente de um `struct`).  
  
 Se você exportar sem nome `enum`s ou `struct`s, eles receberão nomes que começam com **__unnamed***x*, onde *x* é um número sequencial.  
  
 As definições de tipo válidas para exportação são tipos de base, estruturas, uniões, enumerações, ou digite identificadores.  Consulte [typedef](http://msdn.microsoft.com/library/windows/desktop/aa367287) para obter mais informações.  
  
## <a name="example"></a>Exemplo  
 O código a seguir mostra como usar o **exportar** atributo:  
  
```  
// cpp_attr_ref_export.cpp  
// compile with: /LD  
[module(name="MyLibrary")];  
  
[export]  
struct MyStruct {  
   int i;  
};  
```  
  
## <a name="requirements"></a>Requisitos  
  
### <a name="attribute-context"></a>Contexto de atributo  
  
|||  
|-|-|  
|**Aplica-se a**|**União**, `typedef`, `enum`, `struct`, ou`interface`|  
|**Repetível**|Não|  
|**Atributos necessários.**|Nenhum|  
|**Atributos inválidos**|Nenhum|  
  
 Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).  
  
## <a name="see-also"></a>Consulte também  
 [Atributos de compilador](../windows/compiler-attributes.md)   
 [Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)   
