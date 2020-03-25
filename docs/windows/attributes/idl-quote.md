---
title: idl_quote (C++ atributo com)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.idl_quote
helpviewer_keywords:
- idl_quote attribute
ms.assetid: a370e1b7-948b-4e67-9a25-58facf24e4c9
ms.openlocfilehash: 4b05da6d237d71e0cc645ad0f626f75ecd85c827
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80168023"
---
# <a name="idl_quote"></a>idl_quote

Permite que você use construções IDL que não têm suporte na versão atual do Visual C++ e que elas passem pelo arquivo. idl gerado.

## <a name="syntax"></a>Sintaxe

```cpp
[ idl_quote(text) ]
```

### <a name="parameters"></a>parâmetros

*text*<br/>
O nome do atributo que você pretende que C++ o compilador da Microsoft passe para o arquivo. idl gerado sem retornar um erro do compilador.

## <a name="remarks"></a>Comentários

Se o atributo **idl_quote** C++ for usado como um atributo autônomo (com um ponto e vírgula após o colchete de fechamento), o *texto* será colocado no arquivo. idl mesclado como está. Se **idl_quote** for usado em um símbolo, o *texto* será colocado dentro do bloco de atributo para esse símbolo.

## <a name="example"></a>Exemplo

O código a seguir mostra como você pode especificar um atributo sem suporte (usando **no**, que tem suporte) e como definir e usar uma construção. idl indefinida:

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

Esse código faz com que `MYFLOT` e `MYDUB` e a entrada de *texto* seja colocada no arquivo. idl gerado. O parâmetro *Name* força o *texto* a ser colocado antes de qualquer coisa que referencie o *nome* no arquivo. idl gerado. O parâmetro *Dependencies* força as definições da lista de dependências a serem colocadas antes do *texto* no arquivo. idl gerado.

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Lugares|
|**Repetível**|Não|
|**Atributos necessários**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos de IDL](idl-attributes.md)<br/>
[Atributos independentes](stand-alone-attributes.md)
