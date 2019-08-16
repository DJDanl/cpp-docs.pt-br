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
ms.openlocfilehash: 150e78b7880a61343db21c3c787ffdd1f0b734a5
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69503163"
---
# <a name="coleupdatedialog-class"></a>Classe COleUpdateDialog

Usado para um caso especial da caixa de diálogo links de edição OLE, que deve ser usado quando você precisar atualizar somente objetos vinculados ou incorporados existentes em um documento.

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
|[COleUpdateDialog::DoModal](#domodal)|Exibe a caixa de diálogo **Editar links** em um modo de atualização.|

## <a name="remarks"></a>Comentários

Para obter mais informações sobre caixas de diálogo específicas de OLE, consulte as caixas de diálogo do artigo [em OLE](../../mfc/dialog-boxes-in-ole.md).

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

**Cabeçalho:** afxodlgs. h

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
Aponta para o documento que contém os links que podem precisar ser atualizados.

*bUpdateLinks*<br/>
Sinalizador que determina se os objetos vinculados devem ser atualizados.

*bUpdateEmbeddings*<br/>
Sinalizador que determina se os objetos incorporados devem ser atualizados.

*pParentWnd*<br/>
Aponta para o objeto de janela pai ou proprietário (do `CWnd`tipo) ao qual o objeto de caixa de diálogo pertence. Se for NULL, a janela pai da caixa de diálogo será definida como a janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Essa função constrói apenas um `COleUpdateDialog` objeto. Para exibir a caixa de diálogo, chame [DoModal](../../mfc/reference/colelinksdialog-class.md#domodal). Essa classe deve ser usada em vez `COleLinksDialog` de quando você deseja atualizar somente itens vinculados ou inseridos existentes.

##  <a name="domodal"></a>  COleUpdateDialog::DoModal

Exibe a caixa de diálogo Editar links no modo de atualização.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor de retorno

Status de conclusão da caixa de diálogo. Um dos seguintes valores:

- IDOK se a caixa de diálogo foi retornada com êxito.

- IDCANCEL se nenhum dos itens vinculados ou incorporados no documento atual precisar de atualização.

- IDABORT se ocorreu um erro. Se IDABORT for retornado, chame a função de membro [COleDialog:: GetLastError](../../mfc/reference/coledialog-class.md#getlasterror) para obter mais informações sobre o tipo de erro ocorrido. Para obter uma lista de possíveis erros, consulte a função [OLEUIEDITLINKS](/windows/win32/api/oledlg/nf-oledlg-oleuieditlinksw) no SDK do Windows.

### <a name="remarks"></a>Comentários

Todos os links e/ou incorporações são atualizados, a menos que o usuário selecione o botão Cancelar.

## <a name="see-also"></a>Consulte também

[Exemplo de OCLIENT do MFC](../../overview/visual-cpp-samples.md)<br/>
[Classe COleLinksDialog](../../mfc/reference/colelinksdialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleLinksDialog](../../mfc/reference/colelinksdialog-class.md)
