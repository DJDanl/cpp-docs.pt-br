---
title: arquivo de ajuda | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.helpfile
dev_langs:
- C++
helpviewer_keywords:
- helpfile attribute
ms.assetid: d75161c1-1363-4019-ae09-e7e3b8a3971e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 424c6b642bba04a22ee4dedd59e38761260ac8eb
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43221923"
---
# <a name="helpfile"></a>helpfile

Define o nome do arquivo de ajuda para uma biblioteca de tipos.

## <a name="syntax"></a>Sintaxe

```cpp
[ helpfile(
   "filename"
) ]
```

### <a name="parameters"></a>Parâmetros

*filename*  
O nome do arquivo que contém os tópicos da Ajuda.

## <a name="remarks"></a>Comentários

O **helpfile** atributo C++ tem a mesma funcionalidade que o [helpfile](/windows/desktop/Midl/helpfile) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [módulo](../windows/module-cpp.md) para obter um exemplo de como usar **helpfile**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|**interface**, **typedef**, **classe**, método, **propriedade**|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos de interface](../windows/interface-attributes.md)  
[Atributos de classe](../windows/class-attributes.md)  
[Atributos de método](../windows/method-attributes.md)  
[Atributos Typedef, Enum, Union e Struct](../windows/typedef-enum-union-and-struct-attributes.md)  
[helpcontext](../windows/helpcontext.md)  
[helpstring](../windows/helpstring.md)  