---
title: Classe COleControlModule
ms.date: 11/04/2016
f1_keywords:
- OleControlModule
helpviewer_keywords:
- OLE control modules [MFC]
- MFC ActiveX controls [MFC], OLE control modules
- COleControlModule class [MFC]
- control modules [MFC]
ms.assetid: 0721724d-d4af-4eda-ad34-5a2b27810dd4
ms.openlocfilehash: f6d486c7bacb897d70d85414ac3d0bd0d13e447b
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62310390"
---
# <a name="colecontrolmodule-class"></a>Classe COleControlModule

A classe base da qual você deriva um objeto de módulo de controle OLE.

## <a name="syntax"></a>Sintaxe

```
class COleControlModule : public CWinApp
```

## <a name="remarks"></a>Comentários

Essa classe fornece funções de membro para inicializar o módulo de controle. Cada módulo de controle OLE que usa as Microsoft Foundation classes só pode conter um objeto derivado de `COleControlModule`. Esse objeto é construído quando outros objetos globais de C++ são construídos. Declare seu derivada `COleControlModule` objeto no nível global.

Para obter mais informações sobre como usar o `COleControlModule` classe, consulte a [CWinApp](../../mfc/reference/cwinapp-class.md) classe e o artigo [controles ActiveX](../../mfc/mfc-activex-controls.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWinThread](../../mfc/reference/cwinthread-class.md)

[CWinApp](../../mfc/reference/cwinapp-class.md)

`COleControlModule`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxctl. h

## <a name="see-also"></a>Consulte também

[Exemplo MFC TESTHELP](../../overview/visual-cpp-samples.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
