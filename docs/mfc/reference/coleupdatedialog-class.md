---
title: Classe COleUpdateDialog
ms.date: 11/04/2016
f1_keywords:
- COleUpdateDialog
- AFXODLGS/COleUpdateDialog
- AFXODLGS/COleUpdateDialog::COleUpdateDialog
- AFXODLGS/COleUpdateDialog::DoModal
helpviewer_keywords:
- COleUpdateDialog [MFC], COleUpdateDialog
- COleUpdateDialog [MFC], DoModal
ms.assetid: 699ca980-52b1-4cf8-9ab1-ac6767ad5b0e
ms.openlocfilehash: 9e2c7a8d79ebf5e6483a06354b280e474d7b8e61
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374843"
---
# <a name="coleupdatedialog-class"></a>Classe COleUpdateDialog

Usado para um caso especial da caixa de diálogo OLE Edit Links, que deve ser usado quando você precisa atualizar apenas objetos vinculados ou incorporados existentes em um documento.

## <a name="syntax"></a>Sintaxe

```
class COleUpdateDialog : public COleLinksDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleUpdateDialog::COleUpdateDialog](#coleupdatedialog)|Constrói um objeto `COleUpdateDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleUpdateDialog::DoModal](#domodal)|Exibe a caixa de diálogo **Editar vínculos** em um modo de atualização.|

## <a name="remarks"></a>Comentários

Para obter mais informações sobre caixas de diálogo específicas do OLE, consulte o artigo [Caixas de diálogo no OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[Cobject](../../mfc/reference/cobject-class.md)

[Ccmdtarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[Cdialog](../../mfc/reference/cdialog-class.md)

[Ccommondialog](../../mfc/reference/ccommondialog-class.md)

[Coledialog](../../mfc/reference/coledialog-class.md)

[Colelinksdialog](../../mfc/reference/colelinksdialog-class.md)

`COleUpdateDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs.h

## <a name="coleupdatedialogcoleupdatedialog"></a><a name="coleupdatedialog"></a>COleUpdateDialog::COleUpdateDialog

Constrói um objeto `COleUpdateDialog`.

```
explicit COleUpdateDialog(
    COleDocument* pDoc,
    BOOL bUpdateLinks = TRUE,
    BOOL bUpdateEmbeddings = FALSE,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*pDoc*<br/>
Aponta para o documento contendo os links que podem precisar ser atualizados.

*bUpdateLinks*<br/>
Sinalizador que determina se os objetos vinculados devem ser atualizados.

*bUpdateEmincorporaddings*<br/>
Sinalizador que determina se os objetos incorporados devem ser atualizados.

*Pparentwnd*<br/>
Aponta para o objeto da janela `CWnd`pai ou proprietário (de tipo) ao qual o objeto de diálogo pertence. Se for NULL, a janela pai da caixa de diálogo será definida na janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Esta função constrói `COleUpdateDialog` apenas um objeto. Para exibir a caixa de diálogo, ligue para [DoModal](../../mfc/reference/colelinksdialog-class.md#domodal). Esta classe deve ser `COleLinksDialog` usada em vez de quando você quiser atualizar apenas itens vinculados ou incorporados existentes.

## <a name="coleupdatedialogdomodal"></a><a name="domodal"></a>COleUpdateDialog::DoModal

Exibe a caixa de diálogo Editar vínculos no modo de atualização.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor retornado

Status de conclusão da caixa de diálogo. Um dos seguintes valores:

- IDOK se a caixa de diálogo retornar com sucesso.

- IDCANCEL se nenhum dos itens vinculados ou incorporados no documento atual precisar ser atualizado.

- IDABORT se ocorreu um erro. Se o IDABORT for retornado, ligue para a função de membro [COleDialog::GetLastError](../../mfc/reference/coledialog-class.md#getlasterror) para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte a função [OleUIEditLinks](/windows/win32/api/oledlg/nf-oledlg-oleuieditlinksw) no SDK do Windows.

### <a name="remarks"></a>Comentários

Todos os links e/ou incorporações são atualizados a menos que o usuário selecione o botão Cancelar.

## <a name="see-also"></a>Confira também

[MFC Amostra OCLIENT](../../overview/visual-cpp-samples.md)<br/>
[Classe COleLinksDialog](../../mfc/reference/colelinksdialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleLinksDialog](../../mfc/reference/colelinksdialog-class.md)
