---
title: emitidl (atributo COM C++)
ms.date: 10/02/2018
f1_keywords:
- vc-attr.emitidl
helpviewer_keywords:
- emitidl attribute
ms.assetid: 85b80c56-578e-4392-ac03-8443c74ebb7d
ms.openlocfilehash: 4ddf71c385414a28c2b616b359a93a637abc24aa
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87222128"
---
# <a name="emitidl"></a>emitidl

Especifica se todos os atributos IDL subsequentes são processados e colocados no arquivo. idl gerado.

## <a name="syntax"></a>Sintaxe

```cpp
[ emitidl(state, defaultimports=boolean) ];
```

### <a name="parameters"></a>parâmetros

*state*<br/>
Um desses valores possíveis:,,,, **`true`** **`false`** `forced` `restricted` `push` ou `pop` .

- Se **`true`** , todos os atributos de categoria de IDL encontrados em um arquivo de código-fonte serão colocados no arquivo. idl gerado. Essa é a configuração padrão para **emitidl**.

- Se **`false`** , qualquer atributo de categoria de IDL encontrado em um arquivo de código-fonte não será colocado no arquivo. idl gerado.

- Se `restricted` , permite que os atributos IDL estejam no arquivo sem um atributo de [módulo](module-cpp.md) . O compilador não gera um arquivo. idl.

- Se `forced` , substitui um `restricted` atributo subsequente, que exige que um arquivo tenha um `module` atributo se houver atributos IDL no arquivo.

- `push`permite salvar as configurações de **emitidl** atuais em uma pilha **emitidl** interna e `pop` permite que você defina **emitidl** como qualquer valor na parte superior da pilha **emitidl** interna.

`defaultimports=`*valor booleano* \( adicional

- Se *booliano* for **`true`** , docobj. idl será importado para o arquivo. idl gerado. Além disso, se um arquivo. idl com o mesmo nome de um arquivo. h que você `#include` em seu código-fonte for encontrado no mesmo diretório que o arquivo. h, o arquivo. idl gerado conterá uma instrução de importação para esse arquivo. idl.

- Se *booliano* for **`false`** , docobj. idl não será importado para o arquivo. idl gerado. Você deve importar explicitamente arquivos. idl com [importação](import.md).

## <a name="remarks"></a>Comentários

Depois que o atributo **emitidl** C++ é encontrado em um arquivo de código-fonte, os atributos de categoria IDL são colocados no arquivo. idl gerado. Se não houver nenhum atributo **emitidl** , os atributos IDL no arquivo de código-fonte serão gerados para o arquivo. idl gerado.

É possível ter vários atributos **emitidl** em um arquivo de código-fonte. Se `[emitidl(false)];` for encontrado em um arquivo sem um subseqüente `[emitidl(true)];` , nenhum atributo será processado no arquivo. idl gerado.

Cada vez que o compilador encontra um novo arquivo, **emitidl** é implicitamente definido como **`true`** .

## <a name="requirements"></a>Requisitos

### <a name="attribute-context"></a>Contexto de atributo

|||
|-|-|
|**Aplica-se a**|Qualquer lugar|
|**Repetível**|Não|
|**Atributos obrigatórios**|Nenhum|
|**Atributos inválidos**|Nenhum|

Para obter mais informações, consulte [contextos de atributo](cpp-attributes-com-net.md#contexts).

## <a name="see-also"></a>Confira também

[Atributos do compilador](compiler-attributes.md)<br/>
[Atributos autônomos](stand-alone-attributes.md)
