---
title: Classe COleDialog | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-mfc
ms.topic: reference
f1_keywords:
- COleDialog
- AFXODLGS/COleDialog
- AFXODLGS/COleDialog::GetLastError
dev_langs:
- C++
helpviewer_keywords:
- COleDialog [MFC], GetLastError
ms.assetid: b1ed0aca-3914-4b00-af34-4a4fb491aec7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 3c6cebf6af24de860c583398c16c87824ede0075
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46401271"
---
# <a name="coledialog-class"></a>Classe COleDialog

Fornece funcionalidade comum às caixas de diálogo para OLE.

## <a name="syntax"></a>Sintaxe

```
class COleDialog : public CCommonDialog
```

## <a name="members"></a>Membros

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleDialog::GetLastError](#getlasterror)|Obtém o código de erro retornado pela caixa de diálogo.|

## <a name="remarks"></a>Comentários

A biblioteca Microsoft Foundation Class fornece várias classes derivadas de `COleDialog`:

- [COleInsertDialog](../../mfc/reference/coleinsertdialog-class.md)

- [COleConvertDialog](../../mfc/reference/coleconvertdialog-class.md)

- [COleChangeIconDialog](../../mfc/reference/colechangeicondialog-class.md)

- [COleLinksDialog](../../mfc/reference/colelinksdialog-class.md)

- [COleBusyDialog](../../mfc/reference/colebusydialog-class.md)

- [COleUpdateDialog](../../mfc/reference/coleupdatedialog-class.md)

- [COlePasteSpecialDialog](../../mfc/reference/colepastespecialdialog-class.md)

- [COlePropertiesDialog](../../mfc/reference/colepropertiesdialog-class.md)

- [COleChangeSourceDialog](../../mfc/reference/colechangesourcedialog-class.md)

Para obter mais informações sobre caixas de diálogo OLE específico, consulte o artigo [caixas de diálogo em OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

`COleDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs.h

##  <a name="getlasterror"></a>  COleDialog::GetLastError

Chame o `GetLastError` função de membro para obter informações adicionais sobre erros quando `DoModal` retorna IDABORT.

```
UINT GetLastError() const;
```

### <a name="return-value"></a>Valor de retorno

Os códigos de erro retornados pelo `GetLastError` dependem da caixa de diálogo específico exibido.

### <a name="remarks"></a>Comentários

Consulte o `DoModal` função de membro em classes derivadas para obter informações sobre mensagens de erro específicas.

## <a name="see-also"></a>Consulte também

[Classe CCommonDialog](../../mfc/reference/ccommondialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)



