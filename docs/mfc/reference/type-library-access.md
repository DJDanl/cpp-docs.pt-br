---
title: Acesso à biblioteca de tipos
ms.date: 11/04/2016
helpviewer_keywords:
- type libraries [MFC], accessing
ms.assetid: a03fa7f0-86c2-4119-bf81-202916fb74b3
ms.openlocfilehash: 23d4675bd3638d2effd1b967f0729f9e70dac6de
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79420746"
---
# <a name="type-library-access"></a>Acesso à biblioteca de tipos

Bibliotecas de tipos expõem as interfaces de um controle OLE para outros aplicativos que reconhecem OLE. Cada controle OLE deve ter uma biblioteca de tipos se uma ou mais interfaces devem ser expostas.

As macros a seguir permitem que um controle OLE forneça acesso à sua própria biblioteca de tipos:

### <a name="type-library-access"></a>Acesso à biblioteca de tipos

|||
|-|-|
|[DECLARE_OLETYPELIB](#declare_oletypelib)|Declara uma função membro `GetTypeLib` de um controle OLE (deve ser usada na declaração de classe).|
|[IMPLEMENT_OLETYPELIB](#implement_oletypelib)|Implementa uma função membro `GetTypeLib` de um controle OLE (deve ser usada na implementação de classe).|

##  <a name="declare_oletypelib"></a>DECLARE_OLETYPELIB

Declara a função membro `GetTypeLib` da classe de controle.

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

##  <a name="implement_oletypelib"></a>IMPLEMENT_OLETYPELIB

Implementa a função de membro `GetTypeLib` do controle.

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
