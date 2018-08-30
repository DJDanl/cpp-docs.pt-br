---
title: cpp_quote | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.cpp_quote
dev_langs:
- C++
helpviewer_keywords:
- cpp_quote attribute
ms.assetid: f75327ff-42bd-498b-9177-7ffa25427e1f
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: da9e378ff75ec67660b0c29a5765be88a2c06496
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43205660"
---
# <a name="cppquote"></a>cpp_quote

Emite a cadeia de caracteres especificada, sem os caracteres de aspas no arquivo. idl gerado.

## <a name="syntax"></a>Sintaxe

```cpp
[ cpp_quote(
   "statement"
) ];
```

### <a name="parameters"></a>Parâmetros

*statement*  
Uma instrução C.

## <a name="remarks"></a>Comentários

O **cpp_quote** atributo C++ é útil se você deseja colocar uma diretiva de pré-processador em um arquivo. idl.

Você também pode usar **cpp_quote** e gerar um arquivo. h como parte da compilação MIDL. Por exemplo, se você tiver um arquivo de cabeçalho de C++ que usa atributos de IDL do C++, mas não é possível usar esse arquivo para alguma tarefa, em seguida, você pode compilá-lo para criar um arquivo. h de gerados por MIDL, que você deve ser capaz de usar.

O **cpp_quote** atributo tem a mesma funcionalidade que o [cpp_quote](/windows/desktop/Midl/cpp-quote) atributo MIDL.

## <a name="example"></a>Exemplo

Veja o exemplo de [dual](../windows/dual.md) para obter um exemplo usar como usar **cpp_quote**.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Em qualquer lugar|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações sobre os contextos de atributo, consulte [contextos de atributo](../windows/attribute-contexts.md).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](../windows/idl-attributes.md)  
[Atributos independentes](../windows/stand-alone-attributes.md)  