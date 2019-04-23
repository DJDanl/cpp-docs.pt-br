---
title: idl_quote (C++ COM atributo)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.idl_quote
helpviewer_keywords:
- idl_quote attribute
ms.assetid: a370e1b7-948b-4e67-9a25-58facf24e4c9
ms.openlocfilehash: fd7455298c9a1b69926d85766b6cd7f96bd374cc
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59037111"
---
# <a name="idlquote"></a>idl_quote

Permite que você use construções IDL que não têm suporte na versão atual do Visual C++ e fazer com que eles passam para o arquivo. idl gerado.

## <a name="syntax"></a>Sintaxe

```cpp
[ idl_quote(text) ]
```

### <a name="parameters"></a>Parâmetros

*text*<br/>
O nome do atributo que você pretende que o compilador do Visual C++ para passar para o arquivo. idl gerado sem retornar um erro do compilador.

## <a name="remarks"></a>Comentários

Se o **idl_quote** C++ atributo é usado como um atributo autônomo (com um ponto e vírgula após o colchete de fechamento), em seguida, *texto* é colocado no arquivo. idl mesclado como está. Se **idl_quote** é usado em um símbolo *texto* é colocado dentro do bloco de atributo para esse símbolo.

## <a name="example"></a>Exemplo

O código a seguir mostra como você pode especificar um atributo sem suporte (usando **em**, que tem suporte) e como definir e usar uma construção de IDL indefinido:

```cpp
// cpp_attr_ref_idl_quote.cpp
// compile with: /LD
#include <unknwn.h>
[module(name="MyLibrary")];

[export]
struct MYFLOT {
   int i;
};

[export]
struct MYDUB {
   int i;
};

[idl_quote("typedef union _S1_TYPE switch (long l1) U1_TYPE { case 1024: \
struct MYFLOT f1; case 2048: struct MYDUB d2; } S1_TYPE;") ];

typedef struct _S1_TYPE {
   long l1;

union {
   MYFLOT f1; MYDUB d2; } U1_TYPE;
} S1_TYPE;

[uuid("2F5F63F1-16DA-11d2-9E7B-00C04FB926DA"), object]
__interface IStatic{
   HRESULT Func1([idl_quote("in")] int i);
   HRESULT func( S1_TYPE* myStruct );
};
```

Esse código causa `MYFLOT` e `MYDUB` e o *texto* entrada a ser colocado no arquivo. idl gerado. O *nome* parâmetro força *texto* a ser colocado antes de qualquer coisa que faz referência *nome* no arquivo. idl gerado. O *dependências* parâmetro força as definições de lista de dependência a ser colocado antes *texto* no arquivo. idl gerado.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Atributo de contexto

|||
|-|-|
|**Aplica-se a**|Em qualquer lugar|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Consulte também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos independentes](stand-alone-attributes.md)