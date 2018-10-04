---
title: Exportar (C++ COM o atributo) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
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
ms.openlocfilehash: a636b7d4c943896bcd1e5e7b3580c2d3f7410fc8
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48790089"
---
# <a name="export"></a>export

Faz com que uma estrutura de dados a serem colocados no arquivo. idl.

## <a name="syntax"></a>Sintaxe

```cpp
[export]
```

## <a name="remarks"></a>Comentários

O **exportar** C++ atributo faz com que uma estrutura de dados a serem colocados no arquivo. idl e, em seguida, esteja disponível na biblioteca de tipos em um formato compatível com o binário que o torna disponível para uso com qualquer linguagem.

Não é possível aplicar a **exportar** a uma classe de atributo, mesmo se a classe tem somente membros públicos (o equivalente a um **struct**).

Se você exportar um sem-nome **enum** ou **struct**, ele recebe um nome que começa com **Unnamed**<em>x</em>, onde *x* é um número sequencial.

As definições de tipo válidas para a exportação são tipos base, estruturas, uniões, enumerações, ou identificadores de tipo.  Ver [typedef](/windows/desktop/Midl/typedef) para obter mais informações.

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

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de compilador](compiler-attributes.md)<br/>
[Atributos Typedef, Enum, Union e Struct](typedef-enum-union-and-struct-attributes.md)  