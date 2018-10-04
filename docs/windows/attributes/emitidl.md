---
title: emitidl (atributo de COM do C++) | Microsoft Docs
ms.custom: ''
ms.date: 10/02/2018
ms.technology:
- cpp-windows
ms.topic: reference
f1_keywords:
- vc-attr.emitidl
dev_langs:
- C++
helpviewer_keywords:
- emitidl attribute
ms.assetid: 85b80c56-578e-4392-ac03-8443c74ebb7d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 5e11e1ce061fcf2e9ce21155dcbeb93b45b66238
ms.sourcegitcommit: 955ef0f9d966e7c9c65e040f1e28fa83abe102a5
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/04/2018
ms.locfileid: "48790224"
---
# <a name="emitidl"></a>emitidl

Especifica se todos os atributos IDL subsequentes são processados e colocados no arquivo. idl gerado.

## <a name="syntax"></a>Sintaxe

```cpp
[ emitidl(state, defaultimports=boolean) ];
```

### <a name="parameters"></a>Parâmetros

*state*<br/>
Um desses valores possíveis: `true`, `false`, `forced`, `restricted`, `push`, ou `pop`.

- Se `true`, qualquer atributo de categoria IDL encontrado em um arquivo de código-fonte é colocado no arquivo. idl gerado. Essa é a configuração padrão para **emitidl**.

- Se `false`, qualquer atributo de categoria IDL encontrado em um arquivo de código-fonte não é colocado no arquivo. idl gerado.

- Se `restricted`, permite que os atributos IDL estar em um arquivo sem uma [módulo](module-cpp.md) atributo. O compilador não gera um arquivo. idl.

- Se `forced`, substitui um subsequentes `restricted` atributo, que requer um arquivo para ter um `module` atributo se houver IDL atributos no arquivo.

- `push` permite que você salve atual **emitidl** as configurações para interno **emitidl** pilha, e `pop` permite que você defina **emitidl** para qualquer valor que está na parte superior da interno **emitidl** pilha.

`defaultimports=`*booleano* \(opcional)  
- Se *boolean* é **verdadeiro**, docobj. IDL é importado para o arquivo. idl gerado. Além disso, se um arquivo. idl com o mesmo nome que um. h do arquivo que você `#include` em sua fonte de código é encontrado no mesmo diretório que o arquivo. h e, em seguida, o arquivo. idl gerado contém uma instrução de importação para esse arquivo. idl.

- Se *boolean* é **falso**, docobj. idl não será importado para o arquivo. idl gerado. Você deve explicitamente, importar arquivos. idl com [importação](import.md).

## <a name="remarks"></a>Comentários

Após o **emitidl** atributo C++ é encontrado em um arquivo de código-fonte, atributos de categoria IDL são colocados no arquivo. idl gerado. Se não houver nenhuma **emitidl** atributo, os atributos IDL no arquivo de código de origem são passados para o arquivo. idl gerado.

É possível ter vários **emitidl** atributos em um arquivo de código-fonte. Se `[emitidl(false)];` é encontrado em um arquivo sem um subsequentes `[emitidl(true)];`, em seguida, os atributos não são processados no arquivo. idl gerado.

Cada vez que o compilador encontra um novo arquivo, **emitidl** é definido implicitamente como **verdadeiro**.

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

[Atributos de compilador](compiler-attributes.md)<br/>
[Atributos independentes](stand-alone-attributes.md)  
