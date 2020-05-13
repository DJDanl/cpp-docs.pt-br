---
title: Classe COleDialog
ms.date: 11/04/2016
f1_keywords:
- COleDialog
- AFXODLGS/COleDialog
- AFXODLGS/COleDialog::GetLastError
helpviewer_keywords:
- COleDialog [MFC], GetLastError
ms.assetid: b1ed0aca-3914-4b00-af34-4a4fb491aec7
ms.openlocfilehash: 6a1983d426e97dd8063aee2857dc36557aa20677
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81366089"
---
# <a name="coledialog-class"></a>Classe COleDialog

Fornece funcionalidade comum às caixas de diálogo para OLE.

## <a name="syntax"></a>Sintaxe

```
class COleDialog : public CCommonDialog
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDialog::GetLastError](#getlasterror)|Obtém o código de erro retornado pela caixa de diálogo.|

## <a name="remarks"></a>Comentários

A Biblioteca de Classes da Microsoft `COleDialog`Foundation fornece várias classes derivadas de :

- [Coleinsertdialog](../../mfc/reference/coleinsertdialog-class.md)

- [Coleconvertdialog](../../mfc/reference/coleconvertdialog-class.md)

- [Colechangeicondialog](../../mfc/reference/colechangeicondialog-class.md)

- [Colelinksdialog](../../mfc/reference/colelinksdialog-class.md)

- [Colebusydialog](../../mfc/reference/colebusydialog-class.md)

- [Coleupdatedialog](../../mfc/reference/coleupdatedialog-class.md)

- [Colepastespecialdialog](../../mfc/reference/colepastespecialdialog-class.md)

- [Colepropertiesdialog](../../mfc/reference/colepropertiesdialog-class.md)

- [Colechangesourcedialog](../../mfc/reference/colechangesourcedialog-class.md)

Para obter mais informações sobre caixas de diálogo específicas da OLE, consulte o artigo [Caixas de Diálogo no OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Ccommondialog](../../mfc/reference/ccommondialog-class.md)

`COleDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs.h

## <a name="coledialoggetlasterror"></a><a name="getlasterror"></a>COleDialog::GetLastError

Ligue `GetLastError` para a função membro `DoModal` para obter informações adicionais de erro quando retornar IDABORT.

```
UINT GetLastError() const;
```

### <a name="return-value"></a>Valor retornado

Os códigos de `GetLastError` erro retornados dependem da caixa de diálogo específica exibida.

### <a name="remarks"></a>Comentários

Consulte `DoModal` a função do membro nas classes derivadas para obter informações sobre mensagens de erro específicas.

## <a name="see-also"></a>Confira também

[Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)
