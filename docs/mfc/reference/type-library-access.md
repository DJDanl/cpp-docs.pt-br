---
title: Acesso à biblioteca de tipos
ms.date: 11/04/2016
helpviewer_keywords:
- type libraries [MFC], accessing
ms.assetid: a03fa7f0-86c2-4119-bf81-202916fb74b3
ms.openlocfilehash: 1794e16489ab48d919bbd4116588fba4b74b88d9
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81372881"
---
# <a name="type-library-access"></a>Acesso à biblioteca de tipos

Bibliotecas de tipo expõem as interfaces de um controle OLE a outros aplicativos com reconhecimento de OLE. Cada controle OLE deve ter uma biblioteca de tipos se uma ou mais interfaces forem expostas.

As seguintes macros permitem que um controle OLE forneça acesso à sua própria biblioteca de tipos:

### <a name="type-library-access"></a>Acesso à biblioteca de tipos

|||
|-|-|
|[DECLARE_OLETYPELIB](#declare_oletypelib)|Declara uma `GetTypeLib` função membro de um controle OLE (deve ser usado na declaração de classe).|
|[IMPLEMENT_OLETYPELIB](#implement_oletypelib)|Implementa `GetTypeLib` uma função membro de um controle OLE (deve ser usado na implementação da classe).|

## <a name="declare_oletypelib"></a><a name="declare_oletypelib"></a>DECLARE_OLETYPELIB

Declara a `GetTypeLib` função membro da sua classe de controle.

```
DECLARE_OLETYPELIB(class_name)
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome da classe de controle relacionado à biblioteca do tipo.

### <a name="remarks"></a>Comentários

Use esta macro no arquivo de cabeçalho da classe de controle.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="implement_oletypelib"></a><a name="implement_oletypelib"></a>IMPLEMENT_OLETYPELIB

Implementa a função `GetTypeLib` de membro do controle.

```
IMPLEMENT_OLETYPELIB(class_name, tlid, wVerMajor,  wVerMinor)
```

### <a name="parameters"></a>Parâmetros

*Class_name*<br/>
O nome da classe de controle relacionado à biblioteca do tipo.

*tlid*<br/>
O número de id da biblioteca do tipo.

*wVerMajor*<br/>
O número da versão principal da biblioteca do tipo.

*wVerMinor*<br/>
O tipo de número de versão menor da biblioteca.

### <a name="remarks"></a>Comentários

Esta macro deve aparecer no arquivo de implementação para qualquer classe de controle que use a DECLARE_OLETYPELIB macro.

### <a name="requirements"></a>Requisitos

**Cabeçalho:** afxdisp.h

## <a name="see-also"></a>Confira também

[Macros e globais](../../mfc/reference/mfc-macros-and-globals.md)
