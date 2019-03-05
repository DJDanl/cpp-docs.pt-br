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
ms.openlocfilehash: 74607a2a145025533c660ae68f20ffb8e59d3fad
ms.sourcegitcommit: c3093251193944840e3d0a068ecc30e6449624ba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/04/2019
ms.locfileid: "57281727"
---
# <a name="coleupdatedialog-class"></a>Classe COleUpdateDialog

Usado para um caso especial de caixa de diálogo Editar Links do OLE, que deve ser usado quando você precisa atualizar somente objetos vinculados ou incorporados em um documento.

## <a name="syntax"></a>Sintaxe

```
class COleUpdateDialog : public COleLinksDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleUpdateDialog::COleUpdateDialog](#coleupdatedialog)|Constrói um objeto `COleUpdateDialog`.|

### <a name="public-methods"></a>Métodos Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleUpdateDialog::DoModal](#domodal)|Exibe a **Editar Links** caixa de diálogo em um modo de atualização.|

## <a name="remarks"></a>Comentários

Para obter mais informações sobre caixas de diálogo OLE específico, consulte o artigo [caixas de diálogo em OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

[COleDialog](../../mfc/reference/coledialog-class.md)

[COleLinksDialog](../../mfc/reference/colelinksdialog-class.md)

`COleUpdateDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs.h

##  <a name="coleupdatedialog"></a>  COleUpdateDialog::COleUpdateDialog

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
Aponta para o documento que contém os links que podem precisar de atualização.

*bUpdateLinks*<br/>
Sinalizador que determina se os objetos vinculados devem ser atualizadas.

*bUpdateEmbeddings*<br/>
Sinalizador que determina se os objetos inseridos serão atualizados.

*pParentWnd*<br/>
Aponta para o objeto de janela pai ou proprietária (do tipo `CWnd`) ao qual pertence o objeto de caixa de diálogo. Se for NULL, a janela pai da caixa de diálogo será definida para a janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Essa função só constrói um `COleUpdateDialog` objeto. Para exibir a caixa de diálogo, chame [DoModal](../../mfc/reference/colelinksdialog-class.md#domodal). Essa classe deve ser usada em vez de `COleLinksDialog` quando você deseja atualizar somente existente vinculado ou inserido itens.

##  <a name="domodal"></a>  COleUpdateDialog::DoModal

Exibe a caixa de diálogo Editar Links caixa no modo de atualização.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor de retorno

Status de conclusão para a caixa de diálogo. Um dos seguintes valores:

- IDOK se a caixa de diálogo retornado com êxito.

- IDCANCEL se nenhum dos itens vinculados ou inseridos no documento atual precisam ser atualizados.

- IDABORT se ocorreu um erro. Se IDABORT for retornado, chame o [COleDialog::GetLastError](../../mfc/reference/coledialog-class.md#getlasterror) a função de membro para obter mais informações sobre o tipo de erro que ocorreu. Para obter uma lista de possíveis erros, consulte o [OleUIEditLinks](/windows/desktop/api/oledlg/nf-oledlg-oleuieditlinksa) função no SDK do Windows.

### <a name="remarks"></a>Comentários

Todos os links e/ou objetos incorporados são atualizados, a menos que o usuário seleciona o botão Cancelar.

## <a name="see-also"></a>Consulte também

[Exemplo MFC OCLIENT](../../visual-cpp-samples.md)<br/>
[Classe COleLinksDialog](../../mfc/reference/colelinksdialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleLinksDialog](../../mfc/reference/colelinksdialog-class.md)
