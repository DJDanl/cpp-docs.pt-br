---
title: Acesso à biblioteca de tipos
ms.date: 11/04/2016
helpviewer_keywords:
- type libraries [MFC], accessing
ms.assetid: a03fa7f0-86c2-4119-bf81-202916fb74b3
ms.openlocfilehash: 23d4675bd3638d2effd1b967f0729f9e70dac6de
ms.sourcegitcommit: 934cb53fa4cb59fea611bfeb9db110d8d6f7d165
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/14/2019
ms.locfileid: "65611537"
---
# <a name="type-library-access"></a>Acesso à biblioteca de tipos

Bibliotecas de tipos expõem as interfaces de um controle OLE para outros aplicativos com reconhecimento de OLE. Cada controle OLE deve ter uma biblioteca de tipos, se uma ou mais interfaces devem ser expostos.

As macros a seguir permitem que um controle OLE fornecer acesso a sua própria biblioteca de tipos:

### <a name="type-library-access"></a>Acesso à biblioteca de tipos

|||
|-|-|
|[DECLARE_OLETYPELIB](#declare_oletypelib)|Declara um `GetTypeLib` função de membro de um controle OLE (deve ser usado na declaração de classe).|
|[IMPLEMENT_OLETYPELIB](#implement_oletypelib)|Implementa um `GetTypeLib` função de membro de um controle OLE (deve ser usada na implementação da classe).|

##  <a name="declare_oletypelib"></a>  DECLARE_OLETYPELIB

Declara o `GetTypeLib` função de membro de sua classe de controle.

```
DECLARE_OLETYPELIB(class_name)
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome da classe de controle relacionada à biblioteca de tipos.

### <a name="remarks"></a>Comentários

Use esta macro no arquivo de cabeçalho de classe de controle.

### <a name="requirements"></a>Requisitos

**Header:** afxdisp.h

##  <a name="implement_oletypelib"></a>  IMPLEMENT_OLETYPELIB

Implementa o controle `GetTypeLib` função de membro.

```
IMPLEMENT_OLETYPELIB(class_name, tlid, wVerMajor,  wVerMinor)
```

### <a name="parameters"></a>Parâmetros

*class_name*<br/>
O nome da classe de controle relacionada à biblioteca de tipos.

*tlid*<br/>
O número de identificação da biblioteca de tipos.

*wVerMajor*<br/>
O número de versão principal da biblioteca de tipo.

*wVerMinor*<br/>
O número de versão secundária da biblioteca de tipo.

### <a name="remarks"></a>Comentários

Essa macro deve aparecer no arquivo de implementação para qualquer classe de controle que usa a macro DECLARE_OLETYPELIB.

### <a name="requirements"></a>Requisitos

**Header:** afxdisp.h

## <a name="see-also"></a>Consulte também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
