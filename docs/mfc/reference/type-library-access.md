---
title: Acesso à biblioteca de tipos
ms.date: 11/04/2016
helpviewer_keywords:
- type libraries [MFC], accessing
ms.assetid: a03fa7f0-86c2-4119-bf81-202916fb74b3
ms.openlocfilehash: 55d6a56f566416bb25f3ee3ae508c86f17f0df99
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88840447"
---
# <a name="type-library-access"></a>Acesso à biblioteca de tipos

Bibliotecas de tipos expõem as interfaces de um controle OLE para outros aplicativos que reconhecem OLE. Cada controle OLE deve ter uma biblioteca de tipos se uma ou mais interfaces devem ser expostas.

As macros a seguir permitem que um controle OLE forneça acesso à sua própria biblioteca de tipos:

### <a name="type-library-access"></a>Acesso à biblioteca de tipos

|Nome|Descrição|
|-|-|
|[DECLARE_OLETYPELIB](#declare_oletypelib)|Declara uma `GetTypeLib` função de membro de um controle OLE (deve ser usada na declaração de classe).|
|[IMPLEMENT_OLETYPELIB](#implement_oletypelib)|Implementa uma `GetTypeLib` função de membro de um controle OLE (deve ser usada na implementação de classe).|

## <a name="declare_oletypelib"></a><a name="declare_oletypelib"></a> DECLARE_OLETYPELIB

Declara a `GetTypeLib` função de membro da classe de controle.

```
DECLARE_OLETYPELIB(class_name)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome da classe de controle relacionada à biblioteca de tipos.

### <a name="remarks"></a>Comentários

Use essa macro no arquivo de cabeçalho de classe de controle.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

## <a name="implement_oletypelib"></a><a name="implement_oletypelib"></a> IMPLEMENT_OLETYPELIB

Implementa a função de `GetTypeLib` membro do controle.

```
IMPLEMENT_OLETYPELIB(class_name, tlid, wVerMajor,  wVerMinor)
```

### <a name="parameters"></a>parâmetros

*class_name*<br/>
O nome da classe de controle relacionada à biblioteca de tipos.

*tlid*<br/>
O número de ID da biblioteca de tipos.

*wVerMajor*<br/>
O número de versão principal da biblioteca de tipos.

*wVerMinor*<br/>
O número de versão secundária da biblioteca de tipos.

### <a name="remarks"></a>Comentários

Essa macro deve aparecer no arquivo de implementação para qualquer classe de controle que use a macro DECLARE_OLETYPELIB.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** AFXDISP. h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
