---
title: Classe COleConvertDialog
ms.date: 11/04/2016
f1_keywords:
- COleConvertDialog
- AFXODLGS/COleConvertDialog
- AFXODLGS/COleConvertDialog::COleConvertDialog
- AFXODLGS/COleConvertDialog::DoConvert
- AFXODLGS/COleConvertDialog::DoModal
- AFXODLGS/COleConvertDialog::GetClassID
- AFXODLGS/COleConvertDialog::GetDrawAspect
- AFXODLGS/COleConvertDialog::GetIconicMetafile
- AFXODLGS/COleConvertDialog::GetSelectionType
- AFXODLGS/COleConvertDialog::m_cv
helpviewer_keywords:
- COleConvertDialog [MFC], COleConvertDialog
- COleConvertDialog [MFC], DoConvert
- COleConvertDialog [MFC], DoModal
- COleConvertDialog [MFC], GetClassID
- COleConvertDialog [MFC], GetDrawAspect
- COleConvertDialog [MFC], GetIconicMetafile
- COleConvertDialog [MFC], GetSelectionType
- COleConvertDialog [MFC], m_cv
ms.assetid: a7c57714-31e8-4b78-834d-8ddd1b856a1c
ms.openlocfilehash: ba57e756457fcffca806eeba7454ddf7bcf99d34
ms.sourcegitcommit: fcb48824f9ca24b1f8bd37d647a4d592de1cc925
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/15/2019
ms.locfileid: "69504303"
---
# <a name="coleconvertdialog-class"></a>Classe COleConvertDialog

Para obter mais informações, consulte a estrutura [OLEUICONVERT](/windows/win32/api/oledlg/ns-oledlg-oleuiconvertw) no SDK do Windows.

## <a name="syntax"></a>Sintaxe

```
class COleConvertDialog : public COleDialog
```

## <a name="members"></a>Membros

### <a name="public-constructors"></a>Construtores públicos

|Nome|Descrição|
|----------|-----------------|
|[COleConvertDialog::COleConvertDialog](#coleconvertdialog)|Constrói um objeto `COleConvertDialog`.|

### <a name="public-methods"></a>Métodos públicos

|Nome|Descrição|
|----------|-----------------|
|[COleConvertDialog::DoConvert](#doconvert)|Executa a conversão especificada na caixa de diálogo.|
|[COleConvertDialog::DoModal](#domodal)|Exibe a caixa de diálogo item de alteração OLE.|
|[COleConvertDialog::GetClassID](#getclassid)|Obtém o CLSID associado ao item escolhido.|
|[COleConvertDialog::GetDrawAspect](#getdrawaspect)|Especifica se o item deve ser desenhado como um ícone.|
|[COleConvertDialog::GetIconicMetafile](#geticonicmetafile)|Obtém um identificador para o metarquivo associado ao formulário icônico deste item.|
|[COleConvertDialog::GetSelectionType](#getselectiontype)|Obtém o tipo de seleção escolhida.|

### <a name="public-data-members"></a>Membros de Dados Públicos

|Nome|Descrição|
|----------|-----------------|
|[COleConvertDialog::m_cv](#m_cv)|Uma estrutura que controla o comportamento da caixa de diálogo.|

## <a name="remarks"></a>Comentários

> [!NOTE]
>  O assistente de aplicativo-código de contêiner gerado usa essa classe.

Para obter mais informações sobre caixas de diálogo específicas de OLE, consulte as caixas de diálogo do artigo [em OLE](../../mfc/dialog-boxes-in-ole.md).

## <a name="inheritance-hierarchy"></a>Hierarquia de herança

[CObject](../../mfc/reference/cobject-class.md)

[CCmdTarget](../../mfc/reference/ccmdtarget-class.md)

[CWnd](../../mfc/reference/cwnd-class.md)

[CDialog](../../mfc/reference/cdialog-class.md)

[CCommonDialog](../../mfc/reference/ccommondialog-class.md)

[COleDialog](../../mfc/reference/coledialog-class.md)

`COleConvertDialog`

## <a name="requirements"></a>Requisitos

**Cabeçalho:** afxodlgs. h

##  <a name="coleconvertdialog"></a>  COleConvertDialog::COleConvertDialog

Constrói apenas um `COleConvertDialog` objeto.

```
explicit COleConvertDialog (
    COleClientItem* pItem,
    DWORD dwFlags = CF_SELECTCONVERTTO,
    CLSID* pClassID = NULL,
    CWnd* pParentWnd = NULL);
```

### <a name="parameters"></a>Parâmetros

*pItem*<br/>
Aponta para o item a ser convertido ou ativado.

*dwFlags*<br/>
Sinalizador de criação, que contém qualquer número dos seguintes valores combinados usando o operador OR bit-a-or:

- CF_SELECTCONVERTTO especifica que o botão de opção converter em será selecionado inicialmente quando a caixa de diálogo for chamada. Esse é o padrão.

- CF_SELECTACTIVATEAS especifica que o botão de opção Ativar como será selecionado inicialmente quando a caixa de diálogo for chamada.

- CF_SETCONVERTDEFAULT Especifica que a classe cujo CLSID é especificado pelo `clsidConvertDefault` membro `m_cv` da estrutura será usada como a seleção padrão na caixa de listagem de classes quando o botão de opção converter em for selecionado.

- CF_SETACTIVATEDEFAULT especifica que a classe cujo CLSID é especificado pelo `clsidActivateDefault` membro `m_cv` da estrutura será usada como a seleção padrão na caixa de listagem de classes quando o botão de opção Ativar como estiver selecionado.

- CF_SHOWHELPBUTTON especifica que o botão ajuda será exibido quando a caixa de diálogo for chamada.

*pClassID*<br/>
Aponta para o CLSID do item a ser convertido ou ativado. Se for NULL, o CLSID associado a *pItem* será usado.

*pParentWnd*<br/>
Aponta para o objeto de janela pai ou proprietário (do `CWnd`tipo) ao qual o objeto de caixa de diálogo pertence. Se for NULL, a janela pai da caixa de diálogo será definida como a janela principal do aplicativo.

### <a name="remarks"></a>Comentários

Para exibir a caixa de diálogo, chame a função [DoModal](#domodal) .

Para obter mais informações, consulte a [chave CLSID](/windows/win32/com/clsid-key-hklm) e a estrutura [OLEUICONVERT](/windows/win32/api/oledlg/ns-oledlg-oleuiconvertw) .

##  <a name="doconvert"></a>  COleConvertDialog::DoConvert

Chame essa função, depois de retornar com êxito de [DoModal](#domodal), para converter ou para ativar um objeto do tipo [COleClientItem](../../mfc/reference/coleclientitem-class.md).

```
BOOL DoConvert(COleClientItem* pItem);
```

### <a name="parameters"></a>Parâmetros

*pItem*<br/>
Aponta para o item a ser convertido ou ativado. Não pode ser NULL.

### <a name="return-value"></a>Valor de retorno

Diferente de zero, se for bem-sucedido; caso contrário, 0.

### <a name="remarks"></a>Comentários

O item é convertido ou ativado de acordo com as informações selecionadas pelo usuário na caixa de diálogo Converter.

##  <a name="domodal"></a>  COleConvertDialog::DoModal

Chame essa função para exibir a caixa de diálogo conversão de OLE.

```
virtual INT_PTR DoModal();
```

### <a name="return-value"></a>Valor de retorno

Status de conclusão da caixa de diálogo. Um dos seguintes valores:

- IDOK se a caixa de diálogo foi exibida com êxito.

- IDCANCEL se o usuário cancelou a caixa de diálogo.

- IDABORT se ocorreu um erro. Se IDABORT for retornado, chame a função de membro [COleDialog:: GetLastError](../../mfc/reference/coledialog-class.md#getlasterror) para obter mais informações sobre o tipo de erro ocorrido. Para obter uma lista de possíveis erros, consulte a função [OLEUICONVERT](/windows/win32/api/oledlg/nf-oledlg-oleuiconvertw) no SDK do Windows.

### <a name="remarks"></a>Comentários

Se você quiser inicializar os vários controles da caixa de diálogo definindo membros da estrutura [m_cv](#m_cv) , faça isso antes de chamar `DoModal`, mas depois que o objeto da caixa de diálogo for construído.

Se `DoModal` retornar IDOK, você poderá chamar outras funções de membro para recuperar as configurações ou informações inseridas pelo usuário na caixa de diálogo.

##  <a name="getclassid"></a>  COleConvertDialog::GetClassID

Chame essa função para obter o CLSID associado ao item selecionado pelo usuário na caixa de diálogo Converter.

```
REFCLSID GetClassID() const;
```

### <a name="return-value"></a>Valor de retorno

O CLSID associado ao item que foi selecionado na caixa de diálogo Converter.

### <a name="remarks"></a>Comentários

Chame essa função somente depois que [DoModal](#domodal) retornar IDOK.

Para obter mais informações, consulte [chave de CLSID](/windows/win32/com/clsid-key-hklm) no SDK do Windows.

##  <a name="getdrawaspect"></a>  COleConvertDialog::GetDrawAspect

Chame essa função para determinar se o usuário optou por exibir o item selecionado como um ícone.

```
DVASPECT GetDrawAspect() const;
```

### <a name="return-value"></a>Valor de retorno

O método necessário para processar o objeto.

- DVASPECT_CONTENT retornado se a caixa de seleção Exibir como ícone não foi marcada.

- DVASPECT_ICON retornado se a caixa de seleção Exibir como ícone foi marcada.

### <a name="remarks"></a>Comentários

Chame essa função somente depois que [DoModal](#domodal) retornar IDOK.

Para obter mais informações sobre o aspecto do desenho, consulte a estrutura de dados [FORMATETC](/windows/win32/api/objidl/ns-objidl-formatetc) na SDK do Windows.

##  <a name="geticonicmetafile"></a>  COleConvertDialog::GetIconicMetafile

Chame essa função para obter um identificador para o metarquivo que contém o aspecto icônico do item selecionado.

```
HGLOBAL GetIconicMetafile() const;
```

### <a name="return-value"></a>Valor de retorno

O identificador para o metarquivo que contém o aspecto de icônico do item selecionado, se a caixa de seleção Exibir como ícone foi marcada quando o diálogo foi descartado, escolhendo OK; caso contrário, NULL.

##  <a name="getselectiontype"></a>  COleConvertDialog::GetSelectionType

Chame essa função para determinar o tipo de conversão selecionada na caixa de diálogo Converter.

```
UINT GetSelectionType() const;
```

### <a name="return-value"></a>Valor de retorno

Tipo de seleção feita.

### <a name="remarks"></a>Comentários

Os valores de tipo de retorno são especificados `Selection` pelo tipo de enumeração declarado `COleConvertDialog` na classe.

```
enum Selection {
    noConversion,
    convertItem,
    activateAs
    };
```

As breves descrições desses valores são as seguintes:

- `COleConvertDialog::noConversion`Retornado se a caixa de diálogo foi cancelada ou o usuário selecionou nenhuma conversão. Se `COleConvertDialog::DoModal` for retornado IDOK, é possível que o usuário tenha selecionado um ícone diferente daquele selecionado anteriormente.

- `COleConvertDialog::convertItem`Retornado se o botão de opção converter em foi marcado, o usuário selecionou um item diferente para o qual `DoModal` converter e retornou IDOK.

- `COleConvertDialog::activateAs`Retornado se o botão de opção Ativar como estava marcado, o usuário selecionou um item diferente para ativar `DoModal` e retornou IDOK.

##  <a name="m_cv"></a>  COleConvertDialog::m_cv

Estrutura do tipo OLEUICONVERT usada para controlar o comportamento da caixa de diálogo Converter.

```
OLEUICONVERT m_cv;
```

### <a name="remarks"></a>Comentários

Os membros dessa estrutura podem ser modificados diretamente ou por meio de funções de membro.

Para obter mais informações, consulte a estrutura [OLEUICONVERT](/windows/win32/api/oledlg/ns-oledlg-oleuiconvertw) no SDK do Windows.

## <a name="see-also"></a>Consulte também

[Classe COleDialog](../../mfc/reference/coledialog-class.md)<br/>
[Gráfico da hierarquia](../../mfc/hierarchy-chart.md)<br/>
[Classe COleDialog](../../mfc/reference/coledialog-class.md)
